#!/usr/bin/env python
'''
mavlink python utility functions

Copyright Andrew Tridgell 2011
Released under GNU GPL version 3 or later
'''

import mavlink, socket, math, struct, time, os
from math import *
from mavextra import *

def evaluate_expression(expression, vars):
    '''evaluation an expression'''
    try:
        v = eval(expression, globals(), vars)
    except NameError:
        return None
    return v

def evaluate_condition(condition, vars):
    '''evaluation a conditional (boolean) statement'''
    if condition is None:
        return True
    v = evaluate_expression(condition, vars)
    if v is None:
        return False
    return v


class mavfile(object):
    '''a generic mavlink port'''
    def __init__(self, fd, address, source_system=255):
        self.fd = fd
        self.address = address
        self.messages = {}
        self.mav = None
        self.target_system = 0
        self.target_component = 0
        self.mav = mavlink.MAVLink(self, srcSystem=source_system)
        self.mav.robust_parsing = True
        self.logfile = None
        self.logfile_raw = None

    def recv(self):
        '''default recv method'''
        raise RuntimeError('no recv() method supplied')

    def write(self, buf):
        '''default write method'''
        raise RuntimeError('no write() method supplied')

    def pre_message(self):
        '''default pre message call'''
        return

    def post_message(self, msg):
        '''default post message call'''
        msg._timestamp = time.time()
        type = msg.get_type()
        self.messages[type] = msg
        if type == 'HEARTBEAT':
            self.target_system = msg.get_srcSystem()
            self.target_component = msg.get_srcComponent()


    def recv_msg(self):
        '''message receive routine'''
        self.pre_message()
        while True:
            s = self.recv()
            if len(s) == 0 and len(self.mav.buf) == 0:
                return None
            if self.logfile_raw:
                self.logfile_raw.write(s)
            msg = self.mav.parse_char(s)
            if msg:
                self.post_message(msg)
                return msg
                
    def recv_match(self, condition=None, type=None, blocking=False):
        '''recv the next MAVLink message that matches the given condition'''
        while True:
            m = self.recv_msg()
            if m is None:
                if blocking:
                    time.sleep(0.01)
                    continue
                return None
            if type is not None and type != m.get_type():
                continue
            if not evaluate_condition(condition, self.messages):
                continue
            return m

    def setup_logfile(self, logfile, mode='w'):
        '''start logging to the given logfile, with timestamps'''
        self.logfile = open(logfile, mode=mode)

    def setup_logfile_raw(self, logfile, mode='w'):
        '''start logging raw bytes to the given logfile, without timestamps'''
        self.logfile_raw = open(logfile, mode=mode)

    def wait_heartbeat(self, blocking=True):
        '''wait for a heartbeat so we know the target system IDs'''
        return self.recv_match(type='HEARTBEAT', blocking=blocking)

class mavserial(mavfile):
    '''a serial mavlink port'''
    def __init__(self, device, baud=115200, autoreconnect=False, source_system=255):
        import serial
        self.baud = baud
        self.device = device
        self.autoreconnect = autoreconnect
        self.port = serial.Serial(self.device, self.baud, timeout=0,
                                  dsrdtr=False, rtscts=False, xonxoff=False)

        try:
            fd = self.port.fileno()
        except Exception:
            raise
        mavfile.__init__(self, fd, device, source_system=source_system)

    def recv(self):
        n = self.mav.bytes_needed()
        if self.fd is None:
            waiting = self.port.inWaiting()
            if waiting < n:
                n = waiting
        return self.port.read(n)

    def write(self, buf):
        try:
            return self.port.write(buf)
        except OSError:
            if self.autoreconnect:
                self.reset()
            return -1
            
    def reset(self):
        import serial
        self.port.close()
        while True:
            try:
                self.port = serial.Serial(self.device, self.baud, timeout=1,
                                          dsrdtr=False, rtscts=False, xonxoff=False)
                try:
                    self.fd = self.port.fileno()
                except Exception:
                    self.fd = None
                return
            except Exception, msg:
                print("Failed to reopen %s - %s" % (self.device, msg))
                time.sleep(1)
        

class mavudp(mavfile):
    '''a UDP mavlink socket'''
    def __init__(self, device, input=True, source_system=255):
        a = device.split(':')
        if len(a) != 2:
            print("UDP ports must be specified as host:port")
            sys.exit(1)
        self.port = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        if input:
            self.port.bind((a[0], int(a[1])))
            self.connected = False
        else:
            self.port.connect((a[0], int(a[1])))
            self.connected = True
        self.port.setblocking(0)
        self.last_address = None
        mavfile.__init__(self, self.port.fileno(), device, source_system=source_system)

    def recv(self):
        try:
            data, self.last_address = self.port.recvfrom(300)
        except socket.error, (enum, emsg):
            if enum == 11:
                return ""
            raise
        return data

    def write(self, buf):
        try:
            if self.connected:
                self.port.send(buf)
            else:
                self.port.sendto(buf, self.last_address)
        except socket.error:
            pass

    def recv_msg(self):
        '''message receive routine for UDP link'''
        self.pre_message()
        s = self.recv()
        if len(s) == 0:
            return None
        msg = self.mav.decode(s)
        if msg:
            self.post_message(msg)
        return msg


class mavlogfile(mavfile):
    '''a MAVLink logfile reader/writer'''
    def __init__(self, filename, planner_format=None,
                 write=False, append=False,
                 robust_parsing=True, notimestamps=False, source_system=255):
        self.filename = filename
        self.writeable = write
        self.robust_parsing = robust_parsing
        self.planner_format = planner_format
        self.notimestamps = notimestamps
        self._two64 = math.pow(2.0, 63)
        if planner_format is None and self.filename.endswith(".tlog"):
            self.planner_format = True
        mode = 'rb'
        if self.writeable:
            if append:
                mode = 'ab'
            else:
                mode = 'wb'
        self.f = open(filename, mode)
        mavfile.__init__(self, None, filename, source_system=source_system)

    def recv(self):
        return self.f.read(self.mav.bytes_needed())

    def pre_message(self):
        '''read timestamp if needed'''
        # read the timestamp
        if self.notimestamps:
            return
        if self.planner_format:
            tbuf = self.f.read(21)
            if len(tbuf) != 21 or tbuf[0] != '-' or tbuf[20] != ':':
                raise RuntimeError('bad planner timestamp %s' % tbuf)
            hnsec = self._two64 + float(tbuf[0:20])
            t = hnsec * 1.0e-7         # convert to seconds
            t -= 719163 * 24 * 60 * 60 # convert to 1970 base
        else:
            tbuf = self.f.read(8)
            if len(tbuf) != 8:
                return
            (tusec,) = struct.unpack('>Q', tbuf)
            t = tusec * 1.0e-6
        self._timestamp = t

    def post_message(self, msg):
        '''add timestamp to message'''
        # read the timestamp
        super(mavlogfile, self).post_message(msg)
        if self.notimestamps:
            msg._timestamp = time.time()
        else:
            msg._timestamp = self._timestamp
        if self.planner_format:
            self.f.read(1) # trailing newline

def mavlink_connection(device, baud=115200, source_system=255,
                       planner_format=None, write=False, append=False,
                       robust_parsing=True, notimestamps=False, input=True):
    '''make a serial or UDP mavlink connection'''
    if device.find(':') != -1:
        return mavudp(device, source_system=source_system, input=input)
    if os.path.isfile(device):
        return mavlogfile(device, planner_format=planner_format, write=write,
                          append=append, robust_parsing=robust_parsing, notimestamps=notimestamps,
                          source_system=source_system)
    return mavserial(device, baud=baud, source_system=source_system)

class periodic_event(object):
    '''a class for fixed frequency events'''
    def __init__(self, frequency):
        self.frequency = float(frequency)
        self.last_time = time.time()
    def trigger(self):
        '''return True if we should trigger now'''
        tnow = time.time()
        if self.last_time + (1.0/self.frequency) <= tnow:
            self.last_time = tnow
            return True
        return False

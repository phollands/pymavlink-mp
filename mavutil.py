#!/usr/bin/env python
'''
mavlink python utility functions

Copyright Andrew Tridgell 2011
Released under GNU GPL version 3 or later
'''

import mavlink, socket, math, struct, time
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


class mavfd(object):
    '''a generic mavlink port'''
    def __init__(self, fd, address):
        self.fd = fd
        self.address = address
        self.messages = {}
        self.mav = None

    def recv(self):
        '''default recv method'''
        raise RuntimeError('no recv() method supplied')

    def recv_msg(self):
        '''message receive routine'''
        while True:
            s = self.recv()
            if len(s) == 0:
                return None
            for c in s:
                msg = self.mav.parse_char(c)
                if msg:
                    self.messages[msg.get_type()] = msg
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
        

class mavserial(mavfd):
    '''a serial mavlink port'''
    def __init__(self, device, baud=115200, autoreconnect=False, source_system=255):
        import serial
        self.baud = baud
        self.device = device
        self.autoreconnect = autoreconnect
        self.port = serial.Serial(self.device, self.baud, timeout=1,
                                  dsrdtr=False, rtscts=False, xonxoff=False)

        try:
            fd = self.port.fileno()
        except Exception:
            fd = None
        mavfd.__init__(self, fd, device)

        self.mav = mavlink.MAVLink(self, srcSystem=source_system)
        self.mav.robust_parsing = True
        self.logfile = None
        self.logfile_raw = None

    def read(self):
        if self.fd is None:
            return self.port.read(self.port.inWaiting())
        return self.port.read()

    def recv(self):
        return self.read()

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
        

class mavudp(mavfd):
    '''a UDP mavlink socket'''
    def __init__(self, device, input=False, source_system=255):
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
        mavfd.__init__(self, self.port.fileno(), device)
        self.mav = mavlink.MAVLink(self, srcSystem=source_system)

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

def mavlink_connection(device, baud=115200, source_system=255):
    '''make a serial or UDP mavlink connection'''
    if device.find(':') != -1:
        return mavudp(device, source_system=source_system, input=True)
    return mavserial(device, baud=baud, source_system=source_system)


class mavlogfile(object):
    '''a MAVLink logfile reader/writer'''
    def __init__(self, filename, planner_format=None,
                 write=False, append=False,
                 robust_parsing=True, notimestamps=False):
        self.filename = filename
        self.write = write
        self.robust_parsing = robust_parsing
        self.planner_format = planner_format
        self.notimestamps = notimestamps
        self._two64 = math.pow(2.0, 63)
        self.mav_mode = (None, None)
        if planner_format is None and self.filename.endswith(".tlog"):
            self.planner_format = True
        mode = 'rb'
        if self.write:
            if append:
                mode = 'ab'
            else:
                mode = 'wb'
        self.f = open(filename, mode)
        self.mav = mavlink.MAVLink(None)
        self.mav.robust_parsing = robust_parsing
        self.messages = {}

    def read(self):
        '''read a single MAVLink message'''
        # read the timestamp
        if self.notimestamps:
            t = time.time()
        elif self.planner_format:
            tbuf = self.f.read(21)
            if len(tbuf) != 21 or tbuf[0] != '-' or tbuf[20] != ':':
                return None
            hnsec = self._two64 + float(tbuf[0:20])
            t = hnsec * 1.0e-7         # convert to seconds
            t -= 719163 * 24 * 60 * 60 # convert to 1970 base
        else:
            tbuf = self.f.read(8)
            if len(tbuf) != 8:
                return None
            (tusec,) = struct.unpack('>Q', tbuf)
            t = tusec * 1.0e-6


        # read the packet
        while True:
            c = self.f.read(1)
            if c == "":
                return None
            try:
                m = self.mav.parse_char(c)
            except mavlink.MAVError, msg:
                if self.robust_parsing:
                    continue
                raise
            if not m:
                continue
            if self.planner_format:
                self.f.read(1)
            if m.get_type() == 'SYS_STATUS':
                self.mav_mode = (m.mode, m.nav_mode)
            m._timestamp = t
            # keep the last message of each type
            self.messages[m.get_type()] = m
            return m

    def read_match(self, condition):
        '''read the next MAVLink message that matches the given condition'''
        while True:
            m = self.read()
            if m is None:
                return None
            if not evaluate_condition(condition, self.messages):
                continue
            return m

def mav_mode(mode):
    '''convert a mode specifier to a mode pair'''
    if mode is None:
        return None
    a = mode.split(',')
    return (int(a[0]), int(a[1]))

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

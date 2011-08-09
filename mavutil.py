#!/usr/bin/env python
'''
mavlink python utility functions

Copyright Andrew Tridgell 2011
Released under GNU GPL version 3 or later
'''

import mavlink, socket, math, struct, time

class mavfd(object):
    '''a generic mavlink port'''
    def __init__(self, fd, address):
        self.fd = fd
        self.address = address

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
        data, self.last_address = self.port.recvfrom(300)
        return data

    def write(self, buf):
        try:
            if self.connected:
                self.port.send(buf)
            else:
                self.port.sendto(buf, self.last_address)
        except socket.error:
            pass


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
            return m

    def read_match(self, mav_mode=None):
        '''read the next MAVLink message that matches the given parameters'''
        while True:
            m = self.read()
            if m is None:
                return None
            if mav_mode is not None and self.mav_mode != mav_mode:
                continue
            return m

def mav_mode(mode):
    '''convert a mode specifier to a mode pair'''
    if mode is None:
        return None
    a = mode.split(',')
    return (int(a[0]), int(a[1]))

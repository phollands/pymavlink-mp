#!/usr/bin/env python

'''
example program that dumps a Mavlink log file. The log file is
assumed to be in the format that qgroundcontrol uses, which consists
of a series of MAVLink packets, each with a 64 bit timestamp
header. The timestamp is in microseconds since 1970 (unix epoch)
'''

import sys, struct, time, os

# allow import from the parent directory, where mavlink.py is
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))

import mavlink

if len(sys.argv) < 2:
    print("Usage: mavlogdump.py <LOGFILE>")
    sys.exit(1)

filename = sys.argv[1]

f = open(filename, mode='r')

# create a mavlink instance, which will do IO on file object 'f'
mav = mavlink.MAVLink(None)

while True:
    # read the timestamp
    tbuf = f.read(8)
    if len(tbuf) != 8:
        break
    (tusec,) = struct.unpack('>Q', tbuf)
    t = time.localtime(tusec/1.0e6)

    # read the packet
    while True:
        c = f.read(1)
        m = mav.parse_char(c)
        if m:
            print("%s.%02u: %s" % (
                time.strftime("%F %T", t), (tusec/1e4)%100, m)
                  )
            break
    

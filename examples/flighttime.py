#!/usr/bin/env python

'''
work out total flight time for a mavlink log
'''

import sys, struct, time, os

# allow import from the parent directory, where mavlink.py is
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))

import mavlink

from optparse import OptionParser
parser = OptionParser("flighttime.py [options]")

parser.add_option("--no-timestamps",dest="notimestamps", action='store_true', help="Log doesn't have timestamps")
parser.add_option("--robust",dest="robust", action='store_true', help="Enable robust parsing")
(opts, args) = parser.parse_args()

if len(args) < 1:
    print("Usage: flighttime.py [options] <LOGFILE>")
    sys.exit(1)

filename = args[0]

f = open(filename, mode='r')

# create a mavlink instance, which will do IO on file object 'f'
mav = mavlink.MAVLink(None)
mav.robust_parsing = opts.robust

in_air = False
start_time = 0
total_time = 0

while True:
    # read the timestamp
    if not opts.notimestamps:
        tbuf = f.read(8)
        if len(tbuf) != 8:
            break
        (tusec,) = struct.unpack('>Q', tbuf)
        t = time.localtime(tusec/1.0e6)

    # read the packet
    while True:
        c = f.read(1)
        if c == "":
            sys.exit(0)
        m = mav.parse_char(c)
        if m:
            mtype = m.get_type()
            if mtype == "VFR_HUD":
                if m.groundspeed > 3.0 and not in_air:
                    print("In air at %s" % time.asctime(t))
                    in_air = True
                    start_time = time.mktime(t)
                elif m.groundspeed < 3.0 and in_air:
                    print("On ground at %s" % time.asctime(t))
                    in_air = False
                    total_time += time.mktime(t) - start_time
            break
print("Total time in air: %u:%02u" % (int(total_time)/60, int(total_time)%60))

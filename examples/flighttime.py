#!/usr/bin/env python

'''
work out total flight time for a mavlink log
'''

import sys, time, os

# allow import from the parent directory, where mavlink.py is
sys.path.insert(0, os.path.join(os.path.dirname(os.path.realpath(__file__)), '..'))

import mavutil

from optparse import OptionParser
parser = OptionParser("flighttime.py [options]")

(opts, args) = parser.parse_args()

if len(args) < 1:
    print("Usage: flighttime.py [options] <LOGFILE...>")
    sys.exit(1)

def flight_time(logfile):
    '''work out flight time for a log file'''
    print("Processing log %s" % filename)
    mlog = mavutil.mavlogfile(filename)

    in_air = False
    start_time = 0.0
    total_time = 0.0

    while True:
        m = mlog.read()
        if m is None:
            return total_time
        mtype = m.get_type()
        if mtype == "VFR_HUD":
            t = time.localtime(m._timestamp)
            if m.groundspeed > 3.0 and not in_air:
                print("In air at %s" % time.asctime(t))
                in_air = True
                start_time = time.mktime(t)
            elif m.groundspeed < 3.0 and in_air:
                print("On ground at %s" % time.asctime(t))
                in_air = False
                total_time += time.mktime(t) - start_time
    return total_time

total = 0.0
for filename in args:
    total += flight_time(filename)

print("Total time in air: %u:%02u" % (int(total)/60, int(total)%60))

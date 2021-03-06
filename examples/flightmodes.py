#!/usr/bin/env python

'''
show changes in flight modes
'''

import sys, time, os

# allow import from the parent directory, where mavlink.py is
sys.path.insert(0, os.path.join(os.path.dirname(os.path.realpath(__file__)), '..'))

import mavutil

from optparse import OptionParser
parser = OptionParser("flightmodes.py [options]")

(opts, args) = parser.parse_args()

if len(args) < 1:
    print("Usage: flightmodes.py [options] <LOGFILE...>")
    sys.exit(1)

def flight_modes(logfile):
    '''show flight modes for a log file'''
    print("Processing log %s" % filename)
    mlog = mavutil.mavlink_connection(filename)

    mode = -1
    nav_mode = -1

    while True:
        m = mlog.recv_match(type='SYS_STATUS',
                            condition='SYS_STATUS.mode != %u or SYS_STATUS.nav_mode != %u' % (mode, nav_mode))
        if m is None:
            return
        mode = m.mode
        nav_mode = m.nav_mode
        print('%s MAV.flightmode=%-12s mode=%u nav_mode=%u (MAV.timestamp=%u)' % (
            time.asctime(time.localtime(m._timestamp)),
            mlog.flightmode,
            mode, nav_mode, m._timestamp))

for filename in args:
    flight_modes(filename)



#!/usr/bin/env python

'''
example program that dumps a Mavlink log file. The log file is
assumed to be in the format that qgroundcontrol uses, which consists
of a series of MAVLink packets, each with a 64 bit timestamp
header. The timestamp is in microseconds since 1970 (unix epoch)
'''

import sys, struct, time, os

# allow import from the parent directory, where mavlink.py is
sys.path.insert(0, os.path.join(os.path.dirname(os.path.realpath(__file__)), '..'))

import mavlink

from optparse import OptionParser
parser = OptionParser("mavlogdump.py [options]")

parser.add_option("--no-timestamps",dest="notimestamps", action='store_true', help="Log doesn't have timestamps")
parser.add_option("--robust",dest="robust", action='store_true', help="Enable robust parsing")
(opts, args) = parser.parse_args()

if len(args) < 1:
    print("Usage: mavlogdump.py [options] <LOGFILE>")
    sys.exit(1)

filename = args[0]

f = open(filename, mode='rb')

# create a mavlink instance, which will do IO on file object 'f'
mav = mavlink.MAVLink(None)
mav.robust_parsing = opts.robust

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
            if opts.notimestamps:
                print("%s" % m)
            else:
                print("%s.%02u: %s" % (
                    time.strftime("%Y-%m-%d %H:%M:%S", t), (tusec/1e4)%100, m))
            break
    

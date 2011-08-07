#!/usr/bin/env python

'''
graph a MAVLink log file
'''

import sys, struct, time, os, datetime
import math
import numpy, pylab, matplotlib

# allow import from the parent directory, where mavlink.py is
sys.path.insert(0, os.path.join(os.path.dirname(os.path.realpath(__file__)), '..'))

import mavlink

def plotit(x, y, fields, colors=[], loc=None, plot_steps=None):
    '''convenience plotting function'''
    for i in range(0, len(fields)):
        pylab.ion()
        pylab.figure(num=1, figsize=(12,6))
        if i < len(colors):
            color = colors[i]
        else:
            color = 'red'
        pylab.plot_date(x[i], y[i], color=color, label=fields[i],
                        linestyle='-', marker='None')
        pylab.draw()
        if loc is not None:
            pylab.legend(loc=loc)
            pylab.draw()

from optparse import OptionParser
parser = OptionParser("mavgraph.py [options] <filename> <fields>")

parser.add_option("--no-timestamps",dest="notimestamps", action='store_true', help="Log doesn't have timestamps")
parser.add_option("--robust",dest="robust", action='store_true', help="Enable robust parsing")
parser.add_option("--planner",dest="planner", action='store_true', help="use planner file format")
(opts, args) = parser.parse_args()

if len(args) < 2:
    print("Usage: mavlogdump.py [options] <LOGFILES...> <fields...>")
    sys.exit(1)

filenames = []
fields = []
for f in args:
    if os.path.exists(f):
        filenames.append(f)
    else:
        fields.append(f)
msg_types = []
multiplier = []

colors = [ 'red', 'green', 'blue', 'yellow', 'olive', 'black', 'grey' ]

# work out msg types we are interested in
x = []
y = []
for f in fields:
    a = f.split('.')
    if len(a) != 2:
        print("Invalid field specifier %s" % f)
        print("You need to specify fields as MSGNAME.fieldname, for example ATTITUDE.pitch")
        sys.exit(1)
    if a[0] not in msg_types:
        msg_types.append(a[0])
    y.append([])
    x.append([])

# create a mavlink instance, which will do IO on file object 'f'
mav = mavlink.MAVLink(None)
mav.robust_parsing = opts.robust


def add_data(t, msg):
    '''add some data'''
    mtype = msg.get_type()
    if mtype not in msg_types:
        return
    for i in range(0, len(fields)):
        f = fields[i]
        a = f.split('.')
        fname = a[1]
        multiplier = 1.0
        if a[1].find(':') != -1:
            m = a[1].split(':')
            fname = m[0]
            type = m[1]
            if type == 'degrees':
                multiplier = 360.0 / (math.pi * 2.0)
            else:
                print("Unknown type '%s' in field specifier %s" % (type, f))
                sys.exit(1)
        if a[0] != mtype:
            continue
        v = float(getattr(msg, fname)) * multiplier
        y[i].append(v)
        x[i].append(t)


tbase = matplotlib.dates.date2num(datetime.datetime.strptime("1970-01-01 00:00", "%Y-%m-%d %H:%M"))
tbase1601 = matplotlib.dates.date2num(datetime.datetime.strptime("1601-01-01 00:00", "%Y-%m-%d %H:%M"))


def process_file(filename):
    '''process one file'''
    print("Processing %s" % filename)
    f = open(filename, mode='rb')

    while True:
        # read the timestamp
        if opts.planner:
            tbuf = f.read(21)
            if len(tbuf) != 21: break
            if tbuf[0] != '-':
                break
            if tbuf[20] != ':':
                break
            nsec1601 = math.pow(2.0, 64) + float(tbuf[0:20])
            t = nsec1601 / 1.0e7
            t -= 369 * 365.25 * 24 * 60 * 60
            t -= 30828 * 365.25 * 24 * 60 * 60
            t /= (24.0*60*60)
            t += tbase
        else:
            tbuf = f.read(8)
            if len(tbuf) != 8: break
            (tusec,) = struct.unpack('>Q', tbuf)
            t = tusec / (1.0e6 * (24*60*60))
            t += tbase

        # read the packet
        while True:
            c = f.read(1)
            if c == "": break
            m = mav.parse_char(c)
            if m:
                add_data(t, m)
                break
        if opts.planner:
            f.read(1)
    f.close()

for fi in range(0, len(filenames)):
    f = filenames[fi]
    process_file(f)
    plotit(x, y, fields, colors=colors[fi*len(fields):], loc='upper right')
    for i in range(0, len(x)):
        x[i] = []
        y[i] = []
pylab.show()
raw_input('press enter to exit....')

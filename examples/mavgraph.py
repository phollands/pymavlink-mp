#!/usr/bin/env python
'''
graph a MAVLink log file
Andrew Tridgell August 2011
'''

import sys, struct, time, os, datetime
import math, re
import pylab, pytz, matplotlib
from math import *

# allow import from the parent directory, where mavlink.py is
sys.path.insert(0, os.path.join(os.path.dirname(os.path.realpath(__file__)), '..'))

import mavutil

def plotit(x, y, fields, colors=[], loc=None):
    '''plot a set of graphs using date for x axis'''
    pylab.ion()
    fig = pylab.figure(num=1, figsize=(12,6))
    ax1 = fig.gca()
    ax2 = None
    formatter = matplotlib.dates.DateFormatter('%H:%M')
    ax1.xaxis.set_major_locator(matplotlib.dates.AutoDateLocator())
    ax1.xaxis.set_major_formatter(formatter)
    for i in range(0, len(fields)):
        if len(x[i]) == 0:
            print("Failed to find any values for field %s" % fields[i])
            continue
        if i < len(colors):
            color = colors[i]
        else:
            color = 'red'
        (tz, tzdst) = time.tzname
        if axes[i] == 2:
            if ax2 == None:
                ax2 = ax1.twinx()
            ax = ax2
            ax2.xaxis.set_major_locator(matplotlib.dates.AutoDateLocator())
            ax2.xaxis.set_major_formatter(formatter)
        else:
            ax = ax1
        ax.plot_date(x[i], y[i], color=color, label=fields[i],
                     linestyle='-', marker='None', tz=None)
        pylab.draw()
    if loc is not None:
        pylab.legend(loc=loc)
        pylab.draw()


from optparse import OptionParser
parser = OptionParser("mavgraph.py [options] <filename> <fields>")

parser.add_option("--no-timestamps",dest="notimestamps", action='store_true', help="Log doesn't have timestamps")
parser.add_option("--planner",dest="planner", action='store_true', help="use planner file format")
parser.add_option("--mode",dest="mode", default=None, help="select packets by mode,nav_mode")
(opts, args) = parser.parse_args()

if len(args) < 2:
    print("Usage: mavlogdump.py [options] <LOGFILES...> <fields...>")
    sys.exit(1)

mav_mode = mavutil.mav_mode(opts.mode)

filenames = []
fields = []
for f in args:
    if os.path.exists(f):
        filenames.append(f)
    else:
        fields.append(f)
msg_types = set()
multiplier = []
field_types = []

colors = [ 'red', 'green', 'blue', 'orange', 'olive', 'black', 'grey' ]

# work out msg types we are interested in
x = []
y = []
axes = []
re_caps = re.compile('[A-Z_]+')
for f in fields:
    caps = set(re.findall(re_caps, f))
    msg_types = msg_types.union(caps)
    field_types.append(caps)
    y.append([])
    x.append([])
    axes.append(1)

def interpret_field(msg, f):
    '''interpret a field specifier'''
    mtype = msg.get_type()
    for attr in msg._fieldnames:
        f = f.replace("%s.%s" % (mtype, attr), str(getattr(msg, attr)))
    v = eval(f)
    return v

def add_data(t, msg):
    '''add some data'''
    mtype = msg.get_type()
    if mtype not in msg_types:
        return
    for i in range(0, len(fields)):
        if mtype not in field_types[i]:
            continue
        f = fields[i]
        if f.endswith(":2"):
            axes[i] = 2
            f = f[:-2]
        try:
            v = interpret_field(msg, f)
        except Exception:
            continue
        y[i].append(v)
        x[i].append(t)


def process_file(filename):
    '''process one file'''
    print("Processing %s" % filename)
    mlog = mavutil.mavlogfile(filename, notimestamps=opts.notimestamps)

    while True:
        msg = mlog.read_match(mav_mode=mav_mode)
        if msg is None: break
        tdays = (msg._timestamp - time.timezone) / (24 * 60 * 60)
        tdays += 719163 # pylab wants it since 0001-01-01
        add_data(tdays, msg)

for fi in range(0, len(filenames)):
    f = filenames[fi]
    process_file(f)
    plotit(x, y, fields, colors=colors[fi*len(fields):], loc='upper right')
    for i in range(0, len(x)):
        x[i] = []
        y[i] = []
pylab.show()
raw_input('press enter to exit....')

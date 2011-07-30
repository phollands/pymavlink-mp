#!/usr/bin/env python
'''
parse a MAVLink protocol XML file and generate a python implementation

Copyright Andrew Tridgell 2011
Released under GNU GPL version 3 or later
'''

import sys, textwrap, os
from optparse import OptionParser
import mavutil
import mavgen_python

parser = OptionParser("mavgen.py [options] <XML files>")
parser.add_option("-o", "--output", dest="output", default="mavlink", help="output base name")
parser.add_option("--lang", dest="language", default="python", help="language to generate")
(opts, args) = parser.parse_args()

if len(args) < 1:
    parser.error("You must supply at least one MAVLink XML protocol definition")
    

msgs = []
enums = []

filelist = []

for fname in args:
    (m, e) = mavutil.parse_mavlink_xml(fname)
    msgs.extend(m)
    enums.extend(e)
    filelist.append(os.path.basename(fname))

if mavutil.check_duplicates(msgs):
    sys.exit(1)

print("Found %u MAVLink message types" % len(msgs))

if opts.language == 'python':
    mavgen_python.generate(opts.output, msgs, enums, filelist)
elif opts.language == 'C':
    mavgen_c.generate(opts.output, msgs, enums, filelist)
else:
    print("Unsupported language %s" % opts.language)
    

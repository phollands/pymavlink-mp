#!/usr/bin/env python
'''
parse a MAVLink protocol XML file and generate a python implementation

Copyright Andrew Tridgell 2011
Released under GNU GPL version 3 or later
'''

import sys, textwrap, os
from optparse import OptionParser
import mavparse
import mavgen_python
import mavgen_c

parser = OptionParser("mavgen.py [options] <XML files>")
parser.add_option("-o", "--output", dest="output", default="mavlink", help="output base name")
parser.add_option("--lang", dest="language", default="python", help="language to generate")
(opts, args) = parser.parse_args()

if len(args) < 1:
    parser.error("You must supply at least one MAVLink XML protocol definition")
    

xml = []

for fname in args:
    xml.append(mavparse.MAVXML(fname))

if mavparse.check_duplicates(xml):
    sys.exit(1)

print("Found %u MAVLink message types" % mavparse.total_msgs(xml))

if opts.language == 'python':
    mavgen_python.generate(opts.output, xml)
elif opts.language == 'C':
    mavgen_c.generate(opts.output, xml)
else:
    print("Unsupported language %s" % opts.language)
    

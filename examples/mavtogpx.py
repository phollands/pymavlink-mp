#!/usr/bin/env python

'''
example program to extract GPS data from a mavlink log, and create a GPX
file, for loading into google earth
'''

import sys, struct, time, os

# allow import from the parent directory, where mavlink.py is
sys.path.insert(0, os.path.join(os.path.dirname(os.path.realpath(__file__)), '..'))

import mavlink

if len(sys.argv) < 2:
    print("Usage: mavtogpx.py <LOGFILE>")
    sys.exit(1)

def mav_to_gpx(infilename, outfilename):
    '''convert a mavlink log file to a GPX file'''

    f = open(infilename, mode='r')
    outf = open(outfilename, mode='w')

    # create a mavlink instance, which will do IO on file object 'f'
    mav = mavlink.MAVLink(None)

    def process_packet(m, t):
        if m.get_type() != 'GPS_RAW' or m.fix_type != 2:
            return
        outf.write('''<trkpt lat="%s" lon="%s">
  <ele>%s</ele>
  <time>%s</time>
  <course>%s</course>
  <speed>%s</speed>
  <fix>3d</fix>
</trkpt>
''' % (m.lat, m.lon, m.alt,
       time.strftime("%FT%TZ", t),
       m.hdg, m.v))

    def add_header():
        outf.write('''<?xml version="1.0" encoding="UTF-8"?>
<gpx
  version="1.0"
  creator="pymavlink"
  xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xmlns="http://www.topografix.com/GPX/1/0"
  xsi:schemaLocation="http://www.topografix.com/GPX/1/0 http://www.topografix.com/GPX/1/0/gpx.xsd">
<trk>
<trkseg>
''')

    def add_footer():
        outf.write('''</trkseg>
</trk>
</gpx>
''')

    add_header()       

    mav.robust_parsing = True

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
            if len(c) != 1:
                break
            m = mav.parse_char(c)
            if m:
                process_packet(m, t)
                break
    add_footer()
    

infilename = sys.argv[1]
if len(sys.argv) > 2:
    outfilename = sys.argv[2]
else:
    outfilename = infilename + '.gpx'
    
mav_to_gpx(infilename, outfilename)

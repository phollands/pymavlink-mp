#!/usr/bin/env python
'''
parse a MAVLink protocol XML file and generate a python implementation

Copyright Andrew Tridgell 2011
Released under GNU GPL version 3 or later
'''

import sys, xml.parsers.expat, textwrap
from optparse import OptionParser

class MAVField(object):
    def __init__(self, name, type):
        self.name = name
        self.type = type
        self.description = ""


class MAVType(object):
    def __init__(self, name, id):
        self.name = name
        self.id = int(id)
        self.description = ""
        self.fields = []
        self.fieldnames = []
        self.fmtstr = ">"

def mavfmt(type):
    '''work out the struct format for a type'''
    map = {
        'float'    : 'f',
        'char'     : 'c',
        'int8_t'   : 'b',
        'uint8_t'  : 'B',
        'uint8_t_mavlink_version'  : 'B',
        'int16_t'  : 'h',
        'uint16_t' : 'H',
        'int32_t'  : 'i',
        'uint32_t' : 'I',
        'int64_t'  : 'q',
        'uint64_t' : 'Q',
        }

    if type in map:
        return map[type]
    if (type+"_t") in map:
        return map[type+"_t"]

    aidx = type.find("[")
    if aidx == -1 or type[-1:] != ']':
        raise RuntimeError("Unknown MAVLink type %s" % type)

    basetype = type[0:aidx]
    if basetype == "array":
        basetype = "uint8_t"
    basefmt = mavfmt(basetype)
    count = int(type[aidx+1:-1])

    if basefmt in ['c', 'b', 'B']:
        basefmt = 's'

    return str(count) + basefmt


def parse_mavlink_xml(fname):
    '''parse a mavlink XML file'''
    lastname = None
    msgs = []
    enums = []
    def start_element(name, attrs):
        lastname = name
        if name == 'message':
            msgs.append(MAVType(attrs['name'], attrs['id']))
        elif name == 'field':
            msgs[-1].fields.append(MAVField(attrs['name'], attrs['type']))
        elif name == 'entry':
            if not 'value' in attrs:
                print("No 'value' for entry '%s'" % attrs['name'])
            else:
                enums.append((attrs['name'], long(attrs['value'])))
    def char_data(data):
        if len(msgs) == 0:
            return
        if len(msgs[-1].fields) == 0:
            msgs[-1].description += data
        else:
            msgs[-1].fields[-1].description += data
    f = open(fname)
    p = xml.parsers.expat.ParserCreate()
    p.StartElementHandler = start_element
    p.CharacterDataHandler = char_data
    p.ParseFile(f)
    f.close()
    for m in msgs:
        for f in m.fields:
            m.fieldnames.append(f.name)
            m.fmtstr += mavfmt(f.type)
    return (msgs, enums)


def generate_preamble(outf, msgs, args):
    print("Generating preamble")
    outf.write("""
'''
MAVLink protocol implementation (auto-generated by mavgen.py)

Generated from: %s

Note: this file has been auto-generated. DO NOT EDIT
'''

import struct

def x25crc(buf):
    '''x25 CRC - based on checksum.h from mavlink library'''
    accum = 0xffff
    for b in buf:
        tmp = ord(b) ^ (accum & 0xff)
        tmp = (tmp ^ (tmp<<4)) & 0xFF
        accum = (accum>>8) ^ (tmp<<8) ^ (tmp<<3) ^ (tmp>>4)
        accum = accum & 0xFFFF
    return accum

class MAVLink_header(object):
    '''MAVLink message header'''
    def __init__(self, msgId, mlen=0, seq=0, srcSystem=0, srcComponent=0):
        self.mlen = mlen
        self.seq = seq
        self.srcSystem = srcSystem
        self.srcComponent = srcComponent
        self.msgId = msgId

    def pack(self):
        return struct.pack('cBBBBB', 'U', self.mlen, self.seq,
                          self.srcSystem, self.srcComponent, self.msgId)

class MAVLink_message(object):
    '''base MAVLink message class'''
    def __init__(self, msgId, name):
        self._header     = MAVLink_header(msgId)
        self._payload    = None
        self._msgbuf     = None
        self._crc        = None
        self._fieldnames = []
        self._type       = name

    def get_msgbuf(self):
        return self._msgbuf

    def get_header(self):
        return self._header

    def get_payload(self):
        return self._payload

    def get_crc(self):
        return self._crc

    def get_fieldnames(self):
        return self._fieldnames

    def get_type(self):
        return self._type

    def get_msgId(self):
        return self._header.msgId

    def __str__(self):
        ret = '%%s {' %% self._type
        for a in self._fieldnames:
            v = getattr(self, a)
            ret += '%%s : %%s, ' %% (a, v)
        ret = ret[0:-2] + '}'
        return ret            

    def pack(self, mav, payload):
        self._payload = payload
        self._header  = MAVLink_header(self._header.msgId, len(payload), mav.seq,
                                       mav.srcSystem, mav.srcComponent)
        self._msgbuf = self._header.pack() + payload
        self._crc = x25crc(self._msgbuf[1:])
        self._msgbuf += struct.pack('<H', self._crc)
        return self._msgbuf

""" % ",".join(args))


def generate_enums(outf, enums):
    print("Generating enums")
    outf.write("\n# enums\n")
    for (e,v) in enums:
	outf.write("%s = %u\n" % (e, v))

def generate_message_ids(outf, msgs):
    print("Generating message IDs")
    outf.write("\n# message IDs\n")
    for m in msgs:
	outf.write("MAVLINK_MSG_ID_%s = %u\n" % (m.name.upper(), m.id))

def generate_classes(outf, msgs):
    print("Generating class definitions")
    wrapper = textwrap.TextWrapper(initial_indent="\t", subsequent_indent="\t")
    for m in msgs:
	outf.write("""
class MAVLink_%s_message(MAVLink_message):
	'''
%s
	'''
	def __init__(self""" % (m.name.lower(), wrapper.fill(m.description.strip())))
        if len(m.fields) != 0:
        	outf.write(", " + ", ".join(m.fieldnames))
        outf.write("):\n")
        outf.write("\t\tMAVLink_message.__init__(self, MAVLINK_MSG_ID_%s, '%s')\n" % (m.name.upper(), m.name.upper()))
        if len(m.fieldnames) != 0:
        	outf.write("\t\tself._fieldnames = ['%s']\n" % "', '".join(m.fieldnames))
        for f in m.fields:
        	outf.write("\t\tself.%s = %s\n" % (f.name, f.name))
        outf.write("""
	def pack(self, mav):
		return MAVLink_message.pack(self, mav, struct.pack('%s'""" % m.fmtstr)
        if len(m.fields) != 0:
        	outf.write(", self." + ", self.".join(m.fieldnames))
        outf.write("))\n")


def generate_mavlink_class(outf, msgs):
    print("Generating MAVLink class")

    outf.write("\n\nmavlink_map = {\n");
    for m in msgs:
        outf.write("\tMAVLINK_MSG_ID_%s : ( '%s', MAVLink_%s_message ),\n" % (
            m.name.upper(), m.fmtstr, m.name.lower()))
    outf.write("}\n\n")
    
    outf.write("""
class MAVError(Exception):
	'''MAVLink error class'''
	def __init__(self, msg):
            Exception.__init__(self, msg)

class MAVString(str):
	'''NUL terminated string'''
	def __init__(self, s):
		str.__init__(self)
	def __str__(self):
            i = self.find(chr(0))
            if i == -1:
                return self[:]
            return self[0:i]
            
class MAVLink(object):
	'''MAVLink protocol handling class'''
	def __init__(self, file, srcSystem=0, srcComponent=0):
		self.seq = 0
		self.file = file
		self.srcSystem = srcSystem
		self.srcComponent = srcComponent
                self.callback = None
                self.callback_args = None
                self.callback_kwargs = None
                self.buf = ""
                self.expected_length = 0
                self.have_prefix_error = False

        def set_callback(self, callback, *args, **kwargs):
            self.callback = callback
            self.callback_args = args
            self.callback_kwargs = kwargs
            
	def send(self, mavmsg):
		'''send a MAVLink message'''
		buf = mavmsg.pack(self)
		self.file.write(buf)
		self.seq = (self.seq + 1) % 255

        def parse_char(self, c):
            self.buf += c
            if len(self.buf) == 1 and self.buf != 'U':
                magic = self.buf
                self.buf = ""
                if self.have_prefix_error:
                    return
                self.have_prefix_error = True
                raise MAVError("invalid MAVLink prefix '%s'" % magic) 
            self.have_prefix_error = False
            if len(self.buf) == 2:
                (magic, self.expected_length) = struct.unpack('cB', self.buf)
                self.expected_length += 8
            elif len(self.buf) == self.expected_length:
                mbuf = self.buf
                self.buf = ""
                self.expected_length = 0
                m = self.decode(mbuf)
                if self.callback:
                    self.callback(m, *self.callback_args, **self.callback_kwargs)
                return m
            return None

	def decode(self, msgbuf):
		'''decode a buffer as a MAVLink message'''
                # decode the header
                try:
                    magic, mlen, seq, srcSystem, srcComponent, msgId = struct.unpack('cBBBBB', msgbuf[:6])
                except struct.error, emsg:
                    raise MAVError('Unable to unpack MAVLink header: %s' % emsg)
                if magic != 'U':
                    raise MAVError("invalid MAVLink prefix '%s'" % magic)
                if mlen != len(msgbuf)-8:
                    raise MAVError('invalid MAVLink message length. Got %u expected %u, msgId=%u' % (len(msgbuf)-8, mlen, msgId))

                # decode the checksum
                try:
                    crc, = struct.unpack('<H', msgbuf[-2:])
                except struct.error, emsg:
                    raise MAVError('Unable to unpack MAVLink CRC: %s' % emsg)
                crc2 = x25crc(msgbuf[1:-2])
                if crc != crc2:
                    raise MAVError('invalid MAVLink CRC in msgID %u 0x%04x should be 0x%04x' % (msgId, crc, crc2))
                if not msgId in mavlink_map:
                    raise MAVError('unknown MAVLink message ID %u' % msgId)

                # decode the payload
                (fmt, type) = mavlink_map[msgId]
                try:
                    t = struct.unpack(fmt, msgbuf[6:-2])
                except struct.error, emsg:
                    raise MAVError('Unable to unpack MAVLink payload type=%s fmt=%s payloadLength=%u: %s' % (
                        type, fmt, len(msgbuf[6:-2]), emsg))

                # terminate any strings
                tlist = list(t)
                for i in range(0, len(tlist)):
                    if isinstance(tlist[i], str):
                        tlist[i] = MAVString(tlist[i])
                t = tuple(tlist)
                # construct the message object
                try:
                    m = type(*t)
                except Exception, emsg:
                    print tlist
                    raise MAVError('Unable to instantiate MAVLink message of type %s : %s' % (type, emsg))
                m._msgbuf = msgbuf
                m._payload = msgbuf[6:-2]
                m._crc = crc
                return m
""")

def generate_methods(outf, msgs):
    print("Generating methods")

    def field_descriptions(fields):
        ret = ""
        for f in fields:
            ret += "\t\t%-18s\t: %s (%s)\n" % (f.name, f.description.strip(), f.type)
        return ret

    wrapper = textwrap.TextWrapper(initial_indent="", subsequent_indent="\t\t")

    for m in msgs:
        comment = "%s\n\n%s" % (wrapper.fill(m.description.strip()), field_descriptions(m.fields))
	outf.write("""
	def %s_encode(%s):
		'''
		%s
		'''
		msg = MAVLink_%s_message(%s)
		msg.pack(self)
                return msg
""" %( m.name.lower(),
       ", ".join(["self"]+m.fieldnames),
       comment,
       m.name.lower(),
       ", ".join(m.fieldnames)))

	outf.write("""
	def %s_send(%s):
		'''
		%s
		'''
		return self.send(self.%s_encode(%s))
""" %( m.name.lower(),
       ", ".join(["self"]+m.fieldnames),
       comment,
       m.name.lower(),
       ", ".join(m.fieldnames)))



if __name__ == "__main__":
    parser = OptionParser("mavgen.py [options] <XML files>")
    parser.add_option("-o", "--output", dest="output", default="mavlink.py", help="output file")
    (opts, args) = parser.parse_args()

if len(args) < 1:
    parser.error("You must supply at least one MAVLink XML protocol definition")
    

msgs = []
enums = []

for fname in args:
	(m, e) = parse_mavlink_xml(fname)
        msgs.extend(m)
        enums.extend(e)

# check for duplicates
msgmap = {}
for m in msgs:
	if m.id in msgmap:
        	print("ERROR: Duplicate message id %u for %s also used by %s" % (
                	m.id, m.name, msgmap[m.id]))
        	sys.exit(1)
        msgmap[m.id] = m.name

print("Found %u MAVLink message types" % len(msgs))
print("Generating %s" % opts.output)

outf = open(opts.output, "w")

generate_preamble(outf, msgs, args)
generate_enums(outf, enums)
generate_message_ids(outf, msgs)
generate_classes(outf, msgs)
generate_mavlink_class(outf, msgs)
generate_methods(outf, msgs)
outf.close()
print("Generated %s OK" % opts.output)

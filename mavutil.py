#!/usr/bin/env python
'''
mavlink python utility functions

Copyright Andrew Tridgell 2011
Released under GNU GPL version 3 or later
'''

import xml.parsers.expat

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


def check_duplicates(msgs):
    '''check for duplicate message IDs'''
    msgmap = {}
    for m in msgs:
	if m.id in msgmap:
            print("ERROR: Duplicate message id %u for %s also used by %s" % (
                m.id, m.name, msgmap[m.id]))
            return True
        msgmap[m.id] = m.name
    return False


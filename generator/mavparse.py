#!/usr/bin/env python
'''
mavlink python parse functions

Copyright Andrew Tridgell 2011
Released under GNU GPL version 3 or later
'''

import xml.parsers.expat, os, time, sys

class MAVParseError(Exception):
    def __init__(self, message, inner_exception=None):
        self.message = message
        self.inner_exception = inner_exception
        self.exception_info = sys.exc_info()
    def __str__(self):
        return self.message

class MAVField(object):
    def __init__(self, name, type, xml, description=''):
        self.name = name
        self.description = description
        self.array_length = None
        self.omit_arg = False
        lengths = {
        'float'    : 4,
        'char'     : 1,
        'int8_t'   : 1,
        'uint8_t'  : 1,
        'uint8_t_mavlink_version'  : 1,
        'int16_t'  : 2,
        'uint16_t' : 2,
        'int32_t'  : 4,
        'uint32_t' : 4,
        'int64_t'  : 8,
        'uint64_t' : 8,
        }

        if type=='uint8_t_mavlink_version':
            type = 'uint8_t'
            self.omit_arg = True
            self.const_value = xml.version

        aidx = type.find("[")
        if aidx != -1:
            assert type[-1:] == ']'
            self.array_length = int(type[aidx+1:-1])
            type = type[0:aidx]
            if type == 'array':
                type = 'int8_t'
        if type in lengths:
            self.type_length = lengths[type]
            self.type = type
        elif (type+"_t") in lengths:
            self.type_length = lengths[type+"_t"]
            self.type = type+'_t'
        else:
            raise MAVParseError("unknown type '%s'" % type)
        if self.array_length is not None:
            self.wire_length = self.array_length * self.type_length
        else:
            self.wire_length = self.type_length

class MAVType(object):
    def __init__(self, name, id, linenumber, description=''):
        self.name = name
        self.name_lower = name.lower()
        self.linenumber = linenumber
        self.id = int(id)
        self.description = description
        self.fields = []
        self.fieldnames = []

class MAVEnumParam(object):
    def __init__(self, index, description=''):
        self.index = index
        self.description = description

class MAVEnumEntry(object):
    def __init__(self, name, value, description=''):
        self.name = name
        self.value = value
        self.description = description
        self.param = []

class MAVEnum(object):
    def __init__(self, name, description=''):
        self.name = name
        self.description = description
        self.entry = []
        self.next_value = 0

class MAVXML(object):
    '''parse a mavlink XML file'''
    def __init__(self, filename):
        self.filename = filename
        self.basename = os.path.basename(filename)
        if self.basename.lower().endswith(".xml"):
            self.basename = self.basename[:-4]
        self.basename_upper = self.basename.upper()
        self.message = []
        self.enum = []
        self.parse_time = time.asctime()
        self.version = 2
        self.include = []

        in_element_list = []

        def check_attrs(attrs, check, where):
            for c in check:
                if not c in attrs:
                    raise MAVParseError('expected missing %s "%s" attribute at %s:%u' % (
                        where, c, filename, p.CurrentLineNumber))

        def start_element(name, attrs):
            in_element_list.append(name)
            in_element = '.'.join(in_element_list)
            #print in_element
            if in_element == "mavlink.messages.message":
                check_attrs(attrs, ['name', 'id'], 'message')
                self.message.append(MAVType(attrs['name'], attrs['id'], p.CurrentLineNumber))
            elif in_element == "mavlink.messages.message.field":
                check_attrs(attrs, ['name', 'type'], 'field')
                self.message[-1].fields.append(MAVField(attrs['name'], attrs['type'], self))
            elif in_element == "mavlink.enums.enum":
                check_attrs(attrs, ['name'], 'enum')
                self.enum.append(MAVEnum(attrs['name']))
            elif in_element == "mavlink.enums.enum.entry":
                check_attrs(attrs, ['name'], 'enum entry')
                if 'value' in attrs:
                    value = long(attrs['value'])
                else:
                    value = self.enum[-1].next_value
                self.enum[-1].next_value = value+1
                self.enum[-1].entry.append(MAVEnumEntry(attrs['name'], value))
            elif in_element == "mavlink.enums.enum.entry.param":
                check_attrs(attrs, ['index'], 'enum param')
                self.enum[-1].entry[-1].param.append(MAVEnumParam(attrs['index']))

        def end_element(name):
            in_element_list.pop()

        def char_data(data):
            in_element = '.'.join(in_element_list)
            if in_element == "mavlink.messages.message.description":
                self.message[-1].description += data
            elif in_element == "mavlink.messages.message.field":
                self.message[-1].fields[-1].description += data
            elif in_element == "mavlink.enums.enum.description":
                self.enum[-1].description += data
            elif in_element == "mavlink.enums.enum.entry.description":
                self.enum[-1].entry[-1].description += data
            elif in_element == "mavlink.enums.enum.entry.param":
                self.enum[-1].entry[-1].param[-1].description += data
            elif in_element == "mavlink.version":
                self.version = int(data)
            elif in_element == "mavlink.include":
                self.include.append(data)

        f = open(filename)
        p = xml.parsers.expat.ParserCreate()
        p.StartElementHandler = start_element
        p.EndElementHandler = end_element
        p.CharacterDataHandler = char_data
        p.ParseFile(f)
        f.close()

        for m in self.message:
            m.wire_length = 0
            m.fieldnames = []
            for f in m.fields:
                f.wire_offset = m.wire_length
                m.wire_length += f.wire_length
                m.fieldnames.append(f.name)


    def __str__(self):
        return "MAVXML for %s from %s (%u message, %u enums)" % (
            self.basename, self.filename, len(self.message), len(self.enum))
    



def check_duplicates(xml):
    '''check for duplicate message IDs'''
    msgmap = {}
    for x in xml:
        for m in x.message:
            if m.id in msgmap:
                print("ERROR: Duplicate message id %u for %s (%s:%u) also used by %s" % (
                    m.id, m.name,
                    x.filename, m.linenumber,
                    msgmap[m.id]))
                return True
            msgmap[m.id] = '%s (%s:%u)' % (m.name, x.filename, m.linenumber)
    return False



def total_msgs(xml):
    '''count total number of msgs'''
    count = 0
    for x in xml:
        count += len(x.message)
    return count

def mkdir_p(dir):
    '''like mkdir -p'''
    if not dir:
        return
    if dir.endswith("/"):
        mkdir_p(dir[:-1])
        return
    if os.path.isdir(dir):
        return
    mkdir_p(os.path.dirname(dir))
    os.mkdir(dir)

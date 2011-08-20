#!/usr/bin/env python
'''
mavlink python parse functions

Copyright Andrew Tridgell 2011
Released under GNU GPL version 3 or later
'''

import xml.parsers.expat, os, time

class MAVField(object):
    def __init__(self, name, type, description=''):
        self.name = name
        self.description = description
        self.array_length = None
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

        aidx = type.find("[")
        if aidx != -1:
            assert type[-1:] == ']'
            self.array_length = int(type[aidx+1:-1])
            type = type[0:aidx]
            if type == 'array':
                type = 'uint8_t'
        if type in lengths:
            self.type_length = lengths[type]
            self.type = type
        elif (type+"_t") in lengths:
            self.type_length = lengths[type+"_t"]
            self.type = type+'_t'
        else:
            raise RuntimeError("unknown type '%s'" % type)
        if self.array_length is not None:
            self.wire_length = self.array_length * self.type_length
        else:
            self.wire_length = self.type_length

class MAVType(object):
    def __init__(self, name, id, description=''):
        self.name = name
        self.name_lower = name.lower()
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
        self.version = None

        in_element_list = []

        def start_element(name, attrs):
            in_element_list.append(name)
            in_element = '.'.join(in_element_list)
            #print in_element
            if in_element == "mavlink.messages.message":
                self.message.append(MAVType(attrs['name'], attrs['id']))
            elif in_element == "mavlink.messages.message.field":
                self.message[-1].fields.append(MAVField(attrs['name'], attrs['type']))
            elif in_element == "mavlink.enums.enum":
                self.enum.append(MAVEnum(attrs['name']))
            elif in_element == "mavlink.enums.enum.entry":
                self.enum[-1].entry.append(MAVEnumEntry(attrs['name'], long(attrs['value'])))
            elif in_element == "mavlink.enums.enum.entry.param":
                self.enum[-1].entry[-1].param.append(MAVEnumParam(attrs['index']))

        def end_element(name):
            in_element_list.pop()
            in_element = '.'.join(in_element_list)

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
                print("ERROR: Duplicate message id %u for %s also used by %s" % (
                    m.id, m.name, msgmap[m.id]))
                return True
            msgmap[m.id] = m.name
    return False

def find_end(text, start_token, end_token):
    '''cope with nested expressions'''
    offset = 0
    while True:
        idx1 = text[offset:].find(start_token)
        idx2 = text[offset:].find(end_token)
        if idx1 == -1 and idx2 == -1:
            return -1
        if idx1 == -1:
            return idx2 + offset
        if idx1 > idx2:
            return idx2 + offset
        offset += idx2
    

def substring(text, subvars={}, trim_leading_lf=True, checkmissing=True):
    '''substitute variables in a string'''
    while True:
        subidx = text.find('${{')
        if subidx == -1:
            break
        endidx = find_end(text[subidx:], '${{', '}}')
        if endidx == -1:
            break
        a = text[subidx+3:subidx+endidx].split(':')
        field_name = a[0]
        rest = ':'.join(a[1:])
        v = getattr(subvars, field_name)
        if v is None:
            raise RuntimeError('unable to find field %s' % field_name)
        t1 = text[0:subidx]
        for f in v:
            t1 += substring(rest, f, trim_leading_lf=False, checkmissing=False)
        if len(v) != 0 and t1[-1] in ["\n", ","]:
            t1 = t1[:-1]
        t1 += text[subidx+endidx+2:]
        text = t1
                
    if trim_leading_lf:
        if text[0] == '\n':
            text = text[1:]
    while True:
        idx = text.find('${')
        if idx == -1:
            return text
        endidx = text[idx:].find('}')
        if endidx == -1:
            raise RuntimeError('missing end of variable: %s' % text[idx:idx+10])
        varname = text[idx+2:idx+endidx]
        if isinstance(subvars, dict):
            if not varname in subvars:
                raise RuntimeError("unknown variable in '${%s}'" % varname)
            value = subvars[varname]
        else:
            value = getattr(subvars, varname, None)
            if varname is None:
                raise RuntimeError("unknown variable in '${%s}'" % varname)
        text = text.replace("${%s}" % varname, str(value))
    return text

def subwrite(file, text, subvars={}, trim_leading_lf=True):
    '''write to a file with variable substitution'''
    file.write(substring(text, subvars=subvars, trim_leading_lf=trim_leading_lf))
    

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


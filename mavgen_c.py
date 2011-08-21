#!/usr/bin/env python
'''
parse a MAVLink protocol XML file and generate a C implementation

Copyright Andrew Tridgell 2011
Released under GNU GPL version 3 or later
'''

import sys, textwrap, os, time
import mavparse, mavtemplate

t = mavtemplate.MAVTemplate()

def generate_mavlink_h(directory, xml):
    '''generate mavlink.h'''
    f = open(os.path.join(directory, "mavlink.h"), mode='w')
    t.write(f,'''
/** @file
 *	@brief MAVLink comm protocol built from ${basename}.xml
 *	@see http://pixhawk.ethz.ch/software/mavlink
 *	Generated on ${parse_time}
 */
#ifndef MAVLINK_H
#define MAVLINK_H

#include "${basename}.h"

#endif // MAVLINK_H
''', xml)
    f.close()

def generate_main_h(directory, xml):
    '''generate main header per XML file'''
    f = open(os.path.join(directory, xml.basename + ".h"), mode='w')
    t.write(f, '''
/** @file
 *	@brief MAVLink comm protocol generated from ${basename}.xml
 *	@see http://qgroundcontrol.org/mavlink/
 *	Generated on ${parse_time}
 */
#ifndef ${basename_upper}_H
#define ${basename_upper}_H

#ifdef __cplusplus
extern "C" {
#endif


#include "../protocol.h"

#define MAVLINK_ENABLED_${basename_upper}

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION ${version}
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION ${version}
#endif

// ENUM DEFINITIONS

${{enum:
/** @brief ${description} */
enum ${name}
{
${{entry:	${name}=${value}, /* ${description} |${{param:${description}| }} */
}}
};
}}

// MESSAGE DEFINITIONS
${{message:#include "./mavlink_msg_${name_lower}.h
}}

// MESSAGE LENGTHS

#undef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {${{message: ${wire_length},}} }
    
#ifdef __cplusplus
}
#endif // __cplusplus
#endif // ${basename_upper}_H
''', xml)

    f.close()
             

def generate_message_h(directory, m):
    '''generate per-message header for a XML file'''
    f = open(os.path.join(directory, 'mavlink_msg_%s.h' % m.name_lower), mode='w')
    t.write(f, '''
// MESSAGE ${name} PACKING

#define MAVLINK_MSG_ID_${name} ${id}

typedef struct __mavlink_${name_lower}_t
{
${{fields: ${type} ${name}${array_suffix}; ///< ${description}
}}
} mavlink_${name_lower}_t;

/**
 * @brief Pack a ${name_lower} message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
${{fields: * @param ${name} ${description}
}}
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_${name_lower}_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						      ${{fields: ${type} ${name}${array_suffix},}})
{
	msg->msgid = MAVLINK_MSG_ID_${name};

${{fields:	put_${type}${array_tag}_by_index(${name}, ${wire_offset}, ${array_arg} msg->payload); // ${description}
}}

	return mavlink_finalize_message(msg, system_id, component_id, ${wire_length});
}

/**
 * @brief Pack a ${name_lower} message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
${{fields: * @param ${name} ${description}
}}
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_${name_lower}_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           ${{fields:${type} ${name}${array_suffix},}})
{
	msg->msgid = MAVLINK_MSG_ID_${name};

${{fields:	put_${type}${array_tag}_by_index(${name}, ${wire_offset}, ${array_arg} msg->payload); // ${description}
}}

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, ${wire_length});
}

/**
 * @brief Encode a ${name_lower} struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ${name_lower} C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_${name_lower}_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_${name_lower}_t* ${name_lower})
{
	return mavlink_msg_${name_lower}_pack(system_id, component_id, msg,${{fields: ${name_lower}->${name},}});
}

/**
 * @brief Send a ${name_lower} message
 * @param chan MAVLink channel to send the message
 *
${{fields: * @param ${name} ${description}
}}
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_${name_lower}_send(mavlink_channel_t chan,${{fields: ${type} ${name}${array_suffix},}})
{
	mavlink_message_t msg;
	mavlink_msg_${name_lower}_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg,${{fields: ${name},}});
	mavlink_send_uart(chan, &msg);
}

#endif

// MESSAGE ${name} UNPACKING

${{fields:
/**
 * @brief Get field ${name} from ${name_lower} message
 *
 * @return ${description}
 */
static inline ${return_type} mavlink_msg_${name_lower}_get_${name}(const mavlink_message_t* msg${get_arg})
{
	MAVLINK_MSG_RETURN_${type}${array_tag}(msg, ${array_return_arg} ${wire_offset});
}
}}

/**
 * @brief Decode a ${name_lower} message into a struct
 *
 * @param msg The message to decode
 * @param ${name_lower} C-struct to decode the message contents into
 */
static inline void mavlink_msg_${name_lower}_decode(const mavlink_message_t* msg, mavlink_${name_lower}_t* ${name_lower})
{
${{fields:	${name_lower}->${name} = mavlink_msg_${name_lower}_get_${name}(msg);
}}
}
''', m)
    f.close()


def generate_one(basename, xml):
    '''generate headers for one XML file'''

    directory = os.path.join(basename, xml.basename)

    print("Generating C implementation in directory %s" % directory)
    mavparse.mkdir_p(directory)

    # add some extra field attributes for convenience with arrays
    for m in xml.message:
        for f in m.fields:
            if f.array_length is not None:
                f.array_suffix = '[%u]' % f.array_length
                f.array_tag = '_array'
                f.array_arg = '%u, ' % f.array_length
                f.array_return_arg = '%s, %u, ' % (f.name, f.array_length)
                f.return_type = 'uint16_t'
                f.get_arg = ', %s *%s' % (f.type, f.name)
            else:
                f.array_suffix = ''
                f.array_tag = ''
                f.array_arg = ''
                f.array_return_arg = ''
                f.get_arg = ''
                f.return_type = f.type

    generate_mavlink_h(directory, xml)
    generate_main_h(directory, xml)
    for m in xml.message:
        generate_message_h(directory, m)


def generate(basename, xml_list):
    '''generate complete MAVLink C implemenation'''

    for xml in xml_list:
        generate_one(basename, xml)

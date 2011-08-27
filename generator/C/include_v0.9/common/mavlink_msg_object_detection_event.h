// MESSAGE OBJECT_DETECTION_EVENT PACKING

#define MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT 140

typedef struct __mavlink_object_detection_event_t
{
 uint32_t time; ///< Timestamp in milliseconds since system boot
 uint16_t object_id; ///< Object ID
 uint8_t type; ///< Object type: 0: image, 1: letter, 2: ground vehicle, 3: air vehicle, 4: surface vehicle, 5: sub-surface vehicle, 6: human, 7: animal
 char name[20]; ///< Name of the object as defined by the detector
 uint8_t quality; ///< Detection quality / confidence. 0: bad, 255: maximum confidence
 float bearing; ///< Angle of the object with respect to the body frame in NED coordinates in radians. 0: front
 float distance; ///< Ground distance in meters
} mavlink_object_detection_event_t;

#define MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN 36
#define MAVLINK_MSG_ID_140_LEN 36

#define MAVLINK_MSG_OBJECT_DETECTION_EVENT_FIELD_NAME_LEN 20

#define MAVLINK_MESSAGE_INFO_OBJECT_DETECTION_EVENT { \
	"OBJECT_DETECTION_EVENT", \
	7, \
	{  { "time", MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_object_detection_event_t, time) }, \
         { "object_id", MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_object_detection_event_t, object_id) }, \
         { "type", MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_object_detection_event_t, type) }, \
         { "name", MAVLINK_TYPE_CHAR, 20, 7, offsetof(mavlink_object_detection_event_t, name) }, \
         { "quality", MAVLINK_TYPE_UINT8_T, 0, 27, offsetof(mavlink_object_detection_event_t, quality) }, \
         { "bearing", MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_object_detection_event_t, bearing) }, \
         { "distance", MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_object_detection_event_t, distance) }, \
         } \
}


/**
 * @brief Pack a object_detection_event message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time Timestamp in milliseconds since system boot
 * @param object_id Object ID
 * @param type Object type: 0: image, 1: letter, 2: ground vehicle, 3: air vehicle, 4: surface vehicle, 5: sub-surface vehicle, 6: human, 7: animal
 * @param name Name of the object as defined by the detector
 * @param quality Detection quality / confidence. 0: bad, 255: maximum confidence
 * @param bearing Angle of the object with respect to the body frame in NED coordinates in radians. 0: front
 * @param distance Ground distance in meters
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_object_detection_event_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t time, uint16_t object_id, uint8_t type, const char *name, uint8_t quality, float bearing, float distance)
{
	msg->msgid = MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT;

	put_uint32_t_by_index(msg, 0, time); // Timestamp in milliseconds since system boot
	put_uint16_t_by_index(msg, 4, object_id); // Object ID
	put_uint8_t_by_index(msg, 6, type); // Object type: 0: image, 1: letter, 2: ground vehicle, 3: air vehicle, 4: surface vehicle, 5: sub-surface vehicle, 6: human, 7: animal
	put_char_array_by_index(msg, 7, name, 20); // Name of the object as defined by the detector
	put_uint8_t_by_index(msg, 27, quality); // Detection quality / confidence. 0: bad, 255: maximum confidence
	put_float_by_index(msg, 28, bearing); // Angle of the object with respect to the body frame in NED coordinates in radians. 0: front
	put_float_by_index(msg, 32, distance); // Ground distance in meters

	return mavlink_finalize_message(msg, system_id, component_id, 36);
}

/**
 * @brief Pack a object_detection_event message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param time Timestamp in milliseconds since system boot
 * @param object_id Object ID
 * @param type Object type: 0: image, 1: letter, 2: ground vehicle, 3: air vehicle, 4: surface vehicle, 5: sub-surface vehicle, 6: human, 7: animal
 * @param name Name of the object as defined by the detector
 * @param quality Detection quality / confidence. 0: bad, 255: maximum confidence
 * @param bearing Angle of the object with respect to the body frame in NED coordinates in radians. 0: front
 * @param distance Ground distance in meters
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_object_detection_event_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t time,uint16_t object_id,uint8_t type,const char *name,uint8_t quality,float bearing,float distance)
{
	msg->msgid = MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT;

	put_uint32_t_by_index(msg, 0, time); // Timestamp in milliseconds since system boot
	put_uint16_t_by_index(msg, 4, object_id); // Object ID
	put_uint8_t_by_index(msg, 6, type); // Object type: 0: image, 1: letter, 2: ground vehicle, 3: air vehicle, 4: surface vehicle, 5: sub-surface vehicle, 6: human, 7: animal
	put_char_array_by_index(msg, 7, name, 20); // Name of the object as defined by the detector
	put_uint8_t_by_index(msg, 27, quality); // Detection quality / confidence. 0: bad, 255: maximum confidence
	put_float_by_index(msg, 28, bearing); // Angle of the object with respect to the body frame in NED coordinates in radians. 0: front
	put_float_by_index(msg, 32, distance); // Ground distance in meters

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 36);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

/**
 * @brief Pack a object_detection_event message on a channel and send
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param time Timestamp in milliseconds since system boot
 * @param object_id Object ID
 * @param type Object type: 0: image, 1: letter, 2: ground vehicle, 3: air vehicle, 4: surface vehicle, 5: sub-surface vehicle, 6: human, 7: animal
 * @param name Name of the object as defined by the detector
 * @param quality Detection quality / confidence. 0: bad, 255: maximum confidence
 * @param bearing Angle of the object with respect to the body frame in NED coordinates in radians. 0: front
 * @param distance Ground distance in meters
 */
static inline void mavlink_msg_object_detection_event_pack_chan_send(mavlink_channel_t chan,
							   mavlink_message_t* msg,
						           uint32_t time,uint16_t object_id,uint8_t type,const char *name,uint8_t quality,float bearing,float distance)
{
	msg->msgid = MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT;

	put_uint32_t_by_index(msg, 0, time); // Timestamp in milliseconds since system boot
	put_uint16_t_by_index(msg, 4, object_id); // Object ID
	put_uint8_t_by_index(msg, 6, type); // Object type: 0: image, 1: letter, 2: ground vehicle, 3: air vehicle, 4: surface vehicle, 5: sub-surface vehicle, 6: human, 7: animal
	put_char_array_by_index(msg, 7, name, 20); // Name of the object as defined by the detector
	put_uint8_t_by_index(msg, 27, quality); // Detection quality / confidence. 0: bad, 255: maximum confidence
	put_float_by_index(msg, 28, bearing); // Angle of the object with respect to the body frame in NED coordinates in radians. 0: front
	put_float_by_index(msg, 32, distance); // Ground distance in meters

	mavlink_finalize_message_chan_send(msg, chan, 36);
}
#endif // MAVLINK_USE_CONVENIENCE_FUNCTIONS


/**
 * @brief Encode a object_detection_event struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param object_detection_event C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_object_detection_event_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_object_detection_event_t* object_detection_event)
{
	return mavlink_msg_object_detection_event_pack(system_id, component_id, msg, object_detection_event->time, object_detection_event->object_id, object_detection_event->type, object_detection_event->name, object_detection_event->quality, object_detection_event->bearing, object_detection_event->distance);
}

/**
 * @brief Send a object_detection_event message
 * @param chan MAVLink channel to send the message
 *
 * @param time Timestamp in milliseconds since system boot
 * @param object_id Object ID
 * @param type Object type: 0: image, 1: letter, 2: ground vehicle, 3: air vehicle, 4: surface vehicle, 5: sub-surface vehicle, 6: human, 7: animal
 * @param name Name of the object as defined by the detector
 * @param quality Detection quality / confidence. 0: bad, 255: maximum confidence
 * @param bearing Angle of the object with respect to the body frame in NED coordinates in radians. 0: front
 * @param distance Ground distance in meters
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_object_detection_event_send(mavlink_channel_t chan, uint32_t time, uint16_t object_id, uint8_t type, const char *name, uint8_t quality, float bearing, float distance)
{
	MAVLINK_ALIGNED_MESSAGE(msg, 36);
	mavlink_msg_object_detection_event_pack_chan_send(chan, msg, time, object_id, type, name, quality, bearing, distance);
}

#endif

// MESSAGE OBJECT_DETECTION_EVENT UNPACKING


/**
 * @brief Get field time from object_detection_event message
 *
 * @return Timestamp in milliseconds since system boot
 */
static inline uint32_t mavlink_msg_object_detection_event_get_time(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field object_id from object_detection_event message
 *
 * @return Object ID
 */
static inline uint16_t mavlink_msg_object_detection_event_get_object_id(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field type from object_detection_event message
 *
 * @return Object type: 0: image, 1: letter, 2: ground vehicle, 3: air vehicle, 4: surface vehicle, 5: sub-surface vehicle, 6: human, 7: animal
 */
static inline uint8_t mavlink_msg_object_detection_event_get_type(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field name from object_detection_event message
 *
 * @return Name of the object as defined by the detector
 */
static inline uint16_t mavlink_msg_object_detection_event_get_name(const mavlink_message_t* msg, char *name)
{
	return MAVLINK_MSG_RETURN_char_array(msg, name, 20,  7);
}

/**
 * @brief Get field quality from object_detection_event message
 *
 * @return Detection quality / confidence. 0: bad, 255: maximum confidence
 */
static inline uint8_t mavlink_msg_object_detection_event_get_quality(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  27);
}

/**
 * @brief Get field bearing from object_detection_event message
 *
 * @return Angle of the object with respect to the body frame in NED coordinates in radians. 0: front
 */
static inline float mavlink_msg_object_detection_event_get_bearing(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  28);
}

/**
 * @brief Get field distance from object_detection_event message
 *
 * @return Ground distance in meters
 */
static inline float mavlink_msg_object_detection_event_get_distance(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  32);
}

/**
 * @brief Decode a object_detection_event message into a struct
 *
 * @param msg The message to decode
 * @param object_detection_event C-struct to decode the message contents into
 */
static inline void mavlink_msg_object_detection_event_decode(const mavlink_message_t* msg, mavlink_object_detection_event_t* object_detection_event)
{
#if MAVLINK_NEED_BYTE_SWAP
	object_detection_event->time = mavlink_msg_object_detection_event_get_time(msg);
	object_detection_event->object_id = mavlink_msg_object_detection_event_get_object_id(msg);
	object_detection_event->type = mavlink_msg_object_detection_event_get_type(msg);
	mavlink_msg_object_detection_event_get_name(msg, object_detection_event->name);
	object_detection_event->quality = mavlink_msg_object_detection_event_get_quality(msg);
	object_detection_event->bearing = mavlink_msg_object_detection_event_get_bearing(msg);
	object_detection_event->distance = mavlink_msg_object_detection_event_get_distance(msg);
#else
	memcpy(object_detection_event, MAVLINK_PAYLOAD(msg), 36);
#endif
}

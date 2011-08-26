// MESSAGE PARAM_SET PACKING

#define MAVLINK_MSG_ID_PARAM_SET 23

typedef struct __mavlink_param_set_t
{
 uint8_t target_system; ///< System ID
 uint8_t target_component; ///< Component ID
 int8_t param_id[15]; ///< Onboard parameter id
 float param_value; ///< Onboard parameter value
} mavlink_param_set_t;

#define MAVLINK_MESSAGE_INFO_PARAM_SET { \
	"PARAM_SET", \
	4, \
	{  { "target_system", MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_param_set_t, target_system) }, \
         { "target_component", MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_param_set_t, target_component) }, \
         { "param_id", MAVLINK_TYPE_INT8_T, 15, 2, offsetof(mavlink_param_set_t, param_id) }, \
         { "param_value", MAVLINK_TYPE_FLOAT, 0, 17, offsetof(mavlink_param_set_t, param_value) }, \
         } \
}


/**
 * @brief Pack a param_set message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param param_id Onboard parameter id
 * @param param_value Onboard parameter value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_set_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, const int8_t *param_id, float param_value)
{
	msg->msgid = MAVLINK_MSG_ID_PARAM_SET;

	put_uint8_t_by_index(target_system, 0,  MAVLINK_PAYLOAD(msg)); // System ID
	put_uint8_t_by_index(target_component, 1,  MAVLINK_PAYLOAD(msg)); // Component ID
	put_int8_t_array_by_index(param_id, 2, 15,  MAVLINK_PAYLOAD(msg)); // Onboard parameter id
	put_float_by_index(param_value, 17,  MAVLINK_PAYLOAD(msg)); // Onboard parameter value

	return mavlink_finalize_message(msg, system_id, component_id, 21, 142);
}

/**
 * @brief Pack a param_set message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param param_id Onboard parameter id
 * @param param_value Onboard parameter value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_set_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,const int8_t *param_id,float param_value)
{
	msg->msgid = MAVLINK_MSG_ID_PARAM_SET;

	put_uint8_t_by_index(target_system, 0,  MAVLINK_PAYLOAD(msg)); // System ID
	put_uint8_t_by_index(target_component, 1,  MAVLINK_PAYLOAD(msg)); // Component ID
	put_int8_t_array_by_index(param_id, 2, 15,  MAVLINK_PAYLOAD(msg)); // Onboard parameter id
	put_float_by_index(param_value, 17,  MAVLINK_PAYLOAD(msg)); // Onboard parameter value

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 21, 142);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

/**
 * @brief Pack a param_set message on a channel and send
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param param_id Onboard parameter id
 * @param param_value Onboard parameter value
 */
static inline void mavlink_msg_param_set_pack_chan_send(mavlink_channel_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,const int8_t *param_id,float param_value)
{
	msg->msgid = MAVLINK_MSG_ID_PARAM_SET;

	put_uint8_t_by_index(target_system, 0,  MAVLINK_PAYLOAD(msg)); // System ID
	put_uint8_t_by_index(target_component, 1,  MAVLINK_PAYLOAD(msg)); // Component ID
	put_int8_t_array_by_index(param_id, 2, 15,  MAVLINK_PAYLOAD(msg)); // Onboard parameter id
	put_float_by_index(param_value, 17,  MAVLINK_PAYLOAD(msg)); // Onboard parameter value

	mavlink_finalize_message_chan_send(msg, chan, 21, 142);
}
#endif // MAVLINK_USE_CONVENIENCE_FUNCTIONS


/**
 * @brief Encode a param_set struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param param_set C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_set_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_param_set_t* param_set)
{
	return mavlink_msg_param_set_pack(system_id, component_id, msg, param_set->target_system, param_set->target_component, param_set->param_id, param_set->param_value);
}

/**
 * @brief Send a param_set message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param param_id Onboard parameter id
 * @param param_value Onboard parameter value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_param_set_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, const int8_t *param_id, float param_value)
{
	MAVLINK_ALIGNED_MESSAGE(msg, 21);
	mavlink_msg_param_set_pack_chan_send(chan, msg, target_system, target_component, param_id, param_value);
}

#endif

// MESSAGE PARAM_SET UNPACKING


/**
 * @brief Get field target_system from param_set message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_param_set_get_target_system(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from param_set message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_param_set_get_target_component(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field param_id from param_set message
 *
 * @return Onboard parameter id
 */
static inline uint16_t mavlink_msg_param_set_get_param_id(const mavlink_message_t* msg, int8_t *param_id)
{
	return MAVLINK_MSG_RETURN_int8_t_array(msg, param_id, 15,  2);
}

/**
 * @brief Get field param_value from param_set message
 *
 * @return Onboard parameter value
 */
static inline float mavlink_msg_param_set_get_param_value(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  17);
}

/**
 * @brief Decode a param_set message into a struct
 *
 * @param msg The message to decode
 * @param param_set C-struct to decode the message contents into
 */
static inline void mavlink_msg_param_set_decode(const mavlink_message_t* msg, mavlink_param_set_t* param_set)
{
#if MAVLINK_NEED_BYTE_SWAP
	param_set->target_system = mavlink_msg_param_set_get_target_system(msg);
	param_set->target_component = mavlink_msg_param_set_get_target_component(msg);
	mavlink_msg_param_set_get_param_id(msg, param_set->param_id);
	param_set->param_value = mavlink_msg_param_set_get_param_value(msg);
#else
	memcpy(param_set, MAVLINK_PAYLOAD(msg), 21);
#endif
}

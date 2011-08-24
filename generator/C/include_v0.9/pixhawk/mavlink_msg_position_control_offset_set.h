// MESSAGE POSITION_CONTROL_OFFSET_SET PACKING

#define MAVLINK_MSG_ID_POSITION_CONTROL_OFFSET_SET 160

typedef struct __mavlink_position_control_offset_set_t
{
 uint8_t target_system; ///< System ID
 uint8_t target_component; ///< Component ID
 float x; ///< x position offset
 float y; ///< y position offset
 float z; ///< z position offset
 float yaw; ///< yaw orientation offset in radians, 0 = NORTH
} mavlink_position_control_offset_set_t;

/**
 * @brief Pack a position_control_offset_set message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param x x position offset
 * @param y y position offset
 * @param z z position offset
 * @param yaw yaw orientation offset in radians, 0 = NORTH
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_control_offset_set_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, float x, float y, float z, float yaw)
{
	msg->msgid = MAVLINK_MSG_ID_POSITION_CONTROL_OFFSET_SET;

	put_uint8_t_by_index(target_system, 0,  msg->payload); // System ID
	put_uint8_t_by_index(target_component, 1,  msg->payload); // Component ID
	put_float_by_index(x, 2,  msg->payload); // x position offset
	put_float_by_index(y, 6,  msg->payload); // y position offset
	put_float_by_index(z, 10,  msg->payload); // z position offset
	put_float_by_index(yaw, 14,  msg->payload); // yaw orientation offset in radians, 0 = NORTH

	return mavlink_finalize_message(msg, system_id, component_id, 18, 142);
}

/**
 * @brief Pack a position_control_offset_set message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param x x position offset
 * @param y y position offset
 * @param z z position offset
 * @param yaw yaw orientation offset in radians, 0 = NORTH
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_control_offset_set_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,float x,float y,float z,float yaw)
{
	msg->msgid = MAVLINK_MSG_ID_POSITION_CONTROL_OFFSET_SET;

	put_uint8_t_by_index(target_system, 0,  msg->payload); // System ID
	put_uint8_t_by_index(target_component, 1,  msg->payload); // Component ID
	put_float_by_index(x, 2,  msg->payload); // x position offset
	put_float_by_index(y, 6,  msg->payload); // y position offset
	put_float_by_index(z, 10,  msg->payload); // z position offset
	put_float_by_index(yaw, 14,  msg->payload); // yaw orientation offset in radians, 0 = NORTH

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 18, 142);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

/**
 * @brief Pack a position_control_offset_set message on a channel and send
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param x x position offset
 * @param y y position offset
 * @param z z position offset
 * @param yaw yaw orientation offset in radians, 0 = NORTH
 */
static inline void mavlink_msg_position_control_offset_set_pack_chan_send(mavlink_channel_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,float x,float y,float z,float yaw)
{
	msg->msgid = MAVLINK_MSG_ID_POSITION_CONTROL_OFFSET_SET;

	put_uint8_t_by_index(target_system, 0,  msg->payload); // System ID
	put_uint8_t_by_index(target_component, 1,  msg->payload); // Component ID
	put_float_by_index(x, 2,  msg->payload); // x position offset
	put_float_by_index(y, 6,  msg->payload); // y position offset
	put_float_by_index(z, 10,  msg->payload); // z position offset
	put_float_by_index(yaw, 14,  msg->payload); // yaw orientation offset in radians, 0 = NORTH

	mavlink_finalize_message_chan_send(msg, chan, 18, 142);
}
#endif // MAVLINK_USE_CONVENIENCE_FUNCTIONS


/**
 * @brief Encode a position_control_offset_set struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param position_control_offset_set C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_position_control_offset_set_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_position_control_offset_set_t* position_control_offset_set)
{
	return mavlink_msg_position_control_offset_set_pack(system_id, component_id, msg, position_control_offset_set->target_system, position_control_offset_set->target_component, position_control_offset_set->x, position_control_offset_set->y, position_control_offset_set->z, position_control_offset_set->yaw);
}

/**
 * @brief Send a position_control_offset_set message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param x x position offset
 * @param y y position offset
 * @param z z position offset
 * @param yaw yaw orientation offset in radians, 0 = NORTH
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_position_control_offset_set_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, float x, float y, float z, float yaw)
{
	MAVLINK_ALIGNED_MESSAGE(msg, 18);
	mavlink_msg_position_control_offset_set_pack_chan_send(chan, msg, target_system, target_component, x, y, z, yaw);
}

#endif

// MESSAGE POSITION_CONTROL_OFFSET_SET UNPACKING


/**
 * @brief Get field target_system from position_control_offset_set message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_position_control_offset_set_get_target_system(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from position_control_offset_set message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_position_control_offset_set_get_target_component(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field x from position_control_offset_set message
 *
 * @return x position offset
 */
static inline float mavlink_msg_position_control_offset_set_get_x(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  2);
}

/**
 * @brief Get field y from position_control_offset_set message
 *
 * @return y position offset
 */
static inline float mavlink_msg_position_control_offset_set_get_y(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  6);
}

/**
 * @brief Get field z from position_control_offset_set message
 *
 * @return z position offset
 */
static inline float mavlink_msg_position_control_offset_set_get_z(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  10);
}

/**
 * @brief Get field yaw from position_control_offset_set message
 *
 * @return yaw orientation offset in radians, 0 = NORTH
 */
static inline float mavlink_msg_position_control_offset_set_get_yaw(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  14);
}

/**
 * @brief Decode a position_control_offset_set message into a struct
 *
 * @param msg The message to decode
 * @param position_control_offset_set C-struct to decode the message contents into
 */
static inline void mavlink_msg_position_control_offset_set_decode(const mavlink_message_t* msg, mavlink_position_control_offset_set_t* position_control_offset_set)
{
#if MAVLINK_NEED_BYTE_SWAP
	position_control_offset_set->target_system = mavlink_msg_position_control_offset_set_get_target_system(msg);
	position_control_offset_set->target_component = mavlink_msg_position_control_offset_set_get_target_component(msg);
	position_control_offset_set->x = mavlink_msg_position_control_offset_set_get_x(msg);
	position_control_offset_set->y = mavlink_msg_position_control_offset_set_get_y(msg);
	position_control_offset_set->z = mavlink_msg_position_control_offset_set_get_z(msg);
	position_control_offset_set->yaw = mavlink_msg_position_control_offset_set_get_yaw(msg);
#else
	memcpy(position_control_offset_set, msg->payload, 18);
#endif
}

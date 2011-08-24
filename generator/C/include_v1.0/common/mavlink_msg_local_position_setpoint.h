// MESSAGE LOCAL_POSITION_SETPOINT PACKING

#define MAVLINK_MSG_ID_LOCAL_POSITION_SETPOINT 51

typedef struct __mavlink_local_position_setpoint_t
{
 float x; ///< x position
 float y; ///< y position
 float z; ///< z position
 float yaw; ///< Desired yaw angle
} mavlink_local_position_setpoint_t;

/**
 * @brief Pack a local_position_setpoint message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param x x position
 * @param y y position
 * @param z z position
 * @param yaw Desired yaw angle
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_local_position_setpoint_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float x, float y, float z, float yaw)
{
	msg->msgid = MAVLINK_MSG_ID_LOCAL_POSITION_SETPOINT;

	put_float_by_index(x, 0,  msg->payload); // x position
	put_float_by_index(y, 4,  msg->payload); // y position
	put_float_by_index(z, 8,  msg->payload); // z position
	put_float_by_index(yaw, 12,  msg->payload); // Desired yaw angle

	return mavlink_finalize_message(msg, system_id, component_id, 16, 40);
}

/**
 * @brief Pack a local_position_setpoint message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param x x position
 * @param y y position
 * @param z z position
 * @param yaw Desired yaw angle
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_local_position_setpoint_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float x,float y,float z,float yaw)
{
	msg->msgid = MAVLINK_MSG_ID_LOCAL_POSITION_SETPOINT;

	put_float_by_index(x, 0,  msg->payload); // x position
	put_float_by_index(y, 4,  msg->payload); // y position
	put_float_by_index(z, 8,  msg->payload); // z position
	put_float_by_index(yaw, 12,  msg->payload); // Desired yaw angle

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 16, 40);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

/**
 * @brief Pack a local_position_setpoint message on a channel and send
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param x x position
 * @param y y position
 * @param z z position
 * @param yaw Desired yaw angle
 */
static inline void mavlink_msg_local_position_setpoint_pack_chan_send(mavlink_channel_t chan,
							   mavlink_message_t* msg,
						           float x,float y,float z,float yaw)
{
	msg->msgid = MAVLINK_MSG_ID_LOCAL_POSITION_SETPOINT;

	put_float_by_index(x, 0,  msg->payload); // x position
	put_float_by_index(y, 4,  msg->payload); // y position
	put_float_by_index(z, 8,  msg->payload); // z position
	put_float_by_index(yaw, 12,  msg->payload); // Desired yaw angle

	mavlink_finalize_message_chan_send(msg, chan, 16, 40);
}
#endif // MAVLINK_USE_CONVENIENCE_FUNCTIONS


/**
 * @brief Encode a local_position_setpoint struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param local_position_setpoint C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_local_position_setpoint_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_local_position_setpoint_t* local_position_setpoint)
{
	return mavlink_msg_local_position_setpoint_pack(system_id, component_id, msg, local_position_setpoint->x, local_position_setpoint->y, local_position_setpoint->z, local_position_setpoint->yaw);
}

/**
 * @brief Send a local_position_setpoint message
 * @param chan MAVLink channel to send the message
 *
 * @param x x position
 * @param y y position
 * @param z z position
 * @param yaw Desired yaw angle
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_local_position_setpoint_send(mavlink_channel_t chan, float x, float y, float z, float yaw)
{
	MAVLINK_ALIGNED_MESSAGE(msg, 16);
	mavlink_msg_local_position_setpoint_pack_chan_send(chan, msg, x, y, z, yaw);
}

#endif

// MESSAGE LOCAL_POSITION_SETPOINT UNPACKING


/**
 * @brief Get field x from local_position_setpoint message
 *
 * @return x position
 */
static inline float mavlink_msg_local_position_setpoint_get_x(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  0);
}

/**
 * @brief Get field y from local_position_setpoint message
 *
 * @return y position
 */
static inline float mavlink_msg_local_position_setpoint_get_y(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  4);
}

/**
 * @brief Get field z from local_position_setpoint message
 *
 * @return z position
 */
static inline float mavlink_msg_local_position_setpoint_get_z(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  8);
}

/**
 * @brief Get field yaw from local_position_setpoint message
 *
 * @return Desired yaw angle
 */
static inline float mavlink_msg_local_position_setpoint_get_yaw(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  12);
}

/**
 * @brief Decode a local_position_setpoint message into a struct
 *
 * @param msg The message to decode
 * @param local_position_setpoint C-struct to decode the message contents into
 */
static inline void mavlink_msg_local_position_setpoint_decode(const mavlink_message_t* msg, mavlink_local_position_setpoint_t* local_position_setpoint)
{
#if MAVLINK_NEED_BYTE_SWAP
	local_position_setpoint->x = mavlink_msg_local_position_setpoint_get_x(msg);
	local_position_setpoint->y = mavlink_msg_local_position_setpoint_get_y(msg);
	local_position_setpoint->z = mavlink_msg_local_position_setpoint_get_z(msg);
	local_position_setpoint->yaw = mavlink_msg_local_position_setpoint_get_yaw(msg);
#else
	memcpy(local_position_setpoint, msg->payload, 16);
#endif
}
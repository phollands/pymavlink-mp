// MESSAGE MID_LVL_CMDS PACKING

#define MAVLINK_MSG_ID_MID_LVL_CMDS 180

typedef struct __mavlink_mid_lvl_cmds_t
{
 float hCommand; ///< Commanded Airspeed
 float uCommand; ///< Log value 2 
 float rCommand; ///< Log value 3 
 uint8_t target; ///< The system setting the commands
} mavlink_mid_lvl_cmds_t;

/**
 * @brief Pack a mid_lvl_cmds message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target The system setting the commands
 * @param hCommand Commanded Airspeed
 * @param uCommand Log value 2 
 * @param rCommand Log value 3 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mid_lvl_cmds_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target, float hCommand, float uCommand, float rCommand)
{
	msg->msgid = MAVLINK_MSG_ID_MID_LVL_CMDS;

	put_float_by_index(hCommand, 0,  msg->payload); // Commanded Airspeed
	put_float_by_index(uCommand, 4,  msg->payload); // Log value 2 
	put_float_by_index(rCommand, 8,  msg->payload); // Log value 3 
	put_uint8_t_by_index(target, 12,  msg->payload); // The system setting the commands

	return mavlink_finalize_message(msg, system_id, component_id, 13, 212);
}

/**
 * @brief Pack a mid_lvl_cmds message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target The system setting the commands
 * @param hCommand Commanded Airspeed
 * @param uCommand Log value 2 
 * @param rCommand Log value 3 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mid_lvl_cmds_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target,float hCommand,float uCommand,float rCommand)
{
	msg->msgid = MAVLINK_MSG_ID_MID_LVL_CMDS;

	put_float_by_index(hCommand, 0,  msg->payload); // Commanded Airspeed
	put_float_by_index(uCommand, 4,  msg->payload); // Log value 2 
	put_float_by_index(rCommand, 8,  msg->payload); // Log value 3 
	put_uint8_t_by_index(target, 12,  msg->payload); // The system setting the commands

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 13, 212);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

/**
 * @brief Pack a mid_lvl_cmds message on a channel and send
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target The system setting the commands
 * @param hCommand Commanded Airspeed
 * @param uCommand Log value 2 
 * @param rCommand Log value 3 
 */
static inline void mavlink_msg_mid_lvl_cmds_pack_chan_send(mavlink_channel_t chan,
							   mavlink_message_t* msg,
						           uint8_t target,float hCommand,float uCommand,float rCommand)
{
	msg->msgid = MAVLINK_MSG_ID_MID_LVL_CMDS;

	put_float_by_index(hCommand, 0,  msg->payload); // Commanded Airspeed
	put_float_by_index(uCommand, 4,  msg->payload); // Log value 2 
	put_float_by_index(rCommand, 8,  msg->payload); // Log value 3 
	put_uint8_t_by_index(target, 12,  msg->payload); // The system setting the commands

	mavlink_finalize_message_chan_send(msg, chan, 13, 212);
}
#endif // MAVLINK_USE_CONVENIENCE_FUNCTIONS


/**
 * @brief Encode a mid_lvl_cmds struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mid_lvl_cmds C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mid_lvl_cmds_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mid_lvl_cmds_t* mid_lvl_cmds)
{
	return mavlink_msg_mid_lvl_cmds_pack(system_id, component_id, msg, mid_lvl_cmds->target, mid_lvl_cmds->hCommand, mid_lvl_cmds->uCommand, mid_lvl_cmds->rCommand);
}

/**
 * @brief Send a mid_lvl_cmds message
 * @param chan MAVLink channel to send the message
 *
 * @param target The system setting the commands
 * @param hCommand Commanded Airspeed
 * @param uCommand Log value 2 
 * @param rCommand Log value 3 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mid_lvl_cmds_send(mavlink_channel_t chan, uint8_t target, float hCommand, float uCommand, float rCommand)
{
	MAVLINK_ALIGNED_MESSAGE(msg, 13);
	mavlink_msg_mid_lvl_cmds_pack_chan_send(chan, msg, target, hCommand, uCommand, rCommand);
}

#endif

// MESSAGE MID_LVL_CMDS UNPACKING


/**
 * @brief Get field target from mid_lvl_cmds message
 *
 * @return The system setting the commands
 */
static inline uint8_t mavlink_msg_mid_lvl_cmds_get_target(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field hCommand from mid_lvl_cmds message
 *
 * @return Commanded Airspeed
 */
static inline float mavlink_msg_mid_lvl_cmds_get_hCommand(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  0);
}

/**
 * @brief Get field uCommand from mid_lvl_cmds message
 *
 * @return Log value 2 
 */
static inline float mavlink_msg_mid_lvl_cmds_get_uCommand(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  4);
}

/**
 * @brief Get field rCommand from mid_lvl_cmds message
 *
 * @return Log value 3 
 */
static inline float mavlink_msg_mid_lvl_cmds_get_rCommand(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  8);
}

/**
 * @brief Decode a mid_lvl_cmds message into a struct
 *
 * @param msg The message to decode
 * @param mid_lvl_cmds C-struct to decode the message contents into
 */
static inline void mavlink_msg_mid_lvl_cmds_decode(const mavlink_message_t* msg, mavlink_mid_lvl_cmds_t* mid_lvl_cmds)
{
#if MAVLINK_NEED_BYTE_SWAP
	mid_lvl_cmds->hCommand = mavlink_msg_mid_lvl_cmds_get_hCommand(msg);
	mid_lvl_cmds->uCommand = mavlink_msg_mid_lvl_cmds_get_uCommand(msg);
	mid_lvl_cmds->rCommand = mavlink_msg_mid_lvl_cmds_get_rCommand(msg);
	mid_lvl_cmds->target = mavlink_msg_mid_lvl_cmds_get_target(msg);
#else
	memcpy(mid_lvl_cmds, msg->payload, 13);
#endif
}
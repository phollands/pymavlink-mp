// MESSAGE PING PACKING

#define MAVLINK_MSG_ID_PING 3

typedef struct __mavlink_ping_t
{
 uint32_t seq; ///< PING sequence
 uint8_t target_system; ///< 0: request ping from all receiving systems, if greater than 0: message is a ping response and number is the system id of the requesting system
 uint8_t target_component; ///< 0: request ping from all receiving components, if greater than 0: message is a ping response and number is the system id of the requesting system
 uint64_t time; ///< Unix timestamp in microseconds
} mavlink_ping_t;

/**
 * @brief Pack a ping message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param seq PING sequence
 * @param target_system 0: request ping from all receiving systems, if greater than 0: message is a ping response and number is the system id of the requesting system
 * @param target_component 0: request ping from all receiving components, if greater than 0: message is a ping response and number is the system id of the requesting system
 * @param time Unix timestamp in microseconds
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ping_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t seq, uint8_t target_system, uint8_t target_component, uint64_t time)
{
	msg->msgid = MAVLINK_MSG_ID_PING;

	put_uint32_t_by_index(seq, 0,  msg->payload); // PING sequence
	put_uint8_t_by_index(target_system, 4,  msg->payload); // 0: request ping from all receiving systems, if greater than 0: message is a ping response and number is the system id of the requesting system
	put_uint8_t_by_index(target_component, 5,  msg->payload); // 0: request ping from all receiving components, if greater than 0: message is a ping response and number is the system id of the requesting system
	put_uint64_t_by_index(time, 6,  msg->payload); // Unix timestamp in microseconds

	return mavlink_finalize_message(msg, system_id, component_id, 14, 242);
}

/**
 * @brief Pack a ping message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param seq PING sequence
 * @param target_system 0: request ping from all receiving systems, if greater than 0: message is a ping response and number is the system id of the requesting system
 * @param target_component 0: request ping from all receiving components, if greater than 0: message is a ping response and number is the system id of the requesting system
 * @param time Unix timestamp in microseconds
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ping_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t seq,uint8_t target_system,uint8_t target_component,uint64_t time)
{
	msg->msgid = MAVLINK_MSG_ID_PING;

	put_uint32_t_by_index(seq, 0,  msg->payload); // PING sequence
	put_uint8_t_by_index(target_system, 4,  msg->payload); // 0: request ping from all receiving systems, if greater than 0: message is a ping response and number is the system id of the requesting system
	put_uint8_t_by_index(target_component, 5,  msg->payload); // 0: request ping from all receiving components, if greater than 0: message is a ping response and number is the system id of the requesting system
	put_uint64_t_by_index(time, 6,  msg->payload); // Unix timestamp in microseconds

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 14, 242);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

/**
 * @brief Pack a ping message on a channel and send
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param seq PING sequence
 * @param target_system 0: request ping from all receiving systems, if greater than 0: message is a ping response and number is the system id of the requesting system
 * @param target_component 0: request ping from all receiving components, if greater than 0: message is a ping response and number is the system id of the requesting system
 * @param time Unix timestamp in microseconds
 */
static inline void mavlink_msg_ping_pack_chan_send(mavlink_channel_t chan,
							   mavlink_message_t* msg,
						           uint32_t seq,uint8_t target_system,uint8_t target_component,uint64_t time)
{
	msg->msgid = MAVLINK_MSG_ID_PING;

	put_uint32_t_by_index(seq, 0,  msg->payload); // PING sequence
	put_uint8_t_by_index(target_system, 4,  msg->payload); // 0: request ping from all receiving systems, if greater than 0: message is a ping response and number is the system id of the requesting system
	put_uint8_t_by_index(target_component, 5,  msg->payload); // 0: request ping from all receiving components, if greater than 0: message is a ping response and number is the system id of the requesting system
	put_uint64_t_by_index(time, 6,  msg->payload); // Unix timestamp in microseconds

	mavlink_finalize_message_chan_send(msg, chan, 14, 242);
}
#endif // MAVLINK_USE_CONVENIENCE_FUNCTIONS


/**
 * @brief Encode a ping struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ping C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ping_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ping_t* ping)
{
	return mavlink_msg_ping_pack(system_id, component_id, msg, ping->seq, ping->target_system, ping->target_component, ping->time);
}

/**
 * @brief Send a ping message
 * @param chan MAVLink channel to send the message
 *
 * @param seq PING sequence
 * @param target_system 0: request ping from all receiving systems, if greater than 0: message is a ping response and number is the system id of the requesting system
 * @param target_component 0: request ping from all receiving components, if greater than 0: message is a ping response and number is the system id of the requesting system
 * @param time Unix timestamp in microseconds
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ping_send(mavlink_channel_t chan, uint32_t seq, uint8_t target_system, uint8_t target_component, uint64_t time)
{
	MAVLINK_ALIGNED_MESSAGE(msg, 14);
	mavlink_msg_ping_pack_chan_send(chan, msg, seq, target_system, target_component, time);
}

#endif

// MESSAGE PING UNPACKING


/**
 * @brief Get field seq from ping message
 *
 * @return PING sequence
 */
static inline uint32_t mavlink_msg_ping_get_seq(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field target_system from ping message
 *
 * @return 0: request ping from all receiving systems, if greater than 0: message is a ping response and number is the system id of the requesting system
 */
static inline uint8_t mavlink_msg_ping_get_target_system(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field target_component from ping message
 *
 * @return 0: request ping from all receiving components, if greater than 0: message is a ping response and number is the system id of the requesting system
 */
static inline uint8_t mavlink_msg_ping_get_target_component(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field time from ping message
 *
 * @return Unix timestamp in microseconds
 */
static inline uint64_t mavlink_msg_ping_get_time(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint64_t(msg,  6);
}

/**
 * @brief Decode a ping message into a struct
 *
 * @param msg The message to decode
 * @param ping C-struct to decode the message contents into
 */
static inline void mavlink_msg_ping_decode(const mavlink_message_t* msg, mavlink_ping_t* ping)
{
#if MAVLINK_NEED_BYTE_SWAP
	ping->seq = mavlink_msg_ping_get_seq(msg);
	ping->target_system = mavlink_msg_ping_get_target_system(msg);
	ping->target_component = mavlink_msg_ping_get_target_component(msg);
	ping->time = mavlink_msg_ping_get_time(msg);
#else
	memcpy(ping, msg->payload, 14);
#endif
}
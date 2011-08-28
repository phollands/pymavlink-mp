// MESSAGE ACTION_ACK PACKING

#define MAVLINK_MSG_ID_ACTION_ACK 9

typedef struct __mavlink_action_ack_t
{
 uint8_t action; ///< The action id
 uint8_t result; ///< 0: Action DENIED, 1: Action executed
} mavlink_action_ack_t;

#define MAVLINK_MSG_ID_ACTION_ACK_LEN 2
#define MAVLINK_MSG_ID_9_LEN 2



#define MAVLINK_MESSAGE_INFO_ACTION_ACK { \
	"ACTION_ACK", \
	2, \
	{  { "action", MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_action_ack_t, action) }, \
         { "result", MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_action_ack_t, result) }, \
         } \
}


/**
 * @brief Pack a action_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param action The action id
 * @param result 0: Action DENIED, 1: Action executed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_action_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t action, uint8_t result)
{
	msg->msgid = MAVLINK_MSG_ID_ACTION_ACK;

	put_uint8_t_by_index(msg, 0, action); // The action id
	put_uint8_t_by_index(msg, 1, result); // 0: Action DENIED, 1: Action executed

	return mavlink_finalize_message(msg, system_id, component_id, 2);
}

/**
 * @brief Pack a action_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param action The action id
 * @param result 0: Action DENIED, 1: Action executed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_action_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t action,uint8_t result)
{
	msg->msgid = MAVLINK_MSG_ID_ACTION_ACK;

	put_uint8_t_by_index(msg, 0, action); // The action id
	put_uint8_t_by_index(msg, 1, result); // 0: Action DENIED, 1: Action executed

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 2);
}

/**
 * @brief Encode a action_ack struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param action_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_action_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_action_ack_t* action_ack)
{
	return mavlink_msg_action_ack_pack(system_id, component_id, msg, action_ack->action, action_ack->result);
}

/**
 * @brief Send a action_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param action The action id
 * @param result 0: Action DENIED, 1: Action executed
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_action_ack_send(mavlink_channel_t chan, uint8_t action, uint8_t result)
{
	MAVLINK_ALIGNED_MESSAGE(msg, 2);
	msg->msgid = MAVLINK_MSG_ID_ACTION_ACK;

	put_uint8_t_by_index(msg, 0, action); // The action id
	put_uint8_t_by_index(msg, 1, result); // 0: Action DENIED, 1: Action executed

	mavlink_finalize_message_chan_send(msg, chan, 2);
}

#endif

// MESSAGE ACTION_ACK UNPACKING


/**
 * @brief Get field action from action_ack message
 *
 * @return The action id
 */
static inline uint8_t mavlink_msg_action_ack_get_action(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field result from action_ack message
 *
 * @return 0: Action DENIED, 1: Action executed
 */
static inline uint8_t mavlink_msg_action_ack_get_result(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a action_ack message into a struct
 *
 * @param msg The message to decode
 * @param action_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_action_ack_decode(const mavlink_message_t* msg, mavlink_action_ack_t* action_ack)
{
#if MAVLINK_NEED_BYTE_SWAP
	action_ack->action = mavlink_msg_action_ack_get_action(msg);
	action_ack->result = mavlink_msg_action_ack_get_result(msg);
#else
	memcpy(action_ack, MAVLINK_PAYLOAD(msg), 2);
#endif
}

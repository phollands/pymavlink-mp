// MESSAGE COMMAND PACKING

#define MAVLINK_MSG_ID_COMMAND 75

typedef struct __mavlink_command_t
{
 float param1; ///< Parameter 1, as defined by MAV_CMD enum.
 float param2; ///< Parameter 2, as defined by MAV_CMD enum.
 float param3; ///< Parameter 3, as defined by MAV_CMD enum.
 float param4; ///< Parameter 4, as defined by MAV_CMD enum.
 uint8_t target_system; ///< System which should execute the command
 uint8_t target_component; ///< Component which should execute the command, 0 for all components
 uint8_t command; ///< Command ID, as defined by MAV_CMD enum.
 uint8_t confirmation; ///< 0: First transmission of this command. 1-255: Confirmation transmissions (e.g. for kill command)
} mavlink_command_t;

/**
 * @brief Pack a command message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System which should execute the command
 * @param target_component Component which should execute the command, 0 for all components
 * @param command Command ID, as defined by MAV_CMD enum.
 * @param confirmation 0: First transmission of this command. 1-255: Confirmation transmissions (e.g. for kill command)
 * @param param1 Parameter 1, as defined by MAV_CMD enum.
 * @param param2 Parameter 2, as defined by MAV_CMD enum.
 * @param param3 Parameter 3, as defined by MAV_CMD enum.
 * @param param4 Parameter 4, as defined by MAV_CMD enum.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, uint8_t command, uint8_t confirmation, float param1, float param2, float param3, float param4)
{
	msg->msgid = MAVLINK_MSG_ID_COMMAND;

	put_float_by_index(param1, 0,  msg->payload); // Parameter 1, as defined by MAV_CMD enum.
	put_float_by_index(param2, 4,  msg->payload); // Parameter 2, as defined by MAV_CMD enum.
	put_float_by_index(param3, 8,  msg->payload); // Parameter 3, as defined by MAV_CMD enum.
	put_float_by_index(param4, 12,  msg->payload); // Parameter 4, as defined by MAV_CMD enum.
	put_uint8_t_by_index(target_system, 16,  msg->payload); // System which should execute the command
	put_uint8_t_by_index(target_component, 17,  msg->payload); // Component which should execute the command, 0 for all components
	put_uint8_t_by_index(command, 18,  msg->payload); // Command ID, as defined by MAV_CMD enum.
	put_uint8_t_by_index(confirmation, 19,  msg->payload); // 0: First transmission of this command. 1-255: Confirmation transmissions (e.g. for kill command)

	return mavlink_finalize_message(msg, system_id, component_id, 20, 144);
}

/**
 * @brief Pack a command message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System which should execute the command
 * @param target_component Component which should execute the command, 0 for all components
 * @param command Command ID, as defined by MAV_CMD enum.
 * @param confirmation 0: First transmission of this command. 1-255: Confirmation transmissions (e.g. for kill command)
 * @param param1 Parameter 1, as defined by MAV_CMD enum.
 * @param param2 Parameter 2, as defined by MAV_CMD enum.
 * @param param3 Parameter 3, as defined by MAV_CMD enum.
 * @param param4 Parameter 4, as defined by MAV_CMD enum.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,uint8_t command,uint8_t confirmation,float param1,float param2,float param3,float param4)
{
	msg->msgid = MAVLINK_MSG_ID_COMMAND;

	put_float_by_index(param1, 0,  msg->payload); // Parameter 1, as defined by MAV_CMD enum.
	put_float_by_index(param2, 4,  msg->payload); // Parameter 2, as defined by MAV_CMD enum.
	put_float_by_index(param3, 8,  msg->payload); // Parameter 3, as defined by MAV_CMD enum.
	put_float_by_index(param4, 12,  msg->payload); // Parameter 4, as defined by MAV_CMD enum.
	put_uint8_t_by_index(target_system, 16,  msg->payload); // System which should execute the command
	put_uint8_t_by_index(target_component, 17,  msg->payload); // Component which should execute the command, 0 for all components
	put_uint8_t_by_index(command, 18,  msg->payload); // Command ID, as defined by MAV_CMD enum.
	put_uint8_t_by_index(confirmation, 19,  msg->payload); // 0: First transmission of this command. 1-255: Confirmation transmissions (e.g. for kill command)

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 20, 144);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

/**
 * @brief Pack a command message on a channel and send
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System which should execute the command
 * @param target_component Component which should execute the command, 0 for all components
 * @param command Command ID, as defined by MAV_CMD enum.
 * @param confirmation 0: First transmission of this command. 1-255: Confirmation transmissions (e.g. for kill command)
 * @param param1 Parameter 1, as defined by MAV_CMD enum.
 * @param param2 Parameter 2, as defined by MAV_CMD enum.
 * @param param3 Parameter 3, as defined by MAV_CMD enum.
 * @param param4 Parameter 4, as defined by MAV_CMD enum.
 */
static inline void mavlink_msg_command_pack_chan_send(mavlink_channel_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,uint8_t command,uint8_t confirmation,float param1,float param2,float param3,float param4)
{
	msg->msgid = MAVLINK_MSG_ID_COMMAND;

	put_float_by_index(param1, 0,  msg->payload); // Parameter 1, as defined by MAV_CMD enum.
	put_float_by_index(param2, 4,  msg->payload); // Parameter 2, as defined by MAV_CMD enum.
	put_float_by_index(param3, 8,  msg->payload); // Parameter 3, as defined by MAV_CMD enum.
	put_float_by_index(param4, 12,  msg->payload); // Parameter 4, as defined by MAV_CMD enum.
	put_uint8_t_by_index(target_system, 16,  msg->payload); // System which should execute the command
	put_uint8_t_by_index(target_component, 17,  msg->payload); // Component which should execute the command, 0 for all components
	put_uint8_t_by_index(command, 18,  msg->payload); // Command ID, as defined by MAV_CMD enum.
	put_uint8_t_by_index(confirmation, 19,  msg->payload); // 0: First transmission of this command. 1-255: Confirmation transmissions (e.g. for kill command)

	mavlink_finalize_message_chan_send(msg, chan, 20, 144);
}
#endif // MAVLINK_USE_CONVENIENCE_FUNCTIONS


/**
 * @brief Encode a command struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_command_t* command)
{
	return mavlink_msg_command_pack(system_id, component_id, msg, command->target_system, command->target_component, command->command, command->confirmation, command->param1, command->param2, command->param3, command->param4);
}

/**
 * @brief Send a command message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System which should execute the command
 * @param target_component Component which should execute the command, 0 for all components
 * @param command Command ID, as defined by MAV_CMD enum.
 * @param confirmation 0: First transmission of this command. 1-255: Confirmation transmissions (e.g. for kill command)
 * @param param1 Parameter 1, as defined by MAV_CMD enum.
 * @param param2 Parameter 2, as defined by MAV_CMD enum.
 * @param param3 Parameter 3, as defined by MAV_CMD enum.
 * @param param4 Parameter 4, as defined by MAV_CMD enum.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_command_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t command, uint8_t confirmation, float param1, float param2, float param3, float param4)
{
	MAVLINK_ALIGNED_MESSAGE(msg, 20);
	mavlink_msg_command_pack_chan_send(chan, msg, target_system, target_component, command, confirmation, param1, param2, param3, param4);
}

#endif

// MESSAGE COMMAND UNPACKING


/**
 * @brief Get field target_system from command message
 *
 * @return System which should execute the command
 */
static inline uint8_t mavlink_msg_command_get_target_system(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field target_component from command message
 *
 * @return Component which should execute the command, 0 for all components
 */
static inline uint8_t mavlink_msg_command_get_target_component(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field command from command message
 *
 * @return Command ID, as defined by MAV_CMD enum.
 */
static inline uint8_t mavlink_msg_command_get_command(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field confirmation from command message
 *
 * @return 0: First transmission of this command. 1-255: Confirmation transmissions (e.g. for kill command)
 */
static inline uint8_t mavlink_msg_command_get_confirmation(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  19);
}

/**
 * @brief Get field param1 from command message
 *
 * @return Parameter 1, as defined by MAV_CMD enum.
 */
static inline float mavlink_msg_command_get_param1(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  0);
}

/**
 * @brief Get field param2 from command message
 *
 * @return Parameter 2, as defined by MAV_CMD enum.
 */
static inline float mavlink_msg_command_get_param2(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  4);
}

/**
 * @brief Get field param3 from command message
 *
 * @return Parameter 3, as defined by MAV_CMD enum.
 */
static inline float mavlink_msg_command_get_param3(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  8);
}

/**
 * @brief Get field param4 from command message
 *
 * @return Parameter 4, as defined by MAV_CMD enum.
 */
static inline float mavlink_msg_command_get_param4(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  12);
}

/**
 * @brief Decode a command message into a struct
 *
 * @param msg The message to decode
 * @param command C-struct to decode the message contents into
 */
static inline void mavlink_msg_command_decode(const mavlink_message_t* msg, mavlink_command_t* command)
{
#if MAVLINK_NEED_BYTE_SWAP
	command->param1 = mavlink_msg_command_get_param1(msg);
	command->param2 = mavlink_msg_command_get_param2(msg);
	command->param3 = mavlink_msg_command_get_param3(msg);
	command->param4 = mavlink_msg_command_get_param4(msg);
	command->target_system = mavlink_msg_command_get_target_system(msg);
	command->target_component = mavlink_msg_command_get_target_component(msg);
	command->command = mavlink_msg_command_get_command(msg);
	command->confirmation = mavlink_msg_command_get_confirmation(msg);
#else
	memcpy(command, msg->payload, 20);
#endif
}
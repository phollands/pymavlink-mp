// MESSAGE SYS_STATUS PACKING

#define MAVLINK_MSG_ID_SYS_STATUS 34

typedef struct __mavlink_sys_status_t
{
 uint8_t mode; ///< System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
 uint8_t nav_mode; ///< Navigation mode, see MAV_NAV_MODE ENUM
 uint8_t status; ///< System status flag, see MAV_STATUS ENUM
 uint16_t load; ///< Maximum usage in percent of the mainloop time, (0%: 0, 100%: 1000) should be always below 1000
 uint16_t vbat; ///< Battery voltage, in millivolts (1 = 1 millivolt)
 uint16_t battery_remaining; ///< Remaining battery energy: (0%: 0, 100%: 1000)
 uint16_t packet_drop; ///< Dropped packets (packets that were corrupted on reception on the MAV)
} mavlink_sys_status_t;

/**
 * @brief Pack a sys_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mode System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
 * @param nav_mode Navigation mode, see MAV_NAV_MODE ENUM
 * @param status System status flag, see MAV_STATUS ENUM
 * @param load Maximum usage in percent of the mainloop time, (0%: 0, 100%: 1000) should be always below 1000
 * @param vbat Battery voltage, in millivolts (1 = 1 millivolt)
 * @param battery_remaining Remaining battery energy: (0%: 0, 100%: 1000)
 * @param packet_drop Dropped packets (packets that were corrupted on reception on the MAV)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sys_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t mode, uint8_t nav_mode, uint8_t status, uint16_t load, uint16_t vbat, uint16_t battery_remaining, uint16_t packet_drop)
{
	msg->msgid = MAVLINK_MSG_ID_SYS_STATUS;

	put_uint8_t_by_index(mode, 0,  msg->payload); // System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
	put_uint8_t_by_index(nav_mode, 1,  msg->payload); // Navigation mode, see MAV_NAV_MODE ENUM
	put_uint8_t_by_index(status, 2,  msg->payload); // System status flag, see MAV_STATUS ENUM
	put_uint16_t_by_index(load, 3,  msg->payload); // Maximum usage in percent of the mainloop time, (0%: 0, 100%: 1000) should be always below 1000
	put_uint16_t_by_index(vbat, 5,  msg->payload); // Battery voltage, in millivolts (1 = 1 millivolt)
	put_uint16_t_by_index(battery_remaining, 7,  msg->payload); // Remaining battery energy: (0%: 0, 100%: 1000)
	put_uint16_t_by_index(packet_drop, 9,  msg->payload); // Dropped packets (packets that were corrupted on reception on the MAV)

	return mavlink_finalize_message(msg, system_id, component_id, 11, 90);
}

/**
 * @brief Pack a sys_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param mode System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
 * @param nav_mode Navigation mode, see MAV_NAV_MODE ENUM
 * @param status System status flag, see MAV_STATUS ENUM
 * @param load Maximum usage in percent of the mainloop time, (0%: 0, 100%: 1000) should be always below 1000
 * @param vbat Battery voltage, in millivolts (1 = 1 millivolt)
 * @param battery_remaining Remaining battery energy: (0%: 0, 100%: 1000)
 * @param packet_drop Dropped packets (packets that were corrupted on reception on the MAV)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sys_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t mode,uint8_t nav_mode,uint8_t status,uint16_t load,uint16_t vbat,uint16_t battery_remaining,uint16_t packet_drop)
{
	msg->msgid = MAVLINK_MSG_ID_SYS_STATUS;

	put_uint8_t_by_index(mode, 0,  msg->payload); // System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
	put_uint8_t_by_index(nav_mode, 1,  msg->payload); // Navigation mode, see MAV_NAV_MODE ENUM
	put_uint8_t_by_index(status, 2,  msg->payload); // System status flag, see MAV_STATUS ENUM
	put_uint16_t_by_index(load, 3,  msg->payload); // Maximum usage in percent of the mainloop time, (0%: 0, 100%: 1000) should be always below 1000
	put_uint16_t_by_index(vbat, 5,  msg->payload); // Battery voltage, in millivolts (1 = 1 millivolt)
	put_uint16_t_by_index(battery_remaining, 7,  msg->payload); // Remaining battery energy: (0%: 0, 100%: 1000)
	put_uint16_t_by_index(packet_drop, 9,  msg->payload); // Dropped packets (packets that were corrupted on reception on the MAV)

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 11, 90);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

/**
 * @brief Pack a sys_status message on a channel and send
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param mode System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
 * @param nav_mode Navigation mode, see MAV_NAV_MODE ENUM
 * @param status System status flag, see MAV_STATUS ENUM
 * @param load Maximum usage in percent of the mainloop time, (0%: 0, 100%: 1000) should be always below 1000
 * @param vbat Battery voltage, in millivolts (1 = 1 millivolt)
 * @param battery_remaining Remaining battery energy: (0%: 0, 100%: 1000)
 * @param packet_drop Dropped packets (packets that were corrupted on reception on the MAV)
 */
static inline void mavlink_msg_sys_status_pack_chan_send(mavlink_channel_t chan,
							   mavlink_message_t* msg,
						           uint8_t mode,uint8_t nav_mode,uint8_t status,uint16_t load,uint16_t vbat,uint16_t battery_remaining,uint16_t packet_drop)
{
	msg->msgid = MAVLINK_MSG_ID_SYS_STATUS;

	put_uint8_t_by_index(mode, 0,  msg->payload); // System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
	put_uint8_t_by_index(nav_mode, 1,  msg->payload); // Navigation mode, see MAV_NAV_MODE ENUM
	put_uint8_t_by_index(status, 2,  msg->payload); // System status flag, see MAV_STATUS ENUM
	put_uint16_t_by_index(load, 3,  msg->payload); // Maximum usage in percent of the mainloop time, (0%: 0, 100%: 1000) should be always below 1000
	put_uint16_t_by_index(vbat, 5,  msg->payload); // Battery voltage, in millivolts (1 = 1 millivolt)
	put_uint16_t_by_index(battery_remaining, 7,  msg->payload); // Remaining battery energy: (0%: 0, 100%: 1000)
	put_uint16_t_by_index(packet_drop, 9,  msg->payload); // Dropped packets (packets that were corrupted on reception on the MAV)

	mavlink_finalize_message_chan_send(msg, chan, 11, 90);
}
#endif // MAVLINK_USE_CONVENIENCE_FUNCTIONS


/**
 * @brief Encode a sys_status struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sys_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sys_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sys_status_t* sys_status)
{
	return mavlink_msg_sys_status_pack(system_id, component_id, msg, sys_status->mode, sys_status->nav_mode, sys_status->status, sys_status->load, sys_status->vbat, sys_status->battery_remaining, sys_status->packet_drop);
}

/**
 * @brief Send a sys_status message
 * @param chan MAVLink channel to send the message
 *
 * @param mode System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
 * @param nav_mode Navigation mode, see MAV_NAV_MODE ENUM
 * @param status System status flag, see MAV_STATUS ENUM
 * @param load Maximum usage in percent of the mainloop time, (0%: 0, 100%: 1000) should be always below 1000
 * @param vbat Battery voltage, in millivolts (1 = 1 millivolt)
 * @param battery_remaining Remaining battery energy: (0%: 0, 100%: 1000)
 * @param packet_drop Dropped packets (packets that were corrupted on reception on the MAV)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sys_status_send(mavlink_channel_t chan, uint8_t mode, uint8_t nav_mode, uint8_t status, uint16_t load, uint16_t vbat, uint16_t battery_remaining, uint16_t packet_drop)
{
	MAVLINK_ALIGNED_MESSAGE(msg, 11);
	mavlink_msg_sys_status_pack_chan_send(chan, msg, mode, nav_mode, status, load, vbat, battery_remaining, packet_drop);
}

#endif

// MESSAGE SYS_STATUS UNPACKING


/**
 * @brief Get field mode from sys_status message
 *
 * @return System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
 */
static inline uint8_t mavlink_msg_sys_status_get_mode(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field nav_mode from sys_status message
 *
 * @return Navigation mode, see MAV_NAV_MODE ENUM
 */
static inline uint8_t mavlink_msg_sys_status_get_nav_mode(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field status from sys_status message
 *
 * @return System status flag, see MAV_STATUS ENUM
 */
static inline uint8_t mavlink_msg_sys_status_get_status(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field load from sys_status message
 *
 * @return Maximum usage in percent of the mainloop time, (0%: 0, 100%: 1000) should be always below 1000
 */
static inline uint16_t mavlink_msg_sys_status_get_load(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint16_t(msg,  3);
}

/**
 * @brief Get field vbat from sys_status message
 *
 * @return Battery voltage, in millivolts (1 = 1 millivolt)
 */
static inline uint16_t mavlink_msg_sys_status_get_vbat(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint16_t(msg,  5);
}

/**
 * @brief Get field battery_remaining from sys_status message
 *
 * @return Remaining battery energy: (0%: 0, 100%: 1000)
 */
static inline uint16_t mavlink_msg_sys_status_get_battery_remaining(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint16_t(msg,  7);
}

/**
 * @brief Get field packet_drop from sys_status message
 *
 * @return Dropped packets (packets that were corrupted on reception on the MAV)
 */
static inline uint16_t mavlink_msg_sys_status_get_packet_drop(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint16_t(msg,  9);
}

/**
 * @brief Decode a sys_status message into a struct
 *
 * @param msg The message to decode
 * @param sys_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_sys_status_decode(const mavlink_message_t* msg, mavlink_sys_status_t* sys_status)
{
#if MAVLINK_NEED_BYTE_SWAP
	sys_status->mode = mavlink_msg_sys_status_get_mode(msg);
	sys_status->nav_mode = mavlink_msg_sys_status_get_nav_mode(msg);
	sys_status->status = mavlink_msg_sys_status_get_status(msg);
	sys_status->load = mavlink_msg_sys_status_get_load(msg);
	sys_status->vbat = mavlink_msg_sys_status_get_vbat(msg);
	sys_status->battery_remaining = mavlink_msg_sys_status_get_battery_remaining(msg);
	sys_status->packet_drop = mavlink_msg_sys_status_get_packet_drop(msg);
#else
	memcpy(sys_status, msg->payload, 11);
#endif
}

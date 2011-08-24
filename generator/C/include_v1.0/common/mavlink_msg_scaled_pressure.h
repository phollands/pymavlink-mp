// MESSAGE SCALED_PRESSURE PACKING

#define MAVLINK_MSG_ID_SCALED_PRESSURE 38

typedef struct __mavlink_scaled_pressure_t
{
 uint64_t usec; ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 float press_abs; ///< Absolute pressure (hectopascal)
 float press_diff; ///< Differential pressure 1 (hectopascal)
 int16_t temperature; ///< Temperature measurement (0.01 degrees celsius)
} mavlink_scaled_pressure_t;

/**
 * @brief Pack a scaled_pressure message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param press_abs Absolute pressure (hectopascal)
 * @param press_diff Differential pressure 1 (hectopascal)
 * @param temperature Temperature measurement (0.01 degrees celsius)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_scaled_pressure_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t usec, float press_abs, float press_diff, int16_t temperature)
{
	msg->msgid = MAVLINK_MSG_ID_SCALED_PRESSURE;

	put_uint64_t_by_index(usec, 0,  msg->payload); // Timestamp (microseconds since UNIX epoch or microseconds since system boot)
	put_float_by_index(press_abs, 8,  msg->payload); // Absolute pressure (hectopascal)
	put_float_by_index(press_diff, 12,  msg->payload); // Differential pressure 1 (hectopascal)
	put_int16_t_by_index(temperature, 16,  msg->payload); // Temperature measurement (0.01 degrees celsius)

	return mavlink_finalize_message(msg, system_id, component_id, 18, 153);
}

/**
 * @brief Pack a scaled_pressure message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param press_abs Absolute pressure (hectopascal)
 * @param press_diff Differential pressure 1 (hectopascal)
 * @param temperature Temperature measurement (0.01 degrees celsius)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_scaled_pressure_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t usec,float press_abs,float press_diff,int16_t temperature)
{
	msg->msgid = MAVLINK_MSG_ID_SCALED_PRESSURE;

	put_uint64_t_by_index(usec, 0,  msg->payload); // Timestamp (microseconds since UNIX epoch or microseconds since system boot)
	put_float_by_index(press_abs, 8,  msg->payload); // Absolute pressure (hectopascal)
	put_float_by_index(press_diff, 12,  msg->payload); // Differential pressure 1 (hectopascal)
	put_int16_t_by_index(temperature, 16,  msg->payload); // Temperature measurement (0.01 degrees celsius)

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 18, 153);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

/**
 * @brief Pack a scaled_pressure message on a channel and send
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param press_abs Absolute pressure (hectopascal)
 * @param press_diff Differential pressure 1 (hectopascal)
 * @param temperature Temperature measurement (0.01 degrees celsius)
 */
static inline void mavlink_msg_scaled_pressure_pack_chan_send(mavlink_channel_t chan,
							   mavlink_message_t* msg,
						           uint64_t usec,float press_abs,float press_diff,int16_t temperature)
{
	msg->msgid = MAVLINK_MSG_ID_SCALED_PRESSURE;

	put_uint64_t_by_index(usec, 0,  msg->payload); // Timestamp (microseconds since UNIX epoch or microseconds since system boot)
	put_float_by_index(press_abs, 8,  msg->payload); // Absolute pressure (hectopascal)
	put_float_by_index(press_diff, 12,  msg->payload); // Differential pressure 1 (hectopascal)
	put_int16_t_by_index(temperature, 16,  msg->payload); // Temperature measurement (0.01 degrees celsius)

	mavlink_finalize_message_chan_send(msg, chan, 18, 153);
}
#endif // MAVLINK_USE_CONVENIENCE_FUNCTIONS


/**
 * @brief Encode a scaled_pressure struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param scaled_pressure C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_scaled_pressure_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_scaled_pressure_t* scaled_pressure)
{
	return mavlink_msg_scaled_pressure_pack(system_id, component_id, msg, scaled_pressure->usec, scaled_pressure->press_abs, scaled_pressure->press_diff, scaled_pressure->temperature);
}

/**
 * @brief Send a scaled_pressure message
 * @param chan MAVLink channel to send the message
 *
 * @param usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param press_abs Absolute pressure (hectopascal)
 * @param press_diff Differential pressure 1 (hectopascal)
 * @param temperature Temperature measurement (0.01 degrees celsius)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_scaled_pressure_send(mavlink_channel_t chan, uint64_t usec, float press_abs, float press_diff, int16_t temperature)
{
	MAVLINK_ALIGNED_MESSAGE(msg, 18);
	mavlink_msg_scaled_pressure_pack_chan_send(chan, msg, usec, press_abs, press_diff, temperature);
}

#endif

// MESSAGE SCALED_PRESSURE UNPACKING


/**
 * @brief Get field usec from scaled_pressure message
 *
 * @return Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
static inline uint64_t mavlink_msg_scaled_pressure_get_usec(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field press_abs from scaled_pressure message
 *
 * @return Absolute pressure (hectopascal)
 */
static inline float mavlink_msg_scaled_pressure_get_press_abs(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  8);
}

/**
 * @brief Get field press_diff from scaled_pressure message
 *
 * @return Differential pressure 1 (hectopascal)
 */
static inline float mavlink_msg_scaled_pressure_get_press_diff(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  12);
}

/**
 * @brief Get field temperature from scaled_pressure message
 *
 * @return Temperature measurement (0.01 degrees celsius)
 */
static inline int16_t mavlink_msg_scaled_pressure_get_temperature(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_int16_t(msg,  16);
}

/**
 * @brief Decode a scaled_pressure message into a struct
 *
 * @param msg The message to decode
 * @param scaled_pressure C-struct to decode the message contents into
 */
static inline void mavlink_msg_scaled_pressure_decode(const mavlink_message_t* msg, mavlink_scaled_pressure_t* scaled_pressure)
{
#if MAVLINK_NEED_BYTE_SWAP
	scaled_pressure->usec = mavlink_msg_scaled_pressure_get_usec(msg);
	scaled_pressure->press_abs = mavlink_msg_scaled_pressure_get_press_abs(msg);
	scaled_pressure->press_diff = mavlink_msg_scaled_pressure_get_press_diff(msg);
	scaled_pressure->temperature = mavlink_msg_scaled_pressure_get_temperature(msg);
#else
	memcpy(scaled_pressure, msg->payload, 18);
#endif
}
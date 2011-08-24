// MESSAGE SET_CAM_SHUTTER PACKING

#define MAVLINK_MSG_ID_SET_CAM_SHUTTER 151

typedef struct __mavlink_set_cam_shutter_t
{
 uint8_t cam_no; ///< Camera id
 uint8_t cam_mode; ///< Camera mode: 0 = auto, 1 = manual
 uint8_t trigger_pin; ///< Trigger pin, 0-3 for PtGrey FireFly
 uint16_t interval; ///< Shutter interval, in microseconds
 uint16_t exposure; ///< Exposure time, in microseconds
 float gain; ///< Camera gain
} mavlink_set_cam_shutter_t;

/**
 * @brief Pack a set_cam_shutter message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param cam_no Camera id
 * @param cam_mode Camera mode: 0 = auto, 1 = manual
 * @param trigger_pin Trigger pin, 0-3 for PtGrey FireFly
 * @param interval Shutter interval, in microseconds
 * @param exposure Exposure time, in microseconds
 * @param gain Camera gain
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_cam_shutter_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t cam_no, uint8_t cam_mode, uint8_t trigger_pin, uint16_t interval, uint16_t exposure, float gain)
{
	msg->msgid = MAVLINK_MSG_ID_SET_CAM_SHUTTER;

	put_uint8_t_by_index(cam_no, 0,  msg->payload); // Camera id
	put_uint8_t_by_index(cam_mode, 1,  msg->payload); // Camera mode: 0 = auto, 1 = manual
	put_uint8_t_by_index(trigger_pin, 2,  msg->payload); // Trigger pin, 0-3 for PtGrey FireFly
	put_uint16_t_by_index(interval, 3,  msg->payload); // Shutter interval, in microseconds
	put_uint16_t_by_index(exposure, 5,  msg->payload); // Exposure time, in microseconds
	put_float_by_index(gain, 7,  msg->payload); // Camera gain

	return mavlink_finalize_message(msg, system_id, component_id, 11, 206);
}

/**
 * @brief Pack a set_cam_shutter message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param cam_no Camera id
 * @param cam_mode Camera mode: 0 = auto, 1 = manual
 * @param trigger_pin Trigger pin, 0-3 for PtGrey FireFly
 * @param interval Shutter interval, in microseconds
 * @param exposure Exposure time, in microseconds
 * @param gain Camera gain
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_cam_shutter_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t cam_no,uint8_t cam_mode,uint8_t trigger_pin,uint16_t interval,uint16_t exposure,float gain)
{
	msg->msgid = MAVLINK_MSG_ID_SET_CAM_SHUTTER;

	put_uint8_t_by_index(cam_no, 0,  msg->payload); // Camera id
	put_uint8_t_by_index(cam_mode, 1,  msg->payload); // Camera mode: 0 = auto, 1 = manual
	put_uint8_t_by_index(trigger_pin, 2,  msg->payload); // Trigger pin, 0-3 for PtGrey FireFly
	put_uint16_t_by_index(interval, 3,  msg->payload); // Shutter interval, in microseconds
	put_uint16_t_by_index(exposure, 5,  msg->payload); // Exposure time, in microseconds
	put_float_by_index(gain, 7,  msg->payload); // Camera gain

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 11, 206);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

/**
 * @brief Pack a set_cam_shutter message on a channel and send
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param cam_no Camera id
 * @param cam_mode Camera mode: 0 = auto, 1 = manual
 * @param trigger_pin Trigger pin, 0-3 for PtGrey FireFly
 * @param interval Shutter interval, in microseconds
 * @param exposure Exposure time, in microseconds
 * @param gain Camera gain
 */
static inline void mavlink_msg_set_cam_shutter_pack_chan_send(mavlink_channel_t chan,
							   mavlink_message_t* msg,
						           uint8_t cam_no,uint8_t cam_mode,uint8_t trigger_pin,uint16_t interval,uint16_t exposure,float gain)
{
	msg->msgid = MAVLINK_MSG_ID_SET_CAM_SHUTTER;

	put_uint8_t_by_index(cam_no, 0,  msg->payload); // Camera id
	put_uint8_t_by_index(cam_mode, 1,  msg->payload); // Camera mode: 0 = auto, 1 = manual
	put_uint8_t_by_index(trigger_pin, 2,  msg->payload); // Trigger pin, 0-3 for PtGrey FireFly
	put_uint16_t_by_index(interval, 3,  msg->payload); // Shutter interval, in microseconds
	put_uint16_t_by_index(exposure, 5,  msg->payload); // Exposure time, in microseconds
	put_float_by_index(gain, 7,  msg->payload); // Camera gain

	mavlink_finalize_message_chan_send(msg, chan, 11, 206);
}
#endif // MAVLINK_USE_CONVENIENCE_FUNCTIONS


/**
 * @brief Encode a set_cam_shutter struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_cam_shutter C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_cam_shutter_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_cam_shutter_t* set_cam_shutter)
{
	return mavlink_msg_set_cam_shutter_pack(system_id, component_id, msg, set_cam_shutter->cam_no, set_cam_shutter->cam_mode, set_cam_shutter->trigger_pin, set_cam_shutter->interval, set_cam_shutter->exposure, set_cam_shutter->gain);
}

/**
 * @brief Send a set_cam_shutter message
 * @param chan MAVLink channel to send the message
 *
 * @param cam_no Camera id
 * @param cam_mode Camera mode: 0 = auto, 1 = manual
 * @param trigger_pin Trigger pin, 0-3 for PtGrey FireFly
 * @param interval Shutter interval, in microseconds
 * @param exposure Exposure time, in microseconds
 * @param gain Camera gain
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_cam_shutter_send(mavlink_channel_t chan, uint8_t cam_no, uint8_t cam_mode, uint8_t trigger_pin, uint16_t interval, uint16_t exposure, float gain)
{
	MAVLINK_ALIGNED_MESSAGE(msg, 11);
	mavlink_msg_set_cam_shutter_pack_chan_send(chan, msg, cam_no, cam_mode, trigger_pin, interval, exposure, gain);
}

#endif

// MESSAGE SET_CAM_SHUTTER UNPACKING


/**
 * @brief Get field cam_no from set_cam_shutter message
 *
 * @return Camera id
 */
static inline uint8_t mavlink_msg_set_cam_shutter_get_cam_no(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field cam_mode from set_cam_shutter message
 *
 * @return Camera mode: 0 = auto, 1 = manual
 */
static inline uint8_t mavlink_msg_set_cam_shutter_get_cam_mode(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field trigger_pin from set_cam_shutter message
 *
 * @return Trigger pin, 0-3 for PtGrey FireFly
 */
static inline uint8_t mavlink_msg_set_cam_shutter_get_trigger_pin(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field interval from set_cam_shutter message
 *
 * @return Shutter interval, in microseconds
 */
static inline uint16_t mavlink_msg_set_cam_shutter_get_interval(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint16_t(msg,  3);
}

/**
 * @brief Get field exposure from set_cam_shutter message
 *
 * @return Exposure time, in microseconds
 */
static inline uint16_t mavlink_msg_set_cam_shutter_get_exposure(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint16_t(msg,  5);
}

/**
 * @brief Get field gain from set_cam_shutter message
 *
 * @return Camera gain
 */
static inline float mavlink_msg_set_cam_shutter_get_gain(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  7);
}

/**
 * @brief Decode a set_cam_shutter message into a struct
 *
 * @param msg The message to decode
 * @param set_cam_shutter C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_cam_shutter_decode(const mavlink_message_t* msg, mavlink_set_cam_shutter_t* set_cam_shutter)
{
#if MAVLINK_NEED_BYTE_SWAP
	set_cam_shutter->cam_no = mavlink_msg_set_cam_shutter_get_cam_no(msg);
	set_cam_shutter->cam_mode = mavlink_msg_set_cam_shutter_get_cam_mode(msg);
	set_cam_shutter->trigger_pin = mavlink_msg_set_cam_shutter_get_trigger_pin(msg);
	set_cam_shutter->interval = mavlink_msg_set_cam_shutter_get_interval(msg);
	set_cam_shutter->exposure = mavlink_msg_set_cam_shutter_get_exposure(msg);
	set_cam_shutter->gain = mavlink_msg_set_cam_shutter_get_gain(msg);
#else
	memcpy(set_cam_shutter, msg->payload, 11);
#endif
}
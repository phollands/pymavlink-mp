// MESSAGE GPS_RAW_INT PACKING

#define MAVLINK_MSG_ID_GPS_RAW_INT 25

typedef struct __mavlink_gps_raw_int_t
{
 uint64_t usec; ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 uint8_t fix_type; ///< 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
 int32_t lat; ///< Latitude in 1E7 degrees
 int32_t lon; ///< Longitude in 1E7 degrees
 int32_t alt; ///< Altitude in 1E3 meters (millimeters)
 float eph; ///< GPS HDOP
 float epv; ///< GPS VDOP
 float v; ///< GPS ground speed (m/s)
 float hdg; ///< Compass heading in degrees, 0..360 degrees
} mavlink_gps_raw_int_t;

/**
 * @brief Pack a gps_raw_int message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param fix_type 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
 * @param lat Latitude in 1E7 degrees
 * @param lon Longitude in 1E7 degrees
 * @param alt Altitude in 1E3 meters (millimeters)
 * @param eph GPS HDOP
 * @param epv GPS VDOP
 * @param v GPS ground speed (m/s)
 * @param hdg Compass heading in degrees, 0..360 degrees
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_raw_int_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t usec, uint8_t fix_type, int32_t lat, int32_t lon, int32_t alt, float eph, float epv, float v, float hdg)
{
	msg->msgid = MAVLINK_MSG_ID_GPS_RAW_INT;

	put_uint64_t_by_index(usec, 0,  MAVLINK_PAYLOAD(msg)); // Timestamp (microseconds since UNIX epoch or microseconds since system boot)
	put_uint8_t_by_index(fix_type, 8,  MAVLINK_PAYLOAD(msg)); // 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
	put_int32_t_by_index(lat, 9,  MAVLINK_PAYLOAD(msg)); // Latitude in 1E7 degrees
	put_int32_t_by_index(lon, 13,  MAVLINK_PAYLOAD(msg)); // Longitude in 1E7 degrees
	put_int32_t_by_index(alt, 17,  MAVLINK_PAYLOAD(msg)); // Altitude in 1E3 meters (millimeters)
	put_float_by_index(eph, 21,  MAVLINK_PAYLOAD(msg)); // GPS HDOP
	put_float_by_index(epv, 25,  MAVLINK_PAYLOAD(msg)); // GPS VDOP
	put_float_by_index(v, 29,  MAVLINK_PAYLOAD(msg)); // GPS ground speed (m/s)
	put_float_by_index(hdg, 33,  MAVLINK_PAYLOAD(msg)); // Compass heading in degrees, 0..360 degrees

	return mavlink_finalize_message(msg, system_id, component_id, 37, 206);
}

/**
 * @brief Pack a gps_raw_int message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param fix_type 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
 * @param lat Latitude in 1E7 degrees
 * @param lon Longitude in 1E7 degrees
 * @param alt Altitude in 1E3 meters (millimeters)
 * @param eph GPS HDOP
 * @param epv GPS VDOP
 * @param v GPS ground speed (m/s)
 * @param hdg Compass heading in degrees, 0..360 degrees
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_raw_int_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t usec,uint8_t fix_type,int32_t lat,int32_t lon,int32_t alt,float eph,float epv,float v,float hdg)
{
	msg->msgid = MAVLINK_MSG_ID_GPS_RAW_INT;

	put_uint64_t_by_index(usec, 0,  MAVLINK_PAYLOAD(msg)); // Timestamp (microseconds since UNIX epoch or microseconds since system boot)
	put_uint8_t_by_index(fix_type, 8,  MAVLINK_PAYLOAD(msg)); // 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
	put_int32_t_by_index(lat, 9,  MAVLINK_PAYLOAD(msg)); // Latitude in 1E7 degrees
	put_int32_t_by_index(lon, 13,  MAVLINK_PAYLOAD(msg)); // Longitude in 1E7 degrees
	put_int32_t_by_index(alt, 17,  MAVLINK_PAYLOAD(msg)); // Altitude in 1E3 meters (millimeters)
	put_float_by_index(eph, 21,  MAVLINK_PAYLOAD(msg)); // GPS HDOP
	put_float_by_index(epv, 25,  MAVLINK_PAYLOAD(msg)); // GPS VDOP
	put_float_by_index(v, 29,  MAVLINK_PAYLOAD(msg)); // GPS ground speed (m/s)
	put_float_by_index(hdg, 33,  MAVLINK_PAYLOAD(msg)); // Compass heading in degrees, 0..360 degrees

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 37, 206);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

/**
 * @brief Pack a gps_raw_int message on a channel and send
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param fix_type 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
 * @param lat Latitude in 1E7 degrees
 * @param lon Longitude in 1E7 degrees
 * @param alt Altitude in 1E3 meters (millimeters)
 * @param eph GPS HDOP
 * @param epv GPS VDOP
 * @param v GPS ground speed (m/s)
 * @param hdg Compass heading in degrees, 0..360 degrees
 */
static inline void mavlink_msg_gps_raw_int_pack_chan_send(mavlink_channel_t chan,
							   mavlink_message_t* msg,
						           uint64_t usec,uint8_t fix_type,int32_t lat,int32_t lon,int32_t alt,float eph,float epv,float v,float hdg)
{
	msg->msgid = MAVLINK_MSG_ID_GPS_RAW_INT;

	put_uint64_t_by_index(usec, 0,  MAVLINK_PAYLOAD(msg)); // Timestamp (microseconds since UNIX epoch or microseconds since system boot)
	put_uint8_t_by_index(fix_type, 8,  MAVLINK_PAYLOAD(msg)); // 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
	put_int32_t_by_index(lat, 9,  MAVLINK_PAYLOAD(msg)); // Latitude in 1E7 degrees
	put_int32_t_by_index(lon, 13,  MAVLINK_PAYLOAD(msg)); // Longitude in 1E7 degrees
	put_int32_t_by_index(alt, 17,  MAVLINK_PAYLOAD(msg)); // Altitude in 1E3 meters (millimeters)
	put_float_by_index(eph, 21,  MAVLINK_PAYLOAD(msg)); // GPS HDOP
	put_float_by_index(epv, 25,  MAVLINK_PAYLOAD(msg)); // GPS VDOP
	put_float_by_index(v, 29,  MAVLINK_PAYLOAD(msg)); // GPS ground speed (m/s)
	put_float_by_index(hdg, 33,  MAVLINK_PAYLOAD(msg)); // Compass heading in degrees, 0..360 degrees

	mavlink_finalize_message_chan_send(msg, chan, 37, 206);
}
#endif // MAVLINK_USE_CONVENIENCE_FUNCTIONS


/**
 * @brief Encode a gps_raw_int struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gps_raw_int C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_raw_int_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gps_raw_int_t* gps_raw_int)
{
	return mavlink_msg_gps_raw_int_pack(system_id, component_id, msg, gps_raw_int->usec, gps_raw_int->fix_type, gps_raw_int->lat, gps_raw_int->lon, gps_raw_int->alt, gps_raw_int->eph, gps_raw_int->epv, gps_raw_int->v, gps_raw_int->hdg);
}

/**
 * @brief Send a gps_raw_int message
 * @param chan MAVLink channel to send the message
 *
 * @param usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param fix_type 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
 * @param lat Latitude in 1E7 degrees
 * @param lon Longitude in 1E7 degrees
 * @param alt Altitude in 1E3 meters (millimeters)
 * @param eph GPS HDOP
 * @param epv GPS VDOP
 * @param v GPS ground speed (m/s)
 * @param hdg Compass heading in degrees, 0..360 degrees
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gps_raw_int_send(mavlink_channel_t chan, uint64_t usec, uint8_t fix_type, int32_t lat, int32_t lon, int32_t alt, float eph, float epv, float v, float hdg)
{
	MAVLINK_ALIGNED_MESSAGE(msg, 37);
	mavlink_msg_gps_raw_int_pack_chan_send(chan, msg, usec, fix_type, lat, lon, alt, eph, epv, v, hdg);
}

#endif

// MESSAGE GPS_RAW_INT UNPACKING


/**
 * @brief Get field usec from gps_raw_int message
 *
 * @return Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
static inline uint64_t mavlink_msg_gps_raw_int_get_usec(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field fix_type from gps_raw_int message
 *
 * @return 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
 */
static inline uint8_t mavlink_msg_gps_raw_int_get_fix_type(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field lat from gps_raw_int message
 *
 * @return Latitude in 1E7 degrees
 */
static inline int32_t mavlink_msg_gps_raw_int_get_lat(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_int32_t(msg,  9);
}

/**
 * @brief Get field lon from gps_raw_int message
 *
 * @return Longitude in 1E7 degrees
 */
static inline int32_t mavlink_msg_gps_raw_int_get_lon(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_int32_t(msg,  13);
}

/**
 * @brief Get field alt from gps_raw_int message
 *
 * @return Altitude in 1E3 meters (millimeters)
 */
static inline int32_t mavlink_msg_gps_raw_int_get_alt(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_int32_t(msg,  17);
}

/**
 * @brief Get field eph from gps_raw_int message
 *
 * @return GPS HDOP
 */
static inline float mavlink_msg_gps_raw_int_get_eph(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  21);
}

/**
 * @brief Get field epv from gps_raw_int message
 *
 * @return GPS VDOP
 */
static inline float mavlink_msg_gps_raw_int_get_epv(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  25);
}

/**
 * @brief Get field v from gps_raw_int message
 *
 * @return GPS ground speed (m/s)
 */
static inline float mavlink_msg_gps_raw_int_get_v(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  29);
}

/**
 * @brief Get field hdg from gps_raw_int message
 *
 * @return Compass heading in degrees, 0..360 degrees
 */
static inline float mavlink_msg_gps_raw_int_get_hdg(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  33);
}

/**
 * @brief Decode a gps_raw_int message into a struct
 *
 * @param msg The message to decode
 * @param gps_raw_int C-struct to decode the message contents into
 */
static inline void mavlink_msg_gps_raw_int_decode(const mavlink_message_t* msg, mavlink_gps_raw_int_t* gps_raw_int)
{
#if MAVLINK_NEED_BYTE_SWAP
	gps_raw_int->usec = mavlink_msg_gps_raw_int_get_usec(msg);
	gps_raw_int->fix_type = mavlink_msg_gps_raw_int_get_fix_type(msg);
	gps_raw_int->lat = mavlink_msg_gps_raw_int_get_lat(msg);
	gps_raw_int->lon = mavlink_msg_gps_raw_int_get_lon(msg);
	gps_raw_int->alt = mavlink_msg_gps_raw_int_get_alt(msg);
	gps_raw_int->eph = mavlink_msg_gps_raw_int_get_eph(msg);
	gps_raw_int->epv = mavlink_msg_gps_raw_int_get_epv(msg);
	gps_raw_int->v = mavlink_msg_gps_raw_int_get_v(msg);
	gps_raw_int->hdg = mavlink_msg_gps_raw_int_get_hdg(msg);
#else
	memcpy(gps_raw_int, MAVLINK_PAYLOAD(msg), 37);
#endif
}

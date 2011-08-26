// MESSAGE TEST_TYPES PACKING

#define MAVLINK_MSG_ID_TEST_TYPES 0

typedef struct __mavlink_test_types_t
{
 uint64_t u64; ///< uint64_t
 int64_t s64; ///< int64_t
 double d; ///< double
 uint64_t u64_array[3]; ///< uint64_t_array
 int64_t s64_array[3]; ///< int64_t_array
 double d_array[3]; ///< double_array
 uint32_t u32; ///< uint32_t
 int32_t s32; ///< int32_t
 float f; ///< float
 uint32_t u32_array[3]; ///< uint32_t_array
 int32_t s32_array[3]; ///< int32_t_array
 float f_array[3]; ///< float_array
 uint16_t u16; ///< uint16_t
 int16_t s16; ///< int16_t
 uint16_t u16_array[3]; ///< uint16_t_array
 int16_t s16_array[3]; ///< int16_t_array
 char c; ///< char
 char s[10]; ///< string
 uint8_t u8; ///< uint8_t
 int8_t s8; ///< int8_t
 uint8_t u8_array[3]; ///< uint8_t_array
 int8_t s8_array[3]; ///< int8_t_array
} mavlink_test_types_t;

/**
 * @brief Pack a test_types message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param c char
 * @param s string
 * @param u8 uint8_t
 * @param u16 uint16_t
 * @param u32 uint32_t
 * @param u64 uint64_t
 * @param s8 int8_t
 * @param s16 int16_t
 * @param s32 int32_t
 * @param s64 int64_t
 * @param f float
 * @param d double
 * @param u8_array uint8_t_array
 * @param u16_array uint16_t_array
 * @param u32_array uint32_t_array
 * @param u64_array uint64_t_array
 * @param s8_array int8_t_array
 * @param s16_array int16_t_array
 * @param s32_array int32_t_array
 * @param s64_array int64_t_array
 * @param f_array float_array
 * @param d_array double_array
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_test_types_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       char c, const char *s, uint8_t u8, uint16_t u16, uint32_t u32, uint64_t u64, int8_t s8, int16_t s16, int32_t s32, int64_t s64, float f, double d, const uint8_t *u8_array, const uint16_t *u16_array, const uint32_t *u32_array, const uint64_t *u64_array, const int8_t *s8_array, const int16_t *s16_array, const int32_t *s32_array, const int64_t *s64_array, const float *f_array, const double *d_array)
{
	msg->msgid = MAVLINK_MSG_ID_TEST_TYPES;

	put_uint64_t_by_index(u64, 0,  MAVLINK_PAYLOAD(msg)); // uint64_t
	put_int64_t_by_index(s64, 8,  MAVLINK_PAYLOAD(msg)); // int64_t
	put_double_by_index(d, 16,  MAVLINK_PAYLOAD(msg)); // double
	put_uint64_t_array_by_index(u64_array, 24, 3,  MAVLINK_PAYLOAD(msg)); // uint64_t_array
	put_int64_t_array_by_index(s64_array, 48, 3,  MAVLINK_PAYLOAD(msg)); // int64_t_array
	put_double_array_by_index(d_array, 72, 3,  MAVLINK_PAYLOAD(msg)); // double_array
	put_uint32_t_by_index(u32, 96,  MAVLINK_PAYLOAD(msg)); // uint32_t
	put_int32_t_by_index(s32, 100,  MAVLINK_PAYLOAD(msg)); // int32_t
	put_float_by_index(f, 104,  MAVLINK_PAYLOAD(msg)); // float
	put_uint32_t_array_by_index(u32_array, 108, 3,  MAVLINK_PAYLOAD(msg)); // uint32_t_array
	put_int32_t_array_by_index(s32_array, 120, 3,  MAVLINK_PAYLOAD(msg)); // int32_t_array
	put_float_array_by_index(f_array, 132, 3,  MAVLINK_PAYLOAD(msg)); // float_array
	put_uint16_t_by_index(u16, 144,  MAVLINK_PAYLOAD(msg)); // uint16_t
	put_int16_t_by_index(s16, 146,  MAVLINK_PAYLOAD(msg)); // int16_t
	put_uint16_t_array_by_index(u16_array, 148, 3,  MAVLINK_PAYLOAD(msg)); // uint16_t_array
	put_int16_t_array_by_index(s16_array, 154, 3,  MAVLINK_PAYLOAD(msg)); // int16_t_array
	put_char_by_index(c, 160,  MAVLINK_PAYLOAD(msg)); // char
	put_char_array_by_index(s, 161, 10,  MAVLINK_PAYLOAD(msg)); // string
	put_uint8_t_by_index(u8, 171,  MAVLINK_PAYLOAD(msg)); // uint8_t
	put_int8_t_by_index(s8, 172,  MAVLINK_PAYLOAD(msg)); // int8_t
	put_uint8_t_array_by_index(u8_array, 173, 3,  MAVLINK_PAYLOAD(msg)); // uint8_t_array
	put_int8_t_array_by_index(s8_array, 176, 3,  MAVLINK_PAYLOAD(msg)); // int8_t_array

	return mavlink_finalize_message(msg, system_id, component_id, 179, 136);
}

/**
 * @brief Pack a test_types message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param c char
 * @param s string
 * @param u8 uint8_t
 * @param u16 uint16_t
 * @param u32 uint32_t
 * @param u64 uint64_t
 * @param s8 int8_t
 * @param s16 int16_t
 * @param s32 int32_t
 * @param s64 int64_t
 * @param f float
 * @param d double
 * @param u8_array uint8_t_array
 * @param u16_array uint16_t_array
 * @param u32_array uint32_t_array
 * @param u64_array uint64_t_array
 * @param s8_array int8_t_array
 * @param s16_array int16_t_array
 * @param s32_array int32_t_array
 * @param s64_array int64_t_array
 * @param f_array float_array
 * @param d_array double_array
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_test_types_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           char c,const char *s,uint8_t u8,uint16_t u16,uint32_t u32,uint64_t u64,int8_t s8,int16_t s16,int32_t s32,int64_t s64,float f,double d,const uint8_t *u8_array,const uint16_t *u16_array,const uint32_t *u32_array,const uint64_t *u64_array,const int8_t *s8_array,const int16_t *s16_array,const int32_t *s32_array,const int64_t *s64_array,const float *f_array,const double *d_array)
{
	msg->msgid = MAVLINK_MSG_ID_TEST_TYPES;

	put_uint64_t_by_index(u64, 0,  MAVLINK_PAYLOAD(msg)); // uint64_t
	put_int64_t_by_index(s64, 8,  MAVLINK_PAYLOAD(msg)); // int64_t
	put_double_by_index(d, 16,  MAVLINK_PAYLOAD(msg)); // double
	put_uint64_t_array_by_index(u64_array, 24, 3,  MAVLINK_PAYLOAD(msg)); // uint64_t_array
	put_int64_t_array_by_index(s64_array, 48, 3,  MAVLINK_PAYLOAD(msg)); // int64_t_array
	put_double_array_by_index(d_array, 72, 3,  MAVLINK_PAYLOAD(msg)); // double_array
	put_uint32_t_by_index(u32, 96,  MAVLINK_PAYLOAD(msg)); // uint32_t
	put_int32_t_by_index(s32, 100,  MAVLINK_PAYLOAD(msg)); // int32_t
	put_float_by_index(f, 104,  MAVLINK_PAYLOAD(msg)); // float
	put_uint32_t_array_by_index(u32_array, 108, 3,  MAVLINK_PAYLOAD(msg)); // uint32_t_array
	put_int32_t_array_by_index(s32_array, 120, 3,  MAVLINK_PAYLOAD(msg)); // int32_t_array
	put_float_array_by_index(f_array, 132, 3,  MAVLINK_PAYLOAD(msg)); // float_array
	put_uint16_t_by_index(u16, 144,  MAVLINK_PAYLOAD(msg)); // uint16_t
	put_int16_t_by_index(s16, 146,  MAVLINK_PAYLOAD(msg)); // int16_t
	put_uint16_t_array_by_index(u16_array, 148, 3,  MAVLINK_PAYLOAD(msg)); // uint16_t_array
	put_int16_t_array_by_index(s16_array, 154, 3,  MAVLINK_PAYLOAD(msg)); // int16_t_array
	put_char_by_index(c, 160,  MAVLINK_PAYLOAD(msg)); // char
	put_char_array_by_index(s, 161, 10,  MAVLINK_PAYLOAD(msg)); // string
	put_uint8_t_by_index(u8, 171,  MAVLINK_PAYLOAD(msg)); // uint8_t
	put_int8_t_by_index(s8, 172,  MAVLINK_PAYLOAD(msg)); // int8_t
	put_uint8_t_array_by_index(u8_array, 173, 3,  MAVLINK_PAYLOAD(msg)); // uint8_t_array
	put_int8_t_array_by_index(s8_array, 176, 3,  MAVLINK_PAYLOAD(msg)); // int8_t_array

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 179, 136);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

/**
 * @brief Pack a test_types message on a channel and send
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param c char
 * @param s string
 * @param u8 uint8_t
 * @param u16 uint16_t
 * @param u32 uint32_t
 * @param u64 uint64_t
 * @param s8 int8_t
 * @param s16 int16_t
 * @param s32 int32_t
 * @param s64 int64_t
 * @param f float
 * @param d double
 * @param u8_array uint8_t_array
 * @param u16_array uint16_t_array
 * @param u32_array uint32_t_array
 * @param u64_array uint64_t_array
 * @param s8_array int8_t_array
 * @param s16_array int16_t_array
 * @param s32_array int32_t_array
 * @param s64_array int64_t_array
 * @param f_array float_array
 * @param d_array double_array
 */
static inline void mavlink_msg_test_types_pack_chan_send(mavlink_channel_t chan,
							   mavlink_message_t* msg,
						           char c,const char *s,uint8_t u8,uint16_t u16,uint32_t u32,uint64_t u64,int8_t s8,int16_t s16,int32_t s32,int64_t s64,float f,double d,const uint8_t *u8_array,const uint16_t *u16_array,const uint32_t *u32_array,const uint64_t *u64_array,const int8_t *s8_array,const int16_t *s16_array,const int32_t *s32_array,const int64_t *s64_array,const float *f_array,const double *d_array)
{
	msg->msgid = MAVLINK_MSG_ID_TEST_TYPES;

	put_uint64_t_by_index(u64, 0,  MAVLINK_PAYLOAD(msg)); // uint64_t
	put_int64_t_by_index(s64, 8,  MAVLINK_PAYLOAD(msg)); // int64_t
	put_double_by_index(d, 16,  MAVLINK_PAYLOAD(msg)); // double
	put_uint64_t_array_by_index(u64_array, 24, 3,  MAVLINK_PAYLOAD(msg)); // uint64_t_array
	put_int64_t_array_by_index(s64_array, 48, 3,  MAVLINK_PAYLOAD(msg)); // int64_t_array
	put_double_array_by_index(d_array, 72, 3,  MAVLINK_PAYLOAD(msg)); // double_array
	put_uint32_t_by_index(u32, 96,  MAVLINK_PAYLOAD(msg)); // uint32_t
	put_int32_t_by_index(s32, 100,  MAVLINK_PAYLOAD(msg)); // int32_t
	put_float_by_index(f, 104,  MAVLINK_PAYLOAD(msg)); // float
	put_uint32_t_array_by_index(u32_array, 108, 3,  MAVLINK_PAYLOAD(msg)); // uint32_t_array
	put_int32_t_array_by_index(s32_array, 120, 3,  MAVLINK_PAYLOAD(msg)); // int32_t_array
	put_float_array_by_index(f_array, 132, 3,  MAVLINK_PAYLOAD(msg)); // float_array
	put_uint16_t_by_index(u16, 144,  MAVLINK_PAYLOAD(msg)); // uint16_t
	put_int16_t_by_index(s16, 146,  MAVLINK_PAYLOAD(msg)); // int16_t
	put_uint16_t_array_by_index(u16_array, 148, 3,  MAVLINK_PAYLOAD(msg)); // uint16_t_array
	put_int16_t_array_by_index(s16_array, 154, 3,  MAVLINK_PAYLOAD(msg)); // int16_t_array
	put_char_by_index(c, 160,  MAVLINK_PAYLOAD(msg)); // char
	put_char_array_by_index(s, 161, 10,  MAVLINK_PAYLOAD(msg)); // string
	put_uint8_t_by_index(u8, 171,  MAVLINK_PAYLOAD(msg)); // uint8_t
	put_int8_t_by_index(s8, 172,  MAVLINK_PAYLOAD(msg)); // int8_t
	put_uint8_t_array_by_index(u8_array, 173, 3,  MAVLINK_PAYLOAD(msg)); // uint8_t_array
	put_int8_t_array_by_index(s8_array, 176, 3,  MAVLINK_PAYLOAD(msg)); // int8_t_array

	mavlink_finalize_message_chan_send(msg, chan, 179, 136);
}
#endif // MAVLINK_USE_CONVENIENCE_FUNCTIONS


/**
 * @brief Encode a test_types struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param test_types C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_test_types_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_test_types_t* test_types)
{
	return mavlink_msg_test_types_pack(system_id, component_id, msg, test_types->c, test_types->s, test_types->u8, test_types->u16, test_types->u32, test_types->u64, test_types->s8, test_types->s16, test_types->s32, test_types->s64, test_types->f, test_types->d, test_types->u8_array, test_types->u16_array, test_types->u32_array, test_types->u64_array, test_types->s8_array, test_types->s16_array, test_types->s32_array, test_types->s64_array, test_types->f_array, test_types->d_array);
}

/**
 * @brief Send a test_types message
 * @param chan MAVLink channel to send the message
 *
 * @param c char
 * @param s string
 * @param u8 uint8_t
 * @param u16 uint16_t
 * @param u32 uint32_t
 * @param u64 uint64_t
 * @param s8 int8_t
 * @param s16 int16_t
 * @param s32 int32_t
 * @param s64 int64_t
 * @param f float
 * @param d double
 * @param u8_array uint8_t_array
 * @param u16_array uint16_t_array
 * @param u32_array uint32_t_array
 * @param u64_array uint64_t_array
 * @param s8_array int8_t_array
 * @param s16_array int16_t_array
 * @param s32_array int32_t_array
 * @param s64_array int64_t_array
 * @param f_array float_array
 * @param d_array double_array
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_test_types_send(mavlink_channel_t chan, char c, const char *s, uint8_t u8, uint16_t u16, uint32_t u32, uint64_t u64, int8_t s8, int16_t s16, int32_t s32, int64_t s64, float f, double d, const uint8_t *u8_array, const uint16_t *u16_array, const uint32_t *u32_array, const uint64_t *u64_array, const int8_t *s8_array, const int16_t *s16_array, const int32_t *s32_array, const int64_t *s64_array, const float *f_array, const double *d_array)
{
	MAVLINK_ALIGNED_MESSAGE(msg, 179);
	mavlink_msg_test_types_pack_chan_send(chan, msg, c, s, u8, u16, u32, u64, s8, s16, s32, s64, f, d, u8_array, u16_array, u32_array, u64_array, s8_array, s16_array, s32_array, s64_array, f_array, d_array);
}

#endif

// MESSAGE TEST_TYPES UNPACKING


/**
 * @brief Get field c from test_types message
 *
 * @return char
 */
static inline char mavlink_msg_test_types_get_c(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_char(msg,  160);
}

/**
 * @brief Get field s from test_types message
 *
 * @return string
 */
static inline uint16_t mavlink_msg_test_types_get_s(const mavlink_message_t* msg, char *s)
{
	return MAVLINK_MSG_RETURN_char_array(msg, s, 10,  161);
}

/**
 * @brief Get field u8 from test_types message
 *
 * @return uint8_t
 */
static inline uint8_t mavlink_msg_test_types_get_u8(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint8_t(msg,  171);
}

/**
 * @brief Get field u16 from test_types message
 *
 * @return uint16_t
 */
static inline uint16_t mavlink_msg_test_types_get_u16(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint16_t(msg,  144);
}

/**
 * @brief Get field u32 from test_types message
 *
 * @return uint32_t
 */
static inline uint32_t mavlink_msg_test_types_get_u32(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint32_t(msg,  96);
}

/**
 * @brief Get field u64 from test_types message
 *
 * @return uint64_t
 */
static inline uint64_t mavlink_msg_test_types_get_u64(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field s8 from test_types message
 *
 * @return int8_t
 */
static inline int8_t mavlink_msg_test_types_get_s8(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_int8_t(msg,  172);
}

/**
 * @brief Get field s16 from test_types message
 *
 * @return int16_t
 */
static inline int16_t mavlink_msg_test_types_get_s16(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_int16_t(msg,  146);
}

/**
 * @brief Get field s32 from test_types message
 *
 * @return int32_t
 */
static inline int32_t mavlink_msg_test_types_get_s32(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_int32_t(msg,  100);
}

/**
 * @brief Get field s64 from test_types message
 *
 * @return int64_t
 */
static inline int64_t mavlink_msg_test_types_get_s64(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_int64_t(msg,  8);
}

/**
 * @brief Get field f from test_types message
 *
 * @return float
 */
static inline float mavlink_msg_test_types_get_f(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_float(msg,  104);
}

/**
 * @brief Get field d from test_types message
 *
 * @return double
 */
static inline double mavlink_msg_test_types_get_d(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_double(msg,  16);
}

/**
 * @brief Get field u8_array from test_types message
 *
 * @return uint8_t_array
 */
static inline uint16_t mavlink_msg_test_types_get_u8_array(const mavlink_message_t* msg, uint8_t *u8_array)
{
	return MAVLINK_MSG_RETURN_uint8_t_array(msg, u8_array, 3,  173);
}

/**
 * @brief Get field u16_array from test_types message
 *
 * @return uint16_t_array
 */
static inline uint16_t mavlink_msg_test_types_get_u16_array(const mavlink_message_t* msg, uint16_t *u16_array)
{
	return MAVLINK_MSG_RETURN_uint16_t_array(msg, u16_array, 3,  148);
}

/**
 * @brief Get field u32_array from test_types message
 *
 * @return uint32_t_array
 */
static inline uint16_t mavlink_msg_test_types_get_u32_array(const mavlink_message_t* msg, uint32_t *u32_array)
{
	return MAVLINK_MSG_RETURN_uint32_t_array(msg, u32_array, 3,  108);
}

/**
 * @brief Get field u64_array from test_types message
 *
 * @return uint64_t_array
 */
static inline uint16_t mavlink_msg_test_types_get_u64_array(const mavlink_message_t* msg, uint64_t *u64_array)
{
	return MAVLINK_MSG_RETURN_uint64_t_array(msg, u64_array, 3,  24);
}

/**
 * @brief Get field s8_array from test_types message
 *
 * @return int8_t_array
 */
static inline uint16_t mavlink_msg_test_types_get_s8_array(const mavlink_message_t* msg, int8_t *s8_array)
{
	return MAVLINK_MSG_RETURN_int8_t_array(msg, s8_array, 3,  176);
}

/**
 * @brief Get field s16_array from test_types message
 *
 * @return int16_t_array
 */
static inline uint16_t mavlink_msg_test_types_get_s16_array(const mavlink_message_t* msg, int16_t *s16_array)
{
	return MAVLINK_MSG_RETURN_int16_t_array(msg, s16_array, 3,  154);
}

/**
 * @brief Get field s32_array from test_types message
 *
 * @return int32_t_array
 */
static inline uint16_t mavlink_msg_test_types_get_s32_array(const mavlink_message_t* msg, int32_t *s32_array)
{
	return MAVLINK_MSG_RETURN_int32_t_array(msg, s32_array, 3,  120);
}

/**
 * @brief Get field s64_array from test_types message
 *
 * @return int64_t_array
 */
static inline uint16_t mavlink_msg_test_types_get_s64_array(const mavlink_message_t* msg, int64_t *s64_array)
{
	return MAVLINK_MSG_RETURN_int64_t_array(msg, s64_array, 3,  48);
}

/**
 * @brief Get field f_array from test_types message
 *
 * @return float_array
 */
static inline uint16_t mavlink_msg_test_types_get_f_array(const mavlink_message_t* msg, float *f_array)
{
	return MAVLINK_MSG_RETURN_float_array(msg, f_array, 3,  132);
}

/**
 * @brief Get field d_array from test_types message
 *
 * @return double_array
 */
static inline uint16_t mavlink_msg_test_types_get_d_array(const mavlink_message_t* msg, double *d_array)
{
	return MAVLINK_MSG_RETURN_double_array(msg, d_array, 3,  72);
}

/**
 * @brief Decode a test_types message into a struct
 *
 * @param msg The message to decode
 * @param test_types C-struct to decode the message contents into
 */
static inline void mavlink_msg_test_types_decode(const mavlink_message_t* msg, mavlink_test_types_t* test_types)
{
#if MAVLINK_NEED_BYTE_SWAP
	test_types->u64 = mavlink_msg_test_types_get_u64(msg);
	test_types->s64 = mavlink_msg_test_types_get_s64(msg);
	test_types->d = mavlink_msg_test_types_get_d(msg);
	mavlink_msg_test_types_get_u64_array(msg, test_types->u64_array);
	mavlink_msg_test_types_get_s64_array(msg, test_types->s64_array);
	mavlink_msg_test_types_get_d_array(msg, test_types->d_array);
	test_types->u32 = mavlink_msg_test_types_get_u32(msg);
	test_types->s32 = mavlink_msg_test_types_get_s32(msg);
	test_types->f = mavlink_msg_test_types_get_f(msg);
	mavlink_msg_test_types_get_u32_array(msg, test_types->u32_array);
	mavlink_msg_test_types_get_s32_array(msg, test_types->s32_array);
	mavlink_msg_test_types_get_f_array(msg, test_types->f_array);
	test_types->u16 = mavlink_msg_test_types_get_u16(msg);
	test_types->s16 = mavlink_msg_test_types_get_s16(msg);
	mavlink_msg_test_types_get_u16_array(msg, test_types->u16_array);
	mavlink_msg_test_types_get_s16_array(msg, test_types->s16_array);
	test_types->c = mavlink_msg_test_types_get_c(msg);
	mavlink_msg_test_types_get_s(msg, test_types->s);
	test_types->u8 = mavlink_msg_test_types_get_u8(msg);
	test_types->s8 = mavlink_msg_test_types_get_s8(msg);
	mavlink_msg_test_types_get_u8_array(msg, test_types->u8_array);
	mavlink_msg_test_types_get_s8_array(msg, test_types->s8_array);
#else
	memcpy(test_types, MAVLINK_PAYLOAD(msg), 179);
#endif
}

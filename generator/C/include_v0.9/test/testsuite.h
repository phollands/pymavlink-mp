/** @file
 *	@brief MAVLink comm protocol testsuite generated from test.xml
 *	@see http://qgroundcontrol.org/mavlink/
 *	Generated on Fri Aug 26 14:04:06 2011
 */
#ifndef TEST_TESTSUITE_H
#define TEST_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_test(uint8_t, uint8_t);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id)
{

	mavlink_test_test(system_id, component_id);
}
#endif




static void mavlink_test_test_types(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_test_types_t packet2, packet1 = {
		'A',
	"BCDEFGHIJ",
	230,
	17859,
	963498192,
	93372036854776941ULL,
	211,
	18639,
	963498972,
	93372036854777886LL,
	304.0,
	438.0,
	{ 228, 229, 230 },
	{ 20147, 20148, 20149 },
	{ 963500688, 963500689, 963500690 },
	{ 93372036854780469, 93372036854780470, 93372036854780471 },
	{ 171, 172, 173 },
	{ 22487, 22488, 22489 },
	{ 963503028, 963503029, 963503030 },
	{ 93372036854783304, 93372036854783305, 93372036854783306 },
	{ 1018.0, 1019.0, 1020.0 },
	{ 1208.0, 1209.0, 1210.0 },
	};
	if (sizeof(packet2) != 179) {
		packet2 = packet1; // cope with alignment within the packet
	}
	mavlink_msg_test_types_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_test_types_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
	mavlink_msg_test_types_pack(system_id, component_id, &msg , packet1.c , packet1.s , packet1.u8 , packet1.u16 , packet1.u32 , packet1.u64 , packet1.s8 , packet1.s16 , packet1.s32 , packet1.s64 , packet1.f , packet1.d , packet1.u8_array , packet1.u16_array , packet1.u32_array , packet1.u64_array , packet1.s8_array , packet1.s16_array , packet1.s32_array , packet1.s64_array , packet1.f_array , packet1.d_array );
	mavlink_msg_test_types_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.c , packet1.s , packet1.u8 , packet1.u16 , packet1.u32 , packet1.u64 , packet1.s8 , packet1.s16 , packet1.s32 , packet1.s64 , packet1.f , packet1.d , packet1.u8_array , packet1.u16_array , packet1.u32_array , packet1.u64_array , packet1.s8_array , packet1.s16_array , packet1.s32_array , packet1.s64_array , packet1.f_array , packet1.d_array );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_test_types_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.c , packet1.s , packet1.u8 , packet1.u16 , packet1.u32 , packet1.u64 , packet1.s8 , packet1.s16 , packet1.s32 , packet1.s64 , packet1.f , packet1.d , packet1.u8_array , packet1.u16_array , packet1.u32_array , packet1.u64_array , packet1.s8_array , packet1.s16_array , packet1.s32_array , packet1.s64_array , packet1.f_array , packet1.d_array );
	mavlink_msg_test_types_send(MAVLINK_COMM_2 , packet1.c , packet1.s , packet1.u8 , packet1.u16 , packet1.u32 , packet1.u64 , packet1.s8 , packet1.s16 , packet1.s32 , packet1.s64 , packet1.f , packet1.d , packet1.u8_array , packet1.u16_array , packet1.u32_array , packet1.u64_array , packet1.s8_array , packet1.s16_array , packet1.s32_array , packet1.s64_array , packet1.f_array , packet1.d_array );
}

static void mavlink_test_test(uint8_t system_id, uint8_t component_id)
{
	mavlink_test_test_types(system_id, component_id);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // TEST_TESTSUITE_H

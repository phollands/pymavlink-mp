/** @file
 *	@brief MAVLink comm protocol testsuite generated from ualberta.xml
 *	@see http://qgroundcontrol.org/mavlink/
 *	Generated on Fri Aug 26 09:46:52 2011
 */
#ifndef UALBERTA_TESTSUITE_H
#define UALBERTA_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif


static void mavlink_test_nav_filter_bias(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_nav_filter_bias_t packet2, packet1 = {
		.usec = 9223372036854775807LL,
	.accel_0 = 73.0,
	.accel_1 = 101.0,
	.accel_2 = 129.0,
	.gyro_0 = 157.0,
	.gyro_1 = 185.0,
	.gyro_2 = 213.0,
	};
	mavlink_msg_nav_filter_bias_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_nav_filter_bias_decode(&msg, &packet2);
	mavlink_msg_nav_filter_bias_pack(system_id, component_id, &msg , packet1.usec , packet1.accel_0 , packet1.accel_1 , packet1.accel_2 , packet1.gyro_0 , packet1.gyro_1 , packet1.gyro_2 );
	mavlink_msg_nav_filter_bias_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.usec , packet1.accel_0 , packet1.accel_1 , packet1.accel_2 , packet1.gyro_0 , packet1.gyro_1 , packet1.gyro_2 );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_nav_filter_bias_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.usec , packet1.accel_0 , packet1.accel_1 , packet1.accel_2 , packet1.gyro_0 , packet1.gyro_1 , packet1.gyro_2 );
	mavlink_msg_nav_filter_bias_send(MAVLINK_COMM_2 , packet1.usec , packet1.accel_0 , packet1.accel_1 , packet1.accel_2 , packet1.gyro_0 , packet1.gyro_1 , packet1.gyro_2 );
}

static void mavlink_test_radio_calibration(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_radio_calibration_t packet2, packet1 = {
		.aileron = "17235",
	.elevator = "17547",
	.rudder = "17859",
	.gyro = "18171",
	.pitch = "18379",
	.throttle = "18899",
	};
	mavlink_msg_radio_calibration_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_radio_calibration_decode(&msg, &packet2);
	mavlink_msg_radio_calibration_pack(system_id, component_id, &msg , packet1.aileron , packet1.elevator , packet1.rudder , packet1.gyro , packet1.pitch , packet1.throttle );
	mavlink_msg_radio_calibration_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.aileron , packet1.elevator , packet1.rudder , packet1.gyro , packet1.pitch , packet1.throttle );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_radio_calibration_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.aileron , packet1.elevator , packet1.rudder , packet1.gyro , packet1.pitch , packet1.throttle );
	mavlink_msg_radio_calibration_send(MAVLINK_COMM_2 , packet1.aileron , packet1.elevator , packet1.rudder , packet1.gyro , packet1.pitch , packet1.throttle );
}

static void mavlink_test_ualberta_sys_status(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_ualberta_sys_status_t packet2, packet1 = {
		.mode = 5,
	.nav_mode = 72,
	.pilot = 139,
	};
	mavlink_msg_ualberta_sys_status_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ualberta_sys_status_decode(&msg, &packet2);
	mavlink_msg_ualberta_sys_status_pack(system_id, component_id, &msg , packet1.mode , packet1.nav_mode , packet1.pilot );
	mavlink_msg_ualberta_sys_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mode , packet1.nav_mode , packet1.pilot );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ualberta_sys_status_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.mode , packet1.nav_mode , packet1.pilot );
	mavlink_msg_ualberta_sys_status_send(MAVLINK_COMM_2 , packet1.mode , packet1.nav_mode , packet1.pilot );
}

static void mavlink_test_all(uint8_t system_id, uint8_t component_id)
{
	mavlink_test_nav_filter_bias(system_id, component_id);
	mavlink_test_radio_calibration(system_id, component_id);
	mavlink_test_ualberta_sys_status(system_id, component_id);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // UALBERTA_TESTSUITE_H

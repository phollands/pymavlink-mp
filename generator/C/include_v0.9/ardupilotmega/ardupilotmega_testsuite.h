/** @file
 *	@brief MAVLink comm protocol testsuite generated from ardupilotmega.xml
 *	@see http://qgroundcontrol.org/mavlink/
 *	Generated on Fri Aug 26 09:46:50 2011
 */
#ifndef ARDUPILOTMEGA_TESTSUITE_H
#define ARDUPILOTMEGA_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif


static void mavlink_test_sensor_offsets(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_sensor_offsets_t packet2, packet1 = {
		.mag_ofs_x = 17235,
	.mag_ofs_y = 17339,
	.mag_ofs_z = 17443,
	.mag_declination = 59.0,
	.raw_press = 963497984,
	.raw_temp = 963498192,
	.gyro_cal_x = 143.0,
	.gyro_cal_y = 171.0,
	.gyro_cal_z = 199.0,
	.accel_cal_x = 227.0,
	.accel_cal_y = 255.0,
	.accel_cal_z = 283.0,
	};
	mavlink_msg_sensor_offsets_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_sensor_offsets_decode(&msg, &packet2);
	mavlink_msg_sensor_offsets_pack(system_id, component_id, &msg , packet1.mag_ofs_x , packet1.mag_ofs_y , packet1.mag_ofs_z , packet1.mag_declination , packet1.raw_press , packet1.raw_temp , packet1.gyro_cal_x , packet1.gyro_cal_y , packet1.gyro_cal_z , packet1.accel_cal_x , packet1.accel_cal_y , packet1.accel_cal_z );
	mavlink_msg_sensor_offsets_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mag_ofs_x , packet1.mag_ofs_y , packet1.mag_ofs_z , packet1.mag_declination , packet1.raw_press , packet1.raw_temp , packet1.gyro_cal_x , packet1.gyro_cal_y , packet1.gyro_cal_z , packet1.accel_cal_x , packet1.accel_cal_y , packet1.accel_cal_z );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_sensor_offsets_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.mag_ofs_x , packet1.mag_ofs_y , packet1.mag_ofs_z , packet1.mag_declination , packet1.raw_press , packet1.raw_temp , packet1.gyro_cal_x , packet1.gyro_cal_y , packet1.gyro_cal_z , packet1.accel_cal_x , packet1.accel_cal_y , packet1.accel_cal_z );
	mavlink_msg_sensor_offsets_send(MAVLINK_COMM_2 , packet1.mag_ofs_x , packet1.mag_ofs_y , packet1.mag_ofs_z , packet1.mag_declination , packet1.raw_press , packet1.raw_temp , packet1.gyro_cal_x , packet1.gyro_cal_y , packet1.gyro_cal_z , packet1.accel_cal_x , packet1.accel_cal_y , packet1.accel_cal_z );
}

static void mavlink_test_set_mag_offsets(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_set_mag_offsets_t packet2, packet1 = {
		.target_system = 5,
	.target_component = 72,
	.mag_ofs_x = 17339,
	.mag_ofs_y = 17443,
	.mag_ofs_z = 17547,
	};
	mavlink_msg_set_mag_offsets_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_set_mag_offsets_decode(&msg, &packet2);
	mavlink_msg_set_mag_offsets_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.mag_ofs_x , packet1.mag_ofs_y , packet1.mag_ofs_z );
	mavlink_msg_set_mag_offsets_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.mag_ofs_x , packet1.mag_ofs_y , packet1.mag_ofs_z );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_set_mag_offsets_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.mag_ofs_x , packet1.mag_ofs_y , packet1.mag_ofs_z );
	mavlink_msg_set_mag_offsets_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.mag_ofs_x , packet1.mag_ofs_y , packet1.mag_ofs_z );
}

static void mavlink_test_all(uint8_t system_id, uint8_t component_id)
{
	mavlink_test_sensor_offsets(system_id, component_id);
	mavlink_test_set_mag_offsets(system_id, component_id);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // ARDUPILOTMEGA_TESTSUITE_H

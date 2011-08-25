/** @file
 *	@brief MAVLink comm protocol testsuite generated from ardupilotmega.xml
 *	@see http://qgroundcontrol.org/mavlink/
 *	Generated on Fri Aug 26 09:46:51 2011
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
		.mag_ofs_x = 19107,
	.mag_ofs_y = 19211,
	.mag_ofs_z = 19315,
	.mag_declination = 17.0,
	.raw_press = 963497672,
	.raw_temp = 963497880,
	.gyro_cal_x = 101.0,
	.gyro_cal_y = 129.0,
	.gyro_cal_z = 157.0,
	.accel_cal_x = 185.0,
	.accel_cal_y = 213.0,
	.accel_cal_z = 241.0,
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
		.target_system = 151,
	.target_component = 218,
	.mag_ofs_x = 17235,
	.mag_ofs_y = 17339,
	.mag_ofs_z = 17443,
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

/** @file
 *	@brief MAVLink comm protocol testsuite generated from common.xml
 *	@see http://qgroundcontrol.org/mavlink/
 *	Generated on Fri Aug 26 09:46:52 2011
 */
#ifndef COMMON_TESTSUITE_H
#define COMMON_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif


static void mavlink_test_heartbeat(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_heartbeat_t packet2, packet1 = {
		.type = 5,
	.autopilot = 72,
	.system_mode = 139,
	.flight_mode = 206,
	.system_status = 17,
	.safety_status = 84,
	.link_status = 151,
	};
	mavlink_msg_heartbeat_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_heartbeat_decode(&msg, &packet2);
	mavlink_msg_heartbeat_pack(system_id, component_id, &msg , packet1.type , packet1.autopilot , packet1.system_mode , packet1.flight_mode , packet1.system_status , packet1.safety_status , packet1.link_status );
	mavlink_msg_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.autopilot , packet1.system_mode , packet1.flight_mode , packet1.system_status , packet1.safety_status , packet1.link_status );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_heartbeat_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.type , packet1.autopilot , packet1.system_mode , packet1.flight_mode , packet1.system_status , packet1.safety_status , packet1.link_status );
	mavlink_msg_heartbeat_send(MAVLINK_COMM_2 , packet1.type , packet1.autopilot , packet1.system_mode , packet1.flight_mode , packet1.system_status , packet1.safety_status , packet1.link_status );
}

static void mavlink_test_sys_status(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_sys_status_t packet2, packet1 = {
		.onboard_control_sensors_present = 17235,
	.onboard_control_sensors_enabled = 17339,
	.onboard_control_sensors_health = 17443,
	.load = 17547,
	.voltage_battery = 17651,
	.current_battery = 17755,
	.watt = 17859,
	.battery_percent = 199,
	.errors_uart = 17963,
	.errors_i2c = 18067,
	.errors_spi = 18171,
	.errors_can = 18275,
	};
	mavlink_msg_sys_status_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_sys_status_decode(&msg, &packet2);
	mavlink_msg_sys_status_pack(system_id, component_id, &msg , packet1.onboard_control_sensors_present , packet1.onboard_control_sensors_enabled , packet1.onboard_control_sensors_health , packet1.load , packet1.voltage_battery , packet1.current_battery , packet1.watt , packet1.battery_percent , packet1.errors_uart , packet1.errors_i2c , packet1.errors_spi , packet1.errors_can );
	mavlink_msg_sys_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.onboard_control_sensors_present , packet1.onboard_control_sensors_enabled , packet1.onboard_control_sensors_health , packet1.load , packet1.voltage_battery , packet1.current_battery , packet1.watt , packet1.battery_percent , packet1.errors_uart , packet1.errors_i2c , packet1.errors_spi , packet1.errors_can );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_sys_status_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.onboard_control_sensors_present , packet1.onboard_control_sensors_enabled , packet1.onboard_control_sensors_health , packet1.load , packet1.voltage_battery , packet1.current_battery , packet1.watt , packet1.battery_percent , packet1.errors_uart , packet1.errors_i2c , packet1.errors_spi , packet1.errors_can );
	mavlink_msg_sys_status_send(MAVLINK_COMM_2 , packet1.onboard_control_sensors_present , packet1.onboard_control_sensors_enabled , packet1.onboard_control_sensors_health , packet1.load , packet1.voltage_battery , packet1.current_battery , packet1.watt , packet1.battery_percent , packet1.errors_uart , packet1.errors_i2c , packet1.errors_spi , packet1.errors_can );
}

static void mavlink_test_system_time(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_system_time_t packet2, packet1 = {
		.time_usec = 9223372036854775807LL,
	.time_boot_ms = 963497880,
	};
	mavlink_msg_system_time_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_system_time_decode(&msg, &packet2);
	mavlink_msg_system_time_pack(system_id, component_id, &msg , packet1.time_usec , packet1.time_boot_ms );
	mavlink_msg_system_time_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.time_boot_ms );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_system_time_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.time_usec , packet1.time_boot_ms );
	mavlink_msg_system_time_send(MAVLINK_COMM_2 , packet1.time_usec , packet1.time_boot_ms );
}

static void mavlink_test_system_time_utc(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_system_time_utc_t packet2, packet1 = {
		.utc_date = 963497464,
	.utc_time = 963497672,
	};
	mavlink_msg_system_time_utc_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_system_time_utc_decode(&msg, &packet2);
	mavlink_msg_system_time_utc_pack(system_id, component_id, &msg , packet1.utc_date , packet1.utc_time );
	mavlink_msg_system_time_utc_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.utc_date , packet1.utc_time );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_system_time_utc_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.utc_date , packet1.utc_time );
	mavlink_msg_system_time_utc_send(MAVLINK_COMM_2 , packet1.utc_date , packet1.utc_time );
}

static void mavlink_test_ping(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_ping_t packet2, packet1 = {
		.seq = 963497880,
	.target_system = 41,
	.target_component = 108,
	.time = 9223372036854775807LL,
	};
	mavlink_msg_ping_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ping_decode(&msg, &packet2);
	mavlink_msg_ping_pack(system_id, component_id, &msg , packet1.seq , packet1.target_system , packet1.target_component , packet1.time );
	mavlink_msg_ping_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.seq , packet1.target_system , packet1.target_component , packet1.time );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ping_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.seq , packet1.target_system , packet1.target_component , packet1.time );
	mavlink_msg_ping_send(MAVLINK_COMM_2 , packet1.seq , packet1.target_system , packet1.target_component , packet1.time );
}

static void mavlink_test_change_operator_control(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_change_operator_control_t packet2, packet1 = {
		.target_system = 5,
	.control_request = 72,
	.version = 139,
	.passkey = "AQGWMCSIYOEUKAQGWMCSIYOEU",
	};
	mavlink_msg_change_operator_control_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_change_operator_control_decode(&msg, &packet2);
	mavlink_msg_change_operator_control_pack(system_id, component_id, &msg , packet1.target_system , packet1.control_request , packet1.version , packet1.passkey );
	mavlink_msg_change_operator_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.control_request , packet1.version , packet1.passkey );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_change_operator_control_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.control_request , packet1.version , packet1.passkey );
	mavlink_msg_change_operator_control_send(MAVLINK_COMM_2 , packet1.target_system , packet1.control_request , packet1.version , packet1.passkey );
}

static void mavlink_test_change_operator_control_ack(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_change_operator_control_ack_t packet2, packet1 = {
		.gcs_system_id = 5,
	.control_request = 72,
	.ack = 139,
	};
	mavlink_msg_change_operator_control_ack_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_change_operator_control_ack_decode(&msg, &packet2);
	mavlink_msg_change_operator_control_ack_pack(system_id, component_id, &msg , packet1.gcs_system_id , packet1.control_request , packet1.ack );
	mavlink_msg_change_operator_control_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.gcs_system_id , packet1.control_request , packet1.ack );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_change_operator_control_ack_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.gcs_system_id , packet1.control_request , packet1.ack );
	mavlink_msg_change_operator_control_ack_send(MAVLINK_COMM_2 , packet1.gcs_system_id , packet1.control_request , packet1.ack );
}

static void mavlink_test_auth_key(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_auth_key_t packet2, packet1 = {
		.key = "ARIZQHYPGXOFWNEVMDULCTKBSJARIZQH",
	};
	mavlink_msg_auth_key_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_auth_key_decode(&msg, &packet2);
	mavlink_msg_auth_key_pack(system_id, component_id, &msg , packet1.key );
	mavlink_msg_auth_key_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.key );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_auth_key_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.key );
	mavlink_msg_auth_key_send(MAVLINK_COMM_2 , packet1.key );
}

static void mavlink_test_set_mode(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_set_mode_t packet2, packet1 = {
		.target = 5,
	.mode = 72,
	};
	mavlink_msg_set_mode_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_set_mode_decode(&msg, &packet2);
	mavlink_msg_set_mode_pack(system_id, component_id, &msg , packet1.target , packet1.mode );
	mavlink_msg_set_mode_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target , packet1.mode );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_set_mode_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target , packet1.mode );
	mavlink_msg_set_mode_send(MAVLINK_COMM_2 , packet1.target , packet1.mode );
}

static void mavlink_test_set_flight_mode(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_set_flight_mode_t packet2, packet1 = {
		.target = 5,
	.flight_mode = 72,
	};
	mavlink_msg_set_flight_mode_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_set_flight_mode_decode(&msg, &packet2);
	mavlink_msg_set_flight_mode_pack(system_id, component_id, &msg , packet1.target , packet1.flight_mode );
	mavlink_msg_set_flight_mode_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target , packet1.flight_mode );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_set_flight_mode_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target , packet1.flight_mode );
	mavlink_msg_set_flight_mode_send(MAVLINK_COMM_2 , packet1.target , packet1.flight_mode );
}

static void mavlink_test_set_safety_mode(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_set_safety_mode_t packet2, packet1 = {
		.target = 5,
	.safety_mode = 72,
	};
	mavlink_msg_set_safety_mode_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_set_safety_mode_decode(&msg, &packet2);
	mavlink_msg_set_safety_mode_pack(system_id, component_id, &msg , packet1.target , packet1.safety_mode );
	mavlink_msg_set_safety_mode_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target , packet1.safety_mode );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_set_safety_mode_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target , packet1.safety_mode );
	mavlink_msg_set_safety_mode_send(MAVLINK_COMM_2 , packet1.target , packet1.safety_mode );
}

static void mavlink_test_param_request_read(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_param_request_read_t packet2, packet1 = {
		.target_system = 139,
	.target_component = 206,
	.param_id = "AHOVCJQXELSZGNUB",
	.param_index = 17235,
	};
	mavlink_msg_param_request_read_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_param_request_read_decode(&msg, &packet2);
	mavlink_msg_param_request_read_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.param_id , packet1.param_index );
	mavlink_msg_param_request_read_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.param_id , packet1.param_index );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_param_request_read_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.param_id , packet1.param_index );
	mavlink_msg_param_request_read_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.param_id , packet1.param_index );
}

static void mavlink_test_param_request_list(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_param_request_list_t packet2, packet1 = {
		.target_system = 5,
	.target_component = 72,
	};
	mavlink_msg_param_request_list_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_param_request_list_decode(&msg, &packet2);
	mavlink_msg_param_request_list_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component );
	mavlink_msg_param_request_list_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_param_request_list_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component );
	mavlink_msg_param_request_list_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component );
}

static void mavlink_test_param_value(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_param_value_t packet2, packet1 = {
		.param_id = "AXUROLIFCZWTQNKH",
	.param_value = 17.0,
	.param_type = 77,
	.param_count = 17443,
	.param_index = 17547,
	};
	mavlink_msg_param_value_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_param_value_decode(&msg, &packet2);
	mavlink_msg_param_value_pack(system_id, component_id, &msg , packet1.param_id , packet1.param_value , packet1.param_type , packet1.param_count , packet1.param_index );
	mavlink_msg_param_value_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.param_id , packet1.param_value , packet1.param_type , packet1.param_count , packet1.param_index );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_param_value_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.param_id , packet1.param_value , packet1.param_type , packet1.param_count , packet1.param_index );
	mavlink_msg_param_value_send(MAVLINK_COMM_2 , packet1.param_id , packet1.param_value , packet1.param_type , packet1.param_count , packet1.param_index );
}

static void mavlink_test_param_set(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_param_set_t packet2, packet1 = {
		.target_system = 17,
	.target_component = 84,
	.param_id = "APETIXMBQFUJYNCR",
	.param_value = 17.0,
	.param_type = 199,
	};
	mavlink_msg_param_set_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_param_set_decode(&msg, &packet2);
	mavlink_msg_param_set_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.param_id , packet1.param_value , packet1.param_type );
	mavlink_msg_param_set_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.param_id , packet1.param_value , packet1.param_type );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_param_set_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.param_id , packet1.param_value , packet1.param_type );
	mavlink_msg_param_set_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.param_id , packet1.param_value , packet1.param_type );
}

static void mavlink_test_gps_raw_int(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_gps_raw_int_t packet2, packet1 = {
		.usec = 9223372036854775807LL,
	.fix_type = 89,
	.lat = 963497880,
	.lon = 963498088,
	.alt = 963498296,
	.eph = 18275,
	.epv = 18379,
	.vel = 18483,
	.hdg = 18587,
	.satellites_visible = 156,
	};
	mavlink_msg_gps_raw_int_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_gps_raw_int_decode(&msg, &packet2);
	mavlink_msg_gps_raw_int_pack(system_id, component_id, &msg , packet1.usec , packet1.fix_type , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.vel , packet1.hdg , packet1.satellites_visible );
	mavlink_msg_gps_raw_int_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.usec , packet1.fix_type , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.vel , packet1.hdg , packet1.satellites_visible );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_gps_raw_int_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.usec , packet1.fix_type , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.vel , packet1.hdg , packet1.satellites_visible );
	mavlink_msg_gps_raw_int_send(MAVLINK_COMM_2 , packet1.usec , packet1.fix_type , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.vel , packet1.hdg , packet1.satellites_visible );
}

static void mavlink_test_scaled_imu(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_scaled_imu_t packet2, packet1 = {
		.usec = 9223372036854775807LL,
	.xacc = 17651,
	.yacc = 17755,
	.zacc = 17859,
	.xgyro = 17963,
	.ygyro = 18067,
	.zgyro = 18171,
	.xmag = 18275,
	.ymag = 18379,
	.zmag = 18483,
	};
	mavlink_msg_scaled_imu_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_scaled_imu_decode(&msg, &packet2);
	mavlink_msg_scaled_imu_pack(system_id, component_id, &msg , packet1.usec , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.xmag , packet1.ymag , packet1.zmag );
	mavlink_msg_scaled_imu_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.usec , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.xmag , packet1.ymag , packet1.zmag );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_scaled_imu_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.usec , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.xmag , packet1.ymag , packet1.zmag );
	mavlink_msg_scaled_imu_send(MAVLINK_COMM_2 , packet1.usec , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.xmag , packet1.ymag , packet1.zmag );
}

static void mavlink_test_gps_status(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_gps_status_t packet2, packet1 = {
		.satellites_visible = 5,
	.satellite_prn = "72",
	.satellite_used = "132",
	.satellite_elevation = "192",
	.satellite_azimuth = "252",
	.satellite_snr = "56",
	};
	mavlink_msg_gps_status_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_gps_status_decode(&msg, &packet2);
	mavlink_msg_gps_status_pack(system_id, component_id, &msg , packet1.satellites_visible , packet1.satellite_prn , packet1.satellite_used , packet1.satellite_elevation , packet1.satellite_azimuth , packet1.satellite_snr );
	mavlink_msg_gps_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.satellites_visible , packet1.satellite_prn , packet1.satellite_used , packet1.satellite_elevation , packet1.satellite_azimuth , packet1.satellite_snr );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_gps_status_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.satellites_visible , packet1.satellite_prn , packet1.satellite_used , packet1.satellite_elevation , packet1.satellite_azimuth , packet1.satellite_snr );
	mavlink_msg_gps_status_send(MAVLINK_COMM_2 , packet1.satellites_visible , packet1.satellite_prn , packet1.satellite_used , packet1.satellite_elevation , packet1.satellite_azimuth , packet1.satellite_snr );
}

static void mavlink_test_raw_imu(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_raw_imu_t packet2, packet1 = {
		.usec = 9223372036854775807LL,
	.xacc = 17651,
	.yacc = 17755,
	.zacc = 17859,
	.xgyro = 17963,
	.ygyro = 18067,
	.zgyro = 18171,
	.xmag = 18275,
	.ymag = 18379,
	.zmag = 18483,
	};
	mavlink_msg_raw_imu_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_raw_imu_decode(&msg, &packet2);
	mavlink_msg_raw_imu_pack(system_id, component_id, &msg , packet1.usec , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.xmag , packet1.ymag , packet1.zmag );
	mavlink_msg_raw_imu_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.usec , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.xmag , packet1.ymag , packet1.zmag );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_raw_imu_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.usec , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.xmag , packet1.ymag , packet1.zmag );
	mavlink_msg_raw_imu_send(MAVLINK_COMM_2 , packet1.usec , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.xmag , packet1.ymag , packet1.zmag );
}

static void mavlink_test_raw_pressure(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_raw_pressure_t packet2, packet1 = {
		.usec = 9223372036854775807LL,
	.press_abs = 17651,
	.press_diff1 = 17755,
	.press_diff2 = 17859,
	.temperature = 17963,
	};
	mavlink_msg_raw_pressure_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_raw_pressure_decode(&msg, &packet2);
	mavlink_msg_raw_pressure_pack(system_id, component_id, &msg , packet1.usec , packet1.press_abs , packet1.press_diff1 , packet1.press_diff2 , packet1.temperature );
	mavlink_msg_raw_pressure_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.usec , packet1.press_abs , packet1.press_diff1 , packet1.press_diff2 , packet1.temperature );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_raw_pressure_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.usec , packet1.press_abs , packet1.press_diff1 , packet1.press_diff2 , packet1.temperature );
	mavlink_msg_raw_pressure_send(MAVLINK_COMM_2 , packet1.usec , packet1.press_abs , packet1.press_diff1 , packet1.press_diff2 , packet1.temperature );
}

static void mavlink_test_scaled_pressure(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_scaled_pressure_t packet2, packet1 = {
		.usec = 9223372036854775807LL,
	.press_abs = 73.0,
	.press_diff = 101.0,
	.temperature = 18067,
	};
	mavlink_msg_scaled_pressure_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_scaled_pressure_decode(&msg, &packet2);
	mavlink_msg_scaled_pressure_pack(system_id, component_id, &msg , packet1.usec , packet1.press_abs , packet1.press_diff , packet1.temperature );
	mavlink_msg_scaled_pressure_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.usec , packet1.press_abs , packet1.press_diff , packet1.temperature );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_scaled_pressure_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.usec , packet1.press_abs , packet1.press_diff , packet1.temperature );
	mavlink_msg_scaled_pressure_send(MAVLINK_COMM_2 , packet1.usec , packet1.press_abs , packet1.press_diff , packet1.temperature );
}

static void mavlink_test_attitude(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_attitude_t packet2, packet1 = {
		.usec = 9223372036854775807LL,
	.roll = 73.0,
	.pitch = 101.0,
	.yaw = 129.0,
	.rollspeed = 157.0,
	.pitchspeed = 185.0,
	.yawspeed = 213.0,
	};
	mavlink_msg_attitude_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_attitude_decode(&msg, &packet2);
	mavlink_msg_attitude_pack(system_id, component_id, &msg , packet1.usec , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollspeed , packet1.pitchspeed , packet1.yawspeed );
	mavlink_msg_attitude_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.usec , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollspeed , packet1.pitchspeed , packet1.yawspeed );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_attitude_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.usec , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollspeed , packet1.pitchspeed , packet1.yawspeed );
	mavlink_msg_attitude_send(MAVLINK_COMM_2 , packet1.usec , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollspeed , packet1.pitchspeed , packet1.yawspeed );
}

static void mavlink_test_local_position(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_local_position_t packet2, packet1 = {
		.usec = 9223372036854775807LL,
	.x = 73.0,
	.y = 101.0,
	.z = 129.0,
	.vx = 157.0,
	.vy = 185.0,
	.vz = 213.0,
	};
	mavlink_msg_local_position_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_local_position_decode(&msg, &packet2);
	mavlink_msg_local_position_pack(system_id, component_id, &msg , packet1.usec , packet1.x , packet1.y , packet1.z , packet1.vx , packet1.vy , packet1.vz );
	mavlink_msg_local_position_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.usec , packet1.x , packet1.y , packet1.z , packet1.vx , packet1.vy , packet1.vz );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_local_position_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.usec , packet1.x , packet1.y , packet1.z , packet1.vx , packet1.vy , packet1.vz );
	mavlink_msg_local_position_send(MAVLINK_COMM_2 , packet1.usec , packet1.x , packet1.y , packet1.z , packet1.vx , packet1.vy , packet1.vz );
}

static void mavlink_test_global_position(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_global_position_t packet2, packet1 = {
		.usec = 9223372036854775807LL,
	.lat = 73.0,
	.lon = 101.0,
	.alt = 129.0,
	.vx = 157.0,
	.vy = 185.0,
	.vz = 213.0,
	};
	mavlink_msg_global_position_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_global_position_decode(&msg, &packet2);
	mavlink_msg_global_position_pack(system_id, component_id, &msg , packet1.usec , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz );
	mavlink_msg_global_position_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.usec , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_global_position_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.usec , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz );
	mavlink_msg_global_position_send(MAVLINK_COMM_2 , packet1.usec , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz );
}

static void mavlink_test_gps_raw(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_gps_raw_t packet2, packet1 = {
		.usec = 9223372036854775807LL,
	.fix_type = 113,
	.lat = 73.0,
	.lon = 101.0,
	.alt = 129.0,
	.eph = 157.0,
	.epv = 185.0,
	.v = 213.0,
	.hdg = 241.0,
	.satellites_visible = 180,
	};
	mavlink_msg_gps_raw_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_gps_raw_decode(&msg, &packet2);
	mavlink_msg_gps_raw_pack(system_id, component_id, &msg , packet1.usec , packet1.fix_type , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.v , packet1.hdg , packet1.satellites_visible );
	mavlink_msg_gps_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.usec , packet1.fix_type , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.v , packet1.hdg , packet1.satellites_visible );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_gps_raw_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.usec , packet1.fix_type , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.v , packet1.hdg , packet1.satellites_visible );
	mavlink_msg_gps_raw_send(MAVLINK_COMM_2 , packet1.usec , packet1.fix_type , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.v , packet1.hdg , packet1.satellites_visible );
}

static void mavlink_test_rc_channels_raw(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_rc_channels_raw_t packet2, packet1 = {
		.chan1_raw = 17235,
	.chan2_raw = 17339,
	.chan3_raw = 17443,
	.chan4_raw = 17547,
	.chan5_raw = 17651,
	.chan6_raw = 17755,
	.chan7_raw = 17859,
	.chan8_raw = 17963,
	.rssi = 53,
	};
	mavlink_msg_rc_channels_raw_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_rc_channels_raw_decode(&msg, &packet2);
	mavlink_msg_rc_channels_raw_pack(system_id, component_id, &msg , packet1.chan1_raw , packet1.chan2_raw , packet1.chan3_raw , packet1.chan4_raw , packet1.chan5_raw , packet1.chan6_raw , packet1.chan7_raw , packet1.chan8_raw , packet1.rssi );
	mavlink_msg_rc_channels_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.chan1_raw , packet1.chan2_raw , packet1.chan3_raw , packet1.chan4_raw , packet1.chan5_raw , packet1.chan6_raw , packet1.chan7_raw , packet1.chan8_raw , packet1.rssi );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_rc_channels_raw_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.chan1_raw , packet1.chan2_raw , packet1.chan3_raw , packet1.chan4_raw , packet1.chan5_raw , packet1.chan6_raw , packet1.chan7_raw , packet1.chan8_raw , packet1.rssi );
	mavlink_msg_rc_channels_raw_send(MAVLINK_COMM_2 , packet1.chan1_raw , packet1.chan2_raw , packet1.chan3_raw , packet1.chan4_raw , packet1.chan5_raw , packet1.chan6_raw , packet1.chan7_raw , packet1.chan8_raw , packet1.rssi );
}

static void mavlink_test_rc_channels_scaled(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_rc_channels_scaled_t packet2, packet1 = {
		.chan1_scaled = 17235,
	.chan2_scaled = 17339,
	.chan3_scaled = 17443,
	.chan4_scaled = 17547,
	.chan5_scaled = 17651,
	.chan6_scaled = 17755,
	.chan7_scaled = 17859,
	.chan8_scaled = 17963,
	.rssi = 53,
	};
	mavlink_msg_rc_channels_scaled_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_rc_channels_scaled_decode(&msg, &packet2);
	mavlink_msg_rc_channels_scaled_pack(system_id, component_id, &msg , packet1.chan1_scaled , packet1.chan2_scaled , packet1.chan3_scaled , packet1.chan4_scaled , packet1.chan5_scaled , packet1.chan6_scaled , packet1.chan7_scaled , packet1.chan8_scaled , packet1.rssi );
	mavlink_msg_rc_channels_scaled_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.chan1_scaled , packet1.chan2_scaled , packet1.chan3_scaled , packet1.chan4_scaled , packet1.chan5_scaled , packet1.chan6_scaled , packet1.chan7_scaled , packet1.chan8_scaled , packet1.rssi );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_rc_channels_scaled_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.chan1_scaled , packet1.chan2_scaled , packet1.chan3_scaled , packet1.chan4_scaled , packet1.chan5_scaled , packet1.chan6_scaled , packet1.chan7_scaled , packet1.chan8_scaled , packet1.rssi );
	mavlink_msg_rc_channels_scaled_send(MAVLINK_COMM_2 , packet1.chan1_scaled , packet1.chan2_scaled , packet1.chan3_scaled , packet1.chan4_scaled , packet1.chan5_scaled , packet1.chan6_scaled , packet1.chan7_scaled , packet1.chan8_scaled , packet1.rssi );
}

static void mavlink_test_servo_output_raw(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_servo_output_raw_t packet2, packet1 = {
		.servo1_raw = 17235,
	.servo2_raw = 17339,
	.servo3_raw = 17443,
	.servo4_raw = 17547,
	.servo5_raw = 17651,
	.servo6_raw = 17755,
	.servo7_raw = 17859,
	.servo8_raw = 17963,
	};
	mavlink_msg_servo_output_raw_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_servo_output_raw_decode(&msg, &packet2);
	mavlink_msg_servo_output_raw_pack(system_id, component_id, &msg , packet1.servo1_raw , packet1.servo2_raw , packet1.servo3_raw , packet1.servo4_raw , packet1.servo5_raw , packet1.servo6_raw , packet1.servo7_raw , packet1.servo8_raw );
	mavlink_msg_servo_output_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.servo1_raw , packet1.servo2_raw , packet1.servo3_raw , packet1.servo4_raw , packet1.servo5_raw , packet1.servo6_raw , packet1.servo7_raw , packet1.servo8_raw );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_servo_output_raw_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.servo1_raw , packet1.servo2_raw , packet1.servo3_raw , packet1.servo4_raw , packet1.servo5_raw , packet1.servo6_raw , packet1.servo7_raw , packet1.servo8_raw );
	mavlink_msg_servo_output_raw_send(MAVLINK_COMM_2 , packet1.servo1_raw , packet1.servo2_raw , packet1.servo3_raw , packet1.servo4_raw , packet1.servo5_raw , packet1.servo6_raw , packet1.servo7_raw , packet1.servo8_raw );
}

static void mavlink_test_waypoint(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_waypoint_t packet2, packet1 = {
		.target_system = 223,
	.target_component = 34,
	.seq = 18691,
	.frame = 101,
	.command = 168,
	.current = 235,
	.autocontinue = 46,
	.param1 = 17.0,
	.param2 = 45.0,
	.param3 = 73.0,
	.param4 = 101.0,
	.x = 129.0,
	.y = 157.0,
	.z = 185.0,
	};
	mavlink_msg_waypoint_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_waypoint_decode(&msg, &packet2);
	mavlink_msg_waypoint_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.seq , packet1.frame , packet1.command , packet1.current , packet1.autocontinue , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.x , packet1.y , packet1.z );
	mavlink_msg_waypoint_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.seq , packet1.frame , packet1.command , packet1.current , packet1.autocontinue , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.x , packet1.y , packet1.z );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_waypoint_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.seq , packet1.frame , packet1.command , packet1.current , packet1.autocontinue , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.x , packet1.y , packet1.z );
	mavlink_msg_waypoint_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.seq , packet1.frame , packet1.command , packet1.current , packet1.autocontinue , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.x , packet1.y , packet1.z );
}

static void mavlink_test_waypoint_request(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_waypoint_request_t packet2, packet1 = {
		.target_system = 139,
	.target_component = 206,
	.seq = 17235,
	};
	mavlink_msg_waypoint_request_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_waypoint_request_decode(&msg, &packet2);
	mavlink_msg_waypoint_request_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.seq );
	mavlink_msg_waypoint_request_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.seq );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_waypoint_request_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.seq );
	mavlink_msg_waypoint_request_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.seq );
}

static void mavlink_test_waypoint_set_current(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_waypoint_set_current_t packet2, packet1 = {
		.target_system = 139,
	.target_component = 206,
	.seq = 17235,
	};
	mavlink_msg_waypoint_set_current_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_waypoint_set_current_decode(&msg, &packet2);
	mavlink_msg_waypoint_set_current_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.seq );
	mavlink_msg_waypoint_set_current_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.seq );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_waypoint_set_current_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.seq );
	mavlink_msg_waypoint_set_current_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.seq );
}

static void mavlink_test_waypoint_current(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_waypoint_current_t packet2, packet1 = {
		.seq = 17235,
	};
	mavlink_msg_waypoint_current_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_waypoint_current_decode(&msg, &packet2);
	mavlink_msg_waypoint_current_pack(system_id, component_id, &msg , packet1.seq );
	mavlink_msg_waypoint_current_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.seq );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_waypoint_current_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.seq );
	mavlink_msg_waypoint_current_send(MAVLINK_COMM_2 , packet1.seq );
}

static void mavlink_test_waypoint_request_list(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_waypoint_request_list_t packet2, packet1 = {
		.target_system = 5,
	.target_component = 72,
	};
	mavlink_msg_waypoint_request_list_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_waypoint_request_list_decode(&msg, &packet2);
	mavlink_msg_waypoint_request_list_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component );
	mavlink_msg_waypoint_request_list_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_waypoint_request_list_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component );
	mavlink_msg_waypoint_request_list_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component );
}

static void mavlink_test_waypoint_count(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_waypoint_count_t packet2, packet1 = {
		.target_system = 139,
	.target_component = 206,
	.count = 17235,
	};
	mavlink_msg_waypoint_count_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_waypoint_count_decode(&msg, &packet2);
	mavlink_msg_waypoint_count_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.count );
	mavlink_msg_waypoint_count_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.count );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_waypoint_count_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.count );
	mavlink_msg_waypoint_count_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.count );
}

static void mavlink_test_waypoint_clear_all(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_waypoint_clear_all_t packet2, packet1 = {
		.target_system = 5,
	.target_component = 72,
	};
	mavlink_msg_waypoint_clear_all_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_waypoint_clear_all_decode(&msg, &packet2);
	mavlink_msg_waypoint_clear_all_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component );
	mavlink_msg_waypoint_clear_all_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_waypoint_clear_all_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component );
	mavlink_msg_waypoint_clear_all_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component );
}

static void mavlink_test_waypoint_reached(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_waypoint_reached_t packet2, packet1 = {
		.seq = 17235,
	};
	mavlink_msg_waypoint_reached_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_waypoint_reached_decode(&msg, &packet2);
	mavlink_msg_waypoint_reached_pack(system_id, component_id, &msg , packet1.seq );
	mavlink_msg_waypoint_reached_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.seq );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_waypoint_reached_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.seq );
	mavlink_msg_waypoint_reached_send(MAVLINK_COMM_2 , packet1.seq );
}

static void mavlink_test_waypoint_ack(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_waypoint_ack_t packet2, packet1 = {
		.target_system = 5,
	.target_component = 72,
	.type = 139,
	};
	mavlink_msg_waypoint_ack_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_waypoint_ack_decode(&msg, &packet2);
	mavlink_msg_waypoint_ack_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.type );
	mavlink_msg_waypoint_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.type );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_waypoint_ack_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.type );
	mavlink_msg_waypoint_ack_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.type );
}

static void mavlink_test_gps_set_global_origin(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_gps_set_global_origin_t packet2, packet1 = {
		.target_system = 41,
	.target_component = 108,
	.latitude = 963497464,
	.longitude = 963497672,
	.altitude = 963497880,
	};
	mavlink_msg_gps_set_global_origin_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_gps_set_global_origin_decode(&msg, &packet2);
	mavlink_msg_gps_set_global_origin_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.latitude , packet1.longitude , packet1.altitude );
	mavlink_msg_gps_set_global_origin_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.latitude , packet1.longitude , packet1.altitude );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_gps_set_global_origin_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.latitude , packet1.longitude , packet1.altitude );
	mavlink_msg_gps_set_global_origin_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.latitude , packet1.longitude , packet1.altitude );
}

static void mavlink_test_gps_local_origin_set(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_gps_local_origin_set_t packet2, packet1 = {
		.latitude = 963497464,
	.longitude = 963497672,
	.altitude = 963497880,
	};
	mavlink_msg_gps_local_origin_set_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_gps_local_origin_set_decode(&msg, &packet2);
	mavlink_msg_gps_local_origin_set_pack(system_id, component_id, &msg , packet1.latitude , packet1.longitude , packet1.altitude );
	mavlink_msg_gps_local_origin_set_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.latitude , packet1.longitude , packet1.altitude );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_gps_local_origin_set_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.latitude , packet1.longitude , packet1.altitude );
	mavlink_msg_gps_local_origin_set_send(MAVLINK_COMM_2 , packet1.latitude , packet1.longitude , packet1.altitude );
}

static void mavlink_test_local_position_setpoint_set(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_local_position_setpoint_set_t packet2, packet1 = {
		.target_system = 53,
	.target_component = 120,
	.x = 17.0,
	.y = 45.0,
	.z = 73.0,
	.yaw = 101.0,
	};
	mavlink_msg_local_position_setpoint_set_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_local_position_setpoint_set_decode(&msg, &packet2);
	mavlink_msg_local_position_setpoint_set_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.x , packet1.y , packet1.z , packet1.yaw );
	mavlink_msg_local_position_setpoint_set_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.x , packet1.y , packet1.z , packet1.yaw );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_local_position_setpoint_set_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.x , packet1.y , packet1.z , packet1.yaw );
	mavlink_msg_local_position_setpoint_set_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.x , packet1.y , packet1.z , packet1.yaw );
}

static void mavlink_test_local_position_setpoint(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_local_position_setpoint_t packet2, packet1 = {
		.x = 17.0,
	.y = 45.0,
	.z = 73.0,
	.yaw = 101.0,
	};
	mavlink_msg_local_position_setpoint_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_local_position_setpoint_decode(&msg, &packet2);
	mavlink_msg_local_position_setpoint_pack(system_id, component_id, &msg , packet1.x , packet1.y , packet1.z , packet1.yaw );
	mavlink_msg_local_position_setpoint_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.x , packet1.y , packet1.z , packet1.yaw );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_local_position_setpoint_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.x , packet1.y , packet1.z , packet1.yaw );
	mavlink_msg_local_position_setpoint_send(MAVLINK_COMM_2 , packet1.x , packet1.y , packet1.z , packet1.yaw );
}

static void mavlink_test_global_position_setpoint_int(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_global_position_setpoint_int_t packet2, packet1 = {
		.latitude = 963497464,
	.longitude = 963497672,
	.altitude = 963497880,
	.yaw = 17859,
	};
	mavlink_msg_global_position_setpoint_int_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_global_position_setpoint_int_decode(&msg, &packet2);
	mavlink_msg_global_position_setpoint_int_pack(system_id, component_id, &msg , packet1.latitude , packet1.longitude , packet1.altitude , packet1.yaw );
	mavlink_msg_global_position_setpoint_int_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.latitude , packet1.longitude , packet1.altitude , packet1.yaw );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_global_position_setpoint_int_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.latitude , packet1.longitude , packet1.altitude , packet1.yaw );
	mavlink_msg_global_position_setpoint_int_send(MAVLINK_COMM_2 , packet1.latitude , packet1.longitude , packet1.altitude , packet1.yaw );
}

static void mavlink_test_safety_set_allowed_area(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_safety_set_allowed_area_t packet2, packet1 = {
		.target_system = 77,
	.target_component = 144,
	.frame = 211,
	.p1x = 17.0,
	.p1y = 45.0,
	.p1z = 73.0,
	.p2x = 101.0,
	.p2y = 129.0,
	.p2z = 157.0,
	};
	mavlink_msg_safety_set_allowed_area_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_safety_set_allowed_area_decode(&msg, &packet2);
	mavlink_msg_safety_set_allowed_area_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.frame , packet1.p1x , packet1.p1y , packet1.p1z , packet1.p2x , packet1.p2y , packet1.p2z );
	mavlink_msg_safety_set_allowed_area_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.frame , packet1.p1x , packet1.p1y , packet1.p1z , packet1.p2x , packet1.p2y , packet1.p2z );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_safety_set_allowed_area_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.frame , packet1.p1x , packet1.p1y , packet1.p1z , packet1.p2x , packet1.p2y , packet1.p2z );
	mavlink_msg_safety_set_allowed_area_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.frame , packet1.p1x , packet1.p1y , packet1.p1z , packet1.p2x , packet1.p2y , packet1.p2z );
}

static void mavlink_test_safety_allowed_area(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_safety_allowed_area_t packet2, packet1 = {
		.frame = 77,
	.p1x = 17.0,
	.p1y = 45.0,
	.p1z = 73.0,
	.p2x = 101.0,
	.p2y = 129.0,
	.p2z = 157.0,
	};
	mavlink_msg_safety_allowed_area_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_safety_allowed_area_decode(&msg, &packet2);
	mavlink_msg_safety_allowed_area_pack(system_id, component_id, &msg , packet1.frame , packet1.p1x , packet1.p1y , packet1.p1z , packet1.p2x , packet1.p2y , packet1.p2z );
	mavlink_msg_safety_allowed_area_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.frame , packet1.p1x , packet1.p1y , packet1.p1z , packet1.p2x , packet1.p2y , packet1.p2z );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_safety_allowed_area_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.frame , packet1.p1x , packet1.p1y , packet1.p1z , packet1.p2x , packet1.p2y , packet1.p2z );
	mavlink_msg_safety_allowed_area_send(MAVLINK_COMM_2 , packet1.frame , packet1.p1x , packet1.p1y , packet1.p1z , packet1.p2x , packet1.p2y , packet1.p2z );
}

static void mavlink_test_set_roll_pitch_yaw_thrust(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_set_roll_pitch_yaw_thrust_t packet2, packet1 = {
		.target_system = 53,
	.target_component = 120,
	.roll = 17.0,
	.pitch = 45.0,
	.yaw = 73.0,
	.thrust = 101.0,
	};
	mavlink_msg_set_roll_pitch_yaw_thrust_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_set_roll_pitch_yaw_thrust_decode(&msg, &packet2);
	mavlink_msg_set_roll_pitch_yaw_thrust_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.roll , packet1.pitch , packet1.yaw , packet1.thrust );
	mavlink_msg_set_roll_pitch_yaw_thrust_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.roll , packet1.pitch , packet1.yaw , packet1.thrust );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_set_roll_pitch_yaw_thrust_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.roll , packet1.pitch , packet1.yaw , packet1.thrust );
	mavlink_msg_set_roll_pitch_yaw_thrust_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.roll , packet1.pitch , packet1.yaw , packet1.thrust );
}

static void mavlink_test_set_roll_pitch_yaw_speed_thrust(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_set_roll_pitch_yaw_speed_thrust_t packet2, packet1 = {
		.target_system = 53,
	.target_component = 120,
	.roll_speed = 17.0,
	.pitch_speed = 45.0,
	.yaw_speed = 73.0,
	.thrust = 101.0,
	};
	mavlink_msg_set_roll_pitch_yaw_speed_thrust_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_set_roll_pitch_yaw_speed_thrust_decode(&msg, &packet2);
	mavlink_msg_set_roll_pitch_yaw_speed_thrust_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.roll_speed , packet1.pitch_speed , packet1.yaw_speed , packet1.thrust );
	mavlink_msg_set_roll_pitch_yaw_speed_thrust_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.roll_speed , packet1.pitch_speed , packet1.yaw_speed , packet1.thrust );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_set_roll_pitch_yaw_speed_thrust_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.roll_speed , packet1.pitch_speed , packet1.yaw_speed , packet1.thrust );
	mavlink_msg_set_roll_pitch_yaw_speed_thrust_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.roll_speed , packet1.pitch_speed , packet1.yaw_speed , packet1.thrust );
}

static void mavlink_test_roll_pitch_yaw_thrust_setpoint(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_roll_pitch_yaw_thrust_setpoint_t packet2, packet1 = {
		.time_ms = 963497464,
	.roll = 45.0,
	.pitch = 73.0,
	.yaw = 101.0,
	.thrust = 129.0,
	};
	mavlink_msg_roll_pitch_yaw_thrust_setpoint_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_roll_pitch_yaw_thrust_setpoint_decode(&msg, &packet2);
	mavlink_msg_roll_pitch_yaw_thrust_setpoint_pack(system_id, component_id, &msg , packet1.time_ms , packet1.roll , packet1.pitch , packet1.yaw , packet1.thrust );
	mavlink_msg_roll_pitch_yaw_thrust_setpoint_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_ms , packet1.roll , packet1.pitch , packet1.yaw , packet1.thrust );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_roll_pitch_yaw_thrust_setpoint_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.time_ms , packet1.roll , packet1.pitch , packet1.yaw , packet1.thrust );
	mavlink_msg_roll_pitch_yaw_thrust_setpoint_send(MAVLINK_COMM_2 , packet1.time_ms , packet1.roll , packet1.pitch , packet1.yaw , packet1.thrust );
}

static void mavlink_test_roll_pitch_yaw_speed_thrust_setpoint(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_roll_pitch_yaw_speed_thrust_setpoint_t packet2, packet1 = {
		.time_ms = 963497464,
	.roll_speed = 45.0,
	.pitch_speed = 73.0,
	.yaw_speed = 101.0,
	.thrust = 129.0,
	};
	mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_decode(&msg, &packet2);
	mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_pack(system_id, component_id, &msg , packet1.time_ms , packet1.roll_speed , packet1.pitch_speed , packet1.yaw_speed , packet1.thrust );
	mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_ms , packet1.roll_speed , packet1.pitch_speed , packet1.yaw_speed , packet1.thrust );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.time_ms , packet1.roll_speed , packet1.pitch_speed , packet1.yaw_speed , packet1.thrust );
	mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_send(MAVLINK_COMM_2 , packet1.time_ms , packet1.roll_speed , packet1.pitch_speed , packet1.yaw_speed , packet1.thrust );
}

static void mavlink_test_nav_controller_output(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_nav_controller_output_t packet2, packet1 = {
		.nav_roll = 17.0,
	.nav_pitch = 45.0,
	.nav_bearing = 18275,
	.target_bearing = 18379,
	.wp_dist = 18483,
	.alt_error = 73.0,
	.aspd_error = 101.0,
	.xtrack_error = 129.0,
	};
	mavlink_msg_nav_controller_output_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_nav_controller_output_decode(&msg, &packet2);
	mavlink_msg_nav_controller_output_pack(system_id, component_id, &msg , packet1.nav_roll , packet1.nav_pitch , packet1.nav_bearing , packet1.target_bearing , packet1.wp_dist , packet1.alt_error , packet1.aspd_error , packet1.xtrack_error );
	mavlink_msg_nav_controller_output_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.nav_roll , packet1.nav_pitch , packet1.nav_bearing , packet1.target_bearing , packet1.wp_dist , packet1.alt_error , packet1.aspd_error , packet1.xtrack_error );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_nav_controller_output_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.nav_roll , packet1.nav_pitch , packet1.nav_bearing , packet1.target_bearing , packet1.wp_dist , packet1.alt_error , packet1.aspd_error , packet1.xtrack_error );
	mavlink_msg_nav_controller_output_send(MAVLINK_COMM_2 , packet1.nav_roll , packet1.nav_pitch , packet1.nav_bearing , packet1.target_bearing , packet1.wp_dist , packet1.alt_error , packet1.aspd_error , packet1.xtrack_error );
}

static void mavlink_test_position_target(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_position_target_t packet2, packet1 = {
		.x = 17.0,
	.y = 45.0,
	.z = 73.0,
	.yaw = 101.0,
	};
	mavlink_msg_position_target_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_position_target_decode(&msg, &packet2);
	mavlink_msg_position_target_pack(system_id, component_id, &msg , packet1.x , packet1.y , packet1.z , packet1.yaw );
	mavlink_msg_position_target_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.x , packet1.y , packet1.z , packet1.yaw );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_position_target_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.x , packet1.y , packet1.z , packet1.yaw );
	mavlink_msg_position_target_send(MAVLINK_COMM_2 , packet1.x , packet1.y , packet1.z , packet1.yaw );
}

static void mavlink_test_state_correction(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_state_correction_t packet2, packet1 = {
		.xErr = 17.0,
	.yErr = 45.0,
	.zErr = 73.0,
	.rollErr = 101.0,
	.pitchErr = 129.0,
	.yawErr = 157.0,
	.vxErr = 185.0,
	.vyErr = 213.0,
	.vzErr = 241.0,
	};
	mavlink_msg_state_correction_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_state_correction_decode(&msg, &packet2);
	mavlink_msg_state_correction_pack(system_id, component_id, &msg , packet1.xErr , packet1.yErr , packet1.zErr , packet1.rollErr , packet1.pitchErr , packet1.yawErr , packet1.vxErr , packet1.vyErr , packet1.vzErr );
	mavlink_msg_state_correction_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.xErr , packet1.yErr , packet1.zErr , packet1.rollErr , packet1.pitchErr , packet1.yawErr , packet1.vxErr , packet1.vyErr , packet1.vzErr );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_state_correction_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.xErr , packet1.yErr , packet1.zErr , packet1.rollErr , packet1.pitchErr , packet1.yawErr , packet1.vxErr , packet1.vyErr , packet1.vzErr );
	mavlink_msg_state_correction_send(MAVLINK_COMM_2 , packet1.xErr , packet1.yErr , packet1.zErr , packet1.rollErr , packet1.pitchErr , packet1.yawErr , packet1.vxErr , packet1.vyErr , packet1.vzErr );
}

static void mavlink_test_request_data_stream(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_request_data_stream_t packet2, packet1 = {
		.target_system = 139,
	.target_component = 206,
	.req_stream_id = 17,
	.req_message_rate = 17235,
	.start_stop = 84,
	};
	mavlink_msg_request_data_stream_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_request_data_stream_decode(&msg, &packet2);
	mavlink_msg_request_data_stream_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.req_stream_id , packet1.req_message_rate , packet1.start_stop );
	mavlink_msg_request_data_stream_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.req_stream_id , packet1.req_message_rate , packet1.start_stop );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_request_data_stream_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.req_stream_id , packet1.req_message_rate , packet1.start_stop );
	mavlink_msg_request_data_stream_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.req_stream_id , packet1.req_message_rate , packet1.start_stop );
}

static void mavlink_test_data_stream(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_data_stream_t packet2, packet1 = {
		.stream_id = 139,
	.message_rate = 17235,
	.on_off = 206,
	};
	mavlink_msg_data_stream_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_data_stream_decode(&msg, &packet2);
	mavlink_msg_data_stream_pack(system_id, component_id, &msg , packet1.stream_id , packet1.message_rate , packet1.on_off );
	mavlink_msg_data_stream_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.stream_id , packet1.message_rate , packet1.on_off );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_data_stream_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.stream_id , packet1.message_rate , packet1.on_off );
	mavlink_msg_data_stream_send(MAVLINK_COMM_2 , packet1.stream_id , packet1.message_rate , packet1.on_off );
}

static void mavlink_test_manual_control(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_manual_control_t packet2, packet1 = {
		.target = 53,
	.roll = 17.0,
	.pitch = 45.0,
	.yaw = 73.0,
	.thrust = 101.0,
	.roll_manual = 120,
	.pitch_manual = 187,
	.yaw_manual = 254,
	.thrust_manual = 65,
	};
	mavlink_msg_manual_control_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_manual_control_decode(&msg, &packet2);
	mavlink_msg_manual_control_pack(system_id, component_id, &msg , packet1.target , packet1.roll , packet1.pitch , packet1.yaw , packet1.thrust , packet1.roll_manual , packet1.pitch_manual , packet1.yaw_manual , packet1.thrust_manual );
	mavlink_msg_manual_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target , packet1.roll , packet1.pitch , packet1.yaw , packet1.thrust , packet1.roll_manual , packet1.pitch_manual , packet1.yaw_manual , packet1.thrust_manual );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_manual_control_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target , packet1.roll , packet1.pitch , packet1.yaw , packet1.thrust , packet1.roll_manual , packet1.pitch_manual , packet1.yaw_manual , packet1.thrust_manual );
	mavlink_msg_manual_control_send(MAVLINK_COMM_2 , packet1.target , packet1.roll , packet1.pitch , packet1.yaw , packet1.thrust , packet1.roll_manual , packet1.pitch_manual , packet1.yaw_manual , packet1.thrust_manual );
}

static void mavlink_test_rc_channels_override(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_rc_channels_override_t packet2, packet1 = {
		.target_system = 53,
	.target_component = 120,
	.chan1_raw = 17235,
	.chan2_raw = 17339,
	.chan3_raw = 17443,
	.chan4_raw = 17547,
	.chan5_raw = 17651,
	.chan6_raw = 17755,
	.chan7_raw = 17859,
	.chan8_raw = 17963,
	};
	mavlink_msg_rc_channels_override_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_rc_channels_override_decode(&msg, &packet2);
	mavlink_msg_rc_channels_override_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.chan1_raw , packet1.chan2_raw , packet1.chan3_raw , packet1.chan4_raw , packet1.chan5_raw , packet1.chan6_raw , packet1.chan7_raw , packet1.chan8_raw );
	mavlink_msg_rc_channels_override_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.chan1_raw , packet1.chan2_raw , packet1.chan3_raw , packet1.chan4_raw , packet1.chan5_raw , packet1.chan6_raw , packet1.chan7_raw , packet1.chan8_raw );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_rc_channels_override_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.chan1_raw , packet1.chan2_raw , packet1.chan3_raw , packet1.chan4_raw , packet1.chan5_raw , packet1.chan6_raw , packet1.chan7_raw , packet1.chan8_raw );
	mavlink_msg_rc_channels_override_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.chan1_raw , packet1.chan2_raw , packet1.chan3_raw , packet1.chan4_raw , packet1.chan5_raw , packet1.chan6_raw , packet1.chan7_raw , packet1.chan8_raw );
}

static void mavlink_test_global_position_int(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_global_position_int_t packet2, packet1 = {
		.lat = 963497464,
	.lon = 963497672,
	.alt = 963497880,
	.vx = 17859,
	.vy = 17963,
	.vz = 18067,
	.hdg = 18171,
	};
	mavlink_msg_global_position_int_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_global_position_int_decode(&msg, &packet2);
	mavlink_msg_global_position_int_pack(system_id, component_id, &msg , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz , packet1.hdg );
	mavlink_msg_global_position_int_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz , packet1.hdg );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_global_position_int_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz , packet1.hdg );
	mavlink_msg_global_position_int_send(MAVLINK_COMM_2 , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz , packet1.hdg );
}

static void mavlink_test_vfr_hud(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_vfr_hud_t packet2, packet1 = {
		.airspeed = 17.0,
	.groundspeed = 45.0,
	.heading = 18067,
	.throttle = 18171,
	.alt = 73.0,
	.climb = 101.0,
	};
	mavlink_msg_vfr_hud_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_vfr_hud_decode(&msg, &packet2);
	mavlink_msg_vfr_hud_pack(system_id, component_id, &msg , packet1.airspeed , packet1.groundspeed , packet1.heading , packet1.throttle , packet1.alt , packet1.climb );
	mavlink_msg_vfr_hud_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.airspeed , packet1.groundspeed , packet1.heading , packet1.throttle , packet1.alt , packet1.climb );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_vfr_hud_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.airspeed , packet1.groundspeed , packet1.heading , packet1.throttle , packet1.alt , packet1.climb );
	mavlink_msg_vfr_hud_send(MAVLINK_COMM_2 , packet1.airspeed , packet1.groundspeed , packet1.heading , packet1.throttle , packet1.alt , packet1.climb );
}

static void mavlink_test_command_short(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_command_short_t packet2, packet1 = {
		.target_system = 53,
	.target_component = 120,
	.command = 187,
	.confirmation = 254,
	.param1 = 17.0,
	.param2 = 45.0,
	.param3 = 73.0,
	.param4 = 101.0,
	};
	mavlink_msg_command_short_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_command_short_decode(&msg, &packet2);
	mavlink_msg_command_short_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.command , packet1.confirmation , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
	mavlink_msg_command_short_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.command , packet1.confirmation , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_command_short_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.command , packet1.confirmation , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
	mavlink_msg_command_short_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.command , packet1.confirmation , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
}

static void mavlink_test_command_long(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_command_long_t packet2, packet1 = {
		.target_system = 89,
	.target_component = 156,
	.command = 223,
	.confirmation = 34,
	.param1 = 17.0,
	.param2 = 45.0,
	.param3 = 73.0,
	.param4 = 101.0,
	.param5 = 129.0,
	.param6 = 157.0,
	.param7 = 185.0,
	};
	mavlink_msg_command_long_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_command_long_decode(&msg, &packet2);
	mavlink_msg_command_long_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.command , packet1.confirmation , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.param5 , packet1.param6 , packet1.param7 );
	mavlink_msg_command_long_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.command , packet1.confirmation , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.param5 , packet1.param6 , packet1.param7 );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_command_long_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.command , packet1.confirmation , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.param5 , packet1.param6 , packet1.param7 );
	mavlink_msg_command_long_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.command , packet1.confirmation , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.param5 , packet1.param6 , packet1.param7 );
}

static void mavlink_test_command_ack(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_command_ack_t packet2, packet1 = {
		.command = 17.0,
	.result = 45.0,
	};
	mavlink_msg_command_ack_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_command_ack_decode(&msg, &packet2);
	mavlink_msg_command_ack_pack(system_id, component_id, &msg , packet1.command , packet1.result );
	mavlink_msg_command_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.command , packet1.result );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_command_ack_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.command , packet1.result );
	mavlink_msg_command_ack_send(MAVLINK_COMM_2 , packet1.command , packet1.result );
}

static void mavlink_test_hil_state(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_hil_state_t packet2, packet1 = {
		.time_us = 9223372036854775807LL,
	.roll = 73.0,
	.pitch = 101.0,
	.yaw = 129.0,
	.rollspeed = 157.0,
	.pitchspeed = 185.0,
	.yawspeed = 213.0,
	.lat = 963499128,
	.lon = 963499336,
	.alt = 963499544,
	.vx = 19523,
	.vy = 19627,
	.vz = 19731,
	.xacc = 19835,
	.yacc = 19939,
	.zacc = 20043,
	};
	mavlink_msg_hil_state_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_hil_state_decode(&msg, &packet2);
	mavlink_msg_hil_state_pack(system_id, component_id, &msg , packet1.time_us , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollspeed , packet1.pitchspeed , packet1.yawspeed , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz , packet1.xacc , packet1.yacc , packet1.zacc );
	mavlink_msg_hil_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_us , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollspeed , packet1.pitchspeed , packet1.yawspeed , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz , packet1.xacc , packet1.yacc , packet1.zacc );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_hil_state_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.time_us , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollspeed , packet1.pitchspeed , packet1.yawspeed , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz , packet1.xacc , packet1.yacc , packet1.zacc );
	mavlink_msg_hil_state_send(MAVLINK_COMM_2 , packet1.time_us , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollspeed , packet1.pitchspeed , packet1.yawspeed , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz , packet1.xacc , packet1.yacc , packet1.zacc );
}

static void mavlink_test_hil_controls(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_hil_controls_t packet2, packet1 = {
		.time_us = 9223372036854775807LL,
	.roll_ailerons = 73.0,
	.pitch_elevator = 101.0,
	.yaw_rudder = 129.0,
	.throttle = 157.0,
	.aux1 = 185.0,
	.aux2 = 213.0,
	.aux3 = 241.0,
	.aux4 = 269.0,
	.mode = 125,
	.nav_mode = 192,
	};
	mavlink_msg_hil_controls_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_hil_controls_decode(&msg, &packet2);
	mavlink_msg_hil_controls_pack(system_id, component_id, &msg , packet1.time_us , packet1.roll_ailerons , packet1.pitch_elevator , packet1.yaw_rudder , packet1.throttle , packet1.aux1 , packet1.aux2 , packet1.aux3 , packet1.aux4 , packet1.mode , packet1.nav_mode );
	mavlink_msg_hil_controls_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_us , packet1.roll_ailerons , packet1.pitch_elevator , packet1.yaw_rudder , packet1.throttle , packet1.aux1 , packet1.aux2 , packet1.aux3 , packet1.aux4 , packet1.mode , packet1.nav_mode );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_hil_controls_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.time_us , packet1.roll_ailerons , packet1.pitch_elevator , packet1.yaw_rudder , packet1.throttle , packet1.aux1 , packet1.aux2 , packet1.aux3 , packet1.aux4 , packet1.mode , packet1.nav_mode );
	mavlink_msg_hil_controls_send(MAVLINK_COMM_2 , packet1.time_us , packet1.roll_ailerons , packet1.pitch_elevator , packet1.yaw_rudder , packet1.throttle , packet1.aux1 , packet1.aux2 , packet1.aux3 , packet1.aux4 , packet1.mode , packet1.nav_mode );
}

static void mavlink_test_hil_rc_inputs_raw(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_hil_rc_inputs_raw_t packet2, packet1 = {
		.time_us = 9223372036854775807LL,
	.chan1_raw = 17651,
	.chan2_raw = 17755,
	.chan3_raw = 17859,
	.chan4_raw = 17963,
	.chan5_raw = 18067,
	.chan6_raw = 18171,
	.chan7_raw = 18275,
	.chan8_raw = 18379,
	.chan9_raw = 18483,
	.chan10_raw = 18587,
	.chan11_raw = 18691,
	.chan12_raw = 18795,
	.rssi = 101,
	};
	mavlink_msg_hil_rc_inputs_raw_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_hil_rc_inputs_raw_decode(&msg, &packet2);
	mavlink_msg_hil_rc_inputs_raw_pack(system_id, component_id, &msg , packet1.time_us , packet1.chan1_raw , packet1.chan2_raw , packet1.chan3_raw , packet1.chan4_raw , packet1.chan5_raw , packet1.chan6_raw , packet1.chan7_raw , packet1.chan8_raw , packet1.chan9_raw , packet1.chan10_raw , packet1.chan11_raw , packet1.chan12_raw , packet1.rssi );
	mavlink_msg_hil_rc_inputs_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_us , packet1.chan1_raw , packet1.chan2_raw , packet1.chan3_raw , packet1.chan4_raw , packet1.chan5_raw , packet1.chan6_raw , packet1.chan7_raw , packet1.chan8_raw , packet1.chan9_raw , packet1.chan10_raw , packet1.chan11_raw , packet1.chan12_raw , packet1.rssi );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_hil_rc_inputs_raw_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.time_us , packet1.chan1_raw , packet1.chan2_raw , packet1.chan3_raw , packet1.chan4_raw , packet1.chan5_raw , packet1.chan6_raw , packet1.chan7_raw , packet1.chan8_raw , packet1.chan9_raw , packet1.chan10_raw , packet1.chan11_raw , packet1.chan12_raw , packet1.rssi );
	mavlink_msg_hil_rc_inputs_raw_send(MAVLINK_COMM_2 , packet1.time_us , packet1.chan1_raw , packet1.chan2_raw , packet1.chan3_raw , packet1.chan4_raw , packet1.chan5_raw , packet1.chan6_raw , packet1.chan7_raw , packet1.chan8_raw , packet1.chan9_raw , packet1.chan10_raw , packet1.chan11_raw , packet1.chan12_raw , packet1.rssi );
}

static void mavlink_test_optical_flow(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_optical_flow_t packet2, packet1 = {
		.time = 9223372036854775807LL,
	.sensor_id = 53,
	.flow_x = 17859,
	.flow_y = 17963,
	.quality = 120,
	.ground_distance = 73.0,
	};
	mavlink_msg_optical_flow_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_optical_flow_decode(&msg, &packet2);
	mavlink_msg_optical_flow_pack(system_id, component_id, &msg , packet1.time , packet1.sensor_id , packet1.flow_x , packet1.flow_y , packet1.quality , packet1.ground_distance );
	mavlink_msg_optical_flow_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.sensor_id , packet1.flow_x , packet1.flow_y , packet1.quality , packet1.ground_distance );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_optical_flow_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.time , packet1.sensor_id , packet1.flow_x , packet1.flow_y , packet1.quality , packet1.ground_distance );
	mavlink_msg_optical_flow_send(MAVLINK_COMM_2 , packet1.time , packet1.sensor_id , packet1.flow_x , packet1.flow_y , packet1.quality , packet1.ground_distance );
}

static void mavlink_test_memory_vect(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_memory_vect_t packet2, packet1 = {
		.address = 17235,
	.ver = 139,
	.type = 206,
	.value = (int8_t *)"17",
	};
	mavlink_msg_memory_vect_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_memory_vect_decode(&msg, &packet2);
	mavlink_msg_memory_vect_pack(system_id, component_id, &msg , packet1.address , packet1.ver , packet1.type , packet1.value );
	mavlink_msg_memory_vect_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.address , packet1.ver , packet1.type , packet1.value );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_memory_vect_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.address , packet1.ver , packet1.type , packet1.value );
	mavlink_msg_memory_vect_send(MAVLINK_COMM_2 , packet1.address , packet1.ver , packet1.type , packet1.value );
}

static void mavlink_test_debug_vect(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_debug_vect_t packet2, packet1 = {
		.name = "ATMFYRKDWP",
	.usec = 9223372036854775807LL,
	.x = 73.0,
	.y = 101.0,
	.z = 129.0,
	};
	mavlink_msg_debug_vect_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_debug_vect_decode(&msg, &packet2);
	mavlink_msg_debug_vect_pack(system_id, component_id, &msg , packet1.name , packet1.usec , packet1.x , packet1.y , packet1.z );
	mavlink_msg_debug_vect_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.name , packet1.usec , packet1.x , packet1.y , packet1.z );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_debug_vect_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.name , packet1.usec , packet1.x , packet1.y , packet1.z );
	mavlink_msg_debug_vect_send(MAVLINK_COMM_2 , packet1.name , packet1.usec , packet1.x , packet1.y , packet1.z );
}

static void mavlink_test_named_value_float(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_named_value_float_t packet2, packet1 = {
		.name = "AHOVCJQXEL",
	.value = 17.0,
	};
	mavlink_msg_named_value_float_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_named_value_float_decode(&msg, &packet2);
	mavlink_msg_named_value_float_pack(system_id, component_id, &msg , packet1.name , packet1.value );
	mavlink_msg_named_value_float_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.name , packet1.value );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_named_value_float_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.name , packet1.value );
	mavlink_msg_named_value_float_send(MAVLINK_COMM_2 , packet1.name , packet1.value );
}

static void mavlink_test_named_value_int(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_named_value_int_t packet2, packet1 = {
		.name = "AHOVCJQXEL",
	.value = 963497464,
	};
	mavlink_msg_named_value_int_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_named_value_int_decode(&msg, &packet2);
	mavlink_msg_named_value_int_pack(system_id, component_id, &msg , packet1.name , packet1.value );
	mavlink_msg_named_value_int_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.name , packet1.value );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_named_value_int_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.name , packet1.value );
	mavlink_msg_named_value_int_send(MAVLINK_COMM_2 , packet1.name , packet1.value );
}

static void mavlink_test_statustext(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_statustext_t packet2, packet1 = {
		.severity = 5,
	.text = "AIQYGOWEMUCKSAIQYGOWEMUCKSAIQYGOWEMUCKSAIQYGOWEMUC",
	};
	mavlink_msg_statustext_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_statustext_decode(&msg, &packet2);
	mavlink_msg_statustext_pack(system_id, component_id, &msg , packet1.severity , packet1.text );
	mavlink_msg_statustext_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.severity , packet1.text );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_statustext_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.severity , packet1.text );
	mavlink_msg_statustext_send(MAVLINK_COMM_2 , packet1.severity , packet1.text );
}

static void mavlink_test_debug(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_debug_t packet2, packet1 = {
		.ind = 17,
	.value = 17.0,
	};
	mavlink_msg_debug_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_debug_decode(&msg, &packet2);
	mavlink_msg_debug_pack(system_id, component_id, &msg , packet1.ind , packet1.value );
	mavlink_msg_debug_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.ind , packet1.value );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_debug_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.ind , packet1.value );
	mavlink_msg_debug_send(MAVLINK_COMM_2 , packet1.ind , packet1.value );
}

static void mavlink_test_all(uint8_t system_id, uint8_t component_id)
{
	mavlink_test_heartbeat(system_id, component_id);
	mavlink_test_sys_status(system_id, component_id);
	mavlink_test_system_time(system_id, component_id);
	mavlink_test_system_time_utc(system_id, component_id);
	mavlink_test_ping(system_id, component_id);
	mavlink_test_change_operator_control(system_id, component_id);
	mavlink_test_change_operator_control_ack(system_id, component_id);
	mavlink_test_auth_key(system_id, component_id);
	mavlink_test_set_mode(system_id, component_id);
	mavlink_test_set_flight_mode(system_id, component_id);
	mavlink_test_set_safety_mode(system_id, component_id);
	mavlink_test_param_request_read(system_id, component_id);
	mavlink_test_param_request_list(system_id, component_id);
	mavlink_test_param_value(system_id, component_id);
	mavlink_test_param_set(system_id, component_id);
	mavlink_test_gps_raw_int(system_id, component_id);
	mavlink_test_scaled_imu(system_id, component_id);
	mavlink_test_gps_status(system_id, component_id);
	mavlink_test_raw_imu(system_id, component_id);
	mavlink_test_raw_pressure(system_id, component_id);
	mavlink_test_scaled_pressure(system_id, component_id);
	mavlink_test_attitude(system_id, component_id);
	mavlink_test_local_position(system_id, component_id);
	mavlink_test_global_position(system_id, component_id);
	mavlink_test_gps_raw(system_id, component_id);
	mavlink_test_rc_channels_raw(system_id, component_id);
	mavlink_test_rc_channels_scaled(system_id, component_id);
	mavlink_test_servo_output_raw(system_id, component_id);
	mavlink_test_waypoint(system_id, component_id);
	mavlink_test_waypoint_request(system_id, component_id);
	mavlink_test_waypoint_set_current(system_id, component_id);
	mavlink_test_waypoint_current(system_id, component_id);
	mavlink_test_waypoint_request_list(system_id, component_id);
	mavlink_test_waypoint_count(system_id, component_id);
	mavlink_test_waypoint_clear_all(system_id, component_id);
	mavlink_test_waypoint_reached(system_id, component_id);
	mavlink_test_waypoint_ack(system_id, component_id);
	mavlink_test_gps_set_global_origin(system_id, component_id);
	mavlink_test_gps_local_origin_set(system_id, component_id);
	mavlink_test_local_position_setpoint_set(system_id, component_id);
	mavlink_test_local_position_setpoint(system_id, component_id);
	mavlink_test_global_position_setpoint_int(system_id, component_id);
	mavlink_test_safety_set_allowed_area(system_id, component_id);
	mavlink_test_safety_allowed_area(system_id, component_id);
	mavlink_test_set_roll_pitch_yaw_thrust(system_id, component_id);
	mavlink_test_set_roll_pitch_yaw_speed_thrust(system_id, component_id);
	mavlink_test_roll_pitch_yaw_thrust_setpoint(system_id, component_id);
	mavlink_test_roll_pitch_yaw_speed_thrust_setpoint(system_id, component_id);
	mavlink_test_nav_controller_output(system_id, component_id);
	mavlink_test_position_target(system_id, component_id);
	mavlink_test_state_correction(system_id, component_id);
	mavlink_test_request_data_stream(system_id, component_id);
	mavlink_test_data_stream(system_id, component_id);
	mavlink_test_manual_control(system_id, component_id);
	mavlink_test_rc_channels_override(system_id, component_id);
	mavlink_test_global_position_int(system_id, component_id);
	mavlink_test_vfr_hud(system_id, component_id);
	mavlink_test_command_short(system_id, component_id);
	mavlink_test_command_long(system_id, component_id);
	mavlink_test_command_ack(system_id, component_id);
	mavlink_test_hil_state(system_id, component_id);
	mavlink_test_hil_controls(system_id, component_id);
	mavlink_test_hil_rc_inputs_raw(system_id, component_id);
	mavlink_test_optical_flow(system_id, component_id);
	mavlink_test_memory_vect(system_id, component_id);
	mavlink_test_debug_vect(system_id, component_id);
	mavlink_test_named_value_float(system_id, component_id);
	mavlink_test_named_value_int(system_id, component_id);
	mavlink_test_statustext(system_id, component_id);
	mavlink_test_debug(system_id, component_id);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // COMMON_TESTSUITE_H

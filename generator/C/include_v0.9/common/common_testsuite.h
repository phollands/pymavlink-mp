/** @file
 *	@brief MAVLink comm protocol testsuite generated from common.xml
 *	@see http://qgroundcontrol.org/mavlink/
 *	Generated on Fri Aug 26 09:46:51 2011
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
	};
	mavlink_msg_heartbeat_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_heartbeat_decode(&msg, &packet2);
	mavlink_msg_heartbeat_pack(system_id, component_id, &msg , packet1.type , packet1.autopilot );
	mavlink_msg_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.autopilot );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_heartbeat_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.type , packet1.autopilot );
	mavlink_msg_heartbeat_send(MAVLINK_COMM_2 , packet1.type , packet1.autopilot );
}

static void mavlink_test_boot(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_boot_t packet2, packet1 = {
		.version = 963497464,
	};
	mavlink_msg_boot_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_boot_decode(&msg, &packet2);
	mavlink_msg_boot_pack(system_id, component_id, &msg , packet1.version );
	mavlink_msg_boot_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.version );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_boot_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.version );
	mavlink_msg_boot_send(MAVLINK_COMM_2 , packet1.version );
}

static void mavlink_test_system_time(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_system_time_t packet2, packet1 = {
		.time_usec = 9223372036854775807LL,
	};
	mavlink_msg_system_time_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_system_time_decode(&msg, &packet2);
	mavlink_msg_system_time_pack(system_id, component_id, &msg , packet1.time_usec );
	mavlink_msg_system_time_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_system_time_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.time_usec );
	mavlink_msg_system_time_send(MAVLINK_COMM_2 , packet1.time_usec );
}

static void mavlink_test_ping(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_ping_t packet2, packet1 = {
		.seq = 963497464,
	.target_system = 17,
	.target_component = 84,
	.time = 9223372036854776185LL,
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

static void mavlink_test_action_ack(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_action_ack_t packet2, packet1 = {
		.action = 5,
	.result = 72,
	};
	mavlink_msg_action_ack_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_action_ack_decode(&msg, &packet2);
	mavlink_msg_action_ack_pack(system_id, component_id, &msg , packet1.action , packet1.result );
	mavlink_msg_action_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.action , packet1.result );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_action_ack_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.action , packet1.result );
	mavlink_msg_action_ack_send(MAVLINK_COMM_2 , packet1.action , packet1.result );
}

static void mavlink_test_action(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_action_t packet2, packet1 = {
		.target = 5,
	.target_component = 72,
	.action = 139,
	};
	mavlink_msg_action_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_action_decode(&msg, &packet2);
	mavlink_msg_action_pack(system_id, component_id, &msg , packet1.target , packet1.target_component , packet1.action );
	mavlink_msg_action_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target , packet1.target_component , packet1.action );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_action_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target , packet1.target_component , packet1.action );
	mavlink_msg_action_send(MAVLINK_COMM_2 , packet1.target , packet1.target_component , packet1.action );
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

static void mavlink_test_set_nav_mode(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_set_nav_mode_t packet2, packet1 = {
		.target = 5,
	.nav_mode = 72,
	};
	mavlink_msg_set_nav_mode_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_set_nav_mode_decode(&msg, &packet2);
	mavlink_msg_set_nav_mode_pack(system_id, component_id, &msg , packet1.target , packet1.nav_mode );
	mavlink_msg_set_nav_mode_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target , packet1.nav_mode );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_set_nav_mode_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target , packet1.nav_mode );
	mavlink_msg_set_nav_mode_send(MAVLINK_COMM_2 , packet1.target , packet1.nav_mode );
}

static void mavlink_test_param_request_read(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_param_request_read_t packet2, packet1 = {
		.target_system = 5,
	.target_component = 72,
	.param_id = (int8_t *)"139",
	.param_index = 18119,
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
		.param_id = (int8_t *)"5",
	.param_value = 122.0,
	.param_count = 18223,
	.param_index = 18327,
	};
	mavlink_msg_param_value_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_param_value_decode(&msg, &packet2);
	mavlink_msg_param_value_pack(system_id, component_id, &msg , packet1.param_id , packet1.param_value , packet1.param_count , packet1.param_index );
	mavlink_msg_param_value_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.param_id , packet1.param_value , packet1.param_count , packet1.param_index );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_param_value_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.param_id , packet1.param_value , packet1.param_count , packet1.param_index );
	mavlink_msg_param_value_send(MAVLINK_COMM_2 , packet1.param_id , packet1.param_value , packet1.param_count , packet1.param_index );
}

static void mavlink_test_param_set(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_param_set_t packet2, packet1 = {
		.target_system = 5,
	.target_component = 72,
	.param_id = (int8_t *)"139",
	.param_value = 136.0,
	};
	mavlink_msg_param_set_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_param_set_decode(&msg, &packet2);
	mavlink_msg_param_set_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.param_id , packet1.param_value );
	mavlink_msg_param_set_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.param_id , packet1.param_value );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_param_set_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.param_id , packet1.param_value );
	mavlink_msg_param_set_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.param_id , packet1.param_value );
}

static void mavlink_test_gps_raw_int(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_gps_raw_int_t packet2, packet1 = {
		.usec = 9223372036854775807LL,
	.fix_type = 29,
	.lat = 963497932,
	.lon = 963498140,
	.alt = 963498348,
	.eph = 164.0,
	.epv = 192.0,
	.v = 220.0,
	.hdg = 248.0,
	};
	mavlink_msg_gps_raw_int_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_gps_raw_int_decode(&msg, &packet2);
	mavlink_msg_gps_raw_int_pack(system_id, component_id, &msg , packet1.usec , packet1.fix_type , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.v , packet1.hdg );
	mavlink_msg_gps_raw_int_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.usec , packet1.fix_type , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.v , packet1.hdg );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_gps_raw_int_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.usec , packet1.fix_type , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.v , packet1.hdg );
	mavlink_msg_gps_raw_int_send(MAVLINK_COMM_2 , packet1.usec , packet1.fix_type , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.v , packet1.hdg );
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
	.satellite_prn = (int8_t *)"72",
	.satellite_used = (int8_t *)"132",
	.satellite_elevation = (int8_t *)"192",
	.satellite_azimuth = (int8_t *)"252",
	.satellite_snr = (int8_t *)"56",
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
	.fix_type = 29,
	.lat = 80.0,
	.lon = 108.0,
	.alt = 136.0,
	.eph = 164.0,
	.epv = 192.0,
	.v = 220.0,
	.hdg = 248.0,
	};
	mavlink_msg_gps_raw_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_gps_raw_decode(&msg, &packet2);
	mavlink_msg_gps_raw_pack(system_id, component_id, &msg , packet1.usec , packet1.fix_type , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.v , packet1.hdg );
	mavlink_msg_gps_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.usec , packet1.fix_type , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.v , packet1.hdg );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_gps_raw_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.usec , packet1.fix_type , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.v , packet1.hdg );
	mavlink_msg_gps_raw_send(MAVLINK_COMM_2 , packet1.usec , packet1.fix_type , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.v , packet1.hdg );
}

static void mavlink_test_sys_status(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_sys_status_t packet2, packet1 = {
		.mode = 5,
	.nav_mode = 72,
	.status = 139,
	.load = 17391,
	.vbat = 17495,
	.battery_remaining = 17599,
	.packet_drop = 17703,
	};
	mavlink_msg_sys_status_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_sys_status_decode(&msg, &packet2);
	mavlink_msg_sys_status_pack(system_id, component_id, &msg , packet1.mode , packet1.nav_mode , packet1.status , packet1.load , packet1.vbat , packet1.battery_remaining , packet1.packet_drop );
	mavlink_msg_sys_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mode , packet1.nav_mode , packet1.status , packet1.load , packet1.vbat , packet1.battery_remaining , packet1.packet_drop );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_sys_status_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.mode , packet1.nav_mode , packet1.status , packet1.load , packet1.vbat , packet1.battery_remaining , packet1.packet_drop );
	mavlink_msg_sys_status_send(MAVLINK_COMM_2 , packet1.mode , packet1.nav_mode , packet1.status , packet1.load , packet1.vbat , packet1.battery_remaining , packet1.packet_drop );
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
		.target_system = 5,
	.target_component = 72,
	.seq = 17339,
	.frame = 17,
	.command = 84,
	.current = 151,
	.autocontinue = 218,
	.param1 = 73.0,
	.param2 = 101.0,
	.param3 = 129.0,
	.param4 = 157.0,
	.x = 185.0,
	.y = 213.0,
	.z = 241.0,
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
		.target_system = 5,
	.target_component = 72,
	.seq = 17339,
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
		.target_system = 5,
	.target_component = 72,
	.seq = 17339,
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
		.target_system = 5,
	.target_component = 72,
	.count = 17339,
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
		.target_system = 5,
	.target_component = 72,
	.latitude = 963497568,
	.longitude = 963497776,
	.altitude = 963497984,
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
		.target_system = 5,
	.target_component = 72,
	.x = 31.0,
	.y = 59.0,
	.z = 87.0,
	.yaw = 115.0,
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

static void mavlink_test_control_status(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_control_status_t packet2, packet1 = {
		.position_fix = 5,
	.vision_fix = 72,
	.gps_fix = 139,
	.ahrs_health = 206,
	.control_att = 17,
	.control_pos_xy = 84,
	.control_pos_z = 151,
	.control_pos_yaw = 218,
	};
	mavlink_msg_control_status_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_control_status_decode(&msg, &packet2);
	mavlink_msg_control_status_pack(system_id, component_id, &msg , packet1.position_fix , packet1.vision_fix , packet1.gps_fix , packet1.ahrs_health , packet1.control_att , packet1.control_pos_xy , packet1.control_pos_z , packet1.control_pos_yaw );
	mavlink_msg_control_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.position_fix , packet1.vision_fix , packet1.gps_fix , packet1.ahrs_health , packet1.control_att , packet1.control_pos_xy , packet1.control_pos_z , packet1.control_pos_yaw );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_control_status_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.position_fix , packet1.vision_fix , packet1.gps_fix , packet1.ahrs_health , packet1.control_att , packet1.control_pos_xy , packet1.control_pos_z , packet1.control_pos_yaw );
	mavlink_msg_control_status_send(MAVLINK_COMM_2 , packet1.position_fix , packet1.vision_fix , packet1.gps_fix , packet1.ahrs_health , packet1.control_att , packet1.control_pos_xy , packet1.control_pos_z , packet1.control_pos_yaw );
}

static void mavlink_test_safety_set_allowed_area(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_safety_set_allowed_area_t packet2, packet1 = {
		.target_system = 5,
	.target_component = 72,
	.frame = 139,
	.p1x = 38.0,
	.p1y = 66.0,
	.p1z = 94.0,
	.p2x = 122.0,
	.p2y = 150.0,
	.p2z = 178.0,
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
		.frame = 5,
	.p1x = 24.0,
	.p1y = 52.0,
	.p1z = 80.0,
	.p2x = 108.0,
	.p2y = 136.0,
	.p2z = 164.0,
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
		.target_system = 5,
	.target_component = 72,
	.roll = 31.0,
	.pitch = 59.0,
	.yaw = 87.0,
	.thrust = 115.0,
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
		.target_system = 5,
	.target_component = 72,
	.roll_speed = 31.0,
	.pitch_speed = 59.0,
	.yaw_speed = 87.0,
	.thrust = 115.0,
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
		.time_us = 9223372036854775807LL,
	.roll = 73.0,
	.pitch = 101.0,
	.yaw = 129.0,
	.thrust = 157.0,
	};
	mavlink_msg_roll_pitch_yaw_thrust_setpoint_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_roll_pitch_yaw_thrust_setpoint_decode(&msg, &packet2);
	mavlink_msg_roll_pitch_yaw_thrust_setpoint_pack(system_id, component_id, &msg , packet1.time_us , packet1.roll , packet1.pitch , packet1.yaw , packet1.thrust );
	mavlink_msg_roll_pitch_yaw_thrust_setpoint_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_us , packet1.roll , packet1.pitch , packet1.yaw , packet1.thrust );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_roll_pitch_yaw_thrust_setpoint_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.time_us , packet1.roll , packet1.pitch , packet1.yaw , packet1.thrust );
	mavlink_msg_roll_pitch_yaw_thrust_setpoint_send(MAVLINK_COMM_2 , packet1.time_us , packet1.roll , packet1.pitch , packet1.yaw , packet1.thrust );
}

static void mavlink_test_roll_pitch_yaw_speed_thrust_setpoint(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_roll_pitch_yaw_speed_thrust_setpoint_t packet2, packet1 = {
		.time_us = 9223372036854775807LL,
	.roll_speed = 73.0,
	.pitch_speed = 101.0,
	.yaw_speed = 129.0,
	.thrust = 157.0,
	};
	mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_decode(&msg, &packet2);
	mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_pack(system_id, component_id, &msg , packet1.time_us , packet1.roll_speed , packet1.pitch_speed , packet1.yaw_speed , packet1.thrust );
	mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_us , packet1.roll_speed , packet1.pitch_speed , packet1.yaw_speed , packet1.thrust );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.time_us , packet1.roll_speed , packet1.pitch_speed , packet1.yaw_speed , packet1.thrust );
	mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_send(MAVLINK_COMM_2 , packet1.time_us , packet1.roll_speed , packet1.pitch_speed , packet1.yaw_speed , packet1.thrust );
}

static void mavlink_test_nav_controller_output(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_nav_controller_output_t packet2, packet1 = {
		.nav_roll = 17.0,
	.nav_pitch = 45.0,
	.nav_bearing = 17651,
	.target_bearing = 17755,
	.wp_dist = 17859,
	.alt_error = 115.0,
	.aspd_error = 143.0,
	.xtrack_error = 171.0,
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

static void mavlink_test_set_altitude(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_set_altitude_t packet2, packet1 = {
		.target = 5,
	.mode = 963497516,
	};
	mavlink_msg_set_altitude_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_set_altitude_decode(&msg, &packet2);
	mavlink_msg_set_altitude_pack(system_id, component_id, &msg , packet1.target , packet1.mode );
	mavlink_msg_set_altitude_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target , packet1.mode );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_set_altitude_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target , packet1.mode );
	mavlink_msg_set_altitude_send(MAVLINK_COMM_2 , packet1.target , packet1.mode );
}

static void mavlink_test_request_data_stream(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_request_data_stream_t packet2, packet1 = {
		.target_system = 5,
	.target_component = 72,
	.req_stream_id = 139,
	.req_message_rate = 17391,
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

static void mavlink_test_hil_state(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_hil_state_t packet2, packet1 = {
		.usec = 9223372036854775807LL,
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
	mavlink_msg_hil_state_pack(system_id, component_id, &msg , packet1.usec , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollspeed , packet1.pitchspeed , packet1.yawspeed , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz , packet1.xacc , packet1.yacc , packet1.zacc );
	mavlink_msg_hil_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.usec , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollspeed , packet1.pitchspeed , packet1.yawspeed , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz , packet1.xacc , packet1.yacc , packet1.zacc );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_hil_state_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.usec , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollspeed , packet1.pitchspeed , packet1.yawspeed , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz , packet1.xacc , packet1.yacc , packet1.zacc );
	mavlink_msg_hil_state_send(MAVLINK_COMM_2 , packet1.usec , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollspeed , packet1.pitchspeed , packet1.yawspeed , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz , packet1.xacc , packet1.yacc , packet1.zacc );
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
	.mode = 77,
	.nav_mode = 144,
	};
	mavlink_msg_hil_controls_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_hil_controls_decode(&msg, &packet2);
	mavlink_msg_hil_controls_pack(system_id, component_id, &msg , packet1.time_us , packet1.roll_ailerons , packet1.pitch_elevator , packet1.yaw_rudder , packet1.throttle , packet1.mode , packet1.nav_mode );
	mavlink_msg_hil_controls_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_us , packet1.roll_ailerons , packet1.pitch_elevator , packet1.yaw_rudder , packet1.throttle , packet1.mode , packet1.nav_mode );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_hil_controls_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.time_us , packet1.roll_ailerons , packet1.pitch_elevator , packet1.yaw_rudder , packet1.throttle , packet1.mode , packet1.nav_mode );
	mavlink_msg_hil_controls_send(MAVLINK_COMM_2 , packet1.time_us , packet1.roll_ailerons , packet1.pitch_elevator , packet1.yaw_rudder , packet1.throttle , packet1.mode , packet1.nav_mode );
}

static void mavlink_test_manual_control(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_manual_control_t packet2, packet1 = {
		.target = 5,
	.roll = 24.0,
	.pitch = 52.0,
	.yaw = 80.0,
	.thrust = 108.0,
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
		.target_system = 5,
	.target_component = 72,
	.chan1_raw = 17339,
	.chan2_raw = 17443,
	.chan3_raw = 17547,
	.chan4_raw = 17651,
	.chan5_raw = 17755,
	.chan6_raw = 17859,
	.chan7_raw = 17963,
	.chan8_raw = 18067,
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
	};
	mavlink_msg_global_position_int_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_global_position_int_decode(&msg, &packet2);
	mavlink_msg_global_position_int_pack(system_id, component_id, &msg , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz );
	mavlink_msg_global_position_int_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_global_position_int_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz );
	mavlink_msg_global_position_int_send(MAVLINK_COMM_2 , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz );
}

static void mavlink_test_vfr_hud(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_vfr_hud_t packet2, packet1 = {
		.airspeed = 17.0,
	.groundspeed = 45.0,
	.heading = 17651,
	.throttle = 17755,
	.alt = 101.0,
	.climb = 129.0,
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

static void mavlink_test_command(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_command_t packet2, packet1 = {
		.target_system = 5,
	.target_component = 72,
	.command = 139,
	.confirmation = 206,
	.param1 = 45.0,
	.param2 = 73.0,
	.param3 = 101.0,
	.param4 = 129.0,
	};
	mavlink_msg_command_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_command_decode(&msg, &packet2);
	mavlink_msg_command_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.command , packet1.confirmation , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
	mavlink_msg_command_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.command , packet1.confirmation , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_command_pack_chan_send(MAVLINK_COMM_1, &msg , packet1.target_system , packet1.target_component , packet1.command , packet1.confirmation , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
	mavlink_msg_command_send(MAVLINK_COMM_2 , packet1.target_system , packet1.target_component , packet1.command , packet1.confirmation , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
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

static void mavlink_test_optical_flow(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_optical_flow_t packet2, packet1 = {
		.time = 9223372036854775807LL,
	.sensor_id = 29,
	.flow_x = 17703,
	.flow_y = 17807,
	.quality = 108,
	.ground_distance = 115.0,
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

static void mavlink_test_debug_vect(uint8_t system_id, uint8_t component_id)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        int i;
	mavlink_debug_vect_t packet2, packet1 = {
		.name = "ARIZQHYPGX",
	.usec = 9223372036854776437LL,
	.x = 143.0,
	.y = 171.0,
	.z = 199.0,
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
		.name = "ARIZQHYPGX",
	.value = 87.0,
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
		.name = "ARIZQHYPGX",
	.value = 963497984,
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
	.text = (int8_t *)"72",
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
		.ind = 5,
	.value = 24.0,
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
	mavlink_test_boot(system_id, component_id);
	mavlink_test_system_time(system_id, component_id);
	mavlink_test_ping(system_id, component_id);
	mavlink_test_system_time_utc(system_id, component_id);
	mavlink_test_change_operator_control(system_id, component_id);
	mavlink_test_change_operator_control_ack(system_id, component_id);
	mavlink_test_auth_key(system_id, component_id);
	mavlink_test_action_ack(system_id, component_id);
	mavlink_test_action(system_id, component_id);
	mavlink_test_set_mode(system_id, component_id);
	mavlink_test_set_nav_mode(system_id, component_id);
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
	mavlink_test_sys_status(system_id, component_id);
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
	mavlink_test_control_status(system_id, component_id);
	mavlink_test_safety_set_allowed_area(system_id, component_id);
	mavlink_test_safety_allowed_area(system_id, component_id);
	mavlink_test_set_roll_pitch_yaw_thrust(system_id, component_id);
	mavlink_test_set_roll_pitch_yaw_speed_thrust(system_id, component_id);
	mavlink_test_roll_pitch_yaw_thrust_setpoint(system_id, component_id);
	mavlink_test_roll_pitch_yaw_speed_thrust_setpoint(system_id, component_id);
	mavlink_test_nav_controller_output(system_id, component_id);
	mavlink_test_position_target(system_id, component_id);
	mavlink_test_state_correction(system_id, component_id);
	mavlink_test_set_altitude(system_id, component_id);
	mavlink_test_request_data_stream(system_id, component_id);
	mavlink_test_hil_state(system_id, component_id);
	mavlink_test_hil_controls(system_id, component_id);
	mavlink_test_manual_control(system_id, component_id);
	mavlink_test_rc_channels_override(system_id, component_id);
	mavlink_test_global_position_int(system_id, component_id);
	mavlink_test_vfr_hud(system_id, component_id);
	mavlink_test_command(system_id, component_id);
	mavlink_test_command_ack(system_id, component_id);
	mavlink_test_optical_flow(system_id, component_id);
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

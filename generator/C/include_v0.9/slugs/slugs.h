/** @file
 *	@brief MAVLink comm protocol generated from slugs.xml
 *	@see http://qgroundcontrol.org/mavlink/
 *	Generated on Fri Aug 26 14:04:05 2011
 */
#ifndef SLUGS_H
#define SLUGS_H

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {3, 4, 8, 14, 8, 28, 3, 32, 0, 2, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 19, 2, 23, 21, 0, 37, 26, 101, 26, 16, 32, 32, 37, 32, 11, 17, 17, 16, 18, 36, 4, 4, 2, 2, 4, 2, 2, 3, 14, 12, 18, 16, 8, 27, 25, 18, 18, 24, 24, 0, 0, 0, 26, 16, 36, 5, 6, 56, 26, 21, 18, 0, 0, 18, 20, 20, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 10, 24, 18, 0, 0, 30, 24, 0, 7, 13, 3, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 14, 14, 51, 5}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {133, 61, 13, 242, 160, 5, 129, 181, 0, 8, 181, 204, 134, 0, 0, 0, 0, 0, 0, 0, 61, 16, 3, 142, 0, 206, 140, 101, 120, 233, 79, 2, 215, 220, 90, 1, 92, 223, 153, 195, 138, 47, 241, 68, 5, 232, 235, 46, 13, 180, 114, 40, 102, 208, 162, 9, 49, 28, 95, 0, 0, 0, 100, 67, 227, 223, 95, 180, 113, 72, 51, 0, 0, 147, 103, 130, 228, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 127, 185, 183, 204, 0, 0, 188, 126, 0, 66, 144, 142, 0, 93, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 239, 6, 103, 88, 197}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_SLUGS

#include "../common/common.h"

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

// ENUM DEFINITIONS



// MESSAGE DEFINITIONS
#include "./mavlink_msg_cpu_load.h"
#include "./mavlink_msg_air_data.h"
#include "./mavlink_msg_sensor_bias.h"
#include "./mavlink_msg_diagnostic.h"
#include "./mavlink_msg_slugs_navigation.h"
#include "./mavlink_msg_data_log.h"
#include "./mavlink_msg_gps_date_time.h"
#include "./mavlink_msg_mid_lvl_cmds.h"
#include "./mavlink_msg_ctrl_srfc_pt.h"
#include "./mavlink_msg_slugs_action.h"

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // SLUGS_H

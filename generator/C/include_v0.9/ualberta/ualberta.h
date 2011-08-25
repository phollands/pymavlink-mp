/** @file
 *	@brief MAVLink comm protocol generated from ualberta.xml
 *	@see http://qgroundcontrol.org/mavlink/
 *	Generated on Thu Aug 25 18:37:46 2011
 */
#ifndef UALBERTA_H
#define UALBERTA_H

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#undef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {3, 4, 8, 14, 8, 28, 3, 32, 0, 2, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 19, 2, 23, 21, 0, 37, 26, 101, 26, 16, 32, 32, 37, 32, 11, 17, 17, 16, 18, 36, 4, 4, 2, 2, 4, 2, 2, 3, 14, 12, 18, 16, 8, 27, 25, 18, 18, 24, 24, 0, 0, 0, 26, 16, 36, 5, 6, 56, 26, 21, 18, 0, 0, 18, 20, 20, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 42, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 14, 14, 51, 5}

#undef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {133, 61, 13, 242, 160, 5, 129, 181, 0, 8, 181, 204, 134, 0, 0, 0, 0, 0, 0, 0, 61, 16, 3, 142, 0, 206, 140, 101, 120, 233, 79, 2, 215, 220, 90, 1, 92, 223, 153, 195, 138, 47, 241, 68, 5, 232, 235, 46, 13, 180, 114, 40, 102, 208, 162, 9, 49, 28, 95, 0, 0, 0, 100, 67, 227, 223, 95, 180, 113, 72, 51, 0, 0, 147, 103, 130, 228, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 41, 104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 239, 6, 103, 88, 197}
    

#include "../protocol.h"

#define MAVLINK_ENABLED_UALBERTA

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


/** @brief Available autopilot modes for ualberta uav */
enum UALBERTA_AUTOPILOT_MODE
{
	MODE_MANUAL_DIRECT=0, /*  | */
	MODE_MANUAL_SCALED=1, /*  | */
	MODE_AUTO_PID_ATT=2, /*  | */
	MODE_AUTO_PID_VEL=3, /*  | */
	MODE_AUTO_PID_POS=4, /*  | */
};

/** @brief Navigation filter mode */
enum UALBERTA_NAV_MODE
{
	NAV_AHRS_INIT=0, /*  | */
	NAV_AHRS=1, /*  | */
	NAV_INS_GPS_INIT=2, /*  | */
	NAV_INS_GPS=3, /*  | */
};

/** @brief Mode currently commanded by pilot */
enum UALBERTA_PILOT_MODE
{
	PILOT_MANUAL=0, /*  | */
	PILOT_AUTO=1, /*  | */
	PILOT_ROTO=2, /*  | */
};

// MESSAGE DEFINITIONS
#include "./mavlink_msg_nav_filter_bias.h"
#include "./mavlink_msg_radio_calibration.h"
#include "./mavlink_msg_ualberta_sys_status.h"

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // UALBERTA_H

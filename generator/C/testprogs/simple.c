/*
  simple MAVLink testsuite for C
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAVLINK_USE_CONVENIENCE_FUNCTIONS

#include <mavlink_types.h>
static mavlink_system_t mavlink_system = {42,11,};

static unsigned count;

#define MAVLINK_ASSERT(x) assert(x)
static void comm_send_ch(mavlink_channel_t chan, uint8_t c);

#include <common/mavlink.h>
#include <common/common_testsuite.h>

static void comm_send_ch(mavlink_channel_t chan, uint8_t c)
{
	mavlink_message_t msg;
	mavlink_status_t status;
	if (mavlink_parse_char(chan, c, &msg, &status)) {
		count++;
		if (status.current_rx_seq != count) {
			printf("Sequence mismatch error at packet %u (rx_seq=%u)\n", 
			       count, status.current_rx_seq);
			exit(1);
		}
	}
	if (status.packet_rx_drop_count != 0) {
		printf("Parse error at packet %u\n", count);
		exit(1);
	}
}

int main(void)
{
	mavtest_generate_outputs(MAVLINK_COMM_0);
	printf("Received %u messages OK\n", count);
	return 0;
}


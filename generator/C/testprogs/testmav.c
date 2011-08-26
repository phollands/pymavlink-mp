/*
  simple MAVLink testsuite for C
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAVLINK_USE_CONVENIENCE_FUNCTIONS
#define MAVLINK_COMM_NUM_BUFFERS 3

#include <mavlink_types.h>
static mavlink_system_t mavlink_system = {42,11,};

#define MAVLINK_ASSERT(x) assert(x)
static void comm_send_ch(mavlink_channel_t chan, uint8_t c);

#include <mavlink.h>
#include <testsuite.h>

static unsigned chan_counts[MAVLINK_COMM_NUM_BUFFERS];

static const unsigned message_lengths[] = MAVLINK_MESSAGE_LENGTHS;
static unsigned error_count;

static void comm_send_ch(mavlink_channel_t chan, uint8_t c)
{
	mavlink_message_t msg;
	mavlink_status_t status;
	if (mavlink_parse_char(chan, c, &msg, &status)) {
		chan_counts[chan]++;
		/* channel 0 gets 3 messages per message, because of
		   the channel defaults for _pack() and _encode() */
		if (chan == MAVLINK_COMM_0 && status.current_rx_seq != (uint8_t)(chan_counts[chan]*3)) {
			printf("Channel 0 sequence mismatch error at packet %u (rx_seq=%u)\n", 
			       chan_counts[chan], status.current_rx_seq);
			error_count++;
		} else if (chan > MAVLINK_COMM_0 && status.current_rx_seq != (uint8_t)chan_counts[chan]) {
			printf("Channel %u sequence mismatch error at packet %u (rx_seq=%u)\n", 
			       (unsigned)chan, chan_counts[chan], status.current_rx_seq);
			error_count++;
		}
		if (message_lengths[msg.msgid] != msg.len) {
			printf("Incorrect message length %u for message %u - expected %u\n", 
			       (unsigned)msg.len, (unsigned)msg.msgid, message_lengths[msg.msgid]);
			error_count++;
		}
	}
	if (status.packet_rx_drop_count != 0) {
		printf("Parse error at packet %u\n", chan_counts[chan]);
		error_count++;
	}
}

int main(void)
{
	mavlink_channel_t chan;
	mavlink_test_all(11, 10);
	for (chan=MAVLINK_COMM_0; chan<=MAVLINK_COMM_2; chan++) {
		printf("Received %u messages on channel %u OK\n", 
		       chan_counts[chan], (unsigned)chan);
	}
	if (error_count != 0) {
		printf("Error count %u\n", error_count);
		exit(1);
	}
	printf("No errors detected\n");
	return 0;
}


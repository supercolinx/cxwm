/**
 * @file	custom.c
 * @author	Colin X
 * @date	Wed Jun 10 21:25:31 2026
 * @description:
*/

#include <unistd.h>
#include "custom_disp.h"
#include "custom_ticks.h"
#include "custom_event.h"
#include "custom.h"

static custom_event_cb_t s_event_cb = NULL;

int custom_init(void)
{
	if (custom_ticks_init() != 0) 
		return -1;

	custom_disp_init();
	custom_event_init();

	return 0;
}

void custom_deinit(void)
{
	custom_event_deinit();
	custom_disp_deinit();
	custom_ticks_deinit();
}

void custom_event_set_callback(void (*cb)(const unsigned int*, int))
{
	s_event_cb = cb;
}

void custom_event_dequeue(int timeout)
{
	usleep(timeout * 1000);
}

int custom_event_enqueue(const unsigned int event)
{
	if (s_event_cb) {
		s_event_cb(&event, 1);
	}
	return 0;
}

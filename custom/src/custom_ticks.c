/**
 * @file	custom_ticks.c
 * @author	Colin X
 * @date	Wed Jun 10 21:47:19 2026
 * @description:
*/

#include <time.h>
#include <pthread.h>
#include "lvgl/lvgl.h"
#include "custom_ticks.h"

#define CUSTOM_TICKS_MS		20

static pthread_t s_pt = -1;
static const int s_nsec = CUSTOM_TICKS_MS * 1000000;

static void *custom_ticks_inc(void *arg);

int custom_ticks_init(void)
{
	return pthread_create(&s_pt, NULL, custom_ticks_inc, NULL);
}

void custom_ticks_deinit(void)
{
	if (s_pt != -1) {
		pthread_cancel(s_pt);
		pthread_join(s_pt, NULL);
	}
}

static void *custom_ticks_inc(void *arg)
{
	(void)arg;

	struct timespec ts, te = {0, 0};
	while (1) {
		clock_gettime(CLOCK_MONOTONIC, &ts);

		if ((ts.tv_sec == te.tv_sec && ts.tv_nsec > te.tv_nsec) \
						|| (ts.tv_sec > te.tv_sec)) {
			te = ts;

			te.tv_nsec += s_nsec;
			if (te.tv_nsec >= 1000000000) {
				te.tv_nsec -= 1000000000;
				te.tv_sec += 1;
			}
		} else {
			clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &te, NULL);
			lv_tick_inc(CUSTOM_TICKS_MS);
		}
	}

	return (void*)0;
}

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

int custom_init(void)
{
#if !LV_TICK_CUSTOM
	if (custom_ticks_init() != 0) 
		return -1;
#endif

	custom_disp_init();
	custom_event_init();

	return 0;
}

void custom_deinit(void)
{
	custom_event_deinit();
	custom_disp_deinit();
#if !LV_TICK_CUSTOM
	custom_ticks_deinit();
#endif
}

/**
 * @file	main.c
 * @author	Colin X
 * @date	Thu Jan 15 20:06:41 2026
 * @description:
 */
#include <signal.h>
#include <unistd.h>
#include "lvgl/lvgl.h"
#include "custom/custom.h"
#include "ui/ui.h"

static int s_signal = 0;
static void signal_handler(int signal) { s_signal = 1; }

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	signal(SIGTERM, signal_handler);
	signal(SIGINT, signal_handler);

	lv_init();
	custom_init();
	ui_init();

	while (!s_signal) {
		uint32_t ms = lv_timer_handler();
		custom_event_dequeue(ms);
	}

	ui_deinit();
	custom_deinit();
	lv_deinit();
	return 0;
}

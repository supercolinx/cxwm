#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "lvgl/lvgl.h"
#include "wm/wm.h"

static int s_signal = 0;
static void signal_handler(int signal)
{
	s_signal = signal;
}

static void lv_linux_init(int hor_res, int ver_res)
{
	lv_sdl_window_create(hor_res, ver_res);
	lv_sdl_mouse_create();
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <hor_res> <ver_res>\n", argv[0]);
		return -1;
	}

	signal(SIGINT, signal_handler);

	lv_init();
	lv_linux_init(atoi(argv[1]), atoi(argv[2]));

	while (!s_signal) {
		uint32_t delay = lv_timer_handler();
		if (delay < 1) delay = 1;
		usleep(delay * 1000);
	}

	lv_deinit();
	return 0;
}

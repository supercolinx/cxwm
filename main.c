#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "lvgl/lvgl.h"
#include "wm/wm.h"

/*
 * ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
 * ┃ Run dmenu to ask the user for their choice               ┃
 * ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
 */

static int s_signal = 0;
static void
signal_handler(int signal)
{
	s_signal = signal;
}

static void
lv_linux_init(int argc, char *argv[])
{
#if LV_USE_LINUX_FBDEV
	lv_display_t *disp = lv_linux_fbdev_create();
	if (disp) {
		lv_linux_fbdev_set_file(disp, "/dev/fb0");
	}
#elif LV_USE_SDL
	lv_sdl_window_create(
			argc > 1 ? atoi(argv[1]) : 1280,
			argc > 2 ? atoi(argv[2]) : 720
			);
	lv_sdl_mouse_create();
#else
#error "Unknown device!!!"
#endif
}

int
main(int argc, char *argv[])
{
	signal(SIGINT, signal_handler);

	lv_init();
	lv_linux_init(argc, argv);

	while (!s_signal) {
		uint32_t ms = lv_timer_handler();
		if (ms < 1) ms = 1;
		lv_delay_ms(ms);
	}

	lv_deinit();
	return 0;
}

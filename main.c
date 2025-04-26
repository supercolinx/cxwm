#include <unistd.h>
#include <signal.h>
#include "lvgl/lvgl.h"
#include "wm/wm.h"

static int s_signal = 0;
static void signal_handler(int signal)
{
	s_signal = signal;
}

static void lv_linux_init(void)
{
	lv_sdl_window_create(1280, 480);
	lv_sdl_mouse_create();
}

int main(void)
{
	signal(SIGINT, signal_handler);

	lv_init();
	lv_linux_init();

	mainwindow_start(lv_screen_active());
	while (!s_signal) {
		uint32_t delay = lv_timer_handler();
		if (delay < 1) delay = 1;
		usleep(delay * 1000);
	}

	lv_deinit();
	return 0;
}

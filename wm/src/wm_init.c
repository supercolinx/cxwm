#include "wm_main.h"
#include "wm_init.h"

void
wm_init(void)
{
	(void) wm_main_init(lv_screen_active());
}

void
wm_deinit(void)
{
}

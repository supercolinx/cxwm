#include "themes/wm_theme_screen.h"
#include "wm_bar.h"
#include "wm_window.h"
#include "wm_init.h"

void
wm_init(void)
{
	lv_obj_t *root = wm_theme_screen_init(lv_screen_active());
	(void) wm_bar_init(root);
	(void) wm_window_init(root);
}

void
wm_deinit(void)
{
}

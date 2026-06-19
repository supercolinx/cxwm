/**
 * @file	custom_disp.c
 * @author	Colin X
 * @date	Wed Jun 10 21:35:40 2026
 * @description:
*/

#include "lvgl/lvgl.h"
#include "lv_drivers/lv_drivers.h"
#include "custom_disp.h"

#if LV_USE_SDL
static void custom_disp_sdl_init(void);
#endif

void custom_disp_init(void)
{
#if LV_USE_SDL
	custom_disp_sdl_init();
#else
#error "custom_disp_init failed"
#endif
}

void custom_disp_deinit(void)
{
}

static void custom_disp_sdl_init(void)
{
	sdl_init();

	static lv_disp_drv_t disp_drv;
	static lv_disp_draw_buf_t disp_buf;
	static lv_color_t buf1_1[LV_HOR_RES * LV_VER_RES];
	static lv_color_t buf1_2[LV_HOR_RES * LV_VER_RES];
	lv_disp_draw_buf_init(&disp_buf, buf1_1, buf1_2, LV_HOR_RES * LV_VER_RES);

	lv_disp_drv_init(&disp_drv);
	disp_drv.draw_buf = &disp_buf;
	disp_drv.flush_cb = sdl_display_flush;
	disp_drv.direct_mode = 1;
	disp_drv.hor_res = LV_HOR_RES;
	disp_drv.ver_res = LV_VER_RES;
	(void) lv_disp_drv_register(&disp_drv);

	static lv_indev_drv_t indev_mouse;
	lv_indev_drv_init(&indev_mouse);
	indev_mouse.type = LV_INDEV_TYPE_POINTER;
	indev_mouse.read_cb = sdl_mouse_read;
	(void) lv_indev_drv_register(&indev_mouse);
}

/**
 * @file	screen.c
 * @author	Colin X
 * @date	Sat Jan 17 17:15:08 2026
 * @description:
*/

#include "ui_manager.h"
#include "ui_common.h"

static void screen_callback(const unsigned int *events, int count)
{
	for (int i = 0; i < count; ++i) {
		LV_LOG_USER("event = %u", events[i]);
	}
}

static void screen_event(lv_event_t *e)
{
	(void)custom_event_enqueue(lv_event_get_code(e));
}

void screen_create(struct ui_manager *ui)
{
	struct screen *scr = screen_get(ui);

	if (!ui->auto_del && scr->obj)
		return;

	custom_event_set_callback(screen_callback);/*NOTE*/

	scr->obj = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(scr->obj, LV_SCROLLBAR_MODE_OFF);
	lv_obj_set_style_bg_img_src(scr->obj, UI_IMG_BMP_PATH(bg, LV_HOR_RES, LV_VER_RES), LV_PART_MAIN);
	lv_obj_set_scroll_dir(scr->obj, LV_DIR_HOR);

	lv_obj_set_flex_flow(scr->obj, LV_FLEX_FLOW_ROW);
	lv_obj_set_flex_align(scr->obj, LV_FLEX_ALIGN_START, \
			LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_SPACE_EVENLY);

	char buf[256];
	for (int i = 0; i < 25; ++i) {
		lv_obj_t *obj = lv_img_create(scr->obj);
		lv_snprintf(buf, 64, "%s%03d.png", UI_IMG_PATH(emotes/emoji_), i);
		lv_img_set_src(obj, buf);
		lv_img_set_zoom(obj, 256);
		lv_img_set_size_mode(obj, LV_IMG_SIZE_MODE_REAL);
		//lv_obj_set_size(obj, 240, 240);
		lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
		lv_obj_add_event_cb(obj, screen_event, LV_EVENT_CLICKED, NULL);
		scr->icons[i] = obj;
	}
}

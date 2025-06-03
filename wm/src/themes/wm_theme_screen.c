#include "wm_theme_screen.h"

lv_obj_t*
wm_theme_screen_init(lv_obj_t *obj)
{
	lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_COLUMN);
	lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_START, 0);
	lv_obj_set_style_pad_row(obj, 20, 0);
	lv_obj_set_style_bg_color(obj, lv_color_black(), 0);
	lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
	return obj;
}

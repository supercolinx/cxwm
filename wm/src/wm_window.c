#include "wm_window.h"

struct _this {
	lv_obj_t *self;
	lv_obj_t *demo_obj;
};

static void
wm_window_deinit(lv_event_t *e)
{
	struct _this *this = (struct _this*) lv_event_get_user_data(e);
	if (this) {
		free(this);
	}
	LV_LOG_USER("end now");
}

static void
wm_window_style_init(lv_obj_t *obj)
{
	lv_obj_set_width(obj, LV_PCT(100));
	lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, 0);
	lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, 0);
	lv_obj_set_style_bg_color(obj, lv_color_black(), 0);
	lv_obj_set_flex_grow(obj, 1);
}

void*
wm_window_init(lv_obj_t *parent)
{
	struct _this *this = (struct _this*) malloc(sizeof(struct _this));
	if (this) {
		this->self = lv_obj_create(parent);
		wm_window_style_init(this->self);

		lv_obj_add_event_cb(this->self, wm_window_deinit,
				LV_EVENT_DELETE, this);
	}

	return this;
}

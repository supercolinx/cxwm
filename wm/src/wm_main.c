#include <stdlib.h>
#include "wm_main.h"

struct _this {
	lv_obj_t *self;
};

static void
wm_main_deinit(lv_event_t *event)
{
	struct _this *this = (struct _this*) lv_event_get_user_data(event);
	if (this) free(this);
	LV_LOG_USER("end now");
}

static void
wm_main_set_style(lv_obj_t *obj)
{
}

lv_obj_t*
wm_main_init(lv_obj_t *parent)
{
	struct _this *this = (struct _this*) malloc(sizeof(struct _this));
	if (this) {
		this->self = lv_obj_create(parent);
		wm_main_set_style(this->self);

		lv_obj_add_event_cb(this->self, wm_main_deinit,
				LV_EVENT_DELETE, this);

		return this->self;
	}

	return NULL;
}

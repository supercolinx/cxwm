/**
 * @file	ui_manager.h
 * @author	Colin X
 * @date	Sat Jan 17 15:24:22 2026
 * @description:
*/
#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include "lvgl/lvgl.h"
#include "custom/custom.h"
#include <string.h>

struct screen {
	lv_obj_t *obj;
	lv_obj_t *icons[25];
};

struct ui_manager {
	char auto_del;
	struct screen screen;
};

static inline void ui_manager_init(struct ui_manager *ui, char auto_del)
{
	lv_memset_00(ui, sizeof(struct ui_manager));
	ui->auto_del = auto_del;
}

static inline struct screen *screen_get(struct ui_manager *ui)
{
	return &ui->screen;
}

void screen_create(struct ui_manager *ui);

extern struct ui_manager ui_manager;

#endif /*UI_MANAGER_H*/

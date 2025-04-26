#include "mainwindow.h"

#define BACKGROUND lv_color_hex(0x000000)

void*
mainwindow_start(lv_obj_t *parent)
{
	lv_obj_t *slider = lv_slider_create(parent);
	lv_obj_center(slider);

	return NULL;
}

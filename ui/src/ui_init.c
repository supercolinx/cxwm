/**
 * @file	ui_init.c
 * @author	Colin X
 * @date	Sat Jan 17 11:41:22 2026
 * @description:
*/
#include "ui_init.h"

struct ui_manager ui_manager;

void ui_init(void)
{
	ui_manager_init(&ui_manager, 1);
	
	screen_create(&ui_manager);
	lv_scr_load(screen_get(&ui_manager)->obj);
}

void ui_deinit(void)
{
}

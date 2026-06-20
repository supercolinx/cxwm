/**
 * @file	custom_ticks.h
 * @author	Colin X
 * @date	Wed Jun 10 21:46:16 2026
 * @description:
*/
#ifndef _CUSTOM_TICKS_H
#define _CUSTOM_TICKS_H
#include "lvgl/lvgl.h"

#if !LV_TICK_CUSTOM

/**
 * @function: custom_ticks_init
 * @date: Wed Jun 10 21:47:06 2026
 * @description: 
 * @return: On success, the zero is returned. On error, an error number is returned.
 */
int custom_ticks_init(void);

/**
 * @function: custom_ticks_deinit
 * @date: Wed Jun 10 22:13:22 2026
 * @description: 
 * @return: void
 */
void custom_ticks_deinit(void);

#endif /*!LV_TICK_CUSTOM*/

#endif /*_CUSTOM_TICKS_H*/

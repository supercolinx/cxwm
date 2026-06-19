/**
 * @file	ui_common.h
 * @author	Colin X
 * @date	Mon Jan 19 19:43:12 2026
 * @description:
*/
#ifndef UI_COMMON_H
#define UI_COMMON_H

#include "lvgl/lvgl.h"

#define UI_RESOURCES "L:./resources"

#define CONN(x,y) x#y
#define UI_IMG_PATH(y) CONN(UI_RESOURCES"/image/",y)

#define _STR(x) #x
#define STR(x) _STR(x)
#define UI_IMG_BMP_PATH(name,w,h) UI_RESOURCES"/image/"STR(name)STR(w)"x"STR(h)".bmp"
#define UI_IMG_PNG_PATH(name,w,h) UI_RESOURCES"/image/"STR(name)STR(w)"x"STR(h)".png"

#endif /*UI_COMMON_H*/

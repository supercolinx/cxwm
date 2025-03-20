/**
 * @file cx_main.c
 * @date Wed Dec  4 21:10:19 CST 2024
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <time.h>
#include "cx_main.h"

/*********************
 *      DEFINES
 *********************/
#define THIS_PAD_ALL 5
#define THIS_PAD_GAP 5

#define THIS_SUBLABELS_MAX 9

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void cx_main_init(void);
static void cx_main_deinit(lv_event_t *e);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t *this = NULL;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void *cx_main_start(lv_obj_t *parent)
{
	this = parent;
	if (NULL != this) {
		cx_main_init();
	}
	return this;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void cx_main_init(void)
{
	lv_obj_add_event_cb(this, cx_main_deinit, LV_EVENT_DELETE, NULL);
}

static void cx_main_deinit(lv_event_t *e)
{
	LV_LOG_USER("[%s] be deleted", __func__);
	this = NULL;
}

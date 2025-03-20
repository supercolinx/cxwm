#!/bin/sh
#Author: xiekangli

ROOT_PATH=$(pwd .)
BASE_HEAD=cx
BASE_NAME=$1

make_help()
{
	if [ "$1" == "" ]; then
		echo "Try sh $0 [file basename]"
		exit 1
	fi
}

make_check()
{
	if [ -f ${ROOT_PATH}/${BASE_HEAD}_${BASE_NAME}.$1 ]; then
		echo "${BASE_HEAD}_${BASE_NAME}.$1 is exist!"
		exit 1
	fi
}

make_head()
{
	make_check h
	echo "/**
 * @file ${BASE_HEAD}_${BASE_NAME}.h
 * @date $(date)
 */

#ifndef ${BASE_HEAD^^}_${BASE_NAME^^}_H
#define ${BASE_HEAD^^}_${BASE_NAME^^}_H

#ifdef __cplusplus
extern \"C\" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include \"lvgl.h\"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void *${BASE_HEAD}_${BASE_NAME}_start(lv_obj_t *parent);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern \"C\" */
#endif

#endif /* ${BASE_HEAD}_${BASE_NAME^^}_H */" > ${ROOT_PATH}/${BASE_HEAD}_${BASE_NAME}.h
}

make_source()
{
	make_check c
	echo "/**
 * @file ${BASE_HEAD}_${BASE_NAME}.c
 * @date $(date)
 */

/*********************
 *      INCLUDES
 *********************/
#include \"${BASE_HEAD}_${BASE_NAME}.h\"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void ${BASE_HEAD}_${BASE_NAME}_init(void);
static void ${BASE_HEAD}_${BASE_HEAD}_deinit(lv_event_t *e);

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
void *${BASE_HEAD}_${BASE_NAME}_start(lv_obj_t *parent)
{
	this = lv_obj_create(parent);
	if (NULL != this) {
		${BASE_HEAD}_${BASE_NAME}_init();
	}
	return this;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void ${BASE_HEAD}_${BASE_NAME}_init(void)
{
	lv_obj_add_event_cb(this, ${BASE_HEAD}_${BASE_NAME}_deinit, LV_EVENT_DELETE, NULL);
}

static void ${BASE_HEAD}_${BASE_HEAD}_deinit(lv_event_t *e)
{
	LV_LOG_USER("[%s] be deleted", __func__);
	this = NULL;
}" > ${ROOT_PATH}/${BASE_HEAD}_${BASE_NAME}.c
}

main()
{
	make_help $1
	make_head
	make_source
}

main $@

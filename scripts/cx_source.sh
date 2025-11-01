#!/bin/sh
# @file		cx_source.sh
# @author	Colin X
# @data		Sat Nov  1 08:23:25 2025
# @description:

func_create_header()
{
	echo -e "/**
 * @file	cx_$1.h
 * @author	Colin X
 * @date	$(date +%c)
 * @description:
 */
#ifndef CX_${1^^}_H
#define CX_${1^^}_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#if CX_USE_${1^^}

/*Testing of dependencies*/

/*********************
 *      DEFINES
 *********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create an empty $1
 * @param parent\tthe parent or NULL to create a modal $1
 * @return\t\tthe created ${1:0:1}${1:3}
 */
cx_obj_t *cx_$1_create(cx_obj_t *parent);

/**
 * Close a $1
 * @param ${1:0:1}${1:3}\t\tpointer to a $1
 */
void cx_$1_close(cx_obj_t *${1:0:1}${1:3});

/**
 * Close a $1 in the next call of the $1
 * @param ${1:0:1}${1:3}\t\tpointer to a $1
 */
void cx_$1_close_async(cx_obj_t *${1:0:1}${1:3});

/**********************
 *      MACROS
 **********************/

#endif /*CX_USE_${1^^}*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*CX_${1^^}_H*/
" > cx_$1.h
}

func_create_source()
{
	echo -e "/**
 * @file	cx_$1.c
 * @author	Colin X
 * @date	$(date +%c)
 * @description:
 */

/*********************
 *      INCLUDES
 *********************/

#if CX_USE_${1^^}

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

cx_obj_t *cx_$1_create(cx_obj_t *parent)
{
	return NULL;
}

void cx_$1_close(cx_obj_t *${1:0:1}${1:3})
{
}

void cx_$1_close_async(cx_obj_t *${1:0:1}${1:3})
{
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /*CX_USE_${1^^}*/
" > cx_$1.c
}

func_create_header $@
func_create_source $@

/**
 * @file cxwm.h
 * Include all CXWM related headers
 */

#ifndef CXWM_H
#define CXWM_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************
 * CURRENT VERSION OF CXWM
 ***************************/
#include "cx_version.h"

/*********************
 *      INCLUDES
 *********************/

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

#define CX_VERSION_CHECK(x,y,z) (x == CX_VERSION_MAJOR && (y < CX_VERSION_MINOR || (y == CX_VERSION_MINOR && z <= CX_VERSION_PATCH)))

/**
 * Wrapper functions for VERSION macros
 */

static inline int cx_version_major(void)
{
    return CX_VERSION_MAJOR;
}

static inline int cx_version_minor(void)
{
    return CX_VERSION_MINOR;
}

static inline int cx_version_patch(void)
{
    return CX_VERSION_PATCH;
}

static inline const char * cx_version_info(void)
{
    return CX_VERSION_INFO;
}

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*CXWM_H*/

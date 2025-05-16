/**
 * @file wm.h
 * Include all WM related headers
 */

#ifndef WM_H
#define WM_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************
 * CURRENT VERSION OF WM
 ***************************/
#include "wm_version.h"

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
extern void wm_init(void);
extern void wm_deinit(void);

/**********************
 *      MACROS
 **********************/

#define WM_VERSION_CHECK(x,y,z) (x == WM_VERSION_MAJOR && (y < WM_VERSION_MINOR || (y == WM_VERSION_MINOR && z <= WM_VERSION_PATCH)))

/**
 * Wrapper functions for VERSION macros
 */

static inline int wm_version_major(void)
{
    return WM_VERSION_MAJOR;
}

static inline int wm_version_minor(void)
{
    return WM_VERSION_MINOR;
}

static inline int wm_version_patch(void)
{
    return WM_VERSION_PATCH;
}

static inline const char * wm_version_info(void)
{
    return WM_VERSION_INFO;
}

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WM_H*/

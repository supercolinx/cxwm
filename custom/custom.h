/**
 * @file	custom.h
 * @author	Colin X
 * @date	Wed Apr 22 21:40:21 2026
 * @description:
*/
#ifndef CUSTOM_H
#define CUSTOM_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************
 * CURRENT VERSION OF CUSTOM
 ***************************/
#define CUSTOM_VERSION_MAJOR 0
#define CUSTOM_VERSION_MINOR 0
#define CUSTOM_VERSION_PATCH 1
#define CUSTOM_VERSION_INFO ""

/*********************
 *      INCLUDES
 *********************/
#include "src/custom.h"

/*-----------------
 * EXTRAS
 *----------------*/


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

/** Gives 1 if the x.y.z version is supported in the current version
 * Usage:
 *
 * - Require v6
 * #if CUSTOM_VERSION_CHECK(6,0,0)
 *   new_func_in_v6();
 * #endif
 *
 *
 * - Require at least v5.3
 * #if CUSTOM_VERSION_CHECK(5,3,0)
 *   new_feature_from_v5_3();
 * #endif
 *
 *
 * - Require v5.3.2 bugfixes
 * #if CUSTOM_VERSION_CHECK(5,3,2)
 *   bugfix_in_v5_3_2();
 * #endif
 *
 */
#define CUSTOM_VERSION_CHECK(x,y,z) (x == CUSTOM_VERSION_MAJOR && (y < CUSTOM_VERSION_MINOR || (y == CUSTOM_VERSION_MINOR && z <= CUSTOM_VERSION_PATCH)))

/**
 * Wrapper functions for VERSION macros
 */

static inline int custom_version_major(void)
{
    return CUSTOM_VERSION_MAJOR;
}

static inline int custom_version_minor(void)
{
    return CUSTOM_VERSION_MINOR;
}

static inline int custom_version_patch(void)
{
    return CUSTOM_VERSION_PATCH;
}

static inline const char *custom_version_info(void)
{
    return CUSTOM_VERSION_INFO;
}

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*CUSTOM_H*/

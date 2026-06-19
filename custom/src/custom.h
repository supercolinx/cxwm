/**
 * @file	custom.h
 * @author	Colin X
 * @date	Thu May 28 21:08:44 2026
 * @description:
*/
#ifndef _CUSTOM_H
#define _CUSTOM_H

/**
 * @function: custom_init
 * @date: Wed Jun 10 21:27:05 2026
 * @description: 
 * @return: void
 */
int custom_init(void);

/**
 * @function: custom_deinit
 * @date: Wed Jun 10 21:27:08 2026
 * @description: 
 * @return: void
 */
void custom_deinit(void);

/**
 * @function: custom_event_set_callback
 * @date: Fri Jun 19 10:30:14 2026
 * @description: 
 * @return: void
 */
void __attribute__((weak)) custom_event_set_callback(void (*cb)(const unsigned int*, int));

/**
 * @function: custom_event_dequeue
 * @date: Fri Jun 19 09:55:43 2026
 * @description: 
 * @return: void
 */
void __attribute__((weak)) custom_event_dequeue(int timeout);

/**
 * @function: custom_event_enqueue
 * @date: Fri Jun 19 09:55:46 2026
 * @description: 
 * @return: On success, the zero is returned. On error, -1 is returned.
 */
int __attribute__((weak)) custom_event_enqueue(const unsigned int event);
#endif /*_CUSTOM__H*/

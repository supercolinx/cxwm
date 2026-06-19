/**
 * @file	custom_event.h
 * @author	Colin X
 * @date	Thu Jun 18 23:22:44 2026
 * @description:
*/
#ifndef _CUSTOM_EVENT_H
#define _CUSTOM_EVENT_H

typedef unsigned int custom_event_t;
typedef void (*custom_event_cb_t)(const custom_event_t *, int);

/**
 * @function: custom_event_init
 * @date: Thu Jun 18 23:24:05 2026
 * @description: 
 * @return: On success, the zero is returned. On error, -1 is returned.
 */
int custom_event_init(void);

/**
 * @function: custom_event_deinit
 * @date: Fri Jun 19 00:01:29 2026
 * @description: 
 * @return: void
 */
void custom_event_deinit(void);

/**
 * @function: custom_event_set_callback
 * @date: Fri Jun 19 10:13:43 2026
 * @description: 
 * @return: On success, the zero is returned. On error, -1 is returned.
 */
void custom_event_set_callback(custom_event_cb_t cb);

/**
 * @function: custom_event_handler
 * @date: Fri Jun 19 00:02:14 2026
 * @description: 
 * @return: void
 */
void custom_event_dequeue(int timeout);

/**
 * @function: custom_event_enqueue
 * @date: Fri Jun 19 01:07:58 2026
 * @description: 
 * @return: On success, the zero is returned. On error, -1 is returned.
 */
int custom_event_enqueue(const custom_event_t event);

#endif /*_CUSTOM_EVENT_H*/

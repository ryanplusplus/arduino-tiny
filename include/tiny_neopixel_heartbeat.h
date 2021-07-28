/*!
 * @file
 * @brief
 */

#ifndef tiny_neopixel_heartbeat_h
#define tiny_neopixel_heartbeat_h

#ifdef __cplusplus
extern "C" {
#endif

#include "tiny_timer.h"

void tiny_neopixel_heartbeat_init(tiny_timer_group_t* timer_group, tiny_timer_ticks_t period);

#ifdef __cplusplus
}
#endif

#endif

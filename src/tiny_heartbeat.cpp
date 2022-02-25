/*!
 * @file
 * @brief
 */

#include <Arduino.h>

extern "C" {
#include "tiny_heartbeat.h"
}

static tiny_timer_t timer;

#ifdef LED_BUILTIN
#include "tiny_digital_output.h"

static tiny_digital_output_t led;

static void blink(tiny_timer_group_t* timer_group, void* context)
{
  (void)timer_group;
  (void)context;
  static bool state;
  tiny_digital_output_write(&led.interface, state = !state);
}

void tiny_heartbeat_init(tiny_timer_group_t* timer_group, tiny_timer_ticks_t period)
{
  tiny_digital_output_init(&led, LED_BUILTIN);
  tiny_timer_start_periodic(timer_group, &timer, period / 2, NULL, blink);
}

#endif

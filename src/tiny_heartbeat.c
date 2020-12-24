/*!
 * @file
 * @brief
 */

#include <Arduino.h>
#include "tiny_heartbeat.h"
#include "tiny_digital_output.h"

static tiny_digital_output_t led;
static tiny_timer_t timer;

static void blink(tiny_timer_group_t* timer_group, void* context) {
  (void)timer_group;
  static bool state;
  tiny_digital_output_write(&led.interface, state = !state);
}

void tiny_heartbeat_init(tiny_timer_group_t* timer_group, tiny_timer_ticks_t period) {
  tiny_digital_output_init(&led, LED_BUILTIN);
  tiny_timer_start_periodic(timer_group, &timer, period / 2, blink, NULL);
}

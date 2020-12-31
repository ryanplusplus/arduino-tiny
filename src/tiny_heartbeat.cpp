/*!
 * @file
 * @brief
 */

#include <Arduino.h>

extern "C" {
#include "tiny_heartbeat.h"
}

static tiny_timer_t timer;

#ifdef PIN_NEOPIXEL
#include <Adafruit_NeoPixel.h>

static Adafruit_NeoPixel pixel(1, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

static void blink(tiny_timer_group_t* timer_group, void* context)
{
  (void)timer_group;
  (void)context;
  static bool state;
  pixel.setPixelColor(0, pixel.Color(0, state = !state, 0));
  pixel.show();
}

void tiny_heartbeat_init(tiny_timer_group_t* timer_group, tiny_timer_ticks_t period)
{
  pixel.begin();
  tiny_timer_start_periodic(timer_group, &timer, period / 2, blink, NULL);
}
#else
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
  tiny_timer_start_periodic(timer_group, &timer, period / 2, blink, NULL);
}
#endif

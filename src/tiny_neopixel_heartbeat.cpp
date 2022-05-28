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

static void blink(void* context)
{
  (void)context;
  static bool state;
  pixel.setPixelColor(0, pixel.Color(0, state = !state, 0));
  pixel.show();
}

void tiny_neopixel_heartbeat_init(tiny_timer_group_t* timer_group, tiny_timer_ticks_t period)
{
  pixel.begin();
  tiny_timer_start_periodic(timer_group, &timer, period / 2, NULL, blink);
}
#endif

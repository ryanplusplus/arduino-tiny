/*!
 * @file
 * @brief
 */

#include "Arduino.h"
#include "tiny_time_source.h"

static tiny_time_source_ticks_t ticks(i_tiny_time_source_t* self) {
  return (tiny_time_source_ticks_t)millis();
}

static const i_tiny_time_source_api_t api = { ticks };

i_tiny_time_source_t* tiny_time_source_init(void) {
  static i_tiny_time_source_t self;
  self.api = &api;
  return &self;
}

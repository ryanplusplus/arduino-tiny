/*!
 * @file
 * @brief
 */

#include <Arduino.h>
#include "tiny_analog_output.h"
#include "tiny_utils.h"

static void write(i_tiny_analog_output_t* _self, tiny_analog_output_counts_t value) {
  reinterpret(self, _self, tiny_analog_output_t*);
  analogWrite(self->_private.pin, value << 8);
}

static const i_tiny_analog_output_api_t api = { write };

void tiny_analog_output_init(tiny_analog_output_t* self, uint8_t pin) {
  self->_private.pin = pin;
  self->interface.api = &api;
  pinMode(pin, OUTPUT);
}

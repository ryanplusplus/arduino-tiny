/*!
 * @file
 * @brief
 */

#include <Arduino.h>
#include "tiny_analog_input.h"
#include "tiny_utils.h"

static tiny_analog_input_counts_t read(i_tiny_analog_input_t* _self)
{
  reinterpret(self, _self, tiny_analog_input_t*);
  return analogRead(self->_private.pin) << 8;
}

static const i_tiny_analog_input_api_t api = { read };

void tiny_analog_input_init(tiny_analog_input_t* self, uint8_t pin)
{
  self->_private.pin = pin;
  self->interface.api = &api;
  pinMode(pin, INPUT);
}

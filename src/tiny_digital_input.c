/*!
 * @file
 * @brief
 */

#include <Arduino.h>
#include "tiny_digital_input.h"
#include "tiny_utils.h"

static bool read(i_tiny_digital_input_t* _self)
{
  reinterpret(self, _self, tiny_digital_input_t*);
  return digitalRead(self->_private.pin);
}

static const i_tiny_digital_input_api_t api = { read };

void tiny_digital_input_init(tiny_digital_input_t* self, uint8_t pin, uint8_t mode)
{
  self->_private.pin = pin;
  self->interface.api = &api;
  pinMode(pin, mode);
}

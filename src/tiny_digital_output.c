/*!
 * @file
 * @brief
 */

#include "Arduino.h"
#include "tiny_digital_output.h"
#include "tiny_utils.h"

static void write(i_tiny_digital_output_t* _self, bool value) {
  reinterpret(self, _self, tiny_digital_output_t*);
  digitalWrite(self->_private.pin, value);
}

static const i_tiny_digital_output_api_t api = { write };

void tiny_digital_output_init(tiny_digital_output_t* self, uint8_t pin) {
  self->_private.pin = pin;
  self->interface.api = &api;
  pinMode(pin, OUTPUT);
}

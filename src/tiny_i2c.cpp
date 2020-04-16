/*!
 * @file
 * @brief
 */

#include <Arduino.h>
#include <Wire.h>
#include "tiny_i2c.h"
#include "tiny_utils.h"

static bool write(
  i_tiny_i2c_t* _self,
  uint8_t address,
  bool prepare_for_restart,
  const uint8_t* buffer,
  uint16_t buffer_size) {
  reinterpret(self, _self, tiny_i2c_t*);
  (void)prepare_for_restart;

  Wire.setClock(self->_private.speed);
  Wire.beginTransmission(address);

  return buffer_size == Wire.write(buffer, buffer_size);
}

static bool read(
  i_tiny_i2c_t* _self,
  uint8_t address,
  bool prepare_for_restart,
  uint8_t* buffer,
  uint16_t buffer_size) {
  reinterpret(self, _self, tiny_i2c_t*);
  (void)prepare_for_restart;

  Wire.setTimeout(self->_private.timeout);
  Wire.setClock(self->_private.speed);
  Wire.beginTransmission(address);

  return buffer_size == Wire.readBytes(buffer, buffer_size);
}

static const i_tiny_i2c_api_t api = { write, read };

extern "C" void tiny_i2c_init(tiny_i2c_t* self, tiny_i2c_speed_t speed, unsigned long timeout) {
  self->interface.api = &api;
  self->_private.speed = speed;
  self->_private.timeout = timeout;

  Wire.begin();
}

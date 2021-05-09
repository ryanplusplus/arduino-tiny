/*!
 * @file
 * @brief
 */

#include <Arduino.h>
#include <SPI.h>
#include "tiny_spi.h"
#include "tiny_utils.h"

static void transfer(i_tiny_spi_t* _self, const void* _write_buffer, void* _read_buffer, uint16_t buffer_size)
{
  reinterpret(self, _self, tiny_spi_t*);
  reinterpret(write_buffer, _write_buffer, const uint8_t*);
  reinterpret(read_buffer, _read_buffer, uint8_t*);

  SPI.beginTransaction(
    SPISettings(
      self->_private.baud,
      static_cast<decltype(MSBFIRST)>(self->_private.bitOrder),
      self->_private.mode));

  for(uint16_t i = 0; i < buffer_size; i++) {
    uint8_t read = SPI.transfer(write_buffer ? write_buffer[i] : 0);

    if(read_buffer) {
      read_buffer[i] = read;
    }
  }

  SPI.endTransaction();
}

static const i_tiny_spi_api_t api = { transfer };

extern "C" void tiny_spi_init(tiny_spi_t* self, uint32_t baud, uint8_t bitOrder, uint8_t mode)
{
  self->interface.api = &api;
  self->_private.baud = baud;
  self->_private.bitOrder = bitOrder;
  self->_private.mode = mode;

  SPI.begin();
}

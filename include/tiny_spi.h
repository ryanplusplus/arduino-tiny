/*!
 * @file
 * @brief Wrap's Arduino's SPI.
 */

#ifndef tiny_spi_h
#define tiny_spi_h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "hal/i_tiny_spi.h"

typedef struct {
  i_tiny_spi_t interface;

  struct {
    uint32_t baud;
    uint8_t bitOrder;
    uint8_t mode;
  } _private;
} tiny_spi_t;

void tiny_spi_init(tiny_spi_t* self, uint32_t baud, uint8_t bitOrder, uint8_t mode);

#ifdef __cplusplus
}
#endif

#endif

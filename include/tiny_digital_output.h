/*!
 * @file
 * @brief Wraps an Arduino digital output.
 */

#ifndef tiny_digital_output_h
#define tiny_digital_output_h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "hal/i_tiny_digital_output.h"

typedef struct {
  i_tiny_digital_output_t interface;

  struct {
    uint8_t pin;
  } _private;
} tiny_digital_output_t;

void tiny_digital_output_init(tiny_digital_output_t* self, uint8_t pin);

#ifdef __cplusplus
}
#endif

#endif

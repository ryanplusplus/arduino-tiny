/*!
 * @file
 * @brief Wraps an Arduino analog output.
 */

#ifndef tiny_analog_output_h
#define tiny_analog_output_h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "hal/i_tiny_analog_output.h"

typedef struct {
  i_tiny_analog_output_t interface;

  struct {
    uint8_t pin;
  } _private;
} tiny_analog_output_t;

void tiny_analog_output_init(tiny_analog_output_t* self, uint8_t pin);

#ifdef __cplusplus
}
#endif

#endif

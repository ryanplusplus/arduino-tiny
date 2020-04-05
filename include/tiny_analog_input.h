/*!
 * @file
 * @brief Wraps an Arduino analog input.
 */

#ifndef tiny_analog_input_h
#define tiny_analog_input_h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "hal/i_tiny_analog_input.h"

typedef struct {
  i_tiny_analog_input_t interface;

  struct {
    uint8_t pin;
  } _private;
} tiny_analog_input_t;

void tiny_analog_input_init(tiny_analog_input_t* self, uint8_t pin);

#ifdef __cplusplus
}
#endif

#endif

/*!
 * @file
 * @brief Wraps an Arduino digital input.
 */

#ifndef tiny_digital_input_h
#define tiny_digital_input_h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "hal/i_tiny_digital_input.h"

typedef struct {
  i_tiny_digital_input_t interface;

  struct {
    uint8_t pin;
  } _private;
} tiny_digital_input_t;

void tiny_digital_input_init(tiny_digital_input_t* self, uint8_t pin, uint8_t pin_mode);

#ifdef __cplusplus
}
#endif

#endif

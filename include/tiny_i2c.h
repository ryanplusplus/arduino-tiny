/*!
 * @file
 * @brief
 */

#ifndef tiny_i2c_h
#define tiny_i2c_h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "hal/i_tiny_i2c.h"

enum {
  tiny_i2c_speed_low = 10000,
  tiny_i2c_speed_standard = 100000,
  tiny_i2c_speed_fast = 400000,
  tiny_i2c_speed_fast_plus = 1000000,
  tiny_i2c_speed_high = 3400000
};
typedef uint32_t tiny_i2c_speed_t;

typedef struct {
  i_tiny_i2c_t interface;

  struct {
    tiny_i2c_speed_t speed;
    unsigned long timeout;
  } _private;
} tiny_i2c_t;

void tiny_i2c_init(tiny_i2c_t* self, tiny_i2c_speed_t speed, unsigned long timeout);

#ifdef __cplusplus
}
#endif

#endif

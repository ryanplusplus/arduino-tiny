/*!
 * @file
 * @brief Wrapper for Arduino's Serial1 UART.
 */

#ifndef tiny_uart1_h
#define tiny_uart1_h

#ifdef __cplusplus
extern "C" {
#endif

#include "hal/i_tiny_uart.h"
#include "tiny_timer.h"

i_tiny_uart_t* tiny_uart1_init(
  tiny_timer_group_t* timer_group,
  uint32_t baud,
  int mode);

#ifdef __cplusplus
}
#endif

#endif

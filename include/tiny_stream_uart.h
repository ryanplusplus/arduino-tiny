/*!
 * @file
 * @brief
 */

#ifndef tiny_stream_uart_hpp
#define tiny_stream_uart_hpp

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "hal/i_tiny_uart.h"
#include "tiny_event.h"
#include "tiny_timer.h"

typedef struct {
  i_tiny_uart_t interface;

  Stream* uart;
  i_tiny_uart_t self;
  tiny_event_t send_complete_event;
  tiny_event_t receive_event;
  tiny_timer_group_t* timer_group;
  tiny_timer_t timer;
  bool sent;
} tiny_stream_uart_t;

/*!
 * Initialize an adapter to expose an Arduino UART as an i_tiny_uart_t.
 */
void tiny_stream_uart_init(tiny_stream_uart_t* self, tiny_timer_group_t* timer_group, Stream& uart);

#ifdef __cplusplus
}
#endif

#endif

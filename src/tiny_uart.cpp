/*!
 * @file
 * @brief
 */

#include <Arduino.h>

extern "C" {
#include "tiny_uart.h"
#include "tiny_event.h"
}

static i_tiny_uart_t self;
static tiny_event_t send_complete_event;
static tiny_event_t receive_event;
static tiny_timer_group_t* timer_group;
static tiny_timer_t timer;
static bool sent;

static void poll(void* context)
{
  (void)context;

  int byte = Serial.read();
  if(byte != -1) {
    tiny_uart_on_receive_args_t args = { (uint8_t)byte };
    tiny_event_publish(&receive_event, &args);
  }

  if(sent) {
    sent = false;
    tiny_event_publish(&send_complete_event, NULL);
  }
}

static void send(i_tiny_uart_t* self, uint8_t byte)
{
  sent = true;
  Serial.write(byte);
}

static i_tiny_event_t* on_send_complete(i_tiny_uart_t* self)
{
  return &send_complete_event.interface;
}

static i_tiny_event_t* on_receive(i_tiny_uart_t* self)
{
  return &receive_event.interface;
}

static const i_tiny_uart_api_t api = { send, on_send_complete, on_receive };

extern "C" i_tiny_uart_t* tiny_uart_init(tiny_timer_group_t* _timer_group, uint32_t baud, int mode)
{
  timer_group = _timer_group;

  self.api = &api;

  tiny_event_init(&send_complete_event);
  tiny_event_init(&receive_event);

  Serial.begin(baud, static_cast<decltype(SERIAL_8N1)>(mode));

  tiny_timer_start_periodic(timer_group, &timer, 0, NULL, poll);

  return &self;
}

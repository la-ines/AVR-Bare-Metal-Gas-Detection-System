#ifndef UART_H_
#define UART_H_

#include <stdint.h>

#define BAUD 9600

#define BAUD_RATE  (F_CPU/16/BAUD - 1)
void UART_initialize(void);
void UART_Send_Char(uint8_t message);
void UART_Receive_Data(void);
void UART_Send_String(const char* str);



#endif /* UART_H_ */

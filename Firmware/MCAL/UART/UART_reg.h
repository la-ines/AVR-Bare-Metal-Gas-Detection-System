#ifndef UART_REG_H_
#define UART_REG_H_
#include <stdint.h>

#define UCSR0A_Reg        *((volatile uint8_t*)0xC0) //Control and Status A (TX complete, UDRE)
#define UCSR0B_Reg       *((volatile uint8_t*)0xC1) //Control and Status B (enable TX/RX)
#define UCSR0C_Reg        *((volatile uint8_t*)0xC2) //Control and Status C (frame format)
#define UBRR0L_Reg         *((volatile uint8_t*)0xC4) //Baud Rate Register Low Byte
#define UBRR0H_Reg         *((volatile uint8_t*)0xC5) //Baud Rate Register High Byte
#define UDR0_Reg          *((volatile uint8_t*)0xC6)  //USART I/O Data Register




#endif /* UART_REG_H_ */

#ifndef TWI_H_
#define TWI_H_

#include <stdint.h>
#include <avr/io.h>

// Function Prototypes
void I2C_init(void);
void I2C_start(void);
void I2C_stop(void);
void I2C_write(uint8_t data);
uint8_t I2C_readAck(void);
uint8_t I2C_readNack(void);

#endif // TWI_H_

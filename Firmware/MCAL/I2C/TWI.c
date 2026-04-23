#include "TWI.h"
#include "TWI_reg.h"
#include "Bit_Math.h"
#include "TWI.h"
#include "UART.h"

#include <stdint.h>
#include <stdio.h>
#define F_CPU 16000000UL

#include <util/delay.h>
#include <avr/io.h>

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL // Assume 16 MHz clock

// I2C initialization
void I2C_init(void) {
	// Set the I2C clock to 100kHz (using prescaler)
	TWSR = 0x00;         // No prescaler
	TWBR = 72;           // 16 MHz clock -> 100 kHz
}

// Start I2C communication
void I2C_start(void) {
	TWCR = (1 << TWSTA) | (1 << TWINT) | (1 << TWEN); // Send START condition
	while (!(TWCR & (1 << TWINT))); // Wait for TWINT flag set
}

// Stop I2C communication
void I2C_stop(void) {
	TWCR = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN); // Send STOP condition
	while (TWCR & (1 << TWSTO)); // Wait for stop condition to finish
}

// Send data byte via I2C
void I2C_write(uint8_t data) {
	TWDR = data; // Load data to TWDR register
	TWCR = (1 << TWINT) | (1 << TWEN); // Start transmission
	while (!(TWCR & (1 << TWINT))); // Wait for TWINT flag
}

// Read data from I2C
uint8_t I2C_readAck(void) {
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA); // Enable ACK after receiving data
	while (!(TWCR & (1 << TWINT))); // Wait for data to be received
	return TWDR; // Return received data
}

uint8_t I2C_readNack(void) {
	TWCR = (1 << TWINT) | (1 << TWEN); // Disable ACK
	while (!(TWCR & (1 << TWINT))); // Wait for data to be received
	return TWDR; // Return received data
}
			 

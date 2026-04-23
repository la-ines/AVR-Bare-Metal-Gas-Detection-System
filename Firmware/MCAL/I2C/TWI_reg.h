#ifndef TWI_REG_H_
#define TWI_REG_H_

#define TWBR_Reg        *((volatile uint8_t*)0xB8) //sets SCL frequency (speed of I2C)
#define TWSR_Reg       *((volatile uint8_t*)0xB9) //shows current TWI status (start,ACK,STOP..)
#define TWAR_Reg        *((volatile uint8_t*)0xBA) //sets the slave mode (only used when atmega is the slave)
#define TWDR_Reg         *((volatile uint8_t*)0xBB) // holds data to be transmitted or received
#define TWCR_Reg         *((volatile uint8_t*)0xBC) //main control register
#define TWAMR_Reg          *((volatile uint8_t*)0xBD)  //address matching in slave mode




#endif /* TWI_REG_H_ */

#ifndef DIO_REG_H_
#define DIO_REG_H_

#define PORTA_Reg   *((volatile unsigned char*)0x3B)
#define DDRA_Reg    *((volatile unsigned char*)0x3A)
#define PINA_Reg    *((volatile unsigned char*)0x39)

#define PORTB_Reg   *((volatile unsigned char*)0x25)
#define DDRB_Reg    *((volatile unsigned char*)0x24)
#define PINB_Reg    *((volatile unsigned char*)0x23)

#define PORTC_Reg   *((volatile unsigned char*)0x28)
#define DDRC_Reg    *((volatile unsigned char*)0x27)
#define PINC_Reg    *((volatile unsigned char*)0x26)

#define PORTD_Reg   *((volatile unsigned char*)0x2B)
#define DDRD_Reg    *((volatile unsigned char*)0x2A)
#define PIND_Reg    *((volatile unsigned char*)0x29)




#endif /* DIO_REG_H_ */

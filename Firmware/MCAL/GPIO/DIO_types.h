#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

// Enum definitions
typedef enum {
	Input = 0,  // 0
	Output = 1  // 1
} DIO_Direction;

typedef enum {
	DIO_PORTA = 0,
	DIO_PORTB = 1,
	DIO_PORTC = 2,
	DIO_PORTD = 3
	
} DIO_PORT;

typedef enum {
	LOW,
	HIGH
} DIO_Value;

typedef enum {
	Pin0 =0,
	Pin1 =1,
	Pin2 =2,
	Pin3 =3,
	Pin4 =4,
	Pin5 =5,
	Pin6 =6, 
	Pin7 =7
} Pin_Value;

#endif /* DIO_TYPES_H_ */

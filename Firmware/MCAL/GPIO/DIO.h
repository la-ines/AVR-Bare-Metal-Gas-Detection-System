
#ifndef DIO_H_
#define DIO_H_

void DIO_SetPortDirection( DIO_PORT port_ID , DIO_Direction direction);
void DIO_SetPortValue(DIO_PORT port_ID, unsigned char value);
void DIO_SetPinDirection(DIO_PORT port_ID , Pin_Value pin_ID , DIO_Direction direction );
void DIO_SetPinValue(DIO_PORT port_ID , Pin_Value pin_ID , DIO_Value value );
DIO_Value DIO_GetPinValue(DIO_PORT port_ID , Pin_Value pin_ID);



#endif /* DIO_H_ */

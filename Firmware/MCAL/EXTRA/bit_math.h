
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_Bit(port_ID , pin_ID)       (port_ID |=(1<<(pin_ID)) )
#define CLEAR_Bit(port_ID , pin_ID)      (port_ID &=~(1<<(pin_ID)) )
#define TOGGLE_Bit(port_ID , pin_ID)     (port_ID ^=(1<<(pin_ID)) )
#define GET_Bit(port_ID , pin_ID)         (((port_ID) >> (pin_ID)) & 0x01)

#endif /* BIT_MATH_H_ */

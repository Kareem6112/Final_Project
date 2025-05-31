/*
 * DIO_interface.h
 *
 * Created: 2/18/2025 3:28:02 PM
 *  Author: kareem
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"

#define HIGH 1
#define LOW  0

#define OUTPUT 1
#define INPUT  0
/*PORTS*/
#define DIO_PORTA   0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3
/*PINS*/
#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7

void DIO_VoidSetPinDir(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8dir);
void DIO_VoidSetPinVal(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8val);
void DIO_voidTogglePinVal(u8 copy_u8port,u8 copy_u8pin);
u8   DIO_U8ReadPinVal(u8 copy_u8port,u8 copy_u8pin);
void DIO_VoidSetPortDir(u8 copy_u8port,u8 copy_u8dir);
void DIO_VoidSetPortVal(u8 copy_u8port,u8 copy_u8val);
void DIO_voidTogPortVal(u8 copy_u8port);
#endif /* DIO_INTERFACE_H_ */
/*
 * LED_prog.c
 *
 * Created: 2/18/2025 4:49:45 PM
 *  Author: kareem
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"

void LED_VoidInit(u8 copy_u8port,u8 copy_u8pin)
{
	switch(copy_u8port)
	{
		case DIO_PORTA: DIO_VoidSetPinDir(DIO_PORTA,copy_u8pin,OUTPUT);break;
		case DIO_PORTB:	DIO_VoidSetPinDir(DIO_PORTB,copy_u8pin,OUTPUT);break;
		case DIO_PORTC:	DIO_VoidSetPinDir(DIO_PORTC,copy_u8pin,OUTPUT);break;
		case DIO_PORTD:	DIO_VoidSetPinDir(DIO_PORTD,copy_u8pin,OUTPUT);break;
	}
}

void LED_VoidSetLedOn(u8 copy_u8port,u8 copy_u8pin)
{
	switch(copy_u8port)
	{
	case DIO_PORTA: DIO_VoidSetPinVal(DIO_PORTA,copy_u8pin,HIGH);break;
	case DIO_PORTB:	DIO_VoidSetPinVal(DIO_PORTB,copy_u8pin,HIGH);break;
	case DIO_PORTC:	DIO_VoidSetPinVal(DIO_PORTC,copy_u8pin,HIGH);break;
	case DIO_PORTD:	DIO_VoidSetPinVal(DIO_PORTD,copy_u8pin,HIGH);break;
	}
}

void LED_VoidSetLedOff(u8 copy_u8port,u8 copy_u8pin)
{
	switch(copy_u8port)
	{
	case DIO_PORTA: DIO_VoidSetPinVal(DIO_PORTA,copy_u8pin,LOW);break;
	case DIO_PORTB:	DIO_VoidSetPinVal(DIO_PORTB,copy_u8pin,LOW);break;
	case DIO_PORTC:	DIO_VoidSetPinVal(DIO_PORTC,copy_u8pin,LOW);break;
	case DIO_PORTD:	DIO_VoidSetPinVal(DIO_PORTD,copy_u8pin,LOW);break;
	}
}

void LED_VoidSetLedToggle(u8 copy_u8port,u8 copy_u8pin)
{
	switch(copy_u8port)
	{
	case DIO_PORTA: DIO_voidTogglePinVal(DIO_PORTA,copy_u8pin);break;
	case DIO_PORTB:	DIO_voidTogglePinVal(DIO_PORTB,copy_u8pin);break;
	case DIO_PORTC:	DIO_voidTogglePinVal(DIO_PORTC,copy_u8pin);break;
	case DIO_PORTD:	DIO_voidTogglePinVal(DIO_PORTD,copy_u8pin);break;
	}
}
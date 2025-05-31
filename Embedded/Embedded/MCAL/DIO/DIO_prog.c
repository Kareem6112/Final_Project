/*
 * DIO_prog.c
 *
 * Created: 2/18/2025 3:28:27 PM
 *  Author: kareem
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_reg.h"
#include "DIO_interface.h"

void DIO_VoidSetPinDir(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8dir)
{
	if (copy_u8pin>=0 &&copy_u8pin<=7 )
	{
		if(copy_u8dir==OUTPUT)
		{
			switch(copy_u8port)
			{
				case DIO_PORTA:SET_BIT(DDRA_Reg,copy_u8pin);break;
				case DIO_PORTB:SET_BIT(DDRB_Reg,copy_u8pin);break;
				case DIO_PORTC:SET_BIT(DDRC_Reg,copy_u8pin);break;
				case DIO_PORTD:SET_BIT(DDRD_Reg,copy_u8pin);break;
			}
		}
		
		if(copy_u8dir==INPUT)
		{
			switch(copy_u8port)
			{
				case DIO_PORTA:CLR_BIT(DDRA_Reg,copy_u8pin);break;
				case DIO_PORTB:CLR_BIT(DDRB_Reg,copy_u8pin);break;
				case DIO_PORTC:CLR_BIT(DDRC_Reg,copy_u8pin);break;
				case DIO_PORTD:CLR_BIT(DDRD_Reg,copy_u8pin);break;
			}
		}
		
	}
}






void DIO_VoidSetPinVal(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8val)
{
	if (copy_u8pin>=0 &&copy_u8pin<=7 )
	{
		if(copy_u8val==HIGH)
		{
			switch(copy_u8port)
			{
				case DIO_PORTA:SET_BIT(PORTA_Reg,copy_u8pin);break;
				case DIO_PORTB:SET_BIT(PORTB_Reg,copy_u8pin);break;
				case DIO_PORTC:SET_BIT(PORTC_Reg,copy_u8pin);break;
				case DIO_PORTD:SET_BIT(PORTD_Reg,copy_u8pin);break;
			}
		}
		
		if(copy_u8val==LOW)
		{
			switch(copy_u8port)
			{
				case DIO_PORTA:CLR_BIT(PORTA_Reg,copy_u8pin);break;
				case DIO_PORTB:CLR_BIT(PORTB_Reg,copy_u8pin);break;
				case DIO_PORTC:CLR_BIT(PORTC_Reg,copy_u8pin);break;
				case DIO_PORTD:CLR_BIT(PORTD_Reg,copy_u8pin);break;
			}
		}
		
	}
}








void DIO_voidTogglePinVal(u8 copy_u8port,u8 copy_u8pin)
{
	if (copy_u8pin>=0 &&copy_u8pin<=7 )
	{
		
			switch(copy_u8port)
			{
				case DIO_PORTA:TOG_BIT(PORTA_Reg,copy_u8pin);break;
				case DIO_PORTB:TOG_BIT(PORTB_Reg,copy_u8pin);break;
				case DIO_PORTC:TOG_BIT(PORTC_Reg,copy_u8pin);break;
				case DIO_PORTD:TOG_BIT(PORTD_Reg,copy_u8pin);break;
			}
		
	}
}




u8 DIO_U8ReadPinVal(u8 copy_u8port,u8 copy_u8pin)
{

	if (copy_u8pin>=0 &&copy_u8pin<=7 )
	{
		
		switch(copy_u8port)
		{
			case DIO_PORTA: return GET_BIT(PINA_Reg,copy_u8pin);
			case DIO_PORTB:	return GET_BIT(PINB_Reg,copy_u8pin);
			case DIO_PORTC:	return GET_BIT(PINC_Reg,copy_u8pin);
			case DIO_PORTD:	return GET_BIT(PIND_Reg,copy_u8pin);
		}
	}
	return -1;
}


void DIO_VoidSetPortVal(u8 copy_u8port,u8 copy_u8val)
{

	switch(copy_u8port)
	{
		case DIO_PORTA:  PORTA_Reg=copy_u8val;break;
		case DIO_PORTB:  PORTB_Reg=copy_u8val;break;
		case DIO_PORTC:  PORTC_Reg=copy_u8val;break;
		case DIO_PORTD:  PORTD_Reg=copy_u8val;break;
	}
	
}


void DIO_VoidSetPortDir(u8 copy_u8port,u8 copy_u8dir)
{
			switch(copy_u8port)
			{
				case DIO_PORTA:DDRA_Reg=copy_u8dir;break;
				case DIO_PORTB:DDRB_Reg=copy_u8dir;break;
				case DIO_PORTC:DDRC_Reg=copy_u8dir;break;
				case DIO_PORTD:DDRD_Reg=copy_u8dir;break;
			}	
}






void DIO_voidTogPortVal(u8 copy_u8port)
{
	switch(copy_u8port)
	{
		case DIO_PORTA:  PORTA_Reg=~PORTA_Reg;break;
		case DIO_PORTB:  PORTB_Reg=~PORTB_Reg;break;
		case DIO_PORTC:  PORTC_Reg=~PORTC_Reg;break;
		case DIO_PORTD:  PORTD_Reg=~PORTD_Reg;break;
	}
	
}
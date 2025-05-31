/*
 * MOTOR.c
 *
 * Created: 3/22/2025 10:39:41 PM
 *  Author: kareem
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "MOTOR_config.h"
#include "MOTOR_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER0/TIMER0_interface.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"
#include "../../MCAL/TIMER2/TIMER2_interface.h"
void Motor_voidInit(u8 copy_u8dataport,u8 copy_u8ENpin,u8 copy_u8DIR1pin,u8 copy_u8DIR2pin)
{
	DIO_VoidSetPinDir(copy_u8dataport,copy_u8ENpin,OUTPUT);
	DIO_VoidSetPinDir(copy_u8dataport,copy_u8DIR1pin,OUTPUT);
	DIO_VoidSetPinDir(copy_u8dataport,copy_u8DIR2pin,OUTPUT);
	DIO_VoidSetPinVal(copy_u8dataport,copy_u8DIR1pin,LOW);
	DIO_VoidSetPinVal(copy_u8dataport,copy_u8DIR2pin,LOW);
}
void Motor_voidForward(u8 copy_u8dataport,u8 copy_u8timerpin,u8 copy_u8DIR1pin,u8 copy_u8DIR2pin,u8 copy_u8motorspeed)
{
	DIO_VoidSetPinVal(copy_u8dataport,copy_u8DIR1pin,HIGH);
	DIO_VoidSetPinVal(copy_u8dataport,copy_u8DIR2pin,LOW);
	switch(copy_u8timerpin)
	{
		case TIMER0:
					TIMER0_voidPhasePWM(TIMER0_PRESCALER_1024,copy_u8motorspeed);
		break;
		case TIMER1A:
					TIMER1_void10BitResFastPWM(OC1A_PIN,copy_u8motorspeed);
		break;
		case TIMER1B:
					TIMER1_void10BitResFastPWM(OC1B_PIN,copy_u8motorspeed);
		break;
		case TIMER2:
					TIMER2_voidPhasePWM(TIMER2_PRESCALER_1024,copy_u8motorspeed);
		break;
	}
	
}
void Motor_voidBackward(u8 copy_u8dataport,u8 copy_u8timerpin,u8 copy_u8DIR1pin,u8 copy_u8DIR2pin,u8 copy_u8motorspeed)
{
	DIO_VoidSetPinVal(copy_u8dataport,copy_u8DIR1pin,LOW);
	DIO_VoidSetPinVal(copy_u8dataport,copy_u8DIR2pin,HIGH);
	switch(copy_u8timerpin)
	{
		case TIMER0:
					TIMER0_voidPhasePWM(TIMER0_PRESCALER_1024,copy_u8motorspeed);
		      break;
		case TIMER1A:
					TIMER1_void10BitResFastPWM(OC1A_PIN,copy_u8motorspeed);
			  break;
		case TIMER1B:
					TIMER1_void10BitResFastPWM(OC1B_PIN,copy_u8motorspeed);
			  break;
		case TIMER2:
					TIMER2_voidPhasePWM(TIMER2_PRESCALER_1024,copy_u8motorspeed);
			  break;
	}
}
void Motor_voidStop(u8 copy_u8dataport,u8 copy_u8timerpin,u8 copy_u8DIR1pin,u8 copy_u8DIR2pin)
{
	DIO_VoidSetPinVal(copy_u8dataport,copy_u8DIR1pin,LOW);
	DIO_VoidSetPinVal(copy_u8dataport,copy_u8DIR2pin,LOW);
	switch(copy_u8timerpin)
	{
		case TIMER0:
					TIMER0_voidPhasePWM(TIMER0_PRESCALER_1024,0);
		break;
		case TIMER1A:
					TIMER1_void10BitResFastPWM(OC1A_PIN,0);
		break;
		case TIMER1B:
					TIMER1_void10BitResFastPWM(OC1B_PIN,0);
		break;
		case TIMER2:
					TIMER2_voidPhasePWM(TIMER2_PRESCALER_1024,0);
		break;
	}
	
}
/*
 * Ultrasonic_prog.c
 *
 * Created: 4/4/2025 8:26:20 PM
 *  Author: Kareem Glela
 */ 
#define F_CPU 16000000UL
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../Service layer/Software_ICU/ICU_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "Ultrasonic_interface.h"
#include <util/delay.h>
void Ultrasonic_voidInit(u8 copy_Port,u8 copy_trigPin,u8 copy_EchoPin)
{
	static u8 count=0;
	count++;
	if (count==1)
	{
		DIO_VoidSetPinDir(copy_Port,copy_trigPin,OUTPUT);
		DIO_VoidSetPinDir(copy_Port,copy_EchoPin,INPUT);
	}
		DIO_VoidSetPinVal(copy_Port,copy_trigPin,LOW);
		_delay_ms(2);
		DIO_VoidSetPinVal(copy_Port,copy_trigPin,HIGH);
		_delay_us(10);
		DIO_VoidSetPinVal(copy_Port,copy_trigPin,LOW);
}
f32 Ultrasonic_f32Distance()
{
	u16 T_on=0;
	u16 T_total=0;
	f32 distance=0.0;
	ICU_voidInit(INT_PIN0);
	ICU_voidParameters(&T_on,&T_total);
	//distance=((f32)T_on *(0.000002)/2)*343;
	distance = ((f32)T_on * 0.5 * 0.0343) / 2;   //the OUTPUT on cm and the  Multi by 2 if timer prescaller is 64    // Multi by 0.5 if prescaler =8
	return distance;
	}
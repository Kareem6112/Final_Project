/*
 * SERVO_prog.c
 *
 * Created: 3/28/2025 9:11:03 PM
 *  Author: kareem
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"
#include "SERVO_config.h"
#include "SERVO_interface.h"
void SERVO_voidinit() {
	// Set PD5 (OC1A) as output
	DIO_VoidSetPinDir(SERVO_PORT,SERVO_PIN,OUTPUT);
	// Set Timer1 for Fast PWM, 20ms period (50Hz)
	TIMER1_voidFastPWM_ICR();
	// Default to 90-degree position
	//SERVO_voidSetAngle(90, OCR1A_PIN);
	switch(SERVO_PIN)
	{
		case DIO_PIN5 :	SERVO_voidSetAngle(90, OCR1A_PIN);break;
		case DIO_PIN4 :	SERVO_voidSetAngle(90, OCR1B_PIN);break;
	}

}


void SERVO_voidSetAngle(u8 angle ,u8 copy_u8TIM1pin) {
	if (angle > 180) angle = 180;  // Limit angle range
	
	// Convert angle (1ms = 1000, 2ms = 2000)
	u16 duty =(u16) (2000 + ((u32)angle * 2000) / 180);
	 TIMER1_voidSetOCRVal(duty,copy_u8TIM1pin);
}




void SERVO_voidSetAngle_Hardware(u8 angle ,u8 copy_u8TIM1pin) {
	if (angle > 180) angle = 180;  // Limit angle range
	
	// Convert angle (1ms = 1000, 2ms = 2000)
	u16 duty =(u16) (1000 + ((u32)angle * 4000) / 180);
	TIMER1_voidSetOCRVal(duty,copy_u8TIM1pin);
}

/*
 * SERVO_interface.h
 *
 * Created: 3/28/2025 9:11:24 PM
 *  Author: kareem
 */ 


#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

#define OCR1A_PIN     0
#define OCR1B_PIN     1

void SERVO_voidinit(void);

void SERVO_voidSetAngle(u8 angle ,u8 copy_u8TIM1pin);

void SERVO_voidSetAngle_Hardware(u8 angle ,u8 copy_u8TIM1pin);

#endif /* SERVO_INTERFACE_H_ */
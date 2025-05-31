/*
 * STEPPER_interface.c
 *
 * Created: 3/27/2025 4:29:41 AM
 *  Author: kareem
 */ 
#define F_CPU 16000000UL

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_reg.h"
#include "STEPPER_interface.h"
#include "STEPPER_config.h"

#include <util/delay.h>

// Step sequence for full-step mode
const u8 STEPPER_SEQUENCE[4] = {0b0001, 0b0010, 0b0100, 0b1000};

void STEPPER_init() {
	// Set stepper motor control pins as outputs
	DIO_VoidSetPinDir(STEPPER_DDR,STEPPER_IN1,OUTPUT);
	DIO_VoidSetPinDir(STEPPER_DDR,STEPPER_IN2,OUTPUT);
	DIO_VoidSetPinDir(STEPPER_DDR,STEPPER_IN3,OUTPUT);
	DIO_VoidSetPinDir(STEPPER_DDR,STEPPER_IN4,OUTPUT);
	DIO_VoidSetPinVal(STEPPER_PORT,STEPPER_IN1,LOW);
	DIO_VoidSetPinVal(STEPPER_PORT,STEPPER_IN2,LOW);
	DIO_VoidSetPinVal(STEPPER_PORT,STEPPER_IN3,LOW);
	DIO_VoidSetPinVal(STEPPER_PORT,STEPPER_IN4,LOW);
	//STEPPER_DDR |= (1 << STEPPER_IN1) | (1 << STEPPER_IN2) | (1 << STEPPER_IN3) | (1 << STEPPER_IN4);
}

void STEPPER_step(u16 steps, u8 direction, u16 delay_ms) {
	for (u16 i = 0; i < steps; i++) {
		if (direction == CLOCKWISE) {
			// Rotate forward (CW)
			for (u8 j = 0; j < 4; j++) {
				/*DIO_VoidSetPinVal(STEPPER_DDR, STEPPER_IN1, (STEPPER_SEQUENCE[j] >> 0) & 1);
				DIO_VoidSetPinVal(STEPPER_DDR, STEPPER_IN2, (STEPPER_SEQUENCE[j] >> 1) & 1);
				DIO_VoidSetPinVal(STEPPER_DDR, STEPPER_IN3, (STEPPER_SEQUENCE[j] >> 2) & 1);
				DIO_VoidSetPinVal(STEPPER_DDR, STEPPER_IN4, (STEPPER_SEQUENCE[j] >> 3) & 1);*/
				STEPPER_PORT = (STEPPER_PORT & 0xF0) | STEPPER_SEQUENCE[j];
				 for (u16 d = 0; d < delay_ms; d++) {
					 _delay_ms(1);
				 }
			}
			} else {
			// Rotate backward (CCW)
			for (s8 j = 3; j >= 0; j--) {
				STEPPER_PORT = (STEPPER_PORT & 0xF0) | STEPPER_SEQUENCE[j];
				/* DIO_VoidSetPinVal(STEPPER_DDR, STEPPER_IN1, (STEPPER_SEQUENCE[j] >> 0) & 1);
				 DIO_VoidSetPinVal(STEPPER_DDR, STEPPER_IN2, (STEPPER_SEQUENCE[j] >> 1) & 1);
				 DIO_VoidSetPinVal(STEPPER_DDR, STEPPER_IN3, (STEPPER_SEQUENCE[j] >> 2) & 1);
				 DIO_VoidSetPinVal(STEPPER_DDR, STEPPER_IN4, (STEPPER_SEQUENCE[j] >> 3) & 1);*/
				 
				 for (u16 d = 0; d < delay_ms; d++) {
					 _delay_ms(1);
				 }
			}
		}
	}
}


const u8 MICROSTEP_SEQUENCE[8][4] = {
	{1, 0, 0, 0},  // Step 1
	{1, 1, 0, 0},  // Step 2
	{0, 1, 0, 0},  // Step 3
	{0, 1, 1, 0},  // Step 4
	{0, 0, 1, 0},  // Step 5
	{0, 0, 1, 1},  // Step 6
	{0, 0, 0, 1},  // Step 7
	{1, 0, 0, 1}   // Step 8
};

void STEPPER_microStep(u16 steps, u8 direction, u16 delay_us) {
	for (u16 i = 0; i < steps * MICROSTEPS; i++) {  // Multiply by Microsteps
		if (direction == CLOCKWISE) {
			for (u8 j = 0; j < MICROSTEPS; j++) {
				/*for (u8 y=0;y<4;y++)
				{
					STEPPER_PORT = (STEPPER_PORT & 0xF0) | MICROSTEP_SEQUENCE[j][y];
				}*/
				
				DIO_VoidSetPinVal(STEPPER_DDR, STEPPER_IN1, MICROSTEP_SEQUENCE[j][0]);
				DIO_VoidSetPinVal(STEPPER_DDR, STEPPER_IN2, MICROSTEP_SEQUENCE[j][1]);
				DIO_VoidSetPinVal(STEPPER_DDR, STEPPER_IN3, MICROSTEP_SEQUENCE[j][2]);
				DIO_VoidSetPinVal(STEPPER_DDR, STEPPER_IN4, MICROSTEP_SEQUENCE[j][3]);
				for (u16 delay_step=0;delay_step<delay_us;delay_step++)
				{
					_delay_us(1);
				}
				
			}
			} else {
			for (u8 j = MICROSTEPS - 1; j >= 0; j--) {  // Reverse for CCW
				/*for (u8 y=0;y<4;y++)
				{
					STEPPER_PORT = (STEPPER_PORT & 0xF0) | MICROSTEP_SEQUENCE[j][y];
				}*/
				DIO_VoidSetPinVal(STEPPER_DDR, STEPPER_IN1, MICROSTEP_SEQUENCE[j][0]);
				DIO_VoidSetPinVal(STEPPER_DDR, STEPPER_IN2, MICROSTEP_SEQUENCE[j][1]);
				DIO_VoidSetPinVal(STEPPER_DDR, STEPPER_IN3, MICROSTEP_SEQUENCE[j][2]);
				DIO_VoidSetPinVal(STEPPER_DDR, STEPPER_IN4, MICROSTEP_SEQUENCE[j][3]);
				for (u16 delay_step=0;delay_step<delay_us;delay_step++)
				{
					_delay_us(1);
				}
			}
		}
	}
}

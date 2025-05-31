/*
 * STEPPER_config.h
 *
 * Created: 3/27/2025 4:31:31 AM
 *  Author: kareem
 */ 


#ifndef STEPPER_CONFIG_H_
#define STEPPER_CONFIG_H_



#define STEPPER_DDR   DIO_PORTA
#define STEPPER_PORT  PORTA_Reg
#define STEPPER_IN1   DIO_PIN0
#define STEPPER_IN2   DIO_PIN1
#define STEPPER_IN3   DIO_PIN2
#define STEPPER_IN4   DIO_PIN3

#define MICROSTEPS 8  // Set to 8 for 8 Microsteps per full step


#endif /* STEPPER_CONFIG_H_ */
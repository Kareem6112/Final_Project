/*
 * MOTOR_interface.h
 *
 * Created: 3/22/2025 10:41:44 PM
 *  Author: kareem
 */ 


#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

#define TIMER0         0
#define TIMER1A        1
#define TIMER1B        2
#define TIMER2         3

void Motor_voidInit(u8 copy_u8dataport,u8 copy_u8ENpin,u8 copy_u8DIR1pin,u8 copy_u8DIR2pin);
void Motor_voidForward(u8 copy_u8dataport,u8 copy_u8timerpin,u8 copy_u8DIR1pin,u8 copy_u8DIR2pin,u8 copy_u8motorspeed);
void Motor_voidBackward(u8 copy_u8dataport,u8 copy_u8timerpin,u8 copy_u8DIR1pin,u8 copy_u8DIR2pin,u8 copy_u8motorspeed);
void Motor_voidStop(u8 copy_u8dataport,u8 copy_u8timerpin,u8 copy_u8DIR1pin,u8 copy_u8DIR2pin);

#endif /* MOTOR_INTERFACE_H_ */
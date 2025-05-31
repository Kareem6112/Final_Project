/*
 * STEPPER_interface.h
 *
 * Created: 3/27/2025 4:30:47 AM
 *  Author: kareem
 */ 


#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_


// Rotation directions
#define CLOCKWISE     1
#define COUNTERCLOCKWISE 0

void STEPPER_init();
void STEPPER_step(u16 steps, u8 direction, u16 delay_ms);
void STEPPER_microStep(u16 steps, u8 direction, u16 delay_us) ;

#endif /* STEPPER_INTERFACE_H_ */
/*
 * LED_interface.h
 *
 * Created: 2/18/2025 4:49:26 PM
 *  Author: kareem
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


void LED_VoidInit(u8 copy_u8port,u8 copy_u8pin);

void LED_VoidSetLedOn(u8 copy_u8port,u8 copy_u8pin);
void LED_VoidSetLedOff(u8 copy_u8port,u8 copy_u8pin);
void LED_VoidSetLedToggle(u8 copy_u8port,u8 copy_u8pin);

#endif /* LED_INTERFACE_H_ */
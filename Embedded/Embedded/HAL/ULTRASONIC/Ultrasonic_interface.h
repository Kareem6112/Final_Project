/*
 * Ultrasonic_interface.h
 *
 * Created: 4/4/2025 8:26:51 PM
 *  Author: Kareem Glela
 */ 


#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

void Ultrasonic_voidInit(u8 copy_Port,u8 copy_trigPin,u8 copy_EchoPin);

f32 Ultrasonic_f32Distance(void);



#endif /* ULTRASONIC_INTERFACE_H_ */
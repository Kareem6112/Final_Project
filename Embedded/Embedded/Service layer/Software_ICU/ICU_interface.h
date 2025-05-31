/*
 * ICU_interface.h
 *
 * Created: 4/4/2025 6:09:22 PM
 *  Author: Kareem Glela
 */ 


#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

#define  INT_PIN0   0
#define  INT_PIN1   1
#define  INT_PIN2   2

void ICU_voidInit(u8 copy_u8Intpin);  // must use INT_PIN0   INT_PIN1 INT_PIN2 NOT INT0 ,INT1 , INT2 
void ICU_voidParameters(u16* copy_u8TON,u16* copy_u8Ttotal);


#endif /* ICU_INTERFACE_H_ */
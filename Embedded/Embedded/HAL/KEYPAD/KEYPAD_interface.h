/*
 * KEYPAD_interface.h
 *
 * Created: 2/22/2025 8:15:01 PM
 *  Author: AMIT
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_


/* KEYPAD COL /ROW SIZE */

#define  COL_SIZE      4 
#define  ROW_SIZE      4
					  
#define KEYPAD_PIN     4 


void KEYPAD_voidInit(void) ; 


u8 KEYPAD_u8GetKey(void) ; 



#endif /* KEYPAD_INTERFACE_H_ */
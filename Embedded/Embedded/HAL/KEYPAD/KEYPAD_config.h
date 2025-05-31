/*
 * KEYPAD_config.h
 *
 * Created: 2/22/2025 8:15:16 PM
 *  Author: AMIT
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/* row pins */
#define  KEYPAD_ROW_PORT       DIO_PORTC 

#define  KEYPAD_R0_PIN         DIO_PIN4 
#define  KEYPAD_R1_PIN         DIO_PIN5
#define  KEYPAD_R2_PIN         DIO_PIN6

#if ROW_SIZE ==4
#define  KEYPAD_R3_PIN         DIO_PIN7
#endif
/*column pins */

#define  KEYPAD_COL_PORT       DIO_PORTA 

#define  KEYPAD_COL0_PIN       DIO_PIN0
#define  KEYPAD_COL1_PIN       DIO_PIN1
#define  KEYPAD_COL2_PIN       DIO_PIN2

#if COL_SIZE ==4
#define  KEYPAD_COL3_PIN       DIO_PIN3
#endif

#endif /* KEYPAD_CONFIG_H_ */
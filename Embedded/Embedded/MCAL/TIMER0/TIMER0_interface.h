/*
 * TIMER0_interface.h
 *
 * Created: 4/9/2025 2:20:06 PM
 *  Author: kareem
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_



#define TIMER0_OVERFLOWMODE							0
#define TIMER0_OUTCOMPMODE							1

#define TIMER0_PRESCALER_1							1
#define TIMER0_PRESCALER_8							2
#define TIMER0_PRESCALER_64							3
#define TIMER0_PRESCALER_256						4
#define TIMER0_PRESCALER_1024						5
#define TIMER0_Ext_Clock_T0_P_F_E                   6      /* External clock source on T0 pin. Clock on falling edge. */
#define TIMER0_Ext_Clock_T0_P_R_E                   7     /* External clock source on T0 pin. Clock on rising edge. */

//#define TIMER0_PRESCALER   TIMER0_PRESCALER_256				  /* Select the Prescaler */
//#define TIMER0_MODE		   TIMER0_OVERFLOWMODE				 /* Select the TIMER0 MODE */

#define WGM01_PIN									3
#define WGM00_PIN									6
#define COM00_PIN									4
#define COM01_PIN									5

#define TOIE0_PIN								    0
#define OCIE0_PIN								    1

#define TOV0_PIN								    0
#define OCF0_PIN								    1

#define OCR0_VAL                                   250
#define TCNT0_VAL								   100
/* peripherals APIS */
void TIMER0_voidInit(u8 copy_u8mode ,u8 copy_u8prescaller,u8 copy_preloadval);
void TIMER0_voidSetCallBack(void(*ptr)(void),u8 copy_u8mode);
void TIMER0_voidFastPWM(u8 copy_u8prescaller,u8 copy_u8dutycycle);
void TIMER0_voidPhasePWM(u8 copy_u8prescaller,u8 copy_u8dutycycle);



#endif /* TIMER0_INTERFACE_H_ */
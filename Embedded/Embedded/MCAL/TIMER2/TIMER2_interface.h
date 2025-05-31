/*
 * TIMER2_interface.h
 *
 * Created: 3/25/2025 11:29:32 PM
 *  Author: kareem
 */ 


#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_


#define TIMER2_OVERFLOWMODE							0
#define TIMER2_OUTCOMPMODE							1

#define TIMER2_PRESCALER_1							1
#define TIMER2_PRESCALER_8							2
#define TIMER2_PRESCALER_64							3
#define TIMER2_PRESCALER_256						4
#define TIMER2_PRESCALER_1024						5
#define TIMER2_Ext_Clock_T0_P_F_E                   6      /* External clock source on T0 pin. Clock on falling edge. */
#define TIMER2_Ext_Clock_T0_P_R_E                   7     /* External clock source on T0 pin. Clock on rising edge. */

//#define TIMER2_PRESCALER     TIMER2_PRESCALER_256				  /* Select the Prescaler */
//#define TIMER2_MODE		   TIMER2_OVERFLOWMODE				 /* Select the TIMER0 MODE */

#define WGM21_PIN									3
#define WGM20_PIN									6
#define COM20_PIN									4
#define COM21_PIN									5

#define TOIE2_PIN								    6
#define OCIE2_PIN								    7

#define TOV2_PIN								    6
#define OCF2_PIN								    7

#define OCR2_VAL                                   250
#define TCNT2_VAL								   100
/* peripherals APIS */
void TIMER2_voidInit(u8 copy_u8mode ,u8 copy_u8prescaller);
void TIMER2_voidSetCallBack(void(*ptr)(void),u8 copy_u8mode);
void TIMER2_voidFastPWM(u8 copy_u8prescaller,u8 copy_u8dutycycle);
void TIMER2_voidPhasePWM(u8 copy_u8prescaller,u8 copy_u8dutycycle);


#endif /* TIMER2_INTERFACE_H_ */
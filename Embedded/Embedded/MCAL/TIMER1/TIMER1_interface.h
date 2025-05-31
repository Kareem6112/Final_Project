
/*
 * TIMER1_interface.h
 *
 * Created: 3/22/2025 11:00:26 PM
 *  Author: Kareem
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#define OC1A_PIN 0
#define OC1B_PIN 1

#define COM1A0_PIN   6
#define COM1A1_PIN   7
			  
#define COM1B0_PIN   4
#define COM1B1_PIN   5
 
#define WGM10_PIN 0
#define WGM11_PIN 1
#define WGM12_PIN 3
#define WGM13_PIN 4


#define TIMER1_PRESCALER_1							1
#define TIMER1_PRESCALER_8							2
#define TIMER1_PRESCALER_64							3
#define TIMER1_PRESCALER_256						4
#define TIMER1_PRESCALER_1024						5
#define TIMER1_Ext_Clock_T0_P_F_E                   6      /* External clock source on T1 pin. Clock on falling edge. */
#define TIMER1_Ext_Clock_T0_P_R_E                   7     /* External clock source on T1 pin. Clock on rising edge. */


#define TIMER1_PRESCALER                            TIMER1_PRESCALER_8


#define OCR1A_PIN     0
#define OCR1B_PIN     1

void TIMER1_void10BitResFastPWM(u8 copy_u8pin,u8 copy_u8duty);

void TIMER1_voidFastPWM_ICR();
void TIMER1_voidSetOCRVal(u16 copy_u8dutycycle,u8 copy_u8TIM1pin);

void TIMER1_voidOVModeInit(void);
void TIMER1_voidResetVal(void);
u16 TIMER1_u16ReadVal(void);
#endif /* TIMER1_INTERFACE_H_ */
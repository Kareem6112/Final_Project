/*
 * DC_prog.c
 *
 * Created: 3/28/2025 1:13:22 PM
 *  Author: AMIT
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER0/TIMER0_interface.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"
#include "DC_config.h"







void DCMOTOR_voidInit(){
	
		/* set pins dir */
		
		DIO_VoidSetPinDir(DCMOTOR_EN1_PORT,DCMOTOR_EN1_PIN,OUTPUT) ;
		//DIO_VoidSetPinDir(DCMOTOR_EN2_PORT,DCMOTOR_EN2_PIN,OUTPUT) ;
		
		DIO_VoidSetPinDir(DCMOTOR_A1_PORT,DCMOTOR_A1_PIN,OUTPUT) ;
		DIO_VoidSetPinDir(DCMOTOR_A2_PORT,DCMOTOR_A2_PIN,OUTPUT) ;
		//DIO_VoidSetPinDir(DCMOTOR_A3_PORT,DCMOTOR_A3_PIN,OUTPUT) ;
		//DIO_VoidSetPinDir(DCMOTOR_A4_PORT,DCMOTOR_A4_PIN,OUTPUT) ;
		
	
}


void  DCMOTOR_voidForward( u8 copy_u8speed){
	
       
		/*set motor1  speed */
	   TIMER0_voidFastPWM(TIMER0_PRESCALER_1024,copy_u8speed) ;  /* 0 ----> 100 */
	   /*Set motor2 speed */
	  // TIMER1_void10BitResFastPWM(OC1B_PIN,copy_u8speed) ; 
	   
	    /* MOTOR1 */
	   DIO_VoidSetPinVal(DCMOTOR_A1_PORT,DCMOTOR_A1_PIN,HIGH) ; 
	   DIO_VoidSetPinVal(DCMOTOR_A2_PORT,DCMOTOR_A2_PIN,LOW) ;
	   
	   /* MOTOR2 */
	  // DIO_VoidSetPinVal(DCMOTOR_A3_PORT,DCMOTOR_A3_PIN,HIGH) ;
	 //  DIO_VoidSetPinVal(DCMOTOR_A4_PORT,DCMOTOR_A4_PIN,LOW) ;
	   
	   
	
	
	
}

void  DCMOTOR_voidRevers( u8 copy_u8speed){
	/*set motor1  speed */
	TIMER0_voidFastPWM(TIMER0_PRESCALER_1024,copy_u8speed) ;  /* 0 ----> 100 */
	/*Set motor2 speed */
	TIMER1_void10BitResFastPWM(OC1B_PIN,copy_u8speed) ;
	
	/* MOTOR1 */
	DIO_VoidSetPinVal(DCMOTOR_A1_PORT,DCMOTOR_A1_PIN,LOW) ;
	DIO_VoidSetPinVal(DCMOTOR_A2_PORT,DCMOTOR_A2_PIN,HIGH) ;
	
	/* MOTOR2 */
	DIO_VoidSetPinVal(DCMOTOR_A3_PORT,DCMOTOR_A3_PIN,LOW) ;
	DIO_VoidSetPinVal(DCMOTOR_A4_PORT,DCMOTOR_A4_PIN,HIGH) ;
	
	
}
void  DCMOTOR_voidRight( u8 copy_u8speed) {
	
	/*set motor1  speed */
	TIMER0_voidFastPWM(TIMER0_PRESCALER_1024,copy_u8speed) ;  /* 0 ----> 100 */
	/*Set motor2 speed */
	TIMER1_void10BitResFastPWM(OC1B_PIN,copy_u8speed) ;
	
	/* MOTOR1 */
	DIO_VoidSetPinVal(DCMOTOR_A1_PORT,DCMOTOR_A1_PIN,HIGH) ;
	DIO_VoidSetPinVal(DCMOTOR_A2_PORT,DCMOTOR_A2_PIN,LOW) ;
	
	/* MOTOR2 */
	DIO_VoidSetPinVal(DCMOTOR_A3_PORT,DCMOTOR_A3_PIN,LOW) ;
	DIO_VoidSetPinVal(DCMOTOR_A4_PORT,DCMOTOR_A4_PIN,LOW) ;
	
	
	
	
}
void  DCMOTOR_voidLeft( u8 copy_u8speed) {
	
	/*set motor1  speed */
	TIMER0_voidFastPWM(TIMER0_PRESCALER_1024,copy_u8speed) ;  /* 0 ----> 100 */
	/*Set motor2 speed */
	TIMER1_void10BitResFastPWM(OC1B_PIN,copy_u8speed) ;
	
	/* MOTOR1 */
	DIO_VoidSetPinVal(DCMOTOR_A1_PORT,DCMOTOR_A1_PIN,LOW) ;
	DIO_VoidSetPinVal(DCMOTOR_A2_PORT,DCMOTOR_A2_PIN,LOW) ;
	
	/* MOTOR2 */
	DIO_VoidSetPinVal(DCMOTOR_A3_PORT,DCMOTOR_A3_PIN,HIGH) ;
	DIO_VoidSetPinVal(DCMOTOR_A4_PORT,DCMOTOR_A4_PIN,LOW) ;
	
}
void  DCMOTOR_voidStop( u8 copy_u8speed) {
	
	
	/*set motor1  speed */
	TIMER0_voidFastPWM(TIMER0_PRESCALER_1024,copy_u8speed) ;  /* 0 ----> 100 */
	/*Set motor2 speed */
	TIMER1_void10BitResFastPWM(OC1B_PIN,copy_u8speed) ;
	
	/* MOTOR1 */
	DIO_VoidSetPinVal(DCMOTOR_A1_PORT,DCMOTOR_A1_PIN,LOW) ;
	DIO_VoidSetPinVal(DCMOTOR_A2_PORT,DCMOTOR_A2_PIN,LOW) ;
	
	/* MOTOR2 */
	DIO_VoidSetPinVal(DCMOTOR_A3_PORT,DCMOTOR_A3_PIN,LOW) ;
	DIO_VoidSetPinVal(DCMOTOR_A4_PORT,DCMOTOR_A4_PIN,LOW) ;
	
}
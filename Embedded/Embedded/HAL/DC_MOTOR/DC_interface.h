/*
 * DC_interface.h
 *
 * Created: 3/28/2025 1:12:59 PM
 *  Author: AMIT
 */ 


#ifndef DC_INTERFACE_H_
#define DC_INTERFACE_H_



void DCMOTOR_voidInit() ; 

void  DCMOTOR_voidForward( u8 copy_u8speed) ; 

void  DCMOTOR_voidRevers( u8 copy_u8speed) ;
void  DCMOTOR_voidRight( u8 copy_u8speed) ;
void  DCMOTOR_voidLeft( u8 copy_u8speed) ;
void  DCMOTOR_voidStop( u8 copy_u8speed) ;










#endif /* DC_INTERFACE_H_ */
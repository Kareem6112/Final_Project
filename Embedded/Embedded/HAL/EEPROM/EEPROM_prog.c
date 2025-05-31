/*
 * EEPROM_prog.c
 *
 * Created: 4/18/2025 8:46:34 PM
 *  Author: AMIT
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "../LCD/LCD_interface.h"
#define  F_CPU 16000000UL 
#include <util/delay.h>


void EEPROM_voidSendData(u16 copy_u16address , u8 copy_u8data){
	
	u8 loc_u8address=1010000 |(copy_u16address>>8) ;
	/*send start condition */

	//TWI_TWI_ErrSendRepeatedStart();    //  ****** FOR EEPROM IF there is an other one on the bus ******
	TWI_TWI_ErrSendStartCondition();  
	
	/*Send device address with write request (slave address*/
	TWI_TWI_ErrMasterSendSlaveAddressWithWrite(loc_u8address);

	/*Send word address (master send data)*/
	TWI_TWI_ErrMasterSendData((u8)copy_u16address) ;
	
	/*Transmit byte data (master send data)*/
	TWI_TWI_ErrMasterSendData(copy_u8data) ; 

	/*Send stop condition*/
	TWI_voidSendStopCondition() ; 
	
    _delay_ms(10) ; 	
	
	
	
}


u8  EEPROM_voidReciveData(u16 copy_u16address) {
	
	
	u8 loc_u8address=1010000| copy_u16address>>8 ;
	
	u8 loc_val=0 ; 
	/*send start condition */
	TWI_TWI_ErrSendStartCondition() ;
	/*Send device address with write request (slave address*/
	TWI_TWI_ErrMasterSendSlaveAddressWithWrite(loc_u8address);
	/*Send word address (master send data)*/
	TWI_TWI_ErrMasterSendData((u8)copy_u16address) ;
	/*Send repeated start condition*/
	TWI_TWI_ErrSendRepeatedStart() ; 
	/*Send device address with read request*/
	TWI_TWI_ErrMasterSendSlaveAddressWithRead(loc_u8address) ; 
	/*Receive byte data*/
  
    TWI_TWI_ErrMasterReciveData(&loc_val) ; 
	
	
	return loc_val ; 	
	
	
	
	
}

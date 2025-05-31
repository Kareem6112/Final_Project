/*
 * TWI_prog.c
 *
 * Created: 4/18/2025 6:05:37 PM
 *  Author: AMIT
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "TWI_interface.h"
#include "TWI_reg.h"
#define F_CPU 160000000UL
#include <util/delay.h>

void TWI_voidMasterInit(u8 copy_u8address){
	
	/* set TWBR = 12   to INIT clock ( 400khz) FOR Hardware 
	And set TWBR = 72 for Simulation 100 KHZ*/
	TWBR_REG=72 ; 
	
	/* SET Prescaler to 1 */
	
	CLR_BIT(TWSR_REG,0) ; 
	CLR_BIT(TWSR_REG,1) ;
	
	if (copy_u8address != 0)
	{
		TWAR_REG=copy_u8address<<1 ; // SET master address
	}
	else {
		
		// do nothing 
	}
	
	/* enable ACK */
	SET_BIT(TWCR_REG,6) ; 
	/* Enable TWI */
	SET_BIT(TWCR_REG,2) ;

}
void TWI_voidSlaveInit(u8 copy_u8address){
	
		TWAR_REG=copy_u8address<<1 ; // SET slave address
	
	
		/* enable ACK */
		SET_BIT(TWCR_REG,6) ;
		/* Enable TWI */
		SET_BIT(TWCR_REG,2) ;
	
}


TWI_Err TWI_TWI_ErrSendStartCondition(void){

	TWI_Err Loc_Err=NOErr ;
	
	//CLR_BIT(TWCR_REG, 5);     // <-- Clear any previous start condition LM 75
	
	// SendStartCondition
	SET_BIT(TWCR_REG,5) ;
	//CLR Flag to make the next operation
	SET_BIT(TWCR_REG,7) ;
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	if ((TWSR_REG &0xF8) != START_ACK)
	{
		Loc_Err=SendStartConditionErr ;
	}
	
	else {
		// do nothing
	}
	
	return Loc_Err ;

}

TWI_Err TWI_TWI_ErrSendRepeatedStart(void){
	
	
	 TWI_Err Loc_Err=NOErr ;
	
	 /* SendStartCondition */
	 SET_BIT(TWCR_REG,5) ;
	 /*CLR Flag to make the next operation */
	 SET_BIT(TWCR_REG,7) ;
	 
	 while(GET_BIT(TWCR_REG,7)==0) ;
	 
	 if ((TWSR_REG &0xF8) != REP_START)
	 {
		 Loc_Err=SendRepeatedStartErr ;
	 }
	 
	 else {
		 // do nothing
	 }

	 return Loc_Err ;
	
	
	
}

TWI_Err  TWI_TWI_ErrMasterSendSlaveAddressWithWrite(u8 copy_u8address) {
	
	TWI_Err Loc_Err=NOErr ;
	
	/* load slave address on bus */
	
	TWDR_REG=copy_u8address<<1 ; 
	
	/* CLR BIT 0 IN TWDR reg  to write operation */
	CLR_BIT(TWDR_REG,0) ; 
	
	/*  CLR StartCondition BIT  */
	 CLR_BIT(TWCR_REG,5) ;
	/*CLR Flag to make the next operation */
	SET_BIT(TWCR_REG,7) ;
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	if ((TWSR_REG &0xF8) != SLAVE_ADD_AND_WR_ACK)
	{
		Loc_Err=MasterSendSlaveAddressWithWriteErr ;
	}
	
	else {
		// do nothing
	}

	return Loc_Err ;
	
	
	
}
TWI_Err  TWI_TWI_ErrMasterSendSlaveAddressWithRead(u8 copy_u8address){
	
	
	TWI_Err Loc_Err=NOErr ;
	
	/* load slave address on bus */
	
	TWDR_REG=copy_u8address<<1 ;
	
	/* SET BIT 0 IN TWDR reg  to read operation */
	SET_BIT(TWDR_REG,0) ;
	
	/*  CLR StartCondition BIT  */
	CLR_BIT(TWCR_REG,5) ;
	/*CLR Flag to make the next operation */
	SET_BIT(TWCR_REG,7) ;
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	if ((TWSR_REG &0xF8) != SLAVE_ADD_AND_RR_ACK)
	{
		Loc_Err=MasterSendSlaveAddressWithReadErr ;
	}
	
	else {
		// do nothing
	}

	return Loc_Err ;
}

TWI_Err  TWI_TWI_ErrMasterSendData(u8 copy_u8data) {
	
	TWI_Err Loc_Err=NOErr ;
	
	/* load DATA  on bus */
	
	TWDR_REG=copy_u8data;
	
	/*CLR Flag to make the next operation */
	SET_BIT(TWCR_REG,7) ;
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	if ((TWSR_REG &0xF8) != MASTER_WR_BYTE_ACK)
	{
		Loc_Err=MasterSendDataErr ;
	}
	
	else {
		// do nothing
	}

	return Loc_Err ;
	
	
	
}


TWI_Err TWI_TWI_ErrMasterReciveData(u8 *copy_u8data){
	
	TWI_Err Loc_Err=NOErr ;
	

	/*CLR Flag to make the next operation */
	SET_BIT(TWCR_REG,7) ;
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	if ((TWSR_REG &0xF8) != MASTER_RD_BYTE_WITH_ACK)
	{
		Loc_Err=MasterReciveDataErr ;
	}
	
	else {
	
	 *copy_u8data = TWDR_REG ; 
	}

	return Loc_Err ;
	
}

void TWI_voidSendStopCondition(void) {
	
		
		/*SendStopCondition*/
		SET_BIT(TWCR_REG,4) ;
		/*CLR Flag to make the next operation */
		SET_BIT(TWCR_REG,7) ;
			while (GET_BIT(TWCR_REG, 4)); // ?? ADD THIS to wait until STOP clears
}
 void TWI_voidClearStartCondition(void)
 {
	 CLR_BIT(TWCR_REG, 5);  
 } 

u8 TWI_u8I2CAdresse(void)
{
		for (u8 addr = 0x48; addr <= 0x6F; addr++) {
			if ( TWI_TWI_ErrSendStartCondition() == NOErr && TWI_TWI_ErrMasterSendSlaveAddressWithWrite(addr) == NOErr)
			{
				TWI_voidSendStopCondition();
				return addr;
			}
			TWI_voidSendStopCondition();
			_delay_ms(10);
		}
	return 0x00;
}




TWI_Err TWI_TWI_Err_statusSlaveAckOrNotAck(u8 copy_u8address){
	
	TWI_Err Loc_Err=NOErr ;
	
	/*start twi module and ack  data after reception  */
	
	/*enable ACK */
	SET_BIT(TWCR_REG,6) ;
	/* Enable TWI */
	SET_BIT(TWCR_REG,2) ;
	/*clr the interrupt flag to start the next operation  */
	SET_BIT(TWCR_REG,7) ;
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	/* check the operation status */
	
	if ((TWSR_REG&0xf8) != SLAVE_ADD_RCVD_WD_REQ)
	{
		Loc_Err=SlaveAckOrNotAckErr ;
	}
	else{
		
	}
	
	
	return Loc_Err ;

}
u8 TWI_u8SlaveReciveData(void) {
	
	
	/*enable ACK */
	SET_BIT(TWCR_REG,6) ;
	/* Enable TWI */
	SET_BIT(TWCR_REG,2) ;
	/*clr the interrupt flag to start the next operation  */
	SET_BIT(TWCR_REG,7) ;
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	/* return received data */
   	return TWDR_REG;

	
}

void TWI_voidReset(void) {
	TWCR_REG = 0; // Disable TWI completely
	_delay_ms(10);
	TWI_voidMasterInit(0); // Re-init
}
TWI_Err TWI_TWI_ErrMasterReciveLastData(u8 *copy_u8data){
	TWI_Err Loc_Err=NOErr ;

	CLR_BIT(TWCR_REG,6); // Disable ACK
	SET_BIT(TWCR_REG,7); // Clear flag
	while(GET_BIT(TWCR_REG,7)==0);

	if ((TWSR_REG & 0xF8) != 0x58)
	Loc_Err = MasterReciveDataErr;
	else
	*copy_u8data = TWDR_REG;

	return Loc_Err;
}

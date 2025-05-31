/*
 * TWI_interface.h
 *
 * Created: 4/18/2025 6:04:42 PM
 *  Author: AMIT
 */ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_


typedef enum {
	
	   NOErr ,
	   SendStartConditionErr,
	   SendRepeatedStartErr,
	   MasterSendSlaveAddressWithWriteErr,
	   MasterSendSlaveAddressWithReadErr,
	   MasterSendDataErr,
	   MasterReciveDataErr,
	   SlaveAckOrNotAckErr,
	   Err,
	
	}TWI_Err;



// 0 for no address 
void TWI_voidMasterInit(u8 copy_u8address) ; 
void TWI_voidSlaveInit(u8 copy_u8address) ;



TWI_Err TWI_TWI_ErrSendStartCondition(void) ; 
TWI_Err TWI_TWI_ErrSendRepeatedStart(void) ;

TWI_Err  TWI_TWI_ErrMasterSendSlaveAddressWithWrite(u8 copy_u8address) ; 
TWI_Err  TWI_TWI_ErrMasterSendSlaveAddressWithRead(u8 copy_u8address) ;

TWI_Err  TWI_TWI_ErrMasterSendData(u8 copy_u8data) ;

TWI_Err TWI_TWI_ErrMasterReciveData(u8 *copy_u8data) ; 

void TWI_voidSendStopCondition(void) ; 


void TWI_voidClearStartCondition(void);

u8 TWI_u8I2CAdresse(void);

u8 TWI_u8SlaveReciveData(void);
TWI_Err TWI_TWI_ErrdSlaveAckOrNotAck(u8 copy_u8adress);
TWI_Err TWI_TWI_ErrMasterReciveLastData(u8 *copy_u8data);

void TWI_voidReset(void) ;

#endif /* TWI_INTERFACE_H_ */
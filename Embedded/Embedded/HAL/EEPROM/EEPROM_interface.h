/*
 * EEPROM_interface.h
 *
 * Created: 4/18/2025 8:46:19 PM
 *  Author: AMIT
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_




void EEPROM_voidSendData(u16 copy_u16address , u8 copy_u8data);

u8  EEPROM_voidReciveData(u16 copy_u16address) ;






#endif /* EEPROM_INTERFACE_H_ */
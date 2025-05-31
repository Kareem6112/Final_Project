/*
 * SSD_config.h
 *
 * Created: 2/18/2025 5:15:15 PM
 *  Author: kareem
 */ 


#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_

/*Choose Mode 1 For only 1 Seven segment Without A BCD encoder
  Choose Mode 2 For only 2 Seven segment With    A BCD encoder */

#define Mode 2

#define Data_Port   DIO_PORTA  //Data PINS
#define Enable_Port DIO_PORTB // ENable pin -> PORT
#define Enable_Pin1	DIO_PIN1 //  ENable pin1
#define Enable_Pin2 DIO_PIN2//	 ENable pin2


#endif /* SSD_CONFIG_H_ */
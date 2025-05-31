/*
 * main.h
 * Created: 2/18/2025 4:13:33 PM
 *  Author: Kareem Glela
 */ 
#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SSD/SSD_config.h"
#include "../HAL/SSD/SSD_interface.h"
#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KEYPAD/KEYPAD_interface.h"
#include "../HAL/KEYPAD/KEYPAD_config.h"
#include "../MCAL/GI/GI_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/ADC_INT/ADC_INT_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/TIMER0/TIMER0_reg.h"
#include "../MCAL/TIMER1/TIMER1_interface.h"
#include "../HAL/MOTOR/MOTOR_interface.h"
#include "../HAL/STEPPER/STEPPER_interface.h"
#include "../HAL/DC_MOTOR/DC_interface.h"
#include "../HAL/SERVO_MOTOR/SERVO_interface.h"
#include "../MCAL/WDT/WDT_interface.h"
#include "../Service layer/Software_ICU/ICU_interface.h"
#include "../HAL/ULTRASONIC/Ultrasonic_interface.h"
//#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/UART_INT/UART_interface.h"
//#include "../MCAL/TWI/TWI_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../HAL/EEPROM/EEPROM_interface.h"
#include "../MCAL/TWI/TWI_interface.h"
#include "../RTOS_STACK/Kernel_interface.h"
#endif /* MAIN_H_ */
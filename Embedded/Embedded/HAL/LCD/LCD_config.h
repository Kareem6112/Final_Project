/*
 * LCD_config.h
 *
 * Created: 2/18/2025 7:13:52 PM
 *  Author: Kareem
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#if LCD_MODE == LCD_4BITMODE 
#define  LCD_DPORT      DIO_PORTA

#define  LCD_D4BIT      DIO_PIN4
#define  LCD_D5BIT      DIO_PIN5
#define  LCD_D6BIT      DIO_PIN6
#define  LCD_D7BIT      DIO_PIN7
#elif LCD_MODE == LCD_8BITMODE

/*LCD DATA PINS (for 8 BIT MODE ) */

#define  LCD_DPORT      DIO_PORTA

#endif

/* LCD control pins */
#define  LCD_CPORT       DIO_PORTB
#define  LCD_RS_PIN      DIO_PIN1
#define  LCD_RW_PIN      DIO_PIN0
#define  LCD_EN_PIN      DIO_PIN2





#endif /* LCD_CONFIG_H_ */
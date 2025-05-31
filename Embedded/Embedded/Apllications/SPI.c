/*
 * SPI.c
 *
 * Created: 4/13/2025 4:23:07 PM
 *  Author: kareem
 */ 
/*
There is a problem to use the servo with DC motor on the same timer due to different configurations 
*/
/* TASK 1 SERVO WITH POT ---- watch dog timer */

/* interrupt service routine is saved on the flash memory and in the foreground and when it's called in a function it returns to the ***main*** on the background not returning to the function */
/* INTERRUPT you must open the Global interrupt don't forget*/
/* if there is a use of timer you must define the pin as output */

/*
#include "main.h"


int main(void)
{
		DIO_VoidSetPinDir(DIO_PORTB,DIO_PIN5,OUTPUT);
		DIO_VoidSetPinDir(DIO_PORTB,DIO_PIN6,INPUT);
		DIO_VoidSetPinDir(DIO_PORTB,DIO_PIN7,OUTPUT);
		DIO_VoidSetPinDir(DIO_PORTB,DIO_PIN4,OUTPUT);
		DIO_VoidSetPinDir(DIO_PORTB,DIO_PIN3,OUTPUT); //SS 2
	SPI_voidMasterInit();
	
	DIO_VoidSetPinVal(DIO_PORTB, DIO_PIN4, HIGH);
	DIO_VoidSetPinVal(DIO_PORTB, DIO_PIN3, LOW);

	SPI_voidSendString("Hey Slave1\r");  // One clean message

	DIO_VoidSetPinVal(DIO_PORTB, DIO_PIN3, HIGH);

	_delay_ms(50);
	
	DIO_VoidSetPinVal(DIO_PORTB,DIO_PIN4,LOW);
	DIO_VoidSetPinVal(DIO_PORTB,DIO_PIN3,HIGH);
	char* msg = "Hey Slave 2\r";
	for (u8 i = 0; msg[i] != '\0'; i++)
	{
		SPI_voidMasterSendData(msg[i]);
		_delay_ms(100);
	}

	while (1)
	{
		DIO_VoidSetPinVal(DIO_PORTB, DIO_PIN4, LOW);
		DIO_VoidSetPinVal(DIO_PORTB, DIO_PIN3, HIGH);

		SPI_voidSendString("Kareem\r");  // One clean message

		DIO_VoidSetPinVal(DIO_PORTB, DIO_PIN4, HIGH);

		_delay_ms(100);
	}
}

*/






/*
int main(void)
{
	
	DIO_VoidSetPinDir(DIO_PORTC,DIO_PIN1,OUTPUT);
	LCD_voidInit();
	LCD_voidSendCommand(LCD_CURSOR_OFF);
	UART_voidInit(9600);  // UART initialization
	volatile u8 var = 0;
	
	
	while (1)
	{
		
		// Check if data has been received, without blocking
		if (UART_u16DataAvailable())  // Check if data is ready
		{
			
			var = UART_u8Receive();  // Receive data
			if (var == 'A')
			{
				DIO_VoidSetPinVal(DIO_PORTC,DIO_PIN1,HIGH);
			}else DIO_VoidSetPinVal(DIO_PORTC,DIO_PIN1,LOW);
		}
	}
}

*/


/*

STEPPER_init();
		Motor_voidInit(DIO_PORTD,DIO_PIN7,DIO_PIN4,DIO_PIN5);

	while (1)
	{      
		
			// Rotate 100 steps CW
			//STEPPER_step(250, CLOCKWISE,10);
			//_delay_ms(1000);
			
			// Rotate 100 steps CCW
			//STEPPER_step(250, COUNTERCLOCKWISE, 10);
			//_delay_ms(1000);
			
			STEPPER_microStep(250, CLOCKWISE, 500);  // Move 100 full steps with Micro stepping
			_delay_ms(1000);
			STEPPER_microStep(250, COUNTERCLOCKWISE, 500);  // Move back
		 
	}

*/
/*


STEPPER_init();
Motor_voidInit(DIO_PORTD,DIO_PIN7,DIO_PIN4,DIO_PIN5);



		for(u8 val=0;val <100; val++)
		{
			Motor_voidForward( DIO_PORTD,TIMER2,DIO_PIN4,DIO_PIN5,val);
			_delay_ms(50);
		}
		_delay_ms(1000);

		for(u8 val=100;val>0; val--)
		{
			Motor_voidBackward( DIO_PORTD,TIMER2,DIO_PIN4,DIO_PIN5,val);
			_delay_ms(50);
		}
		_delay_ms(1000);
		Motor_voidStop(DIO_PORTD,TIMER2,DIO_PIN4,DIO_PIN5);
		_delay_ms(1000);
		
		// Rotate 100 steps CW
		STEPPER_step(4, CLOCKWISE,100);
		_delay_ms(1000);

		// Rotate 100 steps CCW
		STEPPER_step(4, COUNTERCLOCKWISE, 100);
		_delay_ms(1000);
*/


/*                  SERVO DC MOTORS


#include "main.h"

int main(void)
{
	SERVO_voidinit();
	DCMOTOR_voidInit();
	DIO_VoidSetPinDir(DIO_PORTA,DIO_PIN0,INPUT);
	DIO_VoidSetPinDir(DIO_PORTA,DIO_PIN1,INPUT);
	DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN4,OUTPUT);
	while (1)
	{
		SERVO_voidinit();
		_delay_ms(500);
		SERVO_voidSetAngle( 50 ,OCR1A_PIN);
		_delay_ms(1000);
		SERVO_voidSetAngle( 80 ,OCR1A_PIN);
		_delay_ms(500);
		SERVO_voidSetAngle( 180 ,OCR1A_PIN);
		_delay_ms(500);
		SERVO_voidSetAngle( 50 ,OCR1B_PIN);
		_delay_ms(1000);
		SERVO_voidSetAngle( 80 ,OCR1B_PIN);
		_delay_ms(500);
		SERVO_voidSetAngle( 180 ,OCR1B_PIN);
		_delay_ms(500);
		for (u8 i=0;i<100;i++)
		{
			DCMOTOR_voidRight(i);
			//TIMER1_void10BitResFastPWM(OCR1B_PIN,i);
			_delay_ms(10);
		}
		for (u8 i=100;i>0;i--)
		{
			DCMOTOR_voidLeft(i);
			//TIMER1_void10BitResFastPWM(OCR1B_PIN,i);
			_delay_ms(10);
		}
		
		for (u8 i=100;i>0;i--)
		{
			DCMOTOR_voidRevers(i);
			//TIMER1_void10BitResFastPWM(OCR1B_PIN,i);
			_delay_ms(10);
		}
		
	}
}

*/


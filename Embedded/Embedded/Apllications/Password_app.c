
/*
 * Password_app.c
 *
 * Created: 3/9/2025 6:50:53 PM
 *  Author: kareem
 */ 

/*
int main(void)
{
	LCD_voidInit();
	KEYPAD_voidInit();
	volatile u8 key=0xff;
	u8 counter=0;
	u8 True_Pasword[]={'1','2','3','0'};
	volatile u8 pasword[4]={0};
	u8 c=0;
	u8 max_Repeated_wrong=0;
	LCD_voidGotoXY(0,0);
	LCD_voidSendString("Enter Pass");
	_delay_ms(500);
	//LCD_voidSendCommand(LCD_CURSOR_OFF);
	DIO_VoidSetPinDir(DIO_PORTC,DIO_PIN2,OUTPUT);
	DIO_VoidSetPinDir(DIO_PORTC,DIO_PIN7,OUTPUT);
	DIO_VoidSetPinDir(DIO_PORTB,DIO_PIN3,OUTPUT);
	while (1)
	{
		LCD_voidGotoXY(1,0);
		LCD_voidSendString("                  ");
		c=0;
		for (counter=0;counter<4;counter++)
		{
			do
			{
				key=KEYPAD_u8GetKey();
			} while (key==0xff);
			LCD_voidGotoXY(1,counter);
			pasword[counter]=key;
			LCD_voidSendData(key);
			_delay_ms(100);
			LCD_voidGotoXY(1,counter);
			LCD_voidSendData('*');
		}
		
		for(u8 i=0;i<4;i++)
		{
			if (pasword[i]==True_Pasword[i])
			{
				c++;
			}
		}
		if (c==4)
		{
			LCD_voidGotoXY(1,0);
			LCD_voidSendString("Right password");
			DIO_VoidSetPinVal(DIO_PORTC,DIO_PIN2,HIGH);
			DIO_VoidSetPinVal(DIO_PORTB,DIO_PIN3,LOW);
			DIO_VoidSetPinVal(DIO_PORTC,DIO_PIN7,LOW);
			_delay_ms(1000);
			max_Repeated_wrong=0;
		}else
		{
			max_Repeated_wrong++;
			LCD_voidGotoXY(1,0);
			LCD_voidSendString("Wrong Password");
			DIO_VoidSetPinVal(DIO_PORTC,DIO_PIN7,HIGH);
			DIO_VoidSetPinVal(DIO_PORTB,DIO_PIN3,LOW);
			DIO_VoidSetPinVal(DIO_PORTC,DIO_PIN2,LOW);

			_delay_ms(1000);
		}
		if (max_Repeated_wrong==3)
		{
			LCD_voidGotoXY(1,0);
			LCD_voidSendString("Rest the system");
			DIO_VoidSetPinVal(DIO_PORTB,DIO_PIN3,HIGH);
			DIO_VoidSetPinVal(DIO_PORTC,DIO_PIN2,LOW);
			DIO_VoidSetPinVal(DIO_PORTC,DIO_PIN7,LOW);
			while(1);
		}
	}
}

*/
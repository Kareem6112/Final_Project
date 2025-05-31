/*
 * Stop_watch.c
 *
 * Created: 3/22/2025 6:02:10 PM
 *  Author: kareem
 */ 
/*
#include "main.h"
u8 sec=0;
u8 minute=0;
u8 hour=0;
void LED()
{
	static u16 Loc_u8count=0;
	Loc_u8count++;
	if(Loc_u8count==1000)
	{
		Loc_u8count=0;
		DIO_voidTogglePinVal(DIO_PORTD,DIO_PIN3);
		sec++;
		if (sec==60)
		{
			
			sec=0;
			minute++;
			if (minute==60)
			{
				minute=0;
				hour++;
			}
		}
	}
}

int main(void)
{
	GI_voidEnable();
	DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN3,OUTPUT);
	DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN4,OUTPUT);
	DIO_VoidSetPinVal(DIO_PORTD,DIO_PIN4,LOW);
	TIMER0_voidInit(TIMER0_OUTCOMPMODE,TIMER0_PRESCALER_64);
	TIMER0_voidSetCallBack(LED,TIMER0_OUTCOMPMODE);
	LCD_voidInit();
	LCD_voidLcdClear();
	LCD_voidSendCommand(LCD_CURSOR_OFF);
	while (1)
	{
		if(sec==0)
		{
			LCD_voidGotoXY(0,7);
			LCD_voidSendString(" ");
		}
		LCD_voidGotoXY(0,0);
		LCD_voidIntDisplay(hour);
		LCD_voidSendString(":");
		LCD_voidGotoXY(0,3);
		LCD_voidIntDisplay(minute);
		LCD_voidSendString(":");
		LCD_voidGotoXY(0,6);
		LCD_voidIntDisplay(sec);
		
	}
}

*/
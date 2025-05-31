/*
 * UART.c
 *
 * Created: 5/8/2025 6:27:35 PM
 *  Author: Kareem
 */ 



/*
//Master 
int main(void)
{
	UART_voidInit(9600);
	while(1)
	{
		 UART_voidSendInt(4);
		 _delay_ms(100);
		 UART_voidSendString("ALI");
		 
		 _delay_ms(300);
		 UART_voidSendInt(5);
		 _delay_ms(100);
		 UART_voidSendString("OMAR");
		 
		 _delay_ms(300);
		 UART_voidSendInt(7);
		 _delay_ms(100);
		 UART_voidSendString("Kareem");
		 
		 _delay_ms(300);
		
		
		
	}
}
*/

/* 
//Slave
#include <string.h>  // Required for memset()
int main(void)
{
	#define max 6
	UART_voidInit(9600);
	LCD_voidInit();
	char rec[15]={0};
	u8 num=0;
	u8 flag=0;
	while (1)
	{
		
		
		if (UART_u16DataAvailable())
		{
			if (flag==0)
			{
				num=UART_u16ReceiveInt();
				flag=1;
				
			}
			if (flag==1)
			{
				UART_voidReceiveString(rec, num);
				LCD_voidGotoXY(0,0);
				LCD_voidSendString(rec);

				LCD_voidGotoXY(1,0);
				LCD_voidSendString("Kareem_Glela");
				_delay_ms(200);
				LCD_voidSendCommand(LCD_CLEAR_COMMAND);
				flag=0;
			}
			
		}
		
	}
}
*/
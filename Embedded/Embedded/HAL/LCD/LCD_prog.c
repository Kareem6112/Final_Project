/*
 * LCD_prog.c
 *
 * Created: 2/18/2025 7:14:11 PM
 *  Author: Kareem Glela
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
static void LCD_SHDATA( u8 copy_u8data )
{
	
	u8 LCD_PIN[4]={LCD_D4BIT,LCD_D5BIT,LCD_D6BIT,LCD_D7BIT} ;
	u8 loc_in=0 ;
	
	for (loc_in=0 ; loc_in<4 ;loc_in++)
	{
		DIO_VoidSetPinVal(LCD_DPORT,LCD_PIN[loc_in],GET_BIT(copy_u8data,loc_in)) ;
	}

}

static void LCD_voidSendEnablePulse(){
	/*Send enable pulse  */
	DIO_VoidSetPinVal(LCD_CPORT,LCD_EN_PIN,HIGH) ;
	_delay_ms(2) ;
	DIO_VoidSetPinVal(LCD_CPORT,LCD_EN_PIN,LOW) ;
}

void LCD_voidInit(void)
{
	_delay_ms(40);
    DIO_VoidSetPinDir(LCD_CPORT, LCD_RS_PIN, OUTPUT);
    DIO_VoidSetPinDir(LCD_CPORT, LCD_EN_PIN, OUTPUT);
    DIO_VoidSetPinDir(LCD_CPORT, LCD_RW_PIN, OUTPUT);
    DIO_VoidSetPortDir(LCD_DPORT, 0xF0);
   // DIO_VoidSetPortDir(LCD_CPORT, 0x0F);
		#if LCD_MODE == LCD_4BITMODE
		/* send function set command */
		LCD_SHDATA(0b0010) ;
		LCD_voidSendEnablePulse() ;
		LCD_SHDATA(0b0010) ;
		LCD_voidSendEnablePulse() ;
		LCD_SHDATA(0b1000) ;
		LCD_voidSendEnablePulse() ;
		
		#elif LCD_MODE == LCD_8BITMODE
		
		/* send function set command */
		LCD_voidSendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE) ;
		#endif

    _delay_ms(40);
    
    LCD_voidSendCommand(LCD_CURSOR_ON);  
    LCD_voidSendCommand(LCD_DisplayON_Blinking_Cursor); 
    LCD_voidSendCommand(LCD_CLEAR_COMMAND);  
}

void LCD_voidSendCommand(u8 copy_u8command)
{

    DIO_VoidSetPinVal(LCD_CPORT, LCD_RS_PIN, LOW);
    

    DIO_VoidSetPinVal(LCD_CPORT, LCD_RW_PIN, LOW);
    
	#if LCD_MODE == LCD_8BITMODE
	
	DIO_VoidSetPortVal(LCD_DPORT,copy_u8command) ;
	LCD_voidSendEnablePulse() ;

	
	#elif LCD_MODE == LCD_4BITMODE
	// 1100 1100
	LCD_SHDATA(copy_u8command>>4) ;
	LCD_voidSendEnablePulse() ;
	
	LCD_SHDATA(copy_u8command) ;
	LCD_voidSendEnablePulse() ;
	
	#endif

}

void LCD_voidSendData(u8 copy_u8data)
{

    DIO_VoidSetPinVal(LCD_CPORT, LCD_RS_PIN, HIGH);
    DIO_VoidSetPinVal(LCD_CPORT, LCD_RW_PIN, LOW);
	
    #if LCD_MODE == LCD_8BITMODE
    
    DIO_VoidSetPortVal(LCD_DPORT,copy_u8data) ;
    LCD_voidSendEnablePulse() ;

    
    #elif LCD_MODE == LCD_4BITMODE     // 1100 1100
    LCD_SHDATA(copy_u8data>>4) ;
    LCD_voidSendEnablePulse() ;
    
    LCD_SHDATA(copy_u8data) ;
    LCD_voidSendEnablePulse() ;
    
    #endif
}

void LCD_voidSendString(const char *Str)
{
    u8 i = 0;
    while (Str[i] != nul)
    {
        LCD_voidSendData(Str[i]);
        i++;
    }
}

void LCD_voidGotoXY(u8 copy_u8row, u8 copy_u8col)
{
    u8 LOC_u8lcd_memory_address = 0;

    switch (copy_u8row)
    {
        case 0: LOC_u8lcd_memory_address = copy_u8col + 0x00; break;
        case 1: LOC_u8lcd_memory_address = copy_u8col + 0x40; break;
        case 2: LOC_u8lcd_memory_address = copy_u8col + 0x14; break;
        case 3: LOC_u8lcd_memory_address = copy_u8col + 0x54; break;
    }

   
    LCD_voidSendCommand(LOC_u8lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}
void LCD_voidGotoRowColString(u8 copy_u8row,u8 copy_u8col,const char*str)
{
	LCD_voidGotoXY(copy_u8row,copy_u8col);
	LCD_voidSendString(str);
	
}

void LCD_voidLcdClear(void)
{
    LCD_voidSendCommand(LCD_CLEAR_COMMAND);
    _delay_ms(2);  
}
/*
void LCD_voidIntDisplay(u16 copy_u8int)
{
	 u16 count=0;
	 u16 fact=10;
	 u16 miror=copy_u8int;
	 u16 i=0,p=0;
	 u16 temp=0;
	 u8 Zero_temp=0;
	 while(miror%fact!=0)
	 {
		 miror/=10;
		 fact*=10;
		 count++;
	 }
	 p=count;
	 if (p==0)
	 {
		 Zero_temp++;
	 }
	 char *new_arr=(char*)malloc((Zero_temp+p+1)*sizeof(char));
	 if (Zero_temp==1)
	 {
		 new_arr[0]='0';
	 }
	 while(count>0)
	 {
		 new_arr[i]=copy_u8int%10+'0';
		 copy_u8int/=10;
		 i++;
		 count--;
	 }
	
	 for (int i=0;i<p/2;i++)
	 {
		 
		 temp=new_arr[i];
		 new_arr[i]=new_arr[p-i-1];
		 new_arr[p-i-1]=temp;
	 }
	 if (Zero_temp==1)
	 {
		 new_arr[p+1]='\0';
	 }
	 else new_arr[p]='\0';

	 LCD_voidSendString(new_arr); 
	 free(new_arr);
}
*/
void LCD_voidIntDisplay(u16 copy_u8int)
{
	char new_arr[6];  // Max 5 digits + null terminator (u16 max: 65535)
	u8 i = 0;

	// Handle zero separately
	if (copy_u8int == 0)
	{
		LCD_voidSendString("0");
		return;
	}

	// Convert integer to string (reverse order)
	u16 num = copy_u8int;
	while (num > 0)
	{
		new_arr[i++] = (num % 10) + '0';
		num /= 10;
	}
	new_arr[i] = '\0';

	// Reverse the string in-place
	for (u8 j = 0; j < i / 2; j++)
	{
		char temp = new_arr[j];
		new_arr[j] = new_arr[i - j - 1];
		new_arr[i - j - 1] = temp;
	}

	// Send to LCD
	LCD_voidSendString(new_arr);
}

 void LCD_voidDrawData(u8 copy_u8pattern,u8 data[],u8 copy_u8x,u8 copy_u8y)
 {
	 u8 CGRAM_Adrees=copy_u8pattern*8;
	 CLR_BIT(CGRAM_Adrees,7);
	 SET_BIT(CGRAM_Adrees,6);
	 LCD_voidSendCommand(CGRAM_Adrees);
	 for(u8 i=0;i<8;i++)
	 {
		 LCD_voidSendData(data[i]);
	 }
	 LCD_voidGotoXY(copy_u8x,copy_u8y);
	 LCD_voidSendData(copy_u8pattern);
 }

	
void LCD_SendFloat(float num, u8 decimal_places)
{
	if (num < 0)
	{
		LCD_voidSendData('-'); // Handle negative numbers
		num = -num;
	}

	int int_part = (int)num;  // Extract integer part
	float decimal_part = num - int_part;  // Extract decimal part

	// Display integer part
	LCD_voidIntDisplay(int_part);
	LCD_voidSendData('.');  // Display decimal point

	// Display fractional part
	for (u8 i = 0; i < decimal_places; i++)
	{
		decimal_part *= 10;
		int digit = (int)decimal_part;
		LCD_voidSendData(digit + '0');  // Convert to ASCII and display
		decimal_part -= digit;  // Remove displayed digit
	}
}


/*
 * Amit_project.c
 *
 * Created: 3/23/2025 9:01:04 PM
 *  Author: Kareem Glela
 */ 
/*


#include "main.h"

int main(void)
{
	Motor_voidInit(DIO_PORTB,DIO_PIN3,DIO_PIN4, DIO_PIN5);
  
	while (1)
	{
		for(u8 val=0;val <100; val++)
		{
			Motor_voidForward(val);
			_delay_ms(50);
		}
		
		for(u8 val=100;val>0; val--)
		{
			Motor_voidBackward(val);
			_delay_ms(50);
		}
		_delay_ms(1000);
		Motor_voidStop();
		_delay_ms(1000);
		
	}
}
*/
/*


#include "main.h"

int main(void)
{
	GI_voidEnable();
	DIO_VoidSetPinDir(DIO_PORTB,DIO_PIN3,OUTPUT);
	DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN5,OUTPUT);
	while (1)
	{
		for(u8 val=0;val <100; val++)
		{
			TIMER0_voidFastPWM(TIMER0_PRESCALER_1024,val);
			TIMER1_void10BitResFastPWM(OC1A_PIN,val);
			_delay_ms(50);
		}
		
	}
}





*/




/*****************************  timer over flow ********** 
void LED()
{
	static u16 Loc_u8count=0;
	Loc_u8count++;
	if(Loc_u8count==981)
	{
		Loc_u8count=0;
		DIO_voidTogglePinVal(DIO_PORTD,DIO_PIN3);
	}
}
int main(void)
{
	GI_voidEnable();
	DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN3,OUTPUT);
	DIO_VoidSetPinVal(DIO_PORTD,DIO_PIN3,LOW);
	DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN4,OUTPUT);
	DIO_VoidSetPinVal(DIO_PORTD,DIO_PIN4,LOW);
	TIMER0_voidInit(TIMER0_OVERFLOWMODE,TIMER0_PRESCALER_64);
	TCNT0_REG=105;
	TIMER0_voidSetCallBack(LED,TIMER0_OVERFLOWMODE);
	while (1)
	{
		DIO_voidTogglePinVal(DIO_PORTD,DIO_PIN4);
		_delay_ms(500);
	}
}
*/



/**************************** timer clear on compare match ********
void LED()
{
	static u16 Loc_u8count=0;
	Loc_u8count++;
	if(Loc_u8count==500)
	{
		Loc_u8count=0;
		DIO_voidTogglePinVal(DIO_PORTD,DIO_PIN3);
	}
}
int main(void)
{
	GI_voidEnable();
	DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN3,OUTPUT);
	DIO_VoidSetPinVal(DIO_PORTD,DIO_PIN3,LOW);
	DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN4,OUTPUT);
	DIO_VoidSetPinVal(DIO_PORTD,DIO_PIN4,LOW);
	TIMER0_voidInit(TIMER0_OUTCOMPMODE,TIMER0_PRESCALER_64);
	TCNT0_REG=105;
	TIMER0_voidSetCallBack(LED,TIMER0_OUTCOMPMODE);
	while (1)
	{
		DIO_voidTogglePinVal(DIO_PORTD,DIO_PIN4);
		_delay_ms(500);
	}
}
*/ 


/******************************** Fast PWM 
void LED()
{
	static u16 Loc_u8count=0;
	Loc_u8count++;
	if(Loc_u8count==500)
	{
		Loc_u8count=0;
		DIO_voidTogglePinVal(DIO_PORTD,DIO_PIN3);
	}
}
int main(void)
{
	GI_voidEnable();
	DIO_VoidSetPinDir(DIO_PORTB,DIO_PIN3,OUTPUT);
	DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN4,OUTPUT);
	DIO_VoidSetPinVal(DIO_PORTD,DIO_PIN4,LOW);
	TIMER0_voidFastPWM(TIMER0_PRESCALER_1024,80);
	
	while (1)
	{
		DIO_voidTogglePinVal(DIO_PORTD,DIO_PIN4);
		_delay_ms(100);
	}
}
*/


/*********************** phase correct PWM 

int main(void)
{
	GI_voidEnable();
	DIO_VoidSetPinDir(DIO_PORTB,DIO_PIN3,OUTPUT);
	//TIMER0_voidInit(TIMER0_OUTCOMPMODE,TIMER0_PRESCALER_64);
	TIMER0_voidPhasePWM(TIMER0_PRESCALER_256,30);
	while (1)
	{
	}
}

*/

/*
#include "main.h"

u8 repeat=0;
void button(void);
u8 check_password();
void analog_sensors();
u16 readADC(u8 channel);
u16 ADC_VAL=0;
u16 LDR_VAL=0;
f32 lm35_val=0.0;
u8 key=0xff;
u8 counter=0;
u8 True_Pasword[]={'1','2','3','0'};
volatile u8 pasword[4]={0};
u8 max_Repeated_wrong=0;
u8 num=0;
u8 T=0;
u8 time_system=0;
// False Symobol
u8 name0x0[] = { 0B00100, 0B00100, 0B00100, 0B00100, 0B00100, 0B11111, 0B00000, 0B00000 };
u8 name0x1[] = { 0B00100, 0B00100, 0B00110, 0B01001, 0B01001, 0B11111, 0B00000, 0B00000 };
u8 name0x2[] = { 0B00000, 0B00100, 0B01110, 0B01010, 0B01010, 0B11000, 0B00000, 0B00000 };
// True Symobol
u8 name0x3[] = { 0B00000, 0B00000, 0B01110, 0B10001, 0B11111, 0B00000, 0B00000, 0B00000 };
u8 name0x4[] = { 0B00000, 0B00000, 0B00001, 0B11101, 0B01111, 0B01000, 0B01110, 0B00000 };

int main(void)
{
	GI_voidEnable();
	LCD_voidInit();
	LCD_voidGotoXY(0,0);
	KEYPAD_voidInit();
	LCD_voidSendString("Welcome system !");
	_delay_ms(500);
	LCD_voidLcdClear();
	LCD_voidSendCommand(LCD_CURSOR_OFF);
	ADC_INT_voidInit();
	DIO_VoidSetPinDir(DIO_PORTB,DIO_PIN3,OUTPUT);
	DIO_VoidSetPinDir(DIO_PORTC,DIO_PIN7,OUTPUT);
	DIO_VoidSetPinVal(DIO_PORTC,DIO_PIN7,LOW);
	DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN5,OUTPUT);
	DIO_VoidSetPinVal(DIO_PORTD,DIO_PIN5,LOW);
	DIO_VoidSetPinDir(DIO_PORTC,DIO_PIN6,INPUT);
	DIO_VoidSetPinDir(DIO_PORTC,DIO_PIN5,OUTPUT);
	
	EXTI_voidEnableOrDisableInterruptPin(INT1,Enable);
	EXTI_voidControlSense(INT1,FALLING_EDGE);
	DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN3,INPUT);
	DIO_VoidSetPinVal(DIO_PORTD,DIO_PIN3,HIGH);
	EXTI_voidSetCallBack(button,INT1);
	TIMER1_void10BitResFastPWM(OC1A_PIN,0);
	TIMER1_void10BitResFastPWM(OC1B_PIN,0);
	TIMER0_voidFastPWM(TIMER0_PRESCALER_1024,0);
	while (1)
	{
		if (time_system==0)
		{
			time_system++;
			for (u8 i=0;i<3;i++)
			{
				TIMER1_void10BitResFastPWM(OC1A_PIN,0);
				TIMER1_void10BitResFastPWM(OC1B_PIN,0);
				LCD_voidLcdClear();
				LCD_voidSendString("Enter Password !");
				num=check_password();
				LCD_voidGotoXY(2,0);
				for(u8 i=0;i<4;i++)
				{
					LCD_voidSendData(pasword[i]);
				}
				_delay_ms(1000);
				if (num==1){LCD_voidLcdClear();DIO_VoidSetPinVal(DIO_PORTC,DIO_PIN7,HIGH);break;}
				else max_Repeated_wrong++;
				if (max_Repeated_wrong==3)
				{
					TIMER0_voidFastPWM(TIMER0_PRESCALER_1024,40);
					LCD_voidLcdClear();
					LCD_voidGotoXY(0,0);
					LCD_voidSendString("RESET");
					while(1);
				}
			}
			
		}
		
		
		analog_sensors();
		
	}
}


void analog_sensors()
{
	
	ADC_voidStartConversion(ADC2);
	LDR_VAL=ADC_u16GetResult();
	_delay_ms(100);
	ADC_voidStartConversion(ADC1);
	ADC_VAL=ADC_u16GetResult();
	LCD_voidGotoXY(0,0);
	LCD_voidSendString("LDR_val=");
	LCD_voidSendString("    ");
	LCD_voidGotoXY(0,9);
	LCD_voidSendString("    ");
	LCD_voidGotoXY(0,9);
	LCD_voidIntDisplay(LDR_VAL);
	lm35_val=((f32)ADC_VAL*5/1023)*100;
	LCD_voidGotoXY(1,0);
	LCD_voidSendString("lm35_val=");
	LCD_SendFloat(lm35_val,2);
	LCD_voidGotoXY(3,0);
	LCD_voidSendString("Repeated=");
	LCD_voidIntDisplay(repeat);
	if(26<lm35_val &&lm35_val<30)
	{
		TIMER1_void10BitResFastPWM(OC1A_PIN,50);
		_delay_ms(100);
		TIMER1_void10BitResFastPWM(OC1B_PIN,50);
	}else if (lm35_val>=30)
	{
		TIMER1_void10BitResFastPWM(OC1A_PIN,90);
		_delay_ms(100);
		TIMER1_void10BitResFastPWM(OC1B_PIN,70);
		}else {
		
		TIMER1_void10BitResFastPWM(OC1A_PIN,0);
		_delay_ms(100);
		TIMER1_void10BitResFastPWM(OC1B_PIN,0);
	}
	if (DIO_U8ReadPinVal(DIO_PORTC,DIO_PIN6))
	{
		
		DIO_VoidSetPinVal(DIO_PORTC,DIO_PIN5,HIGH);
		LCD_voidGotoXY(2,0);
		LCD_voidSendString("There is obj");
		}else{
		LCD_voidGotoXY(2,0);
		LCD_voidSendString("            ");
		LCD_voidGotoXY(2,0);
		LCD_voidSendString("NO obj");
	DIO_VoidSetPinVal(DIO_PORTC,DIO_PIN5,LOW);}
}



u8 check_password()
{
	u8 c=0;
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
		LCD_voidGotoXY(3,0);
		LCD_voidSendString("Right password");
		LCD_voidDrawData(0,name0x4,1,14);
		LCD_voidDrawData(2,name0x3,1,15);
		
		_delay_ms(200);
		return 1;
	}else
	{
		LCD_voidGotoXY(3,0);
		LCD_voidSendString("Wrong Password");
		
		LCD_voidDrawData(1,name0x1,1,13);
		LCD_voidDrawData(0,name0x0,1,14);
		LCD_voidDrawData(2,name0x2,1,15);
		
		_delay_ms(200);
		return 0;
	}
	
	return 0;
}

u16 readADC(u8 channel) {
	u16 sum = 0;
	for (u8 i = 0; i < 10; i++) {
		sum += ADC_u16ReadChannel(channel);
		_delay_ms(5);
	}
	return sum / 10;
}


void button(void){
	repeat++;
}

*/
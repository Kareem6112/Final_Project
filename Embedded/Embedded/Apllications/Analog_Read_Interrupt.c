/*
 * Analog_Read_Interrupt.c
 *
 * Created: 3/9/2025 6:53:10 PM
 *  Author: kareem
 */ 

/*
u8 u8_var=0;
u16 adc_val=0;
f32 analog_adc=0.0;
void Increment_void()
{
	u8_var++;
	DIO_voidTogglePinVal(DIO_PORTC,DIO_PIN7);
}
void Decrement_void()
{
	u8_var--;
	DIO_voidTogglePinVal(DIO_PORTC,DIO_PIN2);
}
int main(void)
{
	
	 DIO_VoidSetPinDir(DIO_PORTC,DIO_PIN7,OUTPUT);
	 DIO_VoidSetPinDir(DIO_PORTC,DIO_PIN2,OUTPUT);
	 DIO_VoidSetPinDir(DIO_PORTD,DIO_PIN6,OUTPUT);
	 GI_voidEnable();
	 LCD_voidInit();
	 ADC_voidInit();
	 LCD_voidSendCommand(LCD_CURSOR_OFF);
	
	 
	
	while (1)
	{
		adc_val=ADC_u16ReadChannel(ADC0);
		//LCD_voidGotoXY(0,0);
		
		LCD_voidGotoXY(0,0);
		LCD_voidSendString("      ");
		LCD_voidGotoXY(0,0);
		LCD_voidIntDisplay(adc_val);
		analog_adc=(f32)adc_val*5/1023;
		LCD_voidGotoXY(1,0);
		
		LCD_voidIntDisplay(analog_adc);
		_delay_ms(300);
	}
}
*/


 /*EXTI_voidEnableOrDisableInterruptPin(INT0,Enable);
	 EXTI_voidEnableOrDisableInterruptPin(INT1,Enable);
	 EXTI_voidControlSense(INT0,FALLING_EDGE_INT01);
	 EXTI_voidControlSense(INT0,FALLING_EDGE_INT01);
	 EXTI_voidSetCallBack(Increment_void,INT0);
	 EXTI_voidSetCallBack(Decrement_void,INT1);*/
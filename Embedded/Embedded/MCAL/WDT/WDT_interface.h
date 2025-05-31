/*
 * WDT_interface.h
 *
 * Created: 4/4/2025 4:37:38 PM
 *  Author: Kareem Glela
 */ 


#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_
/*5V Time out for watch dog timer */
#define Time_16_3ms 0
#define Time_32_5ms 1
#define Time_65_0ms 2
#define Time_0_13s 3
#define Time_0_26s 4
#define Time_0_52s 5
#define Time_1_0s 6
#define Time_2_1s 7

#define WDE_PIN   3
#define WDTOE_PIN 4  
void WDT_voidStart(u8 copy_u8time);		 // Difference between WDT and normal timer that it generate System Reset Rather than normal interrupt
void WDT_voidStop();					// The WDT Has an independent Oscillator 


#endif /* WDT_INTERFACE_H_ */
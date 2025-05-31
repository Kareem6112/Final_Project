/*
 * ADC_interface.h
 *
 * Created: 3/8/2025 10:37:22 PM
 *  Author: AMIT
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


/*ADC prescaler */

#define  ADC_2_PRESCALER          1 
#define  ADC_4_PRESCALER          2
#define  ADC_8_PRESCALER          3
#define  ADC_16_PRESCALER         4
#define  ADC_32_PRESCALER         5
#define  ADC_64_PRESCALER         6
#define  ADC_128_PRESCALER        7

/*select adc prescaler */
#define  ADC_PRESCALER     ADC_128_PRESCALER
#define ADC_MAX_VAL  5
/* adc channel */

#define  ADC0                    0
#define  ADC1                    1
#define  ADC2                    2
#define  ADC3                    3
#define  ADC4                    4
#define  ADC5                    5
#define  ADC6                    6
#define  ADC7                    7


/* adc Differential channel */
#define  PDI_ADC1_NDI_ADC0_G_10                    9			  /*Positive Differential Input:ADC1 , Negative Differential Input:ADC0 ,Gain 10x*/
#define  PDI_ADC1_NDI_ADC0_G_200			       11			 /*Positive Differential Input:ADC1 , Negative Differential Input:ADC0 ,Gain 200x*/
#define  PDI_ADC3_NDI_ADC2_G_10                    13			/*Positive Differential Input:ADC3 , Negative Differential Input:ADC2 ,Gain 10x*/
#define  PDI_ADC3_NDI_ADC2_G_200                   15		   /*Positive Differential Input:ADC3 , Negative Differential Input:ADC2 ,Gain 200x*/
#define  PDI_ADC7_NDI_ADC1_G_1                     23		  /*Positive Differential Input:ADC7 , Negative Differential Input:ADC1 ,Gain 1x*/
#define  PDI_ADC6_NDI_ADC1_G_1                     22		 /*Positive Differential Input:ADC6 , Negative Differential Input:ADC1 ,Gain 1x*/
#define  PDI_ADC5_NDI_ADC1_G_1                     21	    /*Positive Differential Input:ADC5 , Negative Differential Input:ADC1 ,Gain 1x*/
#define  PDI_ADC4_NDI_ADC1_G_1                     20	   /*Positive Differential Input:ADC4 , Negative Differential Input:ADC1 ,Gain 1x*/



void ADC_voidInit(void) ; 


u16 ADC_u16ReadChannel(u8 copy_u8channel) ; 

u16 ADC_u16map(u16 input,u16 input_min,u16 input_max,u16 output_min,u16 output_max);

u16 ADC_u16ReadDifferentialINPUTChannel(u8 copy_u8channel);

#endif /* ADC_INTERFACE_H_ */



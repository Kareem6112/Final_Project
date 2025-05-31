/*
 * RTC_interface.h
 *
 * Created: 5/21/2025 11:58:05 PM
 *  Author: kareem
 */ 


#ifndef RTC_INTERFACE_H_
#define RTC_INTERFACE_H_


typedef struct {
	u8 seconds;
	u8 minutes;
	u8 hours;
	u8 day;
	u8 date;
	u8 month;
	u8 year;
} RTC_TimeDate;

void DS3232_voidGetDateTime(RTC_TimeDate* time); // 

#endif /* RTC_INTERFACE_H_ */
/*
 * RTC.h
 *
 *  Created on: 25.6.2015
 *      Author: SESA330795
 */

#ifndef RTC_H_
#define RTC_H_

#include "rtc/Wire.h"
#include "state.h"
#include "Arduino.h"



class RTC {
public:
	RTC(State &pState);
	void update();
	byte getSecond();
	byte getMinute();
	byte getHour();
	void setSecond(int);
	void setMinute(int);
	void setHour(int);

private:
	State *state;
	byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
	byte bcdToDec(byte);
	void readDS3231time(void);
};

#endif /* RTC_H_ */

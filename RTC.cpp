/*
 * RTC.cpp
 *
 *  Created on: 25.6.2015
 *      Author: SESA330795
 */

#include "RTC.h"

#define DS3231_I2C_ADDRESS 0x68
RTC::RTC(State &pState) {
	state = &pState;
	Serial.begin(9600);
	Wire.begin();
}

void RTC::readDS3231time()
{
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  // request seven bytes of data from DS3231 starting from register 00h
  second = bcdToDec(Wire.read() & 0x7f);
  minute = bcdToDec(Wire.read());
  hour = bcdToDec(Wire.read() & 0x3f);
  dayOfWeek = bcdToDec(Wire.read());
  dayOfMonth = bcdToDec(Wire.read());
  month = bcdToDec(Wire.read());
  year = bcdToDec(Wire.read());
}

void RTC::update() {
	switch(*state) {
	case IDLE:
		readDS3231time();
	}
}

byte RTC::getSecond() {
	return second;
}

byte RTC::getMinute() {
	return minute;
}

byte RTC::getHour() {
	return hour;
}

void RTC::setSecond(int pSecond) {
	second = pSecond;
}

void RTC::setMinute(int pMinute) {
	minute = pMinute;
}

void RTC::setHour(int pHour) {
	hour = pHour;
}

byte RTC::bcdToDec(byte val)
{
  return( (val/16*10) + (val%16) );
}


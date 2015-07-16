/*
 * RTC.cpp
 *
 *  Created on: 25.6.2015
 *      Author: SESA330795
 */

#include "RTC.h"

#define DS3231_I2C_ADDRESS 0x68

RTC::RTC() {
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

void RTC::setDS3231time()
{
  // sets time and date data to DS3231
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(minute)); // set minutes
  Wire.write(decToBcd(hour)); // set hours
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month)); // set month
  Wire.write(decToBcd(year)); // set year (0 to 99)
  Wire.endTransmission();
}

void RTC::update() {
	readDS3231time();
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

byte RTC::decToBcd(byte val)
{
  return( (val/10*16) + (val%10) );
}

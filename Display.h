/*
 * Display.h
 *
 *  Created on: 24.6.2015
 *      Author: SESA330795
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "state.h"
#include "display/LiquidCrystal.h"
#include "RTC.h"

class Display {
public:
	Display(State &pState, RTC &pRtc);
	virtual ~Display();
	void update();
private:
	State *state;
	LiquidCrystal *lcd;
	RTC *rtc;
	void initLcd();
	void printTime();
};

#endif /* DISPLAY_H_ */

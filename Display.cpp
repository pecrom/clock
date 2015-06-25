/*
 * Display.cpp
 *
 *  Created on: 24.6.2015
 *      Author: SESA330795
 */

#include "Display.h"
#include "state.h"
#include "display/LiquidCrystal.h"
#include "RTC.h"

const int ROWS = 2;
const int COLS = 16;

Display::Display(State &pState, RTC &pRtc) {
	state = &pState;
	rtc = &pRtc;
	initLcd();
}

void Display::initLcd() {
	lcd = new LiquidCrystal(8, 9, 10, 11, 12, 13);
	lcd->begin(COLS, ROWS);
}

void Display::update() {
	lcd->clear();
	switch(*state) {
	case IDLE:
			lcd->print(rtc->getHour(), DEC);
			lcd->print(":");
			lcd->print(rtc->getMinute(), DEC);
			lcd->print(":");
			lcd->print(rtc->getSecond(), DEC);
		break;
	case HOUR_SETTING:
			lcd->print("HOUR_SETTING");
	}
}

Display::~Display() {
	// TODO Auto-generated destructor stub
}


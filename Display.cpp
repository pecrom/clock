/*
 * Display.cpp
 *
 *  Created on: 24.6.2015
 *      Author: SESA330795
 */

#include "Display.h"
#include "state.h"
#include "display/LiquidCrystal.h"

const int ROWS = 2;
const int COLS = 16;

State *state;
LiquidCrystal *lcd;

Display::Display(State &pState) {
	state = &pState;
	initLcd();
	lcd->print("test12");
}

void Display::initLcd() {
	lcd = new LiquidCrystal(8, 9, 10, 11, 12, 13);
	lcd->begin(COLS, ROWS);
}

void Display::update() {
	lcd->clear();
	switch(*state) {
	case IDLE:
			lcd->print("IDLE");
		break;
	case HOUR_SETTING:
			lcd->print("HOUR_SETTING");
	}
}

Display::~Display() {
	// TODO Auto-generated destructor stub
}


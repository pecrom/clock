/*
 * Display.cpp
 *
 *  Created on: 24.6.2015
 *      Author: SESA330795
 */

#include "Display.h"
#include "display/LiquidCrystal.h"
#include "Settings.h"


Display::Display() {
	initLcd();
}

void Display::initLcd() {
	lcd = new LiquidCrystal(LCD_RS, LCD_E, LCD_DB4, LCD_DB5, LCD_DB6, LCD_DB7);
	lcd->begin(DISPLAY_COLS, DISPLAY_ROWS);
}

void Display::print(char pText[]) {
	lcd->clear();
	lcd->print(pText);
}


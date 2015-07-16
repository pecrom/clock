/*
 * Display.h
 *
 *  Created on: 24.6.2015
 *      Author: SESA330795
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "display/LiquidCrystal.h"

class Display {

public:
	Display();
	void print(char[]);

private:
	LiquidCrystal *lcd;
	void initLcd();

};

#endif /* DISPLAY_H_ */

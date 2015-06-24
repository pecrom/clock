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

class Display {
public:
	Display(State &pState);
	virtual ~Display();
	void update();
private:
	void initLcd();

};

#endif /* DISPLAY_H_ */

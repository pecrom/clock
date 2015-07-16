/*
 * Button.h
 *
 *  Created on: 16.7.2015
 *      Author: SESA330795
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "button/Bounce.h"
#include "Arduino.h"

class Button {

public:
	Button(int);
	bool pressed(void);


private:
	static const int DEBOUNCE_TIME;
	int pinNumber;
	int previousState;
	int readState;
	Bounce *but;

	void update();
};

#endif /* BUTTON_H_ */

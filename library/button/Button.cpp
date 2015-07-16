/*
 * Button.cpp
 *
 *  Created on: 16.7.2015
 *      Author: SESA330795
 */

#include "Button.h"


const int Button::DEBOUNCE_TIME = 5;

Button::Button(int pPinNumber) {
	pinNumber = pPinNumber;
	pinMode(pinNumber, INPUT);
	but = new Bounce(pinNumber, DEBOUNCE_TIME);
	previousState = LOW;
	readState = LOW;
}

bool Button::pressed() {
	bool pressed = false;

	update();

	if (readState == LOW) {
		previousState = LOW;
	}

	if (readState == HIGH && previousState == LOW) {
		previousState = HIGH;
		pressed = true;
	}
	return pressed;
}

void Button::update() {
	but->update();
	readState = but->read();
}

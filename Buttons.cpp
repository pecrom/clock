/*
 * Buttons.cpp
 *
 *  Created on: 25.6.2015
 *      Author: SESA330795
 */

#include "Buttons.h"
#include "Arduino.h"

const int BUT_SETTINGS = 7;
const int BUT_BACK = 6;
const int BUT_UP = 4;
const int BUT_RIGHT = 5;

int backButtonOld = LOW;
int settingsButtonOld = LOW;
int upButtonOld = LOW;
int rightButtonOld = LOW;

Buttons::Buttons(State &pState) {
	state = &pState;
	pinMode(BUT_SETTINGS, INPUT);
	pinMode(BUT_BACK, INPUT);
	pinMode(BUT_UP, INPUT);
	pinMode(BUT_RIGHT, INPUT);
	settingsButton = new Bounce(BUT_SETTINGS, 5);
	backButton = new Bounce(BUT_BACK, 5);
	upButton = new Bounce(BUT_UP, 5);
	rightButton = new Bounce(BUT_RIGHT, 5);

	Serial.begin(9600);
}

void Buttons::update() {
	settingsButton->update();
	  backButton->update();
	  upButton->update();
	  rightButton->update();

	boolean settingsPressed = false;
	boolean backPressed = false;
	boolean upPressed = false;
	boolean rightPressed = false;
	boolean changeState = false;

	int settingsButtonState = settingsButton->read();
	int backButtonState = backButton->read();
	int upButtonState = upButton->read();
	int rightButtonState = rightButton->read();

	if (settingsButtonState == LOW) {
		settingsButtonOld = LOW;
	}

	if (backButtonState == LOW) {
		backButtonOld = LOW;
	}

	if (upButtonState == LOW) {
		upButtonOld = LOW;
	}

	if (rightButtonState == LOW) {
		rightButtonOld = LOW;
	}

	if (settingsButtonState == HIGH && settingsButtonOld == LOW) {
		settingsButtonOld = HIGH;
		settingsPressed = true;
		changeState = true;
	}

	if (backButtonState == HIGH && backButtonOld == LOW) {
		backButtonOld = HIGH;
		backPressed = true;
		changeState = true;
	}

	if (upButtonState == HIGH && upButtonOld == LOW) {
		upButtonOld = HIGH;
		upPressed = true;
		changeState = true;
	}

	if (rightButtonState == HIGH && rightButtonOld == LOW) {
		rightButtonOld = HIGH;
		rightPressed = true;
		changeState = true;
	}

	if (changeState == true) {
		findNextState(settingsPressed, backPressed, upPressed, rightPressed);
	}
}

void Buttons::findNextState(boolean pSettingsButton, boolean pBackButton,
		boolean pUpButton, boolean pRightButton) {
	switch (*state) {
	case IDLE:
		if (pSettingsButton == true) {
			Serial.println("IDLE -> MENU");

		}
		break;
	case HOUR_SETTING:
		if (pBackButton == true) {
			Serial.println("MENU -> IDLE");

		}
		if (pSettingsButton == true) {
			//setDS3231time(second, minute, hour, dayOfWeek, dayOfMonth, month, year);

		}
		if (pUpButton == true) {

		}
		if (pRightButton == true) {

		}
		break;
	case MINUTE_SETTING:
		if (pBackButton == true) {

		}
		if (pSettingsButton == true) {

		}
		if (pUpButton == true) {
			Serial.println("MINUTE");

		}
		if (pRightButton == true) {

		}
		break;

	case SECOND_SETTING:
		if (pBackButton == true) {

		}
		if (pSettingsButton == true) {

		}
		if (pUpButton == true) {
			Serial.println("SECOND");

		}
		if (pRightButton == true) {

		}
		break;
	}
}

Buttons::~Buttons() {
	// TODO Auto-generated destructor stub
}


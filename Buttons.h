/*
 * Buttons.h
 *
 *  Created on: 25.6.2015
 *      Author: SESA330795
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include "button/Bounce.h"
#include "state.h"
#include "Arduino.h"

class Buttons {
public:
	Buttons(State &);
	void update(void);
	virtual ~Buttons();
private:
	Bounce *settingsButton, *backButton, *upButton, *rightButton;
	State *state;
	void findNextState(boolean, boolean, boolean, boolean);
};

#endif /* BUTTONS_H_ */

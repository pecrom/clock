/*
 * Buttons.h
 *
 *  Created on: 25.6.2015
 *      Author: SESA330795
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_


#include "state.h"
#include "Arduino.h"
#include "RTC.h"
#include "button/Button.h"

class Buttons {

public:
	Buttons(int, int, int, int); //Buttons(settings, back, up, right) - these parameters means to which pins the buttons are connected
	bool settingsPressed(void);
	bool backPressed(void);
	bool upPressed(void);
	bool rightPressed(void);

private:
	Button *m_butSettings;
	Button *m_butBack;
	Button *m_butUp;
	Button *m_butRight;
};

#endif /* BUTTONS_H_ */

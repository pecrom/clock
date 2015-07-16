/*
 * Buttons.cpp
 *
 *  Created on: 25.6.2015
 *      Author: SESA330795
 */

#include "Buttons.h"
#include "Arduino.h"
#include "RTC.h"

const int BUT_SETTINGS = 7;
const int BUT_BACK = 6;
const int BUT_UP = 4;
const int BUT_RIGHT = 5;

Buttons::Buttons(int pSettings, int pBack, int pUp, int pRight) {
	m_butSettings = new Button(pSettings);
	m_butBack = new Button(pBack);
	m_butUp = new Button(pUp);
	m_butRight = new Button(pRight);
}

bool Buttons::settingsPressed() {
	return m_butSettings->pressed();
}

bool Buttons::backPressed() {
	return m_butBack->pressed();
}

bool Buttons::upPressed() {
	return m_butUp->pressed();
}

bool Buttons::rightPressed() {
	return m_butRight->pressed();
}

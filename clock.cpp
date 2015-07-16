// Do not remove the include below
#include "clock.h"
#include "display/LiquidCrystal.h"
#include "Display.h"
#include "RTC.h"
#include "Buttons.h"
#include "Settings.h"
#include "state.h"

//global variables
State state;
Display *display;
RTC *rtc;
Buttons *buttons;

//initialization
void setup(){
	state = IDLE;
	rtc = new RTC();
	buttons = new Buttons(BUT_SETTINGS, BUT_BACK, BUT_UP, BUT_RIGHT);
	display = new Display();
}

//main loop
void loop()
{
	switch (state) {
	case IDLE:
		idleState();
		break;
	case HOUR_SETTING:
		hourState();
		break;
	case MINUTE_SETTING:
		minuteState();
		break;
	case SECOND_SETTING:
		secondState();
		break;
	}

	delay(LOOP_DELAY);
}

void secondState() {
	if (buttons->backPressed()) {
		state = MINUTE_SETTING;
	} else if (buttons->upPressed()){
		rtc->setSecond(rtc->getSecond() + 1);
	} else if (buttons->rightPressed()) {
		state = HOUR_SETTING;
	} else if (buttons->settingsPressed()){
		rtc->setDS3231time();
		state = IDLE;
	} else{
		char *second = prepareSecondDisplay();
		display->print(second);
		delete(second);
	}
}

char* prepareSecondDisplay() {
	char *secondDisplay = (char*) malloc(11);
	secondDisplay[0] = 'S';
	secondDisplay[1] = 'e';
	secondDisplay[2] = 'c';
	secondDisplay[3] = 'o';
	secondDisplay[4] = 'n';
	secondDisplay[5] = 'd';
	secondDisplay[6] = ':';
	secondDisplay[7] = ' ';
	secondDisplay[8] = (rtc->getSecond() / 10) + 48;
	secondDisplay[9] = (rtc->getSecond() % 10) + 48;
	secondDisplay[10] = '\0';
	return secondDisplay;
}

void minuteState() {
	if (buttons->backPressed()) {
		state = HOUR_SETTING;
	} else if (buttons->upPressed()){
		rtc->setMinute(rtc->getMinute() + 1);
	} else if (buttons->rightPressed()) {
		state = SECOND_SETTING;
	} else if (buttons->settingsPressed()){
		rtc->setDS3231time();
		state = IDLE;
	} else{
		char *minute = prepareMinuteDisplay();
		display->print(minute);
		delete(minute);
	}
}

char* prepareMinuteDisplay() {
	char *minuteDisplay = (char*) malloc(11);
	minuteDisplay[0] = 'M';
	minuteDisplay[1] = 'i';
	minuteDisplay[2] = 'n';
	minuteDisplay[3] = 'u';
	minuteDisplay[4] = 't';
	minuteDisplay[5] = 'e';
	minuteDisplay[6] = ':';
	minuteDisplay[7] = ' ';
	minuteDisplay[8] = (rtc->getMinute() / 10) + 48;
	minuteDisplay[9] = (rtc->getMinute() % 10) + 48;
	minuteDisplay[10] = '\0';
	return minuteDisplay;
}

void hourState() {
	if (buttons->backPressed()) {
		state = IDLE;
	} else if (buttons->upPressed()){
		rtc->setHour(rtc->getHour() + 1);
	} else if (buttons->rightPressed()) {
		state = MINUTE_SETTING;
	} else if (buttons->settingsPressed()){
		rtc->setDS3231time();
		state = IDLE;
	} else{
		char *hour = prepareHourDisplay();
		display->print(hour);
		delete(hour);
	}
}

char* prepareHourDisplay() {
	char *hourDisplay = (char*) malloc(9);
	hourDisplay[0] = 'H';
	hourDisplay[1] = 'o';
	hourDisplay[2] = 'u';
	hourDisplay[3] = 'r';
	hourDisplay[4] = ':';
	hourDisplay[5] = ' ';
	hourDisplay[6] = (rtc->getHour() / 10) + 48;
	hourDisplay[7] = (rtc->getHour() % 10) + 48;
	hourDisplay[8] = '\0';
	return hourDisplay;
}

void idleState() {
	if (buttons->settingsPressed()) {
		state = HOUR_SETTING;
	} else {
		rtc->update();
		char* time = prepareIdleDisplay();
		display->print(time);
		delete(time);
	}

}

char* prepareIdleDisplay() {
	char *time = (char*) malloc(9);
	time[0] = (rtc->getHour() / 10) + 48;
	time[1] = (rtc->getHour() % 10) + 48;
	time[2] = ':';
	time[3] = (rtc->getMinute() / 10) + 48;;
	time[4] = (rtc->getMinute() % 10) + 48;
	time[5] = ':';
	time[6] = (rtc->getSecond() / 10) + 48;
	time[7] = (rtc->getSecond() % 10) + 48;
	time[8] = '\0';
	return time;
}

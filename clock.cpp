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
	}

	delay(LOOP_DELAY);
}

void idleState() {
	rtc->update();
	char* time = prepareTime();
	display->print(time);
	delete(time);
}

char* prepareTime() {
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

// Do not remove the include below
#include "clock.h"
#include "display/LiquidCrystal.h"
#include "Display.h"
#include "RTC.h"

//global variables
State state;
Display *display;
RTC *rtc;

//initialization
void setup(){
	state = IDLE;
	rtc = new RTC(state);
	display = new Display(state, *rtc);
}

//main loop
void loop()
{
	rtc->update();
	display->update();
	delay(100);
}

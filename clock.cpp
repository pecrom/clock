// Do not remove the include below
#include "clock.h"
#include "display/LiquidCrystal.h"
#include "Display.h"
#include "RTC.h"
#include "Buttons.h"

//global variables
State state;
Display *display;
RTC *rtc;
Buttons *buttons;

//initialization
void setup(){
	state = IDLE;
	rtc = new RTC(state);
	buttons = new Buttons(state, *rtc);
	display = new Display(state, *rtc);
}

//main loop
void loop()
{
	buttons->update();
	rtc->update();
	display->update();
	delay(100);
}

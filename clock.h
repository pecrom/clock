// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef clock_H_
#define clock_H_
#include "Arduino.h"
//add your includes for the project clock here


//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
void idleState();
void hourState();
void minuteState();
void secondState();
char* prepareSecondDisplay();
char* prepareMinuteDisplay();
char* prepareHourDisplay();
char* prepareIdleDisplay();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project clock here




//Do not add code below this line
#endif /* clock_H_ */

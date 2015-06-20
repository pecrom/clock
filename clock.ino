#include <Wire.h>
#include <Bounce.h>
#include <LiquidCrystal.h>
#include "buttons.h"

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
//Buttons
const int BUT_SETTINGS = 7;
const int BUT_BACK = 6;
const int BUT_UP = 4;
const int BUT_RIGHT = 5;

//Time chip
#define DS3231_I2C_ADDRESS 0x68
byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;

//Buttons old
int backButtonOld = LOW;
int settingsButtonOld = LOW;
int upButtonOld = LOW;
int rightButtonOld = LOW;

char idleText[] = "IDLE";
char menuText[] = "MENU";

const int IDLE = 0;
const int HOUR_SETTING = 1;
const int MINUTE_SETTING = 2;
const int SECOND_SETTING = 3;

int state = IDLE;

//Debouncing
Bounce settingsButton = Bounce(BUT_SETTINGS, 5);
Bounce backButton = Bounce(BUT_BACK, 5);
Bounce upButton = Bounce(BUT_UP, 5);
Bounce rightButton = Bounce(BUT_RIGHT, 5);

void setup() {
  pinMode(BUT_SETTINGS, INPUT);
  pinMode(BUT_BACK, INPUT);
  pinMode(BUT_UP, INPUT);
  pinMode(BUT_RIGHT, INPUT);
  lcd.begin(16, 2);
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  updateButtons();
  readButtonsAndFindState();
  updateDisplay(state);
  delay(50);
}



void readButtonsAndFindState() {
  boolean settingsPressed = false;
  boolean backPressed = false;
  boolean upPressed = false;
  boolean rightPressed = false;
  boolean changeState = false;  
  
  int settingsButtonState = settingsButton.read();
  int backButtonState = backButton.read();
  int upButtonState = upButton.read();
  int rightButtonState = rightButton.read();
  
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
    Serial.println("settings");
  }
  
  if (backButtonState == HIGH && backButtonOld == LOW) {
    backButtonOld = HIGH;
    backPressed = true; 
    changeState = true;
    Serial.println("back");
  }
  
  if (upButtonState == HIGH && upButtonOld == LOW) {
    upButtonOld = HIGH;
    upPressed = true; 
    changeState = true;
    Serial.println("up");
  }
  
  if (rightButtonState == HIGH && rightButtonOld == LOW) {
    rightButtonOld = HIGH;
    rightPressed = true; 
    changeState = true;
    Serial.println("right");
  }
  
  if (changeState) {    
    state = findNextState(state, settingsPressed, backPressed, upPressed, rightPressed);  
  }
  
}

void updateButtons() {
  settingsButton.update();
  backButton.update();
  upButton.update();
  rightButton.update();
}

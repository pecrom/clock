

void updateDisplay(int pState) {
  switch (pState) {
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
}

void hourState() {
  lcd.clear();  
  lcd.print("Hour: "); 
  lcd.print(hour);
}

void minuteState() {
  lcd.clear();  
  lcd.print("Minute: "); 
  lcd.print(minute);
}

void secondState() {
  lcd.clear();  
  lcd.print("Second: "); 
  lcd.print(second);
}

void idleState() {
  lcd.clear();
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
  lcd.clear();
  lcd.setCursor(0,0);
  // send it to the serial monitor
  if (hour < 10){
    lcd.print("0");
  }
  lcd.print(hour, DEC);
  // convert the byte variable to a decimal number when displayed
  lcd.print(":");
  if (minute<10)
  {
    lcd.print("0");
  }
  lcd.print(minute, DEC);
  lcd.print(":");
  if (second<10)
  {
    lcd.print("0");
  }
  lcd.print(second, DEC); 
}

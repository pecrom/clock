#include <Arduino.h>


int findNextState(int pState, boolean pSettingsButton, boolean pBackButton, boolean pUpButton, boolean pRightButton) {
   switch (pState) {
     case IDLE:
            if (pSettingsButton == true) {
              Serial.println("IDLE -> MENU");
              hour = 12;
              minute = 0;
              second = 0;
              return HOUR_SETTING;
            } 
           break;
      case HOUR_SETTING:
            if (pBackButton == true) {
              Serial.println("MENU -> IDLE");
              return IDLE;
            } 
            if (pSettingsButton == true) {
               setDS3231time(second, minute, hour, dayOfWeek, dayOfMonth, month, year);
               return IDLE;
            }  
             if (pUpButton == true) {
               Serial.println("HOUR");
               hour = hour+1;
               if (hour > 23) {
                 hour = 0; 
               }
            }  
            if (pRightButton == true) {
              return MINUTE_SETTING;
            }   
           break;
       case MINUTE_SETTING:
         if (pBackButton == true) {
           return HOUR_SETTING;
         } 
          if (pSettingsButton == true) {
            setDS3231time(second, minute, hour, dayOfWeek, dayOfMonth, month, year);
            return IDLE;
          }  
          if (pUpButton == true) {
               Serial.println("MINUTE");
               minute = minute+1;
               if (minute > 59) {
                 minute = 0; 
               }
          }  
          if (pRightButton == true) {
              return SECOND_SETTING;
          }   
         break;
         
       case SECOND_SETTING:
         if (pBackButton == true) {
           return MINUTE_SETTING;
         } 
          if (pSettingsButton == true) {
            setDS3231time(second, minute, hour, dayOfWeek, dayOfMonth, month, year);
            return IDLE;
          }  
          if (pUpButton == true) {
               Serial.println("SECOND");
               second = second+1;
               if (second > 59) {
                 second = 0; 
               }
          }  
          if (pRightButton == true) {
              return HOUR_SETTING;
          }   
         break;
   }
   return pState;
}

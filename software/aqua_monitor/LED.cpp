//thanks to: 
//https://www.youtube.com/watch?v=TtO4H_t_jX4

#include "Arduino.h"
#include "LED.h"
#include "temperature.h"
#include "ph.h"

void LED_init(){
pinMode(LED_PIN_R, OUTPUT);
pinMode(LED_PIN_G, OUTPUT);
//this connects the pin to ground
digitalWrite(LED_PIN_COMMON, LOW);
//control to ensure current flow is correct
pinMode(LED_PIN_COMMON, INPUT);
}

void colorON(int color, int intensity){
    analogWrite(colorPin[color], intensity);
}

void Breath_LED_R(int color){
    for(int i=0; i<256; i++){
        colorON(red,i);
        delay(50);
    }
    for(int i=255; i<0; i--){
        colorON(red,i);
        delay(50);
    }    
}

void Breath_LED_G(int color){
    for(int i=0; i<256; i++){
        colorON(green,i);
        delay(50);
    }
    for(int i=255; i<0; i--){
        colorON(green,i);
        delay(50);
    }    
}

void LED_interface(){
    
    //allow flow through common LED pin
    pinMode(LED_PIN_COMMON, OUTPUT);
    //pull status check for boolean values on alarms

    check_temp_for_alarm();
    check_ph_for_alarm();

    //statement for temperature to alert 
    if((AlarmTempPass = true) && (AlarmPhPass = false)){
        //if high alarms = led is red with pulses   
        Breath_LED_R();
        delay(500);
        }
    
    //statement for temperature to alert
    else if((AlarmPhPass = true) && (AlarmTempPass = false)){
        //if high alarms = led is red with pulses   
        Breath_LED_R();
        delay(50);
        }

    else if((AlarmPhPass = true) && (AlarmTempPass = true)){
        //if high alarms = led is red with pulses   
        Breath_LED_R();
        delay(10);
        }
        
    //if no high alarms = led is green
    else{
        Breath_LED_G();      
    }
}


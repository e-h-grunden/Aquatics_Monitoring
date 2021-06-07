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

    //statement for temperature to alert 
    if(check_temp_for_alarm() == true){
        //if high alarms = led is red with pulses   
        Breath_LED_R(red);
        delay(500);
        }
    
    //statement for temperature to alert
    else if(check_ph_for_alarm() == true){
        //if high alarms = led is red with pulses   
        Breath_LED_R(red);
        delay(50);
        }

    else if((check_temp_for_alarm() == true) & (check_ph_for_alarm() == true)){
        //if high alarms = led is red with pulses   
        Breath_LED_R(red);
        delay(5);
        }
        
    //if no high alarms = led is green
    else{
        Breath_LED_G(green);      
    }
    
    return 0;
}


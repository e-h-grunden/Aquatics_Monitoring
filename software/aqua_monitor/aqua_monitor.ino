//LIBRARIES
#include "ph.h"
#include "ambient.h"
#include "LED.h"
#include "light.h"
#include "temperature.h"
#include "display.h"
#include <DHT.h>               // For DHT-22 Temperature and Humidity Sensor
#include <OneWire.h>           // For DS18B20 Temperature Sensor
#include <DallasTemperature.h> // For DS18B20 Temperature Sensor
#include "Adafruit_Sensor.h"
#include <Adafruit_LTR390.h>  //library used for light sensor 
#include <Adafruit_ThinkInk.h>
#include <Adafruit_GFX.h>    
#include <Adafruit_EPD.h>
//wifi needs defined
//#include "secrets.h"

void setup() {
water_temperature_init();
ambient_init();
ph_init();
light_int();
LED_init();
display_init();
}

void loop() { 
//set text properties
    display.clearBuffer();
    display.setTextSize(1);
    Serial.println("System Values");    
//values as output by sensors
    water_temperature_check();
    ph_check();
    ambient_check();
    light_check();
    display.display();
    delay(2000);   
//check against the call ups of temp and ph to determine how to drive bi-color LED
    LED_interface();
}

void testdrawtext(char *text, uint16_t color) {
  display.setCursor(0, 0);
  display.setTextColor(color);
  display.setTextWrap(true);
  display.print(text);
}

void LED_interface(){
    //allow flow through common
    pinMode(LED_PIN_COMMON, OUTPUT);

    //statement for temperature to alert 
    if(AlarmTempPass = true){
        //if high alarms = led is red with pulses   
        Breath_LED_R();
        delay(500);
        }
    else{
        //if no high alarms = led is green
        Breath_LED_G();      
        }

    //statement for temperature to alert
    if(AlarmPhPass = true){
        //if high alarms = led is red with pulses   
        Breath_LED_R();
        delay(50);
        }
    else{
        //if no high alarms = led is green
        Breath_LED_G();      
        }

    if((AlarmPhPass = true) && (AlarmTempPass = true)){
        //if high alarms = led is red with pulses   
        Breath_LED_R();
        delay(1);
        }
    else{
        //if no high alarms = led is green
        Breath_LED_G();      
    }
}


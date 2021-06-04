//LIBRARIES
#include "ph.h"
#include "ambient.h"
#include "light.h"
#include "temperature.h"
//#include "LED.h"
//#include "eink.h"
#include <DHT.h>               // For DHT-22 Temperature and Humidity Sensor
#include <OneWire.h>           // For DS18B20 Temperature Sensor
#include <DallasTemperature.h> // For DS18B20 Temperature Sensor
#include <Adafruit_Sensor.h>
#include <Adafruit_LTR390.h>  //library used for light sensor 
//#include <Adafruit_ThinkInk.h>
//#include <Adafruit_GFX.h>    
//#include <Adafruit_EPD.h>
//#include <ArduinoJson.h>  
//#include <Fonts/FreeSans9pt7b.h> 
//wifi needs defined
//#include "secrets.h"

void setup() {
water_temperature_init();
ambient_init();
ph_init();
light_int();
//LED_init();
//display_init();
}

void loop() { 
    //display.clearBuffer();
//set text properties
    //display_stuff();
//values as output by sensors
    water_temperature_check();
    ph_check();
    ambient_check();
    light_check();
        //display.display();
//check against the call ups of temp and ph to determine how to drive bi-color LED
 //   LED_interface();

    delay(2000);   
}


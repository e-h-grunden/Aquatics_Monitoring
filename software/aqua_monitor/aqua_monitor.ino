//LIBRARIES
#include "ph.h"
#include "ambient.h"
#include "light.h"
#include "temperature.h"
#include "LED.h"
//#include "eink.h"
#include <DHT.h>               // For DHT-22 Temperature and Humidity Sensor
#include <OneWire.h>           // For DS18B20 Temperature Sensor
#include <DallasTemperature.h> // For DS18B20 Temperature Sensor
#include <Adafruit_Sensor.h>
#include <Adafruit_LTR390.h>  //library used for light sensor 
#include <Adafruit_ThinkInk.h>
#include <Adafruit_GFX.h>    
#include <Adafruit_EPD.h>
#include <ArduinoJson.h>  
#include <Fonts/FreeSans9pt7b.h> 
//wifi needs defined
//#include "secrets.h"

//eink display called out here
#define EPD_DC      14 // can be any pin, but required!    
#define EPD_CS      12 // can be any pin, but required!    
#define SRAM_CS     13  // can set to -1 to not use a pin (uses a lot of RAM!)  
#define EPD_RESET   15 // can set to -1 and share with microcontroller Reset!
#define EPD_BUSY    -1 // can set to -1 to not use a pin (will wait a fixed delay)
#define LEDPIN      16
#define LEDPINON    HIGH
#define LEDPINOFF   LOW 

#define COLOR1 EPD_BLACK
#define COLOR2 EPD_LIGHT
#define COLOR3 EPD_DARK

// 2.9" 4-level Grayscale (use mono) displays with 296x128 pixels and IL0373 chipset
ThinkInk_290_Grayscale4_T5 display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);

void setup() {
    
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LEDPINON);
    
    Serial.begin(115200);
    Serial.println("display initialized");
    display.clearBuffer();
    display.setTextWrap(false);
    water_temperature_init();
    ambient_init();
    ph_init();
    light_init();
    LED_init();
    //display_init();
}

void loop() { 
    display.begin(THINKINK_GRAYSCALE4);
    display.clearBuffer();
    display.setTextColor(EPD_BLACK);
    //display.setFont(THEfont);
    display.setTextSize(1);
    display.print("System Values");  
    display.display();
    delay(100);  
//set text properties
    //display_stuff();
//values as output by sensors
    water_temperature_check();
    ph_check();
    ambient_check();
    light_check();
//check against the call ups of temp and ph to determine how to drive bi-color LED
    LED_interface();
        
    display.display();
    delay(2000);   
}


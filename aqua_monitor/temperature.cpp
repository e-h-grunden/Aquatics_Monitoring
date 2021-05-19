
#include <Arduino.h>
#include "temperature.h"

//#define Pin Callout for Sensors
// Libraries for the DS18B20 Temperature Sensor - Adafruit Supplied
#include <OneWire.h>
#include <DallasTemperature.h>
// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);	
// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

void water_temperature_init() {
    Serial.begin(9600);
    sensors.begin();	// Start up the library
    //SETUP FOR GND AND PWR OF WATER TEMP PROBE    
    pinMode(ONE_WIRE_GND, OUTPUT);
    digitalWrite(ONE_WIRE_GND, LOW);
    pinMode(ONE_WIRE_PWR, OUTPUT);
    digitalWrite(ONE_WIRE_PWR, HIGH);
    sensors.setResolution(tempSensor, 12);
    sensors.setWaitForConversion(false);

}

void water_temperature_check() {
    // Send the command to get temperatures
    sensors.requestTemperatures(); 
    //print the temperature in Celsius
    Serial.print("Water Temperature: ");
    Serial.print(sensors.getTempCByIndex(0));
    Serial.print((char)176);//shows degrees character
    Serial.print("C");
}
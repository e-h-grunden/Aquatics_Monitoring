//help from
//https://lastminuteengineers.com/ds18b20-arduino-tutorial/
//https://github.com/adafruit/Sous_Viduino/blob/master/Sous_Viduino.ino

#include "Arduino.h"
#include "temperature.h"

// Libraries for the DS18B20 Temperature Sensor - Adafruit Supplied
#include <OneWire.h>
#include <DallasTemperature.h>
// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(WATER_TEMP_PIN);	
// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

void water_temperature_init() {
    Serial.begin(9600);
    sensors.begin();	// Start up the library
    sensors.setResolution(9);
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

//function to internally share temperature
void water_temp_pull() {
    sensors.requestTemperatures();
    sensors.getTempCByIndex(0);
}
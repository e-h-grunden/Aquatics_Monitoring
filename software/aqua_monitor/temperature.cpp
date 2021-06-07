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
// arrays to hold device addresses
DeviceAddress waterThermometer;

void water_temperature_init() {
    Serial.begin(9600);
    sensors.begin();	// Start up the library
    sensors.setResolution(9);
    // alarm when temp is higher than 30C
    sensors.setHighAlarmTemp(waterThermometer, 30);
    // alarm when temp is lower than 16C
    sensors.setLowAlarmTemp(waterThermometer, 16);
    //pinMode(TEMP_RELAY_PIN, OUTPUT);
}

void water_temperature_check() {
    // Send the command to get temperatures
    sensors.requestTemperatures(); 
    //print the temperature in Celsius
    Serial.print("Water Temperature: ");
    Serial.print(sensors.getTempCByIndex(0));
    Serial.print((char)176);//shows degrees character
    Serial.println("C");
}

//function to internally share temperature
float water_temp_pull() {
    sensors.requestTemperatures();
    sensors.getTempCByIndex(0);
}

bool check_temp_for_alarm() {
    sensors.requestTemperatures();
    float tempC = sensors.getTempC(waterThermometer);
    if (sensors.hasAlarm(waterThermometer))
    {
    Serial.print("TEMP ALARM: ");
    Serial.println(tempC);
    //digitalWrite(TEMP_RELAY_PIN, HIGH);
    return true;
    }
    else {
        return false;
    //digitalWrite(TEMP_RELAY_PIN, LOW);
    //AlarmTempPass = false;
    }
}

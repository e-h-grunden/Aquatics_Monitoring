
#include "Arduino.h"
//DFRobot's Gravity: Analog pH Sensor / Meter Kit V2, SKU:SEN0161-V2
//source + credit to @ https://github.com/DFRobot/DFRobot_PH
#include "DFRobot_PH.h"
#include "ph.h"
#include <EEPROM.h>
#include "temperature.h"

float voltage, phValue, temperature;
DFRobot_PH ph;

void ph_init() {
    Serial.begin(115200);  
    ph.begin();
}

void ph_check() {
    static unsigned long timepoint = millis();
    if(millis()-timepoint>1000U){                  //time interval: 1s
        temperature = readTemperature();         // read your temperature sensor to execute temperature compensation
        voltage = analogRead(PIN_PH)/1024.0*5000;  // read the voltage
        phValue = ph.readPH(voltage,temperature);  // convert voltage to pH with temperature compensation
        //Serial.print("temperature:");
        //Serial.print(temperature,1);
        Serial.print("pH:");
        Serial.println(phValue);
    }
    ph.calibration(voltage,temperature);           // calibration process by Serail CMD
}

float readTemperature() {
//add your code here to get the temperature from your temperature sensor
    water_temp_pull();
}

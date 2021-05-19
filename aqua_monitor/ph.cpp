
#include <Arduino.h>
//DFRobot's Gravity: Analog pH Sensor / Meter Kit V2, SKU:SEN0161-V2
//source + credit to @ https://github.com/DFRobot/DFRobot_PH
#include "DFRobot_PH.h"
#include <EEPROM.h>
#include "temperature.h"

void ph_init() {
    Serial2.begin(115200);  
    ph.begin();
}

void ph_check() {
    static unsigned long timepoint = millis();
    if(millis()-timepoint>1000U){                  //time interval: 1s
        timepoint = millis();
        phValue = ph.readPH(voltage,temperature);  // convert voltage to pH with temperature compensation
        Serial2.print("pH:");
        Serial2.println(phValue,2);
    }
    ph.calibration(voltage,temperature);           // calibration process by Serail CMD
}

float readTemperature() {
//add your code here to get the temperature from your temperature sensor
temperature = sensors.getTempCByIndex(0);
}
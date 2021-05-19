//LIBRARIES
#include "ph.h"
#include "ambient.h"
#include "LEDS.h"
#include "light.h"
#include "temperature.h"
#include <DHT.h>               // For DHT-22 Temperature and Humidity Sensor
#include <OneWire.h>           // For DS18B20 Temperature Sensor
#include <DallasTemperature.h> // For DS18B20 Temperature Sensor
#include "Adafruit_Sensor.h"
#include "DHT_U.h"             //library for unified version as needed

void setup() {
water_temperature_init();
ambient_init();
ph_init();
}

void loop() {
void water_temperature_check();
void ambient_check();
void ph_check();
}

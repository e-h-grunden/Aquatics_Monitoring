
#include "Arduino.h"
#include "ambient.h"
#include <DHT.h>             // For DHT-22 Temperature and Humidity Sensor
#include "Adafruit_Sensor.h"

DHT dht(DHTPIN, DHTTYPE);

void ambient_init() {
    Serial.begin(9600);
    Serial.println(F("DHT22 test"));
    dht.begin();
}

void ambient_check() {
    // Wait a few seconds between measurements.
    delay(2000);
    
    float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t)) {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }
    
    //Removed F from outputs
    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);

    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.println(F("°C "));
    Serial.print(F("Heat index: "));
    Serial.print(hic);
    Serial.println(F("°C "));
}


#include <Arduino.h>
#include <ambient.h>
#include <DHT.h>             // For DHT-22 Temperature and Humidity Sensor
#include <Adafruit_Sensor.h>

DHT dht(DHTPIN, DHTTYPE);

void ambient_init() {
    Serial3.begin(9600);
    Serial3.println(F("DHT22 test"));
    dht.begin();
}

void ambient_check() {
    // Wait a few seconds between measurements.
    delay(2000);
    
    float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t)) {
        Serial3.println(F("Failed to read from DHT sensor!"));
        return;
    }
    
    //Removed F from outputs
    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);

    Serial3.print(F("Humidity: "));
    Serial3.print(h);
    Serial3.print(F("%  Temperature: "));
    Serial3.print(t);
    Serial3.print(F("°C "));
    Serial3.print(F("Heat index: "));
    Serial3.print(hic);
    Serial3.print(F("°C "));
}
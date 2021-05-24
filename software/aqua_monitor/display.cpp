//thanks to:
//https://learn.adafruit.com/adafruit-2-13-eink-display-breakouts-and-featherwings/arduino-usage
//https://github.com/adafruit/Adafruit_EPD/blob/master/examples/ThinkInk_gray4/ThinkInk_gray4.ino
//https://github.com/adafruit/Adafruit_EPD/blob/master/examples/text_test/text_test.ino
//https://learn.adafruit.com/epaper-display-featherwing-quote-display

#include "Arduino.h"
#include "display.h"
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_EPD.h>
#include <Adafruit_ThinkInk.h>

void display_init() {
    Serial.begin(115200);
      while (!Serial) { delay(10); 
    Serial.println("display initialized");
    display.begin(THINKINK_GRAYSCALE4);
    display.setRotation(0);
}


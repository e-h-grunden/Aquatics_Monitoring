//thanks to:
//https://learn.adafruit.com/adafruit-2-13-eink-display-breakouts-and-featherwings/arduino-usage
//https://github.com/adafruit/Adafruit_EPD/blob/master/examples/ThinkInk_gray4/ThinkInk_gray4.ino
//https://github.com/adafruit/Adafruit_EPD/blob/master/examples/text_test/text_test.ino
//https://learn.adafruit.com/epaper-display-featherwing-quote-display

#include "Arduino.h"
#include "eink.h"
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_EPD.h>
#include <Adafruit_ThinkInk.h>
#include <ArduinoJson.h>   


// 2.9" Grayscale Featherwing or Breakout:
// 2.9" 4-level Grayscale (use mono) displays with 296x128 pixels and IL0373 chipset
ThinkInk_290_Grayscale4_T5 display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);

void display_init() {

  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LEDPINON);

  Serial.begin(115200);
  display.begin();
  Serial.println("ePaper display initialized");
  display.clearBuffer();
  display.setTextWrap(false);

}

void display_stuff(){
  display.begin(THINKINK_GRAYSCALE4);
  display.clearBuffer();
  display.setTextColor(EPD_BLACK);
//display.setFont(THEfont);
  display.setTextSize(1);
  display.print("System Values");  
  display.display();
  delay(100);  
}


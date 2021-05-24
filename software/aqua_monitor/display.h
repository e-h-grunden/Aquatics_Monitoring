#ifndef __DISPLAY_H
#define __DISPLAY_H

//pin to wifi feather
#define EPD_DC 14 // can be any pin, but required!    
#define EPD_CS 12 // can be any pin, but required!    
#define SRAM_CS 13  // can set to -1 to not use a pin (uses a lot of RAM!)  
#define EPD_RESET 15 // can set to -1 and share with microcontroller Reset!
#define EPD_BUSY -1 // can set to -1 to not use a pin (will wait a fixed delay)

#define COLOR1 EPD_BLACK
#define COLOR2 EPD_LIGHT
#define COLOR3 EPD_DARK

// 2.9" Grayscale Featherwing or Breakout:
// 2.9" 4-level Grayscale (use mono) displays with 296x128 pixels and IL0373 chipset
ThinkInk_290_Grayscale4_T5 display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);

void display_init();

#endif //__DISPLAY_H
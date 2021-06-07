#ifndef __EINK_H
#define __EINK_H

//pin to wifi feather
#define EPD_DC      14 // can be any pin, but required!    
#define EPD_CS      12 // can be any pin, but required!    
#define SRAM_CS     13  // can set to -1 to not use a pin (uses a lot of RAM!)  
#define EPD_RESET   15 // can set to -1 and share with microcontroller Reset!
#define EPD_BUSY    -1 // can set to -1 to not use a pin (will wait a fixed delay)
#define LEDPIN      16
#define LEDPINON    HIGH
#define LEDPINOFF   LOW 


#define COLOR1 EPD_BLACK
#define COLOR2 EPD_LIGHT
#define COLOR3 EPD_DARK

//const GFXfont *THEfont = &FreeSans9pt7b;
//const GFXfont *smallfont = NULL;

void display_init();
void display_stuff();

#endif //__EINK_H
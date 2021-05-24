#ifndef __LED_H
#define __LED_H

#define LED_PIN_R 11  //red - use datalogger to have pwm
#define LED_PIN_G 10  //green - use datalogger to have pwm
#define LED_PIN_COMMON 0 //common declared (this is also the ground pin) this is also the RX pin on data logger feather

const int nColors = 2; //bi color led clarification
const int red = 0; //color position in array
const int green = 1; //color position in array

const int colorPin[nColors] = {LED_PIN_R, LED_PIN_G}; //color array

void LED_init();
void colorON();
void Breath_LED_R();
void Breath_LED_G();
//void LED_interface();

#endif //__LED_H
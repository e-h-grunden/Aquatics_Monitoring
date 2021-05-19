#ifndef __TEMPERATURE_H
#define __TEMPERATURE_H

//water TEMP
#define WATER_TEMP_PIN 2

void water_temperature_init();
void water_temperature_check();
void water_temp_pull();
#endif //__TEMPERATURE_H
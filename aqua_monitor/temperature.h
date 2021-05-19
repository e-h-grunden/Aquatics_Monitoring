#ifndef __TEMPERATURE_H
#define __TEMPERATURE_H

//water TEMP
#define ONE_WIRE_BUS 
#define ONE_WIRE_PWR
#define ONE_WIRE_GND 

void water_temperature_init();
void water_temperature_check();

#endif //__TEMPERATURE_H
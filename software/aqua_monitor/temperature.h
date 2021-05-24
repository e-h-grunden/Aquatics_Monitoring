#ifndef __TEMPERATURE_H
#define __TEMPERATURE_H

//water TEMP
#define WATER_TEMP_PIN 5 //use the data logger pinout

bool AlarmTempPass;

void water_temperature_init();
void water_temperature_check();
float water_temp_pull();
bool check_temp_for_alarm();
void LED_interface();
#endif //__TEMPERATURE_H
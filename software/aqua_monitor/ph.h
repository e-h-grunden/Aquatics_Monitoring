#ifndef __PH_H
#define __PH_H

#define PIN_PH A1 //ph probe is an analog value

bool AlarmPhPass = false;

void ph_init();
void ph_check();
float readTemperature();
void check_ph_for_alarm();
#endif 
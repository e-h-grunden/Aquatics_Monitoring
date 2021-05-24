#ifndef __PH_H
#define __PH_H

#define PIN_PH A1 //ph probe is an analog value

bool AlarmPhPass;

void ph_init();
void ph_check();
float readTemperature();
bool check_ph_for_alarm();
#endif 
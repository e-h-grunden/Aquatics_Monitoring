#ifndef __PH_H
#define __PH_H



#define PIN_PH A1 //ph probe is an analog value
float voltage, phValue, temperature = 25;
DFRobot_PH ph;

void ph_init();
void ph_check();

#endif 
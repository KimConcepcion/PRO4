
#ifndef MOISTSENSOR_H_
#define MOISTSENSOR_H_

//	Path for ADC channel:
#define MOIST_PATH "/sys/bus/iio/devices/iio:device0/in_voltage6_raw"	//	path to read ADC value from channel 6

//	Prototypes:
int readMoist();

#endif

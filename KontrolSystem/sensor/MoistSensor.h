
#ifndef MOISTSENSOR_H_
#define MOISTSENSOR_H_

//	Path for ADC channel:
#define MOIST_1 "/sys/bus/iio/devices/iio:device0/in_voltage0_raw"	//	path to read ADC value from channel 6
#define MOIST_2 "/sys/bus/iio/devices/iio:device0/in_voltage2_raw"

//	Prototypes:
double readMoist_1();
double readMoist_2();

#endif

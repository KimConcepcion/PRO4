
#ifndef LDR_H_
#define LDR_H_

//	Path for ADC channel:
#define LDR_PATH "/sys/bus/iio/devices/iio:device0/in_voltage2_raw"	//	path to read ADC value from channel 2

//	Prototypes:
double readLight();

#endif

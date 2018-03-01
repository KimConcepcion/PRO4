
#ifndef LM35DZ_H_
#define LM35DZ_H_

//	Path for ADC channel:
#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage0_raw"	//	path to read ADC value from channel 0

//	Prototypes:
double readTemp();

#endif

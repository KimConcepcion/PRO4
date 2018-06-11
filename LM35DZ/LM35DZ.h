
#ifndef LM35DZ_H_
#define LM35DZ_H_

//	Path for ADC channel:
#define TEMP_1 "/sys/bus/iio/devices/iio:device0/in_voltage1_raw"	//	path to read ADC value from channel 0
#define TEMP_2 "/sys/bus/iio/devices/iio:device0/in_voltage3_raw"

//	Prototypes:
double readTemp_1();
double readTemp_2();

#endif

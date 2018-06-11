
#ifndef LDR_H_
#define LDR_H_

//	Path for ADC channel:
#define LDR_1 "/sys/class/gpio/gpio115/value"	//	path to read ADC value from channel 2
#define LDR_2 "/sys/class/gpio/gpio117/value"

//	Prototypes:
int readLight_1();
int readLight_2();

#endif


#include "LM35DZ.h"

#include <fstream>

using namespace std;

double readTemp_1()
{
	double adc_val = 0;
	double temp = 0;
	double temp_cal = 0;

	fstream tempFile (TEMP_1, fstream::in);
	tempFile >> adc_val;
	tempFile.close();

	//	Calibrate sensorvalue:
	temp = adc_val*1.8/4095;
	temp_cal = (temp*100);

	return temp_cal;
}

double readTemp_2()
{
	double adc_val = 0;
	double temp = 0;
	double temp_cal = 0;

	fstream tempFile (TEMP_2, fstream::in);
	tempFile >> adc_val;
	tempFile.close();

	//	Calibrate sensorvalue:
	temp = adc_val*1.8/4095;
	temp_cal = (temp*100);
	temp_cal = temp_cal-(temp_cal-readTemp_1());

	return temp_cal;
}

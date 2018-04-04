
#include "LM35DZ.h"
#include <fstream>

using namespace std;

double readTemp()
{
	double adc_val = 0;
	double temp = 0;
	double temp_cal = 0;

	fstream tempFile (ADC_PATH, fstream::in);
	tempFile >> adc_val;
	tempFile.close();

	//	Calibrate sensorvalue:
	temp = adc_val*1.8/4095;
	temp_cal = (temp*100);

	return temp_cal;
}

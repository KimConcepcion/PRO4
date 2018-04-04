
#include "LDR.h"
#include <iostream>
#include <fstream>

using namespace std;

double readLight()
{
	double adc_val = 0;
	double light = 0;

	//	Input from file:
	fstream LDRFile (LDR_PATH, fstream::in);
	LDRFile >> adc_val;
	LDRFile.close();

	//	Calibrate values:
	light = adc_val*1.8/4095;

	return light;
}

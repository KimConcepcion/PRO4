
#include <iostream>
#include <fstream>
#include "LDR.h"

using namespace std;

int readLight_1()
{
	double gpio_val = 0;

	//	Input from file:
	fstream LDRFile (LDR_1, fstream::in);
	LDRFile >> gpio_val;
	LDRFile.close();

	return gpio_val;
}

int readLight_2()
{
	double gpio_val = 0;

	//	Input from file:
	fstream LDRFile (LDR_2, fstream::in);
	LDRFile >> gpio_val;
	LDRFile.close();

	return gpio_val;
}

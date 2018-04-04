
#include "MoistSensor.h"

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

double readMoist()
{
	double number = 0;

   fstream MoistFILE (MOIST_PATH, fstream::in);
   MoistFILE >> number;
   MoistFILE.close();

   //	Calibrate sensorvalue:
   number = number*1.8/4095;

   return number;
}

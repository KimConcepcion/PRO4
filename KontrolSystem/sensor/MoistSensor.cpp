
#include "../sensor/MoistSensor.h"

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

double readMoist_1()
{
	double number = 0;

   fstream MoistFILE (MOIST_1, fstream::in);
   MoistFILE >> number;
   MoistFILE.close();

   //	Calibrate sensorvalue:
   number = number*1.8/4095;

   return number;
}

double readMoist_2()
{
	double number = 0;

   fstream MoistFILE (MOIST_2, fstream::in);
   MoistFILE >> number;
   MoistFILE.close();

   //	Calibrate sensorvalue:
   number = number*1.8/4095;

   return number;
}

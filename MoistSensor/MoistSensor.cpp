
#include "MoistSensor.h"

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

int readMoist()
{
	int number = 0;

   fstream MoistFILE (MOIST_PATH, fstream::in);
   MoistFILE >> number;
   MoistFILE.close();

   return number;
}

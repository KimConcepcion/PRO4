
#include <iostream>
#include <csignal>
#include <sys/time.h>
#include <unistd.h>
#include "MoistSensor.h"

using namespace std;

int main(int argC, char **argV)
{
	double moist_1 = readMoist_1();
	double moist_2 = readMoist_2();

	cout << "Running the Moist sensor test" << endl;
	cout << "1. MoistSensor path on Beaglebone: " << MOIST_1 << endl;
	cout << "2. MoistSensor path on Beaglebone: " << MOIST_2 << endl;

	if (moist_1 < 3000) {
	   cout << "1. moistsensor: Well done! Your plants are happy!" << endl;
	}
	else {
	   cout << "1. moistsensor: It's time to water your plants!" << endl;
	   return -1;
	}

	if (moist_2 < 3000) {
	   cout << "2. moistsensor: Well done! Your plants are happy!" << endl;
	}
	else {
	   cout << "2. moistsensor: It's time to water your plants!" << endl;
	   return -2;
	}

	return 0;
}

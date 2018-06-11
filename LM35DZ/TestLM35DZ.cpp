#include <iostream>
#include "LM35DZ.h"

using namespace std;

int main(int argC, char **argV) {

	double temperature_1 = readTemp_1();
	double temperature_2 = readTemp_2();

	cout << "Running the LM35DZ sensor test" << endl;
	cout << "1. LM35DZ path on Beaglebone: " << TEMP_1 << endl;
	cout << "2. LM35DZ path on Beaglebone: " << TEMP_2 << endl;

	if (temperature_1 > 18 && temperature_1 < 27) {
		cout << "1. Temperature is OK, tempValue: " << temperature_1 << endl;
	}

	else {
		cerr << "1. temperature is NOT OK, tempValue " << temperature_1 << endl;
		return -1;
	}

	if (temperature_2 > 18 && temperature_2 < 27) {
		cout << "2. Temperature is OK, tempValue: " << temperature_2 << endl;
	}

	else {
		cerr << "2. temperature is NOT OK, tempValue: " << temperature_2 << endl;
		return -2;
	}
	return 0;
}

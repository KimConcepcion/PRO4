
#include <iostream>
#include <stdio.h>
#include "LDR.h"

using namespace std;

int main(void) {
	cout << "Running the LDR sensor test" << endl;
	cout << "1. LDR path on Beaglebone: " << LDR_1 << endl;
	cout << "2. LDR path on Beaglebone: " << LDR_2 << endl;

	if (readLight_1() == 1) {
		cout << "Returnvalue from 1. LDR-routine: [HIGH]" << endl;
	}

	else if (readLight_1() == 0) {
		cout << "Returnvalue from 1. LDR-routine: [LOW]" << endl;
	}

	else {
		cerr << "1. LDR Something wrong occured!" << endl;
		return -1;
	}

	if (readLight_2() == 1) {
		cout << "Returnvalue from 2. LDR-routine: [HIGH]" << endl;
	}

	else if (readLight_2() == 0) {
		cout << "Returnvalue from 2. LDR-routine: [LOW]" << endl;
	}

	else {
		cerr << "2. LDR: Something wrong occured!" << endl;
		return -2;
	}
	return 0;
}

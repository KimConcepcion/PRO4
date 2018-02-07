#include <iostream>
#include <stdlib.h>
#include "Sensor.h"
#include "Kontrolsystem.h"
#include "Values.h"
#include "collection.h"

using namespace std;

int main(void)
{
	Kontrolsystem unit;
	double userTemp, userLight, userFert, userHum;
	int uInput;

	cout << "----------TESTBENCH----------" << endl;
	cout << "Enter temperature value" << endl;
	cout << "Input: ";
	cin >> userTemp;

	cout << "Enter Light value" << endl;
	cout << "Input: ";
	cin >> userLight;

	cout << "Enter fertilize value:" << endl;
	cout << "Input: ";
	cin >> userFert;

	cout << "Enter humidity value:" << endl;
	cout << "Input: ";
	cin >> userHum;

	unit.getTemperature(0,0, userTemp);
	unit.getLight(0, 0, userLight);
	unit.getFertilizer(0, 0, userFert);
	unit.getHumidity(0, 0, userHum);
	unit.getInput(userTemp, userLight, userFert, userHum);

	printMenu();
	cin >> uInput;

	while(uInput != -1)
	{
		if(uInput == 5)
		{
			cout << "----------TESTBENCH----------" << endl;
			cout << "Enter temperature value" << endl;
			cout << "Input: ";
			cin >> userTemp;

			cout << "Enter Light value" << endl;
			cout << "Input: ";
			cin >> userLight;

			cout << "Enter fertilize value:" << endl;
			cout << "Input: ";
			cin >> userFert;

			cout << "Enter humidity value:" << endl;
			cout << "Input: ";
			cin >> userHum;

			unit.getTemperature(0,0, userTemp);
			unit.getLight(0, 0, userLight);
			unit.getFertilizer(0, 0, userFert);
			unit.getHumidity(0, 0, userHum);
			unit.getInput(userTemp, userLight, userFert, userHum);
		}

		else
		{
			userMenu(uInput, unit);
		}
		printMenu();
		cin >> uInput;
	}

	return 0;
}
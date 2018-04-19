#include <iostream>
#include <stdlib.h>
#include "user.h"

void printMenu()
{
	cout << "[SYSTEMMENU]" << endl;
	cout << "Select an option:" << endl;
	cout << "(1) Plant-menu" << endl;
	cout << "(2) Sensor-status" << endl;
	cout << "(3) Quit"  << endl;
	cout << "----------------------------------" << endl;
	cout << ">>";
}

void userMenu(int userInput, Kontrolsystem obj)
{
		int u_input = 0;
		switch(userInput)
		{
		case 1:
			cout << "[PLANT-MENU]" << endl;
			cout << "(1) Show plant specifications" << endl;
			cout << "(2) Add/remove/customize plants" << endl;
			cout << "(3) Show plant status" << endl;
			cout << "(4) Quit" << endl;
			cout << "----------------------------------" << endl;
			cout << ">>";
			cin >> u_input;

			if(u_input == 1){
				obj.namePlant();
			}
				//obj.namePlant();

			else if(u_input == 2){
				obj.plantOrganizer();
			}

			else if(u_input == 3){
				obj.intervalsMoist();
				//obj.intervalsHumidity();
				obj.intervalsLight();
				obj.intervalsTemperature();
				u_input = 1;
			}
			break;

		case 2:
			obj.sensorStatus();
			break;

		case 3:
			cout << "The system terminates..." << endl;
			exit(0);
			break;

		default:
			cout << "Invalid input!" << endl;
			printMenu();
			cin >> userInput;
			break;
		}
}

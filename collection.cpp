#include "collection.h"
#include <iostream>
#include <stdlib.h>

void printMenu()
{
	cout << "---SYSTEMMENU--- (2 & 3 under development...)" << endl;
	cout << "Select an option:" << endl;
	cout << "(1) Plant-menu" << endl;
	cout << "(2) Vacation mode" << endl;
	cout << "(3) Upload image" << endl;
	cout << "(4) Quit"  << endl;
	cout << "(5) Test interface" << endl;
	cout << "----------------------------------" << endl;
	cout << "Input: ";
}

void userMenu(int userInput, Kontrolsystem obj)
{
		switch(userInput)
		{
		case 1:
			cout << "---PLANT-MENU---" << endl;
			cout << "(1) Show plant specifications" << endl;
			cout << "(2) Add/remove/customize plants" << endl;
			cout << "(3) Show plant status" << endl;
			cout << "(4) Quit" << endl;
			cout << "----------------------------------" << endl;
			cout << "Input: ";
			cin >> userInput;

			if(userInput == 1)
			{
				obj.namePlant();
				//sts.namePlant();
			}
				//obj.namePlant();
			else if(userInput == 2)
			{
				obj.plantOrganizer();
				//obj.notifyCustomer(2);	// Test timer
			}
			else if(userInput == 3){
				obj.intervalsFertilizer();
				obj.intervalsHumidity();
				obj.intervalsLight();
				obj.intervalsTemperature();
				userInput = 1;
			}
			else
			{
				cout << "Bye!" << endl;
				exit(0);
			}

			break;

		case 2:
			cout << "---VACATION_MODE---" << endl;
			//obj.test();
			break;

		case 3:
			cout << "---UPLOAD_IMAGE---" << endl;
			break;

		case 4:
			cout << "Bye!" << endl;
			exit(0);
			break;

		default:
			cout << "Invalid input, program terminating..." << endl;
			exit(0);
			break;
		}
}
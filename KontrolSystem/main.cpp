
#include <iostream>
#include <stdlib.h>
#include "Sensor.h"
#include "Kontrolsystem.h"
#include "user.h"

using namespace std;

int main(void)
{
	int uInput = 0;
	Kontrolsystem unit;

	printMenu();	//	Print welcome menu
	cin >> uInput;	//	Enter input

	while(1)
	{
		if(uInput == -1)
			return -1;

		userMenu(uInput, unit);	//	React on input
		printMenu();
		cin >> uInput;
	}

	return 0;
}

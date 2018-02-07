/*
 * Kontrolsystem.cpp
 *
 *  Created on: 7 Nov 2017
 *      Author: Riemann
 */

#include "Kontrolsystem.h"
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

////////////KONTROLSYSTEM CONSTRUCTOR//////////
Kontrolsystem::Kontrolsystem()
{
	p1.name = "Basilikum";
	p1.temp_val = 0;
	p1.light_val = 0;
	p1.fert_val = 0;
	p1.hum_val = 0;
	p1.water_val = 0;

	p2.name = "Krus Persille";
	p2.temp_val = 0;
	p2.light_val = 0;
	p2.fert_val = 0;
	p2.hum_val = 0;
	p2.water_val = 0;

	p3.name = "Purløg";
	p3.temp_val = 0;
	p3.light_val = 0;
	p3.fert_val = 0;
	p3.hum_val = 0;
	p3.water_val = 0;

	p4.name = "Mynte";
	p4.temp_val = 0;
	p4.light_val = 0;
	p4.fert_val = 0;
	p4.hum_val = 0;
	p4.water_val = 0;

	p5.name = "Timian";
	p5.temp_val = 0;
	p5.light_val = 0;
	p5.fert_val = 0;
	p5.hum_val = 0;
	p5.water_val = 0;

	p6.name = "Rosmarin";
	p6.temp_val = 0;
	p6.light_val = 0;
	p6.fert_val = 0;
	p6.hum_val = 0;
	p6.water_val = 0;

	p7.name = "Citronmelisse";
	p7.temp_val = 0;
	p7.light_val = 0;
	p7.fert_val = 0;
	p7.hum_val = 0;
	p7.water_val = 0;

	p8.name = "Oregano(Merian)";
	p8.temp_val = 0;
	p8.light_val = 0;
	p8.fert_val = 0;
	p8.hum_val = 0;
	p8.water_val = 0;

	p9.name = "Salvie";
	p9.temp_val = 0;
	p9.light_val = 0;
	p9.fert_val = 0;
	p9.hum_val = 0;
	p9.water_val = 0;

	p10.name = "Test_plante";
	p10.temp_val = 0;
	p10.light_val = 0;
	p10.fert_val = 0;
	p10.hum_val = 0;
	p10.water_val = 0;

	//	Prædefinerede planter:
	plantID.push_back(p1);
	plantID.push_back(p2);
	plantID.push_back(p3);
	plantID.push_back(p4);
	plantID.push_back(p5);
	plantID.push_back(p6);
	plantID.push_back(p7);
	plantID.push_back(p8);
	plantID.push_back(p9);
	plantID.push_back(p10);

	//plant_status.name = ".";	//	Irrelevant?
	//////////SENSOR VALUES//////////
	plant_status.temp_val = tempSensor;
	plant_status.light_val = lightSensor;
	plant_status.fert_val = fertSensor;
	plant_status.hum_val = humSensor;


}

static void removePlant(vector<plant>& plantList)
{
	int index;
	char ans;
	cout << "Enter the belonging index-number of the plant you wish to remove" << endl;
	cout << "The plants currently stored are the following:" << endl;

	for(uint i = 0; i < plantList.size(); i++)
	{
		cout << "--------------PAGE[" << i+1 << "]-------------" << endl;
		cout << "|[Index number]: " << i+1 << endl << "|[plant]:" << plantList[i].name << endl;
		cout << "--------------PAGE[" << i+1 << "]-------------" << endl << endl;
	}

	cout << "----------------------------------" << endl;
	cout << "Input: ";
	cin >> index;

	index = index-1;
	if(index < 0)
		index = 0;

	cout << "Are you sure you wish to remove this plant (y/n)?" << endl;
	cin >> ans;
	if(tolower(ans) == 'y')
		plantList.erase(plantList.begin() + index);
	else
		cout << "The plant has not been removed!" << endl;
}

static inline void emptyPlant(vector<plant>& plantList)
{
	plantList.clear();
}

static void addPlant(vector<plant>& plantList)
{
	string nameInput;
	double tempInput;
	double lightInput;
	//double fertInput;
	//double humInput;
	double waterInput;
	int element;
	plant result;

	cout << "Enter the name of the plant:" << endl;
	cin >> nameInput;
	cout << "Enter the temperature tolerance:" << endl;
	cin >> tempInput;
	cout << "Enter the light tolerance:" << endl;
	cin >> lightInput;
		//cout << "Enter the fertilizer tolerance:" << endl;
		//cin >> fertInput;
		//cout << "Enter the humidity tolerance:" << endl;
		//cin >> humInput;
	cout << "Enter the water tolerance:" << endl;
	cin >> waterInput;
	cout << "Enter where to store it in the plant-directory (1-10):" << endl;
	cin >> element;

	element = element-1;
	if(element < 0)
		element = 0;

	result.name = nameInput;
	result.temp_val = tempInput;
	result.light_val = lightInput;
	//result.fert_val = fertInput;
	//result.hum_val = humInput;
	result.water_val = waterInput;

	plantList.insert(plantList.begin() + element, result);
}

static void printPlants(vector<plant>& plantList)
{
	if(plantList.empty()== true)
	{
		cout << "----------------------------------" << endl;
		cout << "[The directory is empty!]" << endl;
		cout << "----------------------------------" << endl;
	}

	else
	{
		cout << "Plants:" << endl;
		for(uint i = 0; i < plantList.size(); i++)
		{
			cout << "--------------PAGE[" << i+1 << "]-------------" << endl;
			cout << "|	Name:" << plantList[i].name <<endl;
			cout << "|	Temperature:" << plantList[i].temp_val << endl;
			cout << "|	Light:" << plantList[i].light_val << endl;
			//cout << "|	Fertilizer:" << plantList[i].fert_val << endl;
			//cout << "|	Humidity:" << plantList[i].hum_val << endl;
			cout << "|	Water:" << plantList[i].water_val << endl;
			cout << "--------------PAGE[" << i+1 << "]-------------" << endl << endl;
		}
	}
}

void Kontrolsystem::facSettings(void)
{
	p1.name = "Basilikum";
	p1.temp_val = 0;
	p1.light_val = 0;
	p1.fert_val = 0;
	p1.hum_val = 0;
	p1.water_val = 0;

	p2.name = "Krus Persille";
	p2.temp_val = 0;
	p2.light_val = 0;
	p2.fert_val = 0;
	p2.hum_val = 0;
	p2.water_val = 0;

	p3.name = "Purløg";
	p3.temp_val = 0;
	p3.light_val = 0;
	p3.fert_val = 0;
	p3.hum_val = 0;
	p3.water_val = 0;

	p4.name = "Mynte";
	p4.temp_val = 0;
	p4.light_val = 0;
	p4.fert_val = 0;
	p4.hum_val = 0;
	p4.water_val = 0;

	p5.name = "Timian";
	p5.temp_val = 0;
	p5.light_val = 0;
	p5.fert_val = 0;
	p5.hum_val = 0;
	p5.water_val = 0;

	p6.name = "Rosmarin";
	p6.temp_val = 0;
	p6.light_val = 0;
	p6.fert_val = 0;
	p6.hum_val = 0;
	p6.water_val = 0;

	p7.name = "Citronmelisse";
	p7.temp_val = 0;
	p7.light_val = 0;
	p7.fert_val = 0;
	p7.hum_val = 0;
	p7.water_val = 0;

	p8.name = "Oregano(Merian)";
	p8.temp_val = 0;
	p8.light_val = 0;
	p8.fert_val = 0;
	p8.hum_val = 0;
	p8.water_val = 0;

	p9.name = "Salvie";
	p9.temp_val = 0;
	p9.light_val = 0;
	p9.fert_val = 0;
	p9.hum_val = 0;
	p9.water_val = 0;

	p10.name = "Test_plante";
	p10.temp_val = 0;
	p10.light_val = 0;
	p10.fert_val = 0;
	p10.hum_val = 0;
	p10.water_val = 0;

	//	Prædefinerede planter:
	plantID.push_back(p1);
	plantID.push_back(p2);
	plantID.push_back(p3);
	plantID.push_back(p4);
	plantID.push_back(p5);
	plantID.push_back(p6);
	plantID.push_back(p7);
	plantID.push_back(p8);
	plantID.push_back(p9);
	plantID.push_back(p10);
}

void Kontrolsystem::plantOrganizer()
{
	char ver;
	int uInput;
	cout << "---Add/remove/customize plants menu---" << endl;
	cout << "(1) Remove a plant from directory" << endl;
	cout << "(2) Empty directory" << endl;
	cout << "(3) Add a plant to directory" << endl;
	cout << "(4) Print plants" << endl;
	cout << "(5) Restore to factory settings" << endl;
	cout << "(6) Quit" << endl;
	cout << "----------------------------------" << endl;
	cout << "Input: ";

	cin >> uInput;

	while(uInput != -1)
	{

		if(uInput == 1)
			removePlant(plantID);

		else if(uInput == 2)
			emptyPlant(plantID);

		else if(uInput == 3)
		{
			if(plantID.size() < 0)
				cerr << "Plant directory empty..." << endl;
			else
				addPlant(plantID);
		}

		else if(uInput == 4)
		{
				printPlants(plantID);
		}

		else if(uInput == 5)
		{
			cout << "Are you sure you wish to remove this plant (y/n)?" << endl;
			cin >> ver;
			ver = tolower(ver);
			if(ver == 'y')
			{
				facSettings();
			}
			else
			{
				cout << "Enter new input:" << endl;
				cout << "(1) Remove a plant from directory" << endl;
				cout << "(2) Empty directory" << endl;
				cout << "(3) Add a plant to directory" << endl;
				cout << "(4) Print plants" << endl;
				cout << "(5) Restore to factory settings" << endl;
				cout << "(6) Quit" << endl;
				cout << "----------------------------------" << endl;
				cout << "Input: ";
				cin >> uInput;
			}
		}

		else
		{
			cout << "Bye!..." << endl;
			exit(0);
		}

		cout << "Enter new input:" << endl;
		cout << "(1) Remove a plant from directory" << endl;
		cout << "(2) Empty directory" << endl;
		cout << "(3) Add a plant to directory" << endl;
		cout << "(4) Print plants" << endl;
		cout << "(5) Restore to factory settings" << endl;
		cout << "(6) Quit" << endl;
		cout << "----------------------------------" << endl;
		cout << "Input: ";
		cin >> uInput;
	}
}

uint Kontrolsystem::timer(uint t_in)
{
	uint time_v = 0;
	uint i = 0;

	while(i < t_in*60)
	{
		if(time_v == 60)
		{
			cout << "-----1 minutes passed-----" << endl;
		}

		if(time_v == 3600)
		{
			cout << "-----1 hour passed-----" << endl;
		}

		cout << "|[s]: " << time_v << "        |[min]: " << time_v/60 << "        |[hr]: " << time_v/3600 << endl;
		usleep(1000000);	// seconds
		time_v++;
		i++;
	}

	return time_v;	//	husk at det er sekunder den returnerer!
}

void Kontrolsystem::namePlant()
{
	int uInput;
	cout << "---PLANT_SPECIFICATIONS---" << endl;
	cout << "Choose a plant between <1-10> (11 to quit)" << endl;
	cout << "----------------------------------" << endl;
	cout << "Input: ";
	cin >> uInput;

	if(uInput > 11 || uInput < 1)
	{
		cout << "Invalid input, program terminating..." << endl;
		exit(0);
	}

	uInput = uInput-1;
	if(uInput < 0)
		uInput = 0;

	while(uInput != 11)
	{
		cout << "--------------PLANT[" << uInput << "]------------" << endl;
		cout << "Name: " << plantID[uInput].name << endl;
		cout << "Temperature: " << plantID[uInput].temp_val << endl;
		cout << "Light: " << plantID[uInput].light_val << endl;
		cout << "Fertilize: " << plantID[uInput].fert_val << endl;
		cout << "Humidity: " << plantID[uInput].hum_val << endl;
		cout << "----------------------------------" << endl;

		cout << "---PLANT_SPECIFICATIONS---" << endl;
		cout << "Choose another plant between <1-10> (11 to quit)" << endl;
		cin >> uInput;
	}
	cout << "Bye!..." << endl;
	exit(0);
}

void Kontrolsystem::notifyCustomer(uint time)
{
	//	Efter nedtælling bliver brugeren informeret om at det er tid til at give planten vand.
	//	Nedtællingen vises løbende,ligesom beskrevet i rapporten:
	timer(time);
	usleep(2*1000000);	// wait 2 seconds before you clear the screen:
	system("clear");
	cout << "\nTime to give your plant some water!" << endl;
}

void Kontrolsystem::sleep(uint time)
{
	usleep(time*1000);	// ms delay (lidt mere præcist? Ellers bare gange 10⁶ for sec delay...)
}

void Kontrolsystem::criticalPlant(plant p_status)
{
	p_status = plant_status;	//	Adgang til sensor værdier til den bestemte plante igennem struct
}

plant Kontrolsystem::getInput(double userTemp, double userLight, double userFert, double userHum)
{
	tempSensor = userTemp;
	lightSensor = userLight;
	fertSensor = userFert;
	humSensor = userHum;

	plant_status.temp_val = userTemp;
	plant_status.light_val = userLight;
	plant_status.fert_val = userFert;
	plant_status.hum_val = userHum;

	return plant_status;
}

void Kontrolsystem::test(void)
{
	cout << "-----Test sensor inputs:-----" << endl;
	cout << "Temperature input:" << plant_status.temp_val << endl;
	cout << "Light input:" << plant_status.light_val << endl;
	cout << "Fertilize input:" << plant_status.fert_val << endl;
	cout << "Humidity input:" << plant_status.hum_val << endl;
}

void Kontrolsystem::imageUpload()
{
	// Nope...
}

void Kontrolsystem::vacationMode()
{
	//	Nope...
}

int Kontrolsystem::intervalsHumidity()
{

	int avg;
	int avgmin;
	int avgmax;
	int max;
	int min;

	avg = plantID[0].hum_val;
	avgmin = avg - 5;
	avgmax = avg + 5;
	max = avg + 15;
	min = avg - 15;

	if (plant_status.hum_val < min)
	{
		cout << "Vand mangler - humidity: "<< plant_status.hum_val << endl;
	}
	else if (plant_status.hum_val > max)
	{
		cout << "For meget vand - humidity: " << plant_status.hum_val << endl;
	}

	else if((plant_status.hum_val > min) && plant_status.hum_val < max)
	{
		if((plant_status.hum_val < avgmax) &&  (plant_status.hum_val > avgmin))
			cout << "Vand ok - humidity: " << plant_status.hum_val << endl;

		else
			cout << "Reached Hysteresis in humidity - humidity: " << plant_status.hum_val << endl;
	}

/*	else if ((plant_status.hum_val < avgmax) &&  (plant_status.hum_val > avgmin))
	{
		cout << "Vand ok" << endl;
	} */

	else
	{
		return 0;
	}
	return 0;
}
int Kontrolsystem::intervalsFertilizer()
{
	int avg = plantID[0].fert_val;
	int avgmin = avg - 5;
	int avgmax = avg + 5;
	int max = avg + 15;
	int min = avg - 15;


	if (plant_status.fert_val < min)
	{
		cout << "Gødning mangler - gødning: " << plant_status.fert_val << endl;
	}
	else if (plant_status.fert_val > max)
	{
		cout << "For meget Gødning - gødning: " << plant_status.fert_val << endl;
	}

	else if((plant_status.fert_val > min) && plant_status.fert_val < max)
	{
		if((plant_status.fert_val < avgmax) &&  (plant_status.fert_val > avgmin))
			cout << "Gødning ok - gødning: " << plant_status.fert_val << endl;

		else
			cout << "Reached Hysteresis in fertilize - gødning: " << plant_status.fert_val << endl;
	}

/*	else if ((plant_status.fert_val < avgmax) &&  (plant_status.fert_val > avgmin))
	{
		cout << "Gødning ok" << endl;
	}*/

	else
	{
		return 0;
	}
	return 0;
}
int Kontrolsystem::intervalsLight()
{
	int avg = plantID[0].light_val;
	int avgmin = avg - 5;
	int avgmax = avg + 5;
	int max = avg + 15;
	int min = avg - 15;

	if (plant_status.light_val < min)
	{
		cout << "Lys mangler - lys: " << plant_status.light_val << endl;
	}
	else if (plant_status.light_val > max)
	{
		cout << "For meget lys - lys: " << plant_status.light_val << endl;
	}

	else if((plant_status.light_val > min) && plant_status.light_val < max)
	{
		if((plant_status.light_val < avgmax) &&  (plant_status.light_val > avgmin))
			cout << "Lyset ok - lys: " << plant_status.light_val << endl;

		else
			cout << "Reached Hysteresis in light - lys: " << plant_status.light_val << endl;
	}

/*	else if ((plant_status.light_val < avgmax) &&  (plant_status.light_val > avgmin))
	{
		cout << "Lyset ok" << endl;
	}*/

	else
	{
		return 0;
	}
	return 0;
}
int Kontrolsystem::intervalsTemperature()
{
	int avg = plantID[0].temp_val;
	int avgmin = avg - 5;
	int avgmax = avg + 5;
	int max = avg + 15;
	int min = avg - 15;

	if (plant_status.temp_val < min)
	{
		cout << "For lav temperatur - temperatur: " << plant_status.temp_val << endl;
	}
	else if (plant_status.temp_val > max)
	{
		cout << "For høj temperatur - temperatur: " << plant_status.temp_val << endl;
	}

	else if((plant_status.temp_val > min) && plant_status.temp_val < max)
	{
		if((plant_status.temp_val < avgmax) &&  (plant_status.temp_val > avgmin))
			cout << "Temperatur ok - temperatur: " << plant_status.temp_val << endl;

		else
			cout << "Reached Hysteresis in temperature - temperatur: " << plant_status.temp_val << endl;
	}
/*
	else if ((plant_status.temp_val < avgmax) &&  (plant_status.temp_val > avgmin))
	{
		cout << "Temperatur ok" << endl;
	}*/

	else
	{
		return 0;
	}
	return 0;
}
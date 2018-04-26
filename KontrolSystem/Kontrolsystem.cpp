/*
 * Kontrolsystem.cpp
 *
 *  Created on: 7 Nov 2017
 *      Author: Riemann
 */

#include "Kontrolsystem.h"
#include "mail.h"
#include "Sqlitecode.h"
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <ctype.h>
////////////KONTROLSYSTEM CONSTRUCTOR//////////
Kontrolsystem::Kontrolsystem()
{
	p1.name = "Basilikum";
	p1.temp_val = 0;
	p1.light_val = 0;
	p1.Moist_val = 0;
	//p1.hum_val = 0;
	p1.water_val = 0;

	p2.name = "Krus Persille";
	p2.temp_val = 0;
	p2.light_val = 0;
	p2.Moist_val = 0;
	//p2.hum_val = 0;
	p2.water_val = 0;

	p3.name = "Purløg";
	p3.temp_val = 0;
	p3.light_val = 0;
	p3.Moist_val = 0;
	//p3.hum_val = 0;
	p3.water_val = 0;

	p4.name = "Mynte";
	p4.temp_val = 0;
	p4.light_val = 0;
	p4.Moist_val = 0;
	//p4.hum_val = 0;
	p4.water_val = 0;

	p5.name = "Timian";
	p5.temp_val = 0;
	p5.light_val = 0;
	p5.Moist_val = 0;
	//p5.hum_val = 0;
	p5.water_val = 0;

	p6.name = "Rosmarin";
	p6.temp_val = 0;
	p6.light_val = 0;
	p6.Moist_val = 0;
	//p6.hum_val = 0;
	p6.water_val = 0;

	p7.name = "Citronmelisse";
	p7.temp_val = 0;
	p7.light_val = 0;
	p7.Moist_val = 0;
	//p7.hum_val = 0;
	p7.water_val = 0;

	p8.name = "Oregano(Merian)";
	p8.temp_val = 0;
	p8.light_val = 0;
	p8.Moist_val = 0;
	//p8.hum_val = 0;
	p8.water_val = 0;

	p9.name = "Salvie";
	p9.temp_val = 0;
	p9.light_val = 0;
	p9.Moist_val = 0;
	//p9.hum_val = 0;
	p9.water_val = 0;

	p10.name = "Test_plante";
	p10.temp_val = 0;
	p10.light_val = 0;
	p10.Moist_val = 0;
	//p10.hum_val = 0;
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

	//SENSOR VALUES
	plant_status.temp_val = tempSensor;
	plant_status.light_val = lightSensor;
	plant_status.Moist_val = moistSensor;
}

static void removePlant(vector<plant>& plantList){
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

static inline void emptyPlant(vector<plant>& plantList){
	plantList.clear();
}

static void addPlant(vector<plant>& plantList){
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
	//result.Moist_val = fertInput;
	//result.hum_val = humInput;
	result.water_val = waterInput;

	plantList.insert(plantList.begin() + element, result);
}

static void printPlants(vector<plant>& plantList){
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
			//cout << "|	Fertilizer:" << plantList[i].Moist_val << endl;
			//cout << "|	Humidity:" << plantList[i].hum_val << endl;
			cout << "|	Water:" << plantList[i].water_val << endl;
			cout << "--------------PAGE[" << i+1 << "]-------------" << endl << endl;
		}
	}
}

void Kontrolsystem::facSettings(void){
	p1.name = "Basilikum";
	p1.temp_val = 0;
	p1.light_val = 0;
	p1.Moist_val = 0;
	//p1.hum_val = 0;
	p1.water_val = 0;

	p2.name = "Krus Persille";
	p2.temp_val = 0;
	p2.light_val = 0;
	p2.Moist_val = 0;
	//p2.hum_val = 0;
	p2.water_val = 0;

	p3.name = "Purløg";
	p3.temp_val = 0;
	p3.light_val = 0;
	p3.Moist_val = 0;
	//p3.hum_val = 0;
	p3.water_val = 0;

	p4.name = "Mynte";
	p4.temp_val = 0;
	p4.light_val = 0;
	p4.Moist_val = 0;
	//p4.hum_val = 0;
	p4.water_val = 0;

	p5.name = "Timian";
	p5.temp_val = 0;
	p5.light_val = 0;
	p5.Moist_val = 0;
	//p5.hum_val = 0;
	p5.water_val = 0;

	p6.name = "Rosmarin";
	p6.temp_val = 0;
	p6.light_val = 0;
	p6.Moist_val = 0;
	//p6.hum_val = 0;
	p6.water_val = 0;

	p7.name = "Citronmelisse";
	p7.temp_val = 0;
	p7.light_val = 0;
	p7.Moist_val = 0;
	//p7.hum_val = 0;
	p7.water_val = 0;

	p8.name = "Oregano(Merian)";
	p8.temp_val = 0;
	p8.light_val = 0;
	p8.Moist_val = 0;
	//p8.hum_val = 0;
	p8.water_val = 0;

	p9.name = "Salvie";
	p9.temp_val = 0;
	p9.light_val = 0;
	p9.Moist_val = 0;
	//p9.hum_val = 0;
	p9.water_val = 0;

	p10.name = "Test_plante";
	p10.temp_val = 0;
	p10.light_val = 0;
	p10.Moist_val = 0;
	//p10.hum_val = 0;
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
		cout << "Fertilize: " << plantID[uInput].Moist_val << endl;
		//cout << "Humidity: " << plantID[uInput].hum_val << endl;
		cout << "----------------------------------" << endl;

		cout << "---PLANT_SPECIFICATIONS---" << endl;
		cout << "Choose another plant between <1-10> (11 to quit)" << endl;
		cin >> uInput;
	}

	//exit(0);
}

void Kontrolsystem::sleep(uint time){
	usleep(time*1000);	// ms delay (lidt mere præcist? Ellers bare gange 10⁶ for sec delay...)
}

void Kontrolsystem::criticalPlant(plant p_status)
{
	p_status = plant_status;	//	Adgang til sensor værdier til den bestemte plante igennem struct
}

plant Kontrolsystem::getInput(double userTemp, double userLight, double userFert)
{
	tempSensor = userTemp;
	lightSensor = userLight;
	moistSensor = userFert;
	//humSensor = userHum;

	plant_status.temp_val = userTemp;
	plant_status.light_val = userLight;
	plant_status.Moist_val = userFert;
	//plant_status.hum_val = userHum;

	return plant_status;
}

int Kontrolsystem::intervalsMoist()
{
	int avg = plantID[0].Moist_val;
	int avgmin = avg - 5;
	int avgmax = avg + 5;
	int max = avg + 15;
	int min = avg - 15;


	if (plant_status.Moist_val < min)
	{
		cout << "Gødning mangler - gødning: " << plant_status.Moist_val << endl;
	}
	else if (plant_status.Moist_val > max)
	{
		cout << "For meget Gødning - gødning: " << plant_status.Moist_val << endl;
	}

	else if((plant_status.Moist_val > min) && plant_status.Moist_val < max)
	{
		if((plant_status.Moist_val < avgmax) &&  (plant_status.Moist_val > avgmin))
			cout << "Gødning ok - gødning: " << plant_status.Moist_val << endl;

		else
			cout << "Reached Hysteresis in fertilize - gødning: " << plant_status.Moist_val << endl;
	}

/*	else if ((plant_status.Moist_val < avgmax) &&  (plant_status.Moist_val > avgmin))
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

void Kontrolsystem::sensorStatus()
{
	//	Update the sensor readings, before it gets printed
	getTemperature();
	getLight();
	getMoist();
	ifstream f("Sensor_database.db");
	if(!f.good()){
		f.close();
		Database_setup();
		Database_insert();
	}
	else{
		f.close();
	}
	string name;
	name = "Heat_1";
	Database_update(name, to_string(tempSensor));
	name = "Heat_2";
	Database_update(name, to_string(tempSensor_more));
	name = "Light_1";
	Database_update(name, to_string(lightSensor));
	name = "Light_2";
	Database_update(name, to_string(lightSensor_more));
	name = "Water_1";
	Database_update(name, to_string(moistSensor));
	name = "Water_2";
	Database_update(name, to_string(moistSensor_more));
	Database_select();
	cout << "----------------------------------" << endl;
	cout << "[Sensor-status]" << endl;
	printf("1. Temperature sensor: %.2lf °C\n", tempSensor);
	printf("2. Temperature sensor: %.2lf °C\n", tempSensor_more);

	if(lightSensor == 1)
		printf("1. LDR: HIGH\n");

	else if(lightSensor == 0)
		printf("1. LDR: LOW\n");

	if(lightSensor_more == 1)
		printf("2. LDR: HIGH\n");

	else if(lightSensor_more == 0)
		printf("2. LDR: LOW\n");

	//printf("1. LDR: %.2lf\n", lightSensor);
	//printf("2. LDR: %.2lf\n", lightSensor_more);

	printf("1. Moist sensor: %.2lf V\n", moistSensor);
	printf("2. Moist sensor: %.2lf V\n", moistSensor_more);

	cout << "----------------------------------" << endl;
}

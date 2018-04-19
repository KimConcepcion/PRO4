
#ifndef KONTROLSYSTEM_H_
#define KONTROLSYSTEM_H_

#include "Sensor.h"
#include <string>
#include <vector>

using namespace std;

struct Plant
{
	string name;
	double light_val;
	double temp_val;
	double Moist_val;
	double water_val;
};

typedef struct Plant plant;

class Kontrolsystem: public Sensor
{

public:
	Kontrolsystem();
	void namePlant();
	void sleep(uint time);
	void criticalPlant(plant p_status);
	void plantOrganizer();
	void facSettings(void);
	void sensorStatus();

	int intervalsHumidity();
	int intervalsMoist();
	int intervalsLight();
	int intervalsTemperature();

	void test(void);
	plant getInput(double userTemp, double userLight, double userMoist);

protected:
	plant p1, p2, p3, p4,p5, p6, p7, p8, p9, p10;
	plant plant_status;
	vector<plant> plantID;
};

#endif

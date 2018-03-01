/*
 * Values.cpp
 *
 *  Created on: 21 Nov 2017
 *      Author: Riemann
 */

#include <stdbool.h>
#include "Values.h"
#include <iostream>

void Values::getValues(double a, double b, double c, double d, double e)
{
	temp_val = a;
	light_val = b;
	fert_val = c;
	hum_val = d;
	water_val = e;

	//cout << temp_val << endl;
	//cout << light_val << endl;
	//cout << fert_val << endl;
	//cout << hum_val << endl;
}

int Values::intervalsHumidity()
{
	cout << temp_val << endl;
	cout << light_val << endl;
	cout << fert_val << endl;
	cout << hum_val << endl;

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
		cout << "Vand mangler" << endl;
	}
	else if (plant_status.hum_val > max)
	{
		cout << "For meget vand" << endl;
	}
	else if ((plant_status.hum_val < avgmax) &&  (plant_status.hum_val > avgmin))
	{
		cout << "Vand ok" << endl;
	}

	else
	{
		return 0;
	}
	return 0;
}
int Values::intervalsFertilizer()
{
	int avg = plantID[0].fert_val;
	int avgmin = avg - 5;
	int avgmax = avg + 5;
	int max = avg + 15;
	int min = avg - 15;


	if (plant_status.fert_val < min)
	{
		cout << "Gødning mangler" << endl;
	}
	else if (plant_status.fert_val > max)
	{
		cout << "For meget Gødning" << endl;
	}
	else if ((plant_status.fert_val < avgmax) &&  (plant_status.fert_val > avgmin))
	{
		cout << "Gødning ok" << endl;
	}

	else
	{
		return 0;
	}
	return 0;
}
int Values::intervalsLight()
{
	int avg = plantID[0].light_val;
	int avgmin = avg - 5;
	int avgmax = avg + 5;
	int max = avg + 15;
	int min = avg - 15;

	if (plant_status.light_val < min)
	{
		cout << "Lys mangler" << endl;
	}
	else if (plant_status.light_val > max)
	{
		cout << "For meget lys" << endl;
	}
	else if ((plant_status.light_val < avgmax) &&  (plant_status.light_val > avgmin))
	{
		cout << "Lyset ok" << endl;
	}

	else
	{
		return 0;
	}
	return 0;
}
int Values::intervalsTemperature()
{
	int avg = plantID[0].temp_val;
	int avgmin = avg - 5;
	int avgmax = avg + 5;
	int max = avg + 15;
	int min = avg - 15;


	if (plant_status.temp_val < min)
	{
		cout << "For lav temperatur" << endl;
	}
	else if (plant_status.temp_val > max)
	{
		cout << "For høj temperatur" << endl;
	}
	else if ((plant_status.temp_val < avgmax) &&  (plant_status.temp_val > avgmin))
	{
		cout << "Temperatur ok" << endl;
	}

	else
	{
		return 0;
	}
	return 0;
}

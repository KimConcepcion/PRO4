/*
 * Sensor.cpp
 *
 *  Created on: 7 Nov 2017
 *      Author: Riemann
 */

#include "Sensor.h"
#include <iostream>

void Sensor::getTemperature(uint *pPort, uint *pPin, double testVal)
{
	//double temp_ret = 0;
	//temp_val = analogRead(pPort, pPin);
	//tempSensor = temp_ret;
	tempSensor = testVal;
}

void Sensor::getLight(uint *pPort, uint *pPin, double testVal)
{
	//double light_ret = 0;
	//light_val = analogRead(pPort, pPin);
	//lightSensor = light_ret;
	lightSensor = testVal;
}

void Sensor::getFertilizer(uint *pPort, uint *pPin, double testVal)
{
	//double fert_ret = 0;
	//fert_val = analogRead(pPort, pPin);
	//fertSensor = fert_ret;
	fertSensor = testVal;
}

void Sensor::getHumidity(uint *pPort, uint *pPin, double testVal)
{
	//int hum_ret = 0;
	//hum_val = analogRead(pPort, pPin);
	//humSensor = hum_ret;
	humSensor = testVal;
}


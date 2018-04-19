/*
 * Sensor.cpp
 *
 *  Created on: 7 Nov 2017
 *      Author: Riemann
 */

#include "Sensor.h"
#include <iostream>
#include "sensor/LM35DZ.h"
#include "sensor/LDR.h"
#include "sensor/MoistSensor.h"

void Sensor::getTemperature(){
	tempSensor = readTemp_1();
	tempSensor_more = readTemp_2();
}

void Sensor::getLight(){
	lightSensor = readLight_1();
	lightSensor_more = readLight_2();
}

void Sensor::getMoist(){
	moistSensor = readMoist_1();
	moistSensor_more = readMoist_2();
}

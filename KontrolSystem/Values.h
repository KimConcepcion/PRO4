/*
 * Values.h
 *
 *  Created on: 21 Nov 2017
 *      Author: Riemann
 */
#include "Kontrolsystem.h"
#ifndef VALUES_H_
#define VALUES_H_

using namespace std;

class Values: public Kontrolsystem {
public:
	//Values(double a, double b, double c, double d, double e) : light_val(a), temp_val(b), fert_val(c), hum_val(d), water_val(e){};
	void getValues(double a, double b, double c, double d, double e);
	int intervalsHumidity();
	int intervalsFertilizer();
	int intervalsLight();
	int intervalsTemperature();

private:
	double light_val;
	double temp_val;
	double fert_val;
	double hum_val;
	double water_val;
};

#endif /* VALUES_H_ */

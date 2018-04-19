
#ifndef SENSOR_H_
#define SENSOR_H_

using namespace std;
typedef unsigned int uint;

class Sensor
{
public:
	void getTemperature();
	void getLight();
	void getMoist();

protected:
	double tempSensor;
	double tempSensor_more;

	int lightSensor;
	int lightSensor_more;

	double moistSensor;
	double moistSensor_more;
};

#endif

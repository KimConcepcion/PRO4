
#ifndef SENSOR_H_
#define SENSOR_H_

using namespace std;
typedef unsigned int uint;

class Sensor
{
public:
	void getTemperature(uint *pPort, uint *pPin, double testVal);
	void getLight(uint *pPort, uint *pPin, double testVal);
	void getFertilizer(uint *pPort, uint *pPin, double testVal);
	void getHumidity(uint *pPort, uint *pPin, double testVal);
	//void getInput(void);

protected:
	double tempSensor;
	double lightSensor;
	double fertSensor;
	double humSensor;
};

#endif

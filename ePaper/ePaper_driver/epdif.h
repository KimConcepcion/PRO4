
#ifndef EPDIF_H_
#define EPDIF_H_

#include <string>

using namespace std;

//	Pins:
#define RST  "/sys/class/gpio/gpio60/value"
#define DC	 "/sys/class/gpio/gpio48/value"
#define BUSY "/sys/class/gpio/gpio49/value"
#define CS   "/sys"

class EpdIf
{
public:
	EpdIf();
	~EpdIf();

	static int IfInit();
	static void DigitalWrite(string file, int value);
	static int DigitalRead(string file);
	static void DelayMs(unsigned int delaytime);

	static void SpiTransfer(unsigned char *data);
};

#endif

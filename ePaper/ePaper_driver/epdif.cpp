
#include "epdif.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "SPI.h"
#include <linux/spi/spidev.h>

using namespace std;

EpdIf::EpdIf(){
}

EpdIf::~EpdIf(){
}

void EpdIf::DigitalWrite(string file, int value) {

	ofstream w_file;

	if(file.compare(RST) == 0)
	{
		w_file.open(RST);
		w_file << value;
		w_file.close();
	}

	else if(file.compare(DC) == 0)
	{
		w_file.open(DC);
		w_file << value;
		w_file.close();
	}

	else if(file.compare(BUSY) == 0)
	{
		w_file.open(BUSY);
		w_file << value;
		w_file.close();
	}

	else if(file.compare(CS) == 0)
	{
		w_file.open(CS);
		w_file << value;
		w_file.close();
	}

	else
	{
		cout << "No valid files were selected..." << endl;
	}
}

int EpdIf::DigitalRead(string file) {

	int read_pin;
	ifstream r_file;

	if(file.compare(RST) == 0)
	{
		r_file.open(RST);
		r_file >> read_pin;
		r_file.close();
	}

	else if(file.compare(DC) == 0)
	{
		r_file.open(DC);
		r_file >> read_pin;
		r_file.close();
	}

	else if(file.compare(BUSY) == 0)
	{
		r_file.open(BUSY);
		r_file >> read_pin;
		r_file.close();
	}

	else if(file.compare(CS) == 0)
	{
		r_file.open(CS);
		r_file >> read_pin;
		r_file.close();
	}

	else
	{
		cout << "No valid files were selected..." << endl;
	}

	return read_pin;
}

void EpdIf::DelayMs(unsigned int delaytime) {
	delaytime = delaytime/1000;	//	Convert to ms: 10⁻³
	sleep(delaytime);
}

void EpdIf::SpiTransfer(unsigned char *data) {
	SPI SPI;
	int fd = 0;
	unsigned char null = 0x00;

	if(SPI.spi_transfer(fd, data, &null, 1) == -1)
	{
		perror("Failed to update the ePaper display!");
	}

	close(fd);
}

int EpdIf::IfInit() {

	ofstream w_file;
	SPI SPI;
	int fd = 0;
	int bits = 8;
	int speed = 2000000;

	w_file.open("/sys/class/gpio/gpio60/direction");
	w_file << "out";	//	Make to an output...
	w_file.close();

	w_file.open("/sys/class/gpio/gpio48/direction");
	w_file << "out";	//	Make to an output...
	w_file.close();

	w_file.open("/sys/class/gpio/gpio49/direction");
	w_file << "in";		//	Make to an input...
	w_file.close();

	//	Find ud af hvad du gør med CS pin...

	//	Set up SPI0 with specific parameters:
	SPI.begin(fd, bits, SPI_MODE_0, speed);

	close(fd);
	return 0;
}






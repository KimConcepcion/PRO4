
#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>

#define SPI_PATH "/dev/spidev1.0"

using namespace std;

class SPI
{
public:
	SPI();
	~SPI();

	int begin(int fd, uint8_t bits, uint8_t mode, uint32_t speed);
	int spi_transfer(int fd, unsigned char send[], unsigned char receive[], int length);
};

#endif

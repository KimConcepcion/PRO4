
#ifndef EPAPER_H_
#define EPAPER_H_

#include <stdint.h>

//	DC	(green wire)
#define DC_PATH "/sys/class/gpio/gpio60/value"

//	RST	(white wire)
#define RST_PATH "/sys/class/gpio/gpio48/value"

//	BUSY (purple wire)
#define BUSY_PATH "/sys/class/gpio/gpio49/value"

//	SPI path
#define SPI_PATH "/dev/spidev1.0"

//	Initialize display:
int ePaper_init(int fd, uint8_t bits, uint8_t mode, uint32_t speed);

//	SPI transfer data Prototype:
int spi_data(int fd, unsigned char send[], unsigned char receive[], int length);

#endif

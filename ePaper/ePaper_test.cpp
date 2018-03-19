
#include "ePaper.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <linux/spi/spidev.h>
#include <stdio.h>

using namespace std;

int main(void)
{
	printf("ePaper driver up and running!");

	int fd = 0;
	int i = 0;
	unsigned char value = 0x00;
	unsigned char null = 0x00;
	uint8_t bits = 8, mode = 3;
	uint32_t speed = 1000000;

	//	Initialize display:
	ePaper_init(fd, bits, mode, speed);

	if (spi_data(fd, (unsigned char*) &i, &null, 1) == -1)
	{
		perror("Failed to update the ePaper display!");
		return -1;
	}

	close(fd);
	return 0;
}

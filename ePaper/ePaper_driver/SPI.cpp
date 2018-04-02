
#include "SPI.h"
#include <linux/spi/spidev.h>
#include <sys/ioctl.h>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>

using namespace std;

SPI::SPI(){
}

SPI::~SPI(){
}

int SPI::begin(int fd, uint8_t bits, uint8_t mode, uint32_t speed)
{


		//	Setup the SPI bus properties:
		if ((fd = open(SPI_PATH, O_RDWR)) < 0) {
			perror("SPI Error: Can't open device!");
			return -1;
		}

		if (ioctl(fd, SPI_IOC_WR_MODE, &mode) == -1) {
			perror("SPI Error: Can't set SPI mode!");
			return -1;
		}

		if (ioctl(fd, SPI_IOC_RD_MODE, &mode) == -1) {
			perror("SPI Error: Can't get SPI mode!");
			return -1;
		}

		if (ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits) == -1) {
			perror("SPI Error: Can't set bits per word!");
			return -1;
		}

		if (ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits) == -1) {
			perror("SPI Error: Can't get bits per word!");
			return -1;
		}

		if (ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) == -1) {
			perror("SPI Error: Can't set max speed!");
			return -1;
		}

		if (ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed) == -1) {
			perror("SPI Error: Can't get max speed!");
			return -1;
		}

		//	Check the properties:
		printf("SPI Mode is: %d\n", mode);
		printf("SPI Bits is: %d\n", bits);
		printf("SPI Speed is: %d\n", speed);

	return 0;
}

int SPI::spi_transfer(int fd, unsigned char send[], unsigned char receive[], int length)
{
		struct spi_ioc_transfer transfer;
		transfer.tx_buf = (unsigned long) send;
		transfer.rx_buf = (unsigned long) receive;
		transfer.len = length;
		transfer.speed_hz = 1000000;
		transfer.bits_per_word = 8;
		transfer.delay_usecs = 0;

		int status = ioctl(fd, SPI_IOC_MESSAGE(1), &transfer);
		if (status < 0) {
			perror("SPI: SPI_IOC_MESSAGE Failed!");
			return -1;
		}
		return status;
}

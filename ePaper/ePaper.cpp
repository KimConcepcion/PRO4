#include "ePaper.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <linux/spi/spidev.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int ePaper_init(int fd, uint8_t bits, uint8_t mode, uint32_t speed) {
	ofstream DC_file(DC_PATH);
	ofstream RST_file(RST_PATH);

	DC_file << 0;	//	Write commands to display
	RST_file << 1;	//	Reset display

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

	DC_file.close();
	RST_file.close();
	return 0;
}

int spi_data(int fd, unsigned char send[], unsigned char receive[], int length) {
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

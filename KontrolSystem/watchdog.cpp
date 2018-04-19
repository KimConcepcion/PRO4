
#include "watchdog.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/watchdog.h>
#include <iostream>

using namespace std;

int watchdog_init(int time)
{
	int fd;

	if( (fd = open(WATCHDOG, O_RDWR)) < 0)
	{
		cerr << "Could not open /dev/watchdog" << endl;
		return -1;
	}

	if((ioctl(fd, WDIOC_SETTIMEOUT, &time)) != 0)
	{
		cerr << "Could not set the watchdog interval" << endl;
		return -1;
	}

	return 0;
}

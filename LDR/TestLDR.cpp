
#include <csignal>
#include <iostream>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include "LDR.h"

using namespace std;

double light;

void timerHandler(int signum)
{
	if(signum == 14)
	{
		light = readLight();
		fprintf(stdout, "Light read from LDR sensor is: %.2f Lux\n", light);
		fflush(stdout);
	}
}

int main(int argC, char **argV)
{
	//	Install signal hanler for timer interrupts:
	if(signal(14, timerHandler)==SIG_ERR)
		fprintf(stderr, "Could not install timerHandler\n");

	struct itimerval timer;
	timer.it_interval.tv_sec = 15;
	timer.it_interval.tv_usec = 0;
	timer.it_value.tv_sec  = 15;
	timer.it_value.tv_usec = 0;

	int retval = setitimer(ITIMER_REAL, &timer, NULL);
	if(retval != 0)
	{
		fprintf(stderr, "Could not install timer\n");
		exit(1);
	}

	while(1)
	{
	}

	return 0;
}

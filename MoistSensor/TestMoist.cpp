
#include <iostream>
#include <csignal>
#include <sys/time.h>
#include <unistd.h>
#include "MoistSensor.h"

using namespace std;

double moist;

void timerHandler(int signum)
{
	if(signum == 14)
	{
		moist = readMoist();
		fprintf(stdout, "moist read from moist sensor is: %.2f\n", moist);
		fflush(stdout);

		if (moist < 3000) {
		   cout << "Well done! Your plants are happy!\n" << endl;
		}
		else {
		   cout << "It's time to water your plants!\n" << endl;
		}
	}
}

int main(int argC, char **argV)
{
	//	Install signal hanler for timer interrupts:
	if(signal(14, timerHandler)==SIG_ERR)
		fprintf(stderr, "Could not install timerHandler\n");

	struct itimerval timer;
	timer.it_interval.tv_sec = 5;
	timer.it_interval.tv_usec = 0;
	timer.it_value.tv_sec  = 5;
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

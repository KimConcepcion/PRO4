
#include "mail.h"
#include <iostream>

#define MSG "Hello from your Beaglebone!"
using namespace std;

int main(void)
{
	cout << "Running the Mail test" << endl;
	if(sendMail(MSG) == -1)
		return -1;
	cout << "Check your mailbox!" << endl;

	return 0;
}

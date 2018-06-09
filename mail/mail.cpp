
#include "mail.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int sendMail(const char *message)
{
	ofstream mailFile (MSG_FILE);	//	Open the file which contains the message
	if(mailFile.is_open() == false)
	{
		cerr << "Could not open file" << endl;
		return -1;
	}

	mailFile << "to: kimnielsen33333@gmail.com\nfrom: UrbanGardeningPRO4@gmail.com\nsubject: Notifikation fra Urban gardening system!!!"
			<< endl;
	mailFile << message << endl;	//	Insert the message
	system(COMMAND);				//	Send til mail

	mailFile.close();
	return 0;
}

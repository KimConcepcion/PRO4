
#include "mail.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void sendMail()
{
	ofstream mailFile (MSG_FILE);

	//	Conditions to enter message after subject field...

	mailFile << "to: morten@ase.au.dk\nfrom: UrbanGardeningPRO4@gmail.com\nsubject: Notifikation fra Urban gardening system!!!" << endl;
	system(COMMAND);	//	Send til mail
	mailFile.close();
}

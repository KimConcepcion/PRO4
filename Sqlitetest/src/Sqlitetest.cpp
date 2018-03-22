//============================================================================
// Name        : Sqlitetest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include "Sqlitecode.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

#include <fstream>


int main(int argc, char* argv[]) {
	ifstream f("Test.db");
	if(!f.good()){
		f.close();
		Database_setup(argc, argv);
		Database_insert(argc, argv);
	}
	else{
		f.close();
	}
	Database_select(argc, argv);
	Database_update(argc, argv);
	return 0;
}

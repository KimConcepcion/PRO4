//============================================================================
// Name        : Sqlitetest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include <string>
#include <fstream>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

static int callback_fetch(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);

   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }

   printf("\n");
   return 0;
}

void Database_setup(int argc, char* argv[]){
	sqlite3 *db;
		int database;
		char * zErrMsg = 0;
		string sql;
		database = sqlite3_open("Test.db",&db);

		if(database == 0){
			cout << "Test opened" << endl;

		}
		else if(database != 0){
			cout << "Test is not opened" << sqlite3_errmsg(db) << endl;
			exit(0);
		}
		sql = "CREATE TABLE SENSORS("  \
				"ID INT PRIMARY KEY     NOT NULL," \
				"NAME           TEXT    NOT NULL," \
				"VALUE          INT     NOT NULL);";
		database = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

		if(database != SQLITE_OK){
				cout << "Test table is not created" << zErrMsg << endl;
				sqlite3_free(zErrMsg);

		}
		else {
			cout << "Test table created" << endl;

		}


		database = sqlite3_close(db);

		if(database == 0){
			cout << "Test closed" << endl;

		}
		else if(database != 0){
			cout << "Test is not closed" << endl;
		}
}

void Database_insert(int argc, char* argv[]){
	sqlite3 *db;
		int database;
		char * zErrMsg = 0;
		string sql;
		database = sqlite3_open("Test.db",&db);

		if(database == 0){
			cout << "Test opened" << endl;

		}
		else if(database != 0){
			cout << "Test is not opened" << sqlite3_errmsg(db) << endl;
			exit(0);
		}
		sql = "INSERT INTO SENSORS (ID,NAME,VALUE) "  \
				"VALUES (1, 'Light', 32); " \
				"INSERT INTO SENSORS (ID,NAME,VALUE) "  \
				"VALUES (2, 'MOISTURE', 25); "     \
				"INSERT INTO SENSORS (ID,NAME,VALUE)" \
				"VALUES (3, 'HEAT', 23);";

		database = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

		if(database != SQLITE_OK){
				cout << "Test table is not inserted into" << zErrMsg << endl;
				sqlite3_free(zErrMsg);

		}
		else {
			cout << "Test table is inserted into" << endl;

		}


		database = sqlite3_close(db);

		if(database == 0){
			cout << "Test closed" << endl;

		}
		else if(database != 0){
			cout << "Test is not closed" << endl;
		}
}

void Database_select(int argc, char* argv[]){
	sqlite3 *db;
		int database;
		char * zErrMsg = 0;
		string sql;
		const char* data = "Callback function called";
		database = sqlite3_open("Test.db",&db);

		if(database == 0){
			cout << "Test opened" << endl;

		}
		else if(database != 0){
			cout << "Test is not opened" << sqlite3_errmsg(db) << endl;
			exit(0);
		}
		sql = "SELECT * from SENSORS";

		database = sqlite3_exec(db, sql.c_str(), callback_fetch, (void*)data, &zErrMsg);

		if(database != SQLITE_OK){
				cout << "Could not extract " << zErrMsg << endl;
				sqlite3_free(zErrMsg);

		}
		else {
			cout << "Test table was extracted from" << endl;

		}


		database = sqlite3_close(db);

		if(database == 0){
			cout << "Test closed" << endl;

		}
		else if(database != 0){
			cout << "Test is not closed" << endl;
		}
}

void Database_update(int argc, char* argv[]){
	sqlite3 *db;
		int database;
		char * zErrMsg = 0;
		string sql;
		database = sqlite3_open("Test.db",&db);
		string SENSOR_value;
		string ID_value;
		ID_value = "2";
		SENSOR_value = "250";


		if(database == 0){
			cout << "Test opened" << endl;

		}
		else if(database != 0){
			cout << "Test is not opened" << sqlite3_errmsg(db) << endl;
			exit(0);
		}

		sql = "UPDATE SENSORS set VALUE = "+ SENSOR_value +" where ID="+ ID_value +"; ";

		database = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

		if(database != SQLITE_OK){
				cout << "Could not update " << zErrMsg << endl;
				sqlite3_free(zErrMsg);

		}
		else {
			cout << "Test table was updated" << endl;

		}


		database = sqlite3_close(db);

		if(database == 0){
			cout << "Test closed" << endl;

		}
		else if(database != 0){
			cout << "Test is not closed" << endl;
		}
}
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

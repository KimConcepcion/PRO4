/*
 * Sqlitecode.cpp
 *
 *  Created on: 22 Mar 2018
 *      Author: Lasse
 */

#include "Sqlitecode.h"
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

void Database_setup(){
	sqlite3 *db;
		int database;
		char * zErrMsg = 0;
		string sql;
		database = sqlite3_open("Sensor_database.db",&db);

		if(database == 0){
			cout << "Sensor_database opened" << endl;

		}
		else if(database != 0){
			cout << "Sensor_database is not opened" << sqlite3_errmsg(db) << endl;
			exit(0);
		}
		sql = "CREATE TABLE SENSORS("  \
				"ID INT PRIMARY KEY     NOT NULL," \
				"NAME           TEXT    NOT NULL," \
				"VALUE          INT     NOT NULL);";
		database = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

		if(database != SQLITE_OK){
				cout << "Sensor_database table is not created" << zErrMsg << endl;
				sqlite3_free(zErrMsg);

		}
		else {
			cout << "Sensor_database table created" << endl;

		}


		database = sqlite3_close(db);

		if(database == 0){
			cout << "Sensor_database closed" << endl;

		}
		else if(database != 0){
			cout << "Sensor_database is not closed" << endl;
		}
}

void Database_insert(){
	sqlite3 *db;
		int database;
		char * zErrMsg = 0;
		string sql;
		database = sqlite3_open("Sensor_database.db",&db);

		if(database == 0){
			cout << "Sensor_database opened" << endl;

		}
		else if(database != 0){
			cout << "Sensor_database is not opened" << sqlite3_errmsg(db) << endl;
			exit(0);
		}
		sql = "INSERT INTO SENSORS (ID,NAME,VALUE) "  \
				"VALUES (1, 'Heat_1', 0); " \
				"INSERT INTO SENSORS (ID,NAME,VALUE) "  \
				"VALUES (2, 'Heat_2', 0); " \
				"INSERT INTO SENSORS (ID,NAME,VALUE) "  \
				"VALUES (3, 'Light_1', 0); "     \
				"INSERT INTO SENSORS (ID,NAME,VALUE) "  \
				"VALUES (4, 'Light_2', 0); "     \
				"INSERT INTO SENSORS (ID,NAME,VALUE)" \
				"VALUES (5, 'Water_1', 0);";
				"INSERT INTO SENSORS (ID,NAME,VALUE)" \
				"VALUES (6, 'Water_2', 0);";

		database = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

		if(database != SQLITE_OK){
				cout << "Sensor_database table is not inserted into" << zErrMsg << endl;
				sqlite3_free(zErrMsg);

		}
		else {
			cout << "Sensor_database table is inserted into" << endl;

		}


		database = sqlite3_close(db);

		if(database == 0){
			cout << "Sensor_database closed" << endl;

		}
		else if(database != 0){
			cout << "Sensor_database is not closed" << endl;
		}
}

void Database_select(){
	sqlite3 *db;
		int database;
		char * zErrMsg = 0;
		string sql;
		const char* data = "Callback function called";
		database = sqlite3_open("Sensor_database.db",&db);

		if(database == 0){
			cout << "Sensor_database opened" << endl;

		}
		else if(database != 0){
			cout << "Sensor_database is not opened" << sqlite3_errmsg(db) << endl;
			exit(0);
		}
		sql = "SELECT * from SENSORS";

		database = sqlite3_exec(db, sql.c_str(), callback_fetch, (void*)data, &zErrMsg);

		if(database != SQLITE_OK){
				cout << "Could not extract " << zErrMsg << endl;
				sqlite3_free(zErrMsg);

		}
		else {
			cout << "Sensor_database table was extracted from" << endl;

		}


		database = sqlite3_close(db);

		if(database == 0){
			cout << "Sensor_database closed" << endl;

		}
		else if(database != 0){
			cout << "Sensor_database is not closed" << endl;
		}
}

void Database_update(string name, string SENSOR_value){
	sqlite3 *db;
		int database;
		char * zErrMsg = 0;
		string sql;
		database = sqlite3_open("Sensor_database.db",&db);
		string ID_value;
		if (name == "Heat_1"){
			ID_value = "1";
		}
		else if (name == "Heat_2"){
			ID_value = "2";
		}
		else if (name == "Light_1"){
			ID_value = "3";
		}
		else if (name == "Light_2"){
			ID_value = "4";
		}
		else if (name == "Water_1"){
			ID_value = "5";
		}
		else if (name == "Water_2"){
			ID_value = "6";
		}

		if(database == 0){
			cout << "Sensor_database opened" << endl;

		}
		else if(database != 0){
			cout << "Sensor_database is not opened" << sqlite3_errmsg(db) << endl;
			exit(0);
		}

		sql = "UPDATE SENSORS set VALUE = "+ SENSOR_value +" where ID="+ ID_value +"; ";

		database = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

		if(database != SQLITE_OK){
				cout << "Could not update " << zErrMsg << endl;
				sqlite3_free(zErrMsg);

		}
		else {
			cout << "Sensor_database table was updated" << endl;

		}


		database = sqlite3_close(db);

		if(database == 0){
			cout << "Sensor_database closed" << endl;

		}
		else if(database != 0){
			cout << "Sensor_database is not closed" << endl;
		}
}


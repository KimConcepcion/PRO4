
#ifndef COLLECTION_H_
#define COLLECTION_H_

#include "Sensor.h"
#include "Kontrolsystem.h"
#include "Values.h"

void printMenu(void);
//void testMenu(double userTemp, double userLight, double userFert, double userHum);
void userMenu(int userInput, Kontrolsystem obj);

#endif

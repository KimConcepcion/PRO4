
CC=/opt/toolchains/gnueabihf/bin/arm-linux-gnueabihf-g++

#echo "Building the module files and test files!";
all: TestLDR TestLM35DZ TestMoist TestMail TestWdog #TestSql

#	Build test executables:
TestLDR: TestLDR.o LDR.o
	$(CC) TestLDR.o LDR.o -o TestLDR
TestLM35DZ: TestLM35DZ.o LM35DZ.o
	$(CC) TestLM35DZ.o LM35DZ.o -o TestLM35DZ
TestMoist: TestMoist.o MoistSensor.o
	$(CC) TestMoist.o MoistSensor.o -o TestMoist
TestMail: TestMail.o mail.o
	$(CC) TestMail.o mail.o -o TestMail
TestWdog: TestWdog.o watchdog.o
	$(CC) TestWdog.o watchdog.o -o TestWdog 

#	Build Object implementation files:
LDR.o: ../sensor/LDR.cpp
	$(CC) -c ../sensor/LDR.cpp	
LM35DZ.o: ../sensor/LM35DZ.cpp
	$(CC) -c ../sensor/LM35DZ.cpp
MoistSensor.o: ../sensor/MoistSensor.cpp
	$(CC) -c ../sensor/MoistSensor.cpp
mail.o: ../mail/mail.cpp
	$(CC) -c ../mail/mail.cpp
watchdog.o: ../watchdog/watchdog.cpp
	$(CC) -c ../watchdog/watchdog.cpp
#Sqlitecode.o: ../../sqlite/Sqlitecode.cpp
#	$(CC) -c ../../sqlite/Sqlitecode.cpp

#	Build Object test files:
TestLDR.o: ../../LDR/TestLDR.cpp
	$(CC) -c ../../LDR/TestLDR.cpp
TestLM35DZ.o: ../../LM35DZ/TestLM35DZ.cpp
	$(CC) -c ../../LM35DZ/TestLM35DZ.cpp
TestMoist.o: ../../MoistSensor/TestMoist.cpp
	$(CC) -c ../../MoistSensor/TestMoist.cpp
TestMail.o: ../../mail/TestMail.cpp
	$(CC) -c ../../mail/TestMail.cpp
TestWdog.o: ../../Watchdog/TestWdog.cpp
	$(CC) -c ../../Watchdog/TestWdog.cpp

clean:
	rm *.o TestLDR TestLM35DZ TestMoist TestMail TestWdog #TestSql
	

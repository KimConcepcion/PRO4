#!/bin/bash
#	Script for running test interface
echo "Building test modules!"
make
echo "Transfering test files to Beaglebone!"
scp TestLDR kim@beagle:~
scp TestLM35DZ kim@beagle:~
scp TestMoist kim@beagle:~
scp TestMail kim@beagle:~
scp TestWdog kim@beagle:~
#./TestSql
echo "All done!"

#!/bin/bash

echo "Setting up GPIO pins and SPI0 for ePaper display!"

# Enable the GPIO pins for the ePaper display: 
cd /lib/firmware/
echo EPAPER-GPIO > $SLOTS
cd /sys/class/gpio

echo 60 > export
echo 49 > export
echo 48 > export

cd /sys/class/gpio/gpio60/
echo out > direction

cd /sys/class/gpio/gpio49/
echo in > direction

cd /sys/class/gpio/gpio48/
echo out > direction

# Enable the SPI:
cd /lib/firmware/
echo BB-SPIDEV0 > $SLOTS

# Print the enabled overlays:
cat $SLOTS

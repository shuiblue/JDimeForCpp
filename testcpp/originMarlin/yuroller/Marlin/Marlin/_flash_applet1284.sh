#!/bin/sh
AVR_TOOLS_DIR=~/opt/arduino-1.6.5/hardware/tools/avr
${AVR_TOOLS_DIR}/bin/avrdude -C ${AVR_TOOLS_DIR}/etc/avrdude.conf -b 57600 -c arduino -p m1284p -P /dev/ttyUSB0 -U flash:w:applet/Marlin.hex:i

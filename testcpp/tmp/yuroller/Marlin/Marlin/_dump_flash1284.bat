@echo off
set AVR_TOOLS_DIR=C:\UserPrograms\arduino-1.0.3\hardware\tools\avr
%AVR_TOOLS_DIR%\bin\avrdude -C %AVR_TOOLS_DIR%\etc\avrdude.conf -b 57600 -c arduino -p m1284p -P com3 -U flash:r:flashdump.hex:i
set AVR_TOOLS_DIR=
@echo off
set _old_path=%PATH%
set path=%PATH%;C:\UserPrograms\arduino-1.0.3\hardware\tools\avr\utils\bin
make clean
make HARDWARE_MOTHERBOARD=33 ARDUINO_INSTALL_DIR=C:\UserPrograms\arduino-1.0.3 AVR_TOOLS_PATH=C:\UserProgramsX86\arduino-1.0.3\hardware\tools\avr\bin\ ARDUINO_VERSION=103
set path=%_old_path%;
set _old_path=
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
/* -*- c++ -*- */
#endif
#if defined (marlin4Due)
    /**
    * Marlin Firmware
    *
    * Based on Sprinter and grbl.
    * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
    *
    * This program is free software: you can redistribute it and/or modify
    * it under the terms of the GNU General Public License as published by
    * the Free Software Foundation, either version 3 of the License, or
    * (at your option) any later version.
    *
    * This program is distributed in the hope that it will be useful,
    * but WITHOUT ANY WARRANTY; without even the implied warranty of
    * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    * GNU General Public License for more details.
    *
    * You should have received a copy of the GNU General Public License
    * along with this program.  If not, see <http://www.gnu.org/licenses/>.
    *
    * About Marlin
    *
    * This firmware is a mashup between Sprinter and grbl.
    *  - https://github.com/kliment/Sprinter
    *  - https://github.com/simen/grbl/tree
    *
    * It has preliminary support for Matthew Roberts advance algorithm
    *  - http://reprap.org/pipermail/reprap-dev/2011-May/003323.html
    */
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    /*
    Reprap firmware based on Sprinter and grbl.
    Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */
    /*
    This firmware is a mashup between Sprinter and grbl.
    (https://github.com/kliment/Sprinter)
    (https://github.com/simen/grbl/tree)

    It has preliminary support for Matthew Roberts advance algorithm
    http://reprap.org/pipermail/reprap-dev/2011-May/003323.html
    */
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
    #include "Marlin.h"
#endif
#if defined (upstream) && defined (ENABLE_AUTO_BED_LEVELING) || defined (bobc) && defined (ENABLE_AUTO_BED_LEVELING)
    #include "vector_3.h"
#endif
#if defined (upstream) && (defined (ENABLE_AUTO_BED_LEVELING) && defined (AUTO_BED_LEVELING_GRID) ) || defined (bobc) && (defined (ENABLE_AUTO_BED_LEVELING) && defined (AUTO_BED_LEVELING_GRID) )
    #include "qr_solve.h"
#endif
#if defined (upstream) || defined (bobc)
    // ENABLE_AUTO_BED_LEVELING
#endif
#if defined (marlin4Due) && ENABLED(MESH_BED_LEVELING)
    #include "mesh_bed_leveling.h"
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
    #include "ultralcd.h"
#endif
#if defined (oliv3r)
    #include "UltiLCD2.h"
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
    #include "planner.h"
    #include "stepper.h"
    #include "temperature.h"
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    #include "motion_control.h"
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
    #include "cardreader.h"
    #include "watchdog.h"
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    #include "ConfigurationStore.h"
#endif
#if defined (marlin4Due)
    #include "configuration_store.h"
#endif
#if defined (oliv3r)
    #include "lifetime_stats.h"
    #include "electronics_test.h"
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
    #include "language.h"
    #include "pins_arduino.h"
#endif
#if defined (upstream) || defined (bobc)
    #include "math.h"
#endif
#if defined (upstream) && defined (BLINKM) || defined (bobc) && defined (BLINKM)
    #include "BlinkM.h"
#endif
#if defined (marlin4Due)
    #include "buzzer.h"
#endif
#if defined (marlin4Due) && ENABLED(BLINKM)
    #include "blinkm.h"
#endif
#if defined (upstream) && defined (BLINKM) || defined (bobc) && defined (BLINKM)
    #include "Wire.h"
#endif
#if defined (upstream) && NUM_SERVOS > 0 || defined (bobc) && NUM_SERVOS > 0 || defined (indi-RichCattell) && NUM_SERVOS > 0 || defined (mattsch) && NUM_SERVOS > 0 || defined (oliv3r) && NUM_SERVOS > 0 || defined (quikshot) && NUM_SERVOS > 0 || defined (ErikZalm) && NUM_SERVOS > 0 || defined (alromh87) && NUM_SERVOS > 0
    #include "Servo.h"
#endif
#if defined (marlin4Due) && HAS_SERVOS
    #include "servo.h"
#endif
#if defined (upstream) && (defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1) || defined (bobc) && (defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1) || defined (indi-RichCattell) && (defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1) || defined (mattsch) && (defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1) || defined (oliv3r) && (defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1) || defined (quikshot) && (defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1) || defined (ErikZalm) && (defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1) || defined (alromh87) && (defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1) || defined (akadamson) && DIGIPOTSS_PIN > -1 || defined (hampussandberg) && (defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1) || defined (drsdre) && DIGIPOTSS_PIN > -1 || defined (indi-3DR) && DIGIPOTSS_PIN > -1 || defined (gregor2005) && DIGIPOTSS_PIN > -1 || defined (oysteinkrog) && (defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1) || defined (johnnyr) && (defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1) || defined (yuroller) && (defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1) || defined (ut7) && (defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1) || defined (marlin4Due) && HAS_DIGIPOTSS
    #include <SPI.h>
#endif
#if defined (upstream) || defined (yuroller)
    #define VERSION_STRING  "1.0.2"
#endif
#if defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (ut7)
    #define VERSION_STRING  "1.0.0"
#endif
#if defined (marlin4Due)
    /**
    * Look here for descriptions of G-codes:
    *  - http://linuxcnc.org/handbook/gcode/g-code.html
    *  - http://objects.reprap.org/wiki/Mendel_User_Manual:_RepRapGCodes
    *
    * Help us document these G-codes online:
    *  - http://www.marlinfirmware.org/index.php/G-Code
    *  - http://reprap.org/wiki/G-code
    *
    * -----------------
    * Implemented Codes
    * -----------------
    *
    * "G" Codes
    *
    * G0  -> G1
    * G1  - Coordinated Movement X Y Z E
    * G2  - CW ARC
    * G3  - CCW ARC
    * G4  - Dwell S<seconds> or P<milliseconds>
    * G10 - retract filament according to settings of M207
    * G11 - retract recover filament according to settings of M208
    * G28 - Home one or more axes
    * G29 - Detailed Z-Probe, probes the bed at 3 or more points.  Will fail if you haven't homed yet.
    * G30 - Single Z Probe, probes bed at current XY location.
    * G31 - Dock sled (Z_PROBE_SLED only)
    * G32 - Undock sled (Z_PROBE_SLED only)
    * G90 - Use Absolute Coordinates
    * G91 - Use Relative Coordinates
    * G92 - Set current position to coordinates given
    *
    * "M" Codes
    *
    * M0   - Unconditional stop - Wait for user to press a button on the LCD (Only if ULTRA_LCD is enabled)
    * M1   - Same as M0
    * M17  - Enable/Power all stepper motors
    * M18  - Disable all stepper motors; same as M84
    * M20  - List SD card
    * M21  - Init SD card
    * M22  - Release SD card
    * M23  - Select SD file (M23 filename.g)
    * M24  - Start/resume SD print
    * M25  - Pause SD print
    * M26  - Set SD position in bytes (M26 S12345)
    * M27  - Report SD print status
    * M28  - Start SD write (M28 filename.g)
    * M29  - Stop SD write
    * M30  - Delete file from SD (M30 filename.g)
    * M31  - Output time since last M109 or SD card start to serial
    * M32  - Select file and start SD print (Can be used _while_ printing from SD card files):
    *        syntax "M32 /path/filename#", or "M32 S<startpos bytes> !filename#"
    *        Call gcode file : "M32 P !filename#" and return to caller file after finishing (similar to #include).
    *        The '#' is necessary when calling from within sd files, as it stops buffer prereading
    * M33  - Get the longname version of a path
    * M42  - Change pin status via gcode Use M42 Px Sy to set pin x to value y, when omitting Px the onboard led will be used.
    * M48  - Measure Z_Probe repeatability. M48 [P # of points] [X position] [Y position] [V_erboseness #] [E_ngage Probe] [L # of legs of travel]
    * M80  - Turn on Power Supply
    * M81  - Turn off Power Supply
    * M82  - Set E codes absolute (default)
    * M83  - Set E codes relative while in Absolute Coordinates (G90) mode
    * M84  - Disable steppers until next move,
    *        or use S<seconds> to specify an inactivity timeout, after which the steppers will be disabled.  S0 to disable the timeout.
    * M85  - Set inactivity shutdown timer with parameter S<seconds>. To disable set zero (default)
    * M92  - Set axis_steps_per_unit - same syntax as G92
    * M104 - Set extruder target temp
    * M105 - Read current temp
    * M106 - Fan on
    * M107 - Fan off
    * M109 - Sxxx Wait for extruder current temp to reach target temp. Waits only when heating
    *        Rxxx Wait for extruder current temp to reach target temp. Waits when heating and cooling
    *        IF AUTOTEMP is enabled, S<mintemp> B<maxtemp> F<factor>. Exit autotemp by any M109 without F
    * M110 - Set the current line number
    * M111 - Set debug flags with S<mask>. See flag bits defined in Marlin.h.
    * M112 - Emergency stop
    * M114 - Output current position to serial port
    * M115 - Capabilities string
    * M117 - Display a message on the controller screen
    * M119 - Output Endstop status to serial port
    * M120 - Enable endstop detection
    * M121 - Disable endstop detection
    * M126 - Solenoid Air Valve Open (BariCUDA support by jmil)
    * M127 - Solenoid Air Valve Closed (BariCUDA vent to atmospheric pressure by jmil)
    * M128 - EtoP Open (BariCUDA EtoP = electricity to air pressure transducer by jmil)
    * M129 - EtoP Closed (BariCUDA EtoP = electricity to air pressure transducer by jmil)
    * M140 - Set bed target temp
    * M145 - Set the heatup state H<hotend> B<bed> F<fan speed> for S<material> (0=PLA, 1=ABS)
    * M150 - Set BlinkM Color Output R: Red<0-255> U(!): Green<0-255> B: Blue<0-255> over i2c, G for green does not work.
    * M190 - Sxxx Wait for bed current temp to reach target temp. Waits only when heating
    *        Rxxx Wait for bed current temp to reach target temp. Waits when heating and cooling
    * M200 - set filament diameter and set E axis units to cubic millimeters (use S0 to set back to millimeters).:D<millimeters>-
    * M201 - Set max acceleration in units/s^2 for print moves (M201 X1000 Y1000)
    * M202 - Set max acceleration in units/s^2 for travel moves (M202 X1000 Y1000) Unused in Marlin!!
    * M203 - Set maximum feedrate that your machine can sustain (M203 X200 Y200 Z300 E10000) in mm/sec
    * M204 - Set default acceleration: P for Printing moves, R for Retract only (no X, Y, Z) moves and T for Travel (non printing) moves (ex. M204 P800 T3000 R9000) in mm/sec^2
    * M205 -  advanced settings:  minimum travel speed S=while printing T=travel only,  B=minimum segment time X= maximum xy jerk, Z=maximum Z jerk, E=maximum E jerk
    * M206 - Set additional homing offset
    * M207 - Set retract length S[positive mm] F[feedrate mm/min] Z[additional zlift/hop], stays in mm regardless of M200 setting
    * M208 - Set recover=unretract length S[positive mm surplus to the M207 S*] F[feedrate mm/min]
    * M209 - S<1=true/0=false> enable automatic retract detect if the slicer did not support G10/11: every normal extrude-only move will be classified as retract depending on the direction.
    * M218 - Set hotend offset (in mm): T<extruder_number> X<offset_on_X> Y<offset_on_Y>
    * M220 - Set speed factor override percentage: S<factor in percent>
    * M221 - Set extrude factor override percentage: S<factor in percent>
    * M226 - Wait until the specified pin reaches the state required: P<pin number> S<pin state>
    * M240 - Trigger a camera to take a photograph
    * M250 - Set LCD contrast C<contrast value> (value 0..63)
    * M280 - Set servo position absolute. P: servo index, S: angle or microseconds
    * M300 - Play beep sound S<frequency Hz> P<duration ms>
    * M301 - Set PID parameters P I and D
    * M302 - Allow cold extrudes, or set the minimum extrude S<temperature>.
    * M303 - PID relay autotune S<temperature> sets the target temperature. (default target temperature = 150C)
    * M304 - Set bed PID parameters P I and D
    * M380 - Activate solenoid on active extruder
    * M381 - Disable all solenoids
    * M400 - Finish all moves
    * M401 - Lower z-probe if present
    * M402 - Raise z-probe if present
    * M404 - N<dia in mm> Enter the nominal filament width (3mm, 1.75mm ) or will display nominal filament width without parameters
    * M405 - Turn on Filament Sensor extrusion control.  Optional D<delay in cm> to set delay in centimeters between sensor and extruder
    * M406 - Turn off Filament Sensor extrusion control
    * M407 - Display measured filament diameter
    * M410 - Quickstop. Abort all the planned moves
    * M420 - Enable/Disable Mesh Leveling (with current values) S1=enable S0=disable
    * M421 - Set a single Z coordinate in the Mesh Leveling grid. X<mm> Y<mm> Z<mm>
    * M428 - Set the home_offset logically based on the current_position
    * M500 - Store parameters in EEPROM
    * M501 - Read parameters from EEPROM (if you need reset them after you changed them temporarily).
    * M502 - Revert to the default "factory settings". You still need to store them in EEPROM afterwards if you want to.
    * M503 - Print the current settings (from memory not from EEPROM). Use S0 to leave off headings.
    * M540 - Use S[0|1] to enable or disable the stop SD card print on endstop hit (requires ABORT_ON_ENDSTOP_HIT_FEATURE_ENABLED)
    * M600 - Pause for filament change X[pos] Y[pos] Z[relative lift] E[initial retract] L[later retract distance for removal]
    * M665 - Set delta configurations: L<diagonal rod> R<delta radius> S<segments/s>
    * M666 - Set delta endstop adjustment
    * M605 - Set dual x-carriage movement mode: S<mode> [ X<duplication x-offset> R<duplication temp offset> ]
    * M907 - Set digital trimpot motor current using axis codes.
    * M908 - Control digital trimpot directly.
    * M350 - Set microstepping mode.
    * M351 - Toggle MS1 MS2 pins directly.
    *
    * ************ SCARA Specific - This can change to suit future G-code regulations
    * M360 - SCARA calibration: Move to cal-position ThetaA (0 deg calibration)
    * M361 - SCARA calibration: Move to cal-position ThetaB (90 deg calibration - steps per degree)
    * M362 - SCARA calibration: Move to cal-position PsiA (0 deg calibration)
    * M363 - SCARA calibration: Move to cal-position PsiB (90 deg calibration - steps per degree)
    * M364 - SCARA calibration: Move to cal-position PSIC (90 deg to Theta calibration position)
    * M365 - SCARA calibration: Scaling factor, X, Y, Z axis
    * ************* SCARA End ***************
    *
    * ************ Custom codes - This can change to suit future G-code regulations
    * M100 - Watch Free Memory (For Debugging Only)
    * M851 - Set probe's Z offset (mm above extruder -- The value will always be negative)


    * M928 - Start SD logging (M928 filename.g) - ended by M29
    * M999 - Restart after being stopped by error
    *
    * "T" Codes
    *
    * T0-T3 - Select a tool by index (usually an extruder) [ F<mm/min> ]
    *
    */
#endif
#if defined (indi-RichCattell) || defined (oliv3r) || defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005)
    // look here for descriptions of gcodes: http://linuxcnc.org/handbook/gcode/g-code.html
#endif
#if defined (upstream) || defined (bobc)
    // look here for descriptions of G-codes: http://linuxcnc.org/handbook/gcode/g-code.html
#endif
#if defined (marlin4Due) && ENABLED(M100_FREE_MEMORY_WATCHER)
    void gcode_M100();
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // http://objects.reprap.org/wiki/Mendel_User_Manual:_RepRapGCodes
    //Implemented Codes
    //-------------------
    // G0  -> G1
    // G1  - Coordinated Movement X Y Z E
    // G2  - CW ARC
    // G3  - CCW ARC
    // G4  - Dwell S<seconds> or P<milliseconds>
    // G10 - retract filament according to settings of M207
    // G11 - retract recover filament according to settings of M208
    // G28 - Home all Axis
#endif
#if defined (indi-RichCattell)
    // G29 - Calibrate print surface with automatic Z probe
#endif
#if defined (upstream) || defined (bobc)
    // G29 - Detailed Z-Probe, probes the bed at 3 or more points.  Will fail if you haven't homed yet.
#endif
#if defined (indi-RichCattell)
    // G30 - Bed Probe and Delta geometry Autocalibration
#endif
#if defined (upstream) || defined (bobc)
    // G30 - Single Z Probe, probes bed at current XY location.
#endif
#if defined (upstream) || defined (mattsch) || defined (ErikZalm) || defined (hampussandberg) || defined (oysteinkrog) || defined (yuroller) || defined (ut7)
    // G31 - Dock sled (Z_PROBE_SLED only)
    // G32 - Undock sled (Z_PROBE_SLED only)
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // G90 - Use Absolute Coordinates
    // G91 - Use Relative Coordinates
#endif
#if defined (indi-RichCattell) || defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005)
    // G92 - Set current position to cordinates given
#endif
#if defined (upstream) || defined (bobc)
    // G92 - Set current position to coordinates given
#endif
#if defined (oliv3r) || defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005)
    //RepRap M Codes
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch)
    // M Codes
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // M0   - Unconditional stop - Wait for user to press a button on the LCD (Only if ULTRA_LCD is enabled)
    // M1   - Same as M0
#endif
#if defined (oliv3r) || defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005)
    // M104 - Set extruder target temp
    // M105 - Read current temp
    // M106 - Fan on
    // M107 - Fan off
    // M109 - Wait for extruder current temp to reach target temp.
    // M114 - Display current position
    //Custom M Codes
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // M17  - Enable/Power all stepper motors
    // M18  - Disable all stepper motors; same as M84
    // M20  - List SD card
    // M21  - Init SD card
    // M22  - Release SD card
    // M23  - Select SD file (M23 filename.g)
    // M24  - Start/resume SD print
    // M25  - Pause SD print
    // M26  - Set SD position in bytes (M26 S12345)
    // M27  - Report SD print status
    // M28  - Start SD write (M28 filename.g)
    // M29  - Stop SD write
    // M30  - Delete file from SD (M30 filename.g)
    // M31  - Output time since last M109 or SD card start to serial
#endif
#if defined (indi-RichCattell)
    // M32  - Select file and start SD print (Can be used when printing from SD card)
#endif
#if defined (akadamson) || defined (indi-3DR)
    // M42  - Change pin status via gcode
#endif
#if defined (upstream) || defined (bobc)
    // M32  - Select file and start SD print (Can be used _while_ printing from SD card files):
    //        syntax "M32 /path/filename#", or "M32 S<startpos bytes> !filename#"
    //        Call gcode file : "M32 P !filename#" and return to caller file after finishing (similar to #include).
    //        The '#' is necessary when calling from within sd files, as it stops buffer prereading
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87)
    // M42  - Change pin status via gcode Use M42 Px Sy to set pin x to value y, when omitting Px the onboard led will be used.
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // M80  - Turn on Power Supply
    // M81  - Turn off Power Supply
    // M82  - Set E codes absolute (default)
    // M83  - Set E codes relative while in Absolute Coordinates (G90) mode
    // M84  - Disable steppers until next move,
    //        or use S<seconds> to specify an inactivity timeout, after which the steppers will be disabled.  S0 to disable the timeout.
    // M85  - Set inactivity shutdown timer with parameter S<seconds>. To disable set zero (default)
    // M92  - Set axis_steps_per_unit - same syntax as G92
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch)
    // M104 - Set extruder target temp
    // M105 - Read current temp
    // M106 - Fan on
    // M107 - Fan off
    // M109 - Sxxx Wait for extruder current temp to reach target temp. Waits only when heating
    //        Rxxx Wait for extruder current temp to reach target temp. Waits when heating and cooling
#endif
#if defined (upstream) || defined (bobc)
    //        IF AUTOTEMP is enabled, S<mintemp> B<maxtemp> F<factor>. Exit autotemp by any M109 without F
    // M112 - Emergency stop
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // M114 - Output current position to serial port
    // M115 - Capabilities string
    // M117 - display message
    // M119 - Output Endstop status to serial port
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87)
    // M126 - Solenoid Air Valve Open (BariCUDA support by jmil)
    // M127 - Solenoid Air Valve Closed (BariCUDA vent to atmospheric pressure by jmil)
    // M128 - EtoP Open (BariCUDA EtoP = electricity to air pressure transducer by jmil)
    // M129 - EtoP Closed (BariCUDA EtoP = electricity to air pressure transducer by jmil)
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // M140 - Set bed target temp
#endif
#if defined (oliv3r) || defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005)
    // M190 - Wait for bed current temp to reach target temp.
#endif
#if defined (upstream) || defined (bobc)
    // M150 - Set BlinkM Color Output R: Red<0-255> U(!): Green<0-255> B: Blue<0-255> over i2c, G for green does not work.
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch)
    // M190 - Sxxx Wait for bed current temp to reach target temp. Waits only when heating
    //        Rxxx Wait for bed current temp to reach target temp. Waits when heating and cooling
#endif
#if defined (indi-RichCattell) || defined (oliv3r) || defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005)
    // M200 - Set filament diameter
#endif
#if defined (upstream) || defined (bobc)
    // M200 D<millimeters>- set filament diameter and set E axis units to cubic millimeters (use S0 to set back to millimeters).
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // M201 - Set max acceleration in units/s^2 for print moves (M201 X1000 Y1000)
    // M202 - Set max acceleration in units/s^2 for travel moves (M202 X1000 Y1000) Unused in Marlin!!
    // M203 - Set maximum feedrate that your machine can sustain (M203 X200 Y200 Z300 E10000) in mm/sec
#endif
#if defined (indi-RichCattell) || defined (oliv3r) || defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005)
    // M204 - Set default acceleration: S normal moves T filament only moves (M204 S3000 T7000) im mm/sec^2  also sets minimum segment time in ms (B20000) to prevent buffer underruns and M20 minimum feedrate
#endif
#if defined (upstream) || defined (bobc)
    // M204 - Set default acceleration: S normal moves T filament only moves (M204 S3000 T7000) in mm/sec^2  also sets minimum segment time in ms (B20000) to prevent buffer under-runs and M20 minimum feedrate
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // M205 -  advanced settings:  minimum travel speed S=while printing T=travel only,  B=minimum segment time X= maximum xy jerk, Z=maximum Z jerk, E=maximum E jerk
#endif
#if defined (indi-RichCattell) || defined (oliv3r) || defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005)
    // M206 - set additional homeing offset
#endif
#if defined (upstream) || defined (bobc)
    // M206 - set additional homing offset
#endif
#if defined (indi-RichCattell) || defined (oliv3r) || defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005)
    // M207 - set retract length S[positive mm] F[feedrate mm/sec] Z[additional zlift/hop]
#endif
#if defined (upstream) || defined (bobc)
    // M207 - set retract length S[positive mm] F[feedrate mm/min] Z[additional zlift/hop], stays in mm regardless of M200 setting
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // M208 - set recover=unretract length S[positive mm surplus to the M207 S*] F[feedrate mm/sec]
    // M209 - S<1=true/0=false> enable automatic retract detect if the slicer did not support G10/11: every normal extrude-only move will be classified as retract depending on the direction.
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87)
    // M218 - set hotend offset (in mm): T<extruder_number> X<offset_on_X> Y<offset_on_Y>
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // M220 S<factor in percent>- set speed factor override percentage
    // M221 S<factor in percent>- set extrude factor override percentage
#endif
#if defined (upstream) || defined (bobc)
    // M226 P<pin number> S<pin state>- Wait until the specified pin reaches the state required
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // M240 - Trigger a camera to take a photograph
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch)
    // M250 - Set LCD contrast C<contrast value> (value 0..63)
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87)
    // M280 - set servo position absolute. P: servo index, S: angle or microseconds
    // M300 - Play beep sound S<frequency Hz> P<duration ms>
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // M301 - Set PID parameters P I and D
#endif
#if defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005)
    // M302 - Allow cold extrudes
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87)
    // M302 - Allow cold extrudes, or set the minimum extrude S<temperature>.
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // M303 - PID relay autotune S<temperature> sets the target temperature. (default target temperature = 150C)
    // M304 - Set bed PID parameters P I and D
    // M400 - Finish all moves
#endif
#if defined (indi-RichCattell) || defined (oliv3r) || defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005)
    // M500 - stores paramters in EEPROM
#endif
#if defined (upstream) || defined (bobc)
    // M401 - Lower z-probe if present
    // M402 - Raise z-probe if present
#endif
#if defined (upstream) || defined (mattsch) || defined (ErikZalm) || defined (oysteinkrog) || defined (yuroller) || defined (ut7)
    // M404 - N<dia in mm> Enter the nominal filament width (3mm, 1.75mm ) or will display nominal filament width without parameters
    // M405 - Turn on Filament Sensor extrusion control.  Optional D<delay in cm> to set delay in centimeters between sensor and extruder
    // M406 - Turn off Filament Sensor extrusion control
    // M407 - Displays measured filament diameter
#endif
#if defined (upstream) || defined (bobc)
    // M500 - stores parameters in EEPROM
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // M501 - reads parameters from EEPROM (if you need reset them after you changed them temporarily).
    // M502 - reverts to the default "factory settings".  You still need to store them in EEPROM afterwards if you want to.
#endif
#if defined (indi-RichCattell) || defined (oliv3r) || defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005)
    // M503 - print the current settings (from memory not from eeprom)
#endif
#if defined (upstream) || defined (bobc)
    // M503 - print the current settings (from memory not from EEPROM)
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87)
    // M540 - Use S[0|1] to enable or disable the stop SD card print on endstop hit (requires ABORT_ON_ENDSTOP_HIT_FEATURE_ENABLED)
    // M600 - Pause for filament change X[pos] Y[pos] Z[relative lift] E[initial retract] L[later retract distance for removal]
#endif
#if defined (upstream) || defined (bobc)
    // M665 - set delta configurations
    // M666 - set delta endstop adjustment
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch)
    // M605 - Set dual x-carriage movement mode: S<mode> [ X<duplication x-offset> R<duplication temp offset> ]
#endif
#if defined (indi-RichCattell)
    // M666 - Endstop and delta geometry adjustment
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // M907 - Set digital trimpot motor current using axis codes.
    // M908 - Control digital trimpot directly.
    // M350 - Set microstepping mode.
    // M351 - Toggle MS1 MS2 pins directly.
#endif
#if defined (oliv3r)
    // M923 - Select file and start printing directly (can be used from other SD file)
#endif
#if defined (upstream) || defined (mattsch) || defined (ErikZalm) || defined (hampussandberg) || defined (oysteinkrog) || defined (yuroller) || defined (ut7)
    // ************ SCARA Specific - This can change to suit future G-code regulations
    // M360 - SCARA calibration: Move to cal-position ThetaA (0 deg calibration)
    // M361 - SCARA calibration: Move to cal-position ThetaB (90 deg calibration - steps per degree)
    // M362 - SCARA calibration: Move to cal-position PsiA (0 deg calibration)
    // M363 - SCARA calibration: Move to cal-position PsiB (90 deg calibration - steps per degree)
    // M364 - SCARA calibration: Move to cal-position PSIC (90 deg to Theta calibration position)
    // M365 - SCARA calibration: Scaling factor, X, Y, Z axis
    //************* SCARA End ***************
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87)
    // M928 - Start SD logging (M928 filename.g) - ended by M29
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    // M999 - Restart after being stopped by error
    //Stepper Movement Variables
    //===========================================================================
    //=============================imported variables============================
    //===========================================================================
    //===========================================================================
    //=============================public variables=============================
    //===========================================================================
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (indi-3DR) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && ENABLED(SDSUPPORT)
    CardReader card;
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    float homing_feedrate[] = HOMING_FEEDRATE;
#endif
#if defined (marlin4Due)
    bool Running = true;
#endif
#if defined (indi-RichCattell)
    float default_z_probe_offset[] = Z_PROBE_OFFSET;
#endif
#if defined (marlin4Due)
    uint8_t marlin_debug_flags = DEBUG_INFO|DEBUG_ERRORS;
#endif
#if defined (indi-RichCattell)
    float z_probe_offset[3];
#endif
#if defined (marlin4Due)
    static float feedrate = 1500.0, saved_feedrate;
#endif
#if defined (indi-RichCattell)
    float z_probe_deploy_start_location[] = Z_PROBE_DEPLOY_START_LOCATION;
#endif
#if defined (marlin4Due)
float current_position[NUM_AXIS] = { 0.0 };
#endif
#if defined (indi-RichCattell)
    float z_probe_deploy_end_location[] = Z_PROBE_DEPLOY_END_LOCATION;
#endif
#if defined (marlin4Due)
static float destination[NUM_AXIS] = { 0.0 };
#endif
#if defined (indi-RichCattell)
    float z_probe_retract_start_location[] = Z_PROBE_RETRACT_START_LOCATION;
#endif
#if defined (marlin4Due)
bool axis_known_position[3] = { false };
#endif
#if defined (indi-RichCattell)
    float z_probe_retract_end_location[] = Z_PROBE_RETRACT_END_LOCATION;
#endif
#if defined (marlin4Due)
    static long gcode_N, gcode_LastN, Stopped_gcode_LastN = 0;
    static char *current_command, *current_command_args;
    static int cmd_queue_index_r = 0;
    static int cmd_queue_index_w = 0;
    static int commands_in_queue = 0;
    static char command_queue[BUFSIZE][MAX_CMD_SIZE];
    const float homing_feedrate[] = HOMING_FEEDRATE;
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
    bool axis_relative_modes[] = AXIS_RELATIVE_MODES;
#endif
#if defined (akadamson)
    volatile int feedmultiply=100;
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87)
    int feedmultiply=100;
#endif
#if defined (marlin4Due)
    int feedrate_multiplier = 100;
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
    //100->1 200->2
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    int saved_feedmultiply;
#endif
#if defined (marlin4Due)
    int saved_feedrate_multiplier;
#endif
#if defined (oliv3r)
    int extrudemultiply[EXTRUDERS]=ARRAY_BY_EXTRUDERS(100, 100, 100);
#endif
#if defined (akadamson)
    volatile bool feedmultiplychanged=false;
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch)
    int extrudemultiply=100;
#endif
#if defined (marlin4Due)
    int extruder_multiplier[EXTRUDERS] = ARRAY_BY_EXTRUDERS1(100);
#endif
#if defined (akadamson)
    volatile int extrudemultiply=100;
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    //100->1 200->2
#endif
#if defined (upstream) || defined (bobc)
int extruder_multiply[EXTRUDERS] = {100
#if EXTRUDERS > 1
                                    , 100
#if EXTRUDERS > 2
                                    , 100
#endif
#endif
                                   };
#endif
#if defined (upstream) || defined (oysteinkrog) || defined (yuroller) || defined (marlin4Due)
    bool volumetric_enabled = false;
#endif
#if defined (upstream) || defined (oysteinkrog) || defined (yuroller)
float filament_size[EXTRUDERS] = { DEFAULT_NOMINAL_FILAMENT_DIA
#if EXTRUDERS > 1
                                   , DEFAULT_NOMINAL_FILAMENT_DIA
#if EXTRUDERS > 2
                                   , DEFAULT_NOMINAL_FILAMENT_DIA
#endif
#endif
                                 };
#endif
#if defined (marlin4Due)
    float filament_size[EXTRUDERS] = ARRAY_BY_EXTRUDERS1(DEFAULT_NOMINAL_FILAMENT_DIA);
#endif
#if defined (upstream) || defined (bobc)
float volumetric_multiplier[EXTRUDERS] = {1.0
#if EXTRUDERS > 1
                                          , 1.0
#if EXTRUDERS > 2
                                          , 1.0
#endif
#endif
                                         };
#endif
#if defined (marlin4Due)
    float volumetric_multiplier[EXTRUDERS] = ARRAY_BY_EXTRUDERS1(1.0);
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
float current_position[NUM_AXIS] = { 0.0, 0.0, 0.0, 0.0 };
#endif
#if defined (marlin4Due)
float home_offset[3] = { 0 };
#endif
#if defined (bobc) || defined (indi-RichCattell) || defined (oliv3r) || defined (quikshot) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (johnnyr)
float add_homeing[3]= {0,0,0};
#endif
#if defined (upstream) || defined (mattsch) || defined (ErikZalm) || defined (oysteinkrog) || defined (yuroller) || defined (ut7)
float add_homing[3]= {0,0,0};
#endif
#if defined (upstream) && defined (DELTA) || defined (bobc) && defined (DELTA) || defined (indi-RichCattell) && defined (DELTA) || defined (mattsch) && defined (DELTA)
float endstop_adj[3]= {0,0,0};
#endif
#if defined (indi-RichCattell) && defined (DELTA)
float tower_adj[6]= {0,0,0,0,0,0};
float delta_radius;
// = DEFAULT_delta_radius;
float delta_diagonal_rod;
// = DEFAULT_DELTA_DIAGONAL_ROD;
float DELTA_DIAGONAL_ROD_2;
float ac_prec = AUTOCALIBRATION_PRECISION / 2;
float bed_radius = BED_DIAMETER / 2;
float delta_tower1_x, delta_tower1_y;
float delta_tower2_x, delta_tower2_y;
float delta_tower3_x, delta_tower3_y;
float base_max_pos[3] = {X_MAX_POS, Y_MAX_POS, Z_MAX_POS};
float base_home_pos[3] = {X_HOME_POS, Y_HOME_POS, Z_HOME_POS};
float max_length[3] = {X_MAX_LENGTH, Y_MAX_LENGTH, Z_MAX_LENGTH};
float saved_position[3]= {0.0,0.0,0.0};
float saved_positions[7][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
};
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
float min_pos[3] = { X_MIN_POS, Y_MIN_POS, Z_MIN_POS };
float max_pos[3] = { X_MAX_POS, Y_MAX_POS, Z_MAX_POS };
#endif
#if defined (oliv3r) || defined (drsdre) || defined (gregor2005)
    // Extruder offset, only in XY plane
#endif
#if defined (upstream) || defined (bobc)
bool axis_known_position[3] = {false, false, false};
#endif
#if defined (oliv3r) && EXTRUDERS > 1 || defined (drsdre) && EXTRUDERS > 1 || defined (gregor2005) && EXTRUDERS > 1
float extruder_offset[2][EXTRUDERS] = {
#if defined(EXTRUDER_OFFSET_X) && defined(EXTRUDER_OFFSET_Y)
    EXTRUDER_OFFSET_X, EXTRUDER_OFFSET_Y
#endif
};
#endif
#if defined (upstream) || defined (bobc)
    float zprobe_zoffset;
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch)
    // Extruder offset
#endif
#if defined (upstream) && (EXTRUDERS > 1 && !defined (DUAL_X_CARRIAGE) ) || defined (bobc) && (EXTRUDERS > 1 && !defined (DUAL_X_CARRIAGE) ) || defined (indi-RichCattell) && (EXTRUDERS > 1 && !defined (DUAL_X_CARRIAGE) ) || defined (mattsch) && (EXTRUDERS > 1 && !defined (DUAL_X_CARRIAGE) )
    #define NUM_EXTRUDER_OFFSETS 2
    // only in XY plane
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (DUAL_X_CARRIAGE) ) || defined (bobc) && (EXTRUDERS > 1 && defined (DUAL_X_CARRIAGE) ) || defined (indi-RichCattell) && (EXTRUDERS > 1 && defined (DUAL_X_CARRIAGE) ) || defined (mattsch) && (EXTRUDERS > 1 && defined (DUAL_X_CARRIAGE) )
    #define NUM_EXTRUDER_OFFSETS 3
    // supports offsets in XYZ plane
#endif
#if defined (upstream) && EXTRUDERS > 1 || defined (bobc) && EXTRUDERS > 1 || defined (indi-RichCattell) && EXTRUDERS > 1 || defined (mattsch) && EXTRUDERS > 1
float extruder_offset[NUM_EXTRUDER_OFFSETS][EXTRUDERS] = {
#if defined(EXTRUDER_OFFSET_X) && defined(EXTRUDER_OFFSET_Y)
    EXTRUDER_OFFSET_X, EXTRUDER_OFFSET_Y
#endif
};
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
    uint8_t active_extruder = 0;
#endif
#if defined (oliv3r)
    uint8_t fanSpeed=0;
#endif
#if defined (akadamson)
    unsigned char FanSpeed=0;
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch)
    int fanSpeed=0;
#endif
#if defined (oliv3r)
    uint8_t fanSpeedPercent=100;
#endif
#if defined (marlin4Due)
    bool cancel_heatup = false;
#endif
#if defined (oliv3r)
struct machinesettings {
    machinesettings() : has_saved_settings(0) {}
    int feedmultiply;
    int HotendTemperature[EXTRUDERS];
    int BedTemperature;
    uint8_t fanSpeed;
    int extrudemultiply[EXTRUDERS];
    long max_acceleration_units_per_sq_second[NUM_AXIS];
    float max_feedrate[NUM_AXIS];
    float acceleration;
    float minimumfeedrate;
    float mintravelfeedrate;
    long minsegmenttime;
    float max_xy_jerk;
    float max_z_jerk;
    float max_e_jerk;
    uint8_t has_saved_settings;
};
#endif
#if defined (marlin4Due)
    const char errormagic[] PROGMEM = "Error:";
#endif
#if defined (oliv3r)
    machinesettings machinesettings_tempsave[10];
#endif
#if defined (marlin4Due)
    const char echomagic[] PROGMEM = "echo:";
#endif
#if defined (upstream) && defined (SERVO_ENDSTOPS) || defined (bobc) && defined (SERVO_ENDSTOPS) || defined (indi-RichCattell) && defined (SERVO_ENDSTOPS) || defined (mattsch) && defined (SERVO_ENDSTOPS) || defined (oliv3r) && defined (SERVO_ENDSTOPS) || defined (quikshot) && defined (SERVO_ENDSTOPS) || defined (ErikZalm) && defined (SERVO_ENDSTOPS) || defined (alromh87) && defined (SERVO_ENDSTOPS)
    int servo_endstops[] = SERVO_ENDSTOPS;
#endif
#if defined (marlin4Due)
const char axis_codes[NUM_AXIS] = {'X', 'Y', 'Z', 'E'};
#endif
#if defined (upstream) && defined (SERVO_ENDSTOPS) || defined (bobc) && defined (SERVO_ENDSTOPS) || defined (indi-RichCattell) && defined (SERVO_ENDSTOPS) || defined (mattsch) && defined (SERVO_ENDSTOPS) || defined (oliv3r) && defined (SERVO_ENDSTOPS) || defined (quikshot) && defined (SERVO_ENDSTOPS) || defined (ErikZalm) && defined (SERVO_ENDSTOPS) || defined (alromh87) && defined (SERVO_ENDSTOPS)
    int servo_endstop_angles[] = SERVO_ENDSTOP_ANGLES;
#endif
#if defined (marlin4Due)
    static bool relative_mode = false;
    //Determines Absolute or Relative Coordinates
    static char serial_char;
    static int serial_count = 0;
    static boolean comment_mode = false;
    static char *seen_pointer;
    ///< A pointer to find chars in the command string (X, Y, Z, E, etc.)
    const char* queued_commands_P= NULL;
    /* pointer to the current line in the active sequence of commands, or NULL when none */
    const int sensitive_pins[] = SENSITIVE_PINS;
    ///< Sensitive pin list for M42
    // Inactivity shutdown
    millis_t previous_cmd_ms = 0;
    static millis_t max_inactive_time = 0;
    static millis_t stepper_inactive_time = DEFAULT_STEPPER_DEACTIVE_TIME * 1000L;
    millis_t print_job_start_ms = 0;
    ///< Print job start time
    millis_t print_job_stop_ms = 0;
    ///< Print job stop time
    static uint8_t target_extruder;
    bool no_wait_for_cooling = true;
    bool target_direction;
#endif
#if defined (marlin4Due) && ENABLED(ENABLE_AUTO_BED_LEVELING)
    int xy_travel_speed = XY_TRAVEL_SPEED;
    float zprobe_zoffset = Z_PROBE_OFFSET_FROM_EXTRUDER;
#endif
#if defined (marlin4Due) && (ENABLED(Z_DUAL_ENDSTOPS) && DISABLED(DELTA))
    float z_endstop_adj = 0;
#endif
#if defined (marlin4Due)
    // Extruder offsets
#endif
#if defined (marlin4Due) && (EXTRUDERS > 1 && !defined (EXTRUDER_OFFSET_X) )
    #define EXTRUDER_OFFSET_X { 0 }
#endif
#if defined (marlin4Due) && (EXTRUDERS > 1 && !defined (EXTRUDER_OFFSET_Y) )
    #define EXTRUDER_OFFSET_Y { 0 }
#endif
#if defined (marlin4Due) && EXTRUDERS > 1
float extruder_offset[][EXTRUDERS] = {
    EXTRUDER_OFFSET_X,
    EXTRUDER_OFFSET_Y
#if ENABLED(DUAL_X_CARRIAGE)
    , { 0 } // supports offsets in XYZ plane
#endif
};
#endif
#if defined (marlin4Due) && HAS_SERVO_ENDSTOPS
    const int servo_endstop_id[] = SERVO_ENDSTOP_IDS;
    const int servo_endstop_angle[][2] = SERVO_ENDSTOP_ANGLES;
#endif
#if defined (upstream) && defined (BARICUDA) || defined (bobc) && defined (BARICUDA) || defined (indi-RichCattell) && defined (BARICUDA) || defined (mattsch) && defined (BARICUDA) || defined (oliv3r) && defined (BARICUDA) || defined (quikshot) && defined (BARICUDA) || defined (ErikZalm) && defined (BARICUDA) || defined (alromh87) && defined (BARICUDA)
    int ValvePressure=0;
    int EtoPPressure=0;
#endif
#if defined (indi-RichCattell) && defined (FWRETRACT) || defined (akadamson) && defined (FWRETRACT) || defined (drsdre) && defined (FWRETRACT) || defined (indi-3DR) && defined (FWRETRACT) || defined (gregor2005) && defined (FWRETRACT)
    bool autoretract_enabled=true;
#endif
#if defined (upstream) && defined (FWRETRACT) || defined (bobc) && defined (FWRETRACT)
    bool autoretract_enabled=false;
#endif
#if defined (bobc) && defined (FWRETRACT) || defined (indi-RichCattell) && defined (FWRETRACT) || defined (oliv3r) && defined (FWRETRACT) || defined (alromh87) && defined (FWRETRACT) || defined (akadamson) && defined (FWRETRACT) || defined (drsdre) && defined (FWRETRACT) || defined (indi-3DR) && defined (FWRETRACT) || defined (gregor2005) && defined (FWRETRACT) || defined (johnnyr) && defined (FWRETRACT)
    bool retracted=false;
#endif
#if defined (upstream) && defined (FWRETRACT) || defined (mattsch) && defined (FWRETRACT) || defined (quikshot) && defined (FWRETRACT) || defined (ErikZalm) && defined (FWRETRACT) || defined (hampussandberg) && defined (FWRETRACT) || defined (oysteinkrog) && defined (FWRETRACT) || defined (yuroller) && defined (FWRETRACT) || defined (ut7) && defined (FWRETRACT)
bool retracted[EXTRUDERS]= {false
#if EXTRUDERS > 1
                            , false
#if EXTRUDERS > 2
                            , false
#endif
#endif
                           };
#endif
#if defined (marlin4Due) && ENABLED(FWRETRACT)
bool retracted[EXTRUDERS] = { false };
#endif
#if defined (oliv3r) && defined (FWRETRACT)
    float retract_length=4.5, retract_feedrate=25*60, retract_zlift=0.8;
#endif
#if defined (indi-RichCattell) && defined (FWRETRACT) || defined (akadamson) && defined (FWRETRACT) || defined (drsdre) && defined (FWRETRACT) || defined (indi-3DR) && defined (FWRETRACT) || defined (gregor2005) && defined (FWRETRACT)
    float retract_length=3, retract_feedrate=17*60, retract_zlift=0.8;
#endif
#if defined (upstream) && defined (FWRETRACT) || defined (mattsch) && defined (FWRETRACT) || defined (quikshot) && defined (FWRETRACT) || defined (ErikZalm) && defined (FWRETRACT) || defined (hampussandberg) && defined (FWRETRACT) || defined (oysteinkrog) && defined (FWRETRACT) || defined (yuroller) && defined (FWRETRACT) || defined (ut7) && defined (FWRETRACT)
bool retracted_swap[EXTRUDERS]= {false
#if EXTRUDERS > 1
                                 , false
#if EXTRUDERS > 2
                                 , false
#endif
#endif
                                };
#endif
#if defined (marlin4Due) && ENABLED(FWRETRACT)
bool retracted_swap[EXTRUDERS] = { false };
#endif
#if defined (oliv3r) && (EXTRUDERS > 1 && defined (FWRETRACT) )
    float extruder_swap_retract_length=16.0;
#endif
#if defined (indi-RichCattell) && defined (FWRETRACT) || defined (akadamson) && defined (FWRETRACT) || defined (drsdre) && defined (FWRETRACT) || defined (indi-3DR) && defined (FWRETRACT) || defined (gregor2005) && defined (FWRETRACT)
    float retract_recover_length=0, retract_recover_feedrate=8*60;
#endif
#if defined (upstream) && defined (FWRETRACT) || defined (bobc) && defined (FWRETRACT)
    float retract_length = RETRACT_LENGTH;
#endif
#if defined (oliv3r) && defined (FWRETRACT)
    float retract_recover_length=0, retract_recover_feedrate=25*60;
#endif
#if defined (upstream) && defined (FWRETRACT) || defined (mattsch) && defined (FWRETRACT) || defined (quikshot) && defined (FWRETRACT) || defined (ErikZalm) && defined (FWRETRACT) || defined (hampussandberg) && defined (FWRETRACT) || defined (oysteinkrog) && defined (FWRETRACT) || defined (yuroller) && defined (FWRETRACT) || defined (ut7) && defined (FWRETRACT) || defined (marlin4Due) && ENABLED(FWRETRACT)
    float retract_length_swap = RETRACT_LENGTH_SWAP;
#endif
#if defined (oliv3r)
    uint8_t printing_state;
#endif
#if defined (upstream) && defined (FWRETRACT) || defined (bobc) && defined (FWRETRACT)
    float retract_feedrate = RETRACT_FEEDRATE;
    float retract_zlift = RETRACT_ZLIFT;
    float retract_recover_length = RETRACT_RECOVER_LENGTH;
#endif
#if defined (upstream) && defined (FWRETRACT) || defined (mattsch) && defined (FWRETRACT) || defined (quikshot) && defined (FWRETRACT) || defined (ErikZalm) && defined (FWRETRACT) || defined (hampussandberg) && defined (FWRETRACT) || defined (oysteinkrog) && defined (FWRETRACT) || defined (yuroller) && defined (FWRETRACT) || defined (ut7) && defined (FWRETRACT) || defined (marlin4Due) && ENABLED(FWRETRACT)
    float retract_recover_length_swap = RETRACT_RECOVER_LENGTH_SWAP;
#endif
#if defined (upstream) && defined (FWRETRACT) || defined (bobc) && defined (FWRETRACT)
    float retract_recover_feedrate = RETRACT_RECOVER_FEEDRATE;
#endif
#if defined (upstream) && (defined (ULTIPANEL) && defined (PS_DEFAULT_OFF) ) || defined (bobc) && (defined (ULTIPANEL) && defined (PS_DEFAULT_OFF) )
    bool powersupply = false;
#endif
#if defined (marlin4Due)
    // FWRETRACT
#endif
#if defined (upstream) && (!defined (PS_DEFAULT_OFF) && defined (ULTIPANEL) ) || defined (bobc) && (!defined (PS_DEFAULT_OFF) && defined (ULTIPANEL) ) || defined (indi-RichCattell) && defined (ULTIPANEL) || defined (mattsch) && (!defined (PS_DEFAULT_OFF) && defined (ULTIPANEL) )
    bool powersupply = true;
#endif
#if defined (marlin4Due) && (ENABLED(ULTIPANEL) && HAS_POWER_SWITCH)
    bool powersupply =
    #if ENABLED(PS_DEFAULT_OFF)
        false
    #else
        true
    #endif
    ;
#endif
#if defined (upstream) && defined (DELTA) || defined (bobc) && defined (DELTA) || defined (indi-RichCattell) && defined (DELTA) || defined (mattsch) && defined (DELTA)
float delta[3] = {0.0, 0.0, 0.0};
#endif
#if defined (marlin4Due) && ENABLED(DELTA)
float delta[3] = { 0 };
#endif
#if defined (indi-RichCattell) && defined (DELTA)
float delta_tmp[3] = {0.0, 0.0, 0.0};
#endif
#if defined (upstream) && defined (DELTA) || defined (bobc) && defined (DELTA)
    #define SIN_60 0.8660254037844386
    #define COS_60 0.5
#endif
#if defined (marlin4Due) && ENABLED(DELTA)
float endstop_adj[3] = { 0 };
#endif
#if defined (upstream) && defined (DELTA) || defined (bobc) && defined (DELTA)
    // these are the default values, can be overriden with M665
    float delta_radius= DELTA_RADIUS;
    float delta_tower1_x= -SIN_60*delta_radius;
    // front left tower
    float delta_tower1_y= -COS_60*delta_radius;
    float delta_tower2_x=  SIN_60*delta_radius;
    // front right tower
    float delta_tower2_y= -COS_60*delta_radius;
    float delta_tower3_x= 0.0;
#endif
#if defined (marlin4Due) && ENABLED(DELTA)
    float delta_tower3_x = 0;
#endif
#if defined (upstream) && defined (DELTA) || defined (bobc) && defined (DELTA)
    // back middle tower
    float delta_tower3_y= delta_radius;
    float delta_diagonal_rod= DELTA_DIAGONAL_ROD;
    float delta_diagonal_rod_2= sq(delta_diagonal_rod);
    float delta_segments_per_second= DELTA_SEGMENTS_PER_SECOND;
#endif
#if defined (upstream) && defined (SCARA) || defined (mattsch) && defined (SCARA) || defined (ErikZalm) && defined (SCARA) || defined (hampussandberg) && defined (SCARA) || defined (oysteinkrog) && defined (SCARA) || defined (yuroller) && defined (SCARA) || defined (ut7) && defined (SCARA)
    // Build size scaling
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(DELTA) )
int delta_grid_spacing[2] = { 0, 0 };
float bed_level[AUTO_BED_LEVELING_GRID_POINTS][AUTO_BED_LEVELING_GRID_POINTS];
#endif
#if defined (marlin4Due) && !ENABLED(DELTA)
    static bool home_all_axis = true;
#endif
#if defined (marlin4Due) && ENABLED(SCARA)
float delta_segments_per_second = SCARA_SEGMENTS_PER_SECOND;
static float delta[3] = { 0 };
#endif
#if defined (upstream) && defined (SCARA) || defined (mattsch) && defined (SCARA) || defined (ErikZalm) && defined (SCARA) || defined (hampussandberg) && defined (SCARA) || defined (oysteinkrog) && defined (SCARA) || defined (yuroller) && defined (SCARA) || defined (ut7) && defined (SCARA) || defined (marlin4Due) && ENABLED(SCARA)
float axis_scaling[3]= {1,1,1};
// Build size scaling, default to 1
#endif
#if defined (upstream) || defined (bobc)
    bool cancel_heatup = false ;
#endif
#if defined (upstream) && defined (FILAMENT_SENSOR) || defined (mattsch) && defined (FILAMENT_SENSOR) || defined (ErikZalm) && defined (FILAMENT_SENSOR) || defined (oysteinkrog) && defined (FILAMENT_SENSOR) || defined (yuroller) && defined (FILAMENT_SENSOR) || defined (ut7) && defined (FILAMENT_SENSOR) || defined (marlin4Due) && ENABLED(FILAMENT_SENSOR)
    //Variables for Filament Sensor input
    float filament_width_nominal=DEFAULT_NOMINAL_FILAMENT_DIA;
    //Set nominal filament width, can be changed with M404
    bool filament_sensor=false;
    //M405 turns on filament_sensor control, M406 turns it off
    float filament_width_meas=DEFAULT_MEASURED_FILAMENT_DIA;
    //Stores the measured filament diameter
    signed char measurement_delay[MAX_MEASUREMENT_DELAY+1];
    //ring buffer to delay measurement  store extruder factor after subtracting 100
    int delay_index1=0;
    //index into ring buffer
    int delay_index2=-1;
    //index into ring buffer - set to -1 on startup to indicate ring buffer needs to be initialized
    float delay_dist=0;
    //delay distance counter
    int meas_delay_cm = MEASUREMENT_DELAY_CM;
    //distance delay setting
#endif
#if defined (upstream) || defined (ErikZalm) || defined (oysteinkrog) || defined (yuroller)
    const char errormagic[] PROGMEM = "Error:";
#endif
#if defined (marlin4Due) && ENABLED(FILAMENT_RUNOUT_SENSOR)
    static bool filrunoutEnqueued = false;
#endif
#if defined (upstream) || defined (ErikZalm) || defined (oysteinkrog) || defined (yuroller)
    const char echomagic[] PROGMEM = "echo:";
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    //===========================================================================
#endif
#if defined (indi-RichCattell) || defined (oliv3r) || defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005)
    //=============================private variables=============================
#endif
#if defined (upstream) || defined (bobc)
    //=============================Private Variables=============================
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
//===========================================================================
const char axis_codes[NUM_AXIS] = {'X', 'Y', 'Z', 'E'};
#endif
#if defined (indi-RichCattell)
    const float SIN_60 = 0.8660254037844386;
    const float COS_60 = 0.5;
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
static float destination[NUM_AXIS] = {  0.0, 0.0, 0.0, 0.0};
#endif
#if defined (upstream) && !defined (DELTA) || defined (mattsch) && !defined (DELTA) || defined (oliv3r) && defined (DELTA) || defined (ErikZalm) && !defined (DELTA) || defined (hampussandberg) || defined (indi-3DR) || defined (oysteinkrog) && !defined (DELTA) || defined (yuroller) && !defined (DELTA) || defined (ut7) && !defined (DELTA)
static float delta[3] = {0.0, 0.0, 0.0};
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
static float offset[3] = {0.0, 0.0, 0.0};
#endif
#if defined (indi-RichCattell)
static float bed_level[7][7] = {
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
};
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    static bool home_all_axis = true;
#endif
#if defined (indi-RichCattell)
    static float feedrate = 1500.0, next_feedrate, saved_feedrate, z_offset;
#endif
#if defined (upstream) || defined (bobc)
    static float feedrate = 1500.0, next_feedrate, saved_feedrate;
#endif
#if defined (indi-RichCattell)
    static float bed_level_x, bed_level_y, bed_level_z;
    static float bed_level_c = 45;
    //used for inital bed probe safe distance (to avoid crashing into bed)
    static float bed_level_ox, bed_level_oy, bed_level_oz;
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    static long gcode_N, gcode_LastN, Stopped_gcode_LastN = 0;
#endif
#if defined (indi-RichCattell)
    static int loopcount;
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    static bool relative_mode = false;
    //Determines Absolute or Relative Coordinates
    static char cmdbuffer[BUFSIZE][MAX_CMD_SIZE];
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due) && ENABLED(SDSUPPORT)
    static bool fromsd[BUFSIZE];
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    static int bufindr = 0;
#endif
#if defined (marlin4Due) && HAS_SERVOS
    Servo servo[NUM_SERVOS];
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    static int bufindw = 0;
    static int buflen = 0;
    //static int i = 0;
    static char serial_char;
    static int serial_count = 0;
    static boolean comment_mode = false;
    static char *strchr_pointer;
#endif
#if defined (indi-RichCattell) || defined (oliv3r) || defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005)
    // just a pointer to find chars in the cmd string like X, Y, Z, E, etc
#endif
#if defined (upstream) || defined (bobc)
    // just a pointer to find chars in the command string like X, Y, Z, E, etc
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    const int sensitive_pins[] = SENSITIVE_PINS;
    // Sensitive pin list for M42
    //static float tt = 0;
    //static float bt = 0;
    //Inactivity shutdown variables
    static unsigned long previous_millis_cmd = 0;
    static unsigned long max_inactive_time = 0;
    static unsigned long stepper_inactive_time = DEFAULT_STEPPER_DEACTIVE_TIME*1000l;
    unsigned long starttime=0;
    unsigned long stoptime=0;
    static uint8_t tmp_extruder;
#endif
#if defined (oliv3r)
    uint8_t Stopped = false;
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch)
    bool Stopped=false;
#endif
#if defined (upstream) && NUM_SERVOS > 0 || defined (bobc) && NUM_SERVOS > 0 || defined (indi-RichCattell) && NUM_SERVOS > 0 || defined (mattsch) && NUM_SERVOS > 0 || defined (oliv3r) && NUM_SERVOS > 0 || defined (quikshot) && NUM_SERVOS > 0 || defined (ErikZalm) && NUM_SERVOS > 0 || defined (alromh87) && NUM_SERVOS > 0
    Servo servos[NUM_SERVOS];
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch)
    bool CooldownNoWait = true;
    bool target_direction;
#endif
#if defined (upstream) || defined (bobc)
    //Insert variables if CHDK is defined
#endif
#if defined (upstream) && defined (CHDK) || defined (bobc) && defined (CHDK)
    unsigned long chdkHigh = 0;
    boolean chdkActive = false;
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
    //===========================================================================
#endif
#if defined (indi-RichCattell) || defined (oliv3r) || defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005)
    //=============================ROUTINES=============================
#endif
#if defined (upstream) || defined (bobc)
    //=============================Routines======================================
#endif
#if defined (marlin4Due)
    //================================ Functions ================================
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
    //===========================================================================
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    void get_arc_coordinates();
#endif
#if defined (marlin4Due)
    void process_next_command();
#endif
#if defined (drsdre)
    void set_extskipwindow_coordinates();
#endif
#if defined (marlin4Due)
    void plan_arc(float target[NUM_AXIS], float *offset, uint8_t clockwise);
#endif
#if defined (drsdre)
    void get_extskipwindow_coordinates();
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
    bool setTargetedHotend(int code);
#endif
#if defined (marlin4Due)
void serial_echopair_P(const char *s_P, int v)           {
    serialprintPGM(s_P);
    SERIAL_ECHO(v);
}
void serial_echopair_P(const char *s_P, long v)          {
    serialprintPGM(s_P);
    SERIAL_ECHO(v);
}
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
void serial_echopair_P
(const char *s_P, float v) {
    serialprintPGM(s_P);
    SERIAL_ECHO(v);
}
void serial_echopair_P
(const char *s_P, double v) {
    serialprintPGM(s_P);
    SERIAL_ECHO(v);
}
void serial_echopair_P
(const char *s_P, unsigned long v) {
    serialprintPGM(s_P);
    SERIAL_ECHO(v);
}
#endif
#if defined (marlin4Due) && ENABLED(PREVENT_DANGEROUS_EXTRUDE)
    float extrude_min_temp = EXTRUDE_MINTEMP;
#endif
#if defined (marlin4Due) && defined (__AVR__)
    // HAL for Due
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (marlin4Due) && (defined (SDSUPPORT) && defined (__AVR__) )
#include "SdFatUtil.h"

int freeMemory() {
    return SdFatUtil::FreeRam();
}
#endif
#if defined (upstream) && !defined (SDSUPPORT) || defined (indi-RichCattell) || defined (mattsch) && !defined (SDSUPPORT) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) && !defined (SDSUPPORT) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) && !defined (SDSUPPORT) || defined (johnnyr) || defined (yuroller) && !defined (SDSUPPORT) || defined (ut7) || defined (marlin4Due) && (!defined (SDSUPPORT) && defined (__AVR__) )

extern "C" {
    extern unsigned int __bss_end;
    extern unsigned int __heap_start;
    extern void *__brkval;

    int freeMemory() {
        int free_memory;
        if ((int)__brkval == 0)
            free_memory = ((int)&free_memory) - ((int)&__bss_end);
        else
            free_memory = ((int)&free_memory) - ((int)__brkval);
        return free_memory;
    }
}
#endif
#if defined (oliv3r)
    //Clear all the commands in the ASCII command buffer, to make sure we have room for abort commands.
#endif
#if defined (upstream) || defined (mattsch) || defined (ErikZalm) || defined (oysteinkrog) || defined (yuroller) || defined (marlin4Due) && defined (__AVR__)
    //!SDSUPPORT
#endif
#if defined (oliv3r)
void clear_command_queue() {
    if (buflen > 0) {
        bufindw = (bufindr + 1)%BUFSIZE;
        buflen = 1;
    }
}
#endif
#if defined (marlin4Due)
    /**
    * Inject the next command from the command queue, when possible
    * Return false only if no command was pending
    */
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    //adds an command to the main command buffer
#endif
#if defined (marlin4Due)
static bool drain_queued_commands_P() {
    if (!queued_commands_P) return false;
    // Get the next 30 chars from the sequence of gcodes to run
    char cmd[30];
    strncpy_P(cmd, queued_commands_P, sizeof(cmd) - 1);
    cmd[sizeof(cmd) - 1] = '\0';
    // Look for the end of line, or the end of sequence
    size_t i = 0;
    char c;
    while((c = cmd[i]) && c != '\n') i++; // find the end of this gcode command
    cmd[i] = '\0';
    if (enqueuecommand(cmd)) {      // buffer was not full (else we will retry later)
        if (c)
            queued_commands_P += i + 1; // move to next command
        else
            queued_commands_P = NULL;   // will have no more commands in the sequence
    }
    return true;
}
#endif
#if defined (marlin4Due)
static bool drain_queued_commands_P() {
    if (!queued_commands_P) return false;
    // Get the next 30 chars from the sequence of gcodes to run
    char cmd[30];
    strncpy_P(cmd, queued_commands_P, sizeof(cmd) - 1);
    cmd[sizeof(cmd) - 1] = '\0';
    // Look for the end of line, or the end of sequence
    size_t i = 0;
    char c;
    while((c = cmd[i]) && c != '\n') i++; // find the end of this gcode command
    cmd[i] = '\0';
    if (enqueuecommand(cmd)) {      // buffer was not full (else we will retry later)
        if (c)
            queued_commands_P += i + 1; // move to next command
        else
            queued_commands_P = NULL;   // will have no more commands in the sequence
    }
    return true;
}
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    //thats really done in a non-safe way.
#endif
#if defined (marlin4Due)
    /**
    * Record one or many commands to run from program memory.
    * Aborts the current queue, if any.
    * Note: drain_queued_commands_P() must be called repeatedly to drain the commands afterwards
    */
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    //needs overworking someday
#endif
#if defined (marlin4Due)
void enqueuecommands_P(const char* pgcode) {
    queued_commands_P = pgcode;
    drain_queued_commands_P(); // first command executed asap (when possible)
}
#endif
#if defined (marlin4Due)
void enqueuecommands_P(const char* pgcode) {
    queued_commands_P = pgcode;
    drain_queued_commands_P(); // first command executed asap (when possible)
}
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)

void enquecommand(const char *cmd) {
    if(buflen < BUFSIZE) {
        //this is dangerous if a mixing of serial and this happens
        strcpy(&(cmdbuffer[bufindw][0]),cmd);
        SERIAL_ECHO_START;
        SERIAL_ECHOPGM(MSG_Enqueing);
        SERIAL_ECHO(cmdbuffer[bufindw]);
        SERIAL_ECHOLNPGM("\"");
        bufindw= (bufindw + 1)%BUFSIZE;
        buflen += 1;
    }
}
#endif
#if defined (marlin4Due)
    /**
    * Copy a command directly into the main command buffer, from RAM.
    *
    * This is done in a non-safe way and needs a rework someday.
    * Returns false if it doesn't add any command
    */
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)

void enquecommand_P(const char *cmd) {
    if(buflen < BUFSIZE) {
        //this is dangerous if a mixing of serial and this happens
        strcpy_P(&(cmdbuffer[bufindw][0]),cmd);
        SERIAL_ECHO_START;
        SERIAL_ECHOPGM(MSG_Enqueing);
        SERIAL_ECHO(cmdbuffer[bufindw]);
        SERIAL_ECHOLNPGM("\"");
        bufindw= (bufindw + 1)%BUFSIZE;
        buflen += 1;
    }
}
#endif
#if defined (marlin4Due)
bool enqueuecommand(const char *cmd) {
    if (*cmd == ';' || commands_in_queue >= BUFSIZE) return false;
    // This is dangerous if a mixing of serial and this happens
    char *command = command_queue[cmd_queue_index_w];
    strcpy(command, cmd);
    SERIAL_ECHO_START;
    SERIAL_ECHOPGM(MSG_Enqueueing);
    SERIAL_ECHO(command);
    SERIAL_ECHOLNPGM("\"");
    cmd_queue_index_w = (cmd_queue_index_w + 1) % BUFSIZE;
    commands_in_queue++;
    return true;
}
#endif
#if defined (oliv3r)
bool is_command_queued() {
    return buflen > 0;
}
uint8_t commands_queued() {
    return buflen;
}
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
void setup_killpin
() {
#if defined (bobc) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (indi-RichCattell) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (mattsch) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (quikshot) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (alromh87) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (akadamson) &&  KILL_PIN>-1 ) || defined (hampussandberg) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (drsdre) &&  KILL_PIN>-1 ) || defined (indi-3DR) &&  KILL_PIN>-1 ) || defined (gregor2005) &&  KILL_PIN>-1 ) || defined (johnnyr) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (ut7) && (defined(KILL_PIN) && KILL_PIN > -1)
    pinMode(KILL_PIN,INPUT);
#endif
#if defined (upstream) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (oliv3r) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (ErikZalm) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (oysteinkrog) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (yuroller) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (marlin4Due) && HAS_KILL
    SET_INPUT(KILL_PIN);
#endif
#if defined (upstream) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (bobc) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (indi-RichCattell) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (mattsch) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (oliv3r) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (quikshot) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (ErikZalm) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (alromh87) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (akadamson) &&  KILL_PIN>-1 ) || defined (hampussandberg) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (drsdre) &&  KILL_PIN>-1 ) || defined (indi-3DR) &&  KILL_PIN>-1 ) || defined (gregor2005) &&  KILL_PIN>-1 ) || defined (oysteinkrog) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (johnnyr) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (yuroller) && (defined(KILL_PIN) && KILL_PIN > -1) || defined (ut7) && (defined(KILL_PIN) && KILL_PIN > -1)
    WRITE(KILL_PIN,HIGH);
#endif
#if defined (marlin4Due) && HAS_KILL
    PULLUP(KILL_PIN, HIGH);
#endif
}
#endif
#if defined (marlin4Due)
void setup_filrunoutpin() {
#if HAS_FILRUNOUT
    SET_INPUT(FILRUNOUT_PIN);
#ifdef ENDSTOPPULLUP_FIL_RUNOUT
    PULLUP(FILRUNOUT_PIN, HIGH);
#endif
#endif
}
#endif
#if defined (upstream) || defined (ErikZalm) || defined (oysteinkrog) || defined (yuroller) || defined (marlin4Due)
// Set home pin

void setup_homepin(void) {
#if defined(HOME_PIN) && HOME_PIN > -1
    SET_INPUT(HOME_PIN);
    WRITE(HOME_PIN,HIGH);
#endif
}
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
void setup_photpin
() {
#if defined (upstream) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (bobc) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (indi-RichCattell) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (mattsch) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (oliv3r) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (quikshot) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (ErikZalm) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (alromh87) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (akadamson) && ((PHOTOGRAPH_PIN > -1) && defined (PHOTOGRAPH_PIN) ) || defined (hampussandberg) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (drsdre) && ((PHOTOGRAPH_PIN > -1) && defined (PHOTOGRAPH_PIN) ) || defined (indi-3DR) && ((PHOTOGRAPH_PIN > -1) && defined (PHOTOGRAPH_PIN) ) || defined (gregor2005) && ((PHOTOGRAPH_PIN > -1) && defined (PHOTOGRAPH_PIN) ) || defined (oysteinkrog) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (johnnyr) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (yuroller) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (ut7) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1)
    SET_OUTPUT(PHOTOGRAPH_PIN);
#endif
#if defined (marlin4Due) && HAS_PHOTOGRAPH
    OUT_WRITE(PHOTOGRAPH_PIN, LOW);
#endif
#if defined (upstream) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (bobc) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (indi-RichCattell) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (mattsch) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (oliv3r) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (quikshot) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (ErikZalm) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (alromh87) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (akadamson) && ((PHOTOGRAPH_PIN > -1) && defined (PHOTOGRAPH_PIN) ) || defined (hampussandberg) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (drsdre) && ((PHOTOGRAPH_PIN > -1) && defined (PHOTOGRAPH_PIN) ) || defined (indi-3DR) && ((PHOTOGRAPH_PIN > -1) && defined (PHOTOGRAPH_PIN) ) || defined (gregor2005) && ((PHOTOGRAPH_PIN > -1) && defined (PHOTOGRAPH_PIN) ) || defined (oysteinkrog) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (johnnyr) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (yuroller) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1) || defined (ut7) && (defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1)
    WRITE(PHOTOGRAPH_PIN, LOW);
#endif
}
void setup_powerhold
() {
#if defined (upstream) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (bobc) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (indi-RichCattell) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (mattsch) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (oliv3r) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (quikshot) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (ErikZalm) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (alromh87) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (akadamson) && (defined (SUICIDE_PIN) && (SUICIDE_PIN> -1) ) || defined (hampussandberg) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (drsdre) && (defined (SUICIDE_PIN) && (SUICIDE_PIN> -1) ) || defined (indi-3DR) && (defined (SUICIDE_PIN) && (SUICIDE_PIN> -1) ) || defined (gregor2005) && (defined (SUICIDE_PIN) && (SUICIDE_PIN> -1) ) || defined (oysteinkrog) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (johnnyr) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (yuroller) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (ut7) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1)
    SET_OUTPUT(SUICIDE_PIN);
#endif
#if defined (marlin4Due) && HAS_SUICIDE
    OUT_WRITE(SUICIDE_PIN, HIGH);
#endif
#if defined (upstream) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (bobc) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (indi-RichCattell) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (mattsch) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (oliv3r) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (quikshot) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (ErikZalm) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (alromh87) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (akadamson) && (defined (SUICIDE_PIN) && (SUICIDE_PIN> -1) ) || defined (hampussandberg) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (drsdre) && (defined (SUICIDE_PIN) && (SUICIDE_PIN> -1) ) || defined (indi-3DR) && (defined (SUICIDE_PIN) && (SUICIDE_PIN> -1) ) || defined (gregor2005) && (defined (SUICIDE_PIN) && (SUICIDE_PIN> -1) ) || defined (oysteinkrog) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (johnnyr) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (yuroller) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (ut7) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1)
    WRITE(SUICIDE_PIN, HIGH);
#endif
#if defined (marlin4Due) && (HAS_POWER_SWITCH && ENABLED(PS_DEFAULT_OFF) )
    OUT_WRITE(PS_ON_PIN, PS_ON_ASLEEP);
#endif
#if defined (upstream) && (defined(PS_ON_PIN) && PS_ON_PIN > -1) || defined (bobc) && (defined(PS_ON_PIN) && PS_ON_PIN > -1) || defined (indi-RichCattell) && (defined(PS_ON_PIN) && PS_ON_PIN > -1) || defined (mattsch) && (defined(PS_ON_PIN) && PS_ON_PIN > -1) || defined (oliv3r) && (defined(PS_ON_PIN) && PS_ON_PIN > -1) || defined (quikshot) && (defined(PS_ON_PIN) && PS_ON_PIN > -1) || defined (ErikZalm) && (defined(PS_ON_PIN) && PS_ON_PIN > -1) || defined (alromh87) && (defined(PS_ON_PIN) && PS_ON_PIN > -1) || defined (hampussandberg) && (defined(PS_ON_PIN) && PS_ON_PIN > -1) || defined (drsdre) && (PS_ON_PIN > -1) || defined (gregor2005) && (PS_ON_PIN > -1) || defined (oysteinkrog) && (defined(PS_ON_PIN) && PS_ON_PIN > -1) || defined (johnnyr) && (defined(PS_ON_PIN) && PS_ON_PIN > -1) || defined (yuroller) && (defined(PS_ON_PIN) && PS_ON_PIN > -1) || defined (ut7) && (defined(PS_ON_PIN) && PS_ON_PIN > -1)
    SET_OUTPUT(PS_ON_PIN);
#endif
#if defined (marlin4Due) && (HAS_POWER_SWITCH && !ENABLED(PS_DEFAULT_OFF) )
    OUT_WRITE(PS_ON_PIN, PS_ON_AWAKE);
#endif
#if defined (upstream) && (defined(PS_DEFAULT_OFF) && (defined(PS_ON_PIN) && PS_ON_PIN > -1 &) || defined (bobc) && (defined(PS_DEFAULT_OFF) && (defined(PS_ON_PIN) && PS_ON_PIN > -1 &) || defined (mattsch) && (defined(PS_DEFAULT_OFF) && (defined(PS_ON_PIN) && PS_ON_PIN > -1 &) || defined (quikshot) && (defined(PS_DEFAULT_OFF) && (defined(PS_ON_PIN) && PS_ON_PIN > -1 &) || defined (ErikZalm) && (defined(PS_DEFAULT_OFF) && (defined(PS_ON_PIN) && PS_ON_PIN > -1 &) || defined (alromh87) && (defined(PS_DEFAULT_OFF) && (defined(PS_ON_PIN) && PS_ON_PIN > -1 &) || defined (hampussandberg) && (defined(PS_DEFAULT_OFF) && (defined(PS_ON_PIN) && PS_ON_PIN > -1 &) || defined (oysteinkrog) && (defined(PS_DEFAULT_OFF) && (defined(PS_ON_PIN) && PS_ON_PIN > -1 &) || defined (johnnyr) && (defined(PS_DEFAULT_OFF) && (defined(PS_ON_PIN) && PS_ON_PIN > -1 &) || defined (yuroller) && (defined(PS_DEFAULT_OFF) && (defined(PS_ON_PIN) && PS_ON_PIN > -1 &) || defined (ut7) && (defined(PS_DEFAULT_OFF) && (defined(PS_ON_PIN) && PS_ON_PIN > -1 &)
    WRITE(PS_ON_PIN, PS_ON_ASLEEP);
#endif
#if defined (upstream) && ((defined(PS_ON_PIN) && PS_ON_PIN > -1 && )!defined(PS_DEFAULT_OFF) ) || defined (bobc) && ((defined(PS_ON_PIN) && PS_ON_PIN > -1 && )!defined(PS_DEFAULT_OFF) ) || defined (indi-RichCattell) && (defined(PS_ON_PIN) && PS_ON_PIN > -1) || defined (mattsch) && ((defined(PS_ON_PIN) && PS_ON_PIN > -1 && )!defined(PS_DEFAULT_OFF) ) || defined (oliv3r) && (defined(PS_ON_PIN) && PS_ON_PIN > -1) || defined (quikshot) && ((defined(PS_ON_PIN) && PS_ON_PIN > -1 && )!defined(PS_DEFAULT_OFF) ) || defined (ErikZalm) && ((defined(PS_ON_PIN) && PS_ON_PIN > -1 && )!defined(PS_DEFAULT_OFF) ) || defined (alromh87) && ((defined(PS_ON_PIN) && PS_ON_PIN > -1 && )!defined(PS_DEFAULT_OFF) ) || defined (hampussandberg) && ((defined(PS_ON_PIN) && PS_ON_PIN > -1 && )!defined(PS_DEFAULT_OFF) ) || defined (drsdre) && (PS_ON_PIN > -1) || defined (gregor2005) && (PS_ON_PIN > -1) || defined (oysteinkrog) && ((defined(PS_ON_PIN) && PS_ON_PIN > -1 && )!defined(PS_DEFAULT_OFF) ) || defined (johnnyr) && ((defined(PS_ON_PIN) && PS_ON_PIN > -1 && )!defined(PS_DEFAULT_OFF) ) || defined (yuroller) && ((defined(PS_ON_PIN) && PS_ON_PIN > -1 && )!defined(PS_DEFAULT_OFF) ) || defined (ut7) && ((defined(PS_ON_PIN) && PS_ON_PIN > -1 && )!defined(PS_DEFAULT_OFF) )
    WRITE(PS_ON_PIN, PS_ON_AWAKE);
#endif
}
void suicide
() {
#if defined (upstream) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (bobc) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (indi-RichCattell) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (mattsch) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (oliv3r) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (quikshot) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (ErikZalm) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (alromh87) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (akadamson) && (defined (SUICIDE_PIN) && (SUICIDE_PIN> -1) ) || defined (hampussandberg) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (drsdre) && (defined (SUICIDE_PIN) && (SUICIDE_PIN> -1) ) || defined (indi-3DR) && (defined (SUICIDE_PIN) && (SUICIDE_PIN> -1) ) || defined (gregor2005) && (defined (SUICIDE_PIN) && (SUICIDE_PIN> -1) ) || defined (oysteinkrog) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (johnnyr) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (yuroller) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (ut7) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1)
    SET_OUTPUT(SUICIDE_PIN);
#endif
#if defined (marlin4Due) && HAS_SUICIDE
    OUT_WRITE(SUICIDE_PIN, LOW);
#endif
#if defined (upstream) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (bobc) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (indi-RichCattell) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (mattsch) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (oliv3r) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (quikshot) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (ErikZalm) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (alromh87) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (akadamson) && (defined (SUICIDE_PIN) && (SUICIDE_PIN> -1) ) || defined (hampussandberg) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (drsdre) && (defined (SUICIDE_PIN) && (SUICIDE_PIN> -1) ) || defined (indi-3DR) && (defined (SUICIDE_PIN) && (SUICIDE_PIN> -1) ) || defined (gregor2005) && (defined (SUICIDE_PIN) && (SUICIDE_PIN> -1) ) || defined (oysteinkrog) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (johnnyr) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (yuroller) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1) || defined (ut7) && (defined(SUICIDE_PIN) && SUICIDE_PIN > -1)
    WRITE(SUICIDE_PIN, LOW);
#endif
}
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (hampussandberg) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)

void servo_init() {
#if (NUM_SERVOS >= 1) && defined(SERVO0_PIN) && (SERVO0_PIN > -1)
    servos[0].attach(SERVO0_PIN);
#endif
#if (NUM_SERVOS >= 2) && defined(SERVO1_PIN) && (SERVO1_PIN > -1)
    servos[1].attach(SERVO1_PIN);
#endif
#if (NUM_SERVOS >= 3) && defined(SERVO2_PIN) && (SERVO2_PIN > -1)
    servos[2].attach(SERVO2_PIN);
#endif
#if (NUM_SERVOS >= 4) && defined(SERVO3_PIN) && (SERVO3_PIN > -1)
    servos[3].attach(SERVO3_PIN);
#endif
#if (NUM_SERVOS >= 5)
#error "TODO: enter initalisation code for more servos"
#endif
    // Set position of Servo Endstops that are defined
#ifdef SERVO_ENDSTOPS
    for(int8_t i = 0; i < 3; i++) {
        if(servo_endstops[i] > -1) {
            servos[servo_endstops[i]].write(servo_endstop_angles[i * 2 + 1]);
        }
    }
#endif
#if defined (ENABLE_AUTO_BED_LEVELING) && (PROBE_SERVO_DEACTIVATION_DELAY > 0)
    delay(PROBE_SERVO_DEACTIVATION_DELAY);
    servos[servo_endstops[Z_AXIS]].detach();
#endif
}
#endif
#if defined (marlin4Due)
    /**
    * Stepper Reset (RigidBoard, et.al.)
    */
#endif
#if defined (marlin4Due) && HAS_STEPPER_RESET
void disableStepperDrivers() {
    pinMode(STEPPER_RESET_PIN, OUTPUT);
    digitalWrite(STEPPER_RESET_PIN, LOW);  // drive it down to hold in reset motor driver chips
}
void enableStepperDrivers() {
    pinMode(STEPPER_RESET_PIN, INPUT);
}
// set to input, which allows it to be pulled high by pullups
#endif
#if defined (marlin4Due)
    /**
    * Marlin entry-point: Set up before the program loop
    *  - Set up the kill pin, filament runout, power hold
    *  - Start the serial port
    *  - Print startup messages and diagnostics
    *  - Get EEPROM or default settings
    *  - Initialize managers for:
    *    â¢ temperature
    *    â¢ planner
    *    â¢ watchdog
    *    â¢ stepper
    *    â¢ photo pin
    *    â¢ servos
    *    â¢ LCD controller
    *    â¢ Digipot I2C
    *    â¢ Z probe sled
    *    â¢ status LEDs
    */
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
void setup
() {
    setup_killpin();
#if defined (marlin4Due)
    setup_filrunoutpin();
#endif
    setup_powerhold();
#if defined (marlin4Due) && HAS_STEPPER_RESET
    disableStepperDrivers();
#endif
    MYSERIAL.begin(BAUDRATE);
    SERIAL_PROTOCOLLNPGM("start");
    SERIAL_ECHO_START;
// Check startup - does nothing if bootloader sets MCUSR to 0
    byte mcu = MCUSR;
    if
    (mcu & 1)
        SERIAL_ECHOLNPGM(MSG_POWERUP);
    if
    (mcu & 2)
        SERIAL_ECHOLNPGM(MSG_EXTERNAL_RESET);
    if
    (mcu & 4)
        SERIAL_ECHOLNPGM(MSG_BROWNOUT_RESET);
    if
    (mcu & 8)
        SERIAL_ECHOLNPGM(MSG_WATCHDOG_RESET);
    if
    (mcu & 32)
        SERIAL_ECHOLNPGM(MSG_SOFTWARE_RESET);
    MCUSR=0;
    SERIAL_ECHOPGM(MSG_MARLIN);
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    SERIAL_ECHOLNPGM(VERSION_STRING);
#endif
#if defined (marlin4Due)
    SERIAL_ECHOLNPGM(" " BUILD_VERSION);
#endif
#if defined (upstream) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (bobc) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (indi-RichCattell) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (mattsch) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (oliv3r) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (quikshot) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (ErikZalm) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (alromh87) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (akadamson) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (hampussandberg) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (drsdre) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (indi-3DR) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (gregor2005) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (oysteinkrog) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (johnnyr) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (yuroller) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (ut7) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (marlin4Due) && (defined (STRING_DISTRIBUTION_DATE) && defined (STRING_CONFIG_H_AUTHOR) )
    SERIAL_ECHO_START;
    SERIAL_ECHOPGM(MSG_CONFIGURATION_VER);
#endif
#if defined (upstream) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (bobc) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (indi-RichCattell) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (mattsch) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (oliv3r) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (quikshot) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (ErikZalm) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (alromh87) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (akadamson) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (hampussandberg) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (drsdre) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (indi-3DR) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (gregor2005) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (oysteinkrog) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (johnnyr) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (yuroller) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (ut7) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) )
    SERIAL_ECHOPGM(STRING_VERSION_CONFIG_H);
#endif
#if defined (marlin4Due) && (defined (STRING_DISTRIBUTION_DATE) && defined (STRING_CONFIG_H_AUTHOR) )
    SERIAL_ECHOPGM(STRING_DISTRIBUTION_DATE);
#endif
#if defined (upstream) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (bobc) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (indi-RichCattell) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (mattsch) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (oliv3r) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (quikshot) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (ErikZalm) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (alromh87) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (akadamson) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (hampussandberg) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (drsdre) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (indi-3DR) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (gregor2005) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (oysteinkrog) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (johnnyr) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (yuroller) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (ut7) && (defined (STRING_CONFIG_H_AUTHOR) && defined (STRING_VERSION_CONFIG_H) ) || defined (marlin4Due) && (defined (STRING_DISTRIBUTION_DATE) && defined (STRING_CONFIG_H_AUTHOR) )
    SERIAL_ECHOPGM(MSG_AUTHOR);
    SERIAL_ECHOLNPGM(STRING_CONFIG_H_AUTHOR);
    SERIAL_ECHOPGM("Compiled: ");
    SERIAL_ECHOLNPGM(__DATE__);
#endif
#if defined (marlin4Due) && defined (STRING_DISTRIBUTION_DATE)
// STRING_CONFIG_H_AUTHOR
#endif
#if defined (marlin4Due)
// STRING_DISTRIBUTION_DATE
#endif
    SERIAL_ECHO_START;
    SERIAL_ECHOPGM(MSG_FREE_MEMORY);
    SERIAL_ECHO(freeMemory());
    SERIAL_ECHOPGM(MSG_PLANNER_BUFFER_BYTES);
    SERIAL_ECHOLN((int)sizeof(block_t)*BLOCK_BUFFER_SIZE);
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due) && ENABLED(SDSUPPORT)
    for(int8_t i = 0; i < BUFSIZE; i++) {
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
        fromsd[i] = false;
#endif
#if defined (marlin4Due) && ENABLED(SDSUPPORT)fromsd[i] = false;
#endif
    }
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (hampussandberg) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
// loads data from EEPROM if available else uses defaults (and resets step acceleration rate)
#endif
    Config_RetrieveSettings();
#if defined (oliv3r)
    lifetime_stats_init();
#endif
#if defined (akadamson) || defined (drsdre) || defined (indi-3DR)
// loads data from EEPROM if available
#endif
#if defined (marlin4Due)
    lcd_init();
#endif
#if defined (akadamson) || defined (drsdre) || defined (indi-3DR)
    for(int8_t i=0; i < NUM_AXIS; i++) {
        axis_steps_per_sqr_second[i] = max_acceleration_units_per_sq_second[i] * axis_steps_per_unit[i];
    }
#endif
#if defined (marlin4Due)
    _delay_ms(1000);
// wait 1sec to display the splash screen
#endif
    tp_init();
// Initialize temperature loop
    plan_init();
// Initialize planner;
    watchdog_init();
    st_init();
// Initialize stepper, this enables interrupts!
    setup_photpin();
#if defined (akadamson)
    LCD_INIT;
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (hampussandberg) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
    servo_init();
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    lcd_init();
#endif
#if defined (marlin4Due)
    init_fsr_values();
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (hampussandberg) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    _delay_ms(1000);
// wait 1sec to display the splash screen
#endif
#if defined (upstream) && (defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1) || defined (bobc) && (defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1) || defined (indi-RichCattell) && (defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1) || defined (mattsch) && (defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1) || defined (oliv3r) && (defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1) || defined (quikshot) && (defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1) || defined (ErikZalm) && (defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1) || defined (alromh87) && (defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1) || defined (hampussandberg) && (defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1) || defined (gregor2005) && defined (CONTROLLERFAN_PIN) || defined (oysteinkrog) && (defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1) || defined (johnnyr) && (defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1) || defined (yuroller) && (defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1) || defined (ut7) && (defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1) || defined (marlin4Due) && HAS_CONTROLLERFAN
    SET_OUTPUT(CONTROLLERFAN_PIN);
//Set pin used for driver cooling fan
#endif
#if defined (marlin4Due) && HAS_STEPPER_RESET
    enableStepperDrivers();
#endif
#if defined (gregor2005) && defined (EXTRUDERFAN_PIN)
    SET_OUTPUT(EXTRUDERFAN_PIN);
#endif
#if defined (upstream) && defined (DIGIPOT_I2C) || defined (bobc) && defined (DIGIPOT_I2C) || defined (mattsch) && defined (DIGIPOT_I2C) || defined (quikshot) && defined (DIGIPOT_I2C) || defined (ErikZalm) && defined (DIGIPOT_I2C) || defined (alromh87) && defined (DIGIPOT_I2C) || defined (hampussandberg) && defined (DIGIPOT_I2C) || defined (oysteinkrog) && defined (DIGIPOT_I2C) || defined (johnnyr) && defined (DIGIPOT_I2C) || defined (yuroller) && defined (DIGIPOT_I2C) || defined (ut7) && defined (DIGIPOT_I2C) || defined (marlin4Due) && ENABLED(DIGIPOT_I2C)
    digipot_i2c_init();
#endif
#if defined (gregor2005) && defined (EXTRUDERFAN_PIN)
//Set pin used for extruder cooling fan
#endif
#if defined (upstream) && defined (Z_PROBE_SLED) || defined (mattsch) && defined (Z_PROBE_SLED) || defined (ErikZalm) && defined (Z_PROBE_SLED) || defined (hampussandberg) && defined (Z_PROBE_SLED) || defined (oysteinkrog) && defined (Z_PROBE_SLED) || defined (yuroller) && defined (Z_PROBE_SLED) || defined (ut7) && defined (Z_PROBE_SLED)
    pinMode(SERVO0_PIN, OUTPUT);
#endif
#if defined (marlin4Due) && ENABLED(Z_PROBE_SLED)
    pinMode(SLED_PIN, OUTPUT);
#endif
#if defined (upstream) && defined (Z_PROBE_SLED) || defined (mattsch) && defined (Z_PROBE_SLED) || defined (ErikZalm) && defined (Z_PROBE_SLED) || defined (hampussandberg) && defined (Z_PROBE_SLED) || defined (oysteinkrog) && defined (Z_PROBE_SLED) || defined (yuroller) && defined (Z_PROBE_SLED) || defined (ut7) && defined (Z_PROBE_SLED)
    digitalWrite(SERVO0_PIN, LOW);
#endif
#if defined (marlin4Due) && ENABLED(Z_PROBE_SLED)
    digitalWrite(SLED_PIN, LOW);
#endif
#if defined (upstream) && defined (Z_PROBE_SLED) || defined (mattsch) && defined (Z_PROBE_SLED) || defined (ErikZalm) && defined (Z_PROBE_SLED) || defined (hampussandberg) && defined (Z_PROBE_SLED) || defined (oysteinkrog) && defined (Z_PROBE_SLED) || defined (yuroller) && defined (Z_PROBE_SLED) || defined (ut7) && defined (Z_PROBE_SLED) || defined (marlin4Due) && ENABLED(Z_PROBE_SLED)
// turn it off
#endif
#if defined (upstream) || defined (mattsch) || defined (ErikZalm) || defined (hampussandberg) || defined (oysteinkrog) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
// Z_PROBE_SLED
#endif
#if defined (upstream) || defined (ErikZalm) || defined (oysteinkrog) || defined (yuroller) || defined (marlin4Due)
    setup_homepin();
#endif
#if defined (marlin4Due) && defined (STAT_LED_RED)
    pinMode(STAT_LED_RED, OUTPUT);
    digitalWrite(STAT_LED_RED, LOW);
// turn it off
#endif
#if defined (marlin4Due) && defined (STAT_LED_BLUE)
    pinMode(STAT_LED_BLUE, OUTPUT);
    digitalWrite(STAT_LED_BLUE, LOW);
// turn it off
#endif
}
#endif
#if defined (marlin4Due)
    /**
    * The main Marlin program loop
    *
    *  - Save or log commands to SD
    *  - Process available commands (if not saving)
    *  - Call heater manager
    *  - Call inactivity manager
    *  - Call endstop manager
    *  - Call LCD update
    */
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
void loop
() {
    if
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    (buflen < (BUFSIZE-1))
#endif
#if defined (marlin4Due)
        (commands_in_queue < BUFSIZE - 1)
#endif
        get_command();
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (indi-3DR) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && ENABLED(SDSUPPORT)
    card.checkautostart(false);
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    if(buflen) {
#ifdef SDSUPPORT
        if(card.saving) {
            if(strstr_P(cmdbuffer[bufindr], PSTR("M29")) == NULL) {
                card.write_command(cmdbuffer[bufindr]);
                if(card.logging) {
                    process_commands();
                } else {
                    SERIAL_PROTOCOLLNPGM(MSG_OK);
                }
            } else {
                card.closefile();
                SERIAL_PROTOCOLLNPGM(MSG_FILE_SAVED);
            }
        } else {
            process_commands();
        }
#else
        process_commands();
#endif //SDSUPPORT
        buflen = (buflen-1);
        bufindr = (bufindr + 1)%BUFSIZE;
    }
#endif
#if defined (marlin4Due)
    if (commands_in_queue) {
#if ENABLED(SDSUPPORT)
        if (card.saving) {
            char *command = command_queue[cmd_queue_index_r];
            if (strstr_P(command, PSTR("M29"))) {
                // M29 closes the file
                card.closefile();
                SERIAL_PROTOCOLLNPGM(MSG_FILE_SAVED);
            } else {
                // Write the string from the read buffer to SD
                card.write_command(command);
                if (card.logging)
                    process_next_command(); // The card is saving because it's logging
                else
                    SERIAL_PROTOCOLLNPGM(MSG_OK);
            }
        } else
            process_next_command();
#else
        process_next_command();
#endif // SDSUPPORT
        commands_in_queue--;
        cmd_queue_index_r = (cmd_queue_index_r + 1) % BUFSIZE;
    }
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
//check heater every n milliseconds
    manage_heater();
    manage_inactivity();
#endif
    checkHitEndstops();
#if defined (akadamson)
    LCD_STATUS;
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    lcd_update();
#endif
#if defined (marlin4Due)
    idle();
#endif
#if defined (oliv3r)
    lifetime_stats_tick();
#endif
}
#endif
#if defined (marlin4Due)
void gcode_line_error(const char *err, bool doFlush=true) {
    SERIAL_ERROR_START;
    serialprintPGM(err);
    SERIAL_ERRORLN(gcode_LastN);
    //Serial.println(gcode_N);
    if (doFlush) FlushSerialRequestResend();
    serial_count = 0;
}
/**
 * Add to the circular command queue the next command from:
 *  - The command-injection queue (queued_commands_P)
 *  - The active serial input (usually USB)
 *  - The SD card file being actively printed
 */
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
void get_command
() {
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    while( MYSERIAL.available() > 0  && buflen < BUFSIZE) {
        serial_char = MYSERIAL.read();
        if(serial_char == '\n' ||
                serial_char == '\r' ||
                (serial_char == ':' && comment_mode == false) ||
                serial_count >= (MAX_CMD_SIZE - 1) ) {
            if(!serial_count) { //if empty line
                comment_mode = false; //for new command
                return;
            }
            cmdbuffer[bufindw][serial_count] = 0; //terminate string
            if(!comment_mode) {
                comment_mode = false; //for new command
                fromsd[bufindw] = false;
                if(strchr(cmdbuffer[bufindw], 'N') != NULL) {
                    strchr_pointer = strchr(cmdbuffer[bufindw], 'N');
                    gcode_N = (strtol(&cmdbuffer[bufindw][strchr_pointer - cmdbuffer[bufindw] + 1], NULL, 10));
                    if(gcode_N != gcode_LastN+1 && (strstr_P(cmdbuffer[bufindw], PSTR("M110")) == NULL) ) {
                        SERIAL_ERROR_START;
                        SERIAL_ERRORPGM(MSG_ERR_LINE_NO);
                        SERIAL_ERRORLN(gcode_LastN);
                        //Serial.println(gcode_N);
                        FlushSerialRequestResend();
                        serial_count = 0;
                        return;
                    }
                    if(strchr(cmdbuffer[bufindw], '*') != NULL) {
                        byte checksum = 0;
                        byte count = 0;
                        while(cmdbuffer[bufindw][count] != '*') checksum = checksum^cmdbuffer[bufindw][count++];
                        strchr_pointer = strchr(cmdbuffer[bufindw], '*');
                        if( (int)(strtod(&cmdbuffer[bufindw][strchr_pointer - cmdbuffer[bufindw] + 1], NULL)) != checksum) {
                            SERIAL_ERROR_START;
                            SERIAL_ERRORPGM(MSG_ERR_CHECKSUM_MISMATCH);
                            SERIAL_ERRORLN(gcode_LastN);
                            FlushSerialRequestResend();
                            serial_count = 0;
                            return;
                        }
                        //if no errors, continue parsing
                    } else {
                        SERIAL_ERROR_START;
                        SERIAL_ERRORPGM(MSG_ERR_NO_CHECKSUM);
                        SERIAL_ERRORLN(gcode_LastN);
                        FlushSerialRequestResend();
                        serial_count = 0;
                        return;
                    }
                    gcode_LastN = gcode_N;
                    //if no errors, continue parsing
                } else { // if we don't receive 'N' but still see '*'
                    if((strchr(cmdbuffer[bufindw], '*') != NULL)) {
                        SERIAL_ERROR_START;
                        SERIAL_ERRORPGM(MSG_ERR_NO_LINENUMBER_WITH_CHECKSUM);
                        SERIAL_ERRORLN(gcode_LastN);
                        serial_count = 0;
                        return;
                    }
                }
                if((strchr(cmdbuffer[bufindw], 'G') != NULL)) {
                    strchr_pointer = strchr(cmdbuffer[bufindw], 'G');
                    switch((int)((strtod(&cmdbuffer[bufindw][strchr_pointer - cmdbuffer[bufindw] + 1], NULL)))) {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                        if (Stopped == true) {
                            SERIAL_ERRORLNPGM(MSG_ERR_STOPPED);
                            LCD_MESSAGEPGM(MSG_STOPPED);
                        }
                        break;
                    default:
                        break;
                    }
                }
                //If command was e-stop process now
                if(strcmp(cmdbuffer[bufindw], "M112") == 0)
                    kill();
                bufindw = (bufindw + 1)%BUFSIZE;
                buflen += 1;
            }
            serial_count = 0; //clear buffer
        } else {
            if(serial_char == ';') comment_mode = true;
            if(!comment_mode) cmdbuffer[bufindw][serial_count++] = serial_char;
        }
    }
#endif
#if defined (marlin4Due)
    if (drain_queued_commands_P()) return;
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (indi-3DR) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
    if(!card.sdprinting || serial_count!=0) {
        return;
    }
#endif
#if defined (marlin4Due)
// priority is given to non-serial commands
#endif
#if defined (oliv3r) && defined (SDSUPPORT)
    if (card.pause) {
        return;
    }
#endif
#if defined (marlin4Due) && ENABLED(NO_TIMEOUTS)
    static millis_t last_command_time = 0;
#endif
#if defined (oliv3r) && defined (SDSUPPORT)
    static uint32_t endOfLineFilePosition = 0;
#endif
#if defined (marlin4Due) && ENABLED(NO_TIMEOUTS)
    millis_t ms = millis();
    if (!MYSERIAL.available() && commands_in_queue == 0 && ms - last_command_time > NO_TIMEOUTS) {
        SERIAL_ECHOLNPGM(MSG_WAIT);
        last_command_time = ms;
    }
#endif
#if defined (marlin4Due)
//
// Loop while serial characters are incoming and the queue is not full
//
    while (commands_in_queue < BUFSIZE && MYSERIAL.available() > 0) {
#if ENABLED(NO_TIMEOUTS)
        last_command_time = ms;
#endif
        serial_char = MYSERIAL.read();
        //
        // If the character ends the line, or the line is full...
        //
        if (serial_char == '\n' || serial_char == '\r' || serial_count >= MAX_CMD_SIZE-1) {
            // end of line == end of comment
            comment_mode = false;
            if (!serial_count) return; // empty lines just exit
            char *command = command_queue[cmd_queue_index_w];
            command[serial_count] = 0; // terminate string
            // this item in the queue is not from sd
#if ENABLED(SDSUPPORT)
            fromsd[cmd_queue_index_w] = false;
#endif
            char *npos = strchr(command, 'N');
            char *apos = strchr(command, '*');
            if (npos) {
                boolean M110 = strstr_P(command, PSTR("M110")) != NULL;
                if (M110) {
                    char *n2pos = strchr(command + 4, 'N');
                    if (n2pos) npos = n2pos;
                }
                gcode_N = strtol(npos + 1, NULL, 10);
                if (gcode_N != gcode_LastN + 1 && !M110) {
                    gcode_line_error(PSTR(MSG_ERR_LINE_NO));
                    return;
                }
                if (apos) {
                    byte checksum = 0, count = 0;
                    while (command[count] != '*') checksum ^= command[count++];
                    if (strtol(apos + 1, NULL, 10) != checksum) {
                        gcode_line_error(PSTR(MSG_ERR_CHECKSUM_MISMATCH));
                        return;
                    }
                    // if no errors, continue parsing
                } else if (npos == command) {
                    gcode_line_error(PSTR(MSG_ERR_NO_CHECKSUM));
                    return;
                }
                gcode_LastN = gcode_N;
                // if no errors, continue parsing
            } else if (apos) { // No '*' without 'N'
                gcode_line_error(PSTR(MSG_ERR_NO_LINENUMBER_WITH_CHECKSUM), false);
                return;
            }
            // Movement commands alert when stopped
            if (IsStopped()) {
                char *gpos = strchr(command, 'G');
                if (gpos) {
                    int codenum = strtol(gpos + 1, NULL, 10);
                    switch (codenum) {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                        SERIAL_ERRORLNPGM(MSG_ERR_STOPPED);
                        LCD_MESSAGEPGM(MSG_STOPPED);
                        break;
                    }
                }
            }
            // If command was e-stop process now
            if (strcmp(command, "M112") == 0) kill(PSTR(MSG_KILLED));
            cmd_queue_index_w = (cmd_queue_index_w + 1) % BUFSIZE;
            commands_in_queue += 1;
            serial_count = 0; //clear buffer
        } else if (serial_char == '\\') { // Handle escapes
            if (MYSERIAL.available() > 0 && commands_in_queue < BUFSIZE) {
                // if we have one more character, copy it over
                serial_char = MYSERIAL.read();
                command_queue[cmd_queue_index_w][serial_count++] = serial_char;
            }
            // otherwise do nothing
        } else { // its not a newline, carriage return or escape char
            if (serial_char == ';') comment_mode = true;
            if (!comment_mode) command_queue[cmd_queue_index_w][serial_count++] = serial_char;
        }
    }
#endif
#if defined (marlin4Due) && ENABLED(SDSUPPORT)
    if (!card.sdprinting || serial_count) return;
#endif
#if defined (indi-RichCattell) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (indi-3DR) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT)
    while( !card.eof()  && buflen < BUFSIZE) {
        int16_t n=card.get();
        serial_char = (char)n;
        if(serial_char == '\n' ||
                serial_char == '\r' ||
                (serial_char == ':' && comment_mode == false) ||
                serial_count >= (MAX_CMD_SIZE - 1)||n==-1) {
            if(card.eof()) {
                SERIAL_PROTOCOLLNPGM(MSG_FILE_PRINTED);
                stoptime=millis();
                char time[30];
                unsigned long t=(stoptime-starttime)/1000;
                int hours, minutes;
                minutes=(t/60)%60;
                hours=t/60/60;
                sprintf_P(time, PSTR("%i hours %i minutes"),hours, minutes);
                SERIAL_ECHO_START;
                SERIAL_ECHOLN(time);
                lcd_setstatus(time);
                card.printingHasFinished();
                card.checkautostart(true);
            }
            if(!serial_count) {
                comment_mode = false; //for new command
                return; //if empty line
            }
            cmdbuffer[bufindw][serial_count] = 0; //terminate string
//      if(!comment_mode){
            fromsd[bufindw] = true;
            buflen += 1;
            bufindw = (bufindw + 1)%BUFSIZE;
//      }
            comment_mode = false; //for new command
            serial_count = 0; //clear buffer
        } else {
            if(serial_char == ';') comment_mode = true;
            if(!comment_mode) cmdbuffer[bufindw][serial_count++] = serial_char;
        }
    }
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && ENABLED(SDSUPPORT)
//'#' stops reading from SD to the buffer prematurely, so procedural macro calls are possible
// if it occurs, stop_buffering is triggered and the buffer is ran dry.
// this character _can_ occur in serial com, due to checksums. however, no checksums are used in SD printing
    static bool stop_buffering=false;
    if(buflen==0) stop_buffering=false;
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
    while( !card.eof()  && buflen < BUFSIZE && !stop_buffering) {
        int16_t n=card.get();
        serial_char = (char)n;
        if(serial_char == '\n' ||
                serial_char == '\r' ||
                (serial_char == '#' && comment_mode == false) ||
                (serial_char == ':' && comment_mode == false) ||
                serial_count >= (MAX_CMD_SIZE - 1)||n==-1) {
            if(card.eof()) {
                SERIAL_PROTOCOLLNPGM(MSG_FILE_PRINTED);
                stoptime=millis();
                char time[30];
                unsigned long t=(stoptime-starttime)/1000;
                int hours, minutes;
                minutes=(t/60)%60;
                hours=t/60/60;
                sprintf_P(time, PSTR("%i hours %i minutes"),hours, minutes);
                SERIAL_ECHO_START;
                SERIAL_ECHOLN(time);
                lcd_setstatus(time);
                card.printingHasFinished();
                card.checkautostart(true);
            }
            if(serial_char=='#')
                stop_buffering=true;
            if(!serial_count) {
                comment_mode = false; //for new command
                return; //if empty line
            }
            cmdbuffer[bufindw][serial_count] = 0; //terminate string
//      if(!comment_mode){
            fromsd[bufindw] = true;
            buflen += 1;
            bufindw = (bufindw + 1)%BUFSIZE;
//      }
            comment_mode = false; //for new command
            serial_count = 0; //clear buffer
        } else {
            if(serial_char == ';') comment_mode = true;
            if(!comment_mode) cmdbuffer[bufindw][serial_count++] = serial_char;
        }
    }
#endif
#if defined (marlin4Due) && ENABLED(SDSUPPORT)
    while (!card.eof() && commands_in_queue < BUFSIZE && !stop_buffering) {
        int16_t n = card.get();
        serial_char = (char)n;
        if (serial_char == '\n' || serial_char == '\r' ||
                ((serial_char == '#' || serial_char == ':') && !comment_mode) ||
                serial_count >= (MAX_CMD_SIZE - 1) || n == -1
           ) {
            if (card.eof()) {
                SERIAL_PROTOCOLLNPGM(MSG_FILE_PRINTED);
                print_job_stop_ms = millis();
                char time[30];
                millis_t t = (print_job_stop_ms - print_job_start_ms) / 1000;
                int hours = t / 60 / 60, minutes = (t / 60) % 60;
                sprintf_P(time, PSTR("%i " MSG_END_HOUR " %i " MSG_END_MINUTE), hours, minutes);
                SERIAL_ECHO_START;
                SERIAL_ECHOLN(time);
                lcd_setstatus(time, true);
                card.printingHasFinished();
                card.checkautostart(true);
            }
            if (serial_char == '#') stop_buffering = true;
            if (!serial_count) {
                comment_mode = false; //for new command
                return; //if empty line
            }
            command_queue[cmd_queue_index_w][serial_count] = 0; //terminate string
            // if (!comment_mode) {
            fromsd[cmd_queue_index_w] = true;
            commands_in_queue += 1;
            cmd_queue_index_w = (cmd_queue_index_w + 1) % BUFSIZE;
            // }
            comment_mode = false; //for new command
            serial_count = 0; //clear buffer
        } else {
            if (serial_char == ';') comment_mode = true;
            if (!comment_mode) command_queue[cmd_queue_index_w][serial_count++] = serial_char;
        }
    }
#endif
//SDSUPPORT
}
#endif
#if defined (marlin4Due)
bool code_has_value() {
    int i = 1;
    char c = seen_pointer[i];
    if (c == '-' || c == '+') c = seen_pointer[++i];
    if (c == '.') c = seen_pointer[++i];
    return (c >= '0' && c <= '9');
}
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
float code_value
() {
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    return (strtod(&cmdbuffer[bufindr][strchr_pointer - cmdbuffer[bufindr] + 1], NULL));
#endif
#if defined (marlin4Due)
    float ret;
    char *e = strchr(seen_pointer, 'E');
    if (e) {
        *e = 0;
        ret = strtod(seen_pointer+1, NULL);
        *e = 'E';
    } else
        ret = strtod(seen_pointer+1, NULL);
    return ret;
#endif
}
long code_value_long
() {
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    return (strtol(&cmdbuffer[bufindr][strchr_pointer - cmdbuffer[bufindr] + 1], NULL, 10));
#endif
#if defined (marlin4Due)
    return strtol(seen_pointer + 1, NULL, 10);
#endif
}
#endif
#if defined (marlin4Due)
int16_t code_value_short() {
    return (int16_t)strtol(seen_pointer + 1, NULL, 10);
}
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
bool code_seen
(char code) {
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    strchr_pointer = strchr(cmdbuffer[bufindr], code);
#endif
#if defined (marlin4Due)
    seen_pointer = strchr(current_command_args, code);
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    return (strchr_pointer != NULL);
#endif
#if defined (marlin4Due)
    return (seen_pointer != NULL);
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
//Return True if a character was found
#endif
#if defined (marlin4Due)
// Return TRUE if the code-letter was found
#endif
}
#define DEFINE_PGM_READ_ANY(type, reader)       \
    static inline type pgm_read_any(const type *p)  \
    { return pgm_read_##reader##_near(p); }
DEFINE_PGM_READ_ANY(float,       float);
;
#define XYZ_CONSTS_FROM_CONFIG(type, array, CONFIG) \
static const PROGMEM type array##_P[3] =        \
    { X_##CONFIG, Y_##CONFIG, Z_##CONFIG };     \
static inline type array(int axis)          \
    { return pgm_read_any(&array##_P[axis]); }
XYZ_CONSTS_FROM_CONFIG(float, base_min_pos,    MIN_POS);
#endif
#if defined (indi-RichCattell)
    //XYZ_CONSTS_FROM_CONFIG(float, base_max_pos,    MAX_POS);
#endif
#if defined (upstream) || defined (bobc)
    XYZ_CONSTS_FROM_CONFIG(float, base_max_pos,    MAX_POS);
#endif
#if defined (indi-RichCattell)
    //XYZ_CONSTS_FROM_CONFIG(float, base_home_pos,   HOME_POS);
#endif
#if defined (upstream) || defined (bobc)
    XYZ_CONSTS_FROM_CONFIG(float, base_home_pos,   HOME_POS);
#endif
#if defined (indi-RichCattell)
    //XYZ_CONSTS_FROM_CONFIG(float, max_length,      MAX_LENGTH);
#endif
#if defined (upstream) || defined (bobc)
    XYZ_CONSTS_FROM_CONFIG(float, max_length,      MAX_LENGTH);
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    XYZ_CONSTS_FROM_CONFIG(float, home_retract_mm, HOME_RETRACT_MM);
#endif
#if defined (marlin4Due)
    XYZ_CONSTS_FROM_CONFIG(float, home_bump_mm,   HOME_BUMP_MM);
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
    ;
#endif
#if defined (upstream) && (defined (DUAL_X_CARRIAGE) && (EXTRUDERS == 1 || defined(COREXY) \
      || !defined(X2_ENABLE_PIN) || !defined(X2_STEP_PIN) || !defined(X2_DIR_PIN) \
      || !defined(X2_HOME_POS) || !defined(X2_MIN_POS) || !defined(X2_MAX_POS) \
      || !defined(X_MAX_PIN) || X_MAX_PIN < 0 &) || defined (bobc) && (defined (DUAL_X_CARRIAGE) && (EXTRUDERS == 1 || defined(COREXY) \
      || !defined(X2_ENABLE_PIN) || !defined(X2_STEP_PIN) || !defined(X2_DIR_PIN) \
      || !defined(X2_HOME_POS) || !defined(X2_MIN_POS) || !defined(X2_MAX_POS) \
      || !defined(X_MAX_PIN) || X_MAX_PIN < 0 &) || defined (indi-RichCattell) && (defined (DUAL_X_CARRIAGE) && (EXTRUDERS == 1 || defined(COREXY) \
      || !defined(X2_ENABLE_PIN) || !defined(X2_STEP_PIN) || !defined(X2_DIR_PIN) \
      || !defined(X2_HOME_POS) || !defined(X2_MIN_POS) || !defined(X2_MAX_POS) \
      || !defined(X_MAX_PIN) || X_MAX_PIN < 0 &) || defined (mattsch) && (defined (DUAL_X_CARRIAGE) && (EXTRUDERS == 1 || defined(COREXY) \
      || !defined(X2_ENABLE_PIN) || !defined(X2_STEP_PIN) || !defined(X2_DIR_PIN) \
      || !defined(X2_HOME_POS) || !defined(X2_MIN_POS) || !defined(X2_MAX_POS) \
      || !defined(X_MAX_PIN) || X_MAX_PIN < 0 &)
#error "Missing or invalid definitions for DUAL_X_CARRIAGE mode."
#endif
#if defined (upstream) && (defined (DUAL_X_CARRIAGE) && (X_HOME_DIR != -1 || X2_HOME_DIR != 1 &) || defined (bobc) && (defined (DUAL_X_CARRIAGE) && (X_HOME_DIR != -1 || X2_HOME_DIR != 1 &) || defined (indi-RichCattell) && (defined (DUAL_X_CARRIAGE) && (X_HOME_DIR != -1 || X2_HOME_DIR != 1 &) || defined (mattsch) && (defined (DUAL_X_CARRIAGE) && (X_HOME_DIR != -1 || X2_HOME_DIR != 1 &)
    #error "Please use canonical x-carriage assignment"
    // the x-carriages are defined by their homing directions
#endif
#if defined (upstream) && defined (DUAL_X_CARRIAGE) || defined (bobc) && defined (DUAL_X_CARRIAGE) || defined (indi-RichCattell) && defined (DUAL_X_CARRIAGE) || defined (mattsch) && defined (DUAL_X_CARRIAGE)
    #define DXC_FULL_CONTROL_MODE 0
    #define DXC_AUTO_PARK_MODE    1
    #define DXC_DUPLICATION_MODE  2
    static int dual_x_carriage_mode = DEFAULT_DUAL_X_CARRIAGE_MODE;
#endif
#if defined (upstream) && defined (DUAL_X_CARRIAGE) || defined (bobc) && defined (DUAL_X_CARRIAGE) || defined (indi-RichCattell) && defined (DUAL_X_CARRIAGE) || defined (mattsch) && defined (DUAL_X_CARRIAGE) || defined (quikshot) && defined (DUAL_X_CARRIAGE) || defined (ErikZalm) && defined (DUAL_X_CARRIAGE) || defined (alromh87) && defined (DUAL_X_CARRIAGE) || defined (hampussandberg) && defined (DUAL_X_CARRIAGE) || defined (oysteinkrog) && defined (DUAL_X_CARRIAGE) || defined (johnnyr) && defined (DUAL_X_CARRIAGE) || defined (yuroller) && defined (DUAL_X_CARRIAGE) || defined (ut7) && defined (DUAL_X_CARRIAGE) || defined (marlin4Due) && ENABLED(DUAL_X_CARRIAGE)

static float x_home_pos(int extruder) {
    if (extruder == 0)
        return base_home_pos(X_AXIS) + add_homing[X_AXIS];
    else
        // In dual carriage mode the extruder offset provides an override of the
        // second X-carriage offset when homed - otherwise X2_HOME_POS is used.
        // This allow soft recalibration of the second extruder offset position without firmware reflash
        // (through the M218 command).
        return (extruder_offset[X_AXIS][1] > 0) ? extruder_offset[X_AXIS][1] : X2_HOME_POS;
}

static int x_home_dir(int extruder) {
    return (extruder == 0) ? X_HOME_DIR : X2_HOME_DIR;
}
#endif
#if defined (upstream) && defined (DUAL_X_CARRIAGE) || defined (bobc) && defined (DUAL_X_CARRIAGE) || defined (indi-RichCattell) && defined (DUAL_X_CARRIAGE) || defined (mattsch) && defined (DUAL_X_CARRIAGE)
    static float inactive_extruder_x_pos = X2_MAX_POS;
    // used in mode 0 & 1
    static bool active_extruder_parked = false;
    // used in mode 1 & 2
    static float raised_parked_position[NUM_AXIS];
    // used in mode 1
    static unsigned long delayed_move_time = 0;
#endif
#if defined (marlin4Due) && ENABLED(DUAL_X_CARRIAGE)
    static millis_t delayed_move_time = 0;
#endif
#if defined (upstream) && defined (DUAL_X_CARRIAGE) || defined (bobc) && defined (DUAL_X_CARRIAGE) || defined (indi-RichCattell) && defined (DUAL_X_CARRIAGE) || defined (mattsch) && defined (DUAL_X_CARRIAGE)
    // used in mode 1
    static float duplicate_extruder_x_offset = DEFAULT_DUPLICATION_X_OFFSET;
    // used in mode 2
    static float duplicate_extruder_temp_offset = 0;
    // used in mode 2
    bool extruder_duplication_enabled = false;
    // used in mode 2
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch)
    //DUAL_X_CARRIAGE
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)

static void axis_is_at_home(int axis) {
#ifdef DUAL_X_CARRIAGE
    if (axis == X_AXIS) {
        if (active_extruder != 0) {
            current_position[X_AXIS] = x_home_pos(active_extruder);
            min_pos[X_AXIS] =          X2_MIN_POS;
            max_pos[X_AXIS] =          max(extruder_offset[X_AXIS][1], X2_MAX_POS);
            return;
        } else if (dual_x_carriage_mode == DXC_DUPLICATION_MODE && active_extruder == 0) {
            current_position[X_AXIS] = base_home_pos(X_AXIS) + add_homing[X_AXIS];
            min_pos[X_AXIS] =          base_min_pos(X_AXIS) + add_homing[X_AXIS];
            max_pos[X_AXIS] =          min(base_max_pos(X_AXIS) + add_homing[X_AXIS],
                                           max(extruder_offset[X_AXIS][1], X2_MAX_POS) - duplicate_extruder_x_offset);
            return;
        }
    }
#endif
#ifdef SCARA
    float homeposition[3];
    char i;
    if (axis < 2) {
        for (i=0; i<3; i++) {
            homeposition[i] = base_home_pos(i);
        }
        // SERIAL_ECHOPGM("homeposition[x]= "); SERIAL_ECHO(homeposition[0]);
        //  SERIAL_ECHOPGM("homeposition[y]= "); SERIAL_ECHOLN(homeposition[1]);
        // Works out real Homeposition angles using inverse kinematics,
        // and calculates homing offset using forward kinematics
        calculate_delta(homeposition);
        // SERIAL_ECHOPGM("base Theta= "); SERIAL_ECHO(delta[X_AXIS]);
        // SERIAL_ECHOPGM(" base Psi+Theta="); SERIAL_ECHOLN(delta[Y_AXIS]);
        for (i=0; i<2; i++) {
            delta[i] -= add_homing[i];
        }
        // SERIAL_ECHOPGM("addhome X="); SERIAL_ECHO(add_homing[X_AXIS]);
        // SERIAL_ECHOPGM(" addhome Y="); SERIAL_ECHO(add_homing[Y_AXIS]);
        // SERIAL_ECHOPGM(" addhome Theta="); SERIAL_ECHO(delta[X_AXIS]);
        // SERIAL_ECHOPGM(" addhome Psi+Theta="); SERIAL_ECHOLN(delta[Y_AXIS]);
        calculate_SCARA_forward_Transform(delta);
        // SERIAL_ECHOPGM("Delta X="); SERIAL_ECHO(delta[X_AXIS]);
        // SERIAL_ECHOPGM(" Delta Y="); SERIAL_ECHOLN(delta[Y_AXIS]);
        current_position[axis] = delta[axis];
        // SCARA home positions are based on configuration since the actual limits are determined by the
        // inverse kinematic transform.
        min_pos[axis] =          base_min_pos(axis); // + (delta[axis] - base_home_pos(axis));
        max_pos[axis] =          base_max_pos(axis); // + (delta[axis] - base_home_pos(axis));
    } else {
        current_position[axis] = base_home_pos(axis) + add_homing[axis];
        min_pos[axis] =          base_min_pos(axis) + add_homing[axis];
        max_pos[axis] =          base_max_pos(axis) + add_homing[axis];
    }
#else
    current_position[axis] = base_home_pos(axis) + add_homing[axis];
    min_pos[axis] =          base_min_pos(axis) + add_homing[axis];
    max_pos[axis] =          base_max_pos(axis) + add_homing[axis];
#endif
}
#endif
#if defined (marlin4Due)
static void set_axis_is_at_home(AxisEnum axis) {
#if ENABLED(DUAL_X_CARRIAGE)
    if (axis == X_AXIS) {
        if (active_extruder != 0) {
            current_position[X_AXIS] = x_home_pos(active_extruder);
            min_pos[X_AXIS] = X2_MIN_POS;
            max_pos[X_AXIS] = max(extruder_offset[X_AXIS][1], X2_MAX_POS);
            return;
        } else if (dual_x_carriage_mode == DXC_DUPLICATION_MODE) {
            float xoff = home_offset[X_AXIS];
            current_position[X_AXIS] = base_home_pos(X_AXIS) + xoff;
            min_pos[X_AXIS] = base_min_pos(X_AXIS) + xoff;
            max_pos[X_AXIS] = min(base_max_pos(X_AXIS) + xoff, max(extruder_offset[X_AXIS][1], X2_MAX_POS) - duplicate_extruder_x_offset);
            return;
        }
    }
#endif
#if ENABLED(SCARA)
    if (axis == X_AXIS || axis == Y_AXIS) {
        float homeposition[3];
        for (int i = 0; i < 3; i++) homeposition[i] = base_home_pos(i);
        // SERIAL_ECHOPGM("homeposition[x]= "); SERIAL_ECHO(homeposition[0]);
        // SERIAL_ECHOPGM("homeposition[y]= "); SERIAL_ECHOLN(homeposition[1]);
        // Works out real Homeposition angles using inverse kinematics,
        // and calculates homing offset using forward kinematics
        calculate_delta(homeposition);
        // SERIAL_ECHOPGM("base Theta= "); SERIAL_ECHO(delta[X_AXIS]);
        // SERIAL_ECHOPGM(" base Psi+Theta="); SERIAL_ECHOLN(delta[Y_AXIS]);
        for (int i = 0; i < 2; i++) delta[i] -= home_offset[i];
        // SERIAL_ECHOPGM("addhome X="); SERIAL_ECHO(home_offset[X_AXIS]);
        // SERIAL_ECHOPGM(" addhome Y="); SERIAL_ECHO(home_offset[Y_AXIS]);
        // SERIAL_ECHOPGM(" addhome Theta="); SERIAL_ECHO(delta[X_AXIS]);
        // SERIAL_ECHOPGM(" addhome Psi+Theta="); SERIAL_ECHOLN(delta[Y_AXIS]);
        calculate_SCARA_forward_Transform(delta);
        // SERIAL_ECHOPGM("Delta X="); SERIAL_ECHO(delta[X_AXIS]);
        // SERIAL_ECHOPGM(" Delta Y="); SERIAL_ECHOLN(delta[Y_AXIS]);
        current_position[axis] = delta[axis];
        // SCARA home positions are based on configuration since the actual limits are determined by the
        // inverse kinematic transform.
        min_pos[axis] = base_min_pos(axis); // + (delta[axis] - base_home_pos(axis));
        max_pos[axis] = base_max_pos(axis); // + (delta[axis] - base_home_pos(axis));
    } else
#endif
    {
        current_position[axis] = base_home_pos(axis) + home_offset[axis];
        min_pos[axis] = base_min_pos(axis) + home_offset[axis];
        max_pos[axis] = base_max_pos(axis) + home_offset[axis];
#if ENABLED(ENABLE_AUTO_BED_LEVELING) && Z_HOME_DIR < 0
        if (axis == Z_AXIS) current_position[Z_AXIS] -= zprobe_zoffset;
#endif
    }
}
/**
 * Some planner shorthand inline functions
 */
inline void set_homing_bump_feedrate(AxisEnum axis) {
    const int homing_bump_divisor[] = HOMING_BUMP_DIVISOR;
    int hbd = homing_bump_divisor[axis];
    if (hbd < 1) {
        hbd = 10;
        SERIAL_ECHO_START;
        SERIAL_ECHOLNPGM("Warning: Homing Bump Divisor < 1");
    }
    feedrate = homing_feedrate[axis] / hbd;
}
inline void line_to_current_position() {
    plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS], feedrate/60, active_extruder);
}
inline void line_to_z(float zPosition) {
    plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], zPosition, current_position[E_AXIS], feedrate/60, active_extruder);
}
inline void line_to_destination(float mm_m) {
    plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], mm_m/60, active_extruder);
}
inline void line_to_destination() {
    line_to_destination(feedrate);
}
inline void sync_plan_position() {
    plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
}
#endif
#if defined (marlin4Due) && (ENABLED(DELTA) || ENABLED(SCARA))
inline void sync_plan_position_delta() {
    calculate_delta(current_position);
    plan_set_position(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], current_position[E_AXIS]);
}
#endif
#if defined (marlin4Due)
inline void set_current_to_destination() {
    memcpy(current_position, destination, sizeof(current_position));
}
inline void set_destination_to_current() {
    memcpy(destination, current_position, sizeof(destination));
}
static void setup_for_endstop_move() {
    saved_feedrate = feedrate;
    saved_feedrate_multiplier = feedrate_multiplier;
    feedrate_multiplier = 100;
    refresh_cmd_timeout();
    enable_endstops(true);
}
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(DELTA) )
/**
     * Calculate delta, start a line, and set current_position to destination
     */
void prepare_move_raw() {
    refresh_cmd_timeout();
    calculate_delta(destination);
    plan_buffer_line(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], destination[E_AXIS], (feedrate/60)*(feedrate_multiplier/100.0), active_extruder);
    set_current_to_destination();
}
#endif
#if defined (upstream) && (defined (ENABLE_AUTO_BED_LEVELING) && defined (AUTO_BED_LEVELING_GRID) ) || defined (bobc) && (defined (ENABLE_AUTO_BED_LEVELING) && defined (AUTO_BED_LEVELING_GRID) ) || defined (mattsch) && (defined (ENABLE_AUTO_BED_LEVELING) && defined (AUTO_BED_LEVELING_GRID) ) || defined (quikshot) && (defined (ENABLE_AUTO_BED_LEVELING) && defined (AUTO_BED_LEVELING_GRID) ) || defined (ErikZalm) && (defined (ENABLE_AUTO_BED_LEVELING) && defined (AUTO_BED_LEVELING_GRID) ) || defined (alromh87) && (defined (ENABLE_AUTO_BED_LEVELING) && defined (AUTO_BED_LEVELING_GRID) ) || defined (hampussandberg) && (defined (ENABLE_AUTO_BED_LEVELING) && defined (AUTO_BED_LEVELING_GRID) ) || defined (oysteinkrog) && (defined (ENABLE_AUTO_BED_LEVELING) && defined (AUTO_BED_LEVELING_GRID) ) || defined (johnnyr) && (defined (ENABLE_AUTO_BED_LEVELING) && defined (AUTO_BED_LEVELING_GRID) ) || defined (yuroller) && (defined (ENABLE_AUTO_BED_LEVELING) && defined (AUTO_BED_LEVELING_GRID) ) || defined (ut7) && (defined (ENABLE_AUTO_BED_LEVELING) && defined (AUTO_BED_LEVELING_GRID) ) || defined (marlin4Due) && (DISABLED(DELTA) && ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(AUTO_BED_LEVELING_GRID) )

static void set_bed_level_equation_lsq(double *plane_equation_coefficients) {
    vector_3 planeNormal = vector_3(-plane_equation_coefficients[0], -plane_equation_coefficients[1], 1);
    planeNormal.debug("planeNormal");
    plan_bed_level_matrix = matrix_3x3::create_look_at(planeNormal);
    //bedLevel.debug("bedLevel");
    //plan_bed_level_matrix.debug("bed level before");
    //vector_3 uncorrected_position = plan_get_position_mm();
    //uncorrected_position.debug("position before");
    vector_3 corrected_position = plan_get_position();
//    corrected_position.debug("position after");
    current_position[X_AXIS] = corrected_position.x;
    current_position[Y_AXIS] = corrected_position.y;
    current_position[Z_AXIS] = corrected_position.z;
    // put the bed at 0 so we don't go below it.
    current_position[Z_AXIS] = zprobe_zoffset; // in the lsq we reach here after raising the extruder due to the loop structure
    plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
}
#endif
#if defined (upstream) && (!defined (AUTO_BED_LEVELING_GRID) && defined (ENABLE_AUTO_BED_LEVELING) ) || defined (bobc) && (!defined (AUTO_BED_LEVELING_GRID) && defined (ENABLE_AUTO_BED_LEVELING) )
    // not AUTO_BED_LEVELING_GRID
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(AUTO_BED_LEVELING_GRID) )
    // !DELTA
#endif
#if defined (marlin4Due) && (!ENABLED(AUTO_BED_LEVELING_GRID) && ENABLED(ENABLE_AUTO_BED_LEVELING) )
    // !AUTO_BED_LEVELING_GRID
#endif
#if defined (upstream) && (!defined (AUTO_BED_LEVELING_GRID) && defined (ENABLE_AUTO_BED_LEVELING) ) || defined (bobc) && (!defined (AUTO_BED_LEVELING_GRID) && defined (ENABLE_AUTO_BED_LEVELING) ) || defined (mattsch) && (!defined (AUTO_BED_LEVELING_GRID) && defined (ENABLE_AUTO_BED_LEVELING) ) || defined (quikshot) && (!defined (AUTO_BED_LEVELING_GRID) && defined (ENABLE_AUTO_BED_LEVELING) ) || defined (ErikZalm) && (!defined (AUTO_BED_LEVELING_GRID) && defined (ENABLE_AUTO_BED_LEVELING) ) || defined (alromh87) && (!defined (AUTO_BED_LEVELING_GRID) && defined (ENABLE_AUTO_BED_LEVELING) ) || defined (hampussandberg) && (!defined (AUTO_BED_LEVELING_GRID) && defined (ENABLE_AUTO_BED_LEVELING) ) || defined (oysteinkrog) && (!defined (AUTO_BED_LEVELING_GRID) && defined (ENABLE_AUTO_BED_LEVELING) ) || defined (johnnyr) && (!defined (AUTO_BED_LEVELING_GRID) && defined (ENABLE_AUTO_BED_LEVELING) ) || defined (yuroller) && (!defined (AUTO_BED_LEVELING_GRID) && defined (ENABLE_AUTO_BED_LEVELING) ) || defined (ut7) && (!defined (AUTO_BED_LEVELING_GRID) && defined (ENABLE_AUTO_BED_LEVELING) ) || defined (marlin4Due) && (!ENABLED(AUTO_BED_LEVELING_GRID) && ENABLED(ENABLE_AUTO_BED_LEVELING) )

static void set_bed_level_equation_3pts(float z_at_pt_1, float z_at_pt_2, float z_at_pt_3) {
    plan_bed_level_matrix.set_to_identity();
    vector_3 pt1 = vector_3(ABL_PROBE_PT_1_X, ABL_PROBE_PT_1_Y, z_at_pt_1);
    vector_3 pt2 = vector_3(ABL_PROBE_PT_2_X, ABL_PROBE_PT_2_Y, z_at_pt_2);
    vector_3 pt3 = vector_3(ABL_PROBE_PT_3_X, ABL_PROBE_PT_3_Y, z_at_pt_3);
    vector_3 from_2_to_1 = (pt1 - pt2).get_normal();
    vector_3 from_2_to_3 = (pt3 - pt2).get_normal();
    vector_3 planeNormal = vector_3::cross(from_2_to_1, from_2_to_3).get_normal();
    planeNormal = vector_3(planeNormal.x, planeNormal.y, abs(planeNormal.z));
    plan_bed_level_matrix = matrix_3x3::create_look_at(planeNormal);
    vector_3 corrected_position = plan_get_position();
    current_position[X_AXIS] = corrected_position.x;
    current_position[Y_AXIS] = corrected_position.y;
    current_position[Z_AXIS] = corrected_position.z;
    // put the bed at 0 so we don't go below it.
    current_position[Z_AXIS] = zprobe_zoffset;
    plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
}
#endif
#if defined (upstream) && defined (ENABLE_AUTO_BED_LEVELING) || defined (bobc) && defined (ENABLE_AUTO_BED_LEVELING)
    // AUTO_BED_LEVELING_GRID
#endif
#if defined (marlin4Due) && ENABLED(ENABLE_AUTO_BED_LEVELING)
    // !AUTO_BED_LEVELING_GRID
#endif
#if defined (upstream) && defined (ENABLE_AUTO_BED_LEVELING) || defined (bobc) && defined (ENABLE_AUTO_BED_LEVELING) || defined (mattsch) && defined (ENABLE_AUTO_BED_LEVELING) || defined (quikshot) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ErikZalm) && defined (ENABLE_AUTO_BED_LEVELING) || defined (alromh87) && defined (ENABLE_AUTO_BED_LEVELING) || defined (hampussandberg) && defined (ENABLE_AUTO_BED_LEVELING) || defined (oysteinkrog) && defined (ENABLE_AUTO_BED_LEVELING) || defined (johnnyr) && defined (ENABLE_AUTO_BED_LEVELING) || defined (yuroller) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ut7) && defined (ENABLE_AUTO_BED_LEVELING) || defined (marlin4Due) && ENABLED(ENABLE_AUTO_BED_LEVELING)

static void run_z_probe() {
    plan_bed_level_matrix.set_to_identity();
    feedrate = homing_feedrate[Z_AXIS];
    // move down until you find the bed
    float zPosition = -10;
    plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], zPosition, current_position[E_AXIS], feedrate/60, active_extruder);
    st_synchronize();
    // we have to let the planner know where we are right now as it is not where we said to go.
    zPosition = st_get_position_mm(Z_AXIS);
    plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], zPosition, current_position[E_AXIS]);
    // move up the retract distance
    zPosition += home_retract_mm(Z_AXIS);
    plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], zPosition, current_position[E_AXIS], feedrate/60, active_extruder);
    st_synchronize();
    // move back down slowly to find bed
    feedrate = homing_feedrate[Z_AXIS]/4;
    zPosition -= home_retract_mm(Z_AXIS) * 2;
    plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], zPosition, current_position[E_AXIS], feedrate/60, active_extruder);
    st_synchronize();
    current_position[Z_AXIS] = st_get_position_mm(Z_AXIS);
    // make sure the planner knows where we are as it may be a bit different than we last said to move to
    plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
}
#endif
#if defined (marlin4Due) && ENABLED(ENABLE_AUTO_BED_LEVELING)
    /**
    *  Plan a move to (X, Y, Z) and set the current_position
    *  The final current_position may not be the one that was requested
    */
#endif
#if defined (upstream) && defined (ENABLE_AUTO_BED_LEVELING) || defined (bobc) && defined (ENABLE_AUTO_BED_LEVELING) || defined (mattsch) && defined (ENABLE_AUTO_BED_LEVELING) || defined (quikshot) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ErikZalm) && defined (ENABLE_AUTO_BED_LEVELING) || defined (alromh87) && defined (ENABLE_AUTO_BED_LEVELING) || defined (hampussandberg) && defined (ENABLE_AUTO_BED_LEVELING) || defined (oysteinkrog) && defined (ENABLE_AUTO_BED_LEVELING) || defined (johnnyr) && defined (ENABLE_AUTO_BED_LEVELING) || defined (yuroller) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ut7) && defined (ENABLE_AUTO_BED_LEVELING) || defined (marlin4Due) && ENABLED(ENABLE_AUTO_BED_LEVELING)

static void do_blocking_move_to(float x, float y, float z) {
    float oldFeedRate = feedrate;
    feedrate = homing_feedrate[Z_AXIS];
    current_position[Z_AXIS] = z;
    plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS], feedrate/60, active_extruder);
    st_synchronize();
    feedrate = XY_TRAVEL_SPEED;
    current_position[X_AXIS] = x;
    current_position[Y_AXIS] = y;
    plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS], feedrate/60, active_extruder);
    st_synchronize();
    feedrate = oldFeedRate;
}
#endif
#if defined (upstream) && defined (ENABLE_AUTO_BED_LEVELING) || defined (bobc) && defined (ENABLE_AUTO_BED_LEVELING) || defined (mattsch) && defined (ENABLE_AUTO_BED_LEVELING) || defined (quikshot) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ErikZalm) && defined (ENABLE_AUTO_BED_LEVELING) || defined (alromh87) && defined (ENABLE_AUTO_BED_LEVELING) || defined (hampussandberg) && defined (ENABLE_AUTO_BED_LEVELING) || defined (oysteinkrog) && defined (ENABLE_AUTO_BED_LEVELING) || defined (johnnyr) && defined (ENABLE_AUTO_BED_LEVELING) || defined (yuroller) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ut7) && defined (ENABLE_AUTO_BED_LEVELING)

static void do_blocking_move_relative(float offset_x, float offset_y, float offset_z) {
    do_blocking_move_to(current_position[X_AXIS] + offset_x, current_position[Y_AXIS] + offset_y, current_position[Z_AXIS] + offset_z);
}
#endif
#if defined (marlin4Due) && ENABLED(ENABLE_AUTO_BED_LEVELING)
inline void do_blocking_move_to_xy(float x, float y) {
    do_blocking_move_to(x, y, current_position[Z_AXIS]);
}
#endif
#if defined (upstream) && defined (ENABLE_AUTO_BED_LEVELING) || defined (bobc) && defined (ENABLE_AUTO_BED_LEVELING) || defined (mattsch) && defined (ENABLE_AUTO_BED_LEVELING) || defined (quikshot) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ErikZalm) && defined (ENABLE_AUTO_BED_LEVELING) || defined (alromh87) && defined (ENABLE_AUTO_BED_LEVELING) || defined (hampussandberg) && defined (ENABLE_AUTO_BED_LEVELING) || defined (oysteinkrog) && defined (ENABLE_AUTO_BED_LEVELING) || defined (johnnyr) && defined (ENABLE_AUTO_BED_LEVELING) || defined (yuroller) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ut7) && defined (ENABLE_AUTO_BED_LEVELING)

static void setup_for_endstop_move() {
    saved_feedrate = feedrate;
    saved_feedmultiply = feedmultiply;
    feedmultiply = 100;
    previous_millis_cmd = millis();
    enable_endstops(true);
}
#endif
#if defined (marlin4Due) && ENABLED(ENABLE_AUTO_BED_LEVELING)
inline void do_blocking_move_to_x(float x) {
    do_blocking_move_to(x, current_position[Y_AXIS], current_position[Z_AXIS]);
}
inline void do_blocking_move_to_z(float z) {
    do_blocking_move_to(current_position[X_AXIS], current_position[Y_AXIS], z);
}
#endif
#if defined (upstream) && defined (ENABLE_AUTO_BED_LEVELING) || defined (bobc) && defined (ENABLE_AUTO_BED_LEVELING) || defined (mattsch) && defined (ENABLE_AUTO_BED_LEVELING) || defined (quikshot) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ErikZalm) && defined (ENABLE_AUTO_BED_LEVELING) || defined (alromh87) && defined (ENABLE_AUTO_BED_LEVELING) || defined (hampussandberg) && defined (ENABLE_AUTO_BED_LEVELING) || defined (oysteinkrog) && defined (ENABLE_AUTO_BED_LEVELING) || defined (johnnyr) && defined (ENABLE_AUTO_BED_LEVELING) || defined (yuroller) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ut7) && defined (ENABLE_AUTO_BED_LEVELING) || defined (marlin4Due) && ENABLED(ENABLE_AUTO_BED_LEVELING)

static void clean_up_after_endstop_move() {
#ifdef ENDSTOPS_ONLY_FOR_HOMING
    enable_endstops(false);
#endif
    feedrate = saved_feedrate;
    feedmultiply = saved_feedmultiply;
    previous_millis_cmd = millis();
}
#endif
#if defined (upstream) && defined (ENABLE_AUTO_BED_LEVELING) || defined (bobc) && defined (ENABLE_AUTO_BED_LEVELING) || defined (mattsch) && defined (ENABLE_AUTO_BED_LEVELING) || defined (quikshot) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ErikZalm) && defined (ENABLE_AUTO_BED_LEVELING) || defined (alromh87) && defined (ENABLE_AUTO_BED_LEVELING) || defined (hampussandberg) && defined (ENABLE_AUTO_BED_LEVELING) || defined (oysteinkrog) && defined (ENABLE_AUTO_BED_LEVELING) || defined (johnnyr) && defined (ENABLE_AUTO_BED_LEVELING) || defined (yuroller) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ut7) && defined (ENABLE_AUTO_BED_LEVELING)

static void engage_z_probe() {
    // Engage Z Servo endstop if enabled
#ifdef SERVO_ENDSTOPS
    if (servo_endstops[Z_AXIS] > -1) {
#if defined (ENABLE_AUTO_BED_LEVELING) && (PROBE_SERVO_DEACTIVATION_DELAY > 0)
        servos[servo_endstops[Z_AXIS]].attach(0);
#endif
        servos[servo_endstops[Z_AXIS]].write(servo_endstop_angles[Z_AXIS * 2]);
#if defined (ENABLE_AUTO_BED_LEVELING) && (PROBE_SERVO_DEACTIVATION_DELAY > 0)
        delay(PROBE_SERVO_DEACTIVATION_DELAY);
        servos[servo_endstops[Z_AXIS]].detach();
#endif
    }
#endif
}
#endif
#if defined (marlin4Due) && ENABLED(ENABLE_AUTO_BED_LEVELING)
static void deploy_z_probe() {
#if HAS_SERVO_ENDSTOPS
    // Engage Z Servo endstop if enabled
    if (servo_endstop_id[Z_AXIS] >= 0) servo[servo_endstop_id[Z_AXIS]].move(servo_endstop_angle[Z_AXIS][0]);
#elif ENABLED(Z_PROBE_ALLEN_KEY)
    feedrate = Z_PROBE_ALLEN_KEY_DEPLOY_1_FEEDRATE;
    // If endstop is already false, the probe is deployed
#if ENABLED(Z_PROBE_ENDSTOP)
    bool z_probe_endstop = (READ(Z_PROBE_PIN) != Z_PROBE_ENDSTOP_INVERTING);
    if (z_probe_endstop)
#else
    bool z_min_endstop = (READ(Z_MIN_PIN) != Z_MIN_ENDSTOP_INVERTING);
    if (z_min_endstop)
#endif
    {
        // Move to the start position to initiate deployment
        destination[X_AXIS] = Z_PROBE_ALLEN_KEY_DEPLOY_1_X;
        destination[Y_AXIS] = Z_PROBE_ALLEN_KEY_DEPLOY_1_Y;
        destination[Z_AXIS] = Z_PROBE_ALLEN_KEY_DEPLOY_1_Z;
        prepare_move_raw(); // this will also set_current_to_destination
        // Move to engage deployment
        if (Z_PROBE_ALLEN_KEY_DEPLOY_2_FEEDRATE != Z_PROBE_ALLEN_KEY_DEPLOY_1_FEEDRATE) {
            feedrate = Z_PROBE_ALLEN_KEY_DEPLOY_2_FEEDRATE;
        }
        if (Z_PROBE_ALLEN_KEY_DEPLOY_2_X != Z_PROBE_ALLEN_KEY_DEPLOY_1_X) {
            destination[X_AXIS] = Z_PROBE_ALLEN_KEY_DEPLOY_2_X;
        }
        if (Z_PROBE_ALLEN_KEY_DEPLOY_2_Y != Z_PROBE_ALLEN_KEY_DEPLOY_1_Y) {
            destination[Y_AXIS] = Z_PROBE_ALLEN_KEY_DEPLOY_2_Y;
        }
        if (Z_PROBE_ALLEN_KEY_DEPLOY_2_Z != Z_PROBE_ALLEN_KEY_DEPLOY_1_Z) {
            destination[Z_AXIS] = Z_PROBE_ALLEN_KEY_DEPLOY_2_Z;
        }
        prepare_move_raw();
#ifdef Z_PROBE_ALLEN_KEY_DEPLOY_3_X
        if (Z_PROBE_ALLEN_KEY_DEPLOY_3_FEEDRATE != Z_PROBE_ALLEN_KEY_DEPLOY_2_FEEDRATE) {
            feedrate = Z_PROBE_ALLEN_KEY_DEPLOY_3_FEEDRATE;
        }
        // Move to trigger deployment
        if (Z_PROBE_ALLEN_KEY_DEPLOY_3_FEEDRATE != Z_PROBE_ALLEN_KEY_DEPLOY_2_FEEDRATE) {
            feedrate = Z_PROBE_ALLEN_KEY_DEPLOY_3_FEEDRATE;
        }
        if (Z_PROBE_ALLEN_KEY_DEPLOY_3_X != Z_PROBE_ALLEN_KEY_DEPLOY_2_X) {
            destination[X_AXIS] = Z_PROBE_ALLEN_KEY_DEPLOY_3_X;
        }
        if (Z_PROBE_ALLEN_KEY_DEPLOY_3_Y != Z_PROBE_ALLEN_KEY_DEPLOY_2_Y) {
            destination[Y_AXIS] = Z_PROBE_ALLEN_KEY_DEPLOY_3_Y;
        }
        if (Z_PROBE_ALLEN_KEY_DEPLOY_3_Z != Z_PROBE_ALLEN_KEY_DEPLOY_2_Z) {
            destination[Z_AXIS] = Z_PROBE_ALLEN_KEY_DEPLOY_3_Z;
        }
        prepare_move_raw();
#endif
    }
    // Partially Home X,Y for safety
    destination[X_AXIS] = destination[X_AXIS]*0.75;
    destination[Y_AXIS] = destination[Y_AXIS]*0.75;
    prepare_move_raw(); // this will also set_current_to_destination
    st_synchronize();
#if ENABLED(Z_PROBE_ENDSTOP)
    z_probe_endstop = (READ(Z_PROBE_PIN) != Z_PROBE_ENDSTOP_INVERTING);
    if (z_probe_endstop)
#else
    z_min_endstop = (READ(Z_MIN_PIN) != Z_MIN_ENDSTOP_INVERTING);
    if (z_min_endstop)
#endif
    {
        if (IsRunning()) {
            SERIAL_ERROR_START;
            SERIAL_ERRORLNPGM("Z-Probe failed to engage!");
            LCD_ALERTMESSAGEPGM("Err: ZPROBE");
        }
        Stop();
    }
#endif // Z_PROBE_ALLEN_KEY
}
#endif
#if defined (upstream) && defined (ENABLE_AUTO_BED_LEVELING) || defined (bobc) && defined (ENABLE_AUTO_BED_LEVELING) || defined (mattsch) && defined (ENABLE_AUTO_BED_LEVELING) || defined (quikshot) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ErikZalm) && defined (ENABLE_AUTO_BED_LEVELING) || defined (alromh87) && defined (ENABLE_AUTO_BED_LEVELING) || defined (hampussandberg) && defined (ENABLE_AUTO_BED_LEVELING) || defined (oysteinkrog) && defined (ENABLE_AUTO_BED_LEVELING) || defined (johnnyr) && defined (ENABLE_AUTO_BED_LEVELING) || defined (yuroller) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ut7) && defined (ENABLE_AUTO_BED_LEVELING)

static void retract_z_probe() {
    // Retract Z Servo endstop if enabled
#ifdef SERVO_ENDSTOPS
    if (servo_endstops[Z_AXIS] > -1) {
#if defined (ENABLE_AUTO_BED_LEVELING) && (PROBE_SERVO_DEACTIVATION_DELAY > 0)
        servos[servo_endstops[Z_AXIS]].attach(0);
#endif
        servos[servo_endstops[Z_AXIS]].write(servo_endstop_angles[Z_AXIS * 2 + 1]);
#if defined (ENABLE_AUTO_BED_LEVELING) && (PROBE_SERVO_DEACTIVATION_DELAY > 0)
        delay(PROBE_SERVO_DEACTIVATION_DELAY);
        servos[servo_endstops[Z_AXIS]].detach();
#endif
    }
#endif
}
#endif
#if defined (marlin4Due) && ENABLED(ENABLE_AUTO_BED_LEVELING)
static void stow_z_probe(bool doRaise=true) {
#if HAS_SERVO_ENDSTOPS
    // Retract Z Servo endstop if enabled
    if (servo_endstop_id[Z_AXIS] >= 0) {
#if Z_RAISE_AFTER_PROBING > 0
        if (doRaise) {
            do_blocking_move_to_z(current_position[Z_AXIS] + Z_RAISE_AFTER_PROBING); // this also updates current_position
            st_synchronize();
        }
#endif
        // Change the Z servo angle
        servo[servo_endstop_id[Z_AXIS]].move(servo_endstop_angle[Z_AXIS][1]);
    }
#elif ENABLED(Z_PROBE_ALLEN_KEY)
    // Move up for safety
    feedrate = Z_PROBE_ALLEN_KEY_STOW_1_FEEDRATE;
#if Z_RAISE_AFTER_PROBING > 0
    destination[Z_AXIS] = current_position[Z_AXIS] + Z_RAISE_AFTER_PROBING;
    prepare_move_raw(); // this will also set_current_to_destination
#endif
    // Move to the start position to initiate retraction
    destination[X_AXIS] = Z_PROBE_ALLEN_KEY_STOW_1_X;
    destination[Y_AXIS] = Z_PROBE_ALLEN_KEY_STOW_1_Y;
    destination[Z_AXIS] = Z_PROBE_ALLEN_KEY_STOW_1_Z;
    prepare_move_raw();
    // Move the nozzle down to push the probe into retracted position
    if (Z_PROBE_ALLEN_KEY_STOW_2_FEEDRATE != Z_PROBE_ALLEN_KEY_STOW_1_FEEDRATE) {
        feedrate = Z_PROBE_ALLEN_KEY_STOW_2_FEEDRATE;
    }
    if (Z_PROBE_ALLEN_KEY_STOW_2_X != Z_PROBE_ALLEN_KEY_STOW_1_X) {
        destination[X_AXIS] = Z_PROBE_ALLEN_KEY_STOW_2_X;
    }
    if (Z_PROBE_ALLEN_KEY_STOW_2_Y != Z_PROBE_ALLEN_KEY_STOW_1_Y) {
        destination[Y_AXIS] = Z_PROBE_ALLEN_KEY_STOW_2_Y;
    }
    destination[Z_AXIS] = Z_PROBE_ALLEN_KEY_STOW_2_Z;
    prepare_move_raw();
    // Move up for safety
    if (Z_PROBE_ALLEN_KEY_STOW_3_FEEDRATE != Z_PROBE_ALLEN_KEY_STOW_2_FEEDRATE) {
        feedrate = Z_PROBE_ALLEN_KEY_STOW_2_FEEDRATE;
    }
    if (Z_PROBE_ALLEN_KEY_STOW_3_X != Z_PROBE_ALLEN_KEY_STOW_2_X) {
        destination[X_AXIS] = Z_PROBE_ALLEN_KEY_STOW_3_X;
    }
    if (Z_PROBE_ALLEN_KEY_STOW_3_Y != Z_PROBE_ALLEN_KEY_STOW_2_Y) {
        destination[Y_AXIS] = Z_PROBE_ALLEN_KEY_STOW_3_Y;
    }
    destination[Z_AXIS] = Z_PROBE_ALLEN_KEY_STOW_3_Z;
    prepare_move_raw();
    // Home XY for safety
    feedrate = homing_feedrate[X_AXIS]/2;
    destination[X_AXIS] = 0;
    destination[Y_AXIS] = 0;
    prepare_move_raw(); // this will also set_current_to_destination
    st_synchronize();
#if ENABLED(Z_PROBE_ENDSTOP)
    bool z_probe_endstop = (READ(Z_PROBE_PIN) != Z_PROBE_ENDSTOP_INVERTING);
    if (!z_probe_endstop)
#else
    bool z_min_endstop = (READ(Z_MIN_PIN) != Z_MIN_ENDSTOP_INVERTING);
    if (!z_min_endstop)
#endif
    {
        if (IsRunning()) {
            SERIAL_ERROR_START;
            SERIAL_ERRORLNPGM("Z-Probe failed to retract!");
            LCD_ALERTMESSAGEPGM("Err: ZPROBE");
        }
        Stop();
    }
#endif // Z_PROBE_ALLEN_KEY
}
#endif
#if defined (upstream) && defined (ENABLE_AUTO_BED_LEVELING) || defined (bobc) && defined (ENABLE_AUTO_BED_LEVELING)
    /// Probe bed height at position (x,y), returns the measured z value
#endif
#if defined (marlin4Due) && ENABLED(ENABLE_AUTO_BED_LEVELING)
enum ProbeAction {
    ProbeStay          = 0,
    ProbeDeploy        = BIT(0),
    ProbeStow          = BIT(1),
    ProbeDeployAndStow = (ProbeDeploy | ProbeStow)
};
// Probe bed height at position (x,y), returns the measured z value
#endif
#if defined (upstream) && defined (ENABLE_AUTO_BED_LEVELING) || defined (bobc) && defined (ENABLE_AUTO_BED_LEVELING) || defined (mattsch) && defined (ENABLE_AUTO_BED_LEVELING) || defined (quikshot) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ErikZalm) && defined (ENABLE_AUTO_BED_LEVELING) || defined (alromh87) && defined (ENABLE_AUTO_BED_LEVELING) || defined (hampussandberg) && defined (ENABLE_AUTO_BED_LEVELING) || defined (oysteinkrog) && defined (ENABLE_AUTO_BED_LEVELING) || defined (johnnyr) && defined (ENABLE_AUTO_BED_LEVELING) || defined (yuroller) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ut7) && defined (ENABLE_AUTO_BED_LEVELING) || defined (marlin4Due) && ENABLED(ENABLE_AUTO_BED_LEVELING)

static float probe_pt(float x, float y, float z_before) {
    // move to right place
    do_blocking_move_to(current_position[X_AXIS], current_position[Y_AXIS], z_before);
    do_blocking_move_to(x - X_PROBE_OFFSET_FROM_EXTRUDER, y - Y_PROBE_OFFSET_FROM_EXTRUDER, current_position[Z_AXIS]);
#ifndef Z_PROBE_SLED
    engage_z_probe();   // Engage Z Servo endstop if available
#endif // Z_PROBE_SLED
    run_z_probe();
    float measured_z = current_position[Z_AXIS];
#ifndef Z_PROBE_SLED
    retract_z_probe();
#endif // Z_PROBE_SLED
    SERIAL_PROTOCOLPGM(MSG_BED);
    SERIAL_PROTOCOLPGM(" x: ");
    SERIAL_PROTOCOL(x);
    SERIAL_PROTOCOLPGM(" y: ");
    SERIAL_PROTOCOL(y);
    SERIAL_PROTOCOLPGM(" z: ");
    SERIAL_PROTOCOL(measured_z);
    SERIAL_PROTOCOLPGM("\n");
    return measured_z;
}
#endif
#if defined (upstream) || defined (bobc)
    // #ifdef ENABLE_AUTO_BED_LEVELING
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(DELTA) )
    /**
    * All DELTA leveling in the Marlin uses NONLINEAR_BED_LEVELING
    */
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)

static void homeaxis(int axis) {
#define HOMEAXIS_DO(LETTER) \
  ((LETTER##_MIN_PIN > -1 && LETTER##_HOME_DIR==-1) || (LETTER##_MAX_PIN > -1 && LETTER##_HOME_DIR==1))
    if (axis==X_AXIS ? HOMEAXIS_DO(X) :
            axis==Y_AXIS ? HOMEAXIS_DO(Y) :
            axis==Z_AXIS ? HOMEAXIS_DO(Z) :
            0) {
        int axis_home_dir = home_dir(axis);
#ifdef DUAL_X_CARRIAGE
        if (axis == X_AXIS)
            axis_home_dir = x_home_dir(active_extruder);
#endif
        current_position[axis] = 0;
        plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
#ifndef Z_PROBE_SLED
        // Engage Servo endstop if enabled
#ifdef SERVO_ENDSTOPS
#if defined (ENABLE_AUTO_BED_LEVELING) && (PROBE_SERVO_DEACTIVATION_DELAY > 0)
        if (axis==Z_AXIS) {
            engage_z_probe();
        } else
#endif
            if (servo_endstops[axis] > -1) {
                servos[servo_endstops[axis]].write(servo_endstop_angles[axis * 2]);
            }
#endif
#endif // Z_PROBE_SLED
        destination[axis] = 1.5 * max_length(axis) * axis_home_dir;
        feedrate = homing_feedrate[axis];
        plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate/60, active_extruder);
        st_synchronize();
        current_position[axis] = 0;
        plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
        destination[axis] = -home_retract_mm(axis) * axis_home_dir;
        plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate/60, active_extruder);
        st_synchronize();
        destination[axis] = 2*home_retract_mm(axis) * axis_home_dir;
#ifdef DELTA
        feedrate = homing_feedrate[axis]/10;
#else
        feedrate = homing_feedrate[axis]/2 ;
#endif
        plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate/60, active_extruder);
        st_synchronize();
#ifdef DELTA
        // retrace by the amount specified in endstop_adj
        if (endstop_adj[axis] * axis_home_dir < 0) {
            plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
            destination[axis] = endstop_adj[axis];
            plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate/60, active_extruder);
            st_synchronize();
        }
#endif
        axis_is_at_home(axis);
        destination[axis] = current_position[axis];
        feedrate = 0.0;
        endstops_hit_on_purpose();
        axis_known_position[axis] = true;
        // Retract Servo endstop if enabled
#ifdef SERVO_ENDSTOPS
        if (servo_endstops[axis] > -1) {
            servos[servo_endstops[axis]].write(servo_endstop_angles[axis * 2 + 1]);
        }
#endif
#if defined (ENABLE_AUTO_BED_LEVELING) && (PROBE_SERVO_DEACTIVATION_DELAY > 0)
#ifndef Z_PROBE_SLED
        if (axis==Z_AXIS) retract_z_probe();
#endif
#endif
    }
}
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(DELTA) )
static void extrapolate_one_point(int x, int y, int xdir, int ydir) {
    if (bed_level[x][y] != 0.0) {
        return;  // Don't overwrite good values.
    }
    float a = 2*bed_level[x+xdir][y] - bed_level[x+xdir*2][y];  // Left to right.
    float b = 2*bed_level[x][y+ydir] - bed_level[x][y+ydir*2];  // Front to back.
    float c = 2*bed_level[x+xdir][y+ydir] - bed_level[x+xdir*2][y+ydir*2];  // Diagonal.
    float median = c;  // Median is robust (ignores outliers).
    if (a < b) {
        if (b < c) median = b;
        if (c < a) median = a;
    } else {  // b <= a
        if (c < b) median = b;
        if (a < c) median = a;
    }
    bed_level[x][y] = median;
}
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    #define HOMEAXIS(LETTER) homeaxis(LETTER##_AXIS)
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(DELTA) )
    // Fill in the unprobed points (corners of circular print surface)
#endif
#if defined (indi-RichCattell)
void set_default_z_probe_offset() {
    z_probe_offset[X_AXIS] = default_z_probe_offset[X_AXIS];
    z_probe_offset[Y_AXIS] = default_z_probe_offset[Y_AXIS];
    z_probe_offset[Z_AXIS] = default_z_probe_offset[Z_AXIS];
}
#endif
#if defined (upstream) || defined (bobc) || defined (mattsch) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (hampussandberg) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)

void refresh_cmd_timeout(void) {
    previous_millis_cmd = millis();
}
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(DELTA) )
    // using linear extrapolation, away from the center.
#endif
#if defined (indi-RichCattell)
void set_delta_constants() {
    max_length[Z_AXIS] = max_pos[Z_AXIS] - Z_MIN_POS;
    base_max_pos[Z_AXIS]  = max_pos[Z_AXIS];
    base_home_pos[Z_AXIS] = max_pos[Z_AXIS];
    DELTA_DIAGONAL_ROD_2 = pow(delta_diagonal_rod,2);
    // Effective X/Y positions of the three vertical towers.
    /*
    delta_tower1_x = (-SIN_60 * delta_radius) + tower_adj[0]; // front left tower + xa
    delta_tower1_y = (-COS_60 * delta_radius) - tower_adj[0] ;
    delta_tower2_x = -(-SIN_60 * delta_radius) + tower_adj[1]; // front right tower + xb
    delta_tower2_y = (-COS_60 * delta_radius) + tower_adj[1]; //
    delta_tower3_x = tower_adj[2] ; // back middle tower + xc
    delta_tower3_y = -2 * (-COS_60 * delta_radius);
    */
    delta_tower1_x = (delta_radius + tower_adj[3]) * cos((210 + tower_adj[0]) * PI/180); // front left tower
    delta_tower1_y = (delta_radius + tower_adj[3]) * sin((210 + tower_adj[0]) * PI/180);
    delta_tower2_x = (delta_radius + tower_adj[4]) * cos((330 + tower_adj[1]) * PI/180); // front right tower
    delta_tower2_y = (delta_radius + tower_adj[4]) * sin((330 + tower_adj[1]) * PI/180);
    delta_tower3_x = (delta_radius + tower_adj[5]) * cos((90 + tower_adj[2]) * PI/180);  // back middle tower
    delta_tower3_y = (delta_radius + tower_adj[5]) * sin((90 + tower_adj[2]) * PI/180);
}
#endif
#if defined (upstream) && defined (FWRETRACT) || defined (bobc) && defined (FWRETRACT) || defined (mattsch) && defined (FWRETRACT) || defined (quikshot) && defined (FWRETRACT) || defined (ErikZalm) && defined (FWRETRACT) || defined (alromh87) && defined (FWRETRACT) || defined (hampussandberg) && defined (FWRETRACT) || defined (oysteinkrog) && defined (FWRETRACT) || defined (johnnyr) && defined (FWRETRACT) || defined (yuroller) && defined (FWRETRACT) || defined (ut7) && defined (FWRETRACT)

void retract(bool retracting, bool swapretract = false) {
    if(retracting && !retracted[active_extruder]) {
        destination[X_AXIS]=current_position[X_AXIS];
        destination[Y_AXIS]=current_position[Y_AXIS];
        destination[Z_AXIS]=current_position[Z_AXIS];
        destination[E_AXIS]=current_position[E_AXIS];
        if (swapretract) {
            current_position[E_AXIS]+=retract_length_swap/volumetric_multiplier[active_extruder];
        } else {
            current_position[E_AXIS]+=retract_length/volumetric_multiplier[active_extruder];
        }
        plan_set_e_position(current_position[E_AXIS]);
        float oldFeedrate = feedrate;
        feedrate=retract_feedrate*60;
        retracted[active_extruder]=true;
        prepare_move();
        current_position[Z_AXIS]-=retract_zlift;
#ifdef DELTA
        calculate_delta(current_position); // change cartesian kinematic to  delta kinematic;
        plan_set_position(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], current_position[E_AXIS]);
#else
        plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
#endif
        prepare_move();
        feedrate = oldFeedrate;
    } else if(!retracting && retracted[active_extruder]) {
        destination[X_AXIS]=current_position[X_AXIS];
        destination[Y_AXIS]=current_position[Y_AXIS];
        destination[Z_AXIS]=current_position[Z_AXIS];
        destination[E_AXIS]=current_position[E_AXIS];
        current_position[Z_AXIS]+=retract_zlift;
#ifdef DELTA
        calculate_delta(current_position); // change cartesian kinematic  to  delta kinematic;
        plan_set_position(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], current_position[E_AXIS]);
#else
        plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
#endif
        //prepare_move();
        if (swapretract) {
            current_position[E_AXIS]-=(retract_length_swap+retract_recover_length_swap)/volumetric_multiplier[active_extruder];
        } else {
            current_position[E_AXIS]-=(retract_length+retract_recover_length)/volumetric_multiplier[active_extruder];
        }
        plan_set_e_position(current_position[E_AXIS]);
        float oldFeedrate = feedrate;
        feedrate=retract_recover_feedrate*60;
        retracted[active_extruder]=false;
        prepare_move();
        feedrate = oldFeedrate;
    }
}
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(DELTA) )
static void extrapolate_unprobed_bed_level() {
    int half = (AUTO_BED_LEVELING_GRID_POINTS-1)/2;
    for (int y = 0; y <= half; y++) {
        for (int x = 0; x <= half; x++) {
            if (x + y < 3) continue;
            extrapolate_one_point(half-x, half-y, x>1?+1:0, y>1?+1:0);
            extrapolate_one_point(half+x, half-y, x>1?-1:0, y>1?+1:0);
            extrapolate_one_point(half-x, half+y, x>1?+1:0, y>1?-1:0);
            extrapolate_one_point(half+x, half+y, x>1?-1:0, y>1?-1:0);
        }
    }
}
#endif
#if defined (indi-RichCattell)
void deploy_z_probe() {
    feedrate = homing_feedrate[X_AXIS];
    destination[X_AXIS] = z_probe_deploy_start_location[X_AXIS];
    destination[Y_AXIS] = z_probe_deploy_start_location[Y_AXIS];
    destination[Z_AXIS] = z_probe_deploy_start_location[Z_AXIS];
    prepare_move_raw();
    feedrate = homing_feedrate[X_AXIS]/10;
    destination[X_AXIS] = z_probe_deploy_end_location[X_AXIS];
    destination[Y_AXIS] = z_probe_deploy_end_location[Y_AXIS];
    destination[Z_AXIS] = z_probe_deploy_end_location[Z_AXIS];
    prepare_move_raw();
    feedrate = homing_feedrate[X_AXIS];
    destination[X_AXIS] = z_probe_deploy_start_location[X_AXIS];
    destination[Y_AXIS] = z_probe_deploy_start_location[Y_AXIS];
    destination[Z_AXIS] = z_probe_deploy_start_location[Z_AXIS];
    prepare_move_raw();
    st_synchronize();
}
#endif
#if defined (indi-RichCattell)
void deploy_z_probe() {
    feedrate = homing_feedrate[X_AXIS];
    destination[X_AXIS] = z_probe_deploy_start_location[X_AXIS];
    destination[Y_AXIS] = z_probe_deploy_start_location[Y_AXIS];
    destination[Z_AXIS] = z_probe_deploy_start_location[Z_AXIS];
    prepare_move_raw();
    feedrate = homing_feedrate[X_AXIS]/10;
    destination[X_AXIS] = z_probe_deploy_end_location[X_AXIS];
    destination[Y_AXIS] = z_probe_deploy_end_location[Y_AXIS];
    destination[Z_AXIS] = z_probe_deploy_end_location[Z_AXIS];
    prepare_move_raw();
    feedrate = homing_feedrate[X_AXIS];
    destination[X_AXIS] = z_probe_deploy_start_location[X_AXIS];
    destination[Y_AXIS] = z_probe_deploy_start_location[Y_AXIS];
    destination[Z_AXIS] = z_probe_deploy_start_location[Z_AXIS];
    prepare_move_raw();
    st_synchronize();
}
#endif
#if defined (upstream) && defined (FWRETRACT) || defined (bobc) && defined (FWRETRACT)
    //retract
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(DELTA) )
    // Print calibration results for plotting or manual frame adjustment.
#endif
#if defined (indi-RichCattell)
void retract_z_probe() {
    feedrate = homing_feedrate[X_AXIS];
    destination[Z_AXIS] = 50;
    prepare_move_raw();
    destination[X_AXIS] = z_probe_retract_start_location[X_AXIS];
    destination[Y_AXIS] = z_probe_retract_start_location[Y_AXIS];
    destination[Z_AXIS] = z_probe_retract_start_location[Z_AXIS];
    prepare_move();
    prepare_move_raw();
    // Move the nozzle below the print surface to push the probe up.
    feedrate = homing_feedrate[Z_AXIS]/10;
    destination[X_AXIS] = z_probe_retract_end_location[X_AXIS];
    destination[Y_AXIS] = z_probe_retract_end_location[Y_AXIS];
    destination[Z_AXIS] = z_probe_retract_end_location[Z_AXIS];
    prepare_move_raw();
    feedrate = homing_feedrate[Z_AXIS];
    destination[X_AXIS] = z_probe_retract_start_location[X_AXIS];
    destination[Y_AXIS] = z_probe_retract_start_location[Y_AXIS];
    destination[Z_AXIS] = z_probe_retract_start_location[Z_AXIS];
    prepare_move_raw();
    st_synchronize();
}
#endif
#if defined (indi-RichCattell)
void retract_z_probe() {
    feedrate = homing_feedrate[X_AXIS];
    destination[Z_AXIS] = 50;
    prepare_move_raw();
    destination[X_AXIS] = z_probe_retract_start_location[X_AXIS];
    destination[Y_AXIS] = z_probe_retract_start_location[Y_AXIS];
    destination[Z_AXIS] = z_probe_retract_start_location[Z_AXIS];
    prepare_move();
    prepare_move_raw();
    // Move the nozzle below the print surface to push the probe up.
    feedrate = homing_feedrate[Z_AXIS]/10;
    destination[X_AXIS] = z_probe_retract_end_location[X_AXIS];
    destination[Y_AXIS] = z_probe_retract_end_location[Y_AXIS];
    destination[Z_AXIS] = z_probe_retract_end_location[Z_AXIS];
    prepare_move_raw();
    feedrate = homing_feedrate[Z_AXIS];
    destination[X_AXIS] = z_probe_retract_start_location[X_AXIS];
    destination[Y_AXIS] = z_probe_retract_start_location[Y_AXIS];
    destination[Z_AXIS] = z_probe_retract_start_location[Z_AXIS];
    prepare_move_raw();
    st_synchronize();
}
#endif
#if defined (upstream) || defined (bobc)
    //FWRETRACT
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(DELTA) )
static void print_bed_level() {
    for (int y = 0; y < AUTO_BED_LEVELING_GRID_POINTS; y++) {
        for (int x = 0; x < AUTO_BED_LEVELING_GRID_POINTS; x++) {
            SERIAL_PROTOCOL_F(bed_level[x][y], 2);
            SERIAL_PROTOCOLCHAR(' ');
        }
        SERIAL_EOL;
    }
}
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(DELTA) )
static void print_bed_level() {
    for (int y = 0; y < AUTO_BED_LEVELING_GRID_POINTS; y++) {
        for (int x = 0; x < AUTO_BED_LEVELING_GRID_POINTS; x++) {
            SERIAL_PROTOCOL_F(bed_level[x][y], 2);
            SERIAL_PROTOCOLCHAR(' ');
        }
        SERIAL_EOL;
    }
}
#endif
#if defined (indi-RichCattell)
float z_probe() {
    feedrate = homing_feedrate[X_AXIS];
    prepare_move_raw();
    st_synchronize();
    enable_endstops(true);
    float start_z = current_position[Z_AXIS];
    long start_steps = st_get_position(Z_AXIS);
    feedrate = homing_feedrate[Z_AXIS]/10;
    destination[Z_AXIS] = -20;
    prepare_move_raw();
    st_synchronize();
    endstops_hit_on_purpose();
    enable_endstops(false);
    long stop_steps = st_get_position(Z_AXIS);
    saved_position[X_AXIS] = float((st_get_position(X_AXIS)) / axis_steps_per_unit[X_AXIS]);
    saved_position[Y_AXIS] = float((st_get_position(Y_AXIS)) / axis_steps_per_unit[Y_AXIS]);
    saved_position[Z_AXIS] = float((st_get_position(Z_AXIS)) / axis_steps_per_unit[Z_AXIS]);
    float mm = start_z -
               float(start_steps - stop_steps) / axis_steps_per_unit[Z_AXIS];
    current_position[Z_AXIS] = mm;
    calculate_delta(current_position);
    plan_set_position(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS],
                      current_position[E_AXIS]);
    saved_position[X_AXIS] = float((st_get_position(X_AXIS)) / axis_steps_per_unit[X_AXIS]);
    saved_position[Y_AXIS] = float((st_get_position(Y_AXIS)) / axis_steps_per_unit[Y_AXIS]);
    saved_position[Z_AXIS] = float((st_get_position(Z_AXIS)) / axis_steps_per_unit[Z_AXIS]);
    feedrate = homing_feedrate[Z_AXIS];
    destination[Z_AXIS] = mm+2;
    prepare_move_raw();
    return mm;
}
#endif
#if defined (indi-RichCattell)
float z_probe() {
    feedrate = homing_feedrate[X_AXIS];
    prepare_move_raw();
    st_synchronize();
    enable_endstops(true);
    float start_z = current_position[Z_AXIS];
    long start_steps = st_get_position(Z_AXIS);
    feedrate = homing_feedrate[Z_AXIS]/10;
    destination[Z_AXIS] = -20;
    prepare_move_raw();
    st_synchronize();
    endstops_hit_on_purpose();
    enable_endstops(false);
    long stop_steps = st_get_position(Z_AXIS);
    saved_position[X_AXIS] = float((st_get_position(X_AXIS)) / axis_steps_per_unit[X_AXIS]);
    saved_position[Y_AXIS] = float((st_get_position(Y_AXIS)) / axis_steps_per_unit[Y_AXIS]);
    saved_position[Z_AXIS] = float((st_get_position(Z_AXIS)) / axis_steps_per_unit[Z_AXIS]);
    float mm = start_z -
               float(start_steps - stop_steps) / axis_steps_per_unit[Z_AXIS];
    current_position[Z_AXIS] = mm;
    calculate_delta(current_position);
    plan_set_position(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS],
                      current_position[E_AXIS]);
    saved_position[X_AXIS] = float((st_get_position(X_AXIS)) / axis_steps_per_unit[X_AXIS]);
    saved_position[Y_AXIS] = float((st_get_position(Y_AXIS)) / axis_steps_per_unit[Y_AXIS]);
    saved_position[Z_AXIS] = float((st_get_position(Z_AXIS)) / axis_steps_per_unit[Z_AXIS]);
    feedrate = homing_feedrate[Z_AXIS];
    destination[Z_AXIS] = mm+2;
    prepare_move_raw();
    return mm;
}
#endif
#if defined (upstream) && defined (Z_PROBE_SLED) || defined (mattsch) && defined (Z_PROBE_SLED) || defined (ErikZalm) && defined (Z_PROBE_SLED) || defined (hampussandberg) && defined (Z_PROBE_SLED) || defined (oysteinkrog) && defined (Z_PROBE_SLED) || defined (yuroller) && defined (Z_PROBE_SLED) || defined (ut7) && defined (Z_PROBE_SLED)
    //
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(DELTA) )
    // Reset calibration results to zero.
#endif
#if defined (indi-RichCattell)
void calibrate_print_surface(float z_offset) {
    float probe_bed_z, probe_z, probe_h, probe_l;
    int probe_count;
    for (int y = 3; y >= -3; y--) {
        int dir = y % 2 ? -1 : 1;
        for (int x = -3*dir; x != 4*dir; x += dir) {
            if (x*x + y*y < 11) {
                destination[X_AXIS] = AUTOLEVEL_GRID * x - z_probe_offset[X_AXIS];
                destination[Y_AXIS] = AUTOLEVEL_GRID * y - z_probe_offset[Y_AXIS];
                probe_count = 0;
                probe_z = -100;
                probe_h = -100;
                probe_l = 100;
                do {
                    probe_bed_z = probe_z;
                    probe_z = z_probe() + z_offset;
                    if (probe_z > probe_h) probe_h = probe_z;
                    if (probe_z < probe_l) probe_l = probe_z;
                    probe_count ++;
                } while ((probe_z != probe_bed_z) and (probe_count < 21));
                bed_level[x+3][3-y] = probe_bed_z;
            } else {
                bed_level[x+3][3-y] = 0.0;
            }
        }
        // For unprobed positions just copy nearest neighbor.
        if (abs(y) >= 3) {
            bed_level[1][3-y] = bed_level[2][3-y];
            bed_level[5][3-y] = bed_level[4][3-y];
        }
        if (abs(y) >=2) {
            bed_level[0][3-y] = bed_level[1][3-y];
            bed_level[6][3-y] = bed_level[5][3-y];
        }
        // Print calibration results for manual frame adjustment.
        for (int x = -3; x <= 3; x++) {
            SERIAL_PROTOCOL_F(bed_level[x+3][3-y], 3);
            SERIAL_PROTOCOLPGM(" ");
        }
        SERIAL_ECHOLN("");
    }
}
#endif
#if defined (indi-RichCattell)
void calibrate_print_surface(float z_offset) {
    float probe_bed_z, probe_z, probe_h, probe_l;
    int probe_count;
    for (int y = 3; y >= -3; y--) {
        int dir = y % 2 ? -1 : 1;
        for (int x = -3*dir; x != 4*dir; x += dir) {
            if (x*x + y*y < 11) {
                destination[X_AXIS] = AUTOLEVEL_GRID * x - z_probe_offset[X_AXIS];
                destination[Y_AXIS] = AUTOLEVEL_GRID * y - z_probe_offset[Y_AXIS];
                probe_count = 0;
                probe_z = -100;
                probe_h = -100;
                probe_l = 100;
                do {
                    probe_bed_z = probe_z;
                    probe_z = z_probe() + z_offset;
                    if (probe_z > probe_h) probe_h = probe_z;
                    if (probe_z < probe_l) probe_l = probe_z;
                    probe_count ++;
                } while ((probe_z != probe_bed_z) and (probe_count < 21));
                bed_level[x+3][3-y] = probe_bed_z;
            } else {
                bed_level[x+3][3-y] = 0.0;
            }
        }
        // For unprobed positions just copy nearest neighbor.
        if (abs(y) >= 3) {
            bed_level[1][3-y] = bed_level[2][3-y];
            bed_level[5][3-y] = bed_level[4][3-y];
        }
        if (abs(y) >=2) {
            bed_level[0][3-y] = bed_level[1][3-y];
            bed_level[6][3-y] = bed_level[5][3-y];
        }
        // Print calibration results for manual frame adjustment.
        for (int x = -3; x <= 3; x++) {
            SERIAL_PROTOCOL_F(bed_level[x+3][3-y], 3);
            SERIAL_PROTOCOLPGM(" ");
        }
        SERIAL_ECHOLN("");
    }
}
#endif
#if defined (upstream) && defined (Z_PROBE_SLED) || defined (mattsch) && defined (Z_PROBE_SLED) || defined (ErikZalm) && defined (Z_PROBE_SLED) || defined (hampussandberg) && defined (Z_PROBE_SLED) || defined (oysteinkrog) && defined (Z_PROBE_SLED) || defined (yuroller) && defined (Z_PROBE_SLED) || defined (ut7) && defined (Z_PROBE_SLED)
    // Method to dock/undock a sled designed by Charles Bell.
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(DELTA) )
void reset_bed_level() {
    for (int y = 0; y < AUTO_BED_LEVELING_GRID_POINTS; y++) {
        for (int x = 0; x < AUTO_BED_LEVELING_GRID_POINTS; x++) {
            bed_level[x][y] = 0.0;
        }
    }
}
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(DELTA) )
void reset_bed_level() {
    for (int y = 0; y < AUTO_BED_LEVELING_GRID_POINTS; y++) {
        for (int x = 0; x < AUTO_BED_LEVELING_GRID_POINTS; x++) {
            bed_level[x][y] = 0.0;
        }
    }
}
#endif
#if defined (indi-RichCattell)
float probe_bed(float x, float y) {
    //Probe bed at specified location and return z height of bed
    float probe_bed_z, probe_z, probe_h, probe_l;
    int probe_count;
//  feedrate = homing_feedrate[Z_AXIS];
    destination[X_AXIS] = x - z_probe_offset[X_AXIS];
    destination[Y_AXIS] = y - z_probe_offset[Y_AXIS];
    destination[Z_AXIS] = bed_level_c - z_probe_offset[Z_AXIS] + 3;
    prepare_move();
    st_synchronize();
    probe_count = 0;
    probe_z = -100;
    probe_h = -100;
    probe_l = 100;
    do {
        probe_bed_z = probe_z;
        probe_z = z_probe() + z_probe_offset[Z_AXIS];
        if (probe_z > probe_h) probe_h = probe_z;
        if (probe_z < probe_l) probe_l = probe_z;
        probe_count ++;
        //SERIAL_PROTOCOL_F(probe_z,3);
        //SERIAL_ECHO(" ");
    } while ((probe_z != probe_bed_z) and (probe_count < 21));
    //SERIAL_ECHOLN("");
    /*
    if (probe_count > 2)
      {
      SERIAL_ECHO("Z-Probe error: ");
      SERIAL_PROTOCOL_F(probe_h - probe_l, 3);
      SERIAL_ECHO("mm in ");
      SERIAL_ECHO(probe_count);
      SERIAL_ECHO(" probes");
      if (probe_count == 20)
        {
        SERIAL_ECHO(" (unable to get 2x consistant probes!)");
        }
      SERIAL_ECHOLN("");
      }
      */
    /*
    SERIAL_ECHO("Bed Z-Height at X:");
    SERIAL_ECHO(x);
    SERIAL_ECHO(" Y:");
    SERIAL_ECHO(y);
    SERIAL_ECHO(" = ");
    SERIAL_PROTOCOL_F(probe_bed_z, 4);
    SERIAL_ECHOLN("");
    */
    return probe_bed_z;
}
#endif
#if defined (indi-RichCattell)
float probe_bed(float x, float y) {
    //Probe bed at specified location and return z height of bed
    float probe_bed_z, probe_z, probe_h, probe_l;
    int probe_count;
//  feedrate = homing_feedrate[Z_AXIS];
    destination[X_AXIS] = x - z_probe_offset[X_AXIS];
    destination[Y_AXIS] = y - z_probe_offset[Y_AXIS];
    destination[Z_AXIS] = bed_level_c - z_probe_offset[Z_AXIS] + 3;
    prepare_move();
    st_synchronize();
    probe_count = 0;
    probe_z = -100;
    probe_h = -100;
    probe_l = 100;
    do {
        probe_bed_z = probe_z;
        probe_z = z_probe() + z_probe_offset[Z_AXIS];
        if (probe_z > probe_h) probe_h = probe_z;
        if (probe_z < probe_l) probe_l = probe_z;
        probe_count ++;
        //SERIAL_PROTOCOL_F(probe_z,3);
        //SERIAL_ECHO(" ");
    } while ((probe_z != probe_bed_z) and (probe_count < 21));
    //SERIAL_ECHOLN("");
    /*
    if (probe_count > 2)
      {
      SERIAL_ECHO("Z-Probe error: ");
      SERIAL_PROTOCOL_F(probe_h - probe_l, 3);
      SERIAL_ECHO("mm in ");
      SERIAL_ECHO(probe_count);
      SERIAL_ECHO(" probes");
      if (probe_count == 20)
        {
        SERIAL_ECHO(" (unable to get 2x consistant probes!)");
        }
      SERIAL_ECHOLN("");
      }
      */
    /*
    SERIAL_ECHO("Bed Z-Height at X:");
    SERIAL_ECHO(x);
    SERIAL_ECHO(" Y:");
    SERIAL_ECHO(y);
    SERIAL_ECHO(" = ");
    SERIAL_PROTOCOL_F(probe_bed_z, 4);
    SERIAL_ECHOLN("");
    */
    return probe_bed_z;
}
#endif
#if defined (upstream) && defined (Z_PROBE_SLED) || defined (mattsch) && defined (Z_PROBE_SLED) || defined (ErikZalm) && defined (Z_PROBE_SLED) || defined (hampussandberg) && defined (Z_PROBE_SLED) || defined (oysteinkrog) && defined (Z_PROBE_SLED) || defined (yuroller) && defined (Z_PROBE_SLED) || defined (ut7) && defined (Z_PROBE_SLED)
    //
#endif
#if defined (marlin4Due) && ENABLED(ENABLE_AUTO_BED_LEVELING)
    // DELTA
#endif
#if defined (indi-RichCattell)
float z_probe_accuracy() {
    //Perform z-probe accuracy test
    float probe_h[7];
    float probe_l[7];
    float range_h = 0, range_l = 0;
    for(int x=0; x < 7; x++) {
        probe_h[x] = -100;
        probe_l[x] = 100;
    }
    // probe test loop
    for(int x=0; x<3; x++) {
        bed_probe_all();
        if (bed_level_c > probe_h[0]) probe_h[0] = bed_level_c;
        if (bed_level_c < probe_l[0]) probe_l[0] = bed_level_c;
        if (bed_level_z > probe_h[1]) probe_h[1] = bed_level_z;
        if (bed_level_z < probe_l[1]) probe_l[1] = bed_level_z;
        if (bed_level_oy > probe_h[2]) probe_h[2] = bed_level_oy;
        if (bed_level_oy < probe_l[2]) probe_l[2] = bed_level_oy;
        if (bed_level_x > probe_h[3]) probe_h[3] = bed_level_x;
        if (bed_level_x < probe_l[3]) probe_l[3] = bed_level_x;
        if (bed_level_oz > probe_h[4]) probe_h[4] = bed_level_oz;
        if (bed_level_oz < probe_l[4]) probe_l[4] = bed_level_oz;
        if (bed_level_y > probe_h[5]) probe_h[5] = bed_level_y;
        if (bed_level_y < probe_l[5]) probe_l[5] = bed_level_y;
        if (bed_level_ox > probe_h[6]) probe_h[6] = bed_level_ox;
        if (bed_level_ox < probe_l[6]) probe_l[6] = bed_level_ox;
    }
    for(int x=0; x < 7; x++) {
        if (probe_h[x] - probe_l[x] > range_h) range_h = probe_h[x] - probe_l[x];
        if (probe_h[x] - probe_l[x] < range_l) range_l = probe_h[x] - probe_l[x];
    }
    return range_h - range_l;
}
#endif
#if defined (indi-RichCattell)
float z_probe_accuracy() {
    //Perform z-probe accuracy test
    float probe_h[7];
    float probe_l[7];
    float range_h = 0, range_l = 0;
    for(int x=0; x < 7; x++) {
        probe_h[x] = -100;
        probe_l[x] = 100;
    }
    // probe test loop
    for(int x=0; x<3; x++) {
        bed_probe_all();
        if (bed_level_c > probe_h[0]) probe_h[0] = bed_level_c;
        if (bed_level_c < probe_l[0]) probe_l[0] = bed_level_c;
        if (bed_level_z > probe_h[1]) probe_h[1] = bed_level_z;
        if (bed_level_z < probe_l[1]) probe_l[1] = bed_level_z;
        if (bed_level_oy > probe_h[2]) probe_h[2] = bed_level_oy;
        if (bed_level_oy < probe_l[2]) probe_l[2] = bed_level_oy;
        if (bed_level_x > probe_h[3]) probe_h[3] = bed_level_x;
        if (bed_level_x < probe_l[3]) probe_l[3] = bed_level_x;
        if (bed_level_oz > probe_h[4]) probe_h[4] = bed_level_oz;
        if (bed_level_oz < probe_l[4]) probe_l[4] = bed_level_oz;
        if (bed_level_y > probe_h[5]) probe_h[5] = bed_level_y;
        if (bed_level_y < probe_l[5]) probe_l[5] = bed_level_y;
        if (bed_level_ox > probe_h[6]) probe_h[6] = bed_level_ox;
        if (bed_level_ox < probe_l[6]) probe_l[6] = bed_level_ox;
    }
    for(int x=0; x < 7; x++) {
        if (probe_h[x] - probe_l[x] > range_h) range_h = probe_h[x] - probe_l[x];
        if (probe_h[x] - probe_l[x] < range_l) range_l = probe_h[x] - probe_l[x];
    }
    return range_h - range_l;
}
#endif
#if defined (upstream) && defined (Z_PROBE_SLED) || defined (mattsch) && defined (Z_PROBE_SLED) || defined (ErikZalm) && defined (Z_PROBE_SLED) || defined (hampussandberg) && defined (Z_PROBE_SLED) || defined (oysteinkrog) && defined (Z_PROBE_SLED) || defined (yuroller) && defined (Z_PROBE_SLED) || defined (ut7) && defined (Z_PROBE_SLED)
    // dock[in]     If true, move to MAX_X and engage the electromagnet
#endif
#if defined (marlin4Due)
    // ENABLE_AUTO_BED_LEVELING
#endif
#if defined (indi-RichCattell)
void bed_probe_all() {
    //Probe all bed positions & store carriage positions
    bed_level_c = probe_bed(0.0, 0.0);
    save_carriage_positions(0);
    bed_level_z = probe_bed(0.0, bed_radius);
    save_carriage_positions(1);
    bed_level_oy = probe_bed(-SIN_60 * bed_radius, COS_60 * bed_radius);
    save_carriage_positions(2);
    bed_level_x = probe_bed(-SIN_60 * bed_radius, -COS_60 * bed_radius);
    save_carriage_positions(3);
    bed_level_oz = probe_bed(0.0, -bed_radius);
    save_carriage_positions(4);
    bed_level_y = probe_bed(SIN_60 * bed_radius, -COS_60 * bed_radius);
    save_carriage_positions(5);
    bed_level_ox = probe_bed(SIN_60 * bed_radius, COS_60 * bed_radius);
    save_carriage_positions(6);
}
#endif
#if defined (indi-RichCattell)
void bed_probe_all() {
    //Probe all bed positions & store carriage positions
    bed_level_c = probe_bed(0.0, 0.0);
    save_carriage_positions(0);
    bed_level_z = probe_bed(0.0, bed_radius);
    save_carriage_positions(1);
    bed_level_oy = probe_bed(-SIN_60 * bed_radius, COS_60 * bed_radius);
    save_carriage_positions(2);
    bed_level_x = probe_bed(-SIN_60 * bed_radius, -COS_60 * bed_radius);
    save_carriage_positions(3);
    bed_level_oz = probe_bed(0.0, -bed_radius);
    save_carriage_positions(4);
    bed_level_y = probe_bed(SIN_60 * bed_radius, -COS_60 * bed_radius);
    save_carriage_positions(5);
    bed_level_ox = probe_bed(SIN_60 * bed_radius, COS_60 * bed_radius);
    save_carriage_positions(6);
}
#endif
#if defined (upstream) && defined (Z_PROBE_SLED) || defined (mattsch) && defined (Z_PROBE_SLED) || defined (ErikZalm) && defined (Z_PROBE_SLED) || defined (hampussandberg) && defined (Z_PROBE_SLED) || defined (oysteinkrog) && defined (Z_PROBE_SLED) || defined (yuroller) && defined (Z_PROBE_SLED) || defined (ut7) && defined (Z_PROBE_SLED)
    // offset[in]   The additional distance to move to adjust docking location
#endif
#if defined (marlin4Due) && (!defined (SLED_DOCKING_OFFSET) && ENABLED(Z_PROBE_SLED) )
    #define SLED_DOCKING_OFFSET 0
#endif
#if defined (indi-RichCattell)
void calibration_report() {
    //Display Report
    SERIAL_ECHOLN("\tZ-Tower\t\t\tEndstop Offsets");
    SERIAL_ECHO("\t");
    SERIAL_PROTOCOL_F(bed_level_z, 4);
    SERIAL_ECHOPAIR("\t\t\tX:",endstop_adj[0]);
    SERIAL_ECHOPAIR(" Y:",endstop_adj[1]);
    SERIAL_ECHOPAIR(" Z:",endstop_adj[2]);
    SERIAL_ECHOLN("");
    SERIAL_PROTOCOL_F(bed_level_oy, 4);
    SERIAL_PROTOCOLPGM("\t\t");
    SERIAL_PROTOCOL_F(bed_level_ox, 4);
    SERIAL_ECHOLN("\t\tTower Position Adjust");
    SERIAL_PROTOCOLPGM("\t");
    SERIAL_PROTOCOL_F(bed_level_c, 4);
    SERIAL_ECHOPAIR("\t\t\tA:",tower_adj[0]);
    SERIAL_ECHOPAIR(" B:",tower_adj[1]);
    SERIAL_ECHOPAIR(" C:",tower_adj[2]);
    SERIAL_ECHOLN("");
    SERIAL_PROTOCOL_F(bed_level_x, 4);
    SERIAL_PROTOCOLPGM("\t\t");
    SERIAL_PROTOCOL_F(bed_level_y, 4);
    SERIAL_ECHOPAIR("\t\tI:",tower_adj[3]);
    SERIAL_ECHOPAIR(" J:",tower_adj[4]);
    SERIAL_ECHOPAIR(" K:",tower_adj[5]);
    SERIAL_ECHOLN("");
    SERIAL_PROTOCOLPGM("\t");
    SERIAL_PROTOCOL_F(bed_level_oz, 4);
    SERIAL_PROTOCOLPGM("\t\t\tDelta Radius: ");
    SERIAL_PROTOCOL_F(delta_radius, 4);
    SERIAL_ECHOLN("");
    SERIAL_PROTOCOLPGM("X-Tower\t\tY-Tower\t\tDiag Rod: ");
    SERIAL_PROTOCOL_F(delta_diagonal_rod, 4);
    SERIAL_ECHOLN("");
}
#endif
#if defined (indi-RichCattell)
void calibration_report() {
    //Display Report
    SERIAL_ECHOLN("\tZ-Tower\t\t\tEndstop Offsets");
    SERIAL_ECHO("\t");
    SERIAL_PROTOCOL_F(bed_level_z, 4);
    SERIAL_ECHOPAIR("\t\t\tX:",endstop_adj[0]);
    SERIAL_ECHOPAIR(" Y:",endstop_adj[1]);
    SERIAL_ECHOPAIR(" Z:",endstop_adj[2]);
    SERIAL_ECHOLN("");
    SERIAL_PROTOCOL_F(bed_level_oy, 4);
    SERIAL_PROTOCOLPGM("\t\t");
    SERIAL_PROTOCOL_F(bed_level_ox, 4);
    SERIAL_ECHOLN("\t\tTower Position Adjust");
    SERIAL_PROTOCOLPGM("\t");
    SERIAL_PROTOCOL_F(bed_level_c, 4);
    SERIAL_ECHOPAIR("\t\t\tA:",tower_adj[0]);
    SERIAL_ECHOPAIR(" B:",tower_adj[1]);
    SERIAL_ECHOPAIR(" C:",tower_adj[2]);
    SERIAL_ECHOLN("");
    SERIAL_PROTOCOL_F(bed_level_x, 4);
    SERIAL_PROTOCOLPGM("\t\t");
    SERIAL_PROTOCOL_F(bed_level_y, 4);
    SERIAL_ECHOPAIR("\t\tI:",tower_adj[3]);
    SERIAL_ECHOPAIR(" J:",tower_adj[4]);
    SERIAL_ECHOPAIR(" K:",tower_adj[5]);
    SERIAL_ECHOLN("");
    SERIAL_PROTOCOLPGM("\t");
    SERIAL_PROTOCOL_F(bed_level_oz, 4);
    SERIAL_PROTOCOLPGM("\t\t\tDelta Radius: ");
    SERIAL_PROTOCOL_F(delta_radius, 4);
    SERIAL_ECHOLN("");
    SERIAL_PROTOCOLPGM("X-Tower\t\tY-Tower\t\tDiag Rod: ");
    SERIAL_PROTOCOL_F(delta_diagonal_rod, 4);
    SERIAL_ECHOLN("");
}
#endif
#if defined (upstream) && defined (Z_PROBE_SLED) || defined (mattsch) && defined (Z_PROBE_SLED) || defined (ErikZalm) && defined (Z_PROBE_SLED) || defined (hampussandberg) && defined (Z_PROBE_SLED) || defined (oysteinkrog) && defined (Z_PROBE_SLED) || defined (yuroller) && defined (Z_PROBE_SLED) || defined (ut7) && defined (Z_PROBE_SLED)
    //
#endif
#if defined (marlin4Due) && ENABLED(Z_PROBE_SLED)
    /**
    * Method to dock/undock a sled designed by Charles Bell.
    *
    * dock[in]     If true, move to MAX_X and engage the electromagnet
    * offset[in]   The additional distance to move to adjust docking location
    */
#endif
#if defined (indi-RichCattell)
void save_carriage_positions(int position_num) {
    for(int8_t i=0; i < NUM_AXIS; i++) {
        saved_positions[position_num][i] = saved_position[i];
    }
}
#endif
#if defined (upstream) && defined (Z_PROBE_SLED) || defined (mattsch) && defined (Z_PROBE_SLED) || defined (ErikZalm) && defined (Z_PROBE_SLED) || defined (hampussandberg) && defined (Z_PROBE_SLED) || defined (oysteinkrog) && defined (Z_PROBE_SLED) || defined (yuroller) && defined (Z_PROBE_SLED) || defined (ut7) && defined (Z_PROBE_SLED) || defined (marlin4Due) && ENABLED(Z_PROBE_SLED)

static void dock_sled(bool dock, int offset=0) {
    int z_loc;
    if (!((axis_known_position[X_AXIS]) && (axis_known_position[Y_AXIS]))) {
        LCD_MESSAGEPGM(MSG_POSITION_UNKNOWN);
        SERIAL_ECHO_START;
        SERIAL_ECHOLNPGM(MSG_POSITION_UNKNOWN);
        return;
    }
    if (dock) {
        do_blocking_move_to(X_MAX_POS + SLED_DOCKING_OFFSET + offset,
                            current_position[Y_AXIS],
                            current_position[Z_AXIS]);
        // turn off magnet
        digitalWrite(SERVO0_PIN, LOW);
    } else {
        if (current_position[Z_AXIS] < (Z_RAISE_BEFORE_PROBING + 5))
            z_loc = Z_RAISE_BEFORE_PROBING;
        else
            z_loc = current_position[Z_AXIS];
        do_blocking_move_to(X_MAX_POS + SLED_DOCKING_OFFSET + offset,
                            Y_PROBE_OFFSET_FROM_EXTRUDER, z_loc);
        // turn on magnet
        digitalWrite(SERVO0_PIN, HIGH);
    }
}
#endif
#if defined (indi-RichCattell)
void home_delta_axis() {
    saved_feedrate = feedrate;
    saved_feedmultiply = feedmultiply;
    feedmultiply = 100;
    previous_millis_cmd = millis();
    enable_endstops(true);
    for(int8_t i=0; i < NUM_AXIS; i++) {
        destination[i] = current_position[i];
    }
    feedrate = 0.0;
    // Move all carriages up together until the first endstop is hit.
    current_position[X_AXIS] = 0;
    current_position[Y_AXIS] = 0;
    current_position[Z_AXIS] = 0;
    plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
    destination[X_AXIS] = 3 * max_length[Z_AXIS];
    destination[Y_AXIS] = 3 * max_length[Z_AXIS];
    destination[Z_AXIS] = 3 * max_length[Z_AXIS];
    feedrate = 1.732 * homing_feedrate[X_AXIS];
    plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate/60, active_extruder);
    st_synchronize();
    endstops_hit_on_purpose();
    current_position[X_AXIS] = destination[X_AXIS];
    current_position[Y_AXIS] = destination[Y_AXIS];
    current_position[Z_AXIS] = destination[Z_AXIS];
    // take care of back off and rehome now we are all at the top
    HOMEAXIS(X);
    HOMEAXIS(Y);
    HOMEAXIS(Z);
    calculate_delta(current_position);
    plan_set_position(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], current_position[E_AXIS]);
#ifdef ENDSTOPS_ONLY_FOR_HOMING
    enable_endstops(false);
#endif
    feedrate = saved_feedrate;
    feedmultiply = saved_feedmultiply;
    previous_millis_cmd = millis();
    endstops_hit_on_purpose();
}
#endif
#if defined (marlin4Due)
    // Z_PROBE_SLED
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)

void process_commands() {
    unsigned long codenum; //throw away variable
    char *starpos = NULL;
#ifdef ENABLE_AUTO_BED_LEVELING
    float x_tmp, y_tmp, z_tmp, real_z;
#endif
    if(code_seen('G')) {
        switch((int)code_value()) {
        case 0: // G0 -> G1
        case 1: // G1
            if(Stopped == false) {
                get_coordinates(); // For X Y Z E F
#ifdef FWRETRACT
                if(autoretract_enabled)
                    if( !(code_seen('X') || code_seen('Y') || code_seen('Z')) && code_seen('E')) {
                        float echange=destination[E_AXIS]-current_position[E_AXIS];
                        if((echange<-MIN_RETRACT && !retracted) || (echange>MIN_RETRACT && retracted)) { //move appears to be an attempt to retract or recover
                            current_position[E_AXIS] = destination[E_AXIS]; //hide the slicer-generated retract/recover from calculations
                            plan_set_e_position(current_position[E_AXIS]); //AND from the planner
                            retract(!retracted);
                            return;
                        }
                    }
#endif //FWRETRACT
                prepare_move();
                //ClearToSend();
            }
            break;
#ifndef SCARA //disable arc support
        case 2: // G2  - CW ARC
            if(Stopped == false) {
                get_arc_coordinates();
                prepare_arc_move(true);
            }
            break;
        case 3: // G3  - CCW ARC
            if(Stopped == false) {
                get_arc_coordinates();
                prepare_arc_move(false);
            }
            break;
#endif
        case 4: // G4 dwell
            LCD_MESSAGEPGM(MSG_DWELL);
            codenum = 0;
            if(code_seen('P')) codenum = code_value(); // milliseconds to wait
            if(code_seen('S')) codenum = code_value() * 1000; // seconds to wait
            st_synchronize();
            codenum += millis();  // keep track of when we started waiting
            previous_millis_cmd = millis();
            while(millis() < codenum) {
                manage_heater();
                manage_inactivity();
                lcd_update();
            }
            break;
#ifdef FWRETRACT
        case 10: // G10 retract
#if EXTRUDERS > 1
            retracted_swap[active_extruder]=(code_seen('S') && code_value_long() == 1); // checks for swap retract argument
            retract(true,retracted_swap[active_extruder]);
#else
            retract(true);
#endif
            break;
        case 11: // G11 retract_recover
#if EXTRUDERS > 1
            retract(false,retracted_swap[active_extruder]);
#else
            retract(false);
#endif
            break;
#endif //FWRETRACT
        case 28: //G28 Home all Axis one at a time
#ifdef ENABLE_AUTO_BED_LEVELING
            plan_bed_level_matrix.set_to_identity();  //Reset the plane ("erase" all leveling data)
#endif //ENABLE_AUTO_BED_LEVELING
            saved_feedrate = feedrate;
            saved_feedmultiply = feedmultiply;
            feedmultiply = 100;
            previous_millis_cmd = millis();
            enable_endstops(true);
            for(int8_t i=0; i < NUM_AXIS; i++) {
                destination[i] = current_position[i];
            }
            feedrate = 0.0;
#ifdef DELTA
            // A delta can only safely home all axis at the same time
            // all axis have to home at the same time
            // Move all carriages up together until the first endstop is hit.
            current_position[X_AXIS] = 0;
            current_position[Y_AXIS] = 0;
            current_position[Z_AXIS] = 0;
            plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
            destination[X_AXIS] = 3 * Z_MAX_LENGTH;
            destination[Y_AXIS] = 3 * Z_MAX_LENGTH;
            destination[Z_AXIS] = 3 * Z_MAX_LENGTH;
            feedrate = 1.732 * homing_feedrate[X_AXIS];
            plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate/60, active_extruder);
            st_synchronize();
            endstops_hit_on_purpose();
            current_position[X_AXIS] = destination[X_AXIS];
            current_position[Y_AXIS] = destination[Y_AXIS];
            current_position[Z_AXIS] = destination[Z_AXIS];
            // take care of back off and rehome now we are all at the top
            HOMEAXIS(X);
            HOMEAXIS(Y);
            HOMEAXIS(Z);
            calculate_delta(current_position);
            plan_set_position(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], current_position[E_AXIS]);
#else // NOT DELTA
            home_all_axis = !((code_seen(axis_codes[X_AXIS])) || (code_seen(axis_codes[Y_AXIS])) || (code_seen(axis_codes[Z_AXIS])));
#if Z_HOME_DIR > 0                      // If homing away from BED do Z first
            if((home_all_axis) || (code_seen(axis_codes[Z_AXIS]))) {
                HOMEAXIS(Z);
            }
#endif
#ifdef QUICK_HOME
            if((home_all_axis)||( code_seen(axis_codes[X_AXIS]) && code_seen(axis_codes[Y_AXIS])) ) { //first diagonal move
                current_position[X_AXIS] = 0;
                current_position[Y_AXIS] = 0;
#ifndef DUAL_X_CARRIAGE
                int x_axis_home_dir = home_dir(X_AXIS);
#else
                int x_axis_home_dir = x_home_dir(active_extruder);
                extruder_duplication_enabled = false;
#endif
                plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
                destination[X_AXIS] = 1.5 * max_length(X_AXIS) * x_axis_home_dir;
                destination[Y_AXIS] = 1.5 * max_length(Y_AXIS) * home_dir(Y_AXIS);
                feedrate = homing_feedrate[X_AXIS];
                if(homing_feedrate[Y_AXIS]<feedrate)
                    feedrate = homing_feedrate[Y_AXIS];
                if (max_length(X_AXIS) > max_length(Y_AXIS)) {
                    feedrate *= sqrt(pow(max_length(Y_AXIS) / max_length(X_AXIS), 2) + 1);
                } else {
                    feedrate *= sqrt(pow(max_length(X_AXIS) / max_length(Y_AXIS), 2) + 1);
                }
                plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate/60, active_extruder);
                st_synchronize();
                axis_is_at_home(X_AXIS);
                axis_is_at_home(Y_AXIS);
                plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
                destination[X_AXIS] = current_position[X_AXIS];
                destination[Y_AXIS] = current_position[Y_AXIS];
                plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate/60, active_extruder);
                feedrate = 0.0;
                st_synchronize();
                endstops_hit_on_purpose();
                current_position[X_AXIS] = destination[X_AXIS];
                current_position[Y_AXIS] = destination[Y_AXIS];
#ifndef SCARA
                current_position[Z_AXIS] = destination[Z_AXIS];
#endif
            }
#endif
            if((home_all_axis) || (code_seen(axis_codes[X_AXIS]))) {
#ifdef DUAL_X_CARRIAGE
                int tmp_extruder = active_extruder;
                extruder_duplication_enabled = false;
                active_extruder = !active_extruder;
                HOMEAXIS(X);
                inactive_extruder_x_pos = current_position[X_AXIS];
                active_extruder = tmp_extruder;
                HOMEAXIS(X);
                // reset state used by the different modes
                memcpy(raised_parked_position, current_position, sizeof(raised_parked_position));
                delayed_move_time = 0;
                active_extruder_parked = true;
#else
                HOMEAXIS(X);
#endif
            }
            if((home_all_axis) || (code_seen(axis_codes[Y_AXIS]))) {
                HOMEAXIS(Y);
            }
            if(code_seen(axis_codes[X_AXIS])) {
                if(code_value_long() != 0) {
#ifdef SCARA
                    current_position[X_AXIS]=code_value();
#else
                    current_position[X_AXIS]=code_value()+add_homing[X_AXIS];
#endif
                }
            }
            if(code_seen(axis_codes[Y_AXIS])) {
                if(code_value_long() != 0) {
#ifdef SCARA
                    current_position[Y_AXIS]=code_value();
#else
                    current_position[Y_AXIS]=code_value()+add_homing[Y_AXIS];
#endif
                }
            }
#if Z_HOME_DIR < 0                      // If homing towards BED do Z last
#ifndef Z_SAFE_HOMING
            if((home_all_axis) || (code_seen(axis_codes[Z_AXIS]))) {
#if defined (Z_RAISE_BEFORE_HOMING) && (Z_RAISE_BEFORE_HOMING > 0)
                destination[Z_AXIS] = Z_RAISE_BEFORE_HOMING * home_dir(Z_AXIS) * (-1);    // Set destination away from bed
                feedrate = max_feedrate[Z_AXIS];
                plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate, active_extruder);
                st_synchronize();
#endif
                HOMEAXIS(Z);
            }
#else                      // Z Safe mode activated.
            if(home_all_axis) {
                destination[X_AXIS] = round(Z_SAFE_HOMING_X_POINT - X_PROBE_OFFSET_FROM_EXTRUDER);
                destination[Y_AXIS] = round(Z_SAFE_HOMING_Y_POINT - Y_PROBE_OFFSET_FROM_EXTRUDER);
                destination[Z_AXIS] = Z_RAISE_BEFORE_HOMING * home_dir(Z_AXIS) * (-1);    // Set destination away from bed
                feedrate = XY_TRAVEL_SPEED/60;
                current_position[Z_AXIS] = 0;
                plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
                plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate, active_extruder);
                st_synchronize();
                current_position[X_AXIS] = destination[X_AXIS];
                current_position[Y_AXIS] = destination[Y_AXIS];
                HOMEAXIS(Z);
            }
            // Let's see if X and Y are homed and probe is inside bed area.
            if(code_seen(axis_codes[Z_AXIS])) {
                if ( (axis_known_position[X_AXIS]) && (axis_known_position[Y_AXIS]) \
                        && (current_position[X_AXIS]+X_PROBE_OFFSET_FROM_EXTRUDER >= X_MIN_POS) \
                        && (current_position[X_AXIS]+X_PROBE_OFFSET_FROM_EXTRUDER <= X_MAX_POS) \
                        && (current_position[Y_AXIS]+Y_PROBE_OFFSET_FROM_EXTRUDER >= Y_MIN_POS) \
                        && (current_position[Y_AXIS]+Y_PROBE_OFFSET_FROM_EXTRUDER <= Y_MAX_POS)) {
                    current_position[Z_AXIS] = 0;
                    plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
                    destination[Z_AXIS] = Z_RAISE_BEFORE_HOMING * home_dir(Z_AXIS) * (-1);    // Set destination away from bed
                    feedrate = max_feedrate[Z_AXIS];
                    plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate, active_extruder);
                    st_synchronize();
                    HOMEAXIS(Z);
                } else if (!((axis_known_position[X_AXIS]) && (axis_known_position[Y_AXIS]))) {
                    LCD_MESSAGEPGM(MSG_POSITION_UNKNOWN);
                    SERIAL_ECHO_START;
                    SERIAL_ECHOLNPGM(MSG_POSITION_UNKNOWN);
                } else {
                    LCD_MESSAGEPGM(MSG_ZPROBE_OUT);
                    SERIAL_ECHO_START;
                    SERIAL_ECHOLNPGM(MSG_ZPROBE_OUT);
                }
            }
#endif
#endif
            if(code_seen(axis_codes[Z_AXIS])) {
                if(code_value_long() != 0) {
                    current_position[Z_AXIS]=code_value()+add_homing[Z_AXIS];
                }
            }
#ifdef ENABLE_AUTO_BED_LEVELING
            if((home_all_axis) || (code_seen(axis_codes[Z_AXIS]))) {
                current_position[Z_AXIS] += zprobe_zoffset;  //Add Z_Probe offset (the distance is negative)
            }
#endif
            plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
#endif // else DELTA
#ifdef SCARA
            calculate_delta(current_position);
            plan_set_position(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], current_position[E_AXIS]);
#endif // SCARA
#ifdef ENDSTOPS_ONLY_FOR_HOMING
            enable_endstops(false);
#endif
            feedrate = saved_feedrate;
            feedmultiply = saved_feedmultiply;
            previous_millis_cmd = millis();
            endstops_hit_on_purpose();
            break;
#ifdef ENABLE_AUTO_BED_LEVELING
        case 29: { // G29 Detailed Z-Probe, probes the bed at 3 or more points.
#if Z_MIN_PIN == -1
#error "You must have a Z_MIN endstop in order to enable Auto Bed Leveling feature!!! Z_MIN_PIN must point to a valid hardware pin."
#endif
            // Prevent user from running a G29 without first homing in X and Y
            if (! (axis_known_position[X_AXIS] && axis_known_position[Y_AXIS]) ) {
                LCD_MESSAGEPGM(MSG_POSITION_UNKNOWN);
                SERIAL_ECHO_START;
                SERIAL_ECHOLNPGM(MSG_POSITION_UNKNOWN);
                break; // abort G29, since we don't know where we are
            }
#ifdef Z_PROBE_SLED
            dock_sled(false);
#endif // Z_PROBE_SLED
            st_synchronize();
            // make sure the bed_level_rotation_matrix is identity or the planner will get it incorectly
            //vector_3 corrected_position = plan_get_position_mm();
            //corrected_position.debug("position before G29");
            plan_bed_level_matrix.set_to_identity();
            vector_3 uncorrected_position = plan_get_position();
            //uncorrected_position.debug("position durring G29");
            current_position[X_AXIS] = uncorrected_position.x;
            current_position[Y_AXIS] = uncorrected_position.y;
            current_position[Z_AXIS] = uncorrected_position.z;
            plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
            setup_for_endstop_move();
            feedrate = homing_feedrate[Z_AXIS];
#ifdef AUTO_BED_LEVELING_GRID
            // probe at the points of a lattice grid
            int xGridSpacing = (RIGHT_PROBE_BED_POSITION - LEFT_PROBE_BED_POSITION) / (AUTO_BED_LEVELING_GRID_POINTS-1);
            int yGridSpacing = (BACK_PROBE_BED_POSITION - FRONT_PROBE_BED_POSITION) / (AUTO_BED_LEVELING_GRID_POINTS-1);
            // solve the plane equation ax + by + d = z
            // A is the matrix with rows [x y 1] for all the probed points
            // B is the vector of the Z positions
            // the normal vector to the plane is formed by the coefficients of the plane equation in the standard form, which is Vx*x+Vy*y+Vz*z+d = 0
            // so Vx = -a Vy = -b Vz = 1 (we want the vector facing towards positive Z
            // "A" matrix of the linear system of equations
            double eqnAMatrix[AUTO_BED_LEVELING_GRID_POINTS*AUTO_BED_LEVELING_GRID_POINTS*3];
            // "B" vector of Z points
            double eqnBVector[AUTO_BED_LEVELING_GRID_POINTS*AUTO_BED_LEVELING_GRID_POINTS];
            int probePointCounter = 0;
            bool zig = true;
            for (int yProbe=FRONT_PROBE_BED_POSITION; yProbe <= BACK_PROBE_BED_POSITION; yProbe += yGridSpacing) {
                int xProbe, xInc;
                if (zig) {
                    xProbe = LEFT_PROBE_BED_POSITION;
                    //xEnd = RIGHT_PROBE_BED_POSITION;
                    xInc = xGridSpacing;
                    zig = false;
                } else { // zag
                    xProbe = RIGHT_PROBE_BED_POSITION;
                    //xEnd = LEFT_PROBE_BED_POSITION;
                    xInc = -xGridSpacing;
                    zig = true;
                }
                for (int xCount=0; xCount < AUTO_BED_LEVELING_GRID_POINTS; xCount++) {
                    float z_before;
                    if (probePointCounter == 0) {
                        // raise before probing
                        z_before = Z_RAISE_BEFORE_PROBING;
                    } else {
                        // raise extruder
                        z_before = current_position[Z_AXIS] + Z_RAISE_BETWEEN_PROBINGS;
                    }
                    float measured_z = probe_pt(xProbe, yProbe, z_before);
                    eqnBVector[probePointCounter] = measured_z;
                    eqnAMatrix[probePointCounter + 0*AUTO_BED_LEVELING_GRID_POINTS*AUTO_BED_LEVELING_GRID_POINTS] = xProbe;
                    eqnAMatrix[probePointCounter + 1*AUTO_BED_LEVELING_GRID_POINTS*AUTO_BED_LEVELING_GRID_POINTS] = yProbe;
                    eqnAMatrix[probePointCounter + 2*AUTO_BED_LEVELING_GRID_POINTS*AUTO_BED_LEVELING_GRID_POINTS] = 1;
                    probePointCounter++;
                    xProbe += xInc;
                }
            }
            clean_up_after_endstop_move();
            // solve lsq problem
            double *plane_equation_coefficients = qr_solve(AUTO_BED_LEVELING_GRID_POINTS*AUTO_BED_LEVELING_GRID_POINTS, 3, eqnAMatrix, eqnBVector);
            SERIAL_PROTOCOLPGM("Eqn coefficients: a: ");
            SERIAL_PROTOCOL(plane_equation_coefficients[0]);
            SERIAL_PROTOCOLPGM(" b: ");
            SERIAL_PROTOCOL(plane_equation_coefficients[1]);
            SERIAL_PROTOCOLPGM(" d: ");
            SERIAL_PROTOCOLLN(plane_equation_coefficients[2]);
            set_bed_level_equation_lsq(plane_equation_coefficients);
            free(plane_equation_coefficients);
#else // AUTO_BED_LEVELING_GRID not defined
            // Probe at 3 arbitrary points
            // probe 1
            float z_at_pt_1 = probe_pt(ABL_PROBE_PT_1_X, ABL_PROBE_PT_1_Y, Z_RAISE_BEFORE_PROBING);
            // probe 2
            float z_at_pt_2 = probe_pt(ABL_PROBE_PT_2_X, ABL_PROBE_PT_2_Y, current_position[Z_AXIS] + Z_RAISE_BETWEEN_PROBINGS);
            // probe 3
            float z_at_pt_3 = probe_pt(ABL_PROBE_PT_3_X, ABL_PROBE_PT_3_Y, current_position[Z_AXIS] + Z_RAISE_BETWEEN_PROBINGS);
            clean_up_after_endstop_move();
            set_bed_level_equation_3pts(z_at_pt_1, z_at_pt_2, z_at_pt_3);
#endif // AUTO_BED_LEVELING_GRID
            st_synchronize();
            // The following code correct the Z height difference from z-probe position and hotend tip position.
            // The Z height on homing is measured by Z-Probe, but the probe is quite far from the hotend.
            // When the bed is uneven, this height must be corrected.
            real_z = float(st_get_position(Z_AXIS))/axis_steps_per_unit[Z_AXIS];  //get the real Z (since the auto bed leveling is already correcting the plane)
            x_tmp = current_position[X_AXIS] + X_PROBE_OFFSET_FROM_EXTRUDER;
            y_tmp = current_position[Y_AXIS] + Y_PROBE_OFFSET_FROM_EXTRUDER;
            z_tmp = current_position[Z_AXIS];
            apply_rotation_xyz(plan_bed_level_matrix, x_tmp, y_tmp, z_tmp);         //Apply the correction sending the probe offset
            current_position[Z_AXIS] = z_tmp - real_z + current_position[Z_AXIS];   //The difference is added to current position and sent to planner.
            plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
#ifdef Z_PROBE_SLED
            dock_sled(true, -SLED_DOCKING_OFFSET); // correct for over travel.
#endif // Z_PROBE_SLED
        }
        break;
#ifndef Z_PROBE_SLED
        case 30: { // G30 Single Z Probe
            engage_z_probe(); // Engage Z Servo endstop if available
            st_synchronize();
            // TODO: make sure the bed_level_rotation_matrix is identity or the planner will get set incorectly
            setup_for_endstop_move();
            feedrate = homing_feedrate[Z_AXIS];
            run_z_probe();
            SERIAL_PROTOCOLPGM(MSG_BED);
            SERIAL_PROTOCOLPGM(" X: ");
            SERIAL_PROTOCOL(current_position[X_AXIS]);
            SERIAL_PROTOCOLPGM(" Y: ");
            SERIAL_PROTOCOL(current_position[Y_AXIS]);
            SERIAL_PROTOCOLPGM(" Z: ");
            SERIAL_PROTOCOL(current_position[Z_AXIS]);
            SERIAL_PROTOCOLPGM("\n");
            clean_up_after_endstop_move();
            retract_z_probe(); // Retract Z Servo endstop if available
        }
        break;
#else
        case 31: // dock the sled
            dock_sled(true);
            break;
        case 32: // undock the sled
            dock_sled(false);
            break;
#endif // Z_PROBE_SLED
#endif // ENABLE_AUTO_BED_LEVELING
        case 90: // G90
            relative_mode = false;
            break;
        case 91: // G91
            relative_mode = true;
            break;
        case 92: // G92
            if(!code_seen(axis_codes[E_AXIS]))
                st_synchronize();
            for(int8_t i=0; i < NUM_AXIS; i++) {
                if(code_seen(axis_codes[i])) {
                    if(i == E_AXIS) {
                        current_position[i] = code_value();
                        plan_set_e_position(current_position[E_AXIS]);
                    } else {
#ifdef SCARA
                        if (i == X_AXIS || i == Y_AXIS) {
                            current_position[i] = code_value();
                        } else {
                            current_position[i] = code_value()+add_homing[i];
                        }
#else
                        current_position[i] = code_value()+add_homing[i];
#endif
                        plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
                    }
                }
            }
            break;
        }
    } else if(code_seen('M')) {
        switch( (int)code_value() ) {
#ifdef ULTIPANEL
        case 0: // M0 - Unconditional stop - Wait for user button press on LCD
        case 1: { // M1 - Conditional stop - Wait for user button press on LCD
            char *src = strchr_pointer + 2;
            codenum = 0;
            bool hasP = false, hasS = false;
            if (code_seen('P')) {
                codenum = code_value(); // milliseconds to wait
                hasP = codenum > 0;
            }
            if (code_seen('S')) {
                codenum = code_value() * 1000; // seconds to wait
                hasS = codenum > 0;
            }
            starpos = strchr(src, '*');
            if (starpos != NULL) *(starpos) = '\0';
            while (*src == ' ') ++src;
            if (!hasP && !hasS && *src != '\0') {
                lcd_setstatus(src);
            } else {
                LCD_MESSAGEPGM(MSG_USERWAIT);
            }
            lcd_ignore_click();
            st_synchronize();
            previous_millis_cmd = millis();
            if (codenum > 0) {
                codenum += millis();  // keep track of when we started waiting
                while(millis() < codenum && !lcd_clicked()) {
                    manage_heater();
                    manage_inactivity();
                    lcd_update();
                }
                lcd_ignore_click(false);
            } else {
                if (!lcd_detected())
                    break;
                while(!lcd_clicked()) {
                    manage_heater();
                    manage_inactivity();
                    lcd_update();
                }
            }
            if (IS_SD_PRINTING)
                LCD_MESSAGEPGM(MSG_RESUMING);
            else
                LCD_MESSAGEPGM(WELCOME_MSG);
        }
        break;
#endif
        case 17:
            LCD_MESSAGEPGM(MSG_NO_MOVE);
            enable_x();
            enable_y();
            enable_z();
            enable_e0();
            enable_e1();
            enable_e2();
            break;
#ifdef SDSUPPORT
        case 20: // M20 - list SD card
            SERIAL_PROTOCOLLNPGM(MSG_BEGIN_FILE_LIST);
            card.ls();
            SERIAL_PROTOCOLLNPGM(MSG_END_FILE_LIST);
            break;
        case 21: // M21 - init SD card
            card.initsd();
            break;
        case 22: //M22 - release SD card
            card.release();
            break;
        case 23: //M23 - Select file
            starpos = (strchr(strchr_pointer + 4,'*'));
            if(starpos!=NULL)
                *(starpos)='\0';
            card.openFile(strchr_pointer + 4,true);
            break;
        case 24: //M24 - Start SD print
            card.startFileprint();
            starttime=millis();
            break;
        case 25: //M25 - Pause SD print
            card.pauseSDPrint();
            break;
        case 26: //M26 - Set SD index
            if(card.cardOK && code_seen('S')) {
                card.setIndex(code_value_long());
            }
            break;
        case 27: //M27 - Get SD status
            card.getStatus();
            break;
        case 28: //M28 - Start SD write
            starpos = (strchr(strchr_pointer + 4,'*'));
            if(starpos != NULL) {
                char* npos = strchr(cmdbuffer[bufindr], 'N');
                strchr_pointer = strchr(npos,' ') + 1;
                *(starpos) = '\0';
            }
            card.openFile(strchr_pointer+4,false);
            break;
        case 29: //M29 - Stop SD write
            //processed in write to file routine above
            //card,saving = false;
            break;
        case 30: //M30 <filename> Delete File
            if (card.cardOK) {
                card.closefile();
                starpos = (strchr(strchr_pointer + 4,'*'));
                if(starpos != NULL) {
                    char* npos = strchr(cmdbuffer[bufindr], 'N');
                    strchr_pointer = strchr(npos,' ') + 1;
                    *(starpos) = '\0';
                }
                card.removeFile(strchr_pointer + 4);
            }
            break;
        case 32: { //M32 - Select file and start SD print
            if(card.sdprinting) {
                st_synchronize();
            }
            starpos = (strchr(strchr_pointer + 4,'*'));
            char* namestartpos = (strchr(strchr_pointer + 4,'!'));   //find ! to indicate filename string start.
            if(namestartpos==NULL) {
                namestartpos=strchr_pointer + 4; //default name position, 4 letters after the M
            } else
                namestartpos++; //to skip the '!'
            if(starpos!=NULL)
                *(starpos)='\0';
            bool call_procedure=(code_seen('P'));
            if(strchr_pointer>namestartpos)
                call_procedure=false;  //false alert, 'P' found within filename
            if( card.cardOK ) {
                card.openFile(namestartpos,true,!call_procedure);
                if(code_seen('S'))
                    if(strchr_pointer<namestartpos) //only if "S" is occuring _before_ the filename
                        card.setIndex(code_value_long());
                card.startFileprint();
                if(!call_procedure)
                    starttime=millis(); //procedure calls count as normal print time.
            }
        }
        break;
        case 928: //M928 - Start SD write
            starpos = (strchr(strchr_pointer + 5,'*'));
            if(starpos != NULL) {
                char* npos = strchr(cmdbuffer[bufindr], 'N');
                strchr_pointer = strchr(npos,' ') + 1;
                *(starpos) = '\0';
            }
            card.openLogFile(strchr_pointer+5);
            break;
#endif //SDSUPPORT
        case 31: { //M31 take time since the start of the SD print or an M109 command
            stoptime=millis();
            char time[30];
            unsigned long t=(stoptime-starttime)/1000;
            int sec,min;
            min=t/60;
            sec=t%60;
            sprintf_P(time, PSTR("%i min, %i sec"), min, sec);
            SERIAL_ECHO_START;
            SERIAL_ECHOLN(time);
            lcd_setstatus(time);
            autotempShutdown();
        }
        break;
        case 42: //M42 -Change pin status via gcode
            if (code_seen('S')) {
                int pin_status = code_value();
                int pin_number = LED_PIN;
                if (code_seen('P') && pin_status >= 0 && pin_status <= 255)
                    pin_number = code_value();
                for(int8_t i = 0; i < (int8_t)(sizeof(sensitive_pins)/sizeof(int)); i++) {
                    if (sensitive_pins[i] == pin_number) {
                        pin_number = -1;
                        break;
                    }
                }
#if defined(FAN_PIN) && FAN_PIN > -1
                if (pin_number == FAN_PIN)
                    fanSpeed = pin_status;
#endif
                if (pin_number > -1) {
                    pinMode(pin_number, OUTPUT);
                    digitalWrite(pin_number, pin_status);
                    analogWrite(pin_number, pin_status);
                }
            }
            break;
// M48 Z-Probe repeatability measurement function.
//
// Usage:   M48 <n #_samples> <X X_position_for_samples> <Y Y_position_for_samples> <V Verbose_Level> <Engage_probe_for_each_reading> <L legs_of_movement_prior_to_doing_probe>
//
// This function assumes the bed has been homed.  Specificaly, that a G28 command
// as been issued prior to invoking the M48 Z-Probe repeatability measurement function.
// Any information generated by a prior G29 Bed leveling command will be lost and need to be
// regenerated.
//
// The number of samples will default to 10 if not specified.  You can use upper or lower case
// letters for any of the options EXCEPT n.  n must be in lower case because Marlin uses a capital
// N for its communication protocol and will get horribly confused if you send it a capital N.
//
#ifdef ENABLE_AUTO_BED_LEVELING
#ifdef Z_PROBE_REPEATABILITY_TEST
        case 48: { // M48 Z-Probe repeatability
#if Z_MIN_PIN == -1
#error "You must have a Z_MIN endstop in order to enable calculation of Z-Probe repeatability."
#endif
            double sum=0.0;
            double mean=0.0;
            double sigma=0.0;
            double sample_set[50];
            int verbose_level=1, n=0, j, n_samples = 10, n_legs=0, engage_probe_for_each_reading=0 ;
            double X_current, Y_current, Z_current;
            double X_probe_location, Y_probe_location, Z_start_location, ext_position;
            if (code_seen('V') || code_seen('v')) {
                verbose_level = code_value();
                if (verbose_level<0 || verbose_level>4 ) {
                    SERIAL_PROTOCOLPGM("?Verbose Level not plausable.\n");
                    goto Sigma_Exit;
                }
            }
            if (verbose_level > 0)   {
                SERIAL_PROTOCOLPGM("M48 Z-Probe Repeatability test.   Version 2.00\n");
                SERIAL_PROTOCOLPGM("Full support at: http://3dprintboard.com/forum.php\n");
            }
            if (code_seen('n')) {
                n_samples = code_value();
                if (n_samples<4 || n_samples>50 ) {
                    SERIAL_PROTOCOLPGM("?Specified sample size not plausable.\n");
                    goto Sigma_Exit;
                }
            }
            X_current = X_probe_location = st_get_position_mm(X_AXIS);
            Y_current = Y_probe_location = st_get_position_mm(Y_AXIS);
            Z_current = st_get_position_mm(Z_AXIS);
            Z_start_location = st_get_position_mm(Z_AXIS) + Z_RAISE_BEFORE_PROBING;
            ext_position	 = st_get_position_mm(E_AXIS);
            if (code_seen('E') || code_seen('e') )
                engage_probe_for_each_reading++;
            if (code_seen('X') || code_seen('x') ) {
                X_probe_location = code_value() -  X_PROBE_OFFSET_FROM_EXTRUDER;
                if (X_probe_location<X_MIN_POS || X_probe_location>X_MAX_POS ) {
                    SERIAL_PROTOCOLPGM("?Specified X position out of range.\n");
                    goto Sigma_Exit;
                }
            }
            if (code_seen('Y') || code_seen('y') ) {
                Y_probe_location = code_value() -  Y_PROBE_OFFSET_FROM_EXTRUDER;
                if (Y_probe_location<Y_MIN_POS || Y_probe_location>Y_MAX_POS ) {
                    SERIAL_PROTOCOLPGM("?Specified Y position out of range.\n");
                    goto Sigma_Exit;
                }
            }
            if (code_seen('L') || code_seen('l') ) {
                n_legs = code_value();
                if ( n_legs==1 )
                    n_legs = 2;
                if ( n_legs<0 || n_legs>15 ) {
                    SERIAL_PROTOCOLPGM("?Specified number of legs in movement not plausable.\n");
                    goto Sigma_Exit;
                }
            }
//
// Do all the preliminary setup work.   First raise the probe.
//
            st_synchronize();
            plan_bed_level_matrix.set_to_identity();
            plan_buffer_line( X_current, Y_current, Z_start_location,
                              ext_position,
                              homing_feedrate[Z_AXIS]/60,
                              active_extruder);
            st_synchronize();
//
// Now get everything to the specified probe point So we can safely do a probe to
// get us close to the bed.  If the Z-Axis is far from the bed, we don't want to
// use that as a starting point for each probe.
//
            if (verbose_level > 2)
                SERIAL_PROTOCOL("Positioning probe for the test.\n");
            plan_buffer_line( X_probe_location, Y_probe_location, Z_start_location,
                              ext_position,
                              homing_feedrate[X_AXIS]/60,
                              active_extruder);
            st_synchronize();
            current_position[X_AXIS] = X_current = st_get_position_mm(X_AXIS);
            current_position[Y_AXIS] = Y_current = st_get_position_mm(Y_AXIS);
            current_position[Z_AXIS] = Z_current = st_get_position_mm(Z_AXIS);
            current_position[E_AXIS] = ext_position = st_get_position_mm(E_AXIS);
//
// OK, do the inital probe to get us close to the bed.
// Then retrace the right amount and use that in subsequent probes
//
            engage_z_probe();
            setup_for_endstop_move();
            run_z_probe();
            current_position[Z_AXIS] = Z_current = st_get_position_mm(Z_AXIS);
            Z_start_location = st_get_position_mm(Z_AXIS) + Z_RAISE_BEFORE_PROBING;
            plan_buffer_line( X_probe_location, Y_probe_location, Z_start_location,
                              ext_position,
                              homing_feedrate[X_AXIS]/60,
                              active_extruder);
            st_synchronize();
            current_position[Z_AXIS] = Z_current = st_get_position_mm(Z_AXIS);
            if (engage_probe_for_each_reading)
                retract_z_probe();
            for( n=0; n<n_samples; n++) {
                do_blocking_move_to( X_probe_location, Y_probe_location, Z_start_location); // Make sure we are at the probe location
                if ( n_legs)  {
                    double radius=0.0, theta=0.0, x_sweep, y_sweep;
                    int rotational_direction, l;
                    rotational_direction = (unsigned long) millis() & 0x0001;			// clockwise or counter clockwise
                    radius = (unsigned long) millis() % (long) (X_MAX_LENGTH/4); 			// limit how far out to go
                    theta = (float) ((unsigned long) millis() % (long) 360) / (360./(2*3.1415926));	// turn into radians
//SERIAL_ECHOPAIR("starting radius: ",radius);
//SERIAL_ECHOPAIR("   theta: ",theta);
//SERIAL_ECHOPAIR("   direction: ",rotational_direction);
//SERIAL_PROTOCOLLNPGM("");
                    for( l=0; l<n_legs-1; l++) {
                        if (rotational_direction==1)
                            theta += (float) ((unsigned long) millis() % (long) 20) / (360.0/(2*3.1415926)); // turn into radians
                        else
                            theta -= (float) ((unsigned long) millis() % (long) 20) / (360.0/(2*3.1415926)); // turn into radians
                        radius += (float) ( ((long) ((unsigned long) millis() % (long) 10)) - 5);
                        if ( radius<0.0 )
                            radius = -radius;
                        X_current = X_probe_location + cos(theta) * radius;
                        Y_current = Y_probe_location + sin(theta) * radius;
                        if ( X_current<X_MIN_POS)		// Make sure our X & Y are sane
                            X_current = X_MIN_POS;
                        if ( X_current>X_MAX_POS)
                            X_current = X_MAX_POS;
                        if ( Y_current<Y_MIN_POS)		// Make sure our X & Y are sane
                            Y_current = Y_MIN_POS;
                        if ( Y_current>Y_MAX_POS)
                            Y_current = Y_MAX_POS;
                        if (verbose_level>3 ) {
                            SERIAL_ECHOPAIR("x: ", X_current);
                            SERIAL_ECHOPAIR("y: ", Y_current);
                            SERIAL_PROTOCOLLNPGM("");
                        }
                        do_blocking_move_to( X_current, Y_current, Z_current );
                    }
                    do_blocking_move_to( X_probe_location, Y_probe_location, Z_start_location); // Go back to the probe location
                }
                if (engage_probe_for_each_reading)  {
                    engage_z_probe();
                    delay(1000);
                }
                setup_for_endstop_move();
                run_z_probe();
                sample_set[n] = current_position[Z_AXIS];
//
// Get the current mean for the data points we have so far
//
                sum=0.0;
                for( j=0; j<=n; j++) {
                    sum = sum + sample_set[j];
                }
                mean = sum / (double (n+1));
//
// Now, use that mean to calculate the standard deviation for the
// data points we have so far
//
                sum=0.0;
                for( j=0; j<=n; j++) {
                    sum = sum + (sample_set[j]-mean) * (sample_set[j]-mean);
                }
                sigma = sqrt( sum / (double (n+1)) );
                if (verbose_level > 1) {
                    SERIAL_PROTOCOL(n+1);
                    SERIAL_PROTOCOL(" of ");
                    SERIAL_PROTOCOL(n_samples);
                    SERIAL_PROTOCOLPGM("   z: ");
                    SERIAL_PROTOCOL_F(current_position[Z_AXIS], 6);
                }
                if (verbose_level > 2) {
                    SERIAL_PROTOCOL(" mean: ");
                    SERIAL_PROTOCOL_F(mean,6);
                    SERIAL_PROTOCOL("   sigma: ");
                    SERIAL_PROTOCOL_F(sigma,6);
                }
                if (verbose_level > 0)
                    SERIAL_PROTOCOLPGM("\n");
                plan_buffer_line( X_probe_location, Y_probe_location, Z_start_location,
                                  current_position[E_AXIS], homing_feedrate[Z_AXIS]/60, active_extruder);
                st_synchronize();
                if (engage_probe_for_each_reading)  {
                    retract_z_probe();
                    delay(1000);
                }
            }
            retract_z_probe();
            delay(1000);
            clean_up_after_endstop_move();
//      enable_endstops(true);
            if (verbose_level > 0) {
                SERIAL_PROTOCOLPGM("Mean: ");
                SERIAL_PROTOCOL_F(mean, 6);
                SERIAL_PROTOCOLPGM("\n");
            }
            SERIAL_PROTOCOLPGM("Standard Deviation: ");
            SERIAL_PROTOCOL_F(sigma, 6);
            SERIAL_PROTOCOLPGM("\n\n");
Sigma_Exit:
            break;
        }
#endif		// Z_PROBE_REPEATABILITY_TEST 
#endif		// ENABLE_AUTO_BED_LEVELING
        case 104: // M104
            if(setTargetedHotend(104)) {
                break;
            }
            if (code_seen('S')) setTargetHotend(code_value(), tmp_extruder);
#ifdef DUAL_X_CARRIAGE
            if (dual_x_carriage_mode == DXC_DUPLICATION_MODE && tmp_extruder == 0)
                setTargetHotend1(code_value() == 0.0 ? 0.0 : code_value() + duplicate_extruder_temp_offset);
#endif
            setWatch();
            break;
        case 112: //  M112 -Emergency Stop
            kill();
            break;
        case 140: // M140 set bed temp
            if (code_seen('S')) setTargetBed(code_value());
            break;
        case 105 : // M105
            if(setTargetedHotend(105)) {
                break;
            }
#if defined(TEMP_0_PIN) && TEMP_0_PIN > -1
            SERIAL_PROTOCOLPGM("ok T:");
            SERIAL_PROTOCOL_F(degHotend(tmp_extruder),1);
            SERIAL_PROTOCOLPGM(" /");
            SERIAL_PROTOCOL_F(degTargetHotend(tmp_extruder),1);
#if defined(TEMP_BED_PIN) && TEMP_BED_PIN > -1
            SERIAL_PROTOCOLPGM(" B:");
            SERIAL_PROTOCOL_F(degBed(),1);
            SERIAL_PROTOCOLPGM(" /");
            SERIAL_PROTOCOL_F(degTargetBed(),1);
#endif //TEMP_BED_PIN
            for (int8_t cur_extruder = 0; cur_extruder < EXTRUDERS; ++cur_extruder) {
                SERIAL_PROTOCOLPGM(" T");
                SERIAL_PROTOCOL(cur_extruder);
                SERIAL_PROTOCOLPGM(":");
                SERIAL_PROTOCOL_F(degHotend(cur_extruder),1);
                SERIAL_PROTOCOLPGM(" /");
                SERIAL_PROTOCOL_F(degTargetHotend(cur_extruder),1);
            }
#else
            SERIAL_ERROR_START;
            SERIAL_ERRORLNPGM(MSG_ERR_NO_THERMISTORS);
#endif
            SERIAL_PROTOCOLPGM(" @:");
#ifdef EXTRUDER_WATTS
            SERIAL_PROTOCOL((EXTRUDER_WATTS * getHeaterPower(tmp_extruder))/127);
            SERIAL_PROTOCOLPGM("W");
#else
            SERIAL_PROTOCOL(getHeaterPower(tmp_extruder));
#endif
            SERIAL_PROTOCOLPGM(" B@:");
#ifdef BED_WATTS
            SERIAL_PROTOCOL((BED_WATTS * getHeaterPower(-1))/127);
            SERIAL_PROTOCOLPGM("W");
#else
            SERIAL_PROTOCOL(getHeaterPower(-1));
#endif
#ifdef SHOW_TEMP_ADC_VALUES
#if defined(TEMP_BED_PIN) && TEMP_BED_PIN > -1
            SERIAL_PROTOCOLPGM("    ADC B:");
            SERIAL_PROTOCOL_F(degBed(),1);
            SERIAL_PROTOCOLPGM("C->");
            SERIAL_PROTOCOL_F(rawBedTemp()/OVERSAMPLENR,0);
#endif
            for (int8_t cur_extruder = 0; cur_extruder < EXTRUDERS; ++cur_extruder) {
                SERIAL_PROTOCOLPGM("  T");
                SERIAL_PROTOCOL(cur_extruder);
                SERIAL_PROTOCOLPGM(":");
                SERIAL_PROTOCOL_F(degHotend(cur_extruder),1);
                SERIAL_PROTOCOLPGM("C->");
                SERIAL_PROTOCOL_F(rawHotendTemp(cur_extruder)/OVERSAMPLENR,0);
            }
#endif
            SERIAL_PROTOCOLLN("");
            return;
            break;
        case 109: {
            // M109 - Wait for extruder heater to reach target.
            if(setTargetedHotend(109)) {
                break;
            }
            LCD_MESSAGEPGM(MSG_HEATING);
#ifdef AUTOTEMP
            autotemp_enabled=false;
#endif
            if (code_seen('S')) {
                setTargetHotend(code_value(), tmp_extruder);
#ifdef DUAL_X_CARRIAGE
                if (dual_x_carriage_mode == DXC_DUPLICATION_MODE && tmp_extruder == 0)
                    setTargetHotend1(code_value() == 0.0 ? 0.0 : code_value() + duplicate_extruder_temp_offset);
#endif
                CooldownNoWait = true;
            } else if (code_seen('R')) {
                setTargetHotend(code_value(), tmp_extruder);
#ifdef DUAL_X_CARRIAGE
                if (dual_x_carriage_mode == DXC_DUPLICATION_MODE && tmp_extruder == 0)
                    setTargetHotend1(code_value() == 0.0 ? 0.0 : code_value() + duplicate_extruder_temp_offset);
#endif
                CooldownNoWait = false;
            }
#ifdef AUTOTEMP
            if (code_seen('S')) autotemp_min=code_value();
            if (code_seen('B')) autotemp_max=code_value();
            if (code_seen('F')) {
                autotemp_factor=code_value();
                autotemp_enabled=true;
            }
#endif
            setWatch();
            codenum = millis();
            /* See if we are heating up or cooling down */
            target_direction = isHeatingHotend(tmp_extruder); // true if heating, false if cooling
            cancel_heatup = false;
#ifdef TEMP_RESIDENCY_TIME
            long residencyStart;
            residencyStart = -1;
            /* continue to loop until we have reached the target temp
              _and_ until TEMP_RESIDENCY_TIME hasn't passed since we reached it */
            while((!cancel_heatup)&&((residencyStart == -1) ||
                                     (residencyStart >= 0 && (((unsigned int) (millis() - residencyStart)) < (TEMP_RESIDENCY_TIME * 1000UL)))) ) {
#else
            while ( target_direction ? (isHeatingHotend(tmp_extruder)) : (isCoolingHotend(tmp_extruder)&&(CooldownNoWait==false)) ) {
#endif //TEMP_RESIDENCY_TIME
                if( (millis() - codenum) > 1000UL ) {
                    //Print Temp Reading and remaining time every 1 second while heating up/cooling down
                    SERIAL_PROTOCOLPGM("T:");
                    SERIAL_PROTOCOL_F(degHotend(tmp_extruder),1);
                    SERIAL_PROTOCOLPGM(" E:");
                    SERIAL_PROTOCOL((int)tmp_extruder);
#ifdef TEMP_RESIDENCY_TIME
                    SERIAL_PROTOCOLPGM(" W:");
                    if(residencyStart > -1) {
                        codenum = ((TEMP_RESIDENCY_TIME * 1000UL) - (millis() - residencyStart)) / 1000UL;
                        SERIAL_PROTOCOLLN( codenum );
                    } else {
                        SERIAL_PROTOCOLLN( "?" );
                    }
#else
                    SERIAL_PROTOCOLLN("");
#endif
                    codenum = millis();
                }
                manage_heater();
                manage_inactivity();
                lcd_update();
#ifdef TEMP_RESIDENCY_TIME
                /* start/restart the TEMP_RESIDENCY_TIME timer whenever we reach target temp for the first time
                  or when current temp falls outside the hysteresis after target temp was reached */
                if ((residencyStart == -1 &&  target_direction && (degHotend(tmp_extruder) >= (degTargetHotend(tmp_extruder)-TEMP_WINDOW))) ||
                        (residencyStart == -1 && !target_direction && (degHotend(tmp_extruder) <= (degTargetHotend(tmp_extruder)+TEMP_WINDOW))) ||
                        (residencyStart > -1 && labs(degHotend(tmp_extruder) - degTargetHotend(tmp_extruder)) > TEMP_HYSTERESIS) ) {
                    residencyStart = millis();
                }
#endif //TEMP_RESIDENCY_TIME
            }
            LCD_MESSAGEPGM(MSG_HEATING_COMPLETE);
            starttime=millis();
            previous_millis_cmd = millis();
        }
        break;
        case 190: // M190 - Wait for bed heater to reach target.
#if defined(TEMP_BED_PIN) && TEMP_BED_PIN > -1
            LCD_MESSAGEPGM(MSG_BED_HEATING);
            if (code_seen('S')) {
                setTargetBed(code_value());
                CooldownNoWait = true;
            } else if (code_seen('R')) {
                setTargetBed(code_value());
                CooldownNoWait = false;
            }
            codenum = millis();
            cancel_heatup = false;
            target_direction = isHeatingBed(); // true if heating, false if cooling
            while ( (target_direction)&&(!cancel_heatup) ? (isHeatingBed()) : (isCoolingBed()&&(CooldownNoWait==false)) ) {
                if(( millis() - codenum) > 1000 ) { //Print Temp Reading every 1 second while heating up.
                    float tt=degHotend(active_extruder);
                    SERIAL_PROTOCOLPGM("T:");
                    SERIAL_PROTOCOL(tt);
                    SERIAL_PROTOCOLPGM(" E:");
                    SERIAL_PROTOCOL((int)active_extruder);
                    SERIAL_PROTOCOLPGM(" B:");
                    SERIAL_PROTOCOL_F(degBed(),1);
                    SERIAL_PROTOCOLLN("");
                    codenum = millis();
                }
                manage_heater();
                manage_inactivity();
                lcd_update();
            }
            LCD_MESSAGEPGM(MSG_BED_DONE);
            previous_millis_cmd = millis();
#endif
            break;
#if defined(FAN_PIN) && FAN_PIN > -1
        case 106: //M106 Fan On
            if (code_seen('S')) {
                fanSpeed=constrain(code_value(),0,255);
            } else {
                fanSpeed=255;
            }
            break;
        case 107: //M107 Fan Off
            fanSpeed = 0;
            break;
#endif //FAN_PIN
#ifdef BARICUDA
            // PWM for HEATER_1_PIN
#if defined(HEATER_1_PIN) && HEATER_1_PIN > -1
        case 126: //M126 valve open
            if (code_seen('S')) {
                ValvePressure=constrain(code_value(),0,255);
            } else {
                ValvePressure=255;
            }
            break;
        case 127: //M127 valve closed
            ValvePressure = 0;
            break;
#endif //HEATER_1_PIN
            // PWM for HEATER_2_PIN
#if defined(HEATER_2_PIN) && HEATER_2_PIN > -1
        case 128: //M128 valve open
            if (code_seen('S')) {
                EtoPPressure=constrain(code_value(),0,255);
            } else {
                EtoPPressure=255;
            }
            break;
        case 129: //M129 valve closed
            EtoPPressure = 0;
            break;
#endif //HEATER_2_PIN
#endif
#if defined(PS_ON_PIN) && PS_ON_PIN > -1
        case 80: // M80 - Turn on Power Supply
            SET_OUTPUT(PS_ON_PIN); //GND
            WRITE(PS_ON_PIN, PS_ON_AWAKE);
            // If you have a switch on suicide pin, this is useful
            // if you want to start another print with suicide feature after
            // a print without suicide...
#if defined SUICIDE_PIN && SUICIDE_PIN > -1
            SET_OUTPUT(SUICIDE_PIN);
            WRITE(SUICIDE_PIN, HIGH);
#endif
#ifdef ULTIPANEL
            powersupply = true;
            LCD_MESSAGEPGM(WELCOME_MSG);
            lcd_update();
#endif
            break;
#endif
        case 81: // M81 - Turn off Power Supply
            disable_heater();
            st_synchronize();
            disable_e0();
            disable_e1();
            disable_e2();
            finishAndDisableSteppers();
            fanSpeed = 0;
            delay(1000); // Wait a little before to switch off
#if defined(SUICIDE_PIN) && SUICIDE_PIN > -1
            st_synchronize();
            suicide();
#elif defined(PS_ON_PIN) && PS_ON_PIN > -1
            SET_OUTPUT(PS_ON_PIN);
            WRITE(PS_ON_PIN, PS_ON_ASLEEP);
#endif
#ifdef ULTIPANEL
            powersupply = false;
            LCD_MESSAGEPGM(MACHINE_NAME" "MSG_OFF".");
            lcd_update();
#endif
            break;
        case 82:
            axis_relative_modes[3] = false;
            break;
        case 83:
            axis_relative_modes[3] = true;
            break;
        case 18: //compatibility
        case 84: // M84
            if(code_seen('S')) {
                stepper_inactive_time = code_value() * 1000;
            } else {
                bool all_axis = !((code_seen(axis_codes[X_AXIS])) || (code_seen(axis_codes[Y_AXIS])) || (code_seen(axis_codes[Z_AXIS]))|| (code_seen(axis_codes[E_AXIS])));
                if(all_axis) {
                    st_synchronize();
                    disable_e0();
                    disable_e1();
                    disable_e2();
                    finishAndDisableSteppers();
                } else {
                    st_synchronize();
                    if(code_seen('X')) disable_x();
                    if(code_seen('Y')) disable_y();
                    if(code_seen('Z')) disable_z();
#if ((E0_ENABLE_PIN != X_ENABLE_PIN) && (E1_ENABLE_PIN != Y_ENABLE_PIN)) // Only enable on boards that have seperate ENABLE_PINS
                    if(code_seen('E')) {
                        disable_e0();
                        disable_e1();
                        disable_e2();
                    }
#endif
                }
            }
            break;
        case 85: // M85
            if(code_seen('S')) {
                max_inactive_time = code_value() * 1000;
            }
            break;
        case 92: // M92
            for(int8_t i=0; i < NUM_AXIS; i++) {
                if(code_seen(axis_codes[i])) {
                    if(i == 3) { // E
                        float value = code_value();
                        if(value < 20.0) {
                            float factor = axis_steps_per_unit[i] / value; // increase e constants if M92 E14 is given for netfab.
                            max_e_jerk *= factor;
                            max_feedrate[i] *= factor;
                            axis_steps_per_sqr_second[i] *= factor;
                        }
                        axis_steps_per_unit[i] = value;
                    } else {
                        axis_steps_per_unit[i] = code_value();
                    }
                }
            }
            break;
        case 115: // M115
            SERIAL_PROTOCOLPGM(MSG_M115_REPORT);
            break;
        case 117: // M117 display message
            starpos = (strchr(strchr_pointer + 5,'*'));
            if(starpos!=NULL)
                *(starpos)='\0';
            lcd_setstatus(strchr_pointer + 5);
            break;
        case 114: // M114
            SERIAL_PROTOCOLPGM("X:");
            SERIAL_PROTOCOL(current_position[X_AXIS]);
            SERIAL_PROTOCOLPGM(" Y:");
            SERIAL_PROTOCOL(current_position[Y_AXIS]);
            SERIAL_PROTOCOLPGM(" Z:");
            SERIAL_PROTOCOL(current_position[Z_AXIS]);
            SERIAL_PROTOCOLPGM(" E:");
            SERIAL_PROTOCOL(current_position[E_AXIS]);
            SERIAL_PROTOCOLPGM(MSG_COUNT_X);
            SERIAL_PROTOCOL(float(st_get_position(X_AXIS))/axis_steps_per_unit[X_AXIS]);
            SERIAL_PROTOCOLPGM(" Y:");
            SERIAL_PROTOCOL(float(st_get_position(Y_AXIS))/axis_steps_per_unit[Y_AXIS]);
            SERIAL_PROTOCOLPGM(" Z:");
            SERIAL_PROTOCOL(float(st_get_position(Z_AXIS))/axis_steps_per_unit[Z_AXIS]);
            SERIAL_PROTOCOLLN("");
#ifdef SCARA
            SERIAL_PROTOCOLPGM("SCARA Theta:");
            SERIAL_PROTOCOL(delta[X_AXIS]);
            SERIAL_PROTOCOLPGM("   Psi+Theta:");
            SERIAL_PROTOCOL(delta[Y_AXIS]);
            SERIAL_PROTOCOLLN("");
            SERIAL_PROTOCOLPGM("SCARA Cal - Theta:");
            SERIAL_PROTOCOL(delta[X_AXIS]+add_homing[X_AXIS]);
            SERIAL_PROTOCOLPGM("   Psi+Theta (90):");
            SERIAL_PROTOCOL(delta[Y_AXIS]-delta[X_AXIS]-90+add_homing[Y_AXIS]);
            SERIAL_PROTOCOLLN("");
            SERIAL_PROTOCOLPGM("SCARA step Cal - Theta:");
            SERIAL_PROTOCOL(delta[X_AXIS]/90*axis_steps_per_unit[X_AXIS]);
            SERIAL_PROTOCOLPGM("   Psi+Theta:");
            SERIAL_PROTOCOL((delta[Y_AXIS]-delta[X_AXIS])/90*axis_steps_per_unit[Y_AXIS]);
            SERIAL_PROTOCOLLN("");
            SERIAL_PROTOCOLLN("");
#endif
            break;
        case 120: // M120
            enable_endstops(false) ;
            break;
        case 121: // M121
            enable_endstops(true) ;
            break;
        case 119: // M119
            SERIAL_PROTOCOLLN(MSG_M119_REPORT);
#if defined(X_MIN_PIN) && X_MIN_PIN > -1
            SERIAL_PROTOCOLPGM(MSG_X_MIN);
            SERIAL_PROTOCOLLN(((READ(X_MIN_PIN)^X_MIN_ENDSTOP_INVERTING)?MSG_ENDSTOP_HIT:MSG_ENDSTOP_OPEN));
#endif
#if defined(X_MAX_PIN) && X_MAX_PIN > -1
            SERIAL_PROTOCOLPGM(MSG_X_MAX);
            SERIAL_PROTOCOLLN(((READ(X_MAX_PIN)^X_MAX_ENDSTOP_INVERTING)?MSG_ENDSTOP_HIT:MSG_ENDSTOP_OPEN));
#endif
#if defined(Y_MIN_PIN) && Y_MIN_PIN > -1
            SERIAL_PROTOCOLPGM(MSG_Y_MIN);
            SERIAL_PROTOCOLLN(((READ(Y_MIN_PIN)^Y_MIN_ENDSTOP_INVERTING)?MSG_ENDSTOP_HIT:MSG_ENDSTOP_OPEN));
#endif
#if defined(Y_MAX_PIN) && Y_MAX_PIN > -1
            SERIAL_PROTOCOLPGM(MSG_Y_MAX);
            SERIAL_PROTOCOLLN(((READ(Y_MAX_PIN)^Y_MAX_ENDSTOP_INVERTING)?MSG_ENDSTOP_HIT:MSG_ENDSTOP_OPEN));
#endif
#if defined(Z_MIN_PIN) && Z_MIN_PIN > -1
            SERIAL_PROTOCOLPGM(MSG_Z_MIN);
            SERIAL_PROTOCOLLN(((READ(Z_MIN_PIN)^Z_MIN_ENDSTOP_INVERTING)?MSG_ENDSTOP_HIT:MSG_ENDSTOP_OPEN));
#endif
#if defined(Z_MAX_PIN) && Z_MAX_PIN > -1
            SERIAL_PROTOCOLPGM(MSG_Z_MAX);
            SERIAL_PROTOCOLLN(((READ(Z_MAX_PIN)^Z_MAX_ENDSTOP_INVERTING)?MSG_ENDSTOP_HIT:MSG_ENDSTOP_OPEN));
#endif
            break;
            //TODO: update for all axis, use for loop
#ifdef BLINKM
        case 150: { // M150
            byte red;
            byte grn;
            byte blu;
            if(code_seen('R')) red = code_value();
            if(code_seen('U')) grn = code_value();
            if(code_seen('B')) blu = code_value();
            SendColors(red,grn,blu);
        }
        break;
#endif //BLINKM
        case 200: { // M200 D<millimeters> set filament diameter and set E axis units to cubic millimeters (use S0 to set back to millimeters).
            tmp_extruder = active_extruder;
            if(code_seen('T')) {
                tmp_extruder = code_value();
                if(tmp_extruder >= EXTRUDERS) {
                    SERIAL_ECHO_START;
                    SERIAL_ECHO(MSG_M200_INVALID_EXTRUDER);
                    break;
                }
            }
            float area = .0;
            if(code_seen('D')) {
                float diameter = (float)code_value();
                if (diameter == 0.0) {
                    // setting any extruder filament size disables volumetric on the assumption that
                    // slicers either generate in extruder values as cubic mm or as as filament feeds
                    // for all extruders
                    volumetric_enabled = false;
                } else {
                    filament_size[tmp_extruder] = (float)code_value();
                    // make sure all extruders have some sane value for the filament size
                    filament_size[0] = (filament_size[0] == 0.0 ? DEFAULT_NOMINAL_FILAMENT_DIA : filament_size[0]);
#if EXTRUDERS > 1
                    filament_size[1] = (filament_size[1] == 0.0 ? DEFAULT_NOMINAL_FILAMENT_DIA : filament_size[1]);
#if EXTRUDERS > 2
                    filament_size[2] = (filament_size[2] == 0.0 ? DEFAULT_NOMINAL_FILAMENT_DIA : filament_size[2]);
#endif
#endif
                    volumetric_enabled = true;
                }
            } else {
                //reserved for setting filament diameter via UFID or filament measuring device
                break;
            }
            calculate_volumetric_multipliers();
        }
        break;
        case 201: // M201
            for(int8_t i=0; i < NUM_AXIS; i++) {
                if(code_seen(axis_codes[i])) {
                    max_acceleration_units_per_sq_second[i] = code_value();
                }
            }
            // steps per sq second need to be updated to agree with the units per sq second (as they are what is used in the planner)
            reset_acceleration_rates();
            break;
#if 0 // Not used for Sprinter/grbl gen6
        case 202: // M202
            for(int8_t i=0; i < NUM_AXIS; i++) {
                if(code_seen(axis_codes[i])) axis_travel_steps_per_sqr_second[i] = code_value() * axis_steps_per_unit[i];
            }
            break;
#endif
        case 203: // M203 max feedrate mm/sec
            for(int8_t i=0; i < NUM_AXIS; i++) {
                if(code_seen(axis_codes[i])) max_feedrate[i] = code_value();
            }
            break;
        case 204: { // M204 acclereration S normal moves T filmanent only moves
            if(code_seen('S')) acceleration = code_value() ;
            if(code_seen('T')) retract_acceleration = code_value() ;
        }
        break;
        case 205: { //M205 advanced settings:  minimum travel speed S=while printing T=travel only,  B=minimum segment time X= maximum xy jerk, Z=maximum Z jerk
            if(code_seen('S')) minimumfeedrate = code_value();
            if(code_seen('T')) mintravelfeedrate = code_value();
            if(code_seen('B')) minsegmenttime = code_value() ;
            if(code_seen('X')) max_xy_jerk = code_value() ;
            if(code_seen('Z')) max_z_jerk = code_value() ;
            if(code_seen('E')) max_e_jerk = code_value() ;
        }
        break;
        case 206: // M206 additional homing offset
            for(int8_t i=0; i < 3; i++) {
                if(code_seen(axis_codes[i])) add_homing[i] = code_value();
            }
#ifdef SCARA
            if(code_seen('T')) {     // Theta
                add_homing[X_AXIS] = code_value() ;
            }
            if(code_seen('P')) {     // Psi
                add_homing[Y_AXIS] = code_value() ;
            }
#endif
            break;
#ifdef DELTA
        case 665: // M665 set delta configurations L<diagonal_rod> R<delta_radius> S<segments_per_sec>
            if(code_seen('L')) {
                delta_diagonal_rod= code_value();
            }
            if(code_seen('R')) {
                delta_radius= code_value();
            }
            if(code_seen('S')) {
                delta_segments_per_second= code_value();
            }
            recalc_delta_settings(delta_radius, delta_diagonal_rod);
            break;
        case 666: // M666 set delta endstop adjustemnt
            for(int8_t i=0; i < 3; i++) {
                if(code_seen(axis_codes[i])) endstop_adj[i] = code_value();
            }
            break;
#endif
#ifdef FWRETRACT
        case 207: { //M207 - set retract length S[positive mm] F[feedrate mm/min] Z[additional zlift/hop]
            if(code_seen('S')) {
                retract_length = code_value() ;
            }
            if(code_seen('F')) {
                retract_feedrate = code_value()/60 ;
            }
            if(code_seen('Z')) {
                retract_zlift = code_value() ;
            }
        }
        break;
        case 208: { // M208 - set retract recover length S[positive mm surplus to the M207 S*] F[feedrate mm/min]
            if(code_seen('S')) {
                retract_recover_length = code_value() ;
            }
            if(code_seen('F')) {
                retract_recover_feedrate = code_value()/60 ;
            }
        }
        break;
        case 209: { // M209 - S<1=true/0=false> enable automatic retract detect if the slicer did not support G10/11: every normal extrude-only move will be classified as retract depending on the direction.
            if(code_seen('S')) {
                int t= code_value() ;
                switch(t) {
                case 0: {
                    autoretract_enabled=false;
                    retracted[0]=false;
#if EXTRUDERS > 1
                    retracted[1]=false;
#endif
#if EXTRUDERS > 2
                    retracted[2]=false;
#endif
                }
                break;
                case 1: {
                    autoretract_enabled=true;
                    retracted[0]=false;
#if EXTRUDERS > 1
                    retracted[1]=false;
#endif
#if EXTRUDERS > 2
                    retracted[2]=false;
#endif
                }
                break;
                default:
                    SERIAL_ECHO_START;
                    SERIAL_ECHOPGM(MSG_UNKNOWN_COMMAND);
                    SERIAL_ECHO(cmdbuffer[bufindr]);
                    SERIAL_ECHOLNPGM("\"");
                }
            }
        }
        break;
#endif // FWRETRACT
#if EXTRUDERS > 1
        case 218: { // M218 - set hotend offset (in mm), T<extruder_number> X<offset_on_X> Y<offset_on_Y>
            if(setTargetedHotend(218)) {
                break;
            }
            if(code_seen('X')) {
                extruder_offset[X_AXIS][tmp_extruder] = code_value();
            }
            if(code_seen('Y')) {
                extruder_offset[Y_AXIS][tmp_extruder] = code_value();
            }
#ifdef DUAL_X_CARRIAGE
            if(code_seen('Z')) {
                extruder_offset[Z_AXIS][tmp_extruder] = code_value();
            }
#endif
            SERIAL_ECHO_START;
            SERIAL_ECHOPGM(MSG_HOTEND_OFFSET);
            for(tmp_extruder = 0; tmp_extruder < EXTRUDERS; tmp_extruder++) {
                SERIAL_ECHO(" ");
                SERIAL_ECHO(extruder_offset[X_AXIS][tmp_extruder]);
                SERIAL_ECHO(",");
                SERIAL_ECHO(extruder_offset[Y_AXIS][tmp_extruder]);
#ifdef DUAL_X_CARRIAGE
                SERIAL_ECHO(",");
                SERIAL_ECHO(extruder_offset[Z_AXIS][tmp_extruder]);
#endif
            }
            SERIAL_ECHOLN("");
        }
        break;
#endif
        case 220: { // M220 S<factor in percent>- set speed factor override percentage
            if(code_seen('S')) {
                feedmultiply = code_value() ;
            }
        }
        break;
        case 221: { // M221 S<factor in percent>- set extrude factor override percentage
            if(code_seen('S')) {
                int tmp_code = code_value();
                if (code_seen('T')) {
                    if(setTargetedHotend(221)) {
                        break;
                    }
                    extruder_multiply[tmp_extruder] = tmp_code;
                } else {
                    extrudemultiply = tmp_code ;
                }
            }
        }
        break;
        case 226: { // M226 P<pin number> S<pin state>- Wait until the specified pin reaches the state required
            if(code_seen('P')) {
                int pin_number = code_value(); // pin number
                int pin_state = -1; // required pin state - default is inverted
                if(code_seen('S')) pin_state = code_value(); // required pin state
                if(pin_state >= -1 && pin_state <= 1) {
                    for(int8_t i = 0; i < (int8_t)(sizeof(sensitive_pins)/sizeof(int)); i++) {
                        if (sensitive_pins[i] == pin_number) {
                            pin_number = -1;
                            break;
                        }
                    }
                    if (pin_number > -1) {
                        int target = LOW;
                        st_synchronize();
                        pinMode(pin_number, INPUT);
                        switch(pin_state) {
                        case 1:
                            target = HIGH;
                            break;
                        case 0:
                            target = LOW;
                            break;
                        case -1:
                            target = !digitalRead(pin_number);
                            break;
                        }
                        while(digitalRead(pin_number) != target) {
                            manage_heater();
                            manage_inactivity();
                            lcd_update();
                        }
                    }
                }
            }
        }
        break;
#if NUM_SERVOS > 0
        case 280: { // M280 - set servo position absolute. P: servo index, S: angle or microseconds
            int servo_index = -1;
            int servo_position = 0;
            if (code_seen('P'))
                servo_index = code_value();
            if (code_seen('S')) {
                servo_position = code_value();
                if ((servo_index >= 0) && (servo_index < NUM_SERVOS)) {
#if defined (ENABLE_AUTO_BED_LEVELING) && (PROBE_SERVO_DEACTIVATION_DELAY > 0)
                    servos[servo_index].attach(0);
#endif
                    servos[servo_index].write(servo_position);
#if defined (ENABLE_AUTO_BED_LEVELING) && (PROBE_SERVO_DEACTIVATION_DELAY > 0)
                    delay(PROBE_SERVO_DEACTIVATION_DELAY);
                    servos[servo_index].detach();
#endif
                } else {
                    SERIAL_ECHO_START;
                    SERIAL_ECHO("Servo ");
                    SERIAL_ECHO(servo_index);
                    SERIAL_ECHOLN(" out of range");
                }
            } else if (servo_index >= 0) {
                SERIAL_PROTOCOL(MSG_OK);
                SERIAL_PROTOCOL(" Servo ");
                SERIAL_PROTOCOL(servo_index);
                SERIAL_PROTOCOL(": ");
                SERIAL_PROTOCOL(servos[servo_index].read());
                SERIAL_PROTOCOLLN("");
            }
        }
        break;
#endif // NUM_SERVOS > 0
#if (LARGE_FLASH == true && ( BEEPER > 0 || defined(ULTRALCD) || defined(LCD_USE_I2C_BUZZER)))
        case 300: { // M300
            int beepS = code_seen('S') ? code_value() : 110;
            int beepP = code_seen('P') ? code_value() : 1000;
            if (beepS > 0) {
#if BEEPER > 0
                tone(BEEPER, beepS);
                delay(beepP);
                noTone(BEEPER);
#elif defined(ULTRALCD)
                lcd_buzz(beepS, beepP);
#elif defined(LCD_USE_I2C_BUZZER)
                lcd_buzz(beepP, beepS);
#endif
            } else {
                delay(beepP);
            }
        }
        break;
#endif // M300
#ifdef PIDTEMP
        case 301: { // M301
            if(code_seen('P')) Kp = code_value();
            if(code_seen('I')) Ki = scalePID_i(code_value());
            if(code_seen('D')) Kd = scalePID_d(code_value());
#ifdef PID_ADD_EXTRUSION_RATE
            if(code_seen('C')) Kc = code_value();
#endif
            updatePID();
            SERIAL_PROTOCOL(MSG_OK);
            SERIAL_PROTOCOL(" p:");
            SERIAL_PROTOCOL(Kp);
            SERIAL_PROTOCOL(" i:");
            SERIAL_PROTOCOL(unscalePID_i(Ki));
            SERIAL_PROTOCOL(" d:");
            SERIAL_PROTOCOL(unscalePID_d(Kd));
#ifdef PID_ADD_EXTRUSION_RATE
            SERIAL_PROTOCOL(" c:");
            //Kc does not have scaling applied above, or in resetting defaults
            SERIAL_PROTOCOL(Kc);
#endif
            SERIAL_PROTOCOLLN("");
        }
        break;
#endif //PIDTEMP
#ifdef PIDTEMPBED
        case 304: { // M304
            if(code_seen('P')) bedKp = code_value();
            if(code_seen('I')) bedKi = scalePID_i(code_value());
            if(code_seen('D')) bedKd = scalePID_d(code_value());
            updatePID();
            SERIAL_PROTOCOL(MSG_OK);
            SERIAL_PROTOCOL(" p:");
            SERIAL_PROTOCOL(bedKp);
            SERIAL_PROTOCOL(" i:");
            SERIAL_PROTOCOL(unscalePID_i(bedKi));
            SERIAL_PROTOCOL(" d:");
            SERIAL_PROTOCOL(unscalePID_d(bedKd));
            SERIAL_PROTOCOLLN("");
        }
        break;
#endif //PIDTEMP
        case 240: { // M240  Triggers a camera by emulating a Canon RC-1 : http://www.doc-diy.net/photo/rc-1_hacked/
#ifdef CHDK
            SET_OUTPUT(CHDK);
            WRITE(CHDK, HIGH);
            chdkHigh = millis();
            chdkActive = true;
#else
#if defined(PHOTOGRAPH_PIN) && PHOTOGRAPH_PIN > -1
            const uint8_t NUM_PULSES=16;
            const float PULSE_LENGTH=0.01524;
            for(int i=0; i < NUM_PULSES; i++) {
                WRITE(PHOTOGRAPH_PIN, HIGH);
                _delay_ms(PULSE_LENGTH);
                WRITE(PHOTOGRAPH_PIN, LOW);
                _delay_ms(PULSE_LENGTH);
            }
            delay(7.33);
            for(int i=0; i < NUM_PULSES; i++) {
                WRITE(PHOTOGRAPH_PIN, HIGH);
                _delay_ms(PULSE_LENGTH);
                WRITE(PHOTOGRAPH_PIN, LOW);
                _delay_ms(PULSE_LENGTH);
            }
#endif
#endif //chdk end if
        }
        break;
#ifdef DOGLCD
        case 250: { // M250  Set LCD contrast value: C<value> (value 0..63)
            if (code_seen('C')) {
                lcd_setcontrast( ((int)code_value())&63 );
            }
            SERIAL_PROTOCOLPGM("lcd contrast value: ");
            SERIAL_PROTOCOL(lcd_contrast);
            SERIAL_PROTOCOLLN("");
        }
        break;
#endif
#ifdef PREVENT_DANGEROUS_EXTRUDE
        case 302: { // allow cold extrudes, or set the minimum extrude temperature
            float temp = .0;
            if (code_seen('S')) temp=code_value();
            set_extrude_min_temp(temp);
        }
        break;
#endif
        case 303: { // M303 PID autotune
            float temp = 150.0;
            int e=0;
            int c=5;
            if (code_seen('E')) e=code_value();
            if (e<0)
                temp=70;
            if (code_seen('S')) temp=code_value();
            if (code_seen('C')) c=code_value();
            PID_autotune(temp, e, c);
        }
        break;
#ifdef SCARA
        case 360:  // M360 SCARA Theta pos1
            SERIAL_ECHOLN(" Cal: Theta 0 ");
            //SoftEndsEnabled = false;              // Ignore soft endstops during calibration
            //SERIAL_ECHOLN(" Soft endstops disabled ");
            if(Stopped == false) {
                //get_coordinates(); // For X Y Z E F
                delta[X_AXIS] = 0;
                delta[Y_AXIS] = 120;
                calculate_SCARA_forward_Transform(delta);
                destination[X_AXIS] = delta[X_AXIS]/axis_scaling[X_AXIS];
                destination[Y_AXIS] = delta[Y_AXIS]/axis_scaling[Y_AXIS];
                prepare_move();
                //ClearToSend();
                return;
            }
            break;
        case 361:  // SCARA Theta pos2
            SERIAL_ECHOLN(" Cal: Theta 90 ");
            //SoftEndsEnabled = false;              // Ignore soft endstops during calibration
            //SERIAL_ECHOLN(" Soft endstops disabled ");
            if(Stopped == false) {
                //get_coordinates(); // For X Y Z E F
                delta[X_AXIS] = 90;
                delta[Y_AXIS] = 130;
                calculate_SCARA_forward_Transform(delta);
                destination[X_AXIS] = delta[X_AXIS]/axis_scaling[X_AXIS];
                destination[Y_AXIS] = delta[Y_AXIS]/axis_scaling[Y_AXIS];
                prepare_move();
                //ClearToSend();
                return;
            }
            break;
        case 362:  // SCARA Psi pos1
            SERIAL_ECHOLN(" Cal: Psi 0 ");
            //SoftEndsEnabled = false;              // Ignore soft endstops during calibration
            //SERIAL_ECHOLN(" Soft endstops disabled ");
            if(Stopped == false) {
                //get_coordinates(); // For X Y Z E F
                delta[X_AXIS] = 60;
                delta[Y_AXIS] = 180;
                calculate_SCARA_forward_Transform(delta);
                destination[X_AXIS] = delta[X_AXIS]/axis_scaling[X_AXIS];
                destination[Y_AXIS] = delta[Y_AXIS]/axis_scaling[Y_AXIS];
                prepare_move();
                //ClearToSend();
                return;
            }
            break;
        case 363:  // SCARA Psi pos2
            SERIAL_ECHOLN(" Cal: Psi 90 ");
            //SoftEndsEnabled = false;              // Ignore soft endstops during calibration
            //SERIAL_ECHOLN(" Soft endstops disabled ");
            if(Stopped == false) {
                //get_coordinates(); // For X Y Z E F
                delta[X_AXIS] = 50;
                delta[Y_AXIS] = 90;
                calculate_SCARA_forward_Transform(delta);
                destination[X_AXIS] = delta[X_AXIS]/axis_scaling[X_AXIS];
                destination[Y_AXIS] = delta[Y_AXIS]/axis_scaling[Y_AXIS];
                prepare_move();
                //ClearToSend();
                return;
            }
            break;
        case 364:  // SCARA Psi pos3 (90 deg to Theta)
            SERIAL_ECHOLN(" Cal: Theta-Psi 90 ");
            // SoftEndsEnabled = false;              // Ignore soft endstops during calibration
            //SERIAL_ECHOLN(" Soft endstops disabled ");
            if(Stopped == false) {
                //get_coordinates(); // For X Y Z E F
                delta[X_AXIS] = 45;
                delta[Y_AXIS] = 135;
                calculate_SCARA_forward_Transform(delta);
                destination[X_AXIS] = delta[X_AXIS]/axis_scaling[X_AXIS];
                destination[Y_AXIS] = delta[Y_AXIS]/axis_scaling[Y_AXIS];
                prepare_move();
                //ClearToSend();
                return;
            }
            break;
        case 365: // M364  Set SCARA scaling for X Y Z
            for(int8_t i=0; i < 3; i++) {
                if(code_seen(axis_codes[i])) {
                    axis_scaling[i] = code_value();
                }
            }
            break;
#endif
        case 400: { // M400 finish all moves
            st_synchronize();
        }
        break;
#if defined(ENABLE_AUTO_BED_LEVELING) && defined(SERVO_ENDSTOPS) && not defined(Z_PROBE_SLED)
        case 401: {
            engage_z_probe();    // Engage Z Servo endstop if available
        }
        break;
        case 402: {
            retract_z_probe();    // Retract Z Servo endstop if enabled
        }
        break;
#endif
#ifdef FILAMENT_SENSOR
        case 404: { //M404 Enter the nominal filament width (3mm, 1.75mm ) N<3.0> or display nominal filament width
#if (FILWIDTH_PIN > -1)
            if(code_seen('N')) filament_width_nominal=code_value();
            else {
                SERIAL_PROTOCOLPGM("Filament dia (nominal mm):");
                SERIAL_PROTOCOLLN(filament_width_nominal);
            }
#endif
        }
        break;
        case 405: { //M405 Turn on filament sensor for control
            if(code_seen('D')) meas_delay_cm=code_value();
            if(meas_delay_cm> MAX_MEASUREMENT_DELAY)
                meas_delay_cm = MAX_MEASUREMENT_DELAY;
            if(delay_index2 == -1) { //initialize the ring buffer if it has not been done since startup
                int temp_ratio = widthFil_to_size_ratio();
                for (delay_index1=0; delay_index1<(MAX_MEASUREMENT_DELAY+1); ++delay_index1 ) {
                    measurement_delay[delay_index1]=temp_ratio-100;  //subtract 100 to scale within a signed byte
                }
                delay_index1=0;
                delay_index2=0;
            }
            filament_sensor = true ;
            //SERIAL_PROTOCOLPGM("Filament dia (measured mm):");
            //SERIAL_PROTOCOL(filament_width_meas);
            //SERIAL_PROTOCOLPGM("Extrusion ratio(%):");
            //SERIAL_PROTOCOL(extrudemultiply);
        }
        break;
        case 406: { //M406 Turn off filament sensor for control
            filament_sensor = false ;
        }
        break;
        case 407: { //M407 Display measured filament diameter
            SERIAL_PROTOCOLPGM("Filament dia (measured mm):");
            SERIAL_PROTOCOLLN(filament_width_meas);
        }
        break;
#endif
        case 500: { // M500 Store settings in EEPROM
            Config_StoreSettings();
        }
        break;
        case 501: { // M501 Read settings from EEPROM
            Config_RetrieveSettings();
        }
        break;
        case 502: { // M502 Revert to default settings
            Config_ResetDefault();
        }
        break;
        case 503: { // M503 print settings currently in memory
            Config_PrintSettings();
        }
        break;
#ifdef ABORT_ON_ENDSTOP_HIT_FEATURE_ENABLED
        case 540: {
            if(code_seen('S')) abort_on_endstop_hit = code_value() > 0;
        }
        break;
#endif
#ifdef CUSTOM_M_CODE_SET_Z_PROBE_OFFSET
        case CUSTOM_M_CODE_SET_Z_PROBE_OFFSET: {
            float value;
            if (code_seen('Z')) {
                value = code_value();
                if ((Z_PROBE_OFFSET_RANGE_MIN <= value) && (value <= Z_PROBE_OFFSET_RANGE_MAX)) {
                    zprobe_zoffset = -value; // compare w/ line 278 of ConfigurationStore.cpp
                    SERIAL_ECHO_START;
                    SERIAL_ECHOLNPGM(MSG_ZPROBE_ZOFFSET " " MSG_OK);
                    SERIAL_PROTOCOLLN("");
                } else {
                    SERIAL_ECHO_START;
                    SERIAL_ECHOPGM(MSG_ZPROBE_ZOFFSET);
                    SERIAL_ECHOPGM(MSG_Z_MIN);
                    SERIAL_ECHO(Z_PROBE_OFFSET_RANGE_MIN);
                    SERIAL_ECHOPGM(MSG_Z_MAX);
                    SERIAL_ECHO(Z_PROBE_OFFSET_RANGE_MAX);
                    SERIAL_PROTOCOLLN("");
                }
            } else {
                SERIAL_ECHO_START;
                SERIAL_ECHOLNPGM(MSG_ZPROBE_ZOFFSET " : ");
                SERIAL_ECHO(-zprobe_zoffset);
                SERIAL_PROTOCOLLN("");
            }
            break;
        }
#endif // CUSTOM_M_CODE_SET_Z_PROBE_OFFSET
#ifdef FILAMENTCHANGEENABLE
        case 600: { //Pause for filament change X[pos] Y[pos] Z[relative lift] E[initial retract] L[later retract distance for removal]
            float target[4];
            float lastpos[4];
            target[X_AXIS]=current_position[X_AXIS];
            target[Y_AXIS]=current_position[Y_AXIS];
            target[Z_AXIS]=current_position[Z_AXIS];
            target[E_AXIS]=current_position[E_AXIS];
            lastpos[X_AXIS]=current_position[X_AXIS];
            lastpos[Y_AXIS]=current_position[Y_AXIS];
            lastpos[Z_AXIS]=current_position[Z_AXIS];
            lastpos[E_AXIS]=current_position[E_AXIS];
            //retract by E
            if(code_seen('E')) {
                target[E_AXIS]+= code_value();
            } else {
#ifdef FILAMENTCHANGE_FIRSTRETRACT
                target[E_AXIS]+= FILAMENTCHANGE_FIRSTRETRACT ;
#endif
            }
            plan_buffer_line(target[X_AXIS], target[Y_AXIS], target[Z_AXIS], target[E_AXIS], feedrate/60, active_extruder);
            //lift Z
            if(code_seen('Z')) {
                target[Z_AXIS]+= code_value();
            } else {
#ifdef FILAMENTCHANGE_ZADD
                target[Z_AXIS]+= FILAMENTCHANGE_ZADD ;
#endif
            }
            plan_buffer_line(target[X_AXIS], target[Y_AXIS], target[Z_AXIS], target[E_AXIS], feedrate/60, active_extruder);
            //move xy
            if(code_seen('X')) {
                target[X_AXIS]+= code_value();
            } else {
#ifdef FILAMENTCHANGE_XPOS
                target[X_AXIS]= FILAMENTCHANGE_XPOS ;
#endif
            }
            if(code_seen('Y')) {
                target[Y_AXIS]= code_value();
            } else {
#ifdef FILAMENTCHANGE_YPOS
                target[Y_AXIS]= FILAMENTCHANGE_YPOS ;
#endif
            }
            plan_buffer_line(target[X_AXIS], target[Y_AXIS], target[Z_AXIS], target[E_AXIS], feedrate/60, active_extruder);
            if(code_seen('L')) {
                target[E_AXIS]+= code_value();
            } else {
#ifdef FILAMENTCHANGE_FINALRETRACT
                target[E_AXIS]+= FILAMENTCHANGE_FINALRETRACT ;
#endif
            }
            plan_buffer_line(target[X_AXIS], target[Y_AXIS], target[Z_AXIS], target[E_AXIS], feedrate/60, active_extruder);
            //finish moves
            st_synchronize();
            //disable extruder steppers so filament can be removed
            disable_e0();
            disable_e1();
            disable_e2();
            delay(100);
            LCD_ALERTMESSAGEPGM(MSG_FILAMENTCHANGE);
            uint8_t cnt=0;
            while(!lcd_clicked()) {
                cnt++;
                manage_heater();
                manage_inactivity(true);
                lcd_update();
                if(cnt==0) {
#if BEEPER > 0
                    SET_OUTPUT(BEEPER);
                    WRITE(BEEPER,HIGH);
                    delay(3);
                    WRITE(BEEPER,LOW);
                    delay(3);
#else
#if !defined(LCD_FEEDBACK_FREQUENCY_HZ) || !defined(LCD_FEEDBACK_FREQUENCY_DURATION_MS)
                    lcd_buzz(1000/6,100);
#else
                    lcd_buzz(LCD_FEEDBACK_FREQUENCY_DURATION_MS,LCD_FEEDBACK_FREQUENCY_HZ);
#endif
#endif
                }
            }
            //return to normal
            if(code_seen('L')) {
                target[E_AXIS]+= -code_value();
            } else {
#ifdef FILAMENTCHANGE_FINALRETRACT
                target[E_AXIS]+=(-1)*FILAMENTCHANGE_FINALRETRACT ;
#endif
            }
            current_position[E_AXIS]=target[E_AXIS]; //the long retract of L is compensated by manual filament feeding
            plan_set_e_position(current_position[E_AXIS]);
            plan_buffer_line(target[X_AXIS], target[Y_AXIS], target[Z_AXIS], target[E_AXIS], feedrate/60, active_extruder); //should do nothing
            plan_buffer_line(lastpos[X_AXIS], lastpos[Y_AXIS], target[Z_AXIS], target[E_AXIS], feedrate/60, active_extruder); //move xy back
            plan_buffer_line(lastpos[X_AXIS], lastpos[Y_AXIS], lastpos[Z_AXIS], target[E_AXIS], feedrate/60, active_extruder); //move z back
            plan_buffer_line(lastpos[X_AXIS], lastpos[Y_AXIS], lastpos[Z_AXIS], lastpos[E_AXIS], feedrate/60, active_extruder); //final untretract
        }
        break;
#endif //FILAMENTCHANGEENABLE
#ifdef DUAL_X_CARRIAGE
        case 605: // Set dual x-carriage movement mode:
            //    M605 S0: Full control mode. The slicer has full control over x-carriage movement
            //    M605 S1: Auto-park mode. The inactive head will auto park/unpark without slicer involvement
            //    M605 S2 [Xnnn] [Rmmm]: Duplication mode. The second extruder will duplicate the first with nnn
            //                         millimeters x-offset and an optional differential hotend temperature of
            //                         mmm degrees. E.g., with "M605 S2 X100 R2" the second extruder will duplicate
            //                         the first with a spacing of 100mm in the x direction and 2 degrees hotter.
            //
            //    Note: the X axis should be homed after changing dual x-carriage mode.
        {
            st_synchronize();
            if (code_seen('S'))
                dual_x_carriage_mode = code_value();
            if (dual_x_carriage_mode == DXC_DUPLICATION_MODE) {
                if (code_seen('X'))
                    duplicate_extruder_x_offset = max(code_value(),X2_MIN_POS - x_home_pos(0));
                if (code_seen('R'))
                    duplicate_extruder_temp_offset = code_value();
                SERIAL_ECHO_START;
                SERIAL_ECHOPGM(MSG_HOTEND_OFFSET);
                SERIAL_ECHO(" ");
                SERIAL_ECHO(extruder_offset[X_AXIS][0]);
                SERIAL_ECHO(",");
                SERIAL_ECHO(extruder_offset[Y_AXIS][0]);
                SERIAL_ECHO(" ");
                SERIAL_ECHO(duplicate_extruder_x_offset);
                SERIAL_ECHO(",");
                SERIAL_ECHOLN(extruder_offset[Y_AXIS][1]);
            } else if (dual_x_carriage_mode != DXC_FULL_CONTROL_MODE && dual_x_carriage_mode != DXC_AUTO_PARK_MODE) {
                dual_x_carriage_mode = DEFAULT_DUAL_X_CARRIAGE_MODE;
            }
            active_extruder_parked = false;
            extruder_duplication_enabled = false;
            delayed_move_time = 0;
        }
        break;
#endif //DUAL_X_CARRIAGE
        case 907: { // M907 Set digital trimpot motor current using axis codes.
#if defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1
            for(int i=0; i<NUM_AXIS; i++) if(code_seen(axis_codes[i])) digipot_current(i,code_value());
            if(code_seen('B')) digipot_current(4,code_value());
            if(code_seen('S')) for(int i=0; i<=4; i++) digipot_current(i,code_value());
#endif
#ifdef MOTOR_CURRENT_PWM_XY_PIN
            if(code_seen('X')) digipot_current(0, code_value());
#endif
#ifdef MOTOR_CURRENT_PWM_Z_PIN
            if(code_seen('Z')) digipot_current(1, code_value());
#endif
#ifdef MOTOR_CURRENT_PWM_E_PIN
            if(code_seen('E')) digipot_current(2, code_value());
#endif
#ifdef DIGIPOT_I2C
            // this one uses actual amps in floating point
            for(int i=0; i<NUM_AXIS; i++) if(code_seen(axis_codes[i])) digipot_i2c_set_current(i, code_value());
            // for each additional extruder (named B,C,D,E..., channels 4,5,6,7...)
            for(int i=NUM_AXIS; i<DIGIPOT_I2C_NUM_CHANNELS; i++) if(code_seen('B'+i-NUM_AXIS)) digipot_i2c_set_current(i, code_value());
#endif
        }
        break;
        case 908: { // M908 Control digital trimpot directly.
#if defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1
            uint8_t channel,current;
            if(code_seen('P')) channel=code_value();
            if(code_seen('S')) current=code_value();
            digitalPotWrite(channel, current);
#endif
        }
        break;
        case 350: { // M350 Set microstepping mode. Warning: Steps per unit remains unchanged. S code sets stepping mode for all drivers.
#if defined(X_MS1_PIN) && X_MS1_PIN > -1
            if(code_seen('S')) for(int i=0; i<=4; i++) microstep_mode(i,code_value());
            for(int i=0; i<NUM_AXIS; i++) if(code_seen(axis_codes[i])) microstep_mode(i,(uint8_t)code_value());
            if(code_seen('B')) microstep_mode(4,code_value());
            microstep_readings();
#endif
        }
        break;
        case 351: { // M351 Toggle MS1 MS2 pins directly, S# determines MS1 or MS2, X# sets the pin high/low.
#if defined(X_MS1_PIN) && X_MS1_PIN > -1
            if(code_seen('S')) switch((int)code_value()) {
                case 1:
                    for(int i=0; i<NUM_AXIS; i++) if(code_seen(axis_codes[i])) microstep_ms(i,code_value(),-1);
                    if(code_seen('B')) microstep_ms(4,code_value(),-1);
                    break;
                case 2:
                    for(int i=0; i<NUM_AXIS; i++) if(code_seen(axis_codes[i])) microstep_ms(i,-1,code_value());
                    if(code_seen('B')) microstep_ms(4,-1,code_value());
                    break;
                }
            microstep_readings();
#endif
        }
        break;
        case 999: // M999: Restart after being stopped
            Stopped = false;
            lcd_reset_alert_level();
            gcode_LastN = Stopped_gcode_LastN;
            FlushSerialRequestResend();
            break;
        }
    }
    else if(code_seen('T')) {
        tmp_extruder = code_value();
        if(tmp_extruder >= EXTRUDERS) {
            SERIAL_ECHO_START;
            SERIAL_ECHO("T");
            SERIAL_ECHO(tmp_extruder);
            SERIAL_ECHOLN(MSG_INVALID_EXTRUDER);
        } else {
            boolean make_move = false;
            if(code_seen('F')) {
                make_move = true;
                next_feedrate = code_value();
                if(next_feedrate > 0.0) {
                    feedrate = next_feedrate;
                }
            }
#if EXTRUDERS > 1
            if(tmp_extruder != active_extruder) {
                // Save current position to return to after applying extruder offset
                memcpy(destination, current_position, sizeof(destination));
#ifdef DUAL_X_CARRIAGE
                if (dual_x_carriage_mode == DXC_AUTO_PARK_MODE && Stopped == false &&
                        (delayed_move_time != 0 || current_position[X_AXIS] != x_home_pos(active_extruder))) {
                    // Park old head: 1) raise 2) move to park position 3) lower
                    plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS] + TOOLCHANGE_PARK_ZLIFT,
                                     current_position[E_AXIS], max_feedrate[Z_AXIS], active_extruder);
                    plan_buffer_line(x_home_pos(active_extruder), current_position[Y_AXIS], current_position[Z_AXIS] + TOOLCHANGE_PARK_ZLIFT,
                                     current_position[E_AXIS], max_feedrate[X_AXIS], active_extruder);
                    plan_buffer_line(x_home_pos(active_extruder), current_position[Y_AXIS], current_position[Z_AXIS],
                                     current_position[E_AXIS], max_feedrate[Z_AXIS], active_extruder);
                    st_synchronize();
                }
                // apply Y & Z extruder offset (x offset is already used in determining home pos)
                current_position[Y_AXIS] = current_position[Y_AXIS] -
                                           extruder_offset[Y_AXIS][active_extruder] +
                                           extruder_offset[Y_AXIS][tmp_extruder];
                current_position[Z_AXIS] = current_position[Z_AXIS] -
                                           extruder_offset[Z_AXIS][active_extruder] +
                                           extruder_offset[Z_AXIS][tmp_extruder];
                active_extruder = tmp_extruder;
                // This function resets the max/min values - the current position may be overwritten below.
                axis_is_at_home(X_AXIS);
                if (dual_x_carriage_mode == DXC_FULL_CONTROL_MODE) {
                    current_position[X_AXIS] = inactive_extruder_x_pos;
                    inactive_extruder_x_pos = destination[X_AXIS];
                } else if (dual_x_carriage_mode == DXC_DUPLICATION_MODE) {
                    active_extruder_parked = (active_extruder == 0); // this triggers the second extruder to move into the duplication position
                    if (active_extruder == 0 || active_extruder_parked)
                        current_position[X_AXIS] = inactive_extruder_x_pos;
                    else
                        current_position[X_AXIS] = destination[X_AXIS] + duplicate_extruder_x_offset;
                    inactive_extruder_x_pos = destination[X_AXIS];
                    extruder_duplication_enabled = false;
                } else {
                    // record raised toolhead position for use by unpark
                    memcpy(raised_parked_position, current_position, sizeof(raised_parked_position));
                    raised_parked_position[Z_AXIS] += TOOLCHANGE_UNPARK_ZLIFT;
                    active_extruder_parked = true;
                    delayed_move_time = 0;
                }
#else
                // Offset extruder (only by XY)
                int i;
                for(i = 0; i < 2; i++) {
                    current_position[i] = current_position[i] -
                                          extruder_offset[i][active_extruder] +
                                          extruder_offset[i][tmp_extruder];
                }
                // Set the new active extruder and position
                active_extruder = tmp_extruder;
#endif //else DUAL_X_CARRIAGE
#ifdef DELTA
                calculate_delta(current_position); // change cartesian kinematic  to  delta kinematic;
                //sent position to plan_set_position();
                plan_set_position(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS],current_position[E_AXIS]);
#else
                plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
#endif
                // Move to the old position if 'F' was in the parameters
                if(make_move && Stopped == false) {
                    prepare_move();
                }
            }
#endif
            SERIAL_ECHO_START;
            SERIAL_ECHO(MSG_ACTIVE_EXTRUDER);
            SERIAL_PROTOCOLLN((int)active_extruder);
        }
    } else {
        SERIAL_ECHO_START;
        SERIAL_ECHOPGM(MSG_UNKNOWN_COMMAND);
        SERIAL_ECHO(cmdbuffer[bufindr]);
        SERIAL_ECHOLNPGM("\"");
    }
    ClearToSend();
}

void FlushSerialRequestResend() {
    //char cmdbuffer[bufindr][100]="Resend:";
    MYSERIAL.flush();
    SERIAL_PROTOCOLPGM(MSG_RESEND);
    SERIAL_PROTOCOLLN(gcode_LastN + 1);
    ClearToSend();
}

void ClearToSend() {
    previous_millis_cmd = millis();
#ifdef SDSUPPORT
    if(fromsd[bufindr])
        return;
#endif //SDSUPPORT
    SERIAL_PROTOCOLLNPGM(MSG_OK);
}

void get_coordinates() {
    bool seen[4]= {false,false,false,false};
    for(int8_t i=0; i < NUM_AXIS; i++) {
        if(code_seen(axis_codes[i])) {
            destination[i] = (float)code_value() + (axis_relative_modes[i] || relative_mode)*current_position[i];
            seen[i]=true;
        } else destination[i] = current_position[i]; //Are these else lines really needed?
    }
    if(code_seen('F')) {
        next_feedrate = code_value();
        if(next_feedrate > 0.0) feedrate = next_feedrate;
    }
}

void get_arc_coordinates() {
#ifdef SF_ARC_FIX
    bool relative_mode_backup = relative_mode;
    relative_mode = true;
#endif
    get_coordinates();
#ifdef SF_ARC_FIX
    relative_mode=relative_mode_backup;
#endif
    if(code_seen('I')) {
        offset[0] = code_value();
    } else {
        offset[0] = 0.0;
    }
    if(code_seen('J')) {
        offset[1] = code_value();
    } else {
        offset[1] = 0.0;
    }
}

void clamp_to_software_endstops(float target[3]) {
    if (min_software_endstops) {
        if (target[X_AXIS] < min_pos[X_AXIS]) target[X_AXIS] = min_pos[X_AXIS];
        if (target[Y_AXIS] < min_pos[Y_AXIS]) target[Y_AXIS] = min_pos[Y_AXIS];
        float negative_z_offset = 0;
#ifdef ENABLE_AUTO_BED_LEVELING
        if (Z_PROBE_OFFSET_FROM_EXTRUDER < 0) negative_z_offset = negative_z_offset + Z_PROBE_OFFSET_FROM_EXTRUDER;
        if (add_homing[Z_AXIS] < 0) negative_z_offset = negative_z_offset + add_homing[Z_AXIS];
#endif
        if (target[Z_AXIS] < min_pos[Z_AXIS]+negative_z_offset) target[Z_AXIS] = min_pos[Z_AXIS]+negative_z_offset;
    }
    if (max_software_endstops) {
        if (target[X_AXIS] > max_pos[X_AXIS]) target[X_AXIS] = max_pos[X_AXIS];
        if (target[Y_AXIS] > max_pos[Y_AXIS]) target[Y_AXIS] = max_pos[Y_AXIS];
        if (target[Z_AXIS] > max_pos[Z_AXIS]) target[Z_AXIS] = max_pos[Z_AXIS];
    }
}

#ifdef DELTA
void recalc_delta_settings(float radius, float diagonal_rod) {
    delta_tower1_x= -SIN_60*radius; // front left tower
    delta_tower1_y= -COS_60*radius;
    delta_tower2_x=  SIN_60*radius; // front right tower
    delta_tower2_y= -COS_60*radius;
    delta_tower3_x= 0.0;                  // back middle tower
    delta_tower3_y= radius;
    delta_diagonal_rod_2= sq(diagonal_rod);
}

void calculate_delta(float cartesian[3]) {
    delta[X_AXIS] = sqrt(delta_diagonal_rod_2
                         - sq(delta_tower1_x-cartesian[X_AXIS])
                         - sq(delta_tower1_y-cartesian[Y_AXIS])
                        ) + cartesian[Z_AXIS];
    delta[Y_AXIS] = sqrt(delta_diagonal_rod_2
                         - sq(delta_tower2_x-cartesian[X_AXIS])
                         - sq(delta_tower2_y-cartesian[Y_AXIS])
                        ) + cartesian[Z_AXIS];
    delta[Z_AXIS] = sqrt(delta_diagonal_rod_2
                         - sq(delta_tower3_x-cartesian[X_AXIS])
                         - sq(delta_tower3_y-cartesian[Y_AXIS])
                        ) + cartesian[Z_AXIS];
    /*
    SERIAL_ECHOPGM("cartesian x="); SERIAL_ECHO(cartesian[X_AXIS]);
    SERIAL_ECHOPGM(" y="); SERIAL_ECHO(cartesian[Y_AXIS]);
    SERIAL_ECHOPGM(" z="); SERIAL_ECHOLN(cartesian[Z_AXIS]);

    SERIAL_ECHOPGM("delta x="); SERIAL_ECHO(delta[X_AXIS]);
    SERIAL_ECHOPGM(" y="); SERIAL_ECHO(delta[Y_AXIS]);
    SERIAL_ECHOPGM(" z="); SERIAL_ECHOLN(delta[Z_AXIS]);
    */
}
#endif

void prepare_move() {
    clamp_to_software_endstops(destination);
    previous_millis_cmd = millis();
#ifdef SCARA //for now same as delta-code
    float difference[NUM_AXIS];
    for (int8_t i=0; i < NUM_AXIS; i++) {
        difference[i] = destination[i] - current_position[i];
    }
    float cartesian_mm = sqrt(	sq(difference[X_AXIS]) +
                                sq(difference[Y_AXIS]) +
                                sq(difference[Z_AXIS]));
    if (cartesian_mm < 0.000001) {
        cartesian_mm = abs(difference[E_AXIS]);
    }
    if (cartesian_mm < 0.000001) {
        return;
    }
    float seconds = 6000 * cartesian_mm / feedrate / feedmultiply;
    int steps = max(1, int(scara_segments_per_second * seconds));
//SERIAL_ECHOPGM("mm="); SERIAL_ECHO(cartesian_mm);
//SERIAL_ECHOPGM(" seconds="); SERIAL_ECHO(seconds);
//SERIAL_ECHOPGM(" steps="); SERIAL_ECHOLN(steps);
    for (int s = 1; s <= steps; s++) {
        float fraction = float(s) / float(steps);
        for(int8_t i=0; i < NUM_AXIS; i++) {
            destination[i] = current_position[i] + difference[i] * fraction;
        }
        calculate_delta(destination);
        //SERIAL_ECHOPGM("destination[X_AXIS]="); SERIAL_ECHOLN(destination[X_AXIS]);
        //SERIAL_ECHOPGM("destination[Y_AXIS]="); SERIAL_ECHOLN(destination[Y_AXIS]);
        //SERIAL_ECHOPGM("destination[Z_AXIS]="); SERIAL_ECHOLN(destination[Z_AXIS]);
        //SERIAL_ECHOPGM("delta[X_AXIS]="); SERIAL_ECHOLN(delta[X_AXIS]);
        //SERIAL_ECHOPGM("delta[Y_AXIS]="); SERIAL_ECHOLN(delta[Y_AXIS]);
        //SERIAL_ECHOPGM("delta[Z_AXIS]="); SERIAL_ECHOLN(delta[Z_AXIS]);
        plan_buffer_line(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS],
                         destination[E_AXIS], feedrate*feedmultiply/60/100.0,
                         active_extruder);
    }
#endif // SCARA
#ifdef DELTA
    float difference[NUM_AXIS];
    for (int8_t i=0; i < NUM_AXIS; i++) {
        difference[i] = destination[i] - current_position[i];
    }
    float cartesian_mm = sqrt(sq(difference[X_AXIS]) +
                              sq(difference[Y_AXIS]) +
                              sq(difference[Z_AXIS]));
    if (cartesian_mm < 0.000001) {
        cartesian_mm = abs(difference[E_AXIS]);
    }
    if (cartesian_mm < 0.000001) {
        return;
    }
    float seconds = 6000 * cartesian_mm / feedrate / feedmultiply;
    int steps = max(1, int(delta_segments_per_second * seconds));
    // SERIAL_ECHOPGM("mm="); SERIAL_ECHO(cartesian_mm);
    // SERIAL_ECHOPGM(" seconds="); SERIAL_ECHO(seconds);
    // SERIAL_ECHOPGM(" steps="); SERIAL_ECHOLN(steps);
    for (int s = 1; s <= steps; s++) {
        float fraction = float(s) / float(steps);
        for(int8_t i=0; i < NUM_AXIS; i++) {
            destination[i] = current_position[i] + difference[i] * fraction;
        }
        calculate_delta(destination);
        plan_buffer_line(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS],
                         destination[E_AXIS], feedrate*feedmultiply/60/100.0,
                         active_extruder);
    }
#endif // DELTA
#ifdef DUAL_X_CARRIAGE
    if (active_extruder_parked) {
        if (dual_x_carriage_mode == DXC_DUPLICATION_MODE && active_extruder == 0) {
            // move duplicate extruder into correct duplication position.
            plan_set_position(inactive_extruder_x_pos, current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
            plan_buffer_line(current_position[X_AXIS] + duplicate_extruder_x_offset, current_position[Y_AXIS], current_position[Z_AXIS],
                             current_position[E_AXIS], max_feedrate[X_AXIS], 1);
            plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
            st_synchronize();
            extruder_duplication_enabled = true;
            active_extruder_parked = false;
        } else if (dual_x_carriage_mode == DXC_AUTO_PARK_MODE) { // handle unparking of head
            if (current_position[E_AXIS] == destination[E_AXIS]) {
                // this is a travel move - skit it but keep track of current position (so that it can later
                // be used as start of first non-travel move)
                if (delayed_move_time != 0xFFFFFFFFUL) {
                    memcpy(current_position, destination, sizeof(current_position));
                    if (destination[Z_AXIS] > raised_parked_position[Z_AXIS])
                        raised_parked_position[Z_AXIS] = destination[Z_AXIS];
                    delayed_move_time = millis();
                    return;
                }
            }
            delayed_move_time = 0;
            // unpark extruder: 1) raise, 2) move into starting XY position, 3) lower
            plan_buffer_line(raised_parked_position[X_AXIS], raised_parked_position[Y_AXIS], raised_parked_position[Z_AXIS],    current_position[E_AXIS], max_feedrate[Z_AXIS], active_extruder);
            plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], raised_parked_position[Z_AXIS],
                             current_position[E_AXIS], min(max_feedrate[X_AXIS],max_feedrate[Y_AXIS]), active_extruder);
            plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS],
                             current_position[E_AXIS], max_feedrate[Z_AXIS], active_extruder);
            active_extruder_parked = false;
        }
    }
#endif //DUAL_X_CARRIAGE
#if ! (defined DELTA || defined SCARA)
    // Do not use feedmultiply for E or Z only moves
    if( (current_position[X_AXIS] == destination [X_AXIS]) && (current_position[Y_AXIS] == destination [Y_AXIS])) {
        plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate/60, active_extruder);
    } else {
        plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate*feedmultiply/60/100.0, active_extruder);
    }
#endif // !(DELTA || SCARA)
    for(int8_t i=0; i < NUM_AXIS; i++) {
        current_position[i] = destination[i];
    }
}

void prepare_arc_move(char isclockwise) {
    float r = hypot(offset[X_AXIS], offset[Y_AXIS]); // Compute arc radius for mc_arc
    // Trace the arc
    mc_arc(current_position, destination, offset, X_AXIS, Y_AXIS, Z_AXIS, feedrate*feedmultiply/60/100.0, r, isclockwise, active_extruder);
    // As far as the parser is concerned, the position is now == target. In reality the
    // motion control system might still be processing the action and the real tool position
    // in any intermediate location.
    for(int8_t i=0; i < NUM_AXIS; i++) {
        current_position[i] = destination[i];
    }
    previous_millis_cmd = millis();
}

#if defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1

#if defined(FAN_PIN)
    #if CONTROLLERFAN_PIN == FAN_PIN
        #error "You cannot set CONTROLLERFAN_PIN equal to FAN_PIN"
    #endif
#endif

unsigned long lastMotor = 0; //Save the time for when a motor was turned on last
unsigned long lastMotorCheck = 0;

void controllerFan() {
    if ((millis() - lastMotorCheck) >= 2500) { //Not a time critical function, so we only check every 2500ms
        lastMotorCheck = millis();
        if(!READ(X_ENABLE_PIN) || !READ(Y_ENABLE_PIN) || !READ(Z_ENABLE_PIN) || (soft_pwm_bed > 0)
#if EXTRUDERS > 2
                || !READ(E2_ENABLE_PIN)
#endif
#if EXTRUDER > 1
#if defined(X2_ENABLE_PIN) && X2_ENABLE_PIN > -1
                || !READ(X2_ENABLE_PIN)
#endif
                || !READ(E1_ENABLE_PIN)
#endif
                || !READ(E0_ENABLE_PIN)) { //If any of the drivers are enabled...
            lastMotor = millis(); //... set time to NOW so the fan will turn on
        }
        if ((millis() - lastMotor) >= (CONTROLLERFAN_SECS*1000UL) || lastMotor == 0) { //If the last time any driver was enabled, is longer since than CONTROLLERSEC...
            digitalWrite(CONTROLLERFAN_PIN, 0);
            analogWrite(CONTROLLERFAN_PIN, 0);
        } else {
            // allows digital or PWM fan output to be used (see M42 handling)
            digitalWrite(CONTROLLERFAN_PIN, CONTROLLERFAN_SPEED);
            analogWrite(CONTROLLERFAN_PIN, CONTROLLERFAN_SPEED);
        }
    }
}
#endif

#ifdef SCARA
void calculate_SCARA_forward_Transform(float f_scara[3]) {
    // Perform forward kinematics, and place results in delta[3]
    // The maths and first version has been done by QHARLEY . Integrated into masterbranch 06/2014 and slightly restructured by Joachim Cerny in June 2014
    float x_sin, x_cos, y_sin, y_cos;
    //SERIAL_ECHOPGM("f_delta x="); SERIAL_ECHO(f_scara[X_AXIS]);
    //SERIAL_ECHOPGM(" y="); SERIAL_ECHO(f_scara[Y_AXIS]);
    x_sin = sin(f_scara[X_AXIS]/SCARA_RAD2DEG) * Linkage_1;
    x_cos = cos(f_scara[X_AXIS]/SCARA_RAD2DEG) * Linkage_1;
    y_sin = sin(f_scara[Y_AXIS]/SCARA_RAD2DEG) * Linkage_2;
    y_cos = cos(f_scara[Y_AXIS]/SCARA_RAD2DEG) * Linkage_2;
    //  SERIAL_ECHOPGM(" x_sin="); SERIAL_ECHO(x_sin);
    //  SERIAL_ECHOPGM(" x_cos="); SERIAL_ECHO(x_cos);
    //  SERIAL_ECHOPGM(" y_sin="); SERIAL_ECHO(y_sin);
    //  SERIAL_ECHOPGM(" y_cos="); SERIAL_ECHOLN(y_cos);
    delta[X_AXIS] = x_cos + y_cos + SCARA_offset_x;  //theta
    delta[Y_AXIS] = x_sin + y_sin + SCARA_offset_y;  //theta+phi
    //SERIAL_ECHOPGM(" delta[X_AXIS]="); SERIAL_ECHO(delta[X_AXIS]);
    //SERIAL_ECHOPGM(" delta[Y_AXIS]="); SERIAL_ECHOLN(delta[Y_AXIS]);
}

void calculate_delta(float cartesian[3]) {
    //reverse kinematics.
    // Perform reversed kinematics, and place results in delta[3]
    // The maths and first version has been done by QHARLEY . Integrated into masterbranch 06/2014 and slightly restructured by Joachim Cerny in June 2014
    float SCARA_pos[2];
    static float SCARA_C2, SCARA_S2, SCARA_K1, SCARA_K2, SCARA_theta, SCARA_psi;
    SCARA_pos[X_AXIS] = cartesian[X_AXIS] * axis_scaling[X_AXIS] - SCARA_offset_x;  //Translate SCARA to standard X Y
    SCARA_pos[Y_AXIS] = cartesian[Y_AXIS] * axis_scaling[Y_AXIS] - SCARA_offset_y;  // With scaling factor.
#if (Linkage_1 == Linkage_2)
    SCARA_C2 = ( ( sq(SCARA_pos[X_AXIS]) + sq(SCARA_pos[Y_AXIS]) ) / (2 * (float)L1_2) ) - 1;
#else
    SCARA_C2 =   ( sq(SCARA_pos[X_AXIS]) + sq(SCARA_pos[Y_AXIS]) - (float)L1_2 - (float)L2_2 ) / 45000;
#endif
    SCARA_S2 = sqrt( 1 - sq(SCARA_C2) );
    SCARA_K1 = Linkage_1 + Linkage_2 * SCARA_C2;
    SCARA_K2 = Linkage_2 * SCARA_S2;
    SCARA_theta = ( atan2(SCARA_pos[X_AXIS],SCARA_pos[Y_AXIS])-atan2(SCARA_K1, SCARA_K2) ) * -1;
    SCARA_psi   =   atan2(SCARA_S2,SCARA_C2);
    delta[X_AXIS] = SCARA_theta * SCARA_RAD2DEG;  // Multiply by 180/Pi  -  theta is support arm angle
    delta[Y_AXIS] = (SCARA_theta + SCARA_psi) * SCARA_RAD2DEG;  //       -  equal to sub arm angle (inverted motor)
    delta[Z_AXIS] = cartesian[Z_AXIS];
    /*
    SERIAL_ECHOPGM("cartesian x="); SERIAL_ECHO(cartesian[X_AXIS]);
    SERIAL_ECHOPGM(" y="); SERIAL_ECHO(cartesian[Y_AXIS]);
    SERIAL_ECHOPGM(" z="); SERIAL_ECHOLN(cartesian[Z_AXIS]);

    SERIAL_ECHOPGM("scara x="); SERIAL_ECHO(SCARA_pos[X_AXIS]);
    SERIAL_ECHOPGM(" y="); SERIAL_ECHOLN(SCARA_pos[Y_AXIS]);

    SERIAL_ECHOPGM("delta x="); SERIAL_ECHO(delta[X_AXIS]);
    SERIAL_ECHOPGM(" y="); SERIAL_ECHO(delta[Y_AXIS]);
    SERIAL_ECHOPGM(" z="); SERIAL_ECHOLN(delta[Z_AXIS]);

    SERIAL_ECHOPGM("C2="); SERIAL_ECHO(SCARA_C2);
    SERIAL_ECHOPGM(" S2="); SERIAL_ECHO(SCARA_S2);
    SERIAL_ECHOPGM(" Theta="); SERIAL_ECHO(SCARA_theta);
    SERIAL_ECHOPGM(" Psi="); SERIAL_ECHOLN(SCARA_psi);
    SERIAL_ECHOLN(" ");*/
}

#endif

#ifdef TEMP_STAT_LEDS
static bool blue_led = false;
static bool red_led = false;
static uint32_t stat_update = 0;

void handle_status_leds(void) {
    float max_temp = 0.0;
    if(millis() > stat_update) {
        stat_update += 500; // Update every 0.5s
        for (int8_t cur_extruder = 0; cur_extruder < EXTRUDERS; ++cur_extruder) {
            max_temp = max(max_temp, degHotend(cur_extruder));
            max_temp = max(max_temp, degTargetHotend(cur_extruder));
        }
#if defined(TEMP_BED_PIN) && TEMP_BED_PIN > -1
        max_temp = max(max_temp, degTargetBed());
        max_temp = max(max_temp, degBed());
#endif
        if((max_temp > 55.0) && (red_led == false)) {
            digitalWrite(STAT_LED_RED, 1);
            digitalWrite(STAT_LED_BLUE, 0);
            red_led = true;
            blue_led = false;
        }
        if((max_temp < 54.0) && (blue_led == false)) {
            digitalWrite(STAT_LED_RED, 0);
            digitalWrite(STAT_LED_BLUE, 1);
            red_led = false;
            blue_led = true;
        }
    }
}
#endif

void manage_inactivity(bool ignore_stepper_queue/*=false*/) { //default argument set in Marlin.h
#if defined(KILL_PIN) && KILL_PIN > -1
    static int killCount = 0;   // make the inactivity button a bit less responsive
    const int KILL_DELAY = 10000;
#endif
#if defined(HOME_PIN) && HOME_PIN > -1
    static int homeDebounceCount = 0;   // poor man's debouncing count
    const int HOME_DEBOUNCE_DELAY = 10000;
#endif
    if(buflen < (BUFSIZE-1))
        get_command();
    if( (millis() - previous_millis_cmd) >  max_inactive_time )
        if(max_inactive_time)
            kill();
    if(stepper_inactive_time)  {
        if( (millis() - previous_millis_cmd) >  stepper_inactive_time ) {
            if(blocks_queued() == false && ignore_stepper_queue == false) {
                disable_x();
                disable_y();
                disable_z();
                disable_e0();
                disable_e1();
                disable_e2();
            }
        }
    }
#ifdef CHDK //Check if pin should be set to LOW after M240 set it to HIGH
    if (chdkActive && (millis() - chdkHigh > CHDK_DELAY)) {
        chdkActive = false;
        WRITE(CHDK, LOW);
    }
#endif
#if defined(KILL_PIN) && KILL_PIN > -1
    // Check if the kill button was pressed and wait just in case it was an accidental
    // key kill key press
    // -------------------------------------------------------------------------------
    if( 0 == READ(KILL_PIN) ) {
        killCount++;
    } else if (killCount > 0) {
        killCount--;
    }
    // Exceeded threshold and we can confirm that it was not accidental
    // KILL the machine
    // ----------------------------------------------------------------
    if ( killCount >= KILL_DELAY) {
        kill();
    }
#endif
#if defined(HOME_PIN) && HOME_PIN > -1
    // Check to see if we have to home, use poor man's debouncer
    // ---------------------------------------------------------
    if ( 0 == READ(HOME_PIN) ) {
        if (homeDebounceCount == 0) {
            enquecommand_P((PSTR("G28")));
            homeDebounceCount++;
            LCD_ALERTMESSAGEPGM(MSG_AUTO_HOME);
        } else if (homeDebounceCount < HOME_DEBOUNCE_DELAY) {
            homeDebounceCount++;
        } else {
            homeDebounceCount = 0;
        }
    }
#endif
#if defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1
    controllerFan(); //Check if fan should be turned on to cool stepper drivers down
#endif
#ifdef EXTRUDER_RUNOUT_PREVENT
    if( (millis() - previous_millis_cmd) >  EXTRUDER_RUNOUT_SECONDS*1000 )
        if(degHotend(active_extruder)>EXTRUDER_RUNOUT_MINTEMP) {
            bool oldstatus=READ(E0_ENABLE_PIN);
            enable_e0();
            float oldepos=current_position[E_AXIS];
            float oldedes=destination[E_AXIS];
            plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS],
                             destination[E_AXIS]+EXTRUDER_RUNOUT_EXTRUDE*EXTRUDER_RUNOUT_ESTEPS/axis_steps_per_unit[E_AXIS],
                             EXTRUDER_RUNOUT_SPEED/60.*EXTRUDER_RUNOUT_ESTEPS/axis_steps_per_unit[E_AXIS], active_extruder);
            current_position[E_AXIS]=oldepos;
            destination[E_AXIS]=oldedes;
            plan_set_e_position(oldepos);
            previous_millis_cmd=millis();
            st_synchronize();
            WRITE(E0_ENABLE_PIN,oldstatus);
        }
#endif
#if defined(DUAL_X_CARRIAGE)
    // handle delayed move timeout
    if (delayed_move_time != 0 && (millis() - delayed_move_time) > 1000 && Stopped == false) {
        // travel moves have been received so enact them
        delayed_move_time = 0xFFFFFFFFUL; // force moves to be done
        memcpy(destination,current_position,sizeof(destination));
        prepare_move();
    }
#endif
#ifdef TEMP_STAT_LEDS
    handle_status_leds();
#endif
    check_axes_activity();
}

void kill() {
    cli(); // Stop interrupts
    disable_heater();
    disable_x();
    disable_y();
    disable_z();
    disable_e0();
    disable_e1();
    disable_e2();
#if defined(PS_ON_PIN) && PS_ON_PIN > -1
    pinMode(PS_ON_PIN,INPUT);
#endif
    SERIAL_ERROR_START;
    SERIAL_ERRORLNPGM(MSG_ERR_KILLED);
    LCD_ALERTMESSAGEPGM(MSG_KILLED);
    // FMC small patch to update the LCD before ending
    sei();   // enable interrupts
    for ( int i=5; i--; lcd_update()) {
        delay(200);
    }
    cli();   // disable interrupts
    suicide();
    while(1) {
        /* Intentionally left empty */
    } // Wait for reset
}

void Stop() {
    disable_heater();
    if(Stopped == false) {
        Stopped = true;
        Stopped_gcode_LastN = gcode_LastN; // Save last g_code for restart
        SERIAL_ERROR_START;
        SERIAL_ERRORLNPGM(MSG_ERR_STOPPED);
        LCD_MESSAGEPGM(MSG_STOPPED);
    }
}

bool IsStopped() {
    return Stopped;
};

#ifdef FAST_PWM_FAN
void setPwmFrequency(uint8_t pin, int val) {
    val &= 0x07;
    switch(digitalPinToTimer(pin)) {
#if defined(TCCR0A)
    case TIMER0A:
    case TIMER0B:
//         TCCR0B &= ~(_BV(CS00) | _BV(CS01) | _BV(CS02));
//         TCCR0B |= val;
        break;
#endif
#if defined(TCCR1A)
    case TIMER1A:
    case TIMER1B:
//         TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));
//         TCCR1B |= val;
        break;
#endif
#if defined(TCCR2)
    case TIMER2:
    case TIMER2:
        TCCR2 &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));
        TCCR2 |= val;
        break;
#endif
#if defined(TCCR2A)
    case TIMER2A:
    case TIMER2B:
        TCCR2B &= ~(_BV(CS20) | _BV(CS21) | _BV(CS22));
        TCCR2B |= val;
        break;
#endif
#if defined(TCCR3A)
    case TIMER3A:
    case TIMER3B:
    case TIMER3C:
        TCCR3B &= ~(_BV(CS30) | _BV(CS31) | _BV(CS32));
        TCCR3B |= val;
        break;
#endif
#if defined(TCCR4A)
    case TIMER4A:
    case TIMER4B:
    case TIMER4C:
        TCCR4B &= ~(_BV(CS40) | _BV(CS41) | _BV(CS42));
        TCCR4B |= val;
        break;
#endif
#if defined(TCCR5A)
    case TIMER5A:
    case TIMER5B:
    case TIMER5C:
        TCCR5B &= ~(_BV(CS50) | _BV(CS51) | _BV(CS52));
        TCCR5B |= val;
        break;
#endif
    }
}
#endif //FAST_PWM_FAN

bool setTargetedHotend(int code) {
    tmp_extruder = active_extruder;
    if(code_seen('T')) {
        tmp_extruder = code_value();
        if(tmp_extruder >= EXTRUDERS) {
            SERIAL_ECHO_START;
            switch(code) {
            case 104:
                SERIAL_ECHO(MSG_M104_INVALID_EXTRUDER);
                break;
            case 105:
                SERIAL_ECHO(MSG_M105_INVALID_EXTRUDER);
                break;
            case 109:
                SERIAL_ECHO(MSG_M109_INVALID_EXTRUDER);
                break;
            case 218:
                SERIAL_ECHO(MSG_M218_INVALID_EXTRUDER);
                break;
            case 221:
                SERIAL_ECHO(MSG_M221_INVALID_EXTRUDER);
                break;
            }
            SERIAL_ECHOLN(tmp_extruder);
            return true;
        }
    }
    return false;
}


float calculate_volumetric_multiplier(float diameter) {
    float area = .0;
    float radius = .0;
    radius = diameter * .5;
    if (! volumetric_enabled || radius == 0) {
        area = 1;
    } else {
        area = M_PI * pow(radius, 2);
    }
    return 1.0 / area;
}

void calculate_volumetric_multipliers() {
    volumetric_multiplier[0] = calculate_volumetric_multiplier(filament_size[0]);
#if EXTRUDERS > 1
    volumetric_multiplier[1] = calculate_volumetric_multiplier(filament_size[1]);
#if EXTRUDERS > 2
    volumetric_multiplier[2] = calculate_volumetric_multiplier(filament_size[2]);
#endif
#endif
}
#endif
#if defined (marlin4Due)
/**
 * Home an individual axis
 */
#define HOMEAXIS(LETTER) homeaxis(LETTER##_AXIS)
static void homeaxis(AxisEnum axis) {
#define HOMEAXIS_DO(LETTER) \
    ((LETTER##_MIN_PIN > -1 && LETTER##_HOME_DIR==-1) || (LETTER##_MAX_PIN > -1 && LETTER##_HOME_DIR==1))
    if (axis == X_AXIS ? HOMEAXIS_DO(X) : axis == Y_AXIS ? HOMEAXIS_DO(Y) : axis == Z_AXIS ? HOMEAXIS_DO(Z) : 0) {
        int axis_home_dir =
#if ENABLED(DUAL_X_CARRIAGE)
            (axis == X_AXIS) ? x_home_dir(active_extruder) :
#endif
            home_dir(axis);
        // Set the axis position as setup for the move
        current_position[axis] = 0;
        sync_plan_position();
#if ENABLED(Z_PROBE_SLED)
        // Get Probe
        if (axis == Z_AXIS) {
            if (axis_home_dir < 0) dock_sled(false);
        }
#endif
#if SERVO_LEVELING && DISABLED(Z_PROBE_SLED)
        // Deploy a probe if there is one, and homing towards the bed
        if (axis == Z_AXIS) {
            if (axis_home_dir < 0) deploy_z_probe();
        }
#endif
#if HAS_SERVO_ENDSTOPS
        // Engage Servo endstop if enabled
        if (axis != Z_AXIS && servo_endstop_id[axis] >= 0)
            servo[servo_endstop_id[axis]].move(servo_endstop_angle[axis][0]);
#endif
        // Set a flag for Z motor locking
#if ENABLED(Z_DUAL_ENDSTOPS)
        if (axis == Z_AXIS) In_Homing_Process(true);
#endif
        // Move towards the endstop until an endstop is triggered
        destination[axis] = 1.5 * max_length(axis) * axis_home_dir;
        feedrate = homing_feedrate[axis];
        line_to_destination();
        st_synchronize();
        // Set the axis position as setup for the move
        current_position[axis] = 0;
        sync_plan_position();
        enable_endstops(false); // Disable endstops while moving away
        // Move away from the endstop by the axis HOME_BUMP_MM
        destination[axis] = -home_bump_mm(axis) * axis_home_dir;
        line_to_destination();
        st_synchronize();
        enable_endstops(true); // Enable endstops for next homing move
        // Slow down the feedrate for the next move
        set_homing_bump_feedrate(axis);
        // Move slowly towards the endstop until triggered
        destination[axis] = 2 * home_bump_mm(axis) * axis_home_dir;
        line_to_destination();
        st_synchronize();
#if ENABLED(Z_DUAL_ENDSTOPS)
        if (axis == Z_AXIS) {
            float adj = fabs(z_endstop_adj);
            bool lockZ1;
            if (axis_home_dir > 0) {
                adj = -adj;
                lockZ1 = (z_endstop_adj > 0);
            } else
                lockZ1 = (z_endstop_adj < 0);
            if (lockZ1) Lock_z_motor(true);
            else Lock_z2_motor(true);
            sync_plan_position();
            // Move to the adjusted endstop height
            feedrate = homing_feedrate[axis];
            destination[Z_AXIS] = adj;
            line_to_destination();
            st_synchronize();
            if (lockZ1) Lock_z_motor(false);
            else Lock_z2_motor(false);
            In_Homing_Process(false);
        } // Z_AXIS
#endif
#if ENABLED(DELTA)
        // retrace by the amount specified in endstop_adj
        if (endstop_adj[axis] * axis_home_dir < 0) {
            enable_endstops(false); // Disable endstops while moving away
            sync_plan_position();
            destination[axis] = endstop_adj[axis];
            line_to_destination();
            st_synchronize();
            enable_endstops(true); // Enable endstops for next homing move
        }
#endif
        // Set the axis position to its home position (plus home offsets)
        set_axis_is_at_home(axis);
        sync_plan_position();
        destination[axis] = current_position[axis];
        feedrate = 0.0;
        endstops_hit_on_purpose(); // clear endstop hit flags
        axis_known_position[axis] = true;
#if ENABLED(Z_PROBE_SLED)
        // bring probe back
        if (axis == Z_AXIS) {
            if (axis_home_dir < 0) dock_sled(true);
        }
#endif
#if SERVO_LEVELING && DISABLED(Z_PROBE_SLED)
        // Deploy a probe if there is one, and homing towards the bed
        if (axis == Z_AXIS) {
            if (axis_home_dir < 0) stow_z_probe();
        } else
#endif
        {
#if HAS_SERVO_ENDSTOPS
            // Retract Servo endstop if enabled
            if (servo_endstop_id[axis] >= 0)
                servo[servo_endstop_id[axis]].move(servo_endstop_angle[axis][1]);
#endif
        }
    }
}
#endif
#if defined (marlin4Due) && ENABLED(FWRETRACT)
void retract(bool retracting, bool swapping=false) {
    if (retracting == retracted[active_extruder]) return;
    float oldFeedrate = feedrate;
    set_destination_to_current();
    if (retracting) {
        feedrate = retract_feedrate * 60;
        current_position[E_AXIS] += (swapping ? retract_length_swap : retract_length) / volumetric_multiplier[active_extruder];
        plan_set_e_position(current_position[E_AXIS]);
        prepare_move();
        if (retract_zlift > 0.01) {
            current_position[Z_AXIS] -= retract_zlift;
#if ENABLED(DELTA)
            sync_plan_position_delta();
#else
            sync_plan_position();
#endif
            prepare_move();
        }
    } else {
        if (retract_zlift > 0.01) {
            current_position[Z_AXIS] += retract_zlift;
#if ENABLED(DELTA)
            sync_plan_position_delta();
#else
            sync_plan_position();
#endif
            //prepare_move();
        }
        feedrate = retract_recover_feedrate * 60;
        float move_e = swapping ? retract_length_swap + retract_recover_length_swap : retract_length + retract_recover_length;
        current_position[E_AXIS] -= move_e / volumetric_multiplier[active_extruder];
        plan_set_e_position(current_position[E_AXIS]);
        prepare_move();
    }
    feedrate = oldFeedrate;
    retracted[active_extruder] = retracting;
}
// retract()
#endif
#if defined (marlin4Due)
// FWRETRACT
/**
 *
 * G-Code Handler functions
 *
 */
/**
 * Set XYZE destination and feedrate from the current GCode command
 *
 *  - Set destination from included axis codes
 *  - Set to current for missing axis codes
 *  - Set the feedrate, if included
 */
void gcode_get_destination() {
    for (int i = 0; i < NUM_AXIS; i++) {
        if (code_seen(axis_codes[i]))
            destination[i] = code_value() + (axis_relative_modes[i] || relative_mode ? current_position[i] : 0);
        else
            destination[i] = current_position[i];
    }
    if (code_seen('F')) {
        float next_feedrate = code_value();
        if (next_feedrate > 0.0) feedrate = next_feedrate;
    }
}
void unknown_command_error() {
    SERIAL_ECHO_START;
    SERIAL_ECHOPGM(MSG_UNKNOWN_COMMAND);
    SERIAL_ECHO(current_command);
    SERIAL_ECHOPGM("\"\n");
}
/**
 * G0, G1: Coordinated movement of X Y Z E axes
 */
inline void gcode_G0_G1() {
    if (IsRunning()) {
        gcode_get_destination(); // For X Y Z E F
#if ENABLED(FWRETRACT)
        if (autoretract_enabled && !(code_seen('X') || code_seen('Y') || code_seen('Z')) && code_seen('E')) {
            float echange = destination[E_AXIS] - current_position[E_AXIS];
            // Is this move an attempt to retract or recover?
            if ((echange < -MIN_RETRACT && !retracted[active_extruder]) || (echange > MIN_RETRACT && retracted[active_extruder])) {
                current_position[E_AXIS] = destination[E_AXIS]; // hide the slicer-generated retract/recover from calculations
                plan_set_e_position(current_position[E_AXIS]);  // AND from the planner
                retract(!retracted[active_extruder]);
                return;
            }
        }
#endif //FWRETRACT
        prepare_move();
    }
}
/**
 * G2: Clockwise Arc
 * G3: Counterclockwise Arc
 */
inline void gcode_G2_G3(bool clockwise) {
    if (IsRunning()) {
#if ENABLED(SF_ARC_FIX)
        bool relative_mode_backup = relative_mode;
        relative_mode = true;
#endif
        gcode_get_destination();
#if ENABLED(SF_ARC_FIX)
        relative_mode = relative_mode_backup;
#endif
        // Center of arc as offset from current_position
        float arc_offset[2] = {
            code_seen('I') ? code_value() : 0,
            code_seen('J') ? code_value() : 0
        };
        // Send an arc to the planner
        plan_arc(destination, arc_offset, clockwise);
        refresh_cmd_timeout();
    }
}
/**
 * G4: Dwell S<seconds> or P<milliseconds>
 */
inline void gcode_G4() {
    millis_t codenum = 0;
    if (code_seen('P')) codenum = code_value_long(); // milliseconds to wait
    if (code_seen('S')) codenum = code_value() * 1000; // seconds to wait
    st_synchronize();
    refresh_cmd_timeout();
    codenum += previous_cmd_ms;  // keep track of when we started waiting
    if (!lcd_hasstatus()) LCD_MESSAGEPGM(MSG_DWELL);
    while (millis() < codenum) idle();
}
#endif
#if defined (marlin4Due) && ENABLED(FWRETRACT)
/**
   * G10 - Retract filament according to settings of M207
   * G11 - Recover filament according to settings of M208
   */
inline void gcode_G10_G11(bool doRetract=false) {
#if EXTRUDERS > 1
    if (doRetract) {
        retracted_swap[active_extruder] = (code_seen('S') && code_value_short() == 1); // checks for swap retract argument
    }
#endif
    retract(doRetract
#if EXTRUDERS > 1
            , retracted_swap[active_extruder]
#endif
           );
}
#endif
#if defined (marlin4Due)
//FWRETRACT
/**
 * G28: Home all axes according to settings
 *
 * Parameters
 *
 *  None  Home to all axes with no parameters.
 *        With QUICK_HOME enabled XY will home together, then Z.
 *
 * Cartesian parameters
 *
 *  X   Home to the X endstop
 *  Y   Home to the Y endstop
 *  Z   Home to the Z endstop
 *
 */
inline void gcode_G28() {
    // Wait for planner moves to finish!
    st_synchronize();
    // For auto bed leveling, clear the level matrix
#if ENABLED(ENABLE_AUTO_BED_LEVELING)
    plan_bed_level_matrix.set_to_identity();
#if ENABLED(DELTA)
    reset_bed_level();
#endif
#endif
    // For manual bed leveling deactivate the matrix temporarily
#if ENABLED(MESH_BED_LEVELING)
    uint8_t mbl_was_active = mbl.active;
    mbl.active = 0;
#endif
    setup_for_endstop_move();
    set_destination_to_current();
    feedrate = 0.0;
#if ENABLED(DELTA)
    // A delta can only safely home all axis at the same time
    // all axis have to home at the same time
    // Pretend the current position is 0,0,0
    for (int i = X_AXIS; i <= Z_AXIS; i++) current_position[i] = 0;
    sync_plan_position();
    // Move all carriages up together until the first endstop is hit.
    for (int i = X_AXIS; i <= Z_AXIS; i++) destination[i] = 3 * Z_MAX_LENGTH;
    feedrate = 1.732 * homing_feedrate[X_AXIS];
    line_to_destination();
    st_synchronize();
    endstops_hit_on_purpose(); // clear endstop hit flags
    // Destination reached
    for (int i = X_AXIS; i <= Z_AXIS; i++) current_position[i] = destination[i];
    // take care of back off and rehome now we are all at the top
    HOMEAXIS(X);
    HOMEAXIS(Y);
    HOMEAXIS(Z);
    sync_plan_position_delta();
#else // NOT DELTA
    bool  homeX = code_seen(axis_codes[X_AXIS]),
          homeY = code_seen(axis_codes[Y_AXIS]),
          homeZ = code_seen(axis_codes[Z_AXIS]);
    home_all_axis = (!homeX && !homeY && !homeZ) || (homeX && homeY && homeZ);
    if (home_all_axis || homeZ) {
#if Z_HOME_DIR > 0  // If homing away from BED do Z first
        HOMEAXIS(Z);
#elif DISABLED(Z_SAFE_HOMING) && defined(Z_RAISE_BEFORE_HOMING) && Z_RAISE_BEFORE_HOMING > 0
        // Raise Z before homing any other axes
        // (Does this need to be "negative home direction?" Why not just use Z_RAISE_BEFORE_HOMING?)
        destination[Z_AXIS] = -Z_RAISE_BEFORE_HOMING * home_dir(Z_AXIS);
        feedrate = max_feedrate[Z_AXIS] * 60;
        line_to_destination();
        st_synchronize();
#endif
    } // home_all_axis || homeZ
#if ENABLED(QUICK_HOME)
    if (home_all_axis || (homeX && homeY)) {  // First diagonal move
        current_position[X_AXIS] = current_position[Y_AXIS] = 0;
#if ENABLED(DUAL_X_CARRIAGE)
        int x_axis_home_dir = x_home_dir(active_extruder);
        extruder_duplication_enabled = false;
#else
        int x_axis_home_dir = home_dir(X_AXIS);
#endif
        sync_plan_position();
        float mlx = max_length(X_AXIS), mly = max_length(Y_AXIS),
              mlratio = mlx>mly ? mly/mlx : mlx/mly;
        destination[X_AXIS] = 1.5 * mlx * x_axis_home_dir;
        destination[Y_AXIS] = 1.5 * mly * home_dir(Y_AXIS);
        feedrate = min(homing_feedrate[X_AXIS], homing_feedrate[Y_AXIS]) * sqrt(mlratio * mlratio + 1);
        line_to_destination();
        st_synchronize();
        set_axis_is_at_home(X_AXIS);
        set_axis_is_at_home(Y_AXIS);
        sync_plan_position();
        destination[X_AXIS] = current_position[X_AXIS];
        destination[Y_AXIS] = current_position[Y_AXIS];
        line_to_destination();
        feedrate = 0.0;
        st_synchronize();
        endstops_hit_on_purpose(); // clear endstop hit flags
        current_position[X_AXIS] = destination[X_AXIS];
        current_position[Y_AXIS] = destination[Y_AXIS];
#if DISABLED(SCARA)
        current_position[Z_AXIS] = destination[Z_AXIS];
#endif
    }
#endif // QUICK_HOME
#if ENABLED(HOME_Y_BEFORE_X)
    // Home Y
    if (home_all_axis || homeY) HOMEAXIS(Y);
#endif
    // Home X
    if (home_all_axis || homeX) {
#if ENABLED(DUAL_X_CARRIAGE)
        int tmp_extruder = active_extruder;
        extruder_duplication_enabled = false;
        active_extruder = !active_extruder;
        HOMEAXIS(X);
        inactive_extruder_x_pos = current_position[X_AXIS];
        active_extruder = tmp_extruder;
        HOMEAXIS(X);
        // reset state used by the different modes
        memcpy(raised_parked_position, current_position, sizeof(raised_parked_position));
        delayed_move_time = 0;
        active_extruder_parked = true;
#else
        HOMEAXIS(X);
#endif
    }
#if DISABLED(HOME_Y_BEFORE_X)
    // Home Y
    if (home_all_axis || homeY) HOMEAXIS(Y);
#endif
    // Home Z last if homing towards the bed
#if Z_HOME_DIR < 0
    if (home_all_axis || homeZ) {
#if ENABLED(Z_SAFE_HOMING)
        if (home_all_axis) {
            current_position[Z_AXIS] = 0;
            sync_plan_position();
            //
            // Set the probe (or just the nozzle) destination to the safe homing point
            //
            // NOTE: If current_position[X_AXIS] or current_position[Y_AXIS] were set above
            // then this may not work as expected.
            destination[X_AXIS] = round(Z_SAFE_HOMING_X_POINT - X_PROBE_OFFSET_FROM_EXTRUDER);
            destination[Y_AXIS] = round(Z_SAFE_HOMING_Y_POINT - Y_PROBE_OFFSET_FROM_EXTRUDER);
            destination[Z_AXIS] = -Z_RAISE_BEFORE_HOMING * home_dir(Z_AXIS);    // Set destination away from bed
            feedrate = XY_TRAVEL_SPEED;
            // This could potentially move X, Y, Z all together
            line_to_destination();
            st_synchronize();
            // Set current X, Y is the Z_SAFE_HOMING_POINT minus PROBE_OFFSET_FROM_EXTRUDER
            current_position[X_AXIS] = destination[X_AXIS];
            current_position[Y_AXIS] = destination[Y_AXIS];
            // Home the Z axis
            HOMEAXIS(Z);
        } else if (homeZ) { // Don't need to Home Z twice
            // Let's see if X and Y are homed
            if (axis_known_position[X_AXIS] && axis_known_position[Y_AXIS]) {
                // Make sure the probe is within the physical limits
                // NOTE: This doesn't necessarily ensure the probe is also within the bed!
                float cpx = current_position[X_AXIS], cpy = current_position[Y_AXIS];
                if (   cpx >= X_MIN_POS - X_PROBE_OFFSET_FROM_EXTRUDER
                        && cpx <= X_MAX_POS - X_PROBE_OFFSET_FROM_EXTRUDER
                        && cpy >= Y_MIN_POS - Y_PROBE_OFFSET_FROM_EXTRUDER
                        && cpy <= Y_MAX_POS - Y_PROBE_OFFSET_FROM_EXTRUDER) {
                    // Set the plan current position to X, Y, 0
                    current_position[Z_AXIS] = 0;
                    plan_set_position(cpx, cpy, 0, current_position[E_AXIS]); // = sync_plan_position
                    // Set Z destination away from bed and raise the axis
                    // NOTE: This should always just be Z_RAISE_BEFORE_HOMING unless...???
                    destination[Z_AXIS] = -Z_RAISE_BEFORE_HOMING * home_dir(Z_AXIS);
                    feedrate = max_feedrate[Z_AXIS] * 60;  // feedrate (mm/m) = max_feedrate (mm/s)
                    line_to_destination();
                    st_synchronize();
                    // Home the Z axis
                    HOMEAXIS(Z);
                } else {
                    LCD_MESSAGEPGM(MSG_ZPROBE_OUT);
                    SERIAL_ECHO_START;
                    SERIAL_ECHOLNPGM(MSG_ZPROBE_OUT);
                }
            } else {
                LCD_MESSAGEPGM(MSG_POSITION_UNKNOWN);
                SERIAL_ECHO_START;
                SERIAL_ECHOLNPGM(MSG_POSITION_UNKNOWN);
            }
        } // !home_all_axes && homeZ
#else // !Z_SAFE_HOMING
        HOMEAXIS(Z);
#endif // !Z_SAFE_HOMING
    } // home_all_axis || homeZ
#endif // Z_HOME_DIR < 0
    sync_plan_position();
#endif // else DELTA
#if ENABLED(SCARA)
    sync_plan_position_delta();
#endif
#if ENABLED(ENDSTOPS_ONLY_FOR_HOMING)
    enable_endstops(false);
#endif
    // For manual leveling move back to 0,0
#if ENABLED(MESH_BED_LEVELING)
    if (mbl_was_active) {
        current_position[X_AXIS] = mbl.get_x(0);
        current_position[Y_AXIS] = mbl.get_y(0);
        set_destination_to_current();
        feedrate = homing_feedrate[X_AXIS];
        line_to_destination();
        st_synchronize();
        current_position[Z_AXIS] = MESH_HOME_SEARCH_Z;
        sync_plan_position();
        mbl.active = 1;
    }
#endif
    feedrate = saved_feedrate;
    feedrate_multiplier = saved_feedrate_multiplier;
    refresh_cmd_timeout();
    endstops_hit_on_purpose(); // clear endstop hit flags
}
#endif
#if defined (marlin4Due) && ENABLED(MESH_BED_LEVELING)
enum MeshLevelingState { MeshReport, MeshStart, MeshNext, MeshSet };
/**
   * G29: Mesh-based Z-Probe, probes a grid and produces a
   *      mesh to compensate for variable bed height
   *
   * Parameters With MESH_BED_LEVELING:
   *
   *  S0              Produce a mesh report
   *  S1              Start probing mesh points
   *  S2              Probe the next mesh point
   *  S3 Xn Yn Zn.nn  Manually modify a single point
   *
   * The S0 report the points as below
   *
   *  +----> X-axis
   *  |
   *  |
   *  v Y-axis
   *
   */
inline void gcode_G29() {
    static int probe_point = -1;
    MeshLevelingState state = code_seen('S') ? (MeshLevelingState)code_value_short() : MeshReport;
    if (state < 0 || state > 3) {
        SERIAL_PROTOCOLLNPGM("S out of range (0-3).");
        return;
    }
    int ix, iy;
    float z;
    switch(state) {
    case MeshReport:
        if (mbl.active) {
            SERIAL_PROTOCOLPGM("Num X,Y: ");
            SERIAL_PROTOCOL(MESH_NUM_X_POINTS);
            SERIAL_PROTOCOLCHAR(',');
            SERIAL_PROTOCOL(MESH_NUM_Y_POINTS);
            SERIAL_PROTOCOLPGM("\nZ search height: ");
            SERIAL_PROTOCOL(MESH_HOME_SEARCH_Z);
            SERIAL_PROTOCOLLNPGM("\nMeasured points:");
            for (int y = 0; y < MESH_NUM_Y_POINTS; y++) {
                for (int x = 0; x < MESH_NUM_X_POINTS; x++) {
                    SERIAL_PROTOCOLPGM("  ");
                    SERIAL_PROTOCOL_F(mbl.z_values[y][x], 5);
                }
                SERIAL_EOL;
            }
        } else
            SERIAL_PROTOCOLLNPGM("Mesh bed leveling not active.");
        break;
    case MeshStart:
        mbl.reset();
        probe_point = 0;
        enqueuecommands_P(PSTR("G28\nG29 S2"));
        break;
    case MeshNext:
        if (probe_point < 0) {
            SERIAL_PROTOCOLLNPGM("Start mesh probing with \"G29 S1\" first.");
            return;
        }
        if (probe_point == 0) {
            // Set Z to a positive value before recording the first Z.
            current_position[Z_AXIS] = MESH_HOME_SEARCH_Z;
            sync_plan_position();
        } else {
            // For others, save the Z of the previous point, then raise Z again.
            ix = (probe_point - 1) % MESH_NUM_X_POINTS;
            iy = (probe_point - 1) / MESH_NUM_X_POINTS;
            if (iy & 1) ix = (MESH_NUM_X_POINTS - 1) - ix; // zig-zag
            mbl.set_z(ix, iy, current_position[Z_AXIS]);
            current_position[Z_AXIS] = MESH_HOME_SEARCH_Z;
            plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS], homing_feedrate[X_AXIS]/60, active_extruder);
            st_synchronize();
        }
        // Is there another point to sample? Move there.
        if (probe_point < MESH_NUM_X_POINTS * MESH_NUM_Y_POINTS) {
            ix = probe_point % MESH_NUM_X_POINTS;
            iy = probe_point / MESH_NUM_X_POINTS;
            if (iy & 1) ix = (MESH_NUM_X_POINTS - 1) - ix; // zig-zag
            current_position[X_AXIS] = mbl.get_x(ix);
            current_position[Y_AXIS] = mbl.get_y(iy);
            plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS], homing_feedrate[X_AXIS]/60, active_extruder);
            st_synchronize();
            probe_point++;
        } else {
            // After recording the last point, activate the mbl and home
            SERIAL_PROTOCOLLNPGM("Mesh probing done.");
            probe_point = -1;
            mbl.active = 1;
            enqueuecommands_P(PSTR("G28"));
        }
        break;
    case MeshSet:
        if (code_seen('X')) {
            ix = code_value_long()-1;
            if (ix < 0 || ix >= MESH_NUM_X_POINTS) {
                SERIAL_PROTOCOLPGM("X out of range (1-" STRINGIFY(MESH_NUM_X_POINTS) ").\n");
                return;
            }
        } else {
            SERIAL_PROTOCOLPGM("X not entered.\n");
            return;
        }
        if (code_seen('Y')) {
            iy = code_value_long()-1;
            if (iy < 0 || iy >= MESH_NUM_Y_POINTS) {
                SERIAL_PROTOCOLPGM("Y out of range (1-" STRINGIFY(MESH_NUM_Y_POINTS) ").\n");
                return;
            }
        } else {
            SERIAL_PROTOCOLPGM("Y not entered.\n");
            return;
        }
        if (code_seen('Z')) {
            z = code_value();
        } else {
            SERIAL_PROTOCOLPGM("Z not entered.\n");
            return;
        }
        mbl.z_values[iy][ix] = z;
    } // switch(state)
}
#endif
#if defined (marlin4Due) && ENABLED(ENABLE_AUTO_BED_LEVELING)
void out_of_range_error(const char *p_edge) {
    SERIAL_PROTOCOLPGM("?Probe ");
    serialprintPGM(p_edge);
    SERIAL_PROTOCOLLNPGM(" position out of range.");
}
/**
   * G29: Detailed Z-Probe, probes the bed at 3 or more points.
   *      Will fail if the printer has not been homed with G28.
   *
   * Enhanced G29 Auto Bed Leveling Probe Routine
   *
   * Parameters With AUTO_BED_LEVELING_GRID:
   *
   *  P  Set the size of the grid that will be probed (P x P points).
   *     Not supported by non-linear delta printer bed leveling.
   *     Example: "G29 P4"
   *
   *  S  Set the XY travel speed between probe points (in mm/min)
   *
   *  D  Dry-Run mode. Just evaluate the bed Topology - Don't apply
   *     or clean the rotation Matrix. Useful to check the topology
   *     after a first run of G29.
   *
   *  V  Set the verbose level (0-4). Example: "G29 V3"
   *
   *  T  Generate a Bed Topology Report. Example: "G29 P5 T" for a detailed report.
   *     This is useful for manual bed leveling and finding flaws in the bed (to
   *     assist with part placement).
   *     Not supported by non-linear delta printer bed leveling.
   *
   *  F  Set the Front limit of the probing grid
   *  B  Set the Back limit of the probing grid
   *  L  Set the Left limit of the probing grid
   *  R  Set the Right limit of the probing grid
   *
   * Global Parameters:
   *
   * E/e By default G29 will engage the probe, test the bed, then disengage.
   *     Include "E" to engage/disengage the probe for each sample.
   *     There's no extra effect if you have a fixed probe.
   *     Usage: "G29 E" or "G29 e"
   *
   */
inline void gcode_G29() {
    // Don't allow auto-leveling without homing first
    if (!axis_known_position[X_AXIS] || !axis_known_position[Y_AXIS]) {
        LCD_MESSAGEPGM(MSG_POSITION_UNKNOWN);
        SERIAL_ECHO_START;
        SERIAL_ECHOLNPGM(MSG_POSITION_UNKNOWN);
        return;
    }
    int verbose_level = code_seen('V') ? code_value_short() : 1;
    if (verbose_level < 0 || verbose_level > 4) {
        SERIAL_ECHOLNPGM("?(V)erbose Level is implausible (0-4).");
        return;
    }
    bool dryrun = code_seen('D'),
         deploy_probe_for_each_reading = code_seen('E');
#if ENABLED(AUTO_BED_LEVELING_GRID)
#if DISABLED(DELTA)
    bool do_topography_map = verbose_level > 2 || code_seen('T');
#endif
    if (verbose_level > 0) {
        SERIAL_PROTOCOLPGM("G29 Auto Bed Leveling\n");
        if (dryrun) SERIAL_ECHOLNPGM("Running in DRY-RUN mode");
    }
    int auto_bed_leveling_grid_points = AUTO_BED_LEVELING_GRID_POINTS;
#if DISABLED(DELTA)
    if (code_seen('P')) auto_bed_leveling_grid_points = code_value_short();
    if (auto_bed_leveling_grid_points < 2) {
        SERIAL_PROTOCOLPGM("?Number of probed (P)oints is implausible (2 minimum).\n");
        return;
    }
#endif
    xy_travel_speed = code_seen('S') ? code_value_short() : XY_TRAVEL_SPEED;
    int left_probe_bed_position = code_seen('L') ? code_value_short() : LEFT_PROBE_BED_POSITION,
        right_probe_bed_position = code_seen('R') ? code_value_short() : RIGHT_PROBE_BED_POSITION,
        front_probe_bed_position = code_seen('F') ? code_value_short() : FRONT_PROBE_BED_POSITION,
        back_probe_bed_position = code_seen('B') ? code_value_short() : BACK_PROBE_BED_POSITION;
    bool left_out_l = left_probe_bed_position < MIN_PROBE_X,
         left_out = left_out_l || left_probe_bed_position > right_probe_bed_position - MIN_PROBE_EDGE,
         right_out_r = right_probe_bed_position > MAX_PROBE_X,
         right_out = right_out_r || right_probe_bed_position < left_probe_bed_position + MIN_PROBE_EDGE;
    bool front_out_f = front_probe_bed_position < MIN_PROBE_Y,
         front_out = front_out_f || front_probe_bed_position > back_probe_bed_position - MIN_PROBE_EDGE,
         back_out_b = back_probe_bed_position > MAX_PROBE_Y,
         back_out = back_out_b || back_probe_bed_position < front_probe_bed_position + MIN_PROBE_EDGE;
    if (left_out || right_out || front_out || back_out) {
        if (left_out) {
            out_of_range_error(PSTR("(L)eft"));
            left_probe_bed_position = left_out_l ? MIN_PROBE_X : right_probe_bed_position - MIN_PROBE_EDGE;
        }
        if (right_out) {
            out_of_range_error(PSTR("(R)ight"));
            right_probe_bed_position = right_out_r ? MAX_PROBE_X : left_probe_bed_position + MIN_PROBE_EDGE;
        }
        if (front_out) {
            out_of_range_error(PSTR("(F)ront"));
            front_probe_bed_position = front_out_f ? MIN_PROBE_Y : back_probe_bed_position - MIN_PROBE_EDGE;
        }
        if (back_out) {
            out_of_range_error(PSTR("(B)ack"));
            back_probe_bed_position = back_out_b ? MAX_PROBE_Y : front_probe_bed_position + MIN_PROBE_EDGE;
        }
        return;
    }
#endif // AUTO_BED_LEVELING_GRID
#if ENABLED(Z_PROBE_SLED)
    dock_sled(false); // engage (un-dock) the probe
#elif ENABLED(Z_PROBE_ALLEN_KEY) //|| SERVO_LEVELING
    deploy_z_probe();
#endif
    st_synchronize();
    if (!dryrun) {
        // make sure the bed_level_rotation_matrix is identity or the planner will get it wrong
        plan_bed_level_matrix.set_to_identity();
#if ENABLED(DELTA)
        reset_bed_level();
#else //!DELTA
        //vector_3 corrected_position = plan_get_position_mm();
        //corrected_position.debug("position before G29");
        vector_3 uncorrected_position = plan_get_position();
        //uncorrected_position.debug("position during G29");
        current_position[X_AXIS] = uncorrected_position.x;
        current_position[Y_AXIS] = uncorrected_position.y;
        current_position[Z_AXIS] = uncorrected_position.z;
        sync_plan_position();
#endif // !DELTA
    }
    setup_for_endstop_move();
    feedrate = homing_feedrate[Z_AXIS];
#if ENABLED(AUTO_BED_LEVELING_GRID)
    // probe at the points of a lattice grid
    const int xGridSpacing = (right_probe_bed_position - left_probe_bed_position) / (auto_bed_leveling_grid_points - 1),
              yGridSpacing = (back_probe_bed_position - front_probe_bed_position) / (auto_bed_leveling_grid_points - 1);
#if ENABLED(DELTA)
    delta_grid_spacing[0] = xGridSpacing;
    delta_grid_spacing[1] = yGridSpacing;
    float z_offset = zprobe_zoffset;
    if (code_seen(axis_codes[Z_AXIS])) z_offset += code_value();
#else // !DELTA
    // solve the plane equation ax + by + d = z
    // A is the matrix with rows [x y 1] for all the probed points
    // B is the vector of the Z positions
    // the normal vector to the plane is formed by the coefficients of the plane equation in the standard form, which is Vx*x+Vy*y+Vz*z+d = 0
    // so Vx = -a Vy = -b Vz = 1 (we want the vector facing towards positive Z
    int abl2 = auto_bed_leveling_grid_points * auto_bed_leveling_grid_points;
    double eqnAMatrix[abl2 * 3], // "A" matrix of the linear system of equations
           eqnBVector[abl2],     // "B" vector of Z points
           mean = 0.0;
#endif // !DELTA
    int probePointCounter = 0;
    bool zig = true;
    for (int yCount = 0; yCount < auto_bed_leveling_grid_points; yCount++) {
        double yProbe = front_probe_bed_position + yGridSpacing * yCount;
        int xStart, xStop, xInc;
        if (zig) {
            xStart = 0;
            xStop = auto_bed_leveling_grid_points;
            xInc = 1;
        } else {
            xStart = auto_bed_leveling_grid_points - 1;
            xStop = -1;
            xInc = -1;
        }
#if DISABLED(DELTA)
        // If do_topography_map is set then don't zig-zag. Just scan in one direction.
        // This gets the probe points in more readable order.
        if (!do_topography_map) zig = !zig;
#else
        zig = !zig;
#endif
        for (int xCount = xStart; xCount != xStop; xCount += xInc) {
            double xProbe = left_probe_bed_position + xGridSpacing * xCount;
            // raise extruder
            float measured_z,
                  z_before = probePointCounter ? Z_RAISE_BETWEEN_PROBINGS + current_position[Z_AXIS] : Z_RAISE_BEFORE_PROBING;
#if ENABLED(DELTA)
            // Avoid probing the corners (outside the round or hexagon print surface) on a delta printer.
            float distance_from_center = sqrt(xProbe*xProbe + yProbe*yProbe);
            if (distance_from_center > DELTA_PROBABLE_RADIUS) continue;
#endif //DELTA
            ProbeAction act;
            if (deploy_probe_for_each_reading) // G29 E - Stow between probes
                act = ProbeDeployAndStow;
            else if (yCount == 0 && xCount == xStart)
                act = ProbeDeploy;
            else if (yCount == auto_bed_leveling_grid_points - 1 && xCount == xStop - xInc)
                act = ProbeStow;
            else
                act = ProbeStay;
            measured_z = probe_pt(xProbe, yProbe, z_before, act, verbose_level);
#if DISABLED(DELTA)
            mean += measured_z;
            eqnBVector[probePointCounter] = measured_z;
            eqnAMatrix[probePointCounter + 0 * abl2] = xProbe;
            eqnAMatrix[probePointCounter + 1 * abl2] = yProbe;
            eqnAMatrix[probePointCounter + 2 * abl2] = 1;
#else
            bed_level[xCount][yCount] = measured_z + z_offset;
#endif
            probePointCounter++;
            idle();
        } //xProbe
    } //yProbe
    clean_up_after_endstop_move();
#if ENABLED(DELTA)
    if (!dryrun) extrapolate_unprobed_bed_level();
    print_bed_level();
#else // !DELTA
    // solve lsq problem
    double plane_equation_coefficients[3];
    qr_solve(plane_equation_coefficients, abl2, 3, eqnAMatrix, eqnBVector);
    mean /= abl2;
    if (verbose_level) {
        SERIAL_PROTOCOLPGM("Eqn coefficients: a: ");
        SERIAL_PROTOCOL_F(plane_equation_coefficients[0], 8);
        SERIAL_PROTOCOLPGM(" b: ");
        SERIAL_PROTOCOL_F(plane_equation_coefficients[1], 8);
        SERIAL_PROTOCOLPGM(" d: ");
        SERIAL_PROTOCOL_F(plane_equation_coefficients[2], 8);
        SERIAL_EOL;
        if (verbose_level > 2) {
            SERIAL_PROTOCOLPGM("Mean of sampled points: ");
            SERIAL_PROTOCOL_F(mean, 8);
            SERIAL_EOL;
        }
    }
    if (!dryrun) set_bed_level_equation_lsq(plane_equation_coefficients);
    free(plane_equation_coefficients);
    // Show the Topography map if enabled
    if (do_topography_map) {
        SERIAL_PROTOCOLPGM(" \nBed Height Topography: \n");
        SERIAL_PROTOCOLPGM("+-----------+\n");
        SERIAL_PROTOCOLPGM("|...Back....|\n");
        SERIAL_PROTOCOLPGM("|Left..Right|\n");
        SERIAL_PROTOCOLPGM("|...Front...|\n");
        SERIAL_PROTOCOLPGM("+-----------+\n");
        float min_diff = 999;
        for (int yy = auto_bed_leveling_grid_points - 1; yy >= 0; yy--) {
            for (int xx = 0; xx < auto_bed_leveling_grid_points; xx++) {
                int ind = yy * auto_bed_leveling_grid_points + xx;
                float diff = eqnBVector[ind] - mean;
                float x_tmp = eqnAMatrix[ind + 0 * abl2],
                      y_tmp = eqnAMatrix[ind + 1 * abl2],
                      z_tmp = 0;
                apply_rotation_xyz(plan_bed_level_matrix,x_tmp,y_tmp,z_tmp);
                if (eqnBVector[ind] - z_tmp < min_diff)
                    min_diff = eqnBVector[ind] - z_tmp;
                if (diff >= 0.0)
                    SERIAL_PROTOCOLPGM(" +");   // Include + for column alignment
                else
                    SERIAL_PROTOCOLCHAR(' ');
                SERIAL_PROTOCOL_F(diff, 5);
            } // xx
            SERIAL_EOL;
        } // yy
        SERIAL_EOL;
        if (verbose_level > 3) {
            SERIAL_PROTOCOLPGM(" \nCorrected Bed Height vs. Bed Topology: \n");
            for (int yy = auto_bed_leveling_grid_points - 1; yy >= 0; yy--) {
                for (int xx = 0; xx < auto_bed_leveling_grid_points; xx++) {
                    int ind = yy * auto_bed_leveling_grid_points + xx;
                    float x_tmp = eqnAMatrix[ind + 0 * abl2],
                          y_tmp = eqnAMatrix[ind + 1 * abl2],
                          z_tmp = 0;
                    apply_rotation_xyz(plan_bed_level_matrix,x_tmp,y_tmp,z_tmp);
                    float diff = eqnBVector[ind] - z_tmp - min_diff;
                    if (diff >= 0.0)
                        SERIAL_PROTOCOLPGM(" +");
                    // Include + for column alignment
                    else
                        SERIAL_PROTOCOLCHAR(' ');
                    SERIAL_PROTOCOL_F(diff, 5);
                } // xx
                SERIAL_EOL;
            } // yy
            SERIAL_EOL;
        }
    } //do_topography_map
#endif //!DELTA
#else // !AUTO_BED_LEVELING_GRID
    // Actions for each probe
    ProbeAction p1, p2, p3;
    if (deploy_probe_for_each_reading)
        p1 = p2 = p3 = ProbeDeployAndStow;
    else
        p1 = ProbeDeploy, p2 = ProbeStay, p3 = ProbeStow;
    // Probe at 3 arbitrary points
    float z_at_pt_1 = probe_pt(ABL_PROBE_PT_1_X, ABL_PROBE_PT_1_Y, Z_RAISE_BEFORE_PROBING, p1, verbose_level),
          z_at_pt_2 = probe_pt(ABL_PROBE_PT_2_X, ABL_PROBE_PT_2_Y, current_position[Z_AXIS] + Z_RAISE_BETWEEN_PROBINGS, p2, verbose_level),
          z_at_pt_3 = probe_pt(ABL_PROBE_PT_3_X, ABL_PROBE_PT_3_Y, current_position[Z_AXIS] + Z_RAISE_BETWEEN_PROBINGS, p3, verbose_level);
    clean_up_after_endstop_move();
    if (!dryrun) set_bed_level_equation_3pts(z_at_pt_1, z_at_pt_2, z_at_pt_3);
#endif // !AUTO_BED_LEVELING_GRID
#if DISABLED(DELTA)
    if (verbose_level > 0)
        plan_bed_level_matrix.debug(" \n\nBed Level Correction Matrix:");
    if (!dryrun) {
        // Correct the Z height difference from z-probe position and hotend tip position.
        // The Z height on homing is measured by Z-Probe, but the probe is quite far from the hotend.
        // When the bed is uneven, this height must be corrected.
        float x_tmp = current_position[X_AXIS] + X_PROBE_OFFSET_FROM_EXTRUDER,
              y_tmp = current_position[Y_AXIS] + Y_PROBE_OFFSET_FROM_EXTRUDER,
              z_tmp = current_position[Z_AXIS],
              real_z = st_get_position_mm(Z_AXIS);  //get the real Z (since plan_get_position is now correcting the plane)
        apply_rotation_xyz(plan_bed_level_matrix, x_tmp, y_tmp, z_tmp); // Apply the correction sending the probe offset
        // Get the current Z position and send it to the planner.
        //
        // >> (z_tmp - real_z) : The rotated current Z minus the uncorrected Z (most recent plan_set_position/sync_plan_position)
        //
        // >> zprobe_zoffset : Z distance from nozzle to probe (set by default, M851, EEPROM, or Menu)
        //
        // >> Z_RAISE_AFTER_PROBING : The distance the probe will have lifted after the last probe
        //
        // >> Should home_offset[Z_AXIS] be included?
        //
        //      Discussion: home_offset[Z_AXIS] was applied in G28 to set the starting Z.
        //      If Z is not tweaked in G29 -and- the Z probe in G29 is not actually "homing" Z...
        //      then perhaps it should not be included here. The purpose of home_offset[] is to
        //      adjust for inaccurate endstops, not for reasonably accurate probes. If it were
        //      added here, it could be seen as a compensating factor for the Z probe.
        //
        current_position[Z_AXIS] = -zprobe_zoffset + (z_tmp - real_z)
#if HAS_SERVO_ENDSTOPS || ENABLED(Z_PROBE_ALLEN_KEY) || ENABLED(Z_PROBE_SLED)
                                   + Z_RAISE_AFTER_PROBING
#endif
                                   ;
        // current_position[Z_AXIS] += home_offset[Z_AXIS]; // The probe determines Z=0, not "Z home"
        sync_plan_position();
    }
#endif // !DELTA
#if ENABLED(Z_PROBE_SLED)
    dock_sled(true); // dock the probe
#elif ENABLED(Z_PROBE_ALLEN_KEY) //|| SERVO_LEVELING
    stow_z_probe();
#endif
#ifdef Z_PROBE_END_SCRIPT
    enqueuecommands_P(PSTR(Z_PROBE_END_SCRIPT));
    st_synchronize();
#endif
}
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && DISABLED(Z_PROBE_SLED) )
inline void gcode_G30() {
    deploy_z_probe(); // Engage Z Servo endstop if available
    st_synchronize();
    // TODO: make sure the bed_level_rotation_matrix is identity or the planner will get set incorectly
    setup_for_endstop_move();
    feedrate = homing_feedrate[Z_AXIS];
    run_z_probe();
    SERIAL_PROTOCOLPGM("Bed X: ");
    SERIAL_PROTOCOL(current_position[X_AXIS] + 0.0001);
    SERIAL_PROTOCOLPGM(" Y: ");
    SERIAL_PROTOCOL(current_position[Y_AXIS] + 0.0001);
    SERIAL_PROTOCOLPGM(" Z: ");
    SERIAL_PROTOCOL(current_position[Z_AXIS] + 0.0001);
    SERIAL_EOL;
    clean_up_after_endstop_move();
    stow_z_probe(); // Retract Z Servo endstop if available
}
#endif
#if defined (marlin4Due) && ENABLED(ENABLE_AUTO_BED_LEVELING)
    //!Z_PROBE_SLED
#endif
#if defined (marlin4Due)
//ENABLE_AUTO_BED_LEVELING
/**
 * G92: Set current position to given X Y Z E
 */
inline void gcode_G92() {
    if (!code_seen(axis_codes[E_AXIS]))
        st_synchronize();
    bool didXYZ = false;
    for (int i = 0; i < NUM_AXIS; i++) {
        if (code_seen(axis_codes[i])) {
            float v = current_position[i] = code_value();
            if (i == E_AXIS)
                plan_set_e_position(v);
            else
                didXYZ = true;
        }
    }
    if (didXYZ) {
#if ENABLED(DELTA) || ENABLED(SCARA)
        sync_plan_position_delta();
#else
        sync_plan_position();
#endif
    }
}
#endif
#if defined (marlin4Due) && ENABLED(ULTIPANEL)
/**
   * M0: // M0 - Unconditional stop - Wait for user button press on LCD
   * M1: // M1 - Conditional stop - Wait for user button press on LCD
   */
inline void gcode_M0_M1() {
    char *args = current_command_args;
    millis_t codenum = 0;
    bool hasP = false, hasS = false;
    if (code_seen('P')) {
        codenum = code_value_short(); // milliseconds to wait
        hasP = codenum > 0;
    }
    if (code_seen('S')) {
        codenum = code_value() * 1000; // seconds to wait
        hasS = codenum > 0;
    }
    if (!hasP && !hasS && *args != '\0')
        lcd_setstatus(args, true);
    else {
        LCD_MESSAGEPGM(MSG_USERWAIT);
#if ENABLED(LCD_PROGRESS_BAR) && PROGRESS_MSG_EXPIRE > 0
        dontExpireStatus();
#endif
    }
    lcd_ignore_click();
    st_synchronize();
    refresh_cmd_timeout();
    if (codenum > 0) {
        codenum += previous_cmd_ms;  // wait until this time for a click
        while (millis() < codenum && !lcd_clicked()) idle();
        lcd_ignore_click(false);
    } else {
        if (!lcd_detected()) return;
        while (!lcd_clicked()) idle();
    }
    if (IS_SD_PRINTING)
        LCD_MESSAGEPGM(MSG_RESUMING);
    else
        LCD_MESSAGEPGM(WELCOME_MSG);
}
#endif
#if defined (marlin4Due)
// ULTIPANEL
/**
 * M17: Enable power on all stepper motors
 */
inline void gcode_M17() {
    LCD_MESSAGEPGM(MSG_NO_MOVE);
    enable_all_steppers();
}
#endif
#if defined (marlin4Due) && ENABLED(SDSUPPORT)
/**
   * M20: List SD card to serial output
   */
inline void gcode_M20() {
    SERIAL_PROTOCOLLNPGM(MSG_BEGIN_FILE_LIST);
    card.ls();
    SERIAL_PROTOCOLLNPGM(MSG_END_FILE_LIST);
}
/**
   * M21: Init SD Card
   */
inline void gcode_M21() {
    card.initsd();
}
/**
   * M22: Release SD Card
   */
inline void gcode_M22() {
    card.release();
}
/**
   * M23: Select a file
   */
inline void gcode_M23() {
    card.openFile(current_command_args, true);
}
/**
   * M24: Start SD Print
   */
inline void gcode_M24() {
    card.startFileprint();
    print_job_start_ms = millis();
}
/**
   * M25: Pause SD Print
   */
inline void gcode_M25() {
    card.pauseSDPrint();
}
/**
   * M26: Set SD Card file index
   */
inline void gcode_M26() {
    if (card.cardOK && code_seen('S'))
        card.setIndex(code_value_short());
}
/**
   * M27: Get SD Card status
   */
inline void gcode_M27() {
    card.getStatus();
}
/**
   * M28: Start SD Write
   */
inline void gcode_M28() {
    card.openFile(current_command_args, false);
}
/**
   * M29: Stop SD Write
   * Processed in write to file routine above
   */
inline void gcode_M29() {
    // card.saving = false;
}
/**
   * M30 <filename>: Delete SD Card file
   */
inline void gcode_M30() {
    if (card.cardOK) {
        card.closefile();
        card.removeFile(current_command_args);
    }
}
#endif
#if defined (marlin4Due)
/**
 * M31: Get the time since the start of SD Print (or last M109)
 */
inline void gcode_M31() {
    print_job_stop_ms = millis();
    millis_t t = (print_job_stop_ms - print_job_start_ms) / 1000;
    int min = t / 60, sec = t % 60;
    char time[30];
    sprintf_P(time, PSTR("%i min, %i sec"), min, sec);
    SERIAL_ECHO_START;
    SERIAL_ECHOLN(time);
    lcd_setstatus(time);
    autotempShutdown();
}
#endif
#if defined (marlin4Due) && ENABLED(SDSUPPORT)
/**
   * M32: Select file and start SD Print
   */
inline void gcode_M32() {
    if (card.sdprinting)
        st_synchronize();
    char* namestartpos = strchr(current_command_args, '!');  // Find ! to indicate filename string start.
    if (!namestartpos)
        namestartpos = current_command_args; // Default name position, 4 letters after the M
    else
        namestartpos++; //to skip the '!'
    bool call_procedure = code_seen('P') && (seen_pointer < namestartpos);
    if (card.cardOK) {
        card.openFile(namestartpos, true, !call_procedure);
        if (code_seen('S') && seen_pointer < namestartpos) // "S" (must occur _before_ the filename!)
            card.setIndex(code_value_short());
        card.startFileprint();
        if (!call_procedure)
            print_job_start_ms = millis(); //procedure calls count as normal print time.
    }
}
#endif
#if defined (marlin4Due) && (ENABLED(SDSUPPORT) && ENABLED(LONG_FILENAME_HOST_SUPPORT) )
/**
     * M33: Get the long full path of a file or folder
     *
     * Parameters:
     *   <dospath> Case-insensitive DOS-style path to a file or folder
     *
     * Example:
     *   M33 miscel~1/armchair/armcha~1.gco
     *
     * Output:
     *   /Miscellaneous/Armchair/Armchair.gcode
     */
inline void gcode_M33() {
    card.printLongPath(current_command_args);
}
#endif
#if defined (marlin4Due) && ENABLED(SDSUPPORT)
/**
   * M928: Start SD Write
   */
inline void gcode_M928() {
    card.openLogFile(current_command_args);
}
#endif
#if defined (marlin4Due)
// SDSUPPORT
/**
 * M42: Change pin status via GCode
 */
inline void gcode_M42() {
    if (code_seen('S')) {
        int pin_status = code_value_short(),
            pin_number = LED_PIN;
        if (code_seen('P') && pin_status >= 0 && pin_status <= 255)
            pin_number = code_value_short();
        for (uint8_t i = 0; i < COUNT(sensitive_pins); i++) {
            if (sensitive_pins[i] == pin_number) {
                pin_number = -1;
                break;
            }
        }
#if HAS_FAN
        if (pin_number == FAN_PIN) fanSpeed = pin_status;
#endif
        if (pin_number > -1) {
            pinMode(pin_number, OUTPUT);
            digitalWrite(pin_number, pin_status);
            analogWrite(pin_number, pin_status);
        }
    } // code_seen('S')
}
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(Z_PROBE_REPEATABILITY_TEST))
    // This is redundant since the SanityCheck.h already checks for a valid Z_PROBE_PIN, but here for clarity.
#endif
#if defined (marlin4Due) && ((ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(Z_PROBE_REPEATABILITY_TEST) && )ENABLED(Z_PROBE_ENDSTOP) && !HAS_Z_PROBE )
    #error You must define Z_PROBE_PIN to enable Z-Probe repeatability calculation.
#endif
#if defined (marlin4Due) && ((ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(Z_PROBE_REPEATABILITY_TEST) && )!HAS_Z_MIN )
    #error You must define Z_MIN_PIN to enable Z-Probe repeatability calculation.
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(Z_PROBE_REPEATABILITY_TEST))
/**
   * M48: Z-Probe repeatability measurement function.
   *
   * Usage:
   *   M48 <P#> <X#> <Y#> <V#> <E> <L#>
   *     P = Number of sampled points (4-50, default 10)
   *     X = Sample X position
   *     Y = Sample Y position
   *     V = Verbose level (0-4, default=1)
   *     E = Engage probe for each reading
   *     L = Number of legs of movement before probe
   *
   * This function assumes the bed has been homed.  Specifically, that a G28 command
   * as been issued prior to invoking the M48 Z-Probe repeatability measurement function.
   * Any information generated by a prior G29 Bed leveling command will be lost and need to be
   * regenerated.
   */
inline void gcode_M48() {
    double sum = 0.0, mean = 0.0, sigma = 0.0, sample_set[50];
    uint8_t verbose_level = 1, n_samples = 10, n_legs = 0;
    if (code_seen('V')) {
        verbose_level = code_value_short();
        if (verbose_level < 0 || verbose_level > 4 ) {
            SERIAL_PROTOCOLPGM("?Verbose Level not plausible (0-4).\n");
            return;
        }
    }
    if (verbose_level > 0)
        SERIAL_PROTOCOLPGM("M48 Z-Probe Repeatability test\n");
    if (code_seen('P')) {
        n_samples = code_value_short();
        if (n_samples < 4 || n_samples > 50) {
            SERIAL_PROTOCOLPGM("?Sample size not plausible (4-50).\n");
            return;
        }
    }
    double X_current = st_get_position_mm(X_AXIS),
           Y_current = st_get_position_mm(Y_AXIS),
           Z_current = st_get_position_mm(Z_AXIS),
           E_current = st_get_position_mm(E_AXIS),
           X_probe_location = X_current, Y_probe_location = Y_current,
           Z_start_location = Z_current + Z_RAISE_BEFORE_PROBING;
    bool deploy_probe_for_each_reading = code_seen('E');
    if (code_seen('X')) {
        X_probe_location = code_value() - X_PROBE_OFFSET_FROM_EXTRUDER;
        if (X_probe_location < X_MIN_POS || X_probe_location > X_MAX_POS) {
            out_of_range_error(PSTR("X"));
            return;
        }
    }
    if (code_seen('Y')) {
        Y_probe_location = code_value() -  Y_PROBE_OFFSET_FROM_EXTRUDER;
        if (Y_probe_location < Y_MIN_POS || Y_probe_location > Y_MAX_POS) {
            out_of_range_error(PSTR("Y"));
            return;
        }
    }
    if (code_seen('L')) {
        n_legs = code_value_short();
        if (n_legs == 1) n_legs = 2;
        if (n_legs < 0 || n_legs > 15) {
            SERIAL_PROTOCOLPGM("?Number of legs in movement not plausible (0-15).\n");
            return;
        }
    }
    //
    // Do all the preliminary setup work.   First raise the probe.
    //
    st_synchronize();
    plan_bed_level_matrix.set_to_identity();
    plan_buffer_line(X_current, Y_current, Z_start_location, E_current, homing_feedrate[Z_AXIS] / 60, active_extruder);
    st_synchronize();
    //
    // Now get everything to the specified probe point So we can safely do a probe to
    // get us close to the bed.  If the Z-Axis is far from the bed, we don't want to
    // use that as a starting point for each probe.
    //
    if (verbose_level > 2)
        SERIAL_PROTOCOLPGM("Positioning the probe...\n");
    plan_buffer_line( X_probe_location, Y_probe_location, Z_start_location,
                      E_current,
                      homing_feedrate[X_AXIS]/60,
                      active_extruder);
    st_synchronize();
    current_position[X_AXIS] = X_current = st_get_position_mm(X_AXIS);
    current_position[Y_AXIS] = Y_current = st_get_position_mm(Y_AXIS);
    current_position[Z_AXIS] = Z_current = st_get_position_mm(Z_AXIS);
    current_position[E_AXIS] = E_current = st_get_position_mm(E_AXIS);
    //
    // OK, do the initial probe to get us close to the bed.
    // Then retrace the right amount and use that in subsequent probes
    //
    deploy_z_probe();
    setup_for_endstop_move();
    run_z_probe();
    current_position[Z_AXIS] = Z_current = st_get_position_mm(Z_AXIS);
    Z_start_location = st_get_position_mm(Z_AXIS) + Z_RAISE_BEFORE_PROBING;
    plan_buffer_line( X_probe_location, Y_probe_location, Z_start_location,
                      E_current,
                      homing_feedrate[X_AXIS]/60,
                      active_extruder);
    st_synchronize();
    current_position[Z_AXIS] = Z_current = st_get_position_mm(Z_AXIS);
    if (deploy_probe_for_each_reading) stow_z_probe();
    for (uint8_t n=0; n < n_samples; n++) {
        // Make sure we are at the probe location
        do_blocking_move_to(X_probe_location, Y_probe_location, Z_start_location); // this also updates current_position
        if (n_legs) {
            millis_t ms = millis();
            double radius = ms % (X_MAX_LENGTH / 4),       // limit how far out to go
                   theta = RADIANS(ms % 360L);
            float dir = (ms & 0x0001) ? 1 : -1;            // clockwise or counter clockwise
            //SERIAL_ECHOPAIR("starting radius: ",radius);
            //SERIAL_ECHOPAIR("   theta: ",theta);
            //SERIAL_ECHOPAIR("   direction: ",dir);
            //SERIAL_EOL;
            for (uint8_t l = 0; l < n_legs - 1; l++) {
                ms = millis();
                theta += RADIANS(dir * (ms % 20L));
                radius += (ms % 10L) - 5L;
                if (radius < 0.0) radius = -radius;
                X_current = X_probe_location + cos(theta) * radius;
                X_current = constrain(X_current, X_MIN_POS, X_MAX_POS);
                Y_current = Y_probe_location + sin(theta) * radius;
                Y_current = constrain(Y_current, Y_MIN_POS, Y_MAX_POS);
                if (verbose_level > 3) {
                    SERIAL_ECHOPAIR("x: ", X_current);
                    SERIAL_ECHOPAIR("y: ", Y_current);
                    SERIAL_EOL;
                }
                do_blocking_move_to(X_current, Y_current, Z_current); // this also updates current_position
            } // n_legs loop
            // Go back to the probe location
            do_blocking_move_to(X_probe_location, Y_probe_location, Z_start_location); // this also updates current_position
        } // n_legs
        if (deploy_probe_for_each_reading)  {
            deploy_z_probe();
            delay(1000);
        }
        setup_for_endstop_move();
        run_z_probe();
        sample_set[n] = current_position[Z_AXIS];
        //
        // Get the current mean for the data points we have so far
        //
        sum = 0.0;
        for (uint8_t j = 0; j <= n; j++) sum += sample_set[j];
        mean = sum / (n + 1);
        //
        // Now, use that mean to calculate the standard deviation for the
        // data points we have so far
        //
        sum = 0.0;
        for (uint8_t j = 0; j <= n; j++) {
            float ss = sample_set[j] - mean;
            sum += ss * ss;
        }
        sigma = sqrt(sum / (n + 1));
        if (verbose_level > 1) {
            SERIAL_PROTOCOL(n+1);
            SERIAL_PROTOCOLPGM(" of ");
            SERIAL_PROTOCOL((int)n_samples);
            SERIAL_PROTOCOLPGM("   z: ");
            SERIAL_PROTOCOL_F(current_position[Z_AXIS], 6);
            if (verbose_level > 2) {
                SERIAL_PROTOCOLPGM(" mean: ");
                SERIAL_PROTOCOL_F(mean,6);
                SERIAL_PROTOCOLPGM("   sigma: ");
                SERIAL_PROTOCOL_F(sigma,6);
            }
        }
        if (verbose_level > 0) SERIAL_EOL;
        plan_buffer_line(X_probe_location, Y_probe_location, Z_start_location, current_position[E_AXIS], homing_feedrate[Z_AXIS]/60, active_extruder);
        st_synchronize();
        // Stow between
        if (deploy_probe_for_each_reading) {
            stow_z_probe();
            delay(1000);
        }
    }
    // Stow after
    if (!deploy_probe_for_each_reading) {
        stow_z_probe();
        delay(1000);
    }
    clean_up_after_endstop_move();
    if (verbose_level > 0) {
        SERIAL_PROTOCOLPGM("Mean: ");
        SERIAL_PROTOCOL_F(mean, 6);
        SERIAL_EOL;
    }
    SERIAL_PROTOCOLPGM("Standard Deviation: ");
    SERIAL_PROTOCOL_F(sigma, 6);
    SERIAL_EOL;
    SERIAL_EOL;
}
#endif
#if defined (marlin4Due)
// ENABLE_AUTO_BED_LEVELING && Z_PROBE_REPEATABILITY_TEST
/**
 * M104: Set hot end temperature
 */
inline void gcode_M104() {
    if (setTargetedHotend(104)) return;
    if (marlin_debug_flags & DEBUG_DRYRUN) return;
    if (code_seen('S')) {
        float temp = code_value();
        setTargetHotend(temp, target_extruder);
#if ENABLED(DUAL_X_CARRIAGE)
        if (dual_x_carriage_mode == DXC_DUPLICATION_MODE && target_extruder == 0)
            setTargetHotend1(temp == 0.0 ? 0.0 : temp + duplicate_extruder_temp_offset);
#endif
    }
}
/**
 * M105: Read hot end and bed temperature
 */
inline void gcode_M105() {
    if (setTargetedHotend(105)) return;
#if HAS_TEMP_0 || HAS_TEMP_BED || ENABLED(HEATER_0_USES_MAX6675)
    SERIAL_PROTOCOLPGM(MSG_OK);
#if HAS_TEMP_0 || ENABLED(HEATER_0_USES_MAX6675)
    SERIAL_PROTOCOLPGM(" T:");
    SERIAL_PROTOCOL_F(degHotend(target_extruder), 1);
    SERIAL_PROTOCOLPGM(" /");
    SERIAL_PROTOCOL_F(degTargetHotend(target_extruder), 1);
#endif
#if HAS_TEMP_BED
    SERIAL_PROTOCOLPGM(" B:");
    SERIAL_PROTOCOL_F(degBed(), 1);
    SERIAL_PROTOCOLPGM(" /");
    SERIAL_PROTOCOL_F(degTargetBed(), 1);
#endif
    for (int8_t e = 0; e < EXTRUDERS; ++e) {
        SERIAL_PROTOCOLPGM(" T");
        SERIAL_PROTOCOL(e);
        SERIAL_PROTOCOLCHAR(':');
        SERIAL_PROTOCOL_F(degHotend(e), 1);
        SERIAL_PROTOCOLPGM(" /");
        SERIAL_PROTOCOL_F(degTargetHotend(e), 1);
    }
#else // !HAS_TEMP_0 && !HAS_TEMP_BED
    SERIAL_ERROR_START;
    SERIAL_ERRORLNPGM(MSG_ERR_NO_THERMISTORS);
#endif
    SERIAL_PROTOCOLPGM(" @:");
#ifdef EXTRUDER_WATTS
    SERIAL_PROTOCOL((EXTRUDER_WATTS * getHeaterPower(target_extruder))/127);
    SERIAL_PROTOCOLCHAR('W');
#else
    SERIAL_PROTOCOL(getHeaterPower(target_extruder));
#endif
    SERIAL_PROTOCOLPGM(" B@:");
#ifdef BED_WATTS
    SERIAL_PROTOCOL((BED_WATTS * getHeaterPower(-1))/127);
    SERIAL_PROTOCOLCHAR('W');
#else
    SERIAL_PROTOCOL(getHeaterPower(-1));
#endif
#if ENABLED(SHOW_TEMP_ADC_VALUES)
#if HAS_TEMP_BED
    SERIAL_PROTOCOLPGM("    ADC B:");
    SERIAL_PROTOCOL_F(degBed(),1);
    SERIAL_PROTOCOLPGM("C->");
    SERIAL_PROTOCOL_F(rawBedTemp()/OVERSAMPLENR,0);
#endif
    for (int8_t cur_extruder = 0; cur_extruder < EXTRUDERS; ++cur_extruder) {
        SERIAL_PROTOCOLPGM("  T");
        SERIAL_PROTOCOL(cur_extruder);
        SERIAL_PROTOCOLCHAR(':');
        SERIAL_PROTOCOL_F(degHotend(cur_extruder),1);
        SERIAL_PROTOCOLPGM("C->");
        SERIAL_PROTOCOL_F(rawHotendTemp(cur_extruder)/OVERSAMPLENR,0);
    }
#endif
    SERIAL_EOL;
}
#endif
#if defined (marlin4Due) && HAS_FAN
/**
   * M106: Set Fan Speed
   */
inline void gcode_M106() {
    fanSpeed = code_seen('S') ? constrain(code_value_short(), 0, 255) : 255;
}
/**
   * M107: Fan Off
   */
inline void gcode_M107() {
    fanSpeed = 0;
}
#endif
#if defined (marlin4Due)
// HAS_FAN
/**
 * M109: Wait for extruder(s) to reach temperature
 */
inline void gcode_M109() {
    if (setTargetedHotend(109)) return;
    if (marlin_debug_flags & DEBUG_DRYRUN) return;
    LCD_MESSAGEPGM(MSG_HEATING);
    no_wait_for_cooling = code_seen('S');
    if (no_wait_for_cooling || code_seen('R')) {
        float temp = code_value();
        setTargetHotend(temp, target_extruder);
#if ENABLED(DUAL_X_CARRIAGE)
        if (dual_x_carriage_mode == DXC_DUPLICATION_MODE && target_extruder == 0)
            setTargetHotend1(temp == 0.0 ? 0.0 : temp + duplicate_extruder_temp_offset);
#endif
    }
#if ENABLED(AUTOTEMP)
    autotemp_enabled = code_seen('F');
    if (autotemp_enabled) autotemp_factor = code_value();
    if (code_seen('S')) autotemp_min = code_value();
    if (code_seen('B')) autotemp_max = code_value();
#endif
    millis_t temp_ms = millis();
    /* See if we are heating up or cooling down */
    target_direction = isHeatingHotend(target_extruder); // true if heating, false if cooling
    cancel_heatup = false;
#ifdef TEMP_RESIDENCY_TIME
    long residency_start_ms = -1;
    /* continue to loop until we have reached the target temp
      _and_ until TEMP_RESIDENCY_TIME hasn't passed since we reached it */
    while((!cancel_heatup)&&((residency_start_ms == -1) ||
                             (residency_start_ms >= 0 && (((unsigned int) (millis() - residency_start_ms)) < (TEMP_RESIDENCY_TIME * 1000UL)))) )
#else
    while ( target_direction ? (isHeatingHotend(target_extruder)) : (isCoolingHotend(target_extruder)&&(no_wait_for_cooling==false)) )
#endif //TEMP_RESIDENCY_TIME
    {
        // while loop
        if (millis() > temp_ms + 1000UL) { //Print temp & remaining time every 1s while waiting
            SERIAL_PROTOCOLPGM("T:");
            SERIAL_PROTOCOL_F(degHotend(target_extruder),1);
            SERIAL_PROTOCOLPGM(" E:");
            SERIAL_PROTOCOL((int)target_extruder);
#ifdef TEMP_RESIDENCY_TIME
            SERIAL_PROTOCOLPGM(" W:");
            if (residency_start_ms > -1) {
                temp_ms = ((TEMP_RESIDENCY_TIME * 1000UL) - (millis() - residency_start_ms)) / 1000UL;
                SERIAL_PROTOCOLLN(temp_ms);
            } else {
                SERIAL_PROTOCOLLNPGM("?");
            }
#else
            SERIAL_EOL;
#endif
            temp_ms = millis();
        }
        idle();
#ifdef TEMP_RESIDENCY_TIME
        // start/restart the TEMP_RESIDENCY_TIME timer whenever we reach target temp for the first time
        // or when current temp falls outside the hysteresis after target temp was reached
        if ((residency_start_ms == -1 &&  target_direction && (degHotend(target_extruder) >= (degTargetHotend(target_extruder)-TEMP_WINDOW))) ||
                (residency_start_ms == -1 && !target_direction && (degHotend(target_extruder) <= (degTargetHotend(target_extruder)+TEMP_WINDOW))) ||
                (residency_start_ms > -1 && labs(degHotend(target_extruder) - degTargetHotend(target_extruder)) > TEMP_HYSTERESIS) ) {
            residency_start_ms = millis();
        }
#endif //TEMP_RESIDENCY_TIME
    }
    LCD_MESSAGEPGM(MSG_HEATING_COMPLETE);
    refresh_cmd_timeout();
    print_job_start_ms = previous_cmd_ms;
}
#endif
#if defined (marlin4Due) && HAS_TEMP_BED
/**
   * M190: Sxxx Wait for bed current temp to reach target temp. Waits only when heating
   *       Rxxx Wait for bed current temp to reach target temp. Waits when heating and cooling
   */
inline void gcode_M190() {
    if (marlin_debug_flags & DEBUG_DRYRUN) return;
    LCD_MESSAGEPGM(MSG_BED_HEATING);
    no_wait_for_cooling = code_seen('S');
    if (no_wait_for_cooling || code_seen('R'))
        setTargetBed(code_value());
    millis_t temp_ms = millis();
    cancel_heatup = false;
    target_direction = isHeatingBed(); // true if heating, false if cooling
    while ((target_direction && !cancel_heatup) ? isHeatingBed() : isCoolingBed() && !no_wait_for_cooling) {
        millis_t ms = millis();
        if (ms > temp_ms + 1000UL) { //Print Temp Reading every 1 second while heating up.
            temp_ms = ms;
            float tt = degHotend(active_extruder);
            SERIAL_PROTOCOLPGM("T:");
            SERIAL_PROTOCOL(tt);
            SERIAL_PROTOCOLPGM(" E:");
            SERIAL_PROTOCOL((int)active_extruder);
            SERIAL_PROTOCOLPGM(" B:");
            SERIAL_PROTOCOL_F(degBed(), 1);
            SERIAL_EOL;
        }
        idle();
    }
    LCD_MESSAGEPGM(MSG_BED_DONE);
    refresh_cmd_timeout();
}
#endif
#if defined (marlin4Due)
// HAS_TEMP_BED
/**
 * M111: Set the debug level
 */
inline void gcode_M111() {
    marlin_debug_flags = code_seen('S') ? code_value_short() : DEBUG_INFO|DEBUG_COMMUNICATION;
    if (marlin_debug_flags & DEBUG_ECHO) {
        SERIAL_ECHO_START;
        SERIAL_ECHOLNPGM(MSG_DEBUG_ECHO);
    }
    // FOR MOMENT NOT ACTIVE
    //if (marlin_debug_flags & DEBUG_INFO) SERIAL_ECHOLNPGM(MSG_DEBUG_INFO);
    //if (marlin_debug_flags & DEBUG_ERRORS) SERIAL_ECHOLNPGM(MSG_DEBUG_ERRORS);
    if (marlin_debug_flags & DEBUG_DRYRUN) {
        SERIAL_ECHO_START;
        SERIAL_ECHOLNPGM(MSG_DEBUG_DRYRUN);
        disable_all_heaters();
    }
}
/**
 * M112: Emergency Stop
 */
inline void gcode_M112() {
    kill(PSTR(MSG_KILLED));
}
#endif
#if defined (marlin4Due) && (ENABLED(BARICUDA) && HAS_HEATER_1 )
/**
     * M126: Heater 1 valve open
     */
inline void gcode_M126() {
    ValvePressure = code_seen('S') ? constrain(code_value(), 0, 255) : 255;
}
/**
     * M127: Heater 1 valve close
     */
inline void gcode_M127() {
    ValvePressure = 0;
}
#endif
#if defined (marlin4Due) && (ENABLED(BARICUDA) && HAS_HEATER_2 )
/**
     * M128: Heater 2 valve open
     */
inline void gcode_M128() {
    EtoPPressure = code_seen('S') ? constrain(code_value(), 0, 255) : 255;
}
/**
     * M129: Heater 2 valve close
     */
inline void gcode_M129() {
    EtoPPressure = 0;
}
#endif
#if defined (marlin4Due)
//BARICUDA
/**
 * M140: Set bed temperature
 */
inline void gcode_M140() {
    if (marlin_debug_flags & DEBUG_DRYRUN) return;
    if (code_seen('S')) setTargetBed(code_value());
}
#endif
#if defined (marlin4Due) && ENABLED(ULTIPANEL)
/**
   * M145: Set the heatup state for a material in the LCD menu
   *   S<material> (0=PLA, 1=ABS)
   *   H<hotend temp>
   *   B<bed temp>
   *   F<fan speed>
   */
inline void gcode_M145() {
    uint8_t material = code_seen('S') ? code_value_short() : 0;
    if (material < 0 || material > 1) {
        SERIAL_ERROR_START;
        SERIAL_ERRORLNPGM(MSG_ERR_MATERIAL_INDEX);
    } else {
        int v;
        switch (material) {
        case 0:
            if (code_seen('H')) {
                v = code_value_short();
                plaPreheatHotendTemp = constrain(v, EXTRUDE_MINTEMP, HEATER_0_MAXTEMP - 15);
            }
            if (code_seen('F')) {
                v = code_value_short();
                plaPreheatFanSpeed = constrain(v, 0, 255);
            }
#if TEMP_SENSOR_BED != 0
            if (code_seen('B')) {
                v = code_value_short();
                plaPreheatHPBTemp = constrain(v, BED_MINTEMP, BED_MAXTEMP - 15);
            }
#endif
            break;
        case 1:
            if (code_seen('H')) {
                v = code_value_short();
                absPreheatHotendTemp = constrain(v, EXTRUDE_MINTEMP, HEATER_0_MAXTEMP - 15);
            }
            if (code_seen('F')) {
                v = code_value_short();
                absPreheatFanSpeed = constrain(v, 0, 255);
            }
#if TEMP_SENSOR_BED != 0
            if (code_seen('B')) {
                v = code_value_short();
                absPreheatHPBTemp = constrain(v, BED_MINTEMP, BED_MAXTEMP - 15);
            }
#endif
            break;
        }
    }
}
#endif
#if defined (marlin4Due) && HAS_POWER_SWITCH
/**
   * M80: Turn on Power Supply
   */
inline void gcode_M80() {
    OUT_WRITE(PS_ON_PIN, PS_ON_AWAKE); //GND
    // If you have a switch on suicide pin, this is useful
    // if you want to start another print with suicide feature after
    // a print without suicide...
#if HAS_SUICIDE
    OUT_WRITE(SUICIDE_PIN, HIGH);
#endif
#if ENABLED(ULTIPANEL)
    powersupply = true;
    LCD_MESSAGEPGM(WELCOME_MSG);
    lcd_update();
#endif
}
#endif
#if defined (marlin4Due)
// HAS_POWER_SWITCH
/**
 * M81: Turn off Power, including Power Supply, if there is one.
 *
 *      This code should ALWAYS be available for EMERGENCY SHUTDOWN!
 */
inline void gcode_M81() {
    disable_all_heaters();
    finishAndDisableSteppers();
    fanSpeed = 0;
    delay(1000); // Wait 1 second before switching off
#if HAS_SUICIDE
    st_synchronize();
    suicide();
#elif HAS_POWER_SWITCH
    OUT_WRITE(PS_ON_PIN, PS_ON_ASLEEP);
#endif
#if ENABLED(ULTIPANEL)
#if HAS_POWER_SWITCH
    powersupply = false;
#endif
    LCD_MESSAGEPGM(MACHINE_NAME " " MSG_OFF ".");
    lcd_update();
#endif
}
/**
 * M82: Set E codes absolute (default)
 */
inline void gcode_M82() {
    axis_relative_modes[E_AXIS] = false;
}
/**
 * M83: Set E codes relative while in Absolute Coordinates (G90) mode
 */
inline void gcode_M83() {
    axis_relative_modes[E_AXIS] = true;
}
/**
 * M18, M84: Disable all stepper motors
 */
inline void gcode_M18_M84() {
    if (code_seen('S')) {
        stepper_inactive_time = code_value() * 1000;
    } else {
        bool all_axis = !((code_seen(axis_codes[X_AXIS])) || (code_seen(axis_codes[Y_AXIS])) || (code_seen(axis_codes[Z_AXIS]))|| (code_seen(axis_codes[E_AXIS])));
        if (all_axis) {
            finishAndDisableSteppers();
        } else {
            st_synchronize();
            if (code_seen('X')) disable_x();
            if (code_seen('Y')) disable_y();
            if (code_seen('Z')) disable_z();
#if ((E0_ENABLE_PIN != X_ENABLE_PIN) && (E1_ENABLE_PIN != Y_ENABLE_PIN)) // Only enable on boards that have seperate ENABLE_PINS
            if (code_seen('E')) {
                disable_e0();
                disable_e1();
                disable_e2();
                disable_e3();
            }
#endif
        }
    }
}
/**
 * M85: Set inactivity shutdown timer with parameter S<seconds>. To disable set zero (default)
 */
inline void gcode_M85() {
    if (code_seen('S')) max_inactive_time = code_value() * 1000;
}
/**
 * M92: Set axis steps-per-unit for one or more axes, X, Y, Z, and E.
 *      (Follows the same syntax as G92)
 */
inline void gcode_M92() {
    for(int8_t i=0; i < NUM_AXIS; i++) {
        if (code_seen(axis_codes[i])) {
            if (i == E_AXIS) {
                float value = code_value();
                if (value < 20.0) {
                    float factor = axis_steps_per_unit[i] / value; // increase e constants if M92 E14 is given for netfab.
                    max_e_jerk *= factor;
                    max_feedrate[i] *= factor;
                    axis_steps_per_sqr_second[i] *= factor;
                }
                axis_steps_per_unit[i] = value;
            } else {
                axis_steps_per_unit[i] = code_value();
            }
        }
    }
}
/**
 * M114: Output current position to serial port
 */
inline void gcode_M114() {
    SERIAL_PROTOCOLPGM("X:");
    SERIAL_PROTOCOL(current_position[X_AXIS]);
    SERIAL_PROTOCOLPGM(" Y:");
    SERIAL_PROTOCOL(current_position[Y_AXIS]);
    SERIAL_PROTOCOLPGM(" Z:");
    SERIAL_PROTOCOL(current_position[Z_AXIS]);
    SERIAL_PROTOCOLPGM(" E:");
    SERIAL_PROTOCOL(current_position[E_AXIS]);
    SERIAL_PROTOCOLPGM(MSG_COUNT_X);
    SERIAL_PROTOCOL(st_get_position_mm(X_AXIS));
    SERIAL_PROTOCOLPGM(" Y:");
    SERIAL_PROTOCOL(st_get_position_mm(Y_AXIS));
    SERIAL_PROTOCOLPGM(" Z:");
    SERIAL_PROTOCOL(st_get_position_mm(Z_AXIS));
    SERIAL_EOL;
#if ENABLED(SCARA)
    SERIAL_PROTOCOLPGM("SCARA Theta:");
    SERIAL_PROTOCOL(delta[X_AXIS]);
    SERIAL_PROTOCOLPGM("   Psi+Theta:");
    SERIAL_PROTOCOL(delta[Y_AXIS]);
    SERIAL_EOL;
    SERIAL_PROTOCOLPGM("SCARA Cal - Theta:");
    SERIAL_PROTOCOL(delta[X_AXIS]+home_offset[X_AXIS]);
    SERIAL_PROTOCOLPGM("   Psi+Theta (90):");
    SERIAL_PROTOCOL(delta[Y_AXIS]-delta[X_AXIS]-90+home_offset[Y_AXIS]);
    SERIAL_EOL;
    SERIAL_PROTOCOLPGM("SCARA step Cal - Theta:");
    SERIAL_PROTOCOL(delta[X_AXIS]/90*axis_steps_per_unit[X_AXIS]);
    SERIAL_PROTOCOLPGM("   Psi+Theta:");
    SERIAL_PROTOCOL((delta[Y_AXIS]-delta[X_AXIS])/90*axis_steps_per_unit[Y_AXIS]);
    SERIAL_EOL;
    SERIAL_EOL;
#endif
}
/**
 * M115: Capabilities string
 */
inline void gcode_M115() {
    SERIAL_PROTOCOLPGM(MSG_M115_REPORT);
}
/**
 * M117: Set LCD Status Message
 */
inline void gcode_M117() {
    lcd_setstatus(current_command_args);
}
/**
 * M119: Output endstop states to serial output
 */
inline void gcode_M119() {
    SERIAL_PROTOCOLLN(MSG_M119_REPORT);
#if HAS_X_MIN
    SERIAL_PROTOCOLPGM(MSG_X_MIN);
    SERIAL_PROTOCOLLN(((READ(X_MIN_PIN)^X_MIN_ENDSTOP_INVERTING)?MSG_ENDSTOP_HIT:MSG_ENDSTOP_OPEN));
#endif
#if HAS_X_MAX
    SERIAL_PROTOCOLPGM(MSG_X_MAX);
    SERIAL_PROTOCOLLN(((READ(X_MAX_PIN)^X_MAX_ENDSTOP_INVERTING)?MSG_ENDSTOP_HIT:MSG_ENDSTOP_OPEN));
#endif
#if HAS_Y_MIN
    SERIAL_PROTOCOLPGM(MSG_Y_MIN);
    SERIAL_PROTOCOLLN(((READ(Y_MIN_PIN)^Y_MIN_ENDSTOP_INVERTING)?MSG_ENDSTOP_HIT:MSG_ENDSTOP_OPEN));
#endif
#if HAS_Y_MAX
    SERIAL_PROTOCOLPGM(MSG_Y_MAX);
    SERIAL_PROTOCOLLN(((READ(Y_MAX_PIN)^Y_MAX_ENDSTOP_INVERTING)?MSG_ENDSTOP_HIT:MSG_ENDSTOP_OPEN));
#endif
#if HAS_Z_MIN
    SERIAL_PROTOCOLPGM(MSG_Z_MIN);
    SERIAL_PROTOCOLLN(((READ(Z_MIN_PIN)^Z_MIN_ENDSTOP_INVERTING)?MSG_ENDSTOP_HIT:MSG_ENDSTOP_OPEN));
#endif
#if HAS_Z_MAX
    SERIAL_PROTOCOLPGM(MSG_Z_MAX);
    SERIAL_PROTOCOLLN(((READ(Z_MAX_PIN)^Z_MAX_ENDSTOP_INVERTING)?MSG_ENDSTOP_HIT:MSG_ENDSTOP_OPEN));
#endif
#if HAS_Z2_MAX
    SERIAL_PROTOCOLPGM(MSG_Z2_MAX);
    SERIAL_PROTOCOLLN(((READ(Z2_MAX_PIN)^Z2_MAX_ENDSTOP_INVERTING)?MSG_ENDSTOP_HIT:MSG_ENDSTOP_OPEN));
#endif
#if HAS_Z_PROBE
    SERIAL_PROTOCOLPGM(MSG_Z_PROBE);
    SERIAL_PROTOCOLLN(((READ(Z_PROBE_PIN)^Z_PROBE_ENDSTOP_INVERTING)?MSG_ENDSTOP_HIT:MSG_ENDSTOP_OPEN));
#endif
}
/**
 * M120: Enable endstops
 */
inline void gcode_M120() {
    enable_endstops(true);
}
/**
 * M121: Disable endstops
 */
inline void gcode_M121() {
    enable_endstops(false);
}
#endif
#if defined (marlin4Due) && ENABLED(BLINKM)
/**
   * M150: Set Status LED Color - Use R-U-B for R-G-B
   */
inline void gcode_M150() {
    SendColors(
        code_seen('R') ? (byte)code_value_short() : 0,
        code_seen('U') ? (byte)code_value_short() : 0,
        code_seen('B') ? (byte)code_value_short() : 0
    );
}
#endif
#if defined (marlin4Due)
// BLINKM
/**
 * M200: Set filament diameter and set E axis units to cubic millimeters
 *
 *    T<extruder> - Optional extruder number. Current extruder if omitted.
 *    D<mm> - Diameter of the filament. Use "D0" to set units back to millimeters.
 */
inline void gcode_M200() {
    if (setTargetedHotend(200)) return;
    if (code_seen('D')) {
        float diameter = code_value();
        // setting any extruder filament size disables volumetric on the assumption that
        // slicers either generate in extruder values as cubic mm or as as filament feeds
        // for all extruders
        volumetric_enabled = (diameter != 0.0);
        if (volumetric_enabled) {
            filament_size[target_extruder] = diameter;
            // make sure all extruders have some sane value for the filament size
            for (int i=0; i<EXTRUDERS; i++)
                if (! filament_size[i]) filament_size[i] = DEFAULT_NOMINAL_FILAMENT_DIA;
        }
    } else {
        //reserved for setting filament diameter via UFID or filament measuring device
        return;
    }
    calculate_volumetric_multipliers();
}
/**
 * M201: Set max acceleration in units/s^2 for print moves (M201 X1000 Y1000)
 */
inline void gcode_M201() {
    for (int8_t i=0; i < NUM_AXIS; i++) {
        if (code_seen(axis_codes[i])) {
            max_acceleration_units_per_sq_second[i] = code_value();
        }
    }
    // steps per sq second need to be updated to agree with the units per sq second (as they are what is used in the planner)
    reset_acceleration_rates();
}
#endif
#if defined (marlin4Due) && 0
    // Not used for Sprinter/grbl gen6
#endif
#if defined (marlin4Due)
/**
 * M203: Set maximum feedrate that your machine can sustain (M203 X200 Y200 Z300 E10000) in mm/sec
 */
inline void gcode_M203() {
    for (int8_t i=0; i < NUM_AXIS; i++) {
        if (code_seen(axis_codes[i])) {
            max_feedrate[i] = code_value();
        }
    }
}
/**
 * M204: Set Accelerations in mm/sec^2 (M204 P1200 R3000 T3000)
 *
 *    P = Printing moves
 *    R = Retract only (no X, Y, Z) moves
 *    T = Travel (non printing) moves
 *
 *  Also sets minimum segment time in ms (B20000) to prevent buffer under-runs and M20 minimum feedrate
 */
inline void gcode_M204() {
    if (code_seen('S')) {  // Kept for legacy compatibility. Should NOT BE USED for new developments.
        travel_acceleration = acceleration = code_value();
        SERIAL_ECHOPAIR("Setting Print and Travel Acceleration: ", acceleration);
        SERIAL_EOL;
    }
    if (code_seen('P')) {
        acceleration = code_value();
        SERIAL_ECHOPAIR("Setting Print Acceleration: ", acceleration );
        SERIAL_EOL;
    }
    if (code_seen('R')) {
        retract_acceleration = code_value();
        SERIAL_ECHOPAIR("Setting Retract Acceleration: ", retract_acceleration );
        SERIAL_EOL;
    }
    if (code_seen('T')) {
        travel_acceleration = code_value();
        SERIAL_ECHOPAIR("Setting Travel Acceleration: ", travel_acceleration );
        SERIAL_EOL;
    }
}
/**
 * M205: Set Advanced Settings
 *
 *    S = Min Feed Rate (mm/s)
 *    T = Min Travel Feed Rate (mm/s)
 *    B = Min Segment Time (Âµs)
 *    X = Max XY Jerk (mm/s/s)
 *    Z = Max Z Jerk (mm/s/s)
 *    E = Max E Jerk (mm/s/s)
 */
inline void gcode_M205() {
    if (code_seen('S')) minimumfeedrate = code_value();
    if (code_seen('T')) mintravelfeedrate = code_value();
    if (code_seen('B')) minsegmenttime = code_value();
    if (code_seen('X')) max_xy_jerk = code_value();
    if (code_seen('Z')) max_z_jerk = code_value();
    if (code_seen('E')) max_e_jerk = code_value();
}
/**
 * M206: Set Additional Homing Offset (X Y Z). SCARA aliases T=X, P=Y
 */
inline void gcode_M206() {
    for (int8_t i=X_AXIS; i <= Z_AXIS; i++) {
        if (code_seen(axis_codes[i])) {
            home_offset[i] = code_value();
        }
    }
#if ENABLED(SCARA)
    if (code_seen('T')) home_offset[X_AXIS] = code_value(); // Theta
    if (code_seen('P')) home_offset[Y_AXIS] = code_value(); // Psi
#endif
}
#endif
#if defined (marlin4Due) && ENABLED(DELTA)
/**
   * M665: Set delta configurations
   *
   *    L = diagonal rod
   *    R = delta radius
   *    S = segments per second
   */
inline void gcode_M665() {
    if (code_seen('L')) delta_diagonal_rod = code_value();
    if (code_seen('R')) delta_radius = code_value();
    if (code_seen('S')) delta_segments_per_second = code_value();
    recalc_delta_settings(delta_radius, delta_diagonal_rod);
}
/**
   * M666: Set delta endstop adjustment
   */
inline void gcode_M666() {
    for (int8_t i = X_AXIS; i <= Z_AXIS; i++) {
        if (code_seen(axis_codes[i])) {
            endstop_adj[i] = code_value();
        }
    }
}
#endif
#if defined (marlin4Due) && ENABLED(Z_DUAL_ENDSTOPS)
// !DELTA && ENABLED(Z_DUAL_ENDSTOPS)
/**
   * M666: For Z Dual Endstop setup, set z axis offset to the z2 axis.
   */
inline void gcode_M666() {
    if (code_seen('Z')) z_endstop_adj = code_value();
    SERIAL_ECHOPAIR("Z Endstop Adjustment set to (mm):", z_endstop_adj);
    SERIAL_EOL;
}
#endif
#if defined (marlin4Due)
    // !DELTA && Z_DUAL_ENDSTOPS
#endif
#if defined (marlin4Due) && ENABLED(FWRETRACT)
/**
   * M207: Set firmware retraction values
   *
   *   S[+mm]    retract_length
   *   W[+mm]    retract_length_swap (multi-extruder)
   *   F[mm/min] retract_feedrate
   *   Z[mm]     retract_zlift
   */
inline void gcode_M207() {
    if (code_seen('S')) retract_length = code_value();
    if (code_seen('F')) retract_feedrate = code_value() / 60;
    if (code_seen('Z')) retract_zlift = code_value();
#if EXTRUDERS > 1
    if (code_seen('W')) retract_length_swap = code_value();
#endif
}
/**
   * M208: Set firmware un-retraction values
   *
   *   S[+mm]    retract_recover_length (in addition to M207 S*)
   *   W[+mm]    retract_recover_length_swap (multi-extruder)
   *   F[mm/min] retract_recover_feedrate
   */
inline void gcode_M208() {
    if (code_seen('S')) retract_recover_length = code_value();
    if (code_seen('F')) retract_recover_feedrate = code_value() / 60;
#if EXTRUDERS > 1
    if (code_seen('W')) retract_recover_length_swap = code_value();
#endif
}
/**
   * M209: Enable automatic retract (M209 S1)
   *       detect if the slicer did not support G10/11: every normal extrude-only move will be classified as retract depending on the direction.
   */
inline void gcode_M209() {
    if (code_seen('S')) {
        int t = code_value_short();
        switch(t) {
        case 0:
            autoretract_enabled = false;
            break;
        case 1:
            autoretract_enabled = true;
            break;
        default:
            unknown_command_error();
            return;
        }
        for (int i=0; i<EXTRUDERS; i++) retracted[i] = false;
    }
}
#endif
#if defined (marlin4Due)
    // FWRETRACT
#endif
#if defined (marlin4Due) && EXTRUDERS > 1
/**
   * M218 - set hotend offset (in mm), T<extruder_number> X<offset_on_X> Y<offset_on_Y>
   */
inline void gcode_M218() {
    if (setTargetedHotend(218)) return;
    if (code_seen('X')) extruder_offset[X_AXIS][target_extruder] = code_value();
    if (code_seen('Y')) extruder_offset[Y_AXIS][target_extruder] = code_value();
#if ENABLED(DUAL_X_CARRIAGE)
    if (code_seen('Z')) extruder_offset[Z_AXIS][target_extruder] = code_value();
#endif
    SERIAL_ECHO_START;
    SERIAL_ECHOPGM(MSG_HOTEND_OFFSET);
    for (int e = 0; e < EXTRUDERS; e++) {
        SERIAL_CHAR(' ');
        SERIAL_ECHO(extruder_offset[X_AXIS][e]);
        SERIAL_CHAR(',');
        SERIAL_ECHO(extruder_offset[Y_AXIS][e]);
#if ENABLED(DUAL_X_CARRIAGE)
        SERIAL_CHAR(',');
        SERIAL_ECHO(extruder_offset[Z_AXIS][e]);
#endif
    }
    SERIAL_EOL;
}
#endif
#if defined (marlin4Due)
// EXTRUDERS > 1
/**
 * M220: Set speed percentage factor, aka "Feed Rate" (M220 S95)
 */
inline void gcode_M220() {
    if (code_seen('S')) feedrate_multiplier = code_value();
}
/**
 * M221: Set extrusion percentage (M221 T0 S95)
 */
inline void gcode_M221() {
    if (code_seen('S')) {
        int sval = code_value();
        if (code_seen('T')) {
            if (setTargetedHotend(221)) return;
            extruder_multiplier[target_extruder] = sval;
        } else {
            extruder_multiplier[active_extruder] = sval;
        }
    }
}
/**
 * M226: Wait until the specified pin reaches the state required (M226 P<pin> S<state>)
 */
inline void gcode_M226() {
    if (code_seen('P')) {
        int pin_number = code_value();
        int pin_state = code_seen('S') ? code_value() : -1; // required pin state - default is inverted
        if (pin_state >= -1 && pin_state <= 1) {
            for (uint8_t i = 0; i < COUNT(sensitive_pins); i++) {
                if (sensitive_pins[i] == pin_number) {
                    pin_number = -1;
                    break;
                }
            }
            if (pin_number > -1) {
                int target = LOW;
                st_synchronize();
                pinMode(pin_number, INPUT);
                switch(pin_state) {
                case 1:
                    target = HIGH;
                    break;
                case 0:
                    target = LOW;
                    break;
                case -1:
                    target = !digitalRead(pin_number);
                    break;
                }
                while (digitalRead(pin_number) != target) idle();
            } // pin_number > -1
        } // pin_state -1 0 1
    } // code_seen('P')
}
#endif
#if defined (marlin4Due) && HAS_SERVOS
/**
   * M280: Get or set servo position. P<index> S<angle>
   */
inline void gcode_M280() {
    int servo_index = code_seen('P') ? code_value_short() : -1;
    int servo_position = 0;
    if (code_seen('S')) {
        servo_position = code_value_short();
        if (servo_index >= 0 && servo_index < NUM_SERVOS)
            servo[servo_index].move(servo_position);
        else {
            SERIAL_ECHO_START;
            SERIAL_ECHO("Servo ");
            SERIAL_ECHO(servo_index);
            SERIAL_ECHOLN(" out of range");
        }
    } else if (servo_index >= 0) {
        SERIAL_PROTOCOL(MSG_OK);
        SERIAL_PROTOCOL(" Servo ");
        SERIAL_PROTOCOL(servo_index);
        SERIAL_PROTOCOL(": ");
        SERIAL_PROTOCOL(servo[servo_index].read());
        SERIAL_EOL;
    }
}
#endif
#if defined (marlin4Due)
    // HAS_SERVOS
#endif
#if defined (marlin4Due) && HAS_BUZZER
/**
   * M300: Play beep sound S<frequency Hz> P<duration ms>
   */
inline void gcode_M300() {
    uint16_t beepS = code_seen('S') ? code_value_short() : 110;
    uint32_t beepP = code_seen('P') ? code_value_long() : 1000;
    if (beepP > 5000) beepP = 5000; // limit to 5 seconds
    buzz(beepP, beepS);
}
#endif
#if defined (marlin4Due)
    // HAS_BUZZER
#endif
#if defined (marlin4Due) && ENABLED(PIDTEMP)
/**
   * M301: Set PID parameters P I D (and optionally C)
   */
inline void gcode_M301() {
    // multi-extruder PID patch: M301 updates or prints a single extruder's PID values
    // default behaviour (omitting E parameter) is to update for extruder 0 only
    int e = code_seen('E') ? code_value() : 0; // extruder being updated
    if (e < EXTRUDERS) { // catch bad input value
        if (code_seen('P')) PID_PARAM(Kp, e) = code_value();
        if (code_seen('I')) PID_PARAM(Ki, e) = scalePID_i(code_value());
        if (code_seen('D')) PID_PARAM(Kd, e) = scalePID_d(code_value());
#if ENABLED(PID_ADD_EXTRUSION_RATE)
        if (code_seen('C')) PID_PARAM(Kc, e) = code_value();
#endif
        updatePID();
        SERIAL_PROTOCOL(MSG_OK);
#if ENABLED(PID_PARAMS_PER_EXTRUDER)
        SERIAL_PROTOCOL(" e:"); // specify extruder in serial output
        SERIAL_PROTOCOL(e);
#endif // PID_PARAMS_PER_EXTRUDER
        SERIAL_PROTOCOL(" p:");
        SERIAL_PROTOCOL(PID_PARAM(Kp, e));
        SERIAL_PROTOCOL(" i:");
        SERIAL_PROTOCOL(unscalePID_i(PID_PARAM(Ki, e)));
        SERIAL_PROTOCOL(" d:");
        SERIAL_PROTOCOL(unscalePID_d(PID_PARAM(Kd, e)));
#if ENABLED(PID_ADD_EXTRUSION_RATE)
        SERIAL_PROTOCOL(" c:");
        //Kc does not have scaling applied above, or in resetting defaults
        SERIAL_PROTOCOL(PID_PARAM(Kc, e));
#endif
        SERIAL_EOL;
    } else {
        SERIAL_ECHO_START;
        SERIAL_ECHOLN(MSG_INVALID_EXTRUDER);
    }
}
#endif
#if defined (marlin4Due)
    // PIDTEMP
#endif
#if defined (marlin4Due) && ENABLED(PIDTEMPBED)
inline void gcode_M304() {
    if (code_seen('P')) bedKp = code_value();
    if (code_seen('I')) bedKi = scalePID_i(code_value());
    if (code_seen('D')) bedKd = scalePID_d(code_value());
    updatePID();
    SERIAL_PROTOCOL(MSG_OK);
    SERIAL_PROTOCOL(" p:");
    SERIAL_PROTOCOL(bedKp);
    SERIAL_PROTOCOL(" i:");
    SERIAL_PROTOCOL(unscalePID_i(bedKi));
    SERIAL_PROTOCOL(" d:");
    SERIAL_PROTOCOL(unscalePID_d(bedKd));
    SERIAL_EOL;
}
#endif
#if defined (marlin4Due)
    // PIDTEMPBED
#endif
#if defined (marlin4Due) && (defined(CHDK) || HAS_PHOTOGRAPH)
/**
   * M240: Trigger a camera by emulating a Canon RC-1
   *       See http://www.doc-diy.net/photo/rc-1_hacked/
   */
inline void gcode_M240() {
#ifdef CHDK
    OUT_WRITE(CHDK, HIGH);
    chdkHigh = millis();
    chdkActive = true;
#elif HAS_PHOTOGRAPH
    const uint8_t NUM_PULSES = 16;
    const float PULSE_LENGTH = 0.01524;
    for (int i = 0; i < NUM_PULSES; i++) {
        WRITE(PHOTOGRAPH_PIN, HIGH);
        _delay_ms(PULSE_LENGTH);
        WRITE(PHOTOGRAPH_PIN, LOW);
        _delay_ms(PULSE_LENGTH);
    }
    delay(7.33);
    for (int i = 0; i < NUM_PULSES; i++) {
        WRITE(PHOTOGRAPH_PIN, HIGH);
        _delay_ms(PULSE_LENGTH);
        WRITE(PHOTOGRAPH_PIN, LOW);
        _delay_ms(PULSE_LENGTH);
    }
#endif // !CHDK && HAS_PHOTOGRAPH
}
#endif
#if defined (marlin4Due)
    // CHDK || PHOTOGRAPH_PIN
#endif
#if defined (marlin4Due) && ENABLED(HAS_LCD_CONTRAST)
/**
   * M250: Read and optionally set the LCD contrast
   */
inline void gcode_M250() {
    if (code_seen('C')) lcd_setcontrast(code_value_short() & 0x3F);
    SERIAL_PROTOCOLPGM("lcd contrast value: ");
    SERIAL_PROTOCOL(lcd_contrast);
    SERIAL_EOL;
}
#endif
#if defined (marlin4Due)
    // HAS_LCD_CONTRAST
#endif
#if defined (marlin4Due) && ENABLED(PREVENT_DANGEROUS_EXTRUDE)
void set_extrude_min_temp(float temp) {
    extrude_min_temp = temp;
}
/**
   * M302: Allow cold extrudes, or set the minimum extrude S<temperature>.
   */
inline void gcode_M302() {
    set_extrude_min_temp(code_seen('S') ? code_value() : 0);
}
#endif
#if defined (marlin4Due)
// PREVENT_DANGEROUS_EXTRUDE
/**
 * M303: PID relay autotune
 *       S<temperature> sets the target temperature. (default target temperature = 150C)
 *       E<extruder> (-1 for the bed)
 *       C<cycles>
 */
inline void gcode_M303() {
    int e = code_seen('E') ? code_value_short() : 0;
    int c = code_seen('C') ? code_value_short() : 5;
    float temp = code_seen('S') ? code_value() : (e < 0 ? 70.0 : 150.0);
    PID_autotune(temp, e, c);
}
#endif
#if defined (marlin4Due) && ENABLED(SCARA)
bool SCARA_move_to_cal(uint8_t delta_x, uint8_t delta_y) {
    //SoftEndsEnabled = false;              // Ignore soft endstops during calibration
    //SERIAL_ECHOLN(" Soft endstops disabled ");
    if (IsRunning()) {
        //gcode_get_destination(); // For X Y Z E F
        delta[X_AXIS] = delta_x;
        delta[Y_AXIS] = delta_y;
        calculate_SCARA_forward_Transform(delta);
        destination[X_AXIS] = delta[X_AXIS]/axis_scaling[X_AXIS];
        destination[Y_AXIS] = delta[Y_AXIS]/axis_scaling[Y_AXIS];
        prepare_move();
        //ok_to_send();
        return true;
    }
    return false;
}
/**
   * M360: SCARA calibration: Move to cal-position ThetaA (0 deg calibration)
   */
inline bool gcode_M360() {
    SERIAL_ECHOLN(" Cal: Theta 0 ");
    return SCARA_move_to_cal(0, 120);
}
/**
   * M361: SCARA calibration: Move to cal-position ThetaB (90 deg calibration - steps per degree)
   */
inline bool gcode_M361() {
    SERIAL_ECHOLN(" Cal: Theta 90 ");
    return SCARA_move_to_cal(90, 130);
}
/**
   * M362: SCARA calibration: Move to cal-position PsiA (0 deg calibration)
   */
inline bool gcode_M362() {
    SERIAL_ECHOLN(" Cal: Psi 0 ");
    return SCARA_move_to_cal(60, 180);
}
/**
   * M363: SCARA calibration: Move to cal-position PsiB (90 deg calibration - steps per degree)
   */
inline bool gcode_M363() {
    SERIAL_ECHOLN(" Cal: Psi 90 ");
    return SCARA_move_to_cal(50, 90);
}
/**
   * M364: SCARA calibration: Move to cal-position PSIC (90 deg to Theta calibration position)
   */
inline bool gcode_M364() {
    SERIAL_ECHOLN(" Cal: Theta-Psi 90 ");
    return SCARA_move_to_cal(45, 135);
}
/**
   * M365: SCARA calibration: Scaling factor, X, Y, Z axis
   */
inline void gcode_M365() {
    for (int8_t i = X_AXIS; i <= Z_AXIS; i++) {
        if (code_seen(axis_codes[i])) {
            axis_scaling[i] = code_value();
        }
    }
}
#endif
#if defined (marlin4Due)
    // SCARA
#endif
#if defined (marlin4Due) && ENABLED(EXT_SOLENOID)
void enable_solenoid(uint8_t num) {
    switch(num) {
    case 0:
        OUT_WRITE(SOL0_PIN, HIGH);
        break;
#if HAS_SOLENOID_1
    case 1:
        OUT_WRITE(SOL1_PIN, HIGH);
        break;
#endif
#if HAS_SOLENOID_2
    case 2:
        OUT_WRITE(SOL2_PIN, HIGH);
        break;
#endif
#if HAS_SOLENOID_3
    case 3:
        OUT_WRITE(SOL3_PIN, HIGH);
        break;
#endif
    default:
        SERIAL_ECHO_START;
        SERIAL_ECHOLNPGM(MSG_INVALID_SOLENOID);
        break;
    }
}
void enable_solenoid_on_active_extruder() {
    enable_solenoid(active_extruder);
}
void disable_all_solenoids() {
    OUT_WRITE(SOL0_PIN, LOW);
    OUT_WRITE(SOL1_PIN, LOW);
    OUT_WRITE(SOL2_PIN, LOW);
    OUT_WRITE(SOL3_PIN, LOW);
}
/**
   * M380: Enable solenoid on the active extruder
   */
inline void gcode_M380() {
    enable_solenoid_on_active_extruder();
}
/**
   * M381: Disable all solenoids
   */
inline void gcode_M381() {
    disable_all_solenoids();
}
#endif
#if defined (marlin4Due)
// EXT_SOLENOID
/**
 * M400: Finish all moves
 */
inline void gcode_M400() {
    st_synchronize();
}
#endif
#if defined (marlin4Due) && ((ENABLED(ENABLE_AUTO_BED_LEVELING) && DISABLED(Z_PROBE_SLED) && (HAS_SERVO_ENDSTOPS || ENABLED(Z_PROBE_ALLEN_KEY)) && )HAS_SERVO_ENDSTOPS )
void raise_z_for_servo() {
    float zpos = current_position[Z_AXIS], z_dest = Z_RAISE_BEFORE_HOMING;
    z_dest += axis_known_position[Z_AXIS] ? zprobe_zoffset : zpos;
    if (zpos < z_dest) do_blocking_move_to_z(z_dest); // also updates current_position
}
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && DISABLED(Z_PROBE_SLED) && (HAS_SERVO_ENDSTOPS || ENABLED(Z_PROBE_ALLEN_KEY)))
/**
   * M401: Engage Z Servo endstop if available
   */
inline void gcode_M401() {
#if HAS_SERVO_ENDSTOPS
    raise_z_for_servo();
#endif
    deploy_z_probe();
}
/**
   * M402: Retract Z Servo endstop if enabled
   */
inline void gcode_M402() {
#if HAS_SERVO_ENDSTOPS
    raise_z_for_servo();
#endif
    stow_z_probe(false);
}
#endif
#if defined (marlin4Due)
    // ENABLE_AUTO_BED_LEVELING && (HAS_SERVO_ENDSTOPS || Z_PROBE_ALLEN_KEY) && !Z_PROBE_SLED
#endif
#if defined (marlin4Due) && ENABLED(FILAMENT_SENSOR)
/**
   * M404: Display or set the nominal filament width (3mm, 1.75mm ) W<3.0>
   */
inline void gcode_M404() {
#if HAS_FILWIDTH
    if (code_seen('W')) {
        filament_width_nominal = code_value();
    } else {
        SERIAL_PROTOCOLPGM("Filament dia (nominal mm):");
        SERIAL_PROTOCOLLN(filament_width_nominal);
    }
#endif
}
/**
   * M405: Turn on filament sensor for control
   */
inline void gcode_M405() {
    if (code_seen('D')) meas_delay_cm = code_value();
    if (meas_delay_cm > MAX_MEASUREMENT_DELAY) meas_delay_cm = MAX_MEASUREMENT_DELAY;
    if (delay_index2 == -1) { //initialize the ring buffer if it has not been done since startup
        int temp_ratio = widthFil_to_size_ratio();
        for (delay_index1 = 0; delay_index1 < MAX_MEASUREMENT_DELAY + 1; ++delay_index1)
            measurement_delay[delay_index1] = temp_ratio - 100;  //subtract 100 to scale within a signed byte
        delay_index1 = delay_index2 = 0;
    }
    filament_sensor = true;
    //SERIAL_PROTOCOLPGM("Filament dia (measured mm):");
    //SERIAL_PROTOCOL(filament_width_meas);
    //SERIAL_PROTOCOLPGM("Extrusion ratio(%):");
    //SERIAL_PROTOCOL(extruder_multiplier[active_extruder]);
}
/**
   * M406: Turn off filament sensor for control
   */
inline void gcode_M406() {
    filament_sensor = false;
}
/**
   * M407: Get measured filament diameter on serial output
   */
inline void gcode_M407() {
    SERIAL_PROTOCOLPGM("Filament dia (measured mm):");
    SERIAL_PROTOCOLLN(filament_width_meas);
}
#endif
#if defined (marlin4Due)
// FILAMENT_SENSOR
/**
 * M410: Quickstop - Abort all planned moves
 *
 * This will stop the carriages mid-move, so most likely they
 * will be out of sync with the stepper position after this.
 */
inline void gcode_M410() {
    quickStop();
}
#endif
#if defined (marlin4Due) && ENABLED(MESH_BED_LEVELING)
/**
   * M420: Enable/Disable Mesh Bed Leveling
   */
inline void gcode_M420() {
    if (code_seen('S') && code_has_value()) mbl.active = !!code_value_short();
}
/**
   * M421: Set a single Mesh Bed Leveling Z coordinate
   */
inline void gcode_M421() {
    float x, y, z;
    bool err = false, hasX, hasY, hasZ;
    if ((hasX = code_seen('X'))) x = code_value();
    if ((hasY = code_seen('Y'))) y = code_value();
    if ((hasZ = code_seen('Z'))) z = code_value();
    if (!hasX || !hasY || !hasZ) {
        SERIAL_ERROR_START;
        SERIAL_ERRORLNPGM(MSG_ERR_M421_REQUIRES_XYZ);
        err = true;
    }
    if (x >= MESH_NUM_X_POINTS || y >= MESH_NUM_Y_POINTS) {
        SERIAL_ERROR_START;
        SERIAL_ERRORLNPGM(MSG_ERR_MESH_INDEX_OOB);
        err = true;
    }
    if (!err) mbl.set_z(mbl.select_x_index(x), mbl.select_y_index(y), z);
}
#endif
#if defined (marlin4Due)
/**
 * M428: Set home_offset based on the distance between the
 *       current_position and the nearest "reference point."
 *       If an axis is past center its endstop position
 *       is the reference-point. Otherwise it uses 0. This allows
 *       the Z offset to be set near the bed when using a max endstop.
 *
 *       M428 can't be used more than 2cm away from 0 or an endstop.
 *
 *       Use M206 to set these values directly.
 */
inline void gcode_M428() {
    bool err = false;
    float new_offs[3], new_pos[3];
    memcpy(new_pos, current_position, sizeof(new_pos));
    memcpy(new_offs, home_offset, sizeof(new_offs));
    for (int8_t i = X_AXIS; i <= Z_AXIS; i++) {
        if (axis_known_position[i]) {
            float base = (new_pos[i] > (min_pos[i] + max_pos[i]) / 2) ? base_home_pos(i) : 0,
                  diff = new_pos[i] - base;
            if (diff > -20 && diff < 20) {
                new_offs[i] -= diff;
                new_pos[i] = base;
            } else {
                SERIAL_ERROR_START;
                SERIAL_ERRORLNPGM(MSG_ERR_M428_TOO_FAR);
                LCD_ALERTMESSAGEPGM("Err: Too far!");
#if HAS_BUZZER
                enqueuecommands_P(PSTR("M300 S40 P200"));
#endif
                err = true;
                break;
            }
        }
    }
    if (!err) {
        memcpy(current_position, new_pos, sizeof(new_pos));
        memcpy(home_offset, new_offs, sizeof(new_offs));
        sync_plan_position();
        LCD_ALERTMESSAGEPGM("Offset applied.");
#if HAS_BUZZER
        enqueuecommands_P(PSTR("M300 S659 P200\nM300 S698 P200"));
#endif
    }
}
/**
 * M500: Store settings in EEPROM
 */
inline void gcode_M500() {
    Config_StoreSettings();
}
/**
 * M501: Read settings from EEPROM
 */
inline void gcode_M501() {
    Config_RetrieveSettings();
}
/**
 * M502: Revert to default settings
 */
inline void gcode_M502() {
    Config_ResetDefault();
}
/**
 * M503: print settings currently in memory
 */
inline void gcode_M503() {
    Config_PrintSettings(code_seen('S') && code_value() == 0);
}
#endif
#if defined (marlin4Due) && ENABLED(ABORT_ON_ENDSTOP_HIT_FEATURE_ENABLED)
/**
   * M540: Set whether SD card print should abort on endstop hit (M540 S<0|1>)
   */
inline void gcode_M540() {
    if (code_seen('S')) abort_on_endstop_hit = (code_value() > 0);
}
#endif
#if defined (marlin4Due)
    // ABORT_ON_ENDSTOP_HIT_FEATURE_ENABLED
#endif
#if defined (marlin4Due) && defined (CUSTOM_M_CODE_SET_Z_PROBE_OFFSET)
inline void gcode_SET_Z_PROBE_OFFSET() {
    float value;
    if (code_seen('Z')) {
        value = code_value();
        if (Z_PROBE_OFFSET_RANGE_MIN <= value && value <= Z_PROBE_OFFSET_RANGE_MAX) {
            zprobe_zoffset = value;
            SERIAL_ECHO_START;
            SERIAL_ECHOLNPGM(MSG_ZPROBE_ZOFFSET " " MSG_OK);
            SERIAL_EOL;
        } else {
            SERIAL_ECHO_START;
            SERIAL_ECHOPGM(MSG_ZPROBE_ZOFFSET);
            SERIAL_ECHOPGM(MSG_Z_MIN);
            SERIAL_ECHO(Z_PROBE_OFFSET_RANGE_MIN);
            SERIAL_ECHOPGM(MSG_Z_MAX);
            SERIAL_ECHO(Z_PROBE_OFFSET_RANGE_MAX);
            SERIAL_EOL;
        }
    } else {
        SERIAL_ECHO_START;
        SERIAL_ECHOPGM(MSG_ZPROBE_ZOFFSET " : ");
        SERIAL_ECHO(zprobe_zoffset);
        SERIAL_EOL;
    }
}
#endif
#if defined (marlin4Due)
    // CUSTOM_M_CODE_SET_Z_PROBE_OFFSET
#endif
#if defined (marlin4Due) && ENABLED(FILAMENTCHANGEENABLE)
/**
   * M600: Pause for filament change
   *
   *  E[distance] - Retract the filament this far (negative value)
   *  Z[distance] - Move the Z axis by this distance
   *  X[position] - Move to this X position, with Y
   *  Y[position] - Move to this Y position, with X
   *  L[distance] - Retract distance for removal (manual reload)
   *
   *  Default values are used for omitted arguments.
   *
   */
inline void gcode_M600() {
    if (degHotend(active_extruder) < extrude_min_temp) {
        SERIAL_ERROR_START;
        SERIAL_ERRORLNPGM(MSG_TOO_COLD_FOR_M600);
        return;
    }
    float lastpos[NUM_AXIS], fr60 = feedrate / 60;
    for (int i=0; i<NUM_AXIS; i++)
        lastpos[i] = destination[i] = current_position[i];
#if ENABLED(DELTA)
#define RUNPLAN calculate_delta(destination); \
                      plan_buffer_line(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], destination[E_AXIS], fr60, active_extruder);
#else
#define RUNPLAN line_to_destination();
#endif
    //retract by E
    if (code_seen('E')) destination[E_AXIS] += code_value();
#ifdef FILAMENTCHANGE_FIRSTRETRACT
    else destination[E_AXIS] += FILAMENTCHANGE_FIRSTRETRACT;
#endif
    RUNPLAN;
    //lift Z
    if (code_seen('Z')) destination[Z_AXIS] += code_value();
#ifdef FILAMENTCHANGE_ZADD
    else destination[Z_AXIS] += FILAMENTCHANGE_ZADD;
#endif
    RUNPLAN;
    //move xy
    if (code_seen('X')) destination[X_AXIS] = code_value();
#ifdef FILAMENTCHANGE_XPOS
    else destination[X_AXIS] = FILAMENTCHANGE_XPOS;
#endif
    if (code_seen('Y')) destination[Y_AXIS] = code_value();
#ifdef FILAMENTCHANGE_YPOS
    else destination[Y_AXIS] = FILAMENTCHANGE_YPOS;
#endif
    RUNPLAN;
    if (code_seen('L')) destination[E_AXIS] += code_value();
#ifdef FILAMENTCHANGE_FINALRETRACT
    else destination[E_AXIS] += FILAMENTCHANGE_FINALRETRACT;
#endif
    RUNPLAN;
    //finish moves
    st_synchronize();
    //disable extruder steppers so filament can be removed
    disable_e0();
    disable_e1();
    disable_e2();
    disable_e3();
    delay(100);
    LCD_ALERTMESSAGEPGM(MSG_FILAMENTCHANGE);
    millis_t next_tick = 0;
    while (!lcd_clicked()) {
#ifndef AUTO_FILAMENT_CHANGE
        millis_t ms = millis();
        if (ms >= next_tick) {
            lcd_quick_feedback();
            next_tick = ms + 2500; // feedback every 2.5s while waiting
        }
        manage_heater();
        manage_inactivity(true);
        lcd_update();
#else
        current_position[E_AXIS] += AUTO_FILAMENT_CHANGE_LENGTH;
        destination[E_AXIS] = current_position[E_AXIS];
        line_to_destination(AUTO_FILAMENT_CHANGE_FEEDRATE);
        st_synchronize();
#endif
    } // while(!lcd_clicked)
    lcd_quick_feedback(); // click sound feedback
#ifdef AUTO_FILAMENT_CHANGE
    current_position[E_AXIS] = 0;
    st_synchronize();
#endif
    //return to normal
    if (code_seen('L')) destination[E_AXIS] -= code_value();
#ifdef FILAMENTCHANGE_FINALRETRACT
    else destination[E_AXIS] -= FILAMENTCHANGE_FINALRETRACT;
#endif
    current_position[E_AXIS] = destination[E_AXIS]; //the long retract of L is compensated by manual filament feeding
    plan_set_e_position(current_position[E_AXIS]);
    RUNPLAN; //should do nothing
    lcd_reset_alert_level();
#if ENABLED(DELTA)
    // Move XYZ to starting position, then E
    calculate_delta(lastpos);
    plan_buffer_line(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], destination[E_AXIS], fr60, active_extruder);
    plan_buffer_line(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], lastpos[E_AXIS], fr60, active_extruder);
#else
    // Move XY to starting position, then Z, then E
    destination[X_AXIS] = lastpos[X_AXIS];
    destination[Y_AXIS] = lastpos[Y_AXIS];
    line_to_destination();
    destination[Z_AXIS] = lastpos[Z_AXIS];
    line_to_destination();
    destination[E_AXIS] = lastpos[E_AXIS];
    line_to_destination();
#endif
#if ENABLED(FILAMENT_RUNOUT_SENSOR)
    filrunoutEnqueued = false;
#endif
}
#endif
#if defined (marlin4Due)
    // FILAMENTCHANGEENABLE
#endif
#if defined (marlin4Due) && ENABLED(DUAL_X_CARRIAGE)
/**
   * M605: Set dual x-carriage movement mode
   *
   *    M605 S0: Full control mode. The slicer has full control over x-carriage movement
   *    M605 S1: Auto-park mode. The inactive head will auto park/unpark without slicer involvement
   *    M605 S2 [Xnnn] [Rmmm]: Duplication mode. The second extruder will duplicate the first with nnn
   *                         millimeters x-offset and an optional differential hotend temperature of
   *                         mmm degrees. E.g., with "M605 S2 X100 R2" the second extruder will duplicate
   *                         the first with a spacing of 100mm in the x direction and 2 degrees hotter.
   *
   *    Note: the X axis should be homed after changing dual x-carriage mode.
   */
inline void gcode_M605() {
    st_synchronize();
    if (code_seen('S')) dual_x_carriage_mode = code_value();
    switch(dual_x_carriage_mode) {
    case DXC_DUPLICATION_MODE:
        if (code_seen('X')) duplicate_extruder_x_offset = max(code_value(), X2_MIN_POS - x_home_pos(0));
        if (code_seen('R')) duplicate_extruder_temp_offset = code_value();
        SERIAL_ECHO_START;
        SERIAL_ECHOPGM(MSG_HOTEND_OFFSET);
        SERIAL_CHAR(' ');
        SERIAL_ECHO(extruder_offset[X_AXIS][0]);
        SERIAL_CHAR(',');
        SERIAL_ECHO(extruder_offset[Y_AXIS][0]);
        SERIAL_CHAR(' ');
        SERIAL_ECHO(duplicate_extruder_x_offset);
        SERIAL_CHAR(',');
        SERIAL_ECHOLN(extruder_offset[Y_AXIS][1]);
        break;
    case DXC_FULL_CONTROL_MODE:
    case DXC_AUTO_PARK_MODE:
        break;
    default:
        dual_x_carriage_mode = DEFAULT_DUAL_X_CARRIAGE_MODE;
        break;
    }
    active_extruder_parked = false;
    extruder_duplication_enabled = false;
    delayed_move_time = 0;
}
#endif
#if defined (marlin4Due)
// DUAL_X_CARRIAGE
/**
 * M907: Set digital trimpot motor current using axis codes X, Y, Z, E, B, S
 */
inline void gcode_M907() {
#if HAS_DIGIPOTSS
    for (int i=0; i<NUM_AXIS; i++)
        if (code_seen(axis_codes[i])) digipot_current(i, code_value());
    if (code_seen('B')) digipot_current(4, code_value());
    if (code_seen('S')) for (int i=0; i<=4; i++) digipot_current(i, code_value());
#endif
#ifdef MOTOR_CURRENT_PWM_XY_PIN
    if (code_seen('X')) digipot_current(0, code_value());
#endif
#ifdef MOTOR_CURRENT_PWM_Z_PIN
    if (code_seen('Z')) digipot_current(1, code_value());
#endif
#ifdef MOTOR_CURRENT_PWM_E_PIN
    if (code_seen('E')) digipot_current(2, code_value());
#endif
#if ENABLED(DIGIPOT_I2C)
    // this one uses actual amps in floating point
    for (int i=0; i<NUM_AXIS; i++) if(code_seen(axis_codes[i])) digipot_i2c_set_current(i, code_value());
    // for each additional extruder (named B,C,D,E..., channels 4,5,6,7...)
    for (int i=NUM_AXIS; i<DIGIPOT_I2C_NUM_CHANNELS; i++) if(code_seen('B'+i-NUM_AXIS)) digipot_i2c_set_current(i, code_value());
#endif
}
#endif
#if defined (marlin4Due) && HAS_DIGIPOTSS
/**
   * M908: Control digital trimpot directly (M908 P<pin> S<current>)
   */
inline void gcode_M908() {
    digitalPotWrite(
        code_seen('P') ? code_value() : 0,
        code_seen('S') ? code_value() : 0
    );
}
#endif
#if defined (marlin4Due)
    // HAS_DIGIPOTSS
#endif
#if defined (marlin4Due) && HAS_MICROSTEPS
// M350 Set microstepping mode. Warning: Steps per unit remains unchanged. S code sets stepping mode for all drivers.
inline void gcode_M350() {
    if(code_seen('S')) for(int i=0; i<=4; i++) microstep_mode(i,code_value());
    for(int i=0; i<NUM_AXIS; i++) if(code_seen(axis_codes[i])) microstep_mode(i,(uint8_t)code_value());
    if(code_seen('B')) microstep_mode(4,code_value());
    microstep_readings();
}
/**
   * M351: Toggle MS1 MS2 pins directly with axis codes X Y Z E B
   *       S# determines MS1 or MS2, X# sets the pin high/low.
   */
inline void gcode_M351() {
    if (code_seen('S')) switch(code_value_short()) {
        case 1:
            for(int i=0; i<NUM_AXIS; i++) if (code_seen(axis_codes[i])) microstep_ms(i, code_value(), -1);
            if (code_seen('B')) microstep_ms(4, code_value(), -1);
            break;
        case 2:
            for(int i=0; i<NUM_AXIS; i++) if (code_seen(axis_codes[i])) microstep_ms(i, -1, code_value());
            if (code_seen('B')) microstep_ms(4, -1, code_value());
            break;
        }
    microstep_readings();
}
#endif
#if defined (marlin4Due)
// HAS_MICROSTEPS
inline void gcode_M800() {
    SERIAL_ECHOLN(get_fsr_value());
}
/**
 * M999: Restart after being stopped
 */
inline void gcode_M999() {
    Running = true;
    lcd_reset_alert_level();
    gcode_LastN = Stopped_gcode_LastN;
    FlushSerialRequestResend();
}
/**
 * T0-T3: Switch tool, usually switching extruders
 *
 *   F[mm/min] Set the movement feedrate
 */
inline void gcode_T(uint8_t tmp_extruder) {
    if (tmp_extruder >= EXTRUDERS) {
        SERIAL_ECHO_START;
        SERIAL_CHAR('T');
        SERIAL_PROTOCOL_F(tmp_extruder,DEC);
        SERIAL_ECHOLN(MSG_INVALID_EXTRUDER);
    } else {
        target_extruder = tmp_extruder;
#if EXTRUDERS > 1
        bool make_move = false;
#endif
        if (code_seen('F')) {
#if EXTRUDERS > 1
            make_move = true;
#endif
            float next_feedrate = code_value();
            if (next_feedrate > 0.0) feedrate = next_feedrate;
        }
#if EXTRUDERS > 1
        if (tmp_extruder != active_extruder) {
            // Save current position to return to after applying extruder offset
            set_destination_to_current();
#if ENABLED(DUAL_X_CARRIAGE)
            if (dual_x_carriage_mode == DXC_AUTO_PARK_MODE && IsRunning() &&
                    (delayed_move_time != 0 || current_position[X_AXIS] != x_home_pos(active_extruder))) {
                // Park old head: 1) raise 2) move to park position 3) lower
                plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS] + TOOLCHANGE_PARK_ZLIFT,
                                 current_position[E_AXIS], max_feedrate[Z_AXIS], active_extruder);
                plan_buffer_line(x_home_pos(active_extruder), current_position[Y_AXIS], current_position[Z_AXIS] + TOOLCHANGE_PARK_ZLIFT,
                                 current_position[E_AXIS], max_feedrate[X_AXIS], active_extruder);
                plan_buffer_line(x_home_pos(active_extruder), current_position[Y_AXIS], current_position[Z_AXIS],
                                 current_position[E_AXIS], max_feedrate[Z_AXIS], active_extruder);
                st_synchronize();
            }
            // apply Y & Z extruder offset (x offset is already used in determining home pos)
            current_position[Y_AXIS] = current_position[Y_AXIS] -
                                       extruder_offset[Y_AXIS][active_extruder] +
                                       extruder_offset[Y_AXIS][tmp_extruder];
            current_position[Z_AXIS] = current_position[Z_AXIS] -
                                       extruder_offset[Z_AXIS][active_extruder] +
                                       extruder_offset[Z_AXIS][tmp_extruder];
            active_extruder = tmp_extruder;
            // This function resets the max/min values - the current position may be overwritten below.
            set_axis_is_at_home(X_AXIS);
            if (dual_x_carriage_mode == DXC_FULL_CONTROL_MODE) {
                current_position[X_AXIS] = inactive_extruder_x_pos;
                inactive_extruder_x_pos = destination[X_AXIS];
            } else if (dual_x_carriage_mode == DXC_DUPLICATION_MODE) {
                active_extruder_parked = (active_extruder == 0); // this triggers the second extruder to move into the duplication position
                if (active_extruder == 0 || active_extruder_parked)
                    current_position[X_AXIS] = inactive_extruder_x_pos;
                else
                    current_position[X_AXIS] = destination[X_AXIS] + duplicate_extruder_x_offset;
                inactive_extruder_x_pos = destination[X_AXIS];
                extruder_duplication_enabled = false;
            } else {
                // record raised toolhead position for use by unpark
                memcpy(raised_parked_position, current_position, sizeof(raised_parked_position));
                raised_parked_position[Z_AXIS] += TOOLCHANGE_UNPARK_ZLIFT;
                active_extruder_parked = true;
                delayed_move_time = 0;
            }
#else // !DUAL_X_CARRIAGE
            // Offset extruder (only by XY)
            for (int i=X_AXIS; i<=Y_AXIS; i++)
                current_position[i] += extruder_offset[i][tmp_extruder] - extruder_offset[i][active_extruder];
            // Set the new active extruder and position
            active_extruder = tmp_extruder;
#endif // !DUAL_X_CARRIAGE
#if ENABLED(DELTA)
            sync_plan_position_delta();
#else
            sync_plan_position();
#endif
            // Move to the old position if 'F' was in the parameters
            if (make_move && IsRunning()) prepare_move();
        }
#if ENABLED(EXT_SOLENOID)
        st_synchronize();
        disable_all_solenoids();
        enable_solenoid_on_active_extruder();
#endif // EXT_SOLENOID
#endif // EXTRUDERS > 1
        SERIAL_ECHO_START;
        SERIAL_ECHO(MSG_ACTIVE_EXTRUDER);
        SERIAL_PROTOCOLLN((int)active_extruder);
    }
}
/**
 * Process a single command and dispatch it to its handler
 * This is called from the main loop()
 */
void process_next_command() {
    current_command = command_queue[cmd_queue_index_r];
    if ((marlin_debug_flags & DEBUG_ECHO)) {
        SERIAL_ECHO_START;
        SERIAL_ECHOLN(current_command);
    }
    // Sanitize the current command:
    //  - Skip leading spaces
    //  - Bypass N[0-9][0-9]*[ ]*
    //  - Overwrite * with nul to mark the end
    while (*current_command == ' ') ++current_command;
    if (*current_command == 'N' && ((current_command[1] >= '0' && current_command[1] <= '9') || current_command[1] == '-')) {
        current_command += 2; // skip N[-0-9]
        while (*current_command >= '0' && *current_command <= '9') ++current_command; // skip [0-9]*
        while (*current_command == ' ') ++current_command; // skip [ ]*
    }
    char *starpos = strchr(current_command, '*');  // * should always be the last parameter
    if (starpos) while (*starpos == ' ' || *starpos == '*') *starpos-- = '\0'; // nullify '*' and ' '
    // Get the command code, which must be G, M, or T
    char command_code = *current_command;
    // The code must have a numeric value
    bool code_is_good = (current_command[1] >= '0' && current_command[1] <= '9');
    int codenum; // define ahead of goto
    // Bail early if there's no code
    if (!code_is_good) goto ExitUnknownCommand;
    // Args pointer optimizes code_seen, especially those taking XYZEF
    // This wastes a little cpu on commands that expect no arguments.
    current_command_args = current_command;
    while (*current_command_args && *current_command_args != ' ') ++current_command_args;
    while (*current_command_args == ' ') ++current_command_args;
    // Interpret the code int
    seen_pointer = current_command;
    codenum = code_value_short();
    // Handle a known G, M, or T
    switch(command_code) {
    case 'G':
        switch (codenum) {
        // G0, G1
        case 0:
        case 1:
            gcode_G0_G1();
            break;
            // G2, G3
#if DISABLED(SCARA)
        case 2: // G2  - CW ARC
        case 3: // G3  - CCW ARC
            gcode_G2_G3(codenum == 2);
            break;
#endif
        // G4 Dwell
        case 4:
            gcode_G4();
            break;
#if ENABLED(FWRETRACT)
        case 10: // G10: retract
        case 11: // G11: retract_recover
            gcode_G10_G11(codenum == 10);
            break;
#endif //FWRETRACT
        case 28: // G28: Home all axes, one at a time
            gcode_G28();
            break;
#if ENABLED(ENABLE_AUTO_BED_LEVELING) || ENABLED(MESH_BED_LEVELING)
        case 29: // G29 Detailed Z-Probe, probes the bed at 3 or more points.
            gcode_G29();
            break;
#endif
#if ENABLED(ENABLE_AUTO_BED_LEVELING)
#if DISABLED(Z_PROBE_SLED)
        case 30: // G30 Single Z Probe
            gcode_G30();
            break;
#else // Z_PROBE_SLED
        case 31: // G31: dock the sled
        case 32: // G32: undock the sled
            dock_sled(codenum == 31);
            break;
#endif // Z_PROBE_SLED
#endif // ENABLE_AUTO_BED_LEVELING
        case 90: // G90
            relative_mode = false;
            break;
        case 91: // G91
            relative_mode = true;
            break;
        case 92: // G92
            gcode_G92();
            break;
        }
        break;
    case 'M':
        switch (codenum) {
#if ENABLED(ULTIPANEL)
        case 0: // M0 - Unconditional stop - Wait for user button press on LCD
        case 1: // M1 - Conditional stop - Wait for user button press on LCD
            gcode_M0_M1();
            break;
#endif // ULTIPANEL
        case 17:
            gcode_M17();
            break;
#if ENABLED(SDSUPPORT)
        case 20: // M20 - list SD card
            gcode_M20();
            break;
        case 21: // M21 - init SD card
            gcode_M21();
            break;
        case 22: //M22 - release SD card
            gcode_M22();
            break;
        case 23: //M23 - Select file
            gcode_M23();
            break;
        case 24: //M24 - Start SD print
            gcode_M24();
            break;
        case 25: //M25 - Pause SD print
            gcode_M25();
            break;
        case 26: //M26 - Set SD index
            gcode_M26();
            break;
        case 27: //M27 - Get SD status
            gcode_M27();
            break;
        case 28: //M28 - Start SD write
            gcode_M28();
            break;
        case 29: //M29 - Stop SD write
            gcode_M29();
            break;
        case 30: //M30 <filename> Delete File
            gcode_M30();
            break;
        case 32: //M32 - Select file and start SD print
            gcode_M32();
            break;
#if ENABLED(LONG_FILENAME_HOST_SUPPORT)
        case 33: //M33 - Get the long full path to a file or folder
            gcode_M33();
            break;
#endif // LONG_FILENAME_HOST_SUPPORT
        case 928: //M928 - Start SD write
            gcode_M928();
            break;
#endif //SDSUPPORT
        case 31: //M31 take time since the start of the SD print or an M109 command
            gcode_M31();
            break;
        case 42: //M42 -Change pin status via gcode
            gcode_M42();
            break;
#if ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(Z_PROBE_REPEATABILITY_TEST)
        case 48: // M48 Z-Probe repeatability
            gcode_M48();
            break;
#endif // ENABLE_AUTO_BED_LEVELING && Z_PROBE_REPEATABILITY_TEST
#ifdef M100_FREE_MEMORY_WATCHER
        case 100:
            gcode_M100();
            break;
#endif
        case 104: // M104
            gcode_M104();
            break;
        case 111: // M111: Set debug level
            gcode_M111();
            break;
        case 112: // M112: Emergency Stop
            gcode_M112();
            break;
        case 140: // M140: Set bed temp
            gcode_M140();
            break;
        case 105: // M105: Read current temperature
            gcode_M105();
            return; // "ok" already printed
        case 109: // M109: Wait for temperature
            gcode_M109();
            break;
#if HAS_TEMP_BED
        case 190: // M190: Wait for bed heater to reach target
            gcode_M190();
            break;
#endif // HAS_TEMP_BED
#if HAS_FAN
        case 106: // M106: Fan On
            gcode_M106();
            break;
        case 107: // M107: Fan Off
            gcode_M107();
            break;
#endif // HAS_FAN
#if ENABLED(BARICUDA)
            // PWM for HEATER_1_PIN
#if HAS_HEATER_1
        case 126: // M126: valve open
            gcode_M126();
            break;
        case 127: // M127: valve closed
            gcode_M127();
            break;
#endif // HAS_HEATER_1
            // PWM for HEATER_2_PIN
#if HAS_HEATER_2
        case 128: // M128: valve open
            gcode_M128();
            break;
        case 129: // M129: valve closed
            gcode_M129();
            break;
#endif // HAS_HEATER_2
#endif // BARICUDA
#if HAS_POWER_SWITCH
        case 80: // M80: Turn on Power Supply
            gcode_M80();
            break;
#endif // HAS_POWER_SWITCH
        case 81: // M81: Turn off Power, including Power Supply, if possible
            gcode_M81();
            break;
        case 82:
            gcode_M82();
            break;
        case 83:
            gcode_M83();
            break;
        case 18: // (for compatibility)
        case 84: // M84
            gcode_M18_M84();
            break;
        case 85: // M85
            gcode_M85();
            break;
        case 92: // M92: Set the steps-per-unit for one or more axes
            gcode_M92();
            break;
        case 115: // M115: Report capabilities
            gcode_M115();
            break;
        case 117: // M117: Set LCD message text, if possible
            gcode_M117();
            break;
        case 114: // M114: Report current position
            gcode_M114();
            break;
        case 120: // M120: Enable endstops
            gcode_M120();
            break;
        case 121: // M121: Disable endstops
            gcode_M121();
            break;
        case 119: // M119: Report endstop states
            gcode_M119();
            break;
#if ENABLED(ULTIPANEL)
        case 145: // M145: Set material heatup parameters
            gcode_M145();
            break;
#endif
#if ENABLED(BLINKM)
        case 150: // M150
            gcode_M150();
            break;
#endif //BLINKM
        case 200: // M200 D<millimeters> set filament diameter and set E axis units to cubic millimeters (use S0 to set back to millimeters).
            gcode_M200();
            break;
        case 201: // M201
            gcode_M201();
            break;
#if 0 // Not used for Sprinter/grbl gen6
        case 202: // M202
            gcode_M202();
            break;
#endif
        case 203: // M203 max feedrate mm/sec
            gcode_M203();
            break;
        case 204: // M204 acclereration S normal moves T filmanent only moves
            gcode_M204();
            break;
        case 205: //M205 advanced settings:  minimum travel speed S=while printing T=travel only,  B=minimum segment time X= maximum xy jerk, Z=maximum Z jerk
            gcode_M205();
            break;
        case 206: // M206 additional homing offset
            gcode_M206();
            break;
#if ENABLED(DELTA)
        case 665: // M665 set delta configurations L<diagonal_rod> R<delta_radius> S<segments_per_sec>
            gcode_M665();
            break;
#endif
#if ENABLED(DELTA) || ENABLED(Z_DUAL_ENDSTOPS)
        case 666: // M666 set delta / dual endstop adjustment
            gcode_M666();
            break;
#endif
#if ENABLED(FWRETRACT)
        case 207: //M207 - set retract length S[positive mm] F[feedrate mm/min] Z[additional zlift/hop]
            gcode_M207();
            break;
        case 208: // M208 - set retract recover length S[positive mm surplus to the M207 S*] F[feedrate mm/min]
            gcode_M208();
            break;
        case 209: // M209 - S<1=true/0=false> enable automatic retract detect if the slicer did not support G10/11: every normal extrude-only move will be classified as retract depending on the direction.
            gcode_M209();
            break;
#endif // FWRETRACT
#if EXTRUDERS > 1
        case 218: // M218 - set hotend offset (in mm), T<extruder_number> X<offset_on_X> Y<offset_on_Y>
            gcode_M218();
            break;
#endif
        case 220: // M220 S<factor in percent>- set speed factor override percentage
            gcode_M220();
            break;
        case 221: // M221 S<factor in percent>- set extrude factor override percentage
            gcode_M221();
            break;
        case 226: // M226 P<pin number> S<pin state>- Wait until the specified pin reaches the state required
            gcode_M226();
            break;
#if HAS_SERVOS
        case 280: // M280 - set servo position absolute. P: servo index, S: angle or microseconds
            gcode_M280();
            break;
#endif // HAS_SERVOS
#if HAS_BUZZER
        case 300: // M300 - Play beep tone
            gcode_M300();
            break;
#endif // HAS_BUZZER
#if ENABLED(PIDTEMP)
        case 301: // M301
            gcode_M301();
            break;
#endif // PIDTEMP
#if ENABLED(PIDTEMPBED)
        case 304: // M304
            gcode_M304();
            break;
#endif // PIDTEMPBED
#if defined(CHDK) || HAS_PHOTOGRAPH
        case 240: // M240  Triggers a camera by emulating a Canon RC-1 : http://www.doc-diy.net/photo/rc-1_hacked/
            gcode_M240();
            break;
#endif // CHDK || PHOTOGRAPH_PIN
#if ENABLED(HAS_LCD_CONTRAST)
        case 250: // M250  Set LCD contrast value: C<value> (value 0..63)
            gcode_M250();
            break;
#endif // HAS_LCD_CONTRAST
#if ENABLED(PREVENT_DANGEROUS_EXTRUDE)
        case 302: // allow cold extrudes, or set the minimum extrude temperature
            gcode_M302();
            break;
#endif // PREVENT_DANGEROUS_EXTRUDE
        case 303: // M303 PID autotune
            gcode_M303();
            break;
#if ENABLED(SCARA)
        case 360:  // M360 SCARA Theta pos1
            if (gcode_M360()) return;
            break;
        case 361:  // M361 SCARA Theta pos2
            if (gcode_M361()) return;
            break;
        case 362:  // M362 SCARA Psi pos1
            if (gcode_M362()) return;
            break;
        case 363:  // M363 SCARA Psi pos2
            if (gcode_M363()) return;
            break;
        case 364:  // M364 SCARA Psi pos3 (90 deg to Theta)
            if (gcode_M364()) return;
            break;
        case 365: // M365 Set SCARA scaling for X Y Z
            gcode_M365();
            break;
#endif // SCARA
        case 400: // M400 finish all moves
            gcode_M400();
            break;
#if ENABLED(ENABLE_AUTO_BED_LEVELING) && (HAS_SERVO_ENDSTOPS || ENABLED(Z_PROBE_ALLEN_KEY)) && DISABLED(Z_PROBE_SLED)
        case 401:
            gcode_M401();
            break;
        case 402:
            gcode_M402();
            break;
#endif // ENABLE_AUTO_BED_LEVELING && (HAS_SERVO_ENDSTOPS || Z_PROBE_ALLEN_KEY) && !Z_PROBE_SLED
#if ENABLED(FILAMENT_SENSOR)
        case 404:  //M404 Enter the nominal filament width (3mm, 1.75mm ) N<3.0> or display nominal filament width
            gcode_M404();
            break;
        case 405:  //M405 Turn on filament sensor for control
            gcode_M405();
            break;
        case 406:  //M406 Turn off filament sensor for control
            gcode_M406();
            break;
        case 407:   //M407 Display measured filament diameter
            gcode_M407();
            break;
#endif // FILAMENT_SENSOR
        case 410: // M410 quickstop - Abort all the planned moves.
            gcode_M410();
            break;
#if ENABLED(MESH_BED_LEVELING)
        case 420: // M420 Enable/Disable Mesh Bed Leveling
            gcode_M420();
            break;
        case 421: // M421 Set a Mesh Bed Leveling Z coordinate
            gcode_M421();
            break;
#endif
        case 428: // M428 Apply current_position to home_offset
            gcode_M428();
            break;
        case 500: // M500 Store settings in EEPROM
            gcode_M500();
            break;
        case 501: // M501 Read settings from EEPROM
            gcode_M501();
            break;
        case 502: // M502 Revert to default settings
            gcode_M502();
            break;
        case 503: // M503 print settings currently in memory
            gcode_M503();
            break;
#if ENABLED(ABORT_ON_ENDSTOP_HIT_FEATURE_ENABLED)
        case 540:
            gcode_M540();
            break;
#endif
#ifdef CUSTOM_M_CODE_SET_Z_PROBE_OFFSET
        case CUSTOM_M_CODE_SET_Z_PROBE_OFFSET:
            gcode_SET_Z_PROBE_OFFSET();
            break;
#endif // CUSTOM_M_CODE_SET_Z_PROBE_OFFSET
#if ENABLED(FILAMENTCHANGEENABLE)
        case 600: //Pause for filament change X[pos] Y[pos] Z[relative lift] E[initial retract] L[later retract distance for removal]
            gcode_M600();
            break;
#endif // FILAMENTCHANGEENABLE
#if ENABLED(DUAL_X_CARRIAGE)
        case 605:
            gcode_M605();
            break;
#endif // DUAL_X_CARRIAGE
        case 907: // M907 Set digital trimpot motor current using axis codes.
            gcode_M907();
            break;
#if HAS_DIGIPOTSS
        case 908: // M908 Control digital trimpot directly.
            gcode_M908();
            break;
#endif // HAS_DIGIPOTSS
#if HAS_MICROSTEPS
        case 350: // M350 Set microstepping mode. Warning: Steps per unit remains unchanged. S code sets stepping mode for all drivers.
            gcode_M350();
            break;
        case 351: // M351 Toggle MS1 MS2 pins directly, S# determines MS1 or MS2, X# sets the pin high/low.
            gcode_M351();
            break;
#endif // HAS_MICROSTEPS
        case 800:
            gcode_M800();
            break;
        case 999: // M999: Restart after being Stopped
            gcode_M999();
            break;
        }
        break;
    case 'T':
        gcode_T(codenum);
        break;
    default:
        code_is_good = false;
    }
ExitUnknownCommand:
    // Still unknown command? Throw an error
    if (!code_is_good) unknown_command_error();
    ok_to_send();
}
void FlushSerialRequestResend() {
    //char command_queue[cmd_queue_index_r][100]="Resend:";
    MYSERIAL.flush();
    SERIAL_PROTOCOLPGM(MSG_RESEND);
    SERIAL_PROTOCOLLN(gcode_LastN + 1);
    ok_to_send();
}
void ok_to_send() {
    refresh_cmd_timeout();
#if ENABLED(SDSUPPORT)
    if (fromsd[cmd_queue_index_r]) return;
#endif
    SERIAL_PROTOCOLPGM(MSG_OK);
#if ENABLED(ADVANCED_OK)
    SERIAL_PROTOCOLPGM(" N");
    SERIAL_PROTOCOL(gcode_LastN);
    SERIAL_PROTOCOLPGM(" P");
    SERIAL_PROTOCOL(int(BLOCK_BUFFER_SIZE - movesplanned() - 1));
    SERIAL_PROTOCOLPGM(" B");
    SERIAL_PROTOCOL(BUFSIZE - commands_in_queue);
#endif
    SERIAL_EOL;
}
void clamp_to_software_endstops(float target[3]) {
    if (min_software_endstops) {
        NOLESS(target[X_AXIS], min_pos[X_AXIS]);
        NOLESS(target[Y_AXIS], min_pos[Y_AXIS]);
        float negative_z_offset = 0;
#if ENABLED(ENABLE_AUTO_BED_LEVELING)
        if (zprobe_zoffset < 0) negative_z_offset += zprobe_zoffset;
        if (home_offset[Z_AXIS] < 0) negative_z_offset += home_offset[Z_AXIS];
#endif
        NOLESS(target[Z_AXIS], min_pos[Z_AXIS] + negative_z_offset);
    }
    if (max_software_endstops) {
        NOMORE(target[X_AXIS], max_pos[X_AXIS]);
        NOMORE(target[Y_AXIS], max_pos[Y_AXIS]);
        NOMORE(target[Z_AXIS], max_pos[Z_AXIS]);
    }
}
#endif
#if defined (marlin4Due) && ENABLED(DELTA)
void recalc_delta_settings(float radius, float diagonal_rod) {
    delta_tower1_x = -SIN_60 * radius;  // front left tower
    delta_tower1_y = -COS_60 * radius;
    delta_tower2_x =  SIN_60 * radius;  // front right tower
    delta_tower2_y = -COS_60 * radius;
    delta_tower3_x = 0.0;               // back middle tower
    delta_tower3_y = radius;
    delta_diagonal_rod_2 = sq(diagonal_rod);
}
void calculate_delta(float cartesian[3]) {
    delta[X_AXIS] = sqrt(delta_diagonal_rod_2
                         - sq(delta_tower1_x-cartesian[X_AXIS])
                         - sq(delta_tower1_y-cartesian[Y_AXIS])
                        ) + cartesian[Z_AXIS];
    delta[Y_AXIS] = sqrt(delta_diagonal_rod_2
                         - sq(delta_tower2_x-cartesian[X_AXIS])
                         - sq(delta_tower2_y-cartesian[Y_AXIS])
                        ) + cartesian[Z_AXIS];
    delta[Z_AXIS] = sqrt(delta_diagonal_rod_2
                         - sq(delta_tower3_x-cartesian[X_AXIS])
                         - sq(delta_tower3_y-cartesian[Y_AXIS])
                        ) + cartesian[Z_AXIS];
    /*
    SERIAL_ECHOPGM("cartesian x="); SERIAL_ECHO(cartesian[X_AXIS]);
    SERIAL_ECHOPGM(" y="); SERIAL_ECHO(cartesian[Y_AXIS]);
    SERIAL_ECHOPGM(" z="); SERIAL_ECHOLN(cartesian[Z_AXIS]);

    SERIAL_ECHOPGM("delta x="); SERIAL_ECHO(delta[X_AXIS]);
    SERIAL_ECHOPGM(" y="); SERIAL_ECHO(delta[Y_AXIS]);
    SERIAL_ECHOPGM(" z="); SERIAL_ECHOLN(delta[Z_AXIS]);
    */
}
#endif
#if defined (marlin4Due) && (ENABLED(ENABLE_AUTO_BED_LEVELING) && ENABLED(DELTA) )
// Adjust print surface height by linear interpolation over the bed_level array.
void adjust_delta(float cartesian[3]) {
    if (delta_grid_spacing[0] == 0 || delta_grid_spacing[1] == 0) return; // G29 not done!
    int half = (AUTO_BED_LEVELING_GRID_POINTS - 1) / 2;
    float h1 = 0.001 - half, h2 = half - 0.001,
          grid_x = max(h1, min(h2, cartesian[X_AXIS] / delta_grid_spacing[0])),
          grid_y = max(h1, min(h2, cartesian[Y_AXIS] / delta_grid_spacing[1]));
    int floor_x = floor(grid_x), floor_y = floor(grid_y);
    float ratio_x = grid_x - floor_x, ratio_y = grid_y - floor_y,
          z1 = bed_level[floor_x + half][floor_y + half],
          z2 = bed_level[floor_x + half][floor_y + half + 1],
          z3 = bed_level[floor_x + half + 1][floor_y + half],
          z4 = bed_level[floor_x + half + 1][floor_y + half + 1],
          left = (1 - ratio_y) * z1 + ratio_y * z2,
          right = (1 - ratio_y) * z3 + ratio_y * z4,
          offset = (1 - ratio_x) * left + ratio_x * right;
    delta[X_AXIS] += offset;
    delta[Y_AXIS] += offset;
    delta[Z_AXIS] += offset;
    /*
    SERIAL_ECHOPGM("grid_x="); SERIAL_ECHO(grid_x);
    SERIAL_ECHOPGM(" grid_y="); SERIAL_ECHO(grid_y);
    SERIAL_ECHOPGM(" floor_x="); SERIAL_ECHO(floor_x);
    SERIAL_ECHOPGM(" floor_y="); SERIAL_ECHO(floor_y);
    SERIAL_ECHOPGM(" ratio_x="); SERIAL_ECHO(ratio_x);
    SERIAL_ECHOPGM(" ratio_y="); SERIAL_ECHO(ratio_y);
    SERIAL_ECHOPGM(" z1="); SERIAL_ECHO(z1);
    SERIAL_ECHOPGM(" z2="); SERIAL_ECHO(z2);
    SERIAL_ECHOPGM(" z3="); SERIAL_ECHO(z3);
    SERIAL_ECHOPGM(" z4="); SERIAL_ECHO(z4);
    SERIAL_ECHOPGM(" left="); SERIAL_ECHO(left);
    SERIAL_ECHOPGM(" right="); SERIAL_ECHO(right);
    SERIAL_ECHOPGM(" offset="); SERIAL_ECHOLN(offset);
    */
}
#endif
#if defined (marlin4Due) && ENABLED(DELTA)
    // ENABLE_AUTO_BED_LEVELING
#endif
#if defined (marlin4Due)
    // DELTA
#endif
#if defined (marlin4Due) && ENABLED(MESH_BED_LEVELING)
// This function is used to split lines on mesh borders so each segment is only part of one mesh area
void mesh_plan_buffer_line(float x, float y, float z, const float e, float feed_rate, const uint8_t &extruder, uint8_t x_splits=0xff, uint8_t y_splits=0xff) {
    if (!mbl.active) {
        plan_buffer_line(x, y, z, e, feed_rate, extruder);
        set_current_to_destination();
        return;
    }
    int pix = mbl.select_x_index(current_position[X_AXIS]);
    int piy = mbl.select_y_index(current_position[Y_AXIS]);
    int ix = mbl.select_x_index(x);
    int iy = mbl.select_y_index(y);
    pix = min(pix, MESH_NUM_X_POINTS - 2);
    piy = min(piy, MESH_NUM_Y_POINTS - 2);
    ix = min(ix, MESH_NUM_X_POINTS - 2);
    iy = min(iy, MESH_NUM_Y_POINTS - 2);
    if (pix == ix && piy == iy) {
        // Start and end on same mesh square
        plan_buffer_line(x, y, z, e, feed_rate, extruder);
        set_current_to_destination();
        return;
    }
    float nx, ny, ne, normalized_dist;
    if (ix > pix && (x_splits) & BIT(ix)) {
        nx = mbl.get_x(ix);
        normalized_dist = (nx - current_position[X_AXIS])/(x - current_position[X_AXIS]);
        ny = current_position[Y_AXIS] + (y - current_position[Y_AXIS]) * normalized_dist;
        ne = current_position[E_AXIS] + (e - current_position[E_AXIS]) * normalized_dist;
        x_splits ^= BIT(ix);
    } else if (ix < pix && (x_splits) & BIT(pix)) {
        nx = mbl.get_x(pix);
        normalized_dist = (nx - current_position[X_AXIS])/(x - current_position[X_AXIS]);
        ny = current_position[Y_AXIS] + (y - current_position[Y_AXIS]) * normalized_dist;
        ne = current_position[E_AXIS] + (e - current_position[E_AXIS]) * normalized_dist;
        x_splits ^= BIT(pix);
    } else if (iy > piy && (y_splits) & BIT(iy)) {
        ny = mbl.get_y(iy);
        normalized_dist = (ny - current_position[Y_AXIS])/(y - current_position[Y_AXIS]);
        nx = current_position[X_AXIS] + (x - current_position[X_AXIS]) * normalized_dist;
        ne = current_position[E_AXIS] + (e - current_position[E_AXIS]) * normalized_dist;
        y_splits ^= BIT(iy);
    } else if (iy < piy && (y_splits) & BIT(piy)) {
        ny = mbl.get_y(piy);
        normalized_dist = (ny - current_position[Y_AXIS])/(y - current_position[Y_AXIS]);
        nx = current_position[X_AXIS] + (x - current_position[X_AXIS]) * normalized_dist;
        ne = current_position[E_AXIS] + (e - current_position[E_AXIS]) * normalized_dist;
        y_splits ^= BIT(piy);
    } else {
        // Already split on a border
        plan_buffer_line(x, y, z, e, feed_rate, extruder);
        set_current_to_destination();
        return;
    }
    // Do the split and look for more borders
    destination[X_AXIS] = nx;
    destination[Y_AXIS] = ny;
    destination[E_AXIS] = ne;
    mesh_plan_buffer_line(nx, ny, z, ne, feed_rate, extruder, x_splits, y_splits);
    destination[X_AXIS] = x;
    destination[Y_AXIS] = y;
    destination[E_AXIS] = e;
    mesh_plan_buffer_line(x, y, z, e, feed_rate, extruder, x_splits, y_splits);
}
#endif
#if defined (marlin4Due)
    // MESH_BED_LEVELING
#endif
#if defined (marlin4Due) && ENABLED(PREVENT_DANGEROUS_EXTRUDE)
inline void prevent_dangerous_extrude(float &curr_e, float &dest_e) {
    if (marlin_debug_flags & DEBUG_DRYRUN) return;
    float de = dest_e - curr_e;
    if (de) {
        if (degHotend(active_extruder) < extrude_min_temp) {
            curr_e = dest_e; // Behave as if the move really took place, but ignore E part
            SERIAL_ECHO_START;
            SERIAL_ECHOLNPGM(MSG_ERR_COLD_EXTRUDE_STOP);
        }
#if ENABLED(PREVENT_LENGTHY_EXTRUDE)
        if (labs(de) > EXTRUDE_MAXLENGTH) {
            curr_e = dest_e; // Behave as if the move really took place, but ignore E part
            SERIAL_ECHO_START;
            SERIAL_ECHOLNPGM(MSG_ERR_LONG_EXTRUDE_STOP);
        }
#endif
    }
}
#endif
#if defined (marlin4Due)
    // PREVENT_DANGEROUS_EXTRUDE
#endif
#if defined (marlin4Due) && (ENABLED(DELTA) || ENABLED(SCARA))
inline bool prepare_move_delta(float target[NUM_AXIS]) {
    float difference[NUM_AXIS];
    for (int8_t i=0; i < NUM_AXIS; i++) difference[i] = target[i] - current_position[i];
    float cartesian_mm = sqrt(sq(difference[X_AXIS]) + sq(difference[Y_AXIS]) + sq(difference[Z_AXIS]));
    if (cartesian_mm < 0.000001) cartesian_mm = abs(difference[E_AXIS]);
    if (cartesian_mm < 0.000001) return false;
    float seconds = 6000 * cartesian_mm / feedrate / feedrate_multiplier;
    int steps = max(1, int(delta_segments_per_second * seconds));
    // SERIAL_ECHOPGM("mm="); SERIAL_ECHO(cartesian_mm);
    // SERIAL_ECHOPGM(" seconds="); SERIAL_ECHO(seconds);
    // SERIAL_ECHOPGM(" steps="); SERIAL_ECHOLN(steps);
    for (int s = 1; s <= steps; s++) {
        float fraction = float(s) / float(steps);
        for (int8_t i = 0; i < NUM_AXIS; i++)
            target[i] = current_position[i] + difference[i] * fraction;
        calculate_delta(target);
#if ENABLED(ENABLE_AUTO_BED_LEVELING)
        adjust_delta(target);
#endif
        //SERIAL_ECHOPGM("target[X_AXIS]="); SERIAL_ECHOLN(target[X_AXIS]);
        //SERIAL_ECHOPGM("target[Y_AXIS]="); SERIAL_ECHOLN(target[Y_AXIS]);
        //SERIAL_ECHOPGM("target[Z_AXIS]="); SERIAL_ECHOLN(target[Z_AXIS]);
        //SERIAL_ECHOPGM("delta[X_AXIS]="); SERIAL_ECHOLN(delta[X_AXIS]);
        //SERIAL_ECHOPGM("delta[Y_AXIS]="); SERIAL_ECHOLN(delta[Y_AXIS]);
        //SERIAL_ECHOPGM("delta[Z_AXIS]="); SERIAL_ECHOLN(delta[Z_AXIS]);
        plan_buffer_line(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], target[E_AXIS], feedrate/60*feedrate_multiplier/100.0, active_extruder);
    }
    return true;
}
#endif
#if defined (marlin4Due)
    // DELTA || SCARA
#endif
#if defined (marlin4Due) && ENABLED(SCARA)
inline bool prepare_move_scara(float target[NUM_AXIS]) {
    return prepare_move_delta(target);
}
#endif
#if defined (marlin4Due) && ENABLED(DUAL_X_CARRIAGE)
inline bool prepare_move_dual_x_carriage() {
    if (active_extruder_parked) {
        if (dual_x_carriage_mode == DXC_DUPLICATION_MODE && active_extruder == 0) {
            // move duplicate extruder into correct duplication position.
            plan_set_position(inactive_extruder_x_pos, current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
            plan_buffer_line(current_position[X_AXIS] + duplicate_extruder_x_offset,
                             current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS], max_feedrate[X_AXIS], 1);
            sync_plan_position();
            st_synchronize();
            extruder_duplication_enabled = true;
            active_extruder_parked = false;
        } else if (dual_x_carriage_mode == DXC_AUTO_PARK_MODE) { // handle unparking of head
            if (current_position[E_AXIS] == destination[E_AXIS]) {
                // This is a travel move (with no extrusion)
                // Skip it, but keep track of the current position
                // (so it can be used as the start of the next non-travel move)
                if (delayed_move_time != 0xFFFFFFFFUL) {
                    set_current_to_destination();
                    NOLESS(raised_parked_position[Z_AXIS], destination[Z_AXIS]);
                    delayed_move_time = millis();
                    return false;
                }
            }
            delayed_move_time = 0;
            // unpark extruder: 1) raise, 2) move into starting XY position, 3) lower
            plan_buffer_line(raised_parked_position[X_AXIS], raised_parked_position[Y_AXIS], raised_parked_position[Z_AXIS], current_position[E_AXIS], max_feedrate[Z_AXIS], active_extruder);
            plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], raised_parked_position[Z_AXIS], current_position[E_AXIS], min(max_feedrate[X_AXIS], max_feedrate[Y_AXIS]), active_extruder);
            plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS], max_feedrate[Z_AXIS], active_extruder);
            active_extruder_parked = false;
        }
    }
    return true;
}
#endif
#if defined (marlin4Due)
    // DUAL_X_CARRIAGE
#endif
#if defined (marlin4Due) && (DISABLED(DELTA) && DISABLED(SCARA))
inline bool prepare_move_cartesian() {
    // Do not use feedrate_multiplier for E or Z only moves
    if (current_position[X_AXIS] == destination[X_AXIS] && current_position[Y_AXIS] == destination[Y_AXIS]) {
        line_to_destination();
    } else {
#if ENABLED(MESH_BED_LEVELING)
        mesh_plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], (feedrate/60)*(feedrate_multiplier/100.0), active_extruder);
        return false;
#else
        line_to_destination(feedrate * feedrate_multiplier / 100.0);
#endif
    }
    return true;
}
#endif
#if defined (marlin4Due)
// !DELTA && !SCARA
/**
 * Prepare a single move and get ready for the next one
 *
 * (This may call plan_buffer_line several times to put
 *  smaller moves into the planner for DELTA or SCARA.)
 */
void prepare_move() {
    clamp_to_software_endstops(destination);
    refresh_cmd_timeout();
#if ENABLED(PREVENT_DANGEROUS_EXTRUDE)
    prevent_dangerous_extrude(current_position[E_AXIS], destination[E_AXIS]);
#endif
#if ENABLED(SCARA)
    if (!prepare_move_scara(destination)) return;
#elif ENABLED(DELTA)
    if (!prepare_move_delta(destination)) return;
#endif
#if ENABLED(DUAL_X_CARRIAGE)
    if (!prepare_move_dual_x_carriage()) return;
#endif
#if DISABLED(DELTA) && DISABLED(SCARA)
    if (!prepare_move_cartesian()) return;
#endif
    set_current_to_destination();
}
/**
 * Plan an arc in 2 dimensions
 *
 * The arc is approximated by generating many small linear segments.
 * The length of each segment is configured in MM_PER_ARC_SEGMENT (Default 1mm)
 * Arcs should only be made relatively large (over 5mm), as larger arcs with
 * larger segments will tend to be more efficient. Your slicer should have
 * options for G2/G3 arc generation. In future these options may be GCode tunable.
 */
void plan_arc(
    float target[NUM_AXIS], // Destination position
    float *offset,          // Center of rotation relative to current_position
    uint8_t clockwise       // Clockwise?
) {
    float radius = hypot(offset[X_AXIS], offset[Y_AXIS]),
          center_axis0 = current_position[X_AXIS] + offset[X_AXIS],
          center_axis1 = current_position[Y_AXIS] + offset[Y_AXIS],
          linear_travel = target[Z_AXIS] - current_position[Z_AXIS],
          extruder_travel = target[E_AXIS] - current_position[E_AXIS],
          r_axis0 = -offset[X_AXIS],  // Radius vector from center to current location
          r_axis1 = -offset[Y_AXIS],
          rt_axis0 = target[X_AXIS] - center_axis0,
          rt_axis1 = target[Y_AXIS] - center_axis1;
    // CCW angle of rotation between position and target from the circle center. Only one atan2() trig computation required.
    float angular_travel = atan2(r_axis0*rt_axis1-r_axis1*rt_axis0, r_axis0*rt_axis0+r_axis1*rt_axis1);
    if (angular_travel < 0) {
        angular_travel += RADIANS(360);
    }
    if (clockwise) {
        angular_travel -= RADIANS(360);
    }
    // Make a circle if the angular rotation is 0
    if (current_position[X_AXIS] == target[X_AXIS] && current_position[Y_AXIS] == target[Y_AXIS] && angular_travel == 0)
        angular_travel += RADIANS(360);
    float mm_of_travel = hypot(angular_travel*radius, fabs(linear_travel));
    if (mm_of_travel < 0.001) {
        return;
    }
    uint16_t segments = floor(mm_of_travel / MM_PER_ARC_SEGMENT);
    if (segments == 0) segments = 1;
    float theta_per_segment = angular_travel/segments;
    float linear_per_segment = linear_travel/segments;
    float extruder_per_segment = extruder_travel/segments;
    /* Vector rotation by transformation matrix: r is the original vector, r_T is the rotated vector,
       and phi is the angle of rotation. Based on the solution approach by Jens Geisler.
           r_T = [cos(phi) -sin(phi);
                  sin(phi)  cos(phi] * r ;

       For arc generation, the center of the circle is the axis of rotation and the radius vector is
       defined from the circle center to the initial position. Each line segment is formed by successive
       vector rotations. This requires only two cos() and sin() computations to form the rotation
       matrix for the duration of the entire arc. Error may accumulate from numerical round-off, since
       all double numbers are single precision on the Arduino. (True double precision will not have
       round off issues for CNC applications.) Single precision error can accumulate to be greater than
       tool precision in some cases. Therefore, arc path correction is implemented.

       Small angle approximation may be used to reduce computation overhead further. This approximation
       holds for everything, but very small circles and large MM_PER_ARC_SEGMENT values. In other words,
       theta_per_segment would need to be greater than 0.1 rad and N_ARC_CORRECTION would need to be large
       to cause an appreciable drift error. N_ARC_CORRECTION~=25 is more than small enough to correct for
       numerical drift error. N_ARC_CORRECTION may be on the order a hundred(s) before error becomes an
       issue for CNC machines with the single precision Arduino calculations.

       This approximation also allows plan_arc to immediately insert a line segment into the planner
       without the initial overhead of computing cos() or sin(). By the time the arc needs to be applied
       a correction, the planner should have caught up to the lag caused by the initial plan_arc overhead.
       This is important when there are successive arc motions.
    */
    // Vector rotation matrix values
    float cos_T = 1-0.5*theta_per_segment*theta_per_segment; // Small angle approximation
    float sin_T = theta_per_segment;
    float arc_target[NUM_AXIS];
    float sin_Ti;
    float cos_Ti;
    float r_axisi;
    uint16_t i;
    int8_t count = 0;
    // Initialize the linear axis
    arc_target[Z_AXIS] = current_position[Z_AXIS];
    // Initialize the extruder axis
    arc_target[E_AXIS] = current_position[E_AXIS];
    float feed_rate = feedrate*feedrate_multiplier/60/100.0;
    for (i = 1; i < segments; i++) { // Increment (segments-1)
        if (count < N_ARC_CORRECTION) {
            // Apply vector rotation matrix to previous r_axis0 / 1
            r_axisi = r_axis0*sin_T + r_axis1*cos_T;
            r_axis0 = r_axis0*cos_T - r_axis1*sin_T;
            r_axis1 = r_axisi;
            count++;
        } else {
            // Arc correction to radius vector. Computed only every N_ARC_CORRECTION increments.
            // Compute exact location by applying transformation matrix from initial radius vector(=-offset).
            cos_Ti = cos(i*theta_per_segment);
            sin_Ti = sin(i*theta_per_segment);
            r_axis0 = -offset[X_AXIS]*cos_Ti + offset[Y_AXIS]*sin_Ti;
            r_axis1 = -offset[X_AXIS]*sin_Ti - offset[Y_AXIS]*cos_Ti;
            count = 0;
        }
        // Update arc_target location
        arc_target[X_AXIS] = center_axis0 + r_axis0;
        arc_target[Y_AXIS] = center_axis1 + r_axis1;
        arc_target[Z_AXIS] += linear_per_segment;
        arc_target[E_AXIS] += extruder_per_segment;
        clamp_to_software_endstops(arc_target);
#if defined(DELTA) || defined(SCARA)
        calculate_delta(arc_target);
#ifdef ENABLE_AUTO_BED_LEVELING
        adjust_delta(arc_target);
#endif
        plan_buffer_line(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], arc_target[E_AXIS], feed_rate, active_extruder);
#else
        plan_buffer_line(arc_target[X_AXIS], arc_target[Y_AXIS], arc_target[Z_AXIS], arc_target[E_AXIS], feed_rate, active_extruder);
#endif
    }
    // Ensure last segment arrives at target location.
#if defined(DELTA) || defined(SCARA)
    calculate_delta(target);
#ifdef ENABLE_AUTO_BED_LEVELING
    adjust_delta(target);
#endif
    plan_buffer_line(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], target[E_AXIS], feed_rate, active_extruder);
#else
    plan_buffer_line(target[X_AXIS], target[Y_AXIS], target[Z_AXIS], target[E_AXIS], feed_rate, active_extruder);
#endif
    // As far as the parser is concerned, the position is now == target. In reality the
    // motion control system might still be processing the action and the real tool position
    // in any intermediate location.
    set_current_to_destination();
}
#endif
#if defined (marlin4Due) && HAS_CONTROLLERFAN
void controllerFan() {
    static millis_t lastMotor = 0;      // Last time a motor was turned on
    static millis_t lastMotorCheck = 0; // Last time the state was checked
    millis_t ms = millis();
    if (ms >= lastMotorCheck + 2500) { // Not a time critical function, so we only check every 2500ms
        lastMotorCheck = ms;
        if (X_ENABLE_READ == X_ENABLE_ON || Y_ENABLE_READ == Y_ENABLE_ON || Z_ENABLE_READ == Z_ENABLE_ON || soft_pwm_bed > 0
                || E0_ENABLE_READ == E_ENABLE_ON // If any of the drivers are enabled...
#if EXTRUDERS > 1
                || E1_ENABLE_READ == E_ENABLE_ON
#if HAS_X2_ENABLE
                || X2_ENABLE_READ == X_ENABLE_ON
#endif
#if EXTRUDERS > 2
                || E2_ENABLE_READ == E_ENABLE_ON
#if EXTRUDERS > 3
                || E3_ENABLE_READ == E_ENABLE_ON
#endif
#endif
#endif
           ) {
            lastMotor = ms; //... set time to NOW so the fan will turn on
        }
        // Dawson - try to get the motor/controller card fan control working with RAMPS-FD v1
        // #ifdef INVERTED_HEATER_PINS
#ifdef INVERTED_MOSFET_CHANNELS
        uint8_t speed = (lastMotor == 0 || ms >= lastMotor + (CONTROLLERFAN_SECS * 1000UL)) ? 255 : (255 - CONTROLLERFAN_SPEED);
#else
        uint8_t speed = (lastMotor == 0 || ms >= lastMotor + (CONTROLLERFAN_SECS * 1000UL)) ? 0 : CONTROLLERFAN_SPEED;
#endif
        // allows digital or PWM fan output to be used (see M42 handling)
        digitalWrite(CONTROLLERFAN_PIN, speed);
        analogWrite(CONTROLLERFAN_PIN, speed);
    }
}
#endif
#if defined (marlin4Due)
    // HAS_CONTROLLERFAN
#endif
#if defined (marlin4Due) && ENABLED(SCARA)
void calculate_SCARA_forward_Transform(float f_scara[3]) {
    // Perform forward kinematics, and place results in delta[3]
    // The maths and first version has been done by QHARLEY . Integrated into masterbranch 06/2014 and slightly restructured by Joachim Cerny in June 2014
    float x_sin, x_cos, y_sin, y_cos;
    //SERIAL_ECHOPGM("f_delta x="); SERIAL_ECHO(f_scara[X_AXIS]);
    //SERIAL_ECHOPGM(" y="); SERIAL_ECHO(f_scara[Y_AXIS]);
    x_sin = sin(f_scara[X_AXIS]/SCARA_RAD2DEG) * Linkage_1;
    x_cos = cos(f_scara[X_AXIS]/SCARA_RAD2DEG) * Linkage_1;
    y_sin = sin(f_scara[Y_AXIS]/SCARA_RAD2DEG) * Linkage_2;
    y_cos = cos(f_scara[Y_AXIS]/SCARA_RAD2DEG) * Linkage_2;
    //SERIAL_ECHOPGM(" x_sin="); SERIAL_ECHO(x_sin);
    //SERIAL_ECHOPGM(" x_cos="); SERIAL_ECHO(x_cos);
    //SERIAL_ECHOPGM(" y_sin="); SERIAL_ECHO(y_sin);
    //SERIAL_ECHOPGM(" y_cos="); SERIAL_ECHOLN(y_cos);
    delta[X_AXIS] = x_cos + y_cos + SCARA_offset_x;  //theta
    delta[Y_AXIS] = x_sin + y_sin + SCARA_offset_y;  //theta+phi
    //SERIAL_ECHOPGM(" delta[X_AXIS]="); SERIAL_ECHO(delta[X_AXIS]);
    //SERIAL_ECHOPGM(" delta[Y_AXIS]="); SERIAL_ECHOLN(delta[Y_AXIS]);
}
void calculate_delta(float cartesian[3]) {
    //reverse kinematics.
    // Perform reversed kinematics, and place results in delta[3]
    // The maths and first version has been done by QHARLEY . Integrated into masterbranch 06/2014 and slightly restructured by Joachim Cerny in June 2014
    float SCARA_pos[2];
    static float SCARA_C2, SCARA_S2, SCARA_K1, SCARA_K2, SCARA_theta, SCARA_psi;
    SCARA_pos[X_AXIS] = cartesian[X_AXIS] * axis_scaling[X_AXIS] - SCARA_offset_x;  //Translate SCARA to standard X Y
    SCARA_pos[Y_AXIS] = cartesian[Y_AXIS] * axis_scaling[Y_AXIS] - SCARA_offset_y;  // With scaling factor.
#if (Linkage_1 == Linkage_2)
    SCARA_C2 = ( ( sq(SCARA_pos[X_AXIS]) + sq(SCARA_pos[Y_AXIS]) ) / (2 * (float)L1_2) ) - 1;
#else
    SCARA_C2 =   ( sq(SCARA_pos[X_AXIS]) + sq(SCARA_pos[Y_AXIS]) - (float)L1_2 - (float)L2_2 ) / 45000;
#endif
    SCARA_S2 = sqrt( 1 - sq(SCARA_C2) );
    SCARA_K1 = Linkage_1 + Linkage_2 * SCARA_C2;
    SCARA_K2 = Linkage_2 * SCARA_S2;
    SCARA_theta = ( atan2(SCARA_pos[X_AXIS],SCARA_pos[Y_AXIS])-atan2(SCARA_K1, SCARA_K2) ) * -1;
    SCARA_psi   =   atan2(SCARA_S2,SCARA_C2);
    delta[X_AXIS] = SCARA_theta * SCARA_RAD2DEG;  // Multiply by 180/Pi  -  theta is support arm angle
    delta[Y_AXIS] = (SCARA_theta + SCARA_psi) * SCARA_RAD2DEG;  //       -  equal to sub arm angle (inverted motor)
    delta[Z_AXIS] = cartesian[Z_AXIS];
    /*
    SERIAL_ECHOPGM("cartesian x="); SERIAL_ECHO(cartesian[X_AXIS]);
    SERIAL_ECHOPGM(" y="); SERIAL_ECHO(cartesian[Y_AXIS]);
    SERIAL_ECHOPGM(" z="); SERIAL_ECHOLN(cartesian[Z_AXIS]);

    SERIAL_ECHOPGM("scara x="); SERIAL_ECHO(SCARA_pos[X_AXIS]);
    SERIAL_ECHOPGM(" y="); SERIAL_ECHOLN(SCARA_pos[Y_AXIS]);

    SERIAL_ECHOPGM("delta x="); SERIAL_ECHO(delta[X_AXIS]);
    SERIAL_ECHOPGM(" y="); SERIAL_ECHO(delta[Y_AXIS]);
    SERIAL_ECHOPGM(" z="); SERIAL_ECHOLN(delta[Z_AXIS]);

    SERIAL_ECHOPGM("C2="); SERIAL_ECHO(SCARA_C2);
    SERIAL_ECHOPGM(" S2="); SERIAL_ECHO(SCARA_S2);
    SERIAL_ECHOPGM(" Theta="); SERIAL_ECHO(SCARA_theta);
    SERIAL_ECHOPGM(" Psi="); SERIAL_ECHOLN(SCARA_psi);
    SERIAL_EOL;
    */
}
#endif
#if defined (marlin4Due)
    // SCARA
#endif
#if defined (marlin4Due) && ENABLED(TEMP_STAT_LEDS)
static bool red_led = false;
static millis_t next_status_led_update_ms = 0;
void handle_status_leds(void) {
    float max_temp = 0.0;
    if (millis() > next_status_led_update_ms) {
        next_status_led_update_ms += 500; // Update every 0.5s
        for (int8_t cur_extruder = 0; cur_extruder < EXTRUDERS; ++cur_extruder)
            max_temp = max(max(max_temp, degHotend(cur_extruder)), degTargetHotend(cur_extruder));
#if HAS_TEMP_BED
        max_temp = max(max(max_temp, degTargetBed()), degBed());
#endif
        bool new_led = (max_temp > 55.0) ? true : (max_temp < 54.0) ? false : red_led;
        if (new_led != red_led) {
            red_led = new_led;
            digitalWrite(STAT_LED_RED, new_led ? HIGH : LOW);
            digitalWrite(STAT_LED_BLUE, new_led ? LOW : HIGH);
        }
    }
}
#endif
#if defined (marlin4Due)
void enable_all_steppers() {
    enable_x();
    enable_y();
    enable_z();
    enable_e0();
    enable_e1();
    enable_e2();
    enable_e3();
}
void disable_all_steppers() {
    disable_x();
    disable_y();
    disable_z();
    disable_e0();
    disable_e1();
    disable_e2();
    disable_e3();
}
/**
 * Standard idle routine keeps the machine alive
 */
void idle() {
    manage_heater();
    manage_inactivity();
    lcd_update();
    get_fsr_value();
}
/**
 * Manage several activities:
 *  - Check for Filament Runout
 *  - Keep the command buffer full
 *  - Check for maximum inactive time between commands
 *  - Check for maximum inactive time between stepper commands
 *  - Check if pin CHDK needs to go LOW
 *  - Check for KILL button held down
 *  - Check for HOME button held down
 *  - Check if cooling fan needs to be switched on
 *  - Check if an idle but hot extruder needs filament extruded (EXTRUDER_RUNOUT_PREVENT)
 */
void manage_inactivity(bool ignore_stepper_queue/*=false*/) {
#if HAS_FILRUNOUT
    if (IS_SD_PRINTING && !(READ(FILRUNOUT_PIN) ^ FIL_RUNOUT_INVERTING))
        filrunout();
#endif
    if (commands_in_queue < BUFSIZE - 1) get_command();
    millis_t ms = millis();
    if (max_inactive_time && ms > previous_cmd_ms + max_inactive_time) kill(PSTR(MSG_KILLED));
    if (stepper_inactive_time && ms > previous_cmd_ms + stepper_inactive_time
            && !ignore_stepper_queue && !blocks_queued()) {
#if DISABLE_X == true
        disable_x();
#endif
#if DISABLE_Y == true
        disable_y();
#endif
#if DISABLE_Z == true
        disable_z();
#endif
#if DISABLE_E == true
        disable_e0();
        disable_e1();
        disable_e2();
        disable_e3();
#endif
    }
#ifdef CHDK // Check if pin should be set to LOW after M240 set it to HIGH
    if (chdkActive && ms > chdkHigh + CHDK_DELAY) {
        chdkActive = false;
        WRITE(CHDK, LOW);
    }
#endif
#if HAS_KILL
    // Check if the kill button was pressed and wait just in case it was an accidental
    // key kill key press
    // -------------------------------------------------------------------------------
    static int killCount = 0;   // make the inactivity button a bit less responsive
    const int KILL_DELAY = 750;
    if (!READ(KILL_PIN))
        killCount++;
    else if (killCount > 0)
        killCount--;
    // Exceeded threshold and we can confirm that it was not accidental
    // KILL the machine
    // ----------------------------------------------------------------
    if (killCount >= KILL_DELAY) kill(PSTR(MSG_KILLED));
#endif
#if HAS_HOME
    // Check to see if we have to home, use poor man's debouncer
    // ---------------------------------------------------------
    static int homeDebounceCount = 0;   // poor man's debouncing count
    const int HOME_DEBOUNCE_DELAY = 750;
    if (!READ(HOME_PIN)) {
        if (!homeDebounceCount) {
            enqueuecommands_P(PSTR("G28"));
            LCD_MESSAGEPGM(MSG_AUTO_HOME);
        }
        if (homeDebounceCount < HOME_DEBOUNCE_DELAY)
            homeDebounceCount++;
        else
            homeDebounceCount = 0;
    }
#endif
#if HAS_CONTROLLERFAN
    controllerFan(); // Check if fan should be turned on to cool stepper drivers down
#endif
#if ENABLED(EXTRUDER_RUNOUT_PREVENT)
    if (ms > previous_cmd_ms + EXTRUDER_RUNOUT_SECONDS * 1000)
        if (degHotend(active_extruder) > EXTRUDER_RUNOUT_MINTEMP) {
            bool oldstatus;
            switch(active_extruder) {
            case 0:
                oldstatus = E0_ENABLE_READ;
                enable_e0();
                break;
#if EXTRUDERS > 1
            case 1:
                oldstatus = E1_ENABLE_READ;
                enable_e1();
                break;
#if EXTRUDERS > 2
            case 2:
                oldstatus = E2_ENABLE_READ;
                enable_e2();
                break;
#if EXTRUDERS > 3
            case 3:
                oldstatus = E3_ENABLE_READ;
                enable_e3();
                break;
#endif
#endif
#endif
            }
            float oldepos = current_position[E_AXIS], oldedes = destination[E_AXIS];
            plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS],
                             destination[E_AXIS] + EXTRUDER_RUNOUT_EXTRUDE * EXTRUDER_RUNOUT_ESTEPS / axis_steps_per_unit[E_AXIS],
                             EXTRUDER_RUNOUT_SPEED / 60. * EXTRUDER_RUNOUT_ESTEPS / axis_steps_per_unit[E_AXIS], active_extruder);
            current_position[E_AXIS] = oldepos;
            destination[E_AXIS] = oldedes;
            plan_set_e_position(oldepos);
            previous_cmd_ms = ms; // refresh_cmd_timeout()
            st_synchronize();
            switch(active_extruder) {
            case 0:
                E0_ENABLE_WRITE(oldstatus);
                break;
#if EXTRUDERS > 1
            case 1:
                E1_ENABLE_WRITE(oldstatus);
                break;
#if EXTRUDERS > 2
            case 2:
                E2_ENABLE_WRITE(oldstatus);
                break;
#if EXTRUDERS > 3
            case 3:
                E3_ENABLE_WRITE(oldstatus);
                break;
#endif
#endif
#endif
            }
        }
#endif
#if ENABLED(DUAL_X_CARRIAGE)
    // handle delayed move timeout
    if (delayed_move_time && ms > delayed_move_time + 1000 && IsRunning()) {
        // travel moves have been received so enact them
        delayed_move_time = 0xFFFFFFFFUL; // force moves to be done
        set_destination_to_current();
        prepare_move();
    }
#endif
#if ENABLED(TEMP_STAT_LEDS)
    handle_status_leds();
#endif
    check_axes_activity();
}
void kill(const char *lcd_msg) {
#if ENABLED(ULTRA_LCD)
    lcd_setalertstatuspgm(lcd_msg);
#endif
    cli(); // Stop interrupts
    disable_all_heaters();
    disable_all_steppers();
#if HAS_POWER_SWITCH
    pinMode(PS_ON_PIN, INPUT);
#endif
    SERIAL_ERROR_START;
    SERIAL_ERRORLNPGM(MSG_ERR_KILLED);
    // FMC small patch to update the LCD before ending
    sei();   // enable interrupts
    for (int i = 5; i--; lcd_update()) delay(200); // Wait a short time
    cli();   // disable interrupts
    suicide();
    while(1) {
        /* Intentionally left empty */
    } // Wait for reset
}
#endif
#if defined (marlin4Due) && ENABLED(FILAMENT_RUNOUT_SENSOR)
void filrunout() {
    if (!filrunoutEnqueued) {
        filrunoutEnqueued = true;
        enqueuecommands_P(PSTR(FILAMENT_RUNOUT_SCRIPT));
        st_synchronize();
    }
}
#endif
#if defined (marlin4Due)
    // FILAMENT_RUNOUT_SENSOR
#endif
#if defined (marlin4Due) && ENABLED(FAST_PWM_FAN)
void setPwmFrequency(uint8_t pin, int val) {
    val &= 0x07;
    switch (digitalPinToTimer(pin)) {
#if defined(TCCR0A)
    case TIMER0A:
    case TIMER0B:
        // TCCR0B &= ~(_BV(CS00) | _BV(CS01) | _BV(CS02));
        // TCCR0B |= val;
        break;
#endif
#if defined(TCCR1A)
    case TIMER1A:
    case TIMER1B:
        // TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));
        // TCCR1B |= val;
        break;
#endif
#if defined(TCCR2)
    case TIMER2:
    case TIMER2:
        TCCR2 &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));
        TCCR2 |= val;
        break;
#endif
#if defined(TCCR2A)
    case TIMER2A:
    case TIMER2B:
        TCCR2B &= ~(_BV(CS20) | _BV(CS21) | _BV(CS22));
        TCCR2B |= val;
        break;
#endif
#if defined(TCCR3A)
    case TIMER3A:
    case TIMER3B:
    case TIMER3C:
        TCCR3B &= ~(_BV(CS30) | _BV(CS31) | _BV(CS32));
        TCCR3B |= val;
        break;
#endif
#if defined(TCCR4A)
    case TIMER4A:
    case TIMER4B:
    case TIMER4C:
        TCCR4B &= ~(_BV(CS40) | _BV(CS41) | _BV(CS42));
        TCCR4B |= val;
        break;
#endif
#if defined(TCCR5A)
    case TIMER5A:
    case TIMER5B:
    case TIMER5C:
        TCCR5B &= ~(_BV(CS50) | _BV(CS51) | _BV(CS52));
        TCCR5B |= val;
        break;
#endif
    }
}
#endif
#if defined (marlin4Due)
// FAST_PWM_FAN
void Stop() {
    disable_all_heaters();
    if (IsRunning()) {
        Running = false;
        Stopped_gcode_LastN = gcode_LastN; // Save last g_code for restart
        SERIAL_ERROR_START;
        SERIAL_ERRORLNPGM(MSG_ERR_STOPPED);
        LCD_MESSAGEPGM(MSG_STOPPED);
    }
}
/**
 * Set target_extruder from the T parameter or the active_extruder
 *
 * Returns TRUE if the target is invalid
 */
bool setTargetedHotend(int code) {
    target_extruder = active_extruder;
    if (code_seen('T')) {
        target_extruder = code_value_short();
        if (target_extruder >= EXTRUDERS) {
            SERIAL_ECHO_START;
            SERIAL_CHAR('M');
            SERIAL_ECHO(code);
            SERIAL_ECHOPGM(" " MSG_INVALID_EXTRUDER " ");
            SERIAL_ECHOLN(target_extruder);
            return true;
        }
    }
    return false;
}
float calculate_volumetric_multiplier(float diameter) {
    if (!volumetric_enabled || diameter == 0) return 1.0;
    float d2 = diameter * 0.5;
    return 1.0 / (M_PI * d2 * d2);
}
void calculate_volumetric_multipliers() {
    for (int i=0; i<EXTRUDERS; i++)
        volumetric_multiplier[i] = calculate_volumetric_multiplier(filament_size[i]);
}
#endif

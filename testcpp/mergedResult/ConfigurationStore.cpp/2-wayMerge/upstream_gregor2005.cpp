#if defined (upstream) || defined (gregor2005)
#include "Marlin.h"
#include "planner.h"
#include "temperature.h"
#include "ultralcd.h"
#include "ConfigurationStore.h"
void _EEPROM_writeData
(int &pos, uint8_t* value, uint8_t size) {
    do {
        eeprom_write_byte((unsigned char*)pos, *value);
        pos++;
        value++;
    } while (--size);
}
#define EEPROM_WRITE_VAR(pos, value) _EEPROM_writeData(pos, (uint8_t*)&value, sizeof(value))
void _EEPROM_readData
(int &pos, uint8_t* value, uint8_t size) {
    do {
        *value = eeprom_read_byte((unsigned char*)pos);
        pos++;
        value++;
    } while (--size);
}
#define EEPROM_READ_VAR(pos, value) _EEPROM_readData(pos, (uint8_t*)&value, sizeof(value))
//======================================================================================
#define EEPROM_OFFSET 100
// IMPORTANT:  Whenever there are changes made to the variables stored in EEPROM
// in the functions below, also increment the version number. This makes sure that
// the default values are used whenever there is a change to the data, to prevent
// wrong data being written to the variables.
// ALSO:  always make sure the variables in the Store and retrieve sections are in the same order.
#endif
#if defined (upstream)
    #define EEPROM_VERSION "V13"
#endif
#if defined (gregor2005)
    #define EEPROM_VERSION "V07"
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (gregor2005) && defined (EEPROM_SETTINGS)
void Config_StoreSettings
() {
    char ver[4]= "000";
    int i=EEPROM_OFFSET;
    EEPROM_WRITE_VAR(i,ver);
// invalidate data first
    EEPROM_WRITE_VAR(i,axis_steps_per_unit);
    EEPROM_WRITE_VAR(i,max_feedrate);
    EEPROM_WRITE_VAR(i,max_acceleration_units_per_sq_second);
    EEPROM_WRITE_VAR(i,acceleration);
    EEPROM_WRITE_VAR(i,retract_acceleration);
    EEPROM_WRITE_VAR(i,minimumfeedrate);
    EEPROM_WRITE_VAR(i,mintravelfeedrate);
    EEPROM_WRITE_VAR(i,minsegmenttime);
    EEPROM_WRITE_VAR(i,max_xy_jerk);
    EEPROM_WRITE_VAR(i,max_z_jerk);
    EEPROM_WRITE_VAR(i,max_e_jerk);
#if defined (upstream) && defined (EEPROM_SETTINGS)
    EEPROM_WRITE_VAR(i,add_homing);
#endif
#if defined (gregor2005) && defined (EEPROM_SETTINGS)
    EEPROM_WRITE_VAR(i,add_homeing);
#endif
#if defined (upstream) && (defined (DELTA) && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i,endstop_adj);
    EEPROM_WRITE_VAR(i,delta_radius);
    EEPROM_WRITE_VAR(i,delta_diagonal_rod);
    EEPROM_WRITE_VAR(i,delta_segments_per_second);
#endif
#if defined (upstream) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (gregor2005) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) )
    int plaPreheatHotendTemp = PLA_PREHEAT_HOTEND_TEMP, plaPreheatHPBTemp = PLA_PREHEAT_HPB_TEMP, plaPreheatFanSpeed = PLA_PREHEAT_FAN_SPEED;
    int absPreheatHotendTemp = ABS_PREHEAT_HOTEND_TEMP, absPreheatHPBTemp = ABS_PREHEAT_HPB_TEMP, absPreheatFanSpeed = ABS_PREHEAT_FAN_SPEED;
#endif
    EEPROM_WRITE_VAR(i,plaPreheatHotendTemp);
    EEPROM_WRITE_VAR(i,plaPreheatHPBTemp);
    EEPROM_WRITE_VAR(i,plaPreheatFanSpeed);
    EEPROM_WRITE_VAR(i,absPreheatHotendTemp);
    EEPROM_WRITE_VAR(i,absPreheatHPBTemp);
    EEPROM_WRITE_VAR(i,absPreheatFanSpeed);
#if defined (upstream) && defined (EEPROM_SETTINGS)
    EEPROM_WRITE_VAR(i,zprobe_zoffset);
#endif
#if defined (upstream) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (gregor2005) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i,Kp);
    EEPROM_WRITE_VAR(i,Ki);
    EEPROM_WRITE_VAR(i,Kd);
#endif
#if defined (upstream) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (gregor2005) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) )
    float dummy = 3000.0f;
    EEPROM_WRITE_VAR(i,dummy);
    dummy = 0.0f;
    EEPROM_WRITE_VAR(i,dummy);
    EEPROM_WRITE_VAR(i,dummy);
#endif
#if defined (upstream) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) )
    int lcd_contrast = 32;
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS)
    EEPROM_WRITE_VAR(i,lcd_contrast);
#endif
#if defined (upstream) && (defined (SCARA) && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i,axis_scaling);
// Add scaling for SCARA
#endif
#if defined (upstream) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
    EEPROM_WRITE_VAR(i,autoretract_enabled);
    EEPROM_WRITE_VAR(i,retract_length);
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
    EEPROM_WRITE_VAR(i,retract_length_swap);
#endif
#if defined (upstream) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
    EEPROM_WRITE_VAR(i,retract_feedrate);
    EEPROM_WRITE_VAR(i,retract_zlift);
    EEPROM_WRITE_VAR(i,retract_recover_length);
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
    EEPROM_WRITE_VAR(i,retract_recover_length_swap);
#endif
#if defined (upstream) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
    EEPROM_WRITE_VAR(i,retract_recover_feedrate);
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS)
// Save filament sizes
    EEPROM_WRITE_VAR(i, volumetric_enabled);
    EEPROM_WRITE_VAR(i, filament_size[0]);
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i, filament_size[1]);
#endif
#if defined (upstream) && (EXTRUDERS > 2 && EXTRUDERS > 1 && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i, filament_size[2]);
#endif
    char ver2[4]=EEPROM_VERSION;
    i=EEPROM_OFFSET;
    EEPROM_WRITE_VAR(i,ver2);
// validate data
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Settings Stored");
}
#endif
#if defined (upstream) || defined (gregor2005)
    //EEPROM_SETTINGS
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (gregor2005) && defined (EEPROM_CHITCHAT)
void Config_PrintSettings
() {
// Always have this function, even with EEPROM_SETTINGS disabled, the current values will be shown
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Steps per unit:");
#if defined (upstream) && !defined (DISABLE_M503)
    SERIAL_ECHO_START;
    SERIAL_ECHOPAIR("  M92 X",axis_steps_per_unit[X_AXIS]);
    SERIAL_ECHOPAIR(" Y",axis_steps_per_unit[Y_AXIS]);
    SERIAL_ECHOPAIR(" Z",axis_steps_per_unit[Z_AXIS]);
    SERIAL_ECHOPAIR(" E",axis_steps_per_unit[E_AXIS]);
    SERIAL_ECHOLN("");
#endif
    SERIAL_ECHO_START;
#if defined (upstream) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHOLNPGM("Scaling factors:");
#endif
#if defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOPAIR("  M92 X",axis_steps_per_unit[0]);
#endif
#if defined (upstream) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHO_START;
#endif
#if defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOPAIR(" Y",axis_steps_per_unit[1]);
#endif
#if defined (upstream) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR("  M365 X",axis_scaling[X_AXIS]);
#endif
#if defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOPAIR(" Z",axis_steps_per_unit[2]);
#endif
#if defined (upstream) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" Y",axis_scaling[Y_AXIS]);
#endif
#if defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOPAIR(" E",axis_steps_per_unit[3]);
#endif
#if defined (upstream) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" Z",axis_scaling[Z_AXIS]);
#endif
#if defined (upstream) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
#endif
    SERIAL_ECHOLNPGM("Maximum feedrates (mm/s):");
    SERIAL_ECHO_START;
#if defined (upstream) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR("  M203 X", max_feedrate[X_AXIS]);
#endif
#if defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOPAIR("  M203 X",max_feedrate[0]);
#endif
#if defined (upstream) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Y", max_feedrate[Y_AXIS]);
#endif
#if defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOPAIR(" Y",max_feedrate[1] );
#endif
#if defined (upstream) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Z", max_feedrate[Z_AXIS]);
#endif
#if defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOPAIR(" Z", max_feedrate[2] );
#endif
#if defined (upstream) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" E", max_feedrate[E_AXIS]);
#endif
#if defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOPAIR(" E", max_feedrate[3]);
#endif
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Maximum Acceleration (mm/s2):");
    SERIAL_ECHO_START;
#if defined (upstream) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR("  M201 X" ,max_acceleration_units_per_sq_second[X_AXIS] );
#endif
#if defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOPAIR("  M201 X" ,max_acceleration_units_per_sq_second[0] );
#endif
#if defined (upstream) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Y" , max_acceleration_units_per_sq_second[Y_AXIS] );
#endif
#if defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOPAIR(" Y" , max_acceleration_units_per_sq_second[1] );
#endif
#if defined (upstream) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Z" ,max_acceleration_units_per_sq_second[Z_AXIS] );
#endif
#if defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOPAIR(" Z" ,max_acceleration_units_per_sq_second[2] );
#endif
#if defined (upstream) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" E" ,max_acceleration_units_per_sq_second[E_AXIS]);
#endif
#if defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOPAIR(" E" ,max_acceleration_units_per_sq_second[3]);
#endif
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Acceleration: S=acceleration, T=retract acceleration");
    SERIAL_ECHO_START;
    SERIAL_ECHOPAIR("  M204 S",acceleration );
    SERIAL_ECHOPAIR(" T" ,retract_acceleration);
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Advanced variables: S=Min feedrate (mm/s), T=Min travel feedrate (mm/s), B=minimum segment time (ms), X=maximum XY jerk (mm/s),  Z=maximum Z jerk (mm/s),  E=maximum E jerk (mm/s)");
    SERIAL_ECHO_START;
    SERIAL_ECHOPAIR("  M205 S",minimumfeedrate );
    SERIAL_ECHOPAIR(" T" ,mintravelfeedrate );
    SERIAL_ECHOPAIR(" B" ,minsegmenttime );
    SERIAL_ECHOPAIR(" X" ,max_xy_jerk );
    SERIAL_ECHOPAIR(" Z" ,max_z_jerk);
    SERIAL_ECHOPAIR(" E" ,max_e_jerk);
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Home offset (mm):");
#if defined (upstream) && !defined (DISABLE_M503)
    SERIAL_ECHO_START;
    SERIAL_ECHOPAIR("  M206 X",add_homing[X_AXIS] );
    SERIAL_ECHOPAIR(" Y" ,add_homing[Y_AXIS] );
    SERIAL_ECHOPAIR(" Z" ,add_homing[Z_AXIS] );
    SERIAL_ECHOLN("");
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Endstop adjustement (mm):");
    SERIAL_ECHO_START;
    SERIAL_ECHOPAIR("  M666 X",endstop_adj[X_AXIS] );
    SERIAL_ECHOPAIR(" Y" ,endstop_adj[Y_AXIS] );
    SERIAL_ECHOPAIR(" Z" ,endstop_adj[Z_AXIS] );
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Delta settings: L=delta_diagonal_rod, R=delta_radius, S=delta_segments_per_second");
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHO_START;
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR("  M665 L",delta_diagonal_rod );
#endif
#if defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOPAIR("  M206 X",add_homeing[0] );
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" R" ,delta_radius );
#endif
#if defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOPAIR(" Y" ,add_homeing[1] );
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" S" ,delta_segments_per_second );
#endif
#if defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOPAIR(" Z" ,add_homeing[2] );
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (gregor2005) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOLN("");
#endif
#if defined (upstream) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (gregor2005) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) )
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("PID settings:");
    SERIAL_ECHO_START;
    SERIAL_ECHOPAIR("   M301 P",Kp);
    SERIAL_ECHOPAIR(" I" ,unscalePID_i(Ki));
    SERIAL_ECHOPAIR(" D" ,unscalePID_d(Kd));
#endif
#if defined (upstream) && (defined (PIDTEMP) && !defined (DISABLE_M503) )
    SERIAL_ECHOLN("");
#endif
#if defined (upstream) && (!defined (DISABLE_M503) && defined (FWRETRACT) )
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Retract: S=Length (mm) F:Speed (mm/m) Z: ZLift (mm)");
    SERIAL_ECHO_START;
    SERIAL_ECHOPAIR("   M207 S",retract_length);
    SERIAL_ECHOPAIR(" F" ,retract_feedrate*60);
    SERIAL_ECHOPAIR(" Z" ,retract_zlift);
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Recover: S=Extra length (mm) F:Speed (mm/m)");
    SERIAL_ECHO_START;
    SERIAL_ECHOPAIR("   M208 S",retract_recover_length);
    SERIAL_ECHOPAIR(" F", retract_recover_feedrate*60);
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Auto-Retract: S=0 to disable, 1 to interpret extrude-only moves as retracts or recoveries");
    SERIAL_ECHO_START;
    SERIAL_ECHOPAIR("   M209 S", (unsigned long)(autoretract_enabled ? 1 : 0));
    SERIAL_ECHOLN("");
#endif
#if defined (upstream) && (EXTRUDERS > 1 && !defined (DISABLE_M503) && defined (FWRETRACT) )
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Multi-extruder settings:");
    SERIAL_ECHO_START;
    SERIAL_ECHOPAIR("   Swap retract length (mm):    ", retract_length_swap);
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
    SERIAL_ECHOPAIR("   Swap rec. addl. length (mm): ", retract_recover_length_swap);
#endif
#if defined (upstream) && (EXTRUDERS > 1 && !defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (gregor2005) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) )
    SERIAL_ECHOLN("");
#endif
#if defined (upstream) && (!defined (DISABLE_M503) && defined (FWRETRACT) )
    SERIAL_ECHO_START;
    if (volumetric_enabled) {
        SERIAL_ECHOLNPGM("Filament settings:");
        SERIAL_ECHO_START;
        SERIAL_ECHOPAIR("   M200 D", filament_size[0]);
        SERIAL_ECHOLN("");
#if EXTRUDERS > 1
        SERIAL_ECHO_START;
        SERIAL_ECHOPAIR("   M200 T1 D", filament_size[1]);
        SERIAL_ECHOLN("");
#if EXTRUDERS > 2
        SERIAL_ECHO_START;
        SERIAL_ECHOPAIR("   M200 T2 D", filament_size[2]);
        SERIAL_ECHOLN("");
#endif
#endif
    } else {
        SERIAL_ECHOLNPGM("Filament settings: Disabled");
    }
#endif
}
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (gregor2005) && defined (EEPROM_SETTINGS)
void Config_RetrieveSettings
() {
    int i=EEPROM_OFFSET;
    char stored_ver[4];
    char ver[4]=EEPROM_VERSION;
    EEPROM_READ_VAR(i,stored_ver);
//read stored version
//  SERIAL_ECHOLN("Version: [" << ver << "] Stored version: [" << stored_ver << "]");
    if
    (strncmp(ver,stored_ver,3) == 0) {
// version number match
        EEPROM_READ_VAR(i,axis_steps_per_unit);
        EEPROM_READ_VAR(i,max_feedrate);
        EEPROM_READ_VAR(i,max_acceleration_units_per_sq_second);
// steps per sq second need to be updated to agree with the units per sq second (as they are what is used in the planner)
        reset_acceleration_rates();
        EEPROM_READ_VAR(i,acceleration);
        EEPROM_READ_VAR(i,retract_acceleration);
        EEPROM_READ_VAR(i,minimumfeedrate);
        EEPROM_READ_VAR(i,mintravelfeedrate);
        EEPROM_READ_VAR(i,minsegmenttime);
        EEPROM_READ_VAR(i,max_xy_jerk);
        EEPROM_READ_VAR(i,max_z_jerk);
        EEPROM_READ_VAR(i,max_e_jerk);
#if defined (upstream) && defined (EEPROM_SETTINGS)
        EEPROM_READ_VAR(i,add_homing);
#endif
#if defined (gregor2005) && defined (EEPROM_SETTINGS)
        EEPROM_READ_VAR(i,add_homeing);
#endif
#if defined (upstream) && (defined (DELTA) && defined (EEPROM_SETTINGS) )
        EEPROM_READ_VAR(i,endstop_adj);
        EEPROM_READ_VAR(i,delta_radius);
        EEPROM_READ_VAR(i,delta_diagonal_rod);
        EEPROM_READ_VAR(i,delta_segments_per_second);
#endif
#if defined (upstream) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (gregor2005) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) )
        int plaPreheatHotendTemp, plaPreheatHPBTemp, plaPreheatFanSpeed;
        int absPreheatHotendTemp, absPreheatHPBTemp, absPreheatFanSpeed;
#endif
        EEPROM_READ_VAR(i,plaPreheatHotendTemp);
        EEPROM_READ_VAR(i,plaPreheatHPBTemp);
        EEPROM_READ_VAR(i,plaPreheatFanSpeed);
        EEPROM_READ_VAR(i,absPreheatHotendTemp);
        EEPROM_READ_VAR(i,absPreheatHPBTemp);
        EEPROM_READ_VAR(i,absPreheatFanSpeed);
#if defined (upstream) && defined (EEPROM_SETTINGS)
        EEPROM_READ_VAR(i,zprobe_zoffset);
#endif
#if defined (upstream) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (gregor2005) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) )
        float Kp,Ki,Kd;
#endif
// do not need to scale PID values as the values in EEPROM are already scaled
        EEPROM_READ_VAR(i,Kp);
        EEPROM_READ_VAR(i,Ki);
        EEPROM_READ_VAR(i,Kd);
#if defined (upstream) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) )
        int lcd_contrast;
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS)
        EEPROM_READ_VAR(i,lcd_contrast);
#endif
#if defined (upstream) && (defined (SCARA) && defined (EEPROM_SETTINGS) )
        EEPROM_READ_VAR(i,axis_scaling);
#endif
#if defined (upstream) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
        EEPROM_READ_VAR(i,autoretract_enabled);
        EEPROM_READ_VAR(i,retract_length);
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
        EEPROM_READ_VAR(i,retract_length_swap);
#endif
#if defined (upstream) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
        EEPROM_READ_VAR(i,retract_feedrate);
        EEPROM_READ_VAR(i,retract_zlift);
        EEPROM_READ_VAR(i,retract_recover_length);
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
        EEPROM_READ_VAR(i,retract_recover_length_swap);
#endif
#if defined (upstream) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
        EEPROM_READ_VAR(i,retract_recover_feedrate);
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS)
        EEPROM_READ_VAR(i, volumetric_enabled);
        EEPROM_READ_VAR(i, filament_size[0]);
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) )
        EEPROM_READ_VAR(i, filament_size[1]);
#endif
#if defined (upstream) && (EXTRUDERS > 2 && EXTRUDERS > 1 && defined (EEPROM_SETTINGS) )
        EEPROM_READ_VAR(i, filament_size[2]);
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS)
        calculate_volumetric_multipliers();
#endif
// Call updatePID (similar to when we have processed M301)
        updatePID();
        SERIAL_ECHO_START;
        SERIAL_ECHOLNPGM("Stored settings retrieved");
    } else {
        Config_ResetDefault();
    }
#if defined (upstream) && (defined (EEPROM_CHITCHAT) && defined (EEPROM_SETTINGS) ) || defined (gregor2005) && defined (EEPROM_SETTINGS)
    Config_PrintSettings();
#endif
}
#endif
#if defined (upstream) || defined (gregor2005)
void Config_ResetDefault
() {
    float tmp1[]=DEFAULT_AXIS_STEPS_PER_UNIT;
    float tmp2[]=DEFAULT_MAX_FEEDRATE;
    long tmp3[]=DEFAULT_MAX_ACCELERATION;
#if defined (upstream)
    for (short i=0; i<4; i++) {
        axis_steps_per_unit[i]=tmp1[i];
        max_feedrate[i]=tmp2[i];
        max_acceleration_units_per_sq_second[i]=tmp3[i];
#ifdef SCARA
        axis_scaling[i]=1;
#endif
    }
#endif
#if defined (gregor2005)
    for (short i=0; i<4; i++) {
        axis_steps_per_unit[i]=tmp1[i];
        max_feedrate[i]=tmp2[i];
        max_acceleration_units_per_sq_second[i]=tmp3[i];
    }
#endif
// steps per sq second need to be updated to agree with the units per sq second
    reset_acceleration_rates();
    acceleration=DEFAULT_ACCELERATION;
    retract_acceleration=DEFAULT_RETRACT_ACCELERATION;
    minimumfeedrate=DEFAULT_MINIMUMFEEDRATE;
    minsegmenttime=DEFAULT_MINSEGMENTTIME;
    mintravelfeedrate=DEFAULT_MINTRAVELFEEDRATE;
    max_xy_jerk=DEFAULT_XYJERK;
    max_z_jerk=DEFAULT_ZJERK;
    max_e_jerk=DEFAULT_EJERK;
#if defined (upstream)
    add_homing[X_AXIS] = add_homing[Y_AXIS] = add_homing[Z_AXIS] = 0;
#endif
#if defined (gregor2005)
    add_homeing[0] = add_homeing[1] = add_homeing[2] = 0;
#endif
#if defined (upstream) && defined (DELTA)
    endstop_adj[X_AXIS] = endstop_adj[Y_AXIS] = endstop_adj[Z_AXIS] = 0;
    delta_radius= DELTA_RADIUS;
    delta_diagonal_rod= DELTA_DIAGONAL_ROD;
    delta_segments_per_second= DELTA_SEGMENTS_PER_SECOND;
    recalc_delta_settings(delta_radius, delta_diagonal_rod);
#endif
#if defined (upstream) && defined (ULTIPANEL) || defined (gregor2005) && defined (ULTIPANEL)
    plaPreheatHotendTemp = PLA_PREHEAT_HOTEND_TEMP;
    plaPreheatHPBTemp = PLA_PREHEAT_HPB_TEMP;
    plaPreheatFanSpeed = PLA_PREHEAT_FAN_SPEED;
    absPreheatHotendTemp = ABS_PREHEAT_HOTEND_TEMP;
    absPreheatHPBTemp = ABS_PREHEAT_HPB_TEMP;
    absPreheatFanSpeed = ABS_PREHEAT_FAN_SPEED;
#endif
#if defined (upstream) && defined (ENABLE_AUTO_BED_LEVELING)
    zprobe_zoffset = -Z_PROBE_OFFSET_FROM_EXTRUDER;
#endif
#if defined (upstream) && defined (DOGLCD)
    lcd_contrast = DEFAULT_LCD_CONTRAST;
#endif
#if defined (upstream) && defined (PIDTEMP) || defined (gregor2005) && defined (PIDTEMP)
    Kp = DEFAULT_Kp;
    Ki = scalePID_i(DEFAULT_Ki);
    Kd = scalePID_d(DEFAULT_Kd);
// call updatePID (similar to when we have processed M301)
    updatePID();
#endif
#if defined (upstream) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (gregor2005) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) )
    Kc = DEFAULT_Kc;
#endif
#if defined (upstream) && defined (PIDTEMP) || defined (gregor2005) && defined (PIDTEMP)
//PID_ADD_EXTRUSION_RATE
#endif
//PIDTEMP
#if defined (upstream) && defined (FWRETRACT)
    autoretract_enabled = false;
    retract_length = RETRACT_LENGTH;
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (FWRETRACT) )
    retract_length_swap = RETRACT_LENGTH_SWAP;
#endif
#if defined (upstream) && defined (FWRETRACT)
    retract_feedrate = RETRACT_FEEDRATE;
    retract_zlift = RETRACT_ZLIFT;
    retract_recover_length = RETRACT_RECOVER_LENGTH;
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (FWRETRACT) )
    retract_recover_length_swap = RETRACT_RECOVER_LENGTH_SWAP;
#endif
#if defined (upstream) && defined (FWRETRACT)
    retract_recover_feedrate = RETRACT_RECOVER_FEEDRATE;
#endif
#if defined (upstream)
    volumetric_enabled = false;
    filament_size[0] = DEFAULT_NOMINAL_FILAMENT_DIA;
#endif
#if defined (upstream) && EXTRUDERS > 1
    filament_size[1] = DEFAULT_NOMINAL_FILAMENT_DIA;
#endif
#if defined (upstream) && (EXTRUDERS > 2 && EXTRUDERS > 1 )
    filament_size[2] = DEFAULT_NOMINAL_FILAMENT_DIA;
#endif
#if defined (upstream)
    calculate_volumetric_multipliers();
#endif
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Hardcoded Default Settings Loaded");
}
#endif
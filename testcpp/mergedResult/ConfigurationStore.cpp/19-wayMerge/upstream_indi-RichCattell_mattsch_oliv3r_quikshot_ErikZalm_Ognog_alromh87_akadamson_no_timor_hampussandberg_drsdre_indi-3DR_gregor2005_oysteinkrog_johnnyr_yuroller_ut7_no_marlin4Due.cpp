#if defined (upstream) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (Ognog) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    #include "Marlin.h"
    #include "planner.h"
    #include "temperature.h"
    #include "ultralcd.h"
#endif
#if defined (oliv3r)
    #include "UltiLCD2.h"
#endif
#if defined (upstream) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (Ognog) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
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
#if defined (indi-RichCattell)
    #define EEPROM_VERSION "V14"
#endif
#if defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005)
    #define EEPROM_VERSION "V07"
#endif
#if defined (upstream) || defined (oysteinkrog) || defined (yuroller)
    #define EEPROM_VERSION "V13"
#endif
#if defined (mattsch) || defined (ErikZalm) || defined (hampussandberg) || defined (ut7)
    #define EEPROM_VERSION "V10"
#endif
#if defined (mattsch) && defined (DELTA) || defined (ErikZalm) && defined (DELTA) || defined (hampussandberg) && defined (DELTA) || defined (ut7) && defined (DELTA)
    #undef EEPROM_VERSION
#endif
#if defined (mattsch) && defined (DELTA) || defined (oliv3r) || defined (quikshot) && defined (DELTA) || defined (ErikZalm) && defined (DELTA) || defined (Ognog) && defined (DELTA) || defined (alromh87) && defined (DELTA) || defined (hampussandberg) && defined (DELTA) || defined (johnnyr) && defined (DELTA) || defined (ut7) && defined (DELTA)
    #define EEPROM_VERSION "V11"
#endif
#if defined (quikshot) && !defined (DELTA) || defined (Ognog) && !defined (DELTA) || defined (alromh87) && !defined (DELTA) || defined (johnnyr) && !defined (DELTA)
    #define EEPROM_VERSION "V10"
#endif
#if defined (mattsch) && defined (SCARA) || defined (ErikZalm) && defined (SCARA) || defined (hampussandberg) && defined (SCARA) || defined (ut7) && defined (SCARA)
    #undef EEPROM_VERSION
    #define EEPROM_VERSION "V12"
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (indi-RichCattell) && defined (EEPROM_SETTINGS) || defined (mattsch) && defined (EEPROM_SETTINGS) || defined (oliv3r) && defined (EEPROM_SETTINGS) || defined (quikshot) && defined (EEPROM_SETTINGS) || defined (ErikZalm) && defined (EEPROM_SETTINGS) || defined (Ognog) && defined (EEPROM_SETTINGS) || defined (alromh87) && defined (EEPROM_SETTINGS) || defined (akadamson) && defined (EEPROM_SETTINGS) || defined (hampussandberg) && defined (EEPROM_SETTINGS) || defined (drsdre) && defined (EEPROM_SETTINGS) || defined (indi-3DR) && defined (EEPROM_SETTINGS) || defined (gregor2005) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && defined (EEPROM_SETTINGS) || defined (johnnyr) && defined (EEPROM_SETTINGS) || defined (yuroller) && defined (EEPROM_SETTINGS) || defined (ut7) && defined (EEPROM_SETTINGS)
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
#if defined (indi-RichCattell) && defined (EEPROM_SETTINGS) || defined (oliv3r) && defined (EEPROM_SETTINGS) || defined (quikshot) && defined (EEPROM_SETTINGS) || defined (Ognog) && defined (EEPROM_SETTINGS) || defined (alromh87) && defined (EEPROM_SETTINGS) || defined (akadamson) && defined (EEPROM_SETTINGS) || defined (hampussandberg) && defined (EEPROM_SETTINGS) || defined (drsdre) && defined (EEPROM_SETTINGS) || defined (indi-3DR) && defined (EEPROM_SETTINGS) || defined (gregor2005) && defined (EEPROM_SETTINGS) || defined (johnnyr) && defined (EEPROM_SETTINGS)
    EEPROM_WRITE_VAR(i,add_homeing);
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (mattsch) && defined (EEPROM_SETTINGS) || defined (ErikZalm) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && defined (EEPROM_SETTINGS) || defined (yuroller) && defined (EEPROM_SETTINGS) || defined (ut7) && defined (EEPROM_SETTINGS)
    EEPROM_WRITE_VAR(i,add_homing);
#endif
#if defined (upstream) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (quikshot) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (Ognog) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (alromh87) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (johnnyr) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (defined (DELTA) && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i,endstop_adj);
#endif
#if defined (upstream) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (indi-RichCattell) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (quikshot) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (Ognog) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (alromh87) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (johnnyr) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (defined (DELTA) && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i,delta_radius);
    EEPROM_WRITE_VAR(i,delta_diagonal_rod);
#endif
#if defined (indi-RichCattell) && (defined (DELTA) && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i,max_pos);
#endif
#if defined (upstream) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (quikshot) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (Ognog) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (alromh87) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (johnnyr) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (defined (DELTA) && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i,delta_segments_per_second);
#endif
#if defined (indi-RichCattell) && (defined (DELTA) && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i,endstop_adj);
    EEPROM_WRITE_VAR(i,tower_adj);
    EEPROM_WRITE_VAR(i,z_probe_offset);
#endif
#if defined (upstream) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (indi-RichCattell) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (oliv3r) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (quikshot) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (Ognog) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (alromh87) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (akadamson) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (drsdre) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (indi-3DR) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (gregor2005) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (johnnyr) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) )
    int plaPreheatHotendTemp = PLA_PREHEAT_HOTEND_TEMP, plaPreheatHPBTemp = PLA_PREHEAT_HPB_TEMP, plaPreheatFanSpeed = PLA_PREHEAT_FAN_SPEED;
    int absPreheatHotendTemp = ABS_PREHEAT_HOTEND_TEMP, absPreheatHPBTemp = ABS_PREHEAT_HPB_TEMP, absPreheatFanSpeed = ABS_PREHEAT_FAN_SPEED;
#endif
    EEPROM_WRITE_VAR(i,plaPreheatHotendTemp);
    EEPROM_WRITE_VAR(i,plaPreheatHPBTemp);
    EEPROM_WRITE_VAR(i,plaPreheatFanSpeed);
    EEPROM_WRITE_VAR(i,absPreheatHotendTemp);
    EEPROM_WRITE_VAR(i,absPreheatHPBTemp);
    EEPROM_WRITE_VAR(i,absPreheatFanSpeed);
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (mattsch) && defined (EEPROM_SETTINGS) || defined (quikshot) && defined (EEPROM_SETTINGS) || defined (ErikZalm) && defined (EEPROM_SETTINGS) || defined (Ognog) && defined (EEPROM_SETTINGS) || defined (alromh87) && defined (EEPROM_SETTINGS) || defined (hampussandberg) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && defined (EEPROM_SETTINGS) || defined (johnnyr) && defined (EEPROM_SETTINGS) || defined (yuroller) && defined (EEPROM_SETTINGS) || defined (ut7) && defined (EEPROM_SETTINGS)
    EEPROM_WRITE_VAR(i,zprobe_zoffset);
#endif
#if defined (upstream) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (indi-RichCattell) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (oliv3r) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (quikshot) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (Ognog) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (alromh87) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (akadamson) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (drsdre) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (indi-3DR) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (gregor2005) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (johnnyr) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (defined (PIDTEMP) && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i,Kp);
    EEPROM_WRITE_VAR(i,Ki);
    EEPROM_WRITE_VAR(i,Kd);
#endif
#if defined (akadamson) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (drsdre) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (indi-3DR) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i,3000);
#endif
#if defined (upstream) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (indi-RichCattell) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (oliv3r) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (quikshot) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (Ognog) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (alromh87) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (gregor2005) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (johnnyr) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) )
    float dummy = 3000.0f;
#endif
#if defined (akadamson) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (drsdre) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (indi-3DR) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i,0);
#endif
#if defined (upstream) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (indi-RichCattell) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (oliv3r) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (quikshot) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (Ognog) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (alromh87) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (gregor2005) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (johnnyr) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i,dummy);
#endif
#if defined (akadamson) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (drsdre) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (indi-3DR) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i,0);
#endif
#if defined (upstream) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (indi-RichCattell) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (oliv3r) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (quikshot) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (Ognog) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (alromh87) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (gregor2005) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (johnnyr) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) )
    dummy = 0.0f;
    EEPROM_WRITE_VAR(i,dummy);
    EEPROM_WRITE_VAR(i,dummy);
#endif
#if defined (oliv3r) && defined (EEPROM_SETTINGS)
    EEPROM_WRITE_VAR(i,motor_current_setting);
#endif
#if defined (upstream) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (indi-RichCattell) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (quikshot) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (Ognog) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (alromh87) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (johnnyr) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) )
    int lcd_contrast = 32;
#endif
#if defined (oliv3r) && (defined (EEPROM_SETTINGS) && defined (ENABLE_ULTILCD2) )
    EEPROM_WRITE_VAR(i,led_brightness_level);
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (indi-RichCattell) && defined (EEPROM_SETTINGS) || defined (mattsch) && defined (EEPROM_SETTINGS) || defined (quikshot) && defined (EEPROM_SETTINGS) || defined (ErikZalm) && defined (EEPROM_SETTINGS) || defined (Ognog) && defined (EEPROM_SETTINGS) || defined (alromh87) && defined (EEPROM_SETTINGS) || defined (hampussandberg) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && defined (EEPROM_SETTINGS) || defined (johnnyr) && defined (EEPROM_SETTINGS) || defined (yuroller) && defined (EEPROM_SETTINGS) || defined (ut7) && defined (EEPROM_SETTINGS)
    EEPROM_WRITE_VAR(i,lcd_contrast);
#endif
#if defined (oliv3r) && (defined (EEPROM_SETTINGS) && defined (ENABLE_ULTILCD2) )
    EEPROM_WRITE_VAR(i,led_mode);
#endif
#if defined (upstream) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (defined (SCARA) && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i,axis_scaling);
#endif
#if defined (oliv3r) && (!defined (ENABLE_ULTILCD2) && defined (EEPROM_SETTINGS) )
    uint8_t dummyByte=0;
#endif
#if defined (upstream) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (defined (SCARA) && defined (EEPROM_SETTINGS) )
// Add scaling for SCARA
#endif
#if defined (oliv3r) && (!defined (ENABLE_ULTILCD2) && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i,dummyByte);
#endif
#if defined (upstream) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (oysteinkrog) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (yuroller) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
    EEPROM_WRITE_VAR(i,autoretract_enabled);
#endif
#if defined (oliv3r) && (!defined (ENABLE_ULTILCD2) && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i,dummyByte);
#endif
#if defined (upstream) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (oliv3r) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (yuroller) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
    EEPROM_WRITE_VAR(i,retract_length);
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (oysteinkrog) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (yuroller) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
    EEPROM_WRITE_VAR(i,retract_length_swap);
#endif
#if defined (upstream) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (oliv3r) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (yuroller) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
    EEPROM_WRITE_VAR(i,retract_feedrate);
#endif
#if defined (upstream) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (oysteinkrog) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (yuroller) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
    EEPROM_WRITE_VAR(i,retract_zlift);
    EEPROM_WRITE_VAR(i,retract_recover_length);
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (oysteinkrog) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (yuroller) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
    EEPROM_WRITE_VAR(i,retract_recover_length_swap);
#endif
#if defined (upstream) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (oysteinkrog) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (yuroller) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
    EEPROM_WRITE_VAR(i,retract_recover_feedrate);
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && defined (EEPROM_SETTINGS) || defined (yuroller) && defined (EEPROM_SETTINGS)
// Save filament sizes
    EEPROM_WRITE_VAR(i, volumetric_enabled);
    EEPROM_WRITE_VAR(i, filament_size[0]);
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) )
    EEPROM_WRITE_VAR(i, filament_size[1]);
#endif
#if defined (upstream) && (EXTRUDERS > 2 && EXTRUDERS > 1 && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (EXTRUDERS > 2 && EXTRUDERS > 1 && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (EXTRUDERS > 2 && EXTRUDERS > 1 && defined (EEPROM_SETTINGS) )
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
#if defined (upstream) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (Ognog) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    //EEPROM_SETTINGS
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (mattsch) && !defined (DISABLE_M503) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (hampussandberg) && !defined (DISABLE_M503) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (johnnyr) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
void Config_PrintSettings
() {
// Always have this function, even with EEPROM_SETTINGS disabled, the current values will be shown
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Steps per unit:");
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (hampussandberg) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHO_START;
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR("  M92 X",axis_steps_per_unit[X_AXIS]);
#endif
#if defined (hampussandberg) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR("  M92 X",axis_steps_per_unit[0]);
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Y",axis_steps_per_unit[Y_AXIS]);
#endif
#if defined (hampussandberg) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Y",axis_steps_per_unit[1]);
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Z",axis_steps_per_unit[Z_AXIS]);
#endif
#if defined (hampussandberg) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Z",axis_steps_per_unit[2]);
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" E",axis_steps_per_unit[E_AXIS]);
#endif
#if defined (hampussandberg) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" E",axis_steps_per_unit[3]);
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (hampussandberg) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOLN("");
#endif
    SERIAL_ECHO_START;
#if defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (johnnyr) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR("  M92 X",axis_steps_per_unit[0]);
#endif
#if defined (upstream) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (mattsch) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (hampussandberg) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHOLNPGM("Scaling factors:");
#endif
#if defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (johnnyr) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Y",axis_steps_per_unit[1]);
#endif
#if defined (upstream) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (mattsch) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (hampussandberg) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHO_START;
#endif
#if defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (johnnyr) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Z",axis_steps_per_unit[2]);
#endif
#if defined (upstream) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (mattsch) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR("  M365 X",axis_scaling[X_AXIS]);
#endif
#if defined (hampussandberg) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR("  M365 X",axis_scaling[0]);
#endif
#if defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (johnnyr) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" E",axis_steps_per_unit[3]);
#endif
#if defined (upstream) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (mattsch) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" Y",axis_scaling[Y_AXIS]);
#endif
#if defined (hampussandberg) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" Y",axis_scaling[1]);
#endif
#if defined (upstream) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (mattsch) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" Z",axis_scaling[Z_AXIS]);
#endif
#if defined (hampussandberg) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" Z",axis_scaling[2]);
#endif
#if defined (upstream) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (mattsch) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (ErikZalm) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (hampussandberg) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (oysteinkrog) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (johnnyr) && !defined (DISABLE_M503) || defined (yuroller) && (defined (SCARA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
#endif
    SERIAL_ECHOLNPGM("Maximum feedrates (mm/s):");
    SERIAL_ECHO_START;
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR("  M203 X", max_feedrate[X_AXIS]);
#endif
#if defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (hampussandberg) && !defined (DISABLE_M503) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (johnnyr) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR("  M203 X",max_feedrate[0]);
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Y", max_feedrate[Y_AXIS]);
#endif
#if defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (hampussandberg) && !defined (DISABLE_M503) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (johnnyr) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Y",max_feedrate[1] );
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Z", max_feedrate[Z_AXIS]);
#endif
#if defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (hampussandberg) && !defined (DISABLE_M503) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (johnnyr) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Z", max_feedrate[2] );
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" E", max_feedrate[E_AXIS]);
#endif
#if defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (hampussandberg) && !defined (DISABLE_M503) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (johnnyr) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" E", max_feedrate[3]);
#endif
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Maximum Acceleration (mm/s2):");
    SERIAL_ECHO_START;
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR("  M201 X" ,max_acceleration_units_per_sq_second[X_AXIS] );
#endif
#if defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (hampussandberg) && !defined (DISABLE_M503) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (johnnyr) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR("  M201 X" ,max_acceleration_units_per_sq_second[0] );
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Y" , max_acceleration_units_per_sq_second[Y_AXIS] );
#endif
#if defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (hampussandberg) && !defined (DISABLE_M503) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (johnnyr) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Y" , max_acceleration_units_per_sq_second[1] );
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Z" ,max_acceleration_units_per_sq_second[Z_AXIS] );
#endif
#if defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (hampussandberg) && !defined (DISABLE_M503) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (johnnyr) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Z" ,max_acceleration_units_per_sq_second[2] );
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" E" ,max_acceleration_units_per_sq_second[E_AXIS]);
#endif
#if defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (hampussandberg) && !defined (DISABLE_M503) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (johnnyr) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
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
#if defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT)
    SERIAL_ECHOLNPGM("Advanced variables: S=Min feedrate (mm/s), T=Min travel feedrate (mm/s), B=minimum segment time (ms), X=maximum xY jerk (mm/s),  Z=maximum Z jerk (mm/s)");
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (mattsch) && !defined (DISABLE_M503) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (hampussandberg) && !defined (DISABLE_M503) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (johnnyr) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOLNPGM("Advanced variables: S=Min feedrate (mm/s), T=Min travel feedrate (mm/s), B=minimum segment time (ms), X=maximum XY jerk (mm/s),  Z=maximum Z jerk (mm/s),  E=maximum E jerk (mm/s)");
#endif
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
    SERIAL_ECHO_START;
#if defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (hampussandberg) && !defined (DISABLE_M503) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (johnnyr) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR("  M206 X",add_homeing[0] );
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR("  M206 X",add_homing[X_AXIS] );
#endif
#if defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR("  M206 X",add_homing[0] );
#endif
#if defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (hampussandberg) && !defined (DISABLE_M503) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (johnnyr) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Y" ,add_homeing[1] );
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Y" ,add_homing[Y_AXIS] );
#endif
#if defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Y" ,add_homing[1] );
#endif
#if defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (hampussandberg) && !defined (DISABLE_M503) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (johnnyr) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Z" ,add_homeing[2] );
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (mattsch) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Z" ,add_homing[Z_AXIS] );
#endif
#if defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Z" ,add_homing[2] );
#endif
#if defined (upstream) && !defined (DISABLE_M503) || defined (indi-RichCattell) && defined (EEPROM_CHITCHAT) || defined (mattsch) && !defined (DISABLE_M503) || defined (quikshot) && !defined (DISABLE_M503) || defined (ErikZalm) && !defined (DISABLE_M503) || defined (Ognog) && !defined (DISABLE_M503) || defined (alromh87) && !defined (DISABLE_M503) || defined (hampussandberg) && !defined (DISABLE_M503) || defined (oysteinkrog) && !defined (DISABLE_M503) || defined (johnnyr) && !defined (DISABLE_M503) || defined (yuroller) && !defined (DISABLE_M503) || defined (ut7) && !defined (DISABLE_M503)
    SERIAL_ECHOLN("");
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (DELTA) ) || defined (mattsch) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (quikshot) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (Ognog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (hampussandberg) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (johnnyr) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHO_START;
#endif
#if defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (DELTA) )
    SERIAL_ECHOLNPGM("Endstop adjustment (mm):");
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (mattsch) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (quikshot) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (Ognog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (hampussandberg) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (johnnyr) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOLNPGM("Endstop adjustement (mm):");
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (DELTA) ) || defined (mattsch) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (quikshot) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (Ognog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (hampussandberg) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (johnnyr) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHO_START;
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (mattsch) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR("  M666 X",endstop_adj[X_AXIS] );
#endif
#if defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (DELTA) ) || defined (quikshot) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (Ognog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (hampussandberg) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (johnnyr) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR("  M666 X",endstop_adj[0]);
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (mattsch) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" Y" ,endstop_adj[Y_AXIS] );
#endif
#if defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (DELTA) ) || defined (quikshot) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (Ognog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (hampussandberg) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (johnnyr) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" Y" ,endstop_adj[1]);
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (mattsch) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" Z" ,endstop_adj[Z_AXIS] );
#endif
#if defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (DELTA) ) || defined (quikshot) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (Ognog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (hampussandberg) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (johnnyr) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" Z" ,endstop_adj[2]);
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (DELTA) ) || defined (mattsch) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (quikshot) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (Ognog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (hampussandberg) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (johnnyr) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
#endif
#if defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (DELTA) )
    SERIAL_ECHOLNPGM("Delta Geometry adjustment:");
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (mattsch) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (quikshot) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (Ognog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (hampussandberg) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (johnnyr) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOLNPGM("Delta settings: L=delta_diagonal_rod, R=delta_radius, S=delta_segments_per_second");
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (DELTA) ) || defined (mattsch) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (quikshot) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (Ognog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (hampussandberg) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (johnnyr) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHO_START;
#endif
#if defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (DELTA) )
    SERIAL_ECHOPAIR("  M666 A",tower_adj[0]);
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (mattsch) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (quikshot) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (Ognog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (hampussandberg) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (johnnyr) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR("  M665 L",delta_diagonal_rod );
#endif
#if defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (DELTA) )
    SERIAL_ECHOPAIR(" B" ,tower_adj[1]);
    SERIAL_ECHOPAIR(" C" ,tower_adj[2]);
    SERIAL_ECHOPAIR(" E" ,tower_adj[3]);
    SERIAL_ECHOPAIR(" F" ,tower_adj[4]);
    SERIAL_ECHOPAIR(" G" ,tower_adj[5]);
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (DELTA) ) || defined (mattsch) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (quikshot) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (Ognog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (hampussandberg) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (johnnyr) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" R" ,delta_radius );
#endif
#if defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (DELTA) )
    SERIAL_ECHOPAIR(" D" ,delta_diagonal_rod);
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (mattsch) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (quikshot) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (Ognog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (hampussandberg) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (johnnyr) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" S" ,delta_segments_per_second );
#endif
#if defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (DELTA) )
    SERIAL_ECHOPAIR(" H" ,max_pos[2]);
    SERIAL_ECHOPAIR(" P" ,z_probe_offset[3]);
#endif
#if defined (upstream) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (DELTA) ) || defined (mattsch) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (oliv3r) && defined (EEPROM_CHITCHAT) || defined (quikshot) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (Ognog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (akadamson) && defined (EEPROM_CHITCHAT) || defined (hampussandberg) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (drsdre) && defined (EEPROM_CHITCHAT) || defined (indi-3DR) && defined (EEPROM_CHITCHAT) || defined (gregor2005) && defined (EEPROM_CHITCHAT) || defined (oysteinkrog) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (johnnyr) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOLN("");
#endif
#if defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (DELTA) )
    /*
          SERIAL_ECHOLN("Tower Positions");
          SERIAL_ECHOPAIR("Tower1 X:",delta_tower1_x);
          SERIAL_ECHOPAIR(" Y:",delta_tower1_y);
          SERIAL_ECHOLN("");
          SERIAL_ECHOPAIR("Tower2 X:",delta_tower2_x);
          SERIAL_ECHOPAIR(" Y:",delta_tower2_y);
          SERIAL_ECHOLN("");
          SERIAL_ECHOPAIR("Tower3 X:",delta_tower3_x);
          SERIAL_ECHOPAIR(" Y:",delta_tower3_y);
          SERIAL_ECHOLN("");
    */
#endif
#if defined (upstream) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (mattsch) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (oliv3r) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (quikshot) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (Ognog) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (akadamson) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (hampussandberg) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (drsdre) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (indi-3DR) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (gregor2005) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (oysteinkrog) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (johnnyr) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (PIDTEMP) && !defined (DISABLE_M503) )
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("PID settings:");
    SERIAL_ECHO_START;
    SERIAL_ECHOPAIR("   M301 P",Kp);
#endif
#if defined (akadamson) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (drsdre) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (indi-3DR) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) )
    SERIAL_ECHOPAIR(" I" ,Ki/PID_dT);
#endif
#if defined (upstream) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (mattsch) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (oliv3r) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (quikshot) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (Ognog) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (hampussandberg) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (gregor2005) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (oysteinkrog) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (johnnyr) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (PIDTEMP) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" I" ,unscalePID_i(Ki));
#endif
#if defined (akadamson) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (drsdre) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (indi-3DR) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) )
    SERIAL_ECHOPAIR(" D" ,Kd*PID_dT);
#endif
#if defined (upstream) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (mattsch) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (oliv3r) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (quikshot) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (Ognog) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (hampussandberg) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (gregor2005) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (oysteinkrog) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (johnnyr) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (ut7) && (defined (PIDTEMP) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" D" ,unscalePID_d(Kd));
#endif
#if defined (upstream) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (mattsch) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (oysteinkrog) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (yuroller) && (defined (PIDTEMP) && !defined (DISABLE_M503) )
    SERIAL_ECHOLN("");
#endif
#if defined (upstream) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (mattsch) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (ErikZalm) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (oysteinkrog) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (yuroller) && (!defined (DISABLE_M503) && defined (FWRETRACT) )
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
#endif
#if defined (upstream) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (oysteinkrog) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (yuroller) && (!defined (DISABLE_M503) && defined (FWRETRACT) )
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Auto-Retract: S=0 to disable, 1 to interpret extrude-only moves as retracts or recoveries");
    SERIAL_ECHO_START;
    SERIAL_ECHOPAIR("   M209 S", (unsigned long)(autoretract_enabled ? 1 : 0));
    SERIAL_ECHOLN("");
#endif
#if defined (upstream) && (EXTRUDERS > 1 && !defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (oysteinkrog) && (EXTRUDERS > 1 && !defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (yuroller) && (EXTRUDERS > 1 && !defined (DISABLE_M503) && defined (FWRETRACT) )
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Multi-extruder settings:");
    SERIAL_ECHO_START;
    SERIAL_ECHOPAIR("   Swap retract length (mm):    ", retract_length_swap);
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
    SERIAL_ECHOPAIR("   Swap rec. addl. length (mm): ", retract_recover_length_swap);
#endif
#if defined (upstream) && (EXTRUDERS > 1 && !defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (indi-RichCattell) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (mattsch) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (oliv3r) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (quikshot) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (ErikZalm) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (Ognog) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (alromh87) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (akadamson) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (hampussandberg) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (drsdre) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (indi-3DR) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (gregor2005) && (defined (EEPROM_CHITCHAT) && defined (PIDTEMP) ) || defined (oysteinkrog) && (EXTRUDERS > 1 && !defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (johnnyr) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (yuroller) && (EXTRUDERS > 1 && !defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (ut7) && (defined (PIDTEMP) && !defined (DISABLE_M503) )
    SERIAL_ECHOLN("");
#endif
#if defined (upstream) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (oysteinkrog) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (yuroller) && (!defined (DISABLE_M503) && defined (FWRETRACT) )
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
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (indi-RichCattell) && defined (EEPROM_SETTINGS) || defined (mattsch) && defined (EEPROM_SETTINGS) || defined (oliv3r) && defined (EEPROM_SETTINGS) || defined (quikshot) && defined (EEPROM_SETTINGS) || defined (ErikZalm) && defined (EEPROM_SETTINGS) || defined (Ognog) && defined (EEPROM_SETTINGS) || defined (alromh87) && defined (EEPROM_SETTINGS) || defined (akadamson) && defined (EEPROM_SETTINGS) || defined (hampussandberg) && defined (EEPROM_SETTINGS) || defined (drsdre) && defined (EEPROM_SETTINGS) || defined (indi-3DR) && defined (EEPROM_SETTINGS) || defined (gregor2005) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && defined (EEPROM_SETTINGS) || defined (johnnyr) && defined (EEPROM_SETTINGS) || defined (yuroller) && defined (EEPROM_SETTINGS) || defined (ut7) && defined (EEPROM_SETTINGS)
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
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (indi-RichCattell) && defined (EEPROM_SETTINGS) || defined (mattsch) && defined (EEPROM_SETTINGS) || defined (oliv3r) && defined (EEPROM_SETTINGS) || defined (quikshot) && defined (EEPROM_SETTINGS) || defined (ErikZalm) && defined (EEPROM_SETTINGS) || defined (Ognog) && defined (EEPROM_SETTINGS) || defined (alromh87) && defined (EEPROM_SETTINGS) || defined (hampussandberg) && defined (EEPROM_SETTINGS) || defined (gregor2005) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && defined (EEPROM_SETTINGS) || defined (johnnyr) && defined (EEPROM_SETTINGS) || defined (yuroller) && defined (EEPROM_SETTINGS) || defined (ut7) && defined (EEPROM_SETTINGS)
// steps per sq second need to be updated to agree with the units per sq second (as they are what is used in the planner)
        reset_acceleration_rates();
#endif
        EEPROM_READ_VAR(i,acceleration);
        EEPROM_READ_VAR(i,retract_acceleration);
        EEPROM_READ_VAR(i,minimumfeedrate);
        EEPROM_READ_VAR(i,mintravelfeedrate);
        EEPROM_READ_VAR(i,minsegmenttime);
        EEPROM_READ_VAR(i,max_xy_jerk);
        EEPROM_READ_VAR(i,max_z_jerk);
        EEPROM_READ_VAR(i,max_e_jerk);
#if defined (indi-RichCattell) && defined (EEPROM_SETTINGS) || defined (oliv3r) && defined (EEPROM_SETTINGS) || defined (quikshot) && defined (EEPROM_SETTINGS) || defined (Ognog) && defined (EEPROM_SETTINGS) || defined (alromh87) && defined (EEPROM_SETTINGS) || defined (akadamson) && defined (EEPROM_SETTINGS) || defined (hampussandberg) && defined (EEPROM_SETTINGS) || defined (drsdre) && defined (EEPROM_SETTINGS) || defined (indi-3DR) && defined (EEPROM_SETTINGS) || defined (gregor2005) && defined (EEPROM_SETTINGS) || defined (johnnyr) && defined (EEPROM_SETTINGS)
        EEPROM_READ_VAR(i,add_homeing);
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (mattsch) && defined (EEPROM_SETTINGS) || defined (ErikZalm) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && defined (EEPROM_SETTINGS) || defined (yuroller) && defined (EEPROM_SETTINGS) || defined (ut7) && defined (EEPROM_SETTINGS)
        EEPROM_READ_VAR(i,add_homing);
#endif
#if defined (upstream) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (quikshot) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (Ognog) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (alromh87) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (johnnyr) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (defined (DELTA) && defined (EEPROM_SETTINGS) )
        EEPROM_READ_VAR(i,endstop_adj);
#endif
#if defined (upstream) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (indi-RichCattell) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (quikshot) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (Ognog) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (alromh87) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (johnnyr) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (defined (DELTA) && defined (EEPROM_SETTINGS) )
        EEPROM_READ_VAR(i,delta_radius);
        EEPROM_READ_VAR(i,delta_diagonal_rod);
#endif
#if defined (indi-RichCattell) && (defined (DELTA) && defined (EEPROM_SETTINGS) )
        EEPROM_READ_VAR(i,max_pos);
#endif
#if defined (upstream) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (quikshot) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (Ognog) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (alromh87) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (johnnyr) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (defined (DELTA) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (defined (DELTA) && defined (EEPROM_SETTINGS) )
        EEPROM_READ_VAR(i,delta_segments_per_second);
        EEPROM_READ_VAR(i,endstop_adj);
#endif
#if defined (ut7) && (defined (DELTA) && defined (EEPROM_SETTINGS) )
        recalc_delta_settings(delta_radius, delta_diagonal_rod);
        EEPROM_READ_VAR(i,tower_adj);
        EEPROM_READ_VAR(i,z_probe_offset);
// Update delta constants for updated delta_radius & tower_adj values
        set_delta_constants();
#endif
#if defined (upstream) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (indi-RichCattell) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (oliv3r) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (quikshot) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (Ognog) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (alromh87) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (akadamson) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (drsdre) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (indi-3DR) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (gregor2005) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (johnnyr) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (!defined (ULTIPANEL) && defined (EEPROM_SETTINGS) )
        int plaPreheatHotendTemp, plaPreheatHPBTemp, plaPreheatFanSpeed;
        int absPreheatHotendTemp, absPreheatHPBTemp, absPreheatFanSpeed;
#endif
        EEPROM_READ_VAR(i,plaPreheatHotendTemp);
        EEPROM_READ_VAR(i,plaPreheatHPBTemp);
        EEPROM_READ_VAR(i,plaPreheatFanSpeed);
        EEPROM_READ_VAR(i,absPreheatHotendTemp);
        EEPROM_READ_VAR(i,absPreheatHPBTemp);
        EEPROM_READ_VAR(i,absPreheatFanSpeed);
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (mattsch) && defined (EEPROM_SETTINGS) || defined (quikshot) && defined (EEPROM_SETTINGS) || defined (ErikZalm) && defined (EEPROM_SETTINGS) || defined (Ognog) && defined (EEPROM_SETTINGS) || defined (alromh87) && defined (EEPROM_SETTINGS) || defined (hampussandberg) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && defined (EEPROM_SETTINGS) || defined (johnnyr) && defined (EEPROM_SETTINGS) || defined (yuroller) && defined (EEPROM_SETTINGS) || defined (ut7) && defined (EEPROM_SETTINGS)
        EEPROM_READ_VAR(i,zprobe_zoffset);
#endif
#if defined (upstream) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (indi-RichCattell) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (oliv3r) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (quikshot) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (Ognog) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (alromh87) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (akadamson) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (drsdre) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (indi-3DR) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (gregor2005) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (johnnyr) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (!defined (PIDTEMP) && defined (EEPROM_SETTINGS) )
        float Kp,Ki,Kd;
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (indi-RichCattell) && defined (EEPROM_SETTINGS) || defined (mattsch) && defined (EEPROM_SETTINGS) || defined (oliv3r) && defined (EEPROM_SETTINGS) || defined (quikshot) && defined (EEPROM_SETTINGS) || defined (ErikZalm) && defined (EEPROM_SETTINGS) || defined (Ognog) && defined (EEPROM_SETTINGS) || defined (alromh87) && defined (EEPROM_SETTINGS) || defined (hampussandberg) && defined (EEPROM_SETTINGS) || defined (gregor2005) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && defined (EEPROM_SETTINGS) || defined (johnnyr) && defined (EEPROM_SETTINGS) || defined (yuroller) && defined (EEPROM_SETTINGS) || defined (ut7) && defined (EEPROM_SETTINGS)
// do not need to scale PID values as the values in EEPROM are already scaled
#endif
        EEPROM_READ_VAR(i,Kp);
        EEPROM_READ_VAR(i,Ki);
        EEPROM_READ_VAR(i,Kd);
#if defined (oliv3r) && defined (EEPROM_SETTINGS)
        EEPROM_READ_VAR(i,motor_current_setting);
#endif
#if defined (upstream) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (indi-RichCattell) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (quikshot) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (Ognog) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (alromh87) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (johnnyr) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (!defined (DOGLCD) && defined (EEPROM_SETTINGS) )
        int lcd_contrast;
#endif
#if defined (oliv3r) && (defined (EEPROM_SETTINGS) && defined (ENABLE_ULTILCD2) )
        EEPROM_READ_VAR(i,led_brightness_level);
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (indi-RichCattell) && defined (EEPROM_SETTINGS) || defined (mattsch) && defined (EEPROM_SETTINGS) || defined (quikshot) && defined (EEPROM_SETTINGS) || defined (ErikZalm) && defined (EEPROM_SETTINGS) || defined (Ognog) && defined (EEPROM_SETTINGS) || defined (alromh87) && defined (EEPROM_SETTINGS) || defined (hampussandberg) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && defined (EEPROM_SETTINGS) || defined (johnnyr) && defined (EEPROM_SETTINGS) || defined (yuroller) && defined (EEPROM_SETTINGS) || defined (ut7) && defined (EEPROM_SETTINGS)
        EEPROM_READ_VAR(i,lcd_contrast);
        EEPROM_READ_VAR(i,led_mode);
#endif
#if defined (upstream) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (mattsch) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (hampussandberg) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (defined (SCARA) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (defined (SCARA) && defined (EEPROM_SETTINGS) )
        EEPROM_READ_VAR(i,axis_scaling);
#endif
#if defined (oliv3r) && (!defined (ENABLE_ULTILCD2) && defined (EEPROM_SETTINGS) )
        uint8_t dummyByte;
#endif
#if defined (upstream) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (oysteinkrog) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (yuroller) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
        EEPROM_READ_VAR(i,autoretract_enabled);
        EEPROM_READ_VAR(i,dummyByte);
        EEPROM_READ_VAR(i,dummyByte);
#endif
#if defined (upstream) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (oliv3r) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (yuroller) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
        EEPROM_READ_VAR(i,retract_length);
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (oysteinkrog) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (yuroller) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
        EEPROM_READ_VAR(i,retract_length_swap);
#endif
#if defined (upstream) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (oliv3r) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (yuroller) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
        EEPROM_READ_VAR(i,retract_feedrate);
#endif
#if defined (upstream) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (oysteinkrog) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (yuroller) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
        EEPROM_READ_VAR(i,retract_zlift);
        EEPROM_READ_VAR(i,retract_recover_length);
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (oysteinkrog) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (yuroller) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
        EEPROM_READ_VAR(i,retract_recover_length_swap);
#endif
#if defined (upstream) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (oysteinkrog) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) ) || defined (yuroller) && (defined (EEPROM_SETTINGS) && defined (FWRETRACT) )
        EEPROM_READ_VAR(i,retract_recover_feedrate);
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && defined (EEPROM_SETTINGS) || defined (yuroller) && defined (EEPROM_SETTINGS)
        EEPROM_READ_VAR(i, volumetric_enabled);
        EEPROM_READ_VAR(i, filament_size[0]);
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (EXTRUDERS > 1 && defined (EEPROM_SETTINGS) )
        EEPROM_READ_VAR(i, filament_size[1]);
#endif
#if defined (upstream) && (EXTRUDERS > 2 && EXTRUDERS > 1 && defined (EEPROM_SETTINGS) ) || defined (oysteinkrog) && (EXTRUDERS > 2 && EXTRUDERS > 1 && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (EXTRUDERS > 2 && EXTRUDERS > 1 && defined (EEPROM_SETTINGS) )
        EEPROM_READ_VAR(i, filament_size[2]);
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && defined (EEPROM_SETTINGS) || defined (yuroller) && defined (EEPROM_SETTINGS)
        calculate_volumetric_multipliers();
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (indi-RichCattell) && defined (EEPROM_SETTINGS) || defined (mattsch) && defined (EEPROM_SETTINGS) || defined (oliv3r) && defined (EEPROM_SETTINGS) || defined (quikshot) && defined (EEPROM_SETTINGS) || defined (ErikZalm) && defined (EEPROM_SETTINGS) || defined (Ognog) && defined (EEPROM_SETTINGS) || defined (alromh87) && defined (EEPROM_SETTINGS) || defined (hampussandberg) && defined (EEPROM_SETTINGS) || defined (gregor2005) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && defined (EEPROM_SETTINGS) || defined (johnnyr) && defined (EEPROM_SETTINGS) || defined (yuroller) && defined (EEPROM_SETTINGS) || defined (ut7) && defined (EEPROM_SETTINGS)
// Call updatePID (similar to when we have processed M301)
        updatePID();
#endif
        SERIAL_ECHO_START;
#if defined (akadamson) && defined (EEPROM_SETTINGS) || defined (drsdre) && defined (EEPROM_SETTINGS) || defined (indi-3DR) && defined (EEPROM_SETTINGS)
        SERIAL_ECHOLNPGM("Stored settings retreived:");
#endif
#if defined (upstream) && defined (EEPROM_SETTINGS) || defined (indi-RichCattell) && defined (EEPROM_SETTINGS) || defined (mattsch) && defined (EEPROM_SETTINGS) || defined (oliv3r) && defined (EEPROM_SETTINGS) || defined (quikshot) && defined (EEPROM_SETTINGS) || defined (ErikZalm) && defined (EEPROM_SETTINGS) || defined (Ognog) && defined (EEPROM_SETTINGS) || defined (alromh87) && defined (EEPROM_SETTINGS) || defined (hampussandberg) && defined (EEPROM_SETTINGS) || defined (gregor2005) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && defined (EEPROM_SETTINGS) || defined (johnnyr) && defined (EEPROM_SETTINGS) || defined (yuroller) && defined (EEPROM_SETTINGS) || defined (ut7) && defined (EEPROM_SETTINGS)
        SERIAL_ECHOLNPGM("Stored settings retrieved");
#endif
    } else {
        Config_ResetDefault();
#if defined (akadamson) && defined (EEPROM_SETTINGS) || defined (drsdre) && defined (EEPROM_SETTINGS) || defined (indi-3DR) && defined (EEPROM_SETTINGS)
        SERIAL_ECHO_START;
        SERIAL_ECHOLN("Using Default settings:");
#endif
    }
#if defined (oliv3r) && defined (EEPROM_SETTINGS)
    if (strncmp_P(ver, PSTR("V010"), 3) == 0) {
        i = EEPROM_OFFSET + 84;
        EEPROM_READ_VAR(i,add_homeing);
    }
#endif
#if defined (upstream) && (defined (EEPROM_CHITCHAT) && defined (EEPROM_SETTINGS) ) || defined (indi-RichCattell) && defined (EEPROM_SETTINGS) || defined (mattsch) && (defined (EEPROM_CHITCHAT) && defined (EEPROM_SETTINGS) ) || defined (oliv3r) && defined (EEPROM_SETTINGS) || defined (quikshot) && (defined (EEPROM_CHITCHAT) && defined (EEPROM_SETTINGS) ) || defined (ErikZalm) && (defined (EEPROM_CHITCHAT) && defined (EEPROM_SETTINGS) ) || defined (Ognog) && (defined (EEPROM_CHITCHAT) && defined (EEPROM_SETTINGS) ) || defined (alromh87) && (defined (EEPROM_CHITCHAT) && defined (EEPROM_SETTINGS) ) || defined (akadamson) && defined (EEPROM_SETTINGS) || defined (hampussandberg) && (defined (EEPROM_CHITCHAT) && defined (EEPROM_SETTINGS) ) || defined (drsdre) && defined (EEPROM_SETTINGS) || defined (indi-3DR) && defined (EEPROM_SETTINGS) || defined (gregor2005) && defined (EEPROM_SETTINGS) || defined (oysteinkrog) && (defined (EEPROM_CHITCHAT) && defined (EEPROM_SETTINGS) ) || defined (johnnyr) && (defined (EEPROM_CHITCHAT) && defined (EEPROM_SETTINGS) ) || defined (yuroller) && (defined (EEPROM_CHITCHAT) && defined (EEPROM_SETTINGS) ) || defined (ut7) && (defined (EEPROM_CHITCHAT) && defined (EEPROM_SETTINGS) )
    Config_PrintSettings();
#endif
}
#endif
#if defined (upstream) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (Ognog) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
void Config_ResetDefault
() {
    float tmp1[]=DEFAULT_AXIS_STEPS_PER_UNIT;
    float tmp2[]=DEFAULT_MAX_FEEDRATE;
    long tmp3[]=DEFAULT_MAX_ACCELERATION;
#if defined (indi-RichCattell) || defined (oliv3r) || defined (quikshot) || defined (Ognog) || defined (alromh87) || defined (akadamson) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (johnnyr)
    for (short i=0; i<4; i++) {
        axis_steps_per_unit[i]=tmp1[i];
        max_feedrate[i]=tmp2[i];
        max_acceleration_units_per_sq_second[i]=tmp3[i];
    }
#endif
#if defined (upstream) || defined (mattsch) || defined (ErikZalm) || defined (hampussandberg) || defined (oysteinkrog) || defined (yuroller) || defined (ut7)
    for (short i=0; i<4; i++) {
        axis_steps_per_unit[i]=tmp1[i];
        max_feedrate[i]=tmp2[i];
        max_acceleration_units_per_sq_second[i]=tmp3[i];
#ifdef SCARA
        axis_scaling[i]=1;
#endif
    }
#endif
#if defined (upstream) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (Ognog) || defined (alromh87) || defined (hampussandberg) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
// steps per sq second need to be updated to agree with the units per sq second
    reset_acceleration_rates();
#endif
    acceleration=DEFAULT_ACCELERATION;
    retract_acceleration=DEFAULT_RETRACT_ACCELERATION;
    minimumfeedrate=DEFAULT_MINIMUMFEEDRATE;
    minsegmenttime=DEFAULT_MINSEGMENTTIME;
    mintravelfeedrate=DEFAULT_MINTRAVELFEEDRATE;
    max_xy_jerk=DEFAULT_XYJERK;
    max_z_jerk=DEFAULT_ZJERK;
    max_e_jerk=DEFAULT_EJERK;
#if defined (indi-RichCattell) || defined (oliv3r) || defined (quikshot) || defined (Ognog) || defined (alromh87) || defined (akadamson) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (johnnyr)
    add_homeing[0] = add_homeing[1] = add_homeing[2] = 0;
#endif
#if defined (upstream) || defined (mattsch) || defined (ErikZalm) || defined (oysteinkrog) || defined (yuroller)
    add_homing[X_AXIS] = add_homing[Y_AXIS] = add_homing[Z_AXIS] = 0;
#endif
#if defined (ut7)
    add_homing[0] = add_homing[1] = add_homing[2] = 0;
#endif
#if defined (indi-RichCattell) && defined (DELTA)
    delta_radius = DEFAULT_DELTA_RADIUS;
#endif
#if defined (upstream) && defined (DELTA) || defined (mattsch) && defined (DELTA) || defined (ErikZalm) && defined (DELTA) || defined (oysteinkrog) && defined (DELTA) || defined (yuroller) && defined (DELTA)
    endstop_adj[X_AXIS] = endstop_adj[Y_AXIS] = endstop_adj[Z_AXIS] = 0;
#endif
#if defined (quikshot) && defined (DELTA) || defined (Ognog) && defined (DELTA) || defined (alromh87) && defined (DELTA) || defined (hampussandberg) && defined (DELTA) || defined (johnnyr) && defined (DELTA) || defined (ut7) && defined (DELTA)
    endstop_adj[0] = endstop_adj[1] = endstop_adj[2] = 0;
#endif
#if defined (indi-RichCattell) && defined (DELTA)
    delta_diagonal_rod = DEFAULT_DELTA_DIAGONAL_ROD;
#endif
#if defined (upstream) && defined (DELTA) || defined (mattsch) && defined (DELTA) || defined (quikshot) && defined (DELTA) || defined (ErikZalm) && defined (DELTA) || defined (Ognog) && defined (DELTA) || defined (alromh87) && defined (DELTA) || defined (hampussandberg) && defined (DELTA) || defined (oysteinkrog) && defined (DELTA) || defined (johnnyr) && defined (DELTA) || defined (yuroller) && defined (DELTA) || defined (ut7) && defined (DELTA)
    delta_radius= DELTA_RADIUS;
#endif
#if defined (indi-RichCattell) && defined (DELTA)
    endstop_adj[0] = endstop_adj[1] = endstop_adj[2] = 0;
#endif
#if defined (upstream) && defined (DELTA) || defined (mattsch) && defined (DELTA) || defined (quikshot) && defined (DELTA) || defined (ErikZalm) && defined (DELTA) || defined (Ognog) && defined (DELTA) || defined (alromh87) && defined (DELTA) || defined (hampussandberg) && defined (DELTA) || defined (oysteinkrog) && defined (DELTA) || defined (johnnyr) && defined (DELTA) || defined (yuroller) && defined (DELTA) || defined (ut7) && defined (DELTA)
    delta_diagonal_rod= DELTA_DIAGONAL_ROD;
#endif
#if defined (indi-RichCattell) && defined (DELTA)
    tower_adj[0] = tower_adj[1] = tower_adj[2] = tower_adj[3] = tower_adj[4] = tower_adj[5] = 0;
#endif
#if defined (upstream) && defined (DELTA) || defined (mattsch) && defined (DELTA) || defined (quikshot) && defined (DELTA) || defined (ErikZalm) && defined (DELTA) || defined (Ognog) && defined (DELTA) || defined (alromh87) && defined (DELTA) || defined (hampussandberg) && defined (DELTA) || defined (oysteinkrog) && defined (DELTA) || defined (johnnyr) && defined (DELTA) || defined (yuroller) && defined (DELTA) || defined (ut7) && defined (DELTA)
    delta_segments_per_second= DELTA_SEGMENTS_PER_SECOND;
#endif
#if defined (indi-RichCattell) && defined (DELTA)
    max_pos[2] = MANUAL_Z_HOME_POS;
#endif
#if defined (upstream) && defined (DELTA) || defined (mattsch) && defined (DELTA) || defined (quikshot) && defined (DELTA) || defined (ErikZalm) && defined (DELTA) || defined (Ognog) && defined (DELTA) || defined (alromh87) && defined (DELTA) || defined (hampussandberg) && defined (DELTA) || defined (oysteinkrog) && defined (DELTA) || defined (johnnyr) && defined (DELTA) || defined (yuroller) && defined (DELTA) || defined (ut7) && defined (DELTA)
    recalc_delta_settings(delta_radius, delta_diagonal_rod);
#endif
#if defined (indi-RichCattell) && defined (DELTA)
    set_default_z_probe_offset();
    set_delta_constants();
#endif
#if defined (upstream) && defined (ULTIPANEL) || defined (indi-RichCattell) && defined (ULTIPANEL) || defined (mattsch) && defined (ULTIPANEL) || defined (oliv3r) && defined (ULTIPANEL) || defined (quikshot) && defined (ULTIPANEL) || defined (ErikZalm) && defined (ULTIPANEL) || defined (Ognog) && defined (ULTIPANEL) || defined (alromh87) && defined (ULTIPANEL) || defined (akadamson) && defined (ULTIPANEL) || defined (hampussandberg) && defined (ULTIPANEL) || defined (drsdre) && defined (ULTIPANEL) || defined (indi-3DR) && defined (ULTIPANEL) || defined (gregor2005) && defined (ULTIPANEL) || defined (oysteinkrog) && defined (ULTIPANEL) || defined (johnnyr) && defined (ULTIPANEL) || defined (yuroller) && defined (ULTIPANEL) || defined (ut7) && defined (ULTIPANEL)
    plaPreheatHotendTemp = PLA_PREHEAT_HOTEND_TEMP;
    plaPreheatHPBTemp = PLA_PREHEAT_HPB_TEMP;
    plaPreheatFanSpeed = PLA_PREHEAT_FAN_SPEED;
    absPreheatHotendTemp = ABS_PREHEAT_HOTEND_TEMP;
    absPreheatHPBTemp = ABS_PREHEAT_HPB_TEMP;
    absPreheatFanSpeed = ABS_PREHEAT_FAN_SPEED;
#endif
#if defined (upstream) && defined (ENABLE_AUTO_BED_LEVELING) || defined (mattsch) && defined (ENABLE_AUTO_BED_LEVELING) || defined (quikshot) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ErikZalm) && defined (ENABLE_AUTO_BED_LEVELING) || defined (Ognog) && defined (ENABLE_AUTO_BED_LEVELING) || defined (alromh87) && defined (ENABLE_AUTO_BED_LEVELING) || defined (hampussandberg) && defined (ENABLE_AUTO_BED_LEVELING) || defined (oysteinkrog) && defined (ENABLE_AUTO_BED_LEVELING) || defined (johnnyr) && defined (ENABLE_AUTO_BED_LEVELING) || defined (yuroller) && defined (ENABLE_AUTO_BED_LEVELING) || defined (ut7) && defined (ENABLE_AUTO_BED_LEVELING)
    zprobe_zoffset = -Z_PROBE_OFFSET_FROM_EXTRUDER;
#endif
#if defined (upstream) && defined (DOGLCD) || defined (indi-RichCattell) && defined (DOGLCD) || defined (mattsch) && defined (DOGLCD) || defined (quikshot) && defined (DOGLCD) || defined (ErikZalm) && defined (DOGLCD) || defined (Ognog) && defined (DOGLCD) || defined (alromh87) && defined (DOGLCD) || defined (hampussandberg) && defined (DOGLCD) || defined (oysteinkrog) && defined (DOGLCD) || defined (johnnyr) && defined (DOGLCD) || defined (yuroller) && defined (DOGLCD) || defined (ut7) && defined (DOGLCD)
    lcd_contrast = DEFAULT_LCD_CONTRAST;
#endif
#if defined (upstream) && defined (PIDTEMP) || defined (indi-RichCattell) && defined (PIDTEMP) || defined (mattsch) && defined (PIDTEMP) || defined (oliv3r) && defined (PIDTEMP) || defined (quikshot) && defined (PIDTEMP) || defined (ErikZalm) && defined (PIDTEMP) || defined (Ognog) && defined (PIDTEMP) || defined (alromh87) && defined (PIDTEMP) || defined (akadamson) && defined (PIDTEMP) || defined (hampussandberg) && defined (PIDTEMP) || defined (drsdre) && defined (PIDTEMP) || defined (indi-3DR) && defined (PIDTEMP) || defined (gregor2005) && defined (PIDTEMP) || defined (oysteinkrog) && defined (PIDTEMP) || defined (johnnyr) && defined (PIDTEMP) || defined (yuroller) && defined (PIDTEMP) || defined (ut7) && defined (PIDTEMP)
    Kp = DEFAULT_Kp;
#endif
#if defined (akadamson) && defined (PIDTEMP) || defined (drsdre) && defined (PIDTEMP) || defined (indi-3DR) && defined (PIDTEMP)
    Ki = (DEFAULT_Ki*PID_dT);
#endif
#if defined (upstream) && defined (PIDTEMP) || defined (indi-RichCattell) && defined (PIDTEMP) || defined (mattsch) && defined (PIDTEMP) || defined (oliv3r) && defined (PIDTEMP) || defined (quikshot) && defined (PIDTEMP) || defined (ErikZalm) && defined (PIDTEMP) || defined (Ognog) && defined (PIDTEMP) || defined (alromh87) && defined (PIDTEMP) || defined (hampussandberg) && defined (PIDTEMP) || defined (gregor2005) && defined (PIDTEMP) || defined (oysteinkrog) && defined (PIDTEMP) || defined (johnnyr) && defined (PIDTEMP) || defined (yuroller) && defined (PIDTEMP) || defined (ut7) && defined (PIDTEMP)
    Ki = scalePID_i(DEFAULT_Ki);
#endif
#if defined (akadamson) && defined (PIDTEMP) || defined (drsdre) && defined (PIDTEMP) || defined (indi-3DR) && defined (PIDTEMP)
    Kd = (DEFAULT_Kd/PID_dT);
#endif
#if defined (upstream) && defined (PIDTEMP) || defined (indi-RichCattell) && defined (PIDTEMP) || defined (mattsch) && defined (PIDTEMP) || defined (oliv3r) && defined (PIDTEMP) || defined (quikshot) && defined (PIDTEMP) || defined (ErikZalm) && defined (PIDTEMP) || defined (Ognog) && defined (PIDTEMP) || defined (alromh87) && defined (PIDTEMP) || defined (hampussandberg) && defined (PIDTEMP) || defined (gregor2005) && defined (PIDTEMP) || defined (oysteinkrog) && defined (PIDTEMP) || defined (johnnyr) && defined (PIDTEMP) || defined (yuroller) && defined (PIDTEMP) || defined (ut7) && defined (PIDTEMP)
    Kd = scalePID_d(DEFAULT_Kd);
// call updatePID (similar to when we have processed M301)
    updatePID();
#endif
#if defined (upstream) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (indi-RichCattell) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (mattsch) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (oliv3r) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (quikshot) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (ErikZalm) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (Ognog) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (alromh87) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (akadamson) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (hampussandberg) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (drsdre) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (indi-3DR) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (gregor2005) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (oysteinkrog) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (johnnyr) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (yuroller) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) ) || defined (ut7) && (defined (PIDTEMP) && defined (PID_ADD_EXTRUSION_RATE) )
    Kc = DEFAULT_Kc;
#endif
#if defined (upstream) && defined (PIDTEMP) || defined (indi-RichCattell) && defined (PIDTEMP) || defined (mattsch) && defined (PIDTEMP) || defined (oliv3r) && defined (PIDTEMP) || defined (quikshot) && defined (PIDTEMP) || defined (ErikZalm) && defined (PIDTEMP) || defined (Ognog) && defined (PIDTEMP) || defined (alromh87) && defined (PIDTEMP) || defined (akadamson) && defined (PIDTEMP) || defined (hampussandberg) && defined (PIDTEMP) || defined (drsdre) && defined (PIDTEMP) || defined (indi-3DR) && defined (PIDTEMP) || defined (gregor2005) && defined (PIDTEMP) || defined (oysteinkrog) && defined (PIDTEMP) || defined (johnnyr) && defined (PIDTEMP) || defined (yuroller) && defined (PIDTEMP) || defined (ut7) && defined (PIDTEMP)
//PID_ADD_EXTRUSION_RATE
#endif
//PIDTEMP
#if defined (oliv3r)
    float tmp_motor_current_setting[]=DEFAULT_PWM_MOTOR_CURRENT;
#endif
#if defined (upstream) && defined (FWRETRACT) || defined (oysteinkrog) && defined (FWRETRACT) || defined (yuroller) && defined (FWRETRACT)
    autoretract_enabled = false;
#endif
#if defined (oliv3r)
    motor_current_setting[0] = tmp_motor_current_setting[0];
#endif
#if defined (upstream) && defined (FWRETRACT) || defined (oysteinkrog) && defined (FWRETRACT) || defined (yuroller) && defined (FWRETRACT)
    retract_length = RETRACT_LENGTH;
#endif
#if defined (oliv3r)
    motor_current_setting[1] = tmp_motor_current_setting[1];
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (FWRETRACT) ) || defined (oysteinkrog) && (EXTRUDERS > 1 && defined (FWRETRACT) ) || defined (yuroller) && (EXTRUDERS > 1 && defined (FWRETRACT) )
    retract_length_swap = RETRACT_LENGTH_SWAP;
#endif
#if defined (oliv3r)
    motor_current_setting[2] = tmp_motor_current_setting[2];
#endif
#if defined (upstream) && defined (FWRETRACT) || defined (oysteinkrog) && defined (FWRETRACT) || defined (yuroller) && defined (FWRETRACT)
    retract_feedrate = RETRACT_FEEDRATE;
#endif
#if defined (oliv3r) && defined (ENABLE_ULTILCD2)
    led_brightness_level = 100;
#endif
#if defined (upstream) && defined (FWRETRACT) || defined (oysteinkrog) && defined (FWRETRACT) || defined (yuroller) && defined (FWRETRACT)
    retract_zlift = RETRACT_ZLIFT;
#endif
#if defined (oliv3r) && defined (ENABLE_ULTILCD2)
    led_mode = LED_MODE_ALWAYS_ON;
#endif
#if defined (upstream) && defined (FWRETRACT) || defined (oysteinkrog) && defined (FWRETRACT) || defined (yuroller) && defined (FWRETRACT)
    retract_recover_length = RETRACT_RECOVER_LENGTH;
#endif
#if defined (oliv3r)
    retract_length = 4.5;
#endif
#if defined (upstream) && (EXTRUDERS > 1 && defined (FWRETRACT) ) || defined (oysteinkrog) && (EXTRUDERS > 1 && defined (FWRETRACT) ) || defined (yuroller) && (EXTRUDERS > 1 && defined (FWRETRACT) )
    retract_recover_length_swap = RETRACT_RECOVER_LENGTH_SWAP;
#endif
#if defined (oliv3r)
    retract_feedrate = 25 * 60;
#endif
#if defined (upstream) && defined (FWRETRACT) || defined (oysteinkrog) && defined (FWRETRACT) || defined (yuroller) && defined (FWRETRACT)
    retract_recover_feedrate = RETRACT_RECOVER_FEEDRATE;
#endif
#if defined (upstream) || defined (oysteinkrog) || defined (yuroller)
    volumetric_enabled = false;
    filament_size[0] = DEFAULT_NOMINAL_FILAMENT_DIA;
#endif
#if defined (upstream) && EXTRUDERS > 1 || defined (oysteinkrog) && EXTRUDERS > 1 || defined (yuroller) && EXTRUDERS > 1
    filament_size[1] = DEFAULT_NOMINAL_FILAMENT_DIA;
#endif
#if defined (upstream) && (EXTRUDERS > 2 && EXTRUDERS > 1 ) || defined (oysteinkrog) && (EXTRUDERS > 2 && EXTRUDERS > 1 ) || defined (yuroller) && (EXTRUDERS > 2 && EXTRUDERS > 1 )
    filament_size[2] = DEFAULT_NOMINAL_FILAMENT_DIA;
#endif
#if defined (upstream) || defined (oysteinkrog) || defined (yuroller)
    calculate_volumetric_multipliers();
#endif
#if defined (upstream) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (Ognog) || defined (alromh87) || defined (hampussandberg) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Hardcoded Default Settings Loaded");
#endif
}
#endif

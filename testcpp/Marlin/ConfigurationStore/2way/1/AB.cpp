#if defined (A) || defined (B)
void Config_StoreSettings() {
#if defined (A) && defined (FWRETRACT)
    EEPROM_WRITE_VAR(i,autoretract_enabled);
#endif
#if defined (A) && defined (FWRETRACT)
    EEPROM_WRITE_VAR(i,retract_length);
#endif
#endif
#if defined (A) && (EXTRUDERS > 1 && defined (FWRETRACT) )#if defined (A) && (EXTRUDERS > 1 && defined (FWRETRACT) )
    EEPROM_WRITE_VAR(i,retract_length_swap);
#endif
#if defined (A) && defined (FWRETRACT)
    EEPROM_WRITE_VAR(i,retract_feedrate);
#endif
#if defined (A) && defined (FWRETRACT)
    EEPROM_WRITE_VAR(i,retract_zlift);
#endif
#if defined (A) && defined (FWRETRACT)
    EEPROM_WRITE_VAR(i,retract_recover_length);
#endif
#endif
#if defined (A) && (EXTRUDERS > 1 && defined (FWRETRACT) )#if defined (A) && (EXTRUDERS > 1 && defined (FWRETRACT) )
    EEPROM_WRITE_VAR(i,retract_recover_length_swap);
#endif
#if defined (A) && defined (FWRETRACT)
    EEPROM_WRITE_VAR(i,retract_recover_feedrate);
#endif
#endif
#if defined (A) && #if defined (A) &&
// Save filament sizes
#endif
#if defined (A) &&
    EEPROM_WRITE_VAR(i, volumetric_enabled);
#endif
#if defined (A) &&
    EEPROM_WRITE_VAR(i, filament_size[0]);
#endif
#endif
#if defined (A) && EXTRUDERS > 1#if defined (A) && EXTRUDERS > 1
    EEPROM_WRITE_VAR(i, filament_size[1]);
#endif
#if defined (A) && (EXTRUDERS > 2 && EXTRUDERS > 1 )
    EEPROM_WRITE_VAR(i, filament_size[2]);
#endif
#endif
    char ver2[4]=EEPROM_VERSION;
    i=EEPROM_OFFSET;
    EEPROM_WRITE_VAR(i,ver2);
// validate data
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Settings Stored");
}
#endif

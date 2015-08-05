


void Config_StoreSettings()
{
  EEPROM_WRITE_VAR(i, volumetric_enabled);
  EEPROM_WRITE_VAR(i, filament_size[0]);







  char ver2[4]=EEPROM_VERSION;
  i=EEPROM_OFFSET;
  EEPROM_WRITE_VAR(i,ver2);
  SERIAL_ECHO_START;
  SERIAL_ECHOLNPGM("Settings Stored");
}

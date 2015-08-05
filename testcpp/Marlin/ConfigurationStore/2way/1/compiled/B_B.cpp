
void Config_StoreSettings()
{

  char ver2[4]=EEPROM_VERSION;
  i=EEPROM_OFFSET;
  EEPROM_WRITE_VAR(i,ver2);
  SERIAL_ECHO_START;
  SERIAL_ECHOLNPGM("Settings Stored");
}

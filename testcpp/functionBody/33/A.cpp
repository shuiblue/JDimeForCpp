<<<<<<< origin/develop
<<<<<<< origin/develop
<<<<<<< origin/develop
<<<<<<< origin/develop
<<<<<<< origin/develop
/* -*- c++ -*- */
=======
>>>>>>> HEAD~18
=======
/* -*- c++ -*- */
>>>>>>> HEAD~16
=======
>>>>>>> HEAD~15

void setup()
{
  setup_killpin();
 
 
  

#ifdef STAT_LED_RED
  pinMode(STAT_LED_RED, OUTPUT);
  digitalWrite(STAT_LED_RED, LOW); // turn it off
#endif
#ifdef STAT_LED_BLUE
  pinMode(STAT_LED_BLUE, OUTPUT);
  digitalWrite(STAT_LED_BLUE, LOW); // turn it off
#endif
  
}






=======
void CardReader::initsd()
{
  cardOK = false;
  if(root.isOpen())
    root.close();
  if (!card.init(SPI_FULL_SPEED,SDSS))
  {
    //if (!card.init(SPI_HALF_SPEED,SDSS))
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM(MSG_SD_INIT_FAIL);
  }
  else if (!volume.init(&card))
  {
    SERIAL_ERROR_START;
    SERIAL_ERRORLNPGM(MSG_SD_VOL_INIT_FAIL);
  }
  else if (!root.openRoot(&volume)) 
  {
    SERIAL_ERROR_START;
    SERIAL_ERRORLNPGM(MSG_SD_OPENROOT_FAIL);
  }
  else 
  {
    cardOK = true;
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM(MSG_SD_CARD_OK);
  }
  workDir=root;
  curDir=&root;
  /*
  if(!workDir.openRoot(&volume))
  {
    SERIAL_ECHOLNPGM(MSG_SD_WORKDIR_FAIL);
  }
  */
>>>>>>> HEAD~19

<<<<<<< origin/develop
=======

#if TEMP_SENSOR_0 != 0 && (TEMP_SENSOR_1 != 0 || TEMP_SENSOR_2 != 0 || TEMP_SENSOR_3 != 0 || TEMP_SENSOR_BED != 0)

  static void lcd_preheat_pla_menu() {
    START_MENU();
    MENU_ITEM(back, MSG_PREPARE, lcd_prepare_menu);
    #if EXTRUDERS == 1
      MENU_ITEM(function, MSG_PREHEAT_PLA, lcd_preheat_pla0);
    #else
      MENU_ITEM(function, MSG_PREHEAT_PLA_N MSG_H1, lcd_preheat_pla0);
      MENU_ITEM(function, MSG_PREHEAT_PLA_N MSG_H2, lcd_preheat_pla1);
      #if EXTRUDERS > 2
        MENU_ITEM(function, MSG_PREHEAT_PLA_N MSG_H3, lcd_preheat_pla2);
        #if EXTRUDERS > 3
          MENU_ITEM(function, MSG_PREHEAT_PLA_N MSG_H4, lcd_preheat_pla3);
        #endif
      #endif
      MENU_ITEM(function, MSG_PREHEAT_PLA_ALL, lcd_preheat_pla0123);
    #endif
    #if TEMP_SENSOR_BED != 0
      MENU_ITEM(function, MSG_PREHEAT_PLA_BEDONLY, lcd_preheat_pla_bedonly);
    #endif
    END_MENU();
  }

  static void lcd_preheat_abs_menu() {
    START_MENU();
    MENU_ITEM(back, MSG_PREPARE, lcd_prepare_menu);
    #if EXTRUDERS == 1
      MENU_ITEM(function, MSG_PREHEAT_ABS, lcd_preheat_abs0);
    #else
      MENU_ITEM(function, MSG_PREHEAT_ABS_N MSG_H1, lcd_preheat_abs0);
      MENU_ITEM(function, MSG_PREHEAT_ABS_N MSG_H2, lcd_preheat_abs1);
      #if EXTRUDERS > 2
        MENU_ITEM(function, MSG_PREHEAT_ABS_N MSG_H3, lcd_preheat_abs2);
        #if EXTRUDERS > 3
          MENU_ITEM(function, MSG_PREHEAT_ABS_N MSG_H4, lcd_preheat_abs3);
        #endif
      #endif
      MENU_ITEM(function, MSG_PREHEAT_ABS_ALL, lcd_preheat_abs0123);
    #endif
    #if TEMP_SENSOR_BED != 0
      MENU_ITEM(function, MSG_PREHEAT_ABS_BEDONLY, lcd_preheat_abs_bedonly);
    #endif
    END_MENU();
>>>>>>> HEAD~7
}
<<<<<<< origin/develop
=======




>>>>>>> HEAD~9
=======

<<<<<<< origin/develop
>>>>>>> HEAD~8
=======
#endif // TEMP_SENSOR_0 && (TEMP_SENSOR_1 || TEMP_SENSOR_2 || TEMP_SENSOR_3 || TEMP_SENSOR_BED)



>>>>>>> HEAD~7

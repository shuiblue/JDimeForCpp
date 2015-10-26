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
  
  // STRING_VERSION_CONFIG_H
  
  
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
=======
static void lcd_preheat_pla_menu()
>>>>>>> HEAD~7
{
    START_MENU();
    MENU_ITEM(back, MSG_PREPARE, lcd_prepare_menu);
    MENU_ITEM(function, MSG_PREHEAT_PLA0, lcd_preheat_pla0);
#if TEMP_SENSOR_1 != 0 //2 extruder preheat
    MENU_ITEM(function, MSG_PREHEAT_PLA1, lcd_preheat_pla1);
#endif //2 extruder preheat
#if TEMP_SENSOR_2 != 0 //3 extruder preheat
    MENU_ITEM(function, MSG_PREHEAT_PLA2, lcd_preheat_pla2);
#endif //3 extruder preheat
#if TEMP_SENSOR_1 != 0 || TEMP_SENSOR_2 != 0 //all extruder preheat
    MENU_ITEM(function, MSG_PREHEAT_PLA012, lcd_preheat_pla012);
#endif //2 extruder preheat
#if TEMP_SENSOR_BED != 0
    MENU_ITEM(function, MSG_PREHEAT_PLA_BEDONLY, lcd_preheat_pla_bedonly);
#endif
    END_MENU();
  }

static void lcd_preheat_abs_menu()
  {
    START_MENU();
    MENU_ITEM(back, MSG_PREPARE, lcd_prepare_menu);
    MENU_ITEM(function, MSG_PREHEAT_ABS0, lcd_preheat_abs0);
#if TEMP_SENSOR_1 != 0 //2 extruder preheat
    MENU_ITEM(function, MSG_PREHEAT_ABS1, lcd_preheat_abs1);
#endif //2 extruder preheat
#if TEMP_SENSOR_2 != 0 //3 extruder preheat
    MENU_ITEM(function, MSG_PREHEAT_ABS2, lcd_preheat_abs2);
#endif //3 extruder preheat
#if TEMP_SENSOR_1 != 0 || TEMP_SENSOR_2 != 0 //all extruder preheat
    MENU_ITEM(function, MSG_PREHEAT_ABS012, lcd_preheat_abs012);
#endif //2 extruder preheat
#if TEMP_SENSOR_BED != 0
    MENU_ITEM(function, MSG_PREHEAT_ABS_BEDONLY, lcd_preheat_abs_bedonly);
#endif
    END_MENU();
  }
<<<<<<< origin/develop
  */
>>>>>>> HEAD~19

<<<<<<< origin/develop
}
<<<<<<< origin/develop
=======




>>>>>>> HEAD~9
=======
=======




>>>>>>> HEAD~7

>>>>>>> HEAD~8

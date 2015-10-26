
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
  }

#endif // TEMP_SENSOR_0 && (TEMP_SENSOR_1 || TEMP_SENSOR_2 || TEMP_SENSOR_3 || TEMP_SENSOR_BED)




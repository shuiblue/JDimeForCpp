#if defined (upstreamBeforeMerge) || defined (forkBeforeMerge)
/**
 * Russian
 *
 * LCD Menu Messages
 * Please note these are limited to 17 characters!
 *
 */
#endif
#if defined (upstreamBeforeMerge) && !defined (LANGUAGE_RU_H) || defined (forkBeforeMerge) && !defined (LANGUAGE_RU_H)
    #define LANGUAGE_RU_H
    #define LANGUAGE_RU
    #define WELCOME_MSG                         MACHINE_NAME "ÐÐ¾ÑÐ¾Ð²."
    #define MSG_SD_INSERTED                     "ÐÐ°ÑÑÐ° Ð²ÑÑÐ°Ð²Ð»ÐµÐ½Ð°"
    #define MSG_SD_REMOVED                      "ÐÐ°ÑÑÐ° Ð¸Ð·Ð²Ð»ÐµÑÐµÐ½Ð°"
    #define MSG_MAIN                            "ÐÐµÐ½Ñ \003"
    #define MSG_AUTOSTART                       "ÐÐ²ÑÐ¾ÑÑÐ°ÑÑ"
    #define MSG_DISABLE_STEPPERS                "ÐÑÐºÐ». Ð´Ð²Ð¸Ð³Ð°ÑÐµÐ»Ð¸"
    #define MSG_AUTO_HOME                       "ÐÐ°ÑÐºÐ¾Ð²ÐºÐ°"
    #define MSG_SET_HOME_OFFSETS                "Set home offsets"
    #define MSG_SET_ORIGIN                      "ÐÐ°Ð¿Ð¾Ð¼Ð½Ð¸ÑÑ Ð½Ð¾Ð»Ñ"
    #define MSG_PREHEAT_PLA                     "ÐÑÐµÐ´Ð½Ð°Ð³ÑÐµÐ² PLA"
    #define MSG_PREHEAT_PLA0                    "ÐÑÐµÐ´Ð½Ð°Ð³ÑÐµÐ² PLA0"
    #define MSG_PREHEAT_PLA1                    "ÐÑÐµÐ´Ð½Ð°Ð³ÑÐµÐ² PLA1"
    #define MSG_PREHEAT_PLA2                    "ÐÑÐµÐ´Ð½Ð°Ð³ÑÐµÐ² PLA2"
    #define MSG_PREHEAT_PLA012                  "ÐÑÐµÐ´Ð½Ð°Ð³. PLA Ð²ÑÐµ"
    #define MSG_PREHEAT_PLA_BEDONLY             "ÐÑÐµÐ´. PLA ÐÑÐ¾Ð²Ð°ÑÑ"
    #define MSG_PREHEAT_PLA_SETTINGS            "ÐÐ°ÑÑÑÐ¾Ð¹ÐºÐ¸ PLA"
    #define MSG_PREHEAT_ABS                     "ÐÑÐµÐ´Ð½Ð°Ð³ÑÐµÐ² ABS"
    #define MSG_PREHEAT_ABS0                    "ÐÑÐµÐ´Ð½Ð°Ð³ÑÐµÐ² ABS0"
    #define MSG_PREHEAT_ABS1                    "ÐÑÐµÐ´Ð½Ð°Ð³ÑÐµÐ² ABS1"
    #define MSG_PREHEAT_ABS2                    "ÐÑÐµÐ´Ð½Ð°Ð³ÑÐµÐ² ABS2"
    #define MSG_PREHEAT_ABS012                  "ÐÑÐµÐ´Ð½Ð°Ð³. ABS Ð²ÑÐµ "
    #define MSG_PREHEAT_ABS_BEDONLY             "ÐÑÐµÐ´. ABS ÐÑÐ¾Ð²Ð°ÑÑ"
    #define MSG_PREHEAT_ABS_SETTINGS            "ÐÐ°ÑÑÑÐ¾Ð¹ÐºÐ¸ ABS"
    #define MSG_COOLDOWN                        "ÐÑÐ»Ð°Ð¶Ð´ÐµÐ½Ð¸Ðµ"
    #define MSG_SWITCH_PS_ON                    "Switch Power On"
    #define MSG_SWITCH_PS_OFF                   "Switch Power Off"
    #define MSG_EXTRUDE                         "Ð­ÐºÑÑÑÑÐ·Ð¸Ñ"
    #define MSG_RETRACT                         "ÐÑÐºÐ°Ñ"
    #define MSG_MOVE_AXIS                       "ÐÐ²Ð¸Ð¶ÐµÐ½Ð¸Ðµ Ð¿Ð¾ Ð¾ÑÑÐ¼"
    #define MSG_MOVE_X                          "Move X"
    #define MSG_MOVE_Y                          "Move Y"
    #define MSG_MOVE_Z                          "Move Z"
    #define MSG_MOVE_E                          "Extruder"
    #define MSG_MOVE_E1                         "Extruder2"
    #define MSG_MOVE_E2                         "Extruder3"
    #define MSG_MOVE_01MM                       "Move 0.1mm"
    #define MSG_MOVE_1MM                        "Move 1mm"
    #define MSG_MOVE_10MM                       "Move 10mm"
    #define MSG_SPEED                           "Ð¡ÐºÐ¾ÑÐ¾ÑÑÑ:"
    #define MSG_NOZZLE                          "\002 Ð¤Ð¸Ð»ÑÐµÑÐ°:"
    #define MSG_NOZZLE1                         "\002 Ð¤Ð¸Ð»ÑÐµÑÐ°2:"
    #define MSG_NOZZLE2                         "\002 Ð¤Ð¸Ð»ÑÐµÑÐ°3:"
    #define MSG_BED                             "\002 ÐÑÐ¾Ð²Ð°ÑÑ:"
    #define MSG_FAN_SPEED                       "ÐÑÐ»Ð»ÐµÑ:"
    #define MSG_FLOW                            "ÐÐ¾ÑÐ¾Ðº:"
    #define MSG_FLOW0                           " ÐÐ¾ÑÐ¾Ðº0:"
    #define MSG_FLOW1                           " ÐÐ¾ÑÐ¾Ðº1:"
    #define MSG_FLOW2                           " ÐÐ¾ÑÐ¾Ðº2:"
    #define MSG_CONTROL                         "ÐÐ°ÑÑÑÐ¾Ð¹ÐºÐ¸ \003"
    #define MSG_MIN                             "\002 ÐÐ¸Ð½Ð¸Ð¼ÑÐ¼:"
    #define MSG_MAX                             "\002 ÐÐ°ÐºÑÐ¸Ð¼ÑÐ¼:"
    #define MSG_FACTOR                          "\002 Ð¤Ð°ÐºÑÐ¾Ñ:"
    #define MSG_AUTOTEMP                        "Autotemp:"
    #define MSG_ON                              "ÐÐºÐ». "
    #define MSG_OFF                             "ÐÑÐºÐ». "
    #define MSG_PID_P                           "PID-P: "
    #define MSG_PID_I                           "PID-I: "
    #define MSG_PID_D                           "PID-D: "
    #define MSG_PID_C                           "PID-C: "
    #define MSG_ACC                             "Acc:"
    #define MSG_VXY_JERK                        "Vxy-jerk: "
    #define MSG_VZ_JERK                         "Vz-jerk"
    #define MSG_VE_JERK                         "Ve-jerk"
    #define MSG_VMAX                            "Vmax "
    #define MSG_X                               "x:"
    #define MSG_Y                               "y:"
    #define MSG_Z                               "z:"
    #define MSG_E                               "e:"
    #define MSG_VMIN                            "Vmin:"
    #define MSG_VTRAV_MIN                       "VTrav min:"
    #define MSG_AMAX                            "Amax "
    #define MSG_A_RETRACT                       "A-retract:"
    #define MSG_XSTEPS                          "X ÑÐ°Ð³/mm:"
    #define MSG_YSTEPS                          "Y ÑÐ°Ð³/mm:"
    #define MSG_ZSTEPS                          "Z ÑÐ°Ð³/mm:"
    #define MSG_ESTEPS                          "E ÑÐ°Ð³/mm:"
    #define MSG_TEMPERATURE                     "Ð¢ÐµÐ¼Ð¿ÐµÑÐ°ÑÑÑÐ°     \x7E"
    #define MSG_MOTION                          "Ð¡ÐºÐ¾ÑÐ¾ÑÑÐ¸        \x7E"
    #define MSG_VOLUMETRIC                      "Filament"
    #define MSG_VOLUMETRIC_ENABLED		        "E in mm3"
    #define MSG_FILAMENT_SIZE_EXTRUDER_0        "Fil. Dia. 1"
    #define MSG_FILAMENT_SIZE_EXTRUDER_1        "Fil. Dia. 2"
    #define MSG_FILAMENT_SIZE_EXTRUDER_2        "Fil. Dia. 3"
    #define MSG_CONTRAST                        "LCD contrast"
    #define MSG_STORE_EPROM                     "Ð¡Ð¾ÑÑÐ°Ð½Ð¸ÑÑ Ð² EPROM"
    #define MSG_LOAD_EPROM                      "ÐÐ°Ð³ÑÑÐ·. Ð¸Ð· EPROM"
    #define MSG_RESTORE_FAILSAFE                "Ð¡Ð±ÑÐ¾Ñ Ð½Ð°ÑÑÑÐ¾ÐµÐº"
    #define MSG_REFRESH                         "\004ÐÐ±Ð½Ð¾Ð²Ð¸ÑÑ"
    #define MSG_WATCH                           "ÐÐ±Ð·Ð¾Ñ           \003"
    #define MSG_PREPARE                         "ÐÐµÐ¹ÑÑÐ²Ð¸Ñ        \x7E"
    #define MSG_TUNE                            "ÐÐ°ÑÑÑÐ¾Ð¹ÐºÐ¸       \x7E"
    #define MSG_PAUSE_PRINT                     "ÐÑÐ¾Ð´Ð¾Ð»Ð¶Ð¸ÑÑ Ð¿ÐµÑÐ°ÑÑ"
    #define MSG_RESUME_PRINT                    "Ð²Ð¾Ð·Ð¾Ð±Ð½. Ð¿ÐµÑÐ°ÑÑ"
    #define MSG_STOP_PRINT                      "ÐÑÑÐ°Ð½Ð¾Ð²Ð¸ÑÑ Ð¿ÐµÑÐ°ÑÑ"
    #define MSG_CARD_MENU                       "ÐÐµÐ½Ñ ÐºÐ°ÑÑÑ      \x7E"
    #define MSG_NO_CARD                         "ÐÐµÑ ÐºÐ°ÑÑÑ"
    #define MSG_DWELL                           "Ð¡Ð¾Ð½..."
    #define MSG_USERWAIT                        "ÐÐ¶Ð¸Ð´Ð°Ð½Ð¸Ð¸Ðµ"
    #define MSG_RESUMING                        "Resuming print"
    #define MSG_PRINT_ABORTED                   "Print aborted"
    #define MSG_NO_MOVE                         "ÐÐµÑ Ð´Ð²Ð¸Ð¶ÐµÐ½Ð¸Ñ."
    #define MSG_KILLED                          "Ð£ÐÐÐ¢Ð."
    #define MSG_STOPPED                         "ÐÐ¡Ð¢ÐÐÐÐÐÐÐÐ."
    #define MSG_CONTROL_RETRACT                 "ÐÑÐºÐ°Ñ mm:"
    #define MSG_CONTROL_RETRACT_SWAP            "ÑÐ²Ð¾Ð¿ ÐÑÐºÐ°Ñ mm:"
    #define MSG_CONTROL_RETRACTF                "ÐÑÐºÐ°Ñ  V:"
    #define MSG_CONTROL_RETRACT_ZLIFT           "ÐÑÑÐ¶Ð¾Ðº mm:"
    #define MSG_CONTROL_RETRACT_RECOVER         "ÐÐ¾Ð·Ð²ÑÐ°Ñ +mm:"
    #define MSG_CONTROL_RETRACT_RECOVER_SWAP    "ÑÐ²Ð¾Ð¿ ÐÐ¾Ð·Ð²ÑÐ°Ñ +mm:"
    #define MSG_CONTROL_RETRACT_RECOVERF        "ÐÐ¾Ð·Ð²ÑÐ°Ñ  V:"
    #define MSG_AUTORETRACT                     "ÐÐ²ÑÐ¾ÐÑÐºÐ°Ñ:"
    #define MSG_FILAMENTCHANGE                  "Change filament"
    #define MSG_INIT_SDCARD                     "Init. SD-Card"
    #define MSG_CNG_SDCARD                      "Change SD-Card"
    #define MSG_ZPROBE_OUT                      "Z probe out. bed"
    #define MSG_POSITION_UNKNOWN                "Home X/Y before Z"
    #define MSG_ZPROBE_ZOFFSET                  "Z Offset"
    #define MSG_BABYSTEP_X                      "Babystep X"
    #define MSG_BABYSTEP_Y                      "Babystep Y"
    #define MSG_BABYSTEP_Z                      "Babystep Z"
    #define MSG_ENDSTOP_ABORT                   "Endstop abort"
    #define MSG_RECTRACT                        "ÐÑÐºÐ°Ñ Ð¿Ð¾Ð´Ð°ÑÐ¸    \x7E"
#endif
#if defined (upstreamBeforeMerge) && (!defined (LANGUAGE_RU_H) && defined (DELTA_CALIBRATION_MENU) ) || defined (forkBeforeMerge) && (!defined (LANGUAGE_RU_H) && defined (DELTA_CALIBRATION_MENU) )
    #define MSG_DELTA_CALIBRATE             "Delta Calibration"
    #define MSG_DELTA_CALIBRATE_X           "Calibrate X"
    #define MSG_DELTA_CALIBRATE_Y           "Calibrate Y"
    #define MSG_DELTA_CALIBRATE_Z           "Calibrate Z"
    #define MSG_DELTA_CALIBRATE_CENTER      "Calibrate Center"
#endif
#if defined (upstreamBeforeMerge) && !defined (LANGUAGE_RU_H) || defined (forkBeforeMerge) && !defined (LANGUAGE_RU_H)
    // DELTA_CALIBRATION_MENU
#endif
#if defined (upstreamBeforeMerge) || defined (forkBeforeMerge)
    // LANGUAGE_RU_H
#endif

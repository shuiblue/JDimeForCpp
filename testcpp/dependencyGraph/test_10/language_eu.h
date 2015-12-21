/**
 * Basque-Euskera
 *
 * LCD Menu Messages
 * Please note these are limited to 17 characters!
 *
 */
#ifndef LANGUAGE_EU_H
#define LANGUAGE_EU_H

#define WELCOME_MSG                         MACHINE_NAME " prest."
#define MSG_SD_INSERTED                     "Txartela sartuta"
#define MSG_SD_REMOVED                      "Txartela kenduta"
#define MSG_MAIN                            "Menu nagusia"
#define MSG_AUTOSTART                       "Auto hasiera"
#define MSG_DISABLE_STEPPERS                "Itzali motoreak"
#define MSG_AUTO_HOME                       "Hasierara joan"
#define MSG_SET_HOME_OFFSETS                "Set home offsets"
#define MSG_SET_ORIGIN                      "Hasiera ipini"
#define MSG_PREHEAT_PLA                     "Aurreberotu PLA"
#define MSG_PREHEAT_PLA0                    "Aurreberotu PLA1"
#define MSG_PREHEAT_PLA1                    "Aurreberotu PLA2"
#define MSG_PREHEAT_PLA2                    "Aurreberotu PLA3"
#define MSG_PREHEAT_PLA012                  "Berotu PLA Guztia"
#define MSG_PREHEAT_PLA_BEDONLY             "Berotu PLA Ohea"
#define MSG_PREHEAT_PLA_SETTINGS            "Berotu PLA Konfig"
#define MSG_PREHEAT_ABS                     "Aurreberotu ABS"
#define MSG_PREHEAT_ABS0                    "Aurreberotu ABS 1"
#define MSG_PREHEAT_ABS1                    "Aurreberotu ABS 2"
#define MSG_PREHEAT_ABS2                    "Aurreberotu ABS 3"
#define MSG_PREHEAT_ABS012                  "Berotu ABS Guztia"
#define MSG_PREHEAT_ABS_BEDONLY             "Berotu ABS Ohea"
#define MSG_PREHEAT_ABS_SETTINGS            "Berotu ABS Konfig"
#define MSG_COOLDOWN                        "Hoztu"
#define MSG_SWITCH_PS_ON                    "Energia piztu"
#define MSG_SWITCH_PS_OFF                   "Energia itzali"
#define MSG_EXTRUDE                         "Estruitu"
#define MSG_RETRACT                         "Atzera eragin"
#define MSG_MOVE_AXIS                       "Ardatzak mugitu"
#define MSG_MOVE_X                          "Mugitu X"
#define MSG_MOVE_Y                          "Mugitu Y"
#define MSG_MOVE_Z                          "Mugitu Z"
#define MSG_MOVE_E                          "Estrusorea"
#define MSG_MOVE_E1                         "Estrusorea2"
#define MSG_MOVE_E2                         "Estrusorea3"
#define MSG_MOVE_01MM                       "Mugitu 0.1mm"
#define MSG_MOVE_1MM                        "Mugitu 1mm"
#define MSG_MOVE_10MM                       "Mugitu 10mm"
#define MSG_SPEED                           "Abiadura"
#define MSG_NOZZLE                          "Pita"
#define MSG_NOZZLE1                         "Pita2"
#define MSG_NOZZLE2                         "Pita3"
#define MSG_BED                             "Ohea"
#define MSG_FAN_SPEED                       "Haizagailua"
#define MSG_FLOW                            "Fluxua"
#define MSG_FLOW0                           "Fluxua 0"
#define MSG_FLOW1                           "Fluxua 1"
#define MSG_FLOW2                           "Fluxua 2"
#define MSG_CONTROL                         "Kontrola"
#define MSG_MIN                             " \002 Min"
#define MSG_MAX                             " \002 Max"
#define MSG_FACTOR                          " \002 Faktorea"
#define MSG_AUTOTEMP                        "Auto tenperatura"
#define MSG_ON                              "On "
#define MSG_OFF                             "Off"
#define MSG_PID_P                           "PID-P"
#define MSG_PID_I                           "PID-I"
#define MSG_PID_D                           "PID-D"
#define MSG_PID_C                           "PID-C"
#define MSG_ACC                             "Azelerazioa"
#define MSG_VXY_JERK                        "Vxy-astindua"
#define MSG_VZ_JERK                         "Vz-astindua"
#define MSG_VE_JERK                         "Ve-astindua"
#define MSG_VMAX                            "Vmax "
#define MSG_X                               "x"
#define MSG_Y                               "y"
#define MSG_Z                               "z"
#define MSG_E                               "e"
#define MSG_VMIN                            "Vmin"
#define MSG_VTRAV_MIN                       "VTrav min"
#define MSG_AMAX                            "Amax "
#define MSG_A_RETRACT                       "A-retrakt"
#define MSG_XSTEPS                          "X pausoak/mm"
#define MSG_YSTEPS                          "Y pausoak/mm"
#define MSG_ZSTEPS                          "Z pausoak/mm"
#define MSG_ESTEPS                          "E pausoak/mm"
#define MSG_TEMPERATURE                     "Tenperatura"
#define MSG_MOTION                          "Mugimendua"
#define MSG_CONTRAST                        "LCD kontrastea"
#define MSG_STORE_EPROM                     "Gorde memoria"
#define MSG_LOAD_EPROM                      "Kargatu memoria"
#define MSG_RESTORE_FAILSAFE                "Larri. berriz."
#define MSG_REFRESH                         "Berriz kargatu"
#define MSG_WATCH                           "Pantaila info"
#define MSG_PREPARE                         "Prestatu"
#define MSG_TUNE                            "Doitu"
#define MSG_PAUSE_PRINT                     "Pausatu inprimak."
#define MSG_RESUME_PRINT                    "Jarraitu inprima."
#define MSG_STOP_PRINT                      "Gelditu inprima."
#define MSG_CARD_MENU                       "SD-tik inprimatu"
#define MSG_NO_CARD                         "Ez dago txartelik"
#define MSG_DWELL                           "Lo egin..."
#define MSG_USERWAIT                        "Aginduak zain..."
#define MSG_RESUMING                        "Jarraitzen inpri."
#define MSG_PRINT_ABORTED                   "Print aborted"
#define MSG_NO_MOVE                         "Mugimendu gabe"
#define MSG_KILLED                          "LARRIALDI GELDIA"
#define MSG_STOPPED                         "GELDITUTA. "
#define MSG_CONTROL_RETRACT                 "Atzera egin mm"
#define MSG_CONTROL_RETRACT_SWAP            "Swap Atzera egin mm"
#define MSG_CONTROL_RETRACTF                "Atzera egin V"
#define MSG_CONTROL_RETRACT_ZLIFT           "Igo mm"
#define MSG_CONTROL_RETRACT_RECOVER         "Atzera egin +mm"
#define MSG_CONTROL_RETRACT_RECOVER_SWAP    "Swap Atzera egin +mm"
#define MSG_CONTROL_RETRACT_RECOVERF        "Atzera egin V"
#define MSG_AUTORETRACT                     "Atzera egin"
#define MSG_FILAMENTCHANGE                  "Aldatu filament."
#define MSG_INIT_SDCARD                     "Hasieratu txartela"
#define MSG_CNG_SDCARD                      "Aldatu txartela"
#define MSG_ZPROBE_OUT                      "Z ohe hasiera"
#define MSG_POSITION_UNKNOWN                "Posizio ezezaguna"
#define MSG_ZPROBE_ZOFFSET                  "Z konpentsatu"
#define MSG_BABYSTEP_X                      "Babystep X"
#define MSG_BABYSTEP_Y                      "Babystep Y"
#define MSG_BABYSTEP_Z                      "Babystep Z"
#define MSG_ENDSTOP_ABORT                   "Endstop deuseztat"

#define MSG_RECTRACT                        "Atzera eragin"

#endif // LANGUAGE_EU_H


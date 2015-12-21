/**
 * Aragonese
 *
 * LCD Menu Messages
 * Please note these are limited to 17 characters!
 *
 */
#ifndef LANGUAGE_AN_H
#define LANGUAGE_AN_H

#define WELCOME_MSG                         MACHINE_NAME " parada."
#define MSG_SD_INSERTED                     "Tarcheta colocada"
#define MSG_SD_REMOVED                      "Tarcheta retirada"
#define MSG_MAIN                            "Menu prencipal"
#define MSG_AUTOSTART                       " Autostart"
#define MSG_DISABLE_STEPPERS                "Amortar motors"
#define MSG_AUTO_HOME                       "Levar a l'orichen"
#define MSG_SET_HOME_OFFSETS                "Set home offsets"
#define MSG_SET_ORIGIN                      "Establir zero"
#define MSG_PREHEAT_PLA                     "Precalentar PLA"
#define MSG_PREHEAT_PLA0                    "Precalentar PLA0"
#define MSG_PREHEAT_PLA1                    "Precalentar PLA1"
#define MSG_PREHEAT_PLA2                    "Precalentar PLA2"
#define MSG_PREHEAT_PLA012                  "Precalentar PLA a"
#define MSG_PREHEAT_PLA_BEDONLY             "Prec. PLA Base"
#define MSG_PREHEAT_PLA_SETTINGS            "Achustar tem. PLA"
#define MSG_PREHEAT_ABS                     "Precalentar ABS"
#define MSG_PREHEAT_ABS0                    "Precalentar ABS0"
#define MSG_PREHEAT_ABS1                    "Precalentar ABS1"
#define MSG_PREHEAT_ABS2                    "Precalentar ABS2"
#define MSG_PREHEAT_ABS012                  "Precalentar ABS a"
#define MSG_PREHEAT_ABS_BEDONLY             "Prec. ABS Base"
#define MSG_PREHEAT_ABS_SETTINGS            "Achustar tem. ABS"
#define MSG_COOLDOWN                        "Enfriar"
#define MSG_SWITCH_PS_ON                    "Enchegar Fuent"
#define MSG_SWITCH_PS_OFF                   "Desenchegar Fuent"
#define MSG_EXTRUDE                         "Extruir"
#define MSG_RETRACT                         "Retraer"
#define MSG_MOVE_AXIS                       "Mover Eixes"
#define MSG_MOVE_X                          "Move X"
#define MSG_MOVE_Y                          "Move Y"
#define MSG_MOVE_Z                          "Move Z"
#define MSG_MOVE_E                          "Extruder"
#define MSG_MOVE_E1                         "Extruder2"
#define MSG_MOVE_E2                         "Extruder3"
#define MSG_MOVE_01MM                       "Move 0.1mm"
#define MSG_MOVE_1MM                        "Move 1mm"
#define MSG_MOVE_10MM                       "Move 10mm"
#define MSG_SPEED                           "Velocidat"
#define MSG_NOZZLE                          "Nozzle"
#define MSG_NOZZLE1                         "Nozzle2"
#define MSG_NOZZLE2                         "Nozzle3"
#define MSG_BED                             "Base"
#define MSG_FAN_SPEED                       "Ixoriador"
#define MSG_FLOW                            "Fluxo"
#define MSG_FLOW0                           "Fluxo 0"
#define MSG_FLOW1                           "Fluxo 1"
#define MSG_FLOW2                           "Fluxo 2"
#define MSG_CONTROL                         "Control"
#define MSG_MIN                             "\002 Min"
#define MSG_MAX                             "\002 Max"
#define MSG_FACTOR                          "\002 Fact"
#define MSG_AUTOTEMP                        "Autotemp"
#define MSG_ON                              "On"
#define MSG_OFF                             "Off"
#define MSG_PID_P                           "PID-P"
#define MSG_PID_I                           "PID-I"
#define MSG_PID_D                           "PID-D"
#define MSG_PID_C                           "PID-C"
#define MSG_ACC                             "Acel"
#define MSG_VXY_JERK                        "Vxy-jerk"
#define MSG_VZ_JERK                         "Vz-jerk"
#define MSG_VE_JERK                         "Ves-jerk"
#define MSG_VMAX                            "Vmax"
#define MSG_X                               "x"
#define MSG_Y                               "y"
#define MSG_Z                               "z"
#define MSG_E                               "y"
#define MSG_VMIN                            "Vmin"
#define MSG_VTRAV_MIN                       "VTrav min"
#define MSG_AMAX                            "Amax"
#define MSG_A_RETRACT                       "A-retrac."
#define MSG_XSTEPS                          "X trangos/mm"
#define MSG_YSTEPS                          "Y trangos/mm"
#define MSG_ZSTEPS                          "Z trangos/mm"
#define MSG_ESTEPS                          "E trangos/mm"
#define MSG_TEMPERATURE                     "Temperatura"
#define MSG_MOTION                          "Movimiento"
#define MSG_CONTRAST                        "Contrast"
#define MSG_STORE_EPROM                     "Alzar Memoria"
#define MSG_LOAD_EPROM                      "Cargar Memoria"
#define MSG_RESTORE_FAILSAFE                "Rest. d'emerchen."
#define MSG_REFRESH                         "Tornar a cargar"
#define MSG_WATCH                           "Monitorizar"
#define MSG_PREPARE                         "Preparar"
#define MSG_TUNE                            "Achustar"
#define MSG_PAUSE_PRINT                     "Pausar impresion"
#define MSG_RESUME_PRINT                    "Contin. impresion"
#define MSG_STOP_PRINT                      "Detener Impresion"
#define MSG_CARD_MENU                       "Menu de SD"
#define MSG_NO_CARD                         "No i hai tarcheta"
#define MSG_DWELL                           "Reposo..."
#define MSG_USERWAIT                        "Asperan. ordines"
#define MSG_RESUMING                        "Contin. impresion"
#define MSG_PRINT_ABORTED                   "Print aborted"
#define MSG_NO_MOVE                         "Sin movimiento"
#define MSG_KILLED                          "ATURADA D'EMERCH."
#define MSG_STOPPED                         "ATURADA."
#define MSG_CONTROL_RETRACT                 "Retraer mm"
#define MSG_CONTROL_RETRACT_SWAP            "Swap Retraer mm"
#define MSG_CONTROL_RETRACTF                "Retraer  F"
#define MSG_CONTROL_RETRACT_ZLIFT           "Devantar mm"
#define MSG_CONTROL_RETRACT_RECOVER         "DesRet +mm"
#define MSG_CONTROL_RETRACT_RECOVER_SWAP    "Swap DesRet +mm"
#define MSG_CONTROL_RETRACT_RECOVERF        "DesRet F"
#define MSG_AUTORETRACT                     "AutoRetr."
#define MSG_FILAMENTCHANGE                  "Cambear"
#define MSG_INIT_SDCARD                     "Encetan. tarcheta"
#define MSG_CNG_SDCARD                      "Cambiar tarcheta"
#define MSG_ZPROBE_OUT                      "Z probe out. bed"
#define MSG_POSITION_UNKNOWN                "Home X/Y before Z"
#define MSG_ZPROBE_ZOFFSET                  "Z Offset"
#define MSG_BABYSTEP_X                      "Babystep X"
#define MSG_BABYSTEP_Y                      "Babystep Y"
#define MSG_BABYSTEP_Z                      "Babystep Z"
#define MSG_ENDSTOP_ABORT                   "Endstop abort"

#define MSG_RECTRACT                        "Retraer"
#define MSG_RECTRACT_WIDE                   "Retraer"
#define MSG_TEMPERATURE_WIDE                "Temperatura"
#define MSG_TEMPERATURE_RTN                 "Temperatura"
#define MSG_MAIN_WIDE                       "Menu Prencipal"
#define MSG_MOTION_WIDE                     "Movimiento"
#define MSG_PREPARE_ALT                     "Preparar"
#define MSG_CONTROL_ARROW                   "Control \x7E"
#define MSG_RETRACT_ARROW                   "Retraer \x7E"
#define MSG_STEPPER_RELEASED                "Desacoplada."

#endif // LANGUAGE_AN_H


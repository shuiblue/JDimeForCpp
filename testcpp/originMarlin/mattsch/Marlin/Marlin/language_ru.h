/**
 * Russian
 *
 * LCD Menu Messages
 * Please note these are limited to 17 characters!
 *
 */
#ifndef LANGUAGE_RU_H
#define LANGUAGE_RU_H

#define WELCOME_MSG                         MACHINE_NAME "Готов."
#define MSG_SD_INSERTED                     "Карта вставлена"
#define MSG_SD_REMOVED                      "Карта извлечена"
#define MSG_MAIN                            "Меню \003"
#define MSG_AUTOSTART                       "Автостарт"
#define MSG_DISABLE_STEPPERS                "Выкл. двигатели"
#define MSG_AUTO_HOME                       "Парковка"
#define MSG_SET_HOME_OFFSETS                "Set home offsets"
#define MSG_SET_ORIGIN                      "Запомнить ноль"
#define MSG_PREHEAT_PLA                     "Преднагрев PLA"
#define MSG_PREHEAT_PLA0                    "Преднагрев PLA0"
#define MSG_PREHEAT_PLA1                    "Преднагрев PLA1"
#define MSG_PREHEAT_PLA2                    "Преднагрев PLA2"
#define MSG_PREHEAT_PLA012                  "Преднаг. PLA все"
#define MSG_PREHEAT_PLA_BEDONLY             "Пред. PLA Кровать"
#define MSG_PREHEAT_PLA_SETTINGS            "Настройки PLA"
#define MSG_PREHEAT_ABS                     "Преднагрев ABS"
#define MSG_PREHEAT_ABS0                    "Преднагрев ABS0"
#define MSG_PREHEAT_ABS1                    "Преднагрев ABS1"
#define MSG_PREHEAT_ABS2                    "Преднагрев ABS2"
#define MSG_PREHEAT_ABS012                  "Преднаг. ABS все "
#define MSG_PREHEAT_ABS_BEDONLY             "Пред. ABS Кровать"
#define MSG_PREHEAT_ABS_SETTINGS            "Настройки ABS"
#define MSG_COOLDOWN                        "Охлаждение"
#define MSG_SWITCH_PS_ON                    "Switch Power On"
#define MSG_SWITCH_PS_OFF                   "Switch Power Off"
#define MSG_EXTRUDE                         "Экструзия"
#define MSG_RETRACT                         "Откат"
#define MSG_MOVE_AXIS                       "Движение по осям"
#define MSG_MOVE_X                          "Move X"
#define MSG_MOVE_Y                          "Move Y"
#define MSG_MOVE_Z                          "Move Z"
#define MSG_MOVE_E                          "Extruder"
#define MSG_MOVE_E1                         "Extruder2"
#define MSG_MOVE_E2                         "Extruder3"
#define MSG_MOVE_01MM                       "Move 0.1mm"
#define MSG_MOVE_1MM                        "Move 1mm"
#define MSG_MOVE_10MM                       "Move 10mm"
#define MSG_SPEED                           "Скорость:"
#define MSG_NOZZLE                          "\002 Фильера:"
#define MSG_NOZZLE1                         "\002 Фильера2:"
#define MSG_NOZZLE2                         "\002 Фильера3:"
#define MSG_BED                             "\002 Кровать:"
#define MSG_FAN_SPEED                       "Куллер:"
#define MSG_FLOW                            "Поток:"
#define MSG_FLOW0                           " Поток0:"
#define MSG_FLOW1                           " Поток1:"
#define MSG_FLOW2                           " Поток2:"
#define MSG_CONTROL                         "Настройки \003"
#define MSG_MIN                             "\002 Минимум:"
#define MSG_MAX                             "\002 Максимум:"
#define MSG_FACTOR                          "\002 Фактор:"
#define MSG_AUTOTEMP                        "Autotemp:"
#define MSG_ON                              "Вкл. "
#define MSG_OFF                             "Выкл. "
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
#define MSG_XSTEPS                          "X шаг/mm:"
#define MSG_YSTEPS                          "Y шаг/mm:"
#define MSG_ZSTEPS                          "Z шаг/mm:"
#define MSG_ESTEPS                          "E шаг/mm:"
#define MSG_TEMPERATURE                     "Температура     \x7E"
#define MSG_MOTION                          "Скорости        \x7E"
#define MSG_CONTRAST                        "LCD contrast"
#define MSG_STORE_EPROM                     "Сохранить в EPROM"
#define MSG_LOAD_EPROM                      "Загруз. из EPROM"
#define MSG_RESTORE_FAILSAFE                "Сброс настроек"
#define MSG_REFRESH                         "\004Обновить"
#define MSG_WATCH                           "Обзор           \003"
#define MSG_PREPARE                         "Действия        \x7E"
#define MSG_TUNE                            "Настройки       \x7E"
#define MSG_PAUSE_PRINT                     "Продолжить печать"
#define MSG_RESUME_PRINT                    "возобн. печать"
#define MSG_STOP_PRINT                      "Остановить печать"
#define MSG_CARD_MENU                       "Меню карты      \x7E"
#define MSG_NO_CARD                         "Нет карты"
#define MSG_DWELL                           "Сон..."
#define MSG_USERWAIT                        "Ожиданиие"
#define MSG_RESUMING                        "Resuming print"
#define MSG_PRINT_ABORTED                   "Print aborted"
#define MSG_NO_MOVE                         "Нет движения."
#define MSG_KILLED                          "УБИТО."
#define MSG_STOPPED                         "ОСТАНОВЛЕНО."
#define MSG_CONTROL_RETRACT                 "Откат mm:"
#define MSG_CONTROL_RETRACT_SWAP            "своп Откат mm:"
#define MSG_CONTROL_RETRACTF                "Откат  V:"
#define MSG_CONTROL_RETRACT_ZLIFT           "Прыжок mm:"
#define MSG_CONTROL_RETRACT_RECOVER         "Возврат +mm:"
#define MSG_CONTROL_RETRACT_RECOVER_SWAP    "своп Возврат +mm:"
#define MSG_CONTROL_RETRACT_RECOVERF        "Возврат  V:"
#define MSG_AUTORETRACT                     "АвтоОткат:"
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

#define MSG_RECTRACT                        "Откат подачи    \x7E"

#endif // LANGUAGE_RU_H



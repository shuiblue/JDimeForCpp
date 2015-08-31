#if defined (akadamson)
    #include "language.h"
#endif
#if defined (upstream) || defined (akadamson)
    #include "temperature.h"
    #include "ultralcd.h"
#endif
#if defined (upstream) && defined (ULTRA_LCD) || defined (akadamson) && defined (ULTRA_LCD)
    #include "Marlin.h"
    #include "language.h"
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    #include "cardreader.h"
#endif
#if defined (upstream) && defined (ULTRA_LCD) || defined (akadamson) && defined (ULTRA_LCD)
    #include "temperature.h"
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    #include "stepper.h"
#endif
#if defined (upstream) && defined (ULTRA_LCD) || defined (akadamson) && defined (ULTRA_LCD)
    #include "ConfigurationStore.h"
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    int8_t encoderDiff;
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    //===========================================================================
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    /* encoderDiff is updated from interrupt context and added to encoderPosition every LCD update */
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    //=============================imported variables============================
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    /* Configuration settings */
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    //===========================================================================
    extern volatile int feedmultiply;
    extern volatile bool feedmultiplychanged;
    extern volatile int extrudemultiply;
    extern long position[4];
#endif
#if defined (akadamson) && (defined (ULTRA_LCD) && defined (SDSUPPORT) )
    #include "cardreader.h"
    extern CardReader card;
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    //===========================================================================
    //=============================public variables============================
    //===========================================================================
    volatile char buttons=0;
    //the last checked buttons in a bit array.
    long encoderpos=0;
    short lastenc=0;
    //TODO: This should be in a preferences file.
#endif
#if defined (upstream) && defined (ULTRA_LCD) || defined (akadamson) && defined (ULTRA_LCD)
    int plaPreheatHotendTemp;
    int plaPreheatHPBTemp;
    int plaPreheatFanSpeed;
    int absPreheatHotendTemp;
    int absPreheatHPBTemp;
    int absPreheatFanSpeed;
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (FILAMENT_LCD_DISPLAY) )
    unsigned long message_millis = 0;
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    //===========================================================================
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static float manual_feedrate[] = MANUAL_FEEDRATE;
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    //=============================private  variables============================
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    // ULTIPANEL
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    //===========================================================================
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    /* !Configuration settings */
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    static char messagetext[LCD_WIDTH]="";
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    //Function pointer to menu functions.
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    //return for string conversion routines
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    typedef void (*menuFunc_t)();
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    static char conv[8];
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    uint8_t lcd_status_message_level;
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    LCD_CLASS lcd(LCD_PINS_RS, LCD_PINS_ENABLE, LCD_PINS_D4, LCD_PINS_D5,LCD_PINS_D6,LCD_PINS_D7);
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    char lcd_status_message[LCD_WIDTH+1] = WELCOME_MSG;
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    //RS,Enable,D4,D5,D6,D7
#endif
#if defined (upstream) && (defined (DOGLCD) && defined (ULTRA_LCD) )
    #include "dogm_lcd_implementation.h"
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    static unsigned long previous_millis_lcd=0;
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && !defined (DOGLCD) )
    #include "ultralcd_implementation_hitachi_HD44780.h"
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    //static long previous_millis_buttons=0;
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    /** forward declarations **/
#endif
#if defined (akadamson) && (defined (NEWPANEL) && defined (ULTRA_LCD) )
    static unsigned long blocking=0;
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    void copy_and_scalePID_i();
#endif
#if defined (akadamson) && (defined (ULTRA_LCD) && !defined (NEWPANEL) )
static unsigned long blocking[8]= {0,0,0,0,0,0,0,0};
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    void copy_and_scalePID_d();
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    static MainMenu menu;
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    /* Different menus */
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
void lcdProgMemprint(const char *str) {
    char ch=pgm_read_byte(str);
    while(ch) {
        lcd.print(ch);
        ch=pgm_read_byte(++str);
    }
}
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
void lcdProgMemprint(const char *str) {
    char ch=pgm_read_byte(str);
    while(ch) {
        lcd.print(ch);
        ch=pgm_read_byte(++str);
    }
}
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    static void lcd_status_screen();
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    #define LCD_PRINT_PGM(x) lcdProgMemprint(PSTR(x))
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    extern bool powersupply;
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    //===========================================================================
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static void lcd_main_menu();
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    //=============================functions         ============================
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static void lcd_tune_menu();
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    //===========================================================================
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static void lcd_prepare_menu();
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
int intround(const float &x) {
    return int(0.5+x);
}
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
int intround(const float &x) {
    return int(0.5+x);
}
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static void lcd_move_menu();
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
void lcd_status(const char* message) {
    strncpy(messagetext,message,LCD_WIDTH);
    messagetext[strlen(message)]=0;
}
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
void lcd_status(const char* message) {
    strncpy(messagetext,message,LCD_WIDTH);
    messagetext[strlen(message)]=0;
}
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static void lcd_control_menu();
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
void lcd_statuspgm(const char* message) {
    char ch=pgm_read_byte(message);
    char *target=messagetext;
    uint8_t cnt=0;
    while(ch &&cnt<LCD_WIDTH) {
        *target=ch;
        target++;
        cnt++;
        ch=pgm_read_byte(++message);
    }
    *target=0;
}
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
void lcd_statuspgm(const char* message) {
    char ch=pgm_read_byte(message);
    char *target=messagetext;
    uint8_t cnt=0;
    while(ch &&cnt<LCD_WIDTH) {
        *target=ch;
        target++;
        cnt++;
        ch=pgm_read_byte(++message);
    }
    *target=0;
}
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static void lcd_control_temperature_menu();
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
void lcd_alertstatuspgm(const char* message) {
    lcd_statuspgm(message);
    menu.showStatus();
}
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
void lcd_alertstatuspgm(const char* message) {
    lcd_statuspgm(message);
    menu.showStatus();
}
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static void lcd_control_temperature_preheat_pla_settings_menu();
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
FORCE_INLINE void clear() {
    lcd.clear();
}
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
FORCE_INLINE void clear() {
    lcd.clear();
}
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static void lcd_control_temperature_preheat_abs_settings_menu();
    static void lcd_control_motion_menu();
    static void lcd_control_volumetric_menu();
#endif
#if defined (upstream) && (defined (DOGLCD) && defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static void lcd_set_contrast();
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static void lcd_control_retract_menu();
    static void lcd_sdcard_menu();
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (DELTA_CALIBRATION_MENU) && defined (ULTIPANEL) )
    static void lcd_delta_calibrate_menu();
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    // DELTA_CALIBRATION_MENU
    static void lcd_quick_feedback();
    //Cause an LCD refresh, and give the user visual or audible feedback that something has happened
    /* Different types of actions that can be used in menu items. */
    static void menu_action_back(menuFunc_t data);
    static void menu_action_submenu(menuFunc_t data);
    static void menu_action_gcode(const char* pgcode);
    static void menu_action_function(menuFunc_t data);
    static void menu_action_sdfile(const char* filename, char* longFilename);
    static void menu_action_sddirectory(const char* filename, char* longFilename);
    static void menu_action_setting_edit_bool(const char* pstr, bool* ptr);
    static void menu_action_setting_edit_int3(const char* pstr, int* ptr, int minValue, int maxValue);
    static void menu_action_setting_edit_float3(const char* pstr, float* ptr, float minValue, float maxValue);
    static void menu_action_setting_edit_float32(const char* pstr, float* ptr, float minValue, float maxValue);
    static void menu_action_setting_edit_float43(const char* pstr, float* ptr, float minValue, float maxValue);
    static void menu_action_setting_edit_float5(const char* pstr, float* ptr, float minValue, float maxValue);
    static void menu_action_setting_edit_float51(const char* pstr, float* ptr, float minValue, float maxValue);
    static void menu_action_setting_edit_float52(const char* pstr, float* ptr, float minValue, float maxValue);
    static void menu_action_setting_edit_long5(const char* pstr, unsigned long* ptr, unsigned long minValue, unsigned long maxValue);
    static void menu_action_setting_edit_callback_bool(const char* pstr, bool* ptr, menuFunc_t callbackFunc);
    static void menu_action_setting_edit_callback_int3(const char* pstr, int* ptr, int minValue, int maxValue, menuFunc_t callbackFunc);
    static void menu_action_setting_edit_callback_float3(const char* pstr, float* ptr, float minValue, float maxValue, menuFunc_t callbackFunc);
    static void menu_action_setting_edit_callback_float32(const char* pstr, float* ptr, float minValue, float maxValue, menuFunc_t callbackFunc);
    static void menu_action_setting_edit_callback_float43(const char* pstr, float* ptr, float minValue, float maxValue, menuFunc_t callbackFunc);
    static void menu_action_setting_edit_callback_float5(const char* pstr, float* ptr, float minValue, float maxValue, menuFunc_t callbackFunc);
    static void menu_action_setting_edit_callback_float51(const char* pstr, float* ptr, float minValue, float maxValue, menuFunc_t callbackFunc);
    static void menu_action_setting_edit_callback_float52(const char* pstr, float* ptr, float minValue, float maxValue, menuFunc_t callbackFunc);
    static void menu_action_setting_edit_callback_long5(const char* pstr, unsigned long* ptr, unsigned long minValue, unsigned long maxValue, menuFunc_t callbackFunc);
    #define ENCODER_FEEDRATE_DEADZONE 10
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && !defined(LCD_I2C_VIKI) && !defined (ENCODER_STEPS_PER_MENU_ITEM) && defined (ULTIPANEL) )
    #define ENCODER_STEPS_PER_MENU_ITEM 5
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && !defined(LCD_I2C_VIKI) && !defined (ENCODER_PULSES_PER_STEP) && defined (ULTIPANEL) )
    #define ENCODER_PULSES_PER_STEP 1
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && !defined (ENCODER_STEPS_PER_MENU_ITEM) && defined(LCD_I2C_VIKI) && defined (ULTIPANEL) )
    #define ENCODER_STEPS_PER_MENU_ITEM 2
    // VIKI LCD rotary encoder uses a different number of steps per rotation
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined(LCD_I2C_VIKI) && !defined (ENCODER_PULSES_PER_STEP) && defined (ULTIPANEL) )
    #define ENCODER_PULSES_PER_STEP 1
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
/* Helper macros for menus */
#define START_MENU() do { \
    if (encoderPosition > 0x8000) encoderPosition = 0; \
    if (encoderPosition / ENCODER_STEPS_PER_MENU_ITEM < currentMenuViewOffset) currentMenuViewOffset = encoderPosition / ENCODER_STEPS_PER_MENU_ITEM;\
    uint8_t _lineNr = currentMenuViewOffset, _menuItemNr; \
    bool wasClicked = LCD_CLICKED;\
    for(uint8_t _drawLineNr = 0; _drawLineNr < LCD_HEIGHT; _drawLineNr++, _lineNr++) { \
        _menuItemNr = 0;
#define MENU_ITEM(type, label, args...) do { \
    if (_menuItemNr == _lineNr) { \
        if (lcdDrawUpdate) { \
            const char* _label_pstr = PSTR(label); \
            if ((encoderPosition / ENCODER_STEPS_PER_MENU_ITEM) == _menuItemNr) { \
                lcd_implementation_drawmenu_ ## type ## _selected (_drawLineNr, _label_pstr , ## args ); \
            }else{\
                lcd_implementation_drawmenu_ ## type (_drawLineNr, _label_pstr , ## args ); \
            }\
        }\
        if (wasClicked && (encoderPosition / ENCODER_STEPS_PER_MENU_ITEM) == _menuItemNr) {\
            lcd_quick_feedback(); \
            menu_action_ ## type ( args ); \
            return;\
        }\
    }\
    _menuItemNr++;\
} while(0)
#define MENU_ITEM_DUMMY() do { _menuItemNr++; } while(0)
#define MENU_ITEM_EDIT(type, label, args...) MENU_ITEM(setting_edit_ ## type, label, PSTR(label) , ## args )
#define MENU_ITEM_EDIT_CALLBACK(type, label, args...) MENU_ITEM(setting_edit_callback_ ## type, label, PSTR(label) , ## args )
#define END_MENU() \
    if (encoderPosition / ENCODER_STEPS_PER_MENU_ITEM >= _menuItemNr) encoderPosition = _menuItemNr * ENCODER_STEPS_PER_MENU_ITEM - 1; \
    if ((uint8_t)(encoderPosition / ENCODER_STEPS_PER_MENU_ITEM) >= currentMenuViewOffset + LCD_HEIGHT) { currentMenuViewOffset = (encoderPosition / ENCODER_STEPS_PER_MENU_ITEM) - LCD_HEIGHT + 1; lcdDrawUpdate = 1; _lineNr = currentMenuViewOffset - 1; _drawLineNr = -1; } \
    } } while(0)
/** Used variables to keep track of the menu */
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && !defined (REPRAPWORLD_KEYPAD) && defined (ULTIPANEL) )
    volatile uint8_t buttons;
    //Contains the bits of the currently pressed buttons.
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (REPRAPWORLD_KEYPAD) && defined (ULTIPANEL) )
    volatile uint8_t buttons_reprapworld_keypad;
    // to store the reprapworld_keypad shift register values
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) && defined (LCD_HAS_SLOW_BUTTONS) )
    volatile uint8_t slow_buttons;
    //Contains the bits of the currently pressed buttons.
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    uint8_t currentMenuViewOffset;
    /* scroll offset in the current menu */
    uint32_t blocking_enc;
    uint8_t lastEncoderBits;
    uint32_t encoderPosition;
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && (SDCARDDETECT > 0) && defined (ULTIPANEL) )
    bool lcd_oldcardstatus;
#endif
#if defined (upstream) && defined (ULTRA_LCD)
//ULTIPANEL
menuFunc_t currentMenu = lcd_status_screen;
/* function pointer to the currently active menu */
uint32_t lcd_next_update_millis;
uint8_t lcd_status_update_delay;
bool ignore_click = false;
bool wait_for_unclick;
uint8_t lcdDrawUpdate = 2;
/* Set to none-zero when the LCD needs to draw, decreased after every draw. Set to 2 in LCD routines so the LCD gets at least 1 full redraw (first redraw is partial) */
//prevMenu and prevEncoderPosition are used to store the previous menu location when editing settings.
menuFunc_t prevMenu = NULL;
uint16_t prevEncoderPosition;
//Variables used when editing values.
const char* editLabel;
void* editValue;
int32_t minEditValue, maxEditValue;
menuFunc_t callbackFunc;
// place-holders for Ki and Kd edits
float raw_Ki, raw_Kd;
static void lcd_goto_menu(menuFunc_t menu, const uint32_t encoder=0, const bool feedback=true) {
    if (currentMenu != menu) {
        currentMenu = menu;
        encoderPosition = encoder;
        if (feedback) lcd_quick_feedback();
        // For LCD_PROGRESS_BAR re-initialize the custom characters
#if defined(LCD_PROGRESS_BAR) && defined(SDSUPPORT)
        lcd_set_custom_characters(menu == lcd_status_screen);
#endif
    }
    /* Main status screen. It's up to the implementation specific part to show what is needed. As this is very display dependent */
    void lcd_status_screen() {
#if defined(LCD_PROGRESS_BAR) && defined(SDSUPPORT)
        uint16_t mil = millis();
#ifndef PROGRESS_MSG_ONCE
        if (mil > progressBarTick + PROGRESS_BAR_MSG_TIME + PROGRESS_BAR_BAR_TIME) {
            progressBarTick = mil;
        }
#endif
#if PROGRESS_MSG_EXPIRE > 0
        // keep the message alive if paused, count down otherwise
        if (messageTick > 0) {
            if (card.isFileOpen()) {
                if (IS_SD_PRINTING) {
                    if ((mil-messageTick) >= PROGRESS_MSG_EXPIRE) {
                        lcd_status_message[0] = '\0';
                        messageTick = 0;
                    }
                } else {
                    messageTick += LCD_UPDATE_INTERVAL;
                }
            } else {
                messageTick = 0;
            }
        }
#endif
#endif //LCD_PROGRESS_BAR
        if (lcd_status_update_delay)
            lcd_status_update_delay--;
        else
            lcdDrawUpdate = 1;
        if (lcdDrawUpdate) {
            lcd_implementation_status_screen();
            lcd_status_update_delay = 10;   /* redraw the main screen every second. This is easier then trying keep track of all things that change on the screen */
        }
#ifdef ULTIPANEL
        bool current_click = LCD_CLICKED;
        if (ignore_click) {
            if (wait_for_unclick) {
                if (!current_click) {
                    ignore_click = wait_for_unclick = false;
                } else {
                    current_click = false;
                }
            } else if (current_click) {
                lcd_quick_feedback();
                wait_for_unclick = true;
                current_click = false;
            }
        }
        if (current_click) {
            lcd_goto_menu(lcd_main_menu);
            lcd_implementation_init( // to maybe revive the LCD if static electricity killed it.
#if defined(LCD_PROGRESS_BAR) && defined(SDSUPPORT)
                currentMenu == lcd_status_screen
#endif
            );
#ifdef FILAMENT_LCD_DISPLAY
            message_millis = millis();  // get status message to show up for a while
#endif
        }
#ifdef ULTIPANEL_FEEDMULTIPLY
        // Dead zone at 100% feedrate
        if ((feedmultiply < 100 && (feedmultiply + int(encoderPosition)) > 100) ||
                (feedmultiply > 100 && (feedmultiply + int(encoderPosition)) < 100)) {
            encoderPosition = 0;
            feedmultiply = 100;
        }
        if (feedmultiply == 100 && int(encoderPosition) > ENCODER_FEEDRATE_DEADZONE) {
            feedmultiply += int(encoderPosition) - ENCODER_FEEDRATE_DEADZONE;
            encoderPosition = 0;
        } else if (feedmultiply == 100 && int(encoderPosition) < -ENCODER_FEEDRATE_DEADZONE) {
            feedmultiply += int(encoderPosition) + ENCODER_FEEDRATE_DEADZONE;
            encoderPosition = 0;
        } else if (feedmultiply != 100) {
            feedmultiply += int(encoderPosition);
            encoderPosition = 0;
        }
#endif //ULTIPANEL_FEEDMULTIPLY
        if (feedmultiply < 10)
            feedmultiply = 10;
        else if (feedmultiply > 999)
            feedmultiply = 999;
#endif //ULTIPANEL
    }
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static void lcd_return_to_status() {
        lcd_goto_menu(lcd_status_screen, 0, false);
    }
    static void lcd_sdcard_pause() {
        card.pauseSDPrint();
    }
    static void lcd_sdcard_resume() {
        card.startFileprint();
    }
    static void lcd_sdcard_stop() {
        card.sdprinting = false;
        card.closefile();
        quickStop();
        if(SD_FINISHED_STEPPERRELEASE) {
            enquecommand_P(PSTR(SD_FINISHED_RELEASECOMMAND));
        }
        autotempShutdown();
        cancel_heatup = true;
        lcd_setstatus(MSG_PRINT_ABORTED);
    }
    /* Menu implementation */
    static void lcd_main_menu() {
        START_MENU();
        MENU_ITEM(back, MSG_WATCH, lcd_status_screen);
        if (movesplanned() || IS_SD_PRINTING) {
            MENU_ITEM(submenu, MSG_TUNE, lcd_tune_menu);
        } else {
            MENU_ITEM(submenu, MSG_PREPARE, lcd_prepare_menu);
#ifdef DELTA_CALIBRATION_MENU
            MENU_ITEM(submenu, MSG_DELTA_CALIBRATE, lcd_delta_calibrate_menu);
#endif // DELTA_CALIBRATION_MENU
        }
        MENU_ITEM(submenu, MSG_CONTROL, lcd_control_menu);
#ifdef SDSUPPORT
        if (card.cardOK) {
            if (card.isFileOpen()) {
                if (card.sdprinting)
                    MENU_ITEM(function, MSG_PAUSE_PRINT, lcd_sdcard_pause);
                else
                    MENU_ITEM(function, MSG_RESUME_PRINT, lcd_sdcard_resume);
                MENU_ITEM(function, MSG_STOP_PRINT, lcd_sdcard_stop);
            } else {
                MENU_ITEM(submenu, MSG_CARD_MENU, lcd_sdcard_menu);
#if SDCARDDETECT < 1
                MENU_ITEM(gcode, MSG_CNG_SDCARD, PSTR("M21"));  // SD-card changed by user
#endif
            }
        } else {
            MENU_ITEM(submenu, MSG_NO_CARD, lcd_sdcard_menu);
#if SDCARDDETECT < 1
            MENU_ITEM(gcode, MSG_INIT_SDCARD, PSTR("M21")); // Manually initialize the SD-card via user interface
#endif
        }
#endif
        END_MENU();
    }
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (SDSUPPORT) && defined (ULTIPANEL) )
    static void lcd_autostart_sd() {
        card.lastnr=0;
        card.setroot();
        card.checkautostart(true);
    }
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    void lcd_set_home_offsets() {
        for(int8_t i=0; i < NUM_AXIS; i++) {
            if (i != E_AXIS) {
                add_homing[i] -= current_position[i];
                current_position[i] = 0.0;
            }
        }
        plan_set_position(0.0, 0.0, 0.0, current_position[E_AXIS]);
        // Audio feedback
        enquecommand_P(PSTR("M300 S659 P200"));
        enquecommand_P(PSTR("M300 S698 P200"));
        lcd_return_to_status();
    }
#endif
#if defined (upstream) && (defined (BABYSTEPPING) && defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static void _lcd_babystep(int axis, const char *msg) {
        if (encoderPosition != 0) {
            babystepsTodo[axis] += (int)encoderPosition;
            encoderPosition = 0;
            lcdDrawUpdate = 1;
        }
        if (lcdDrawUpdate) lcd_implementation_drawedit(msg, "");
        if (LCD_CLICKED) lcd_goto_menu(lcd_tune_menu);
    }
    static void lcd_babystep_x() {
        _lcd_babystep(X_AXIS, PSTR(MSG_BABYSTEPPING_X));
    }
    static void lcd_babystep_y() {
        _lcd_babystep(Y_AXIS, PSTR(MSG_BABYSTEPPING_Y));
    }
    static void lcd_babystep_z() {
        _lcd_babystep(Z_AXIS, PSTR(MSG_BABYSTEPPING_Z));
    }
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
//BABYSTEPPING
    static void lcd_tune_menu() {
        START_MENU();
        MENU_ITEM(back, MSG_MAIN, lcd_main_menu);
        MENU_ITEM_EDIT(int3, MSG_SPEED, &feedmultiply, 10, 999);
#if TEMP_SENSOR_0 != 0
        MENU_ITEM_EDIT(int3, MSG_NOZZLE, &target_temperature[0], 0, HEATER_0_MAXTEMP - 15);
#endif
#if TEMP_SENSOR_1 != 0
        MENU_ITEM_EDIT(int3, MSG_NOZZLE1, &target_temperature[1], 0, HEATER_1_MAXTEMP - 15);
#endif
#if TEMP_SENSOR_2 != 0
        MENU_ITEM_EDIT(int3, MSG_NOZZLE2, &target_temperature[2], 0, HEATER_2_MAXTEMP - 15);
#endif
#if TEMP_SENSOR_BED != 0
        MENU_ITEM_EDIT(int3, MSG_BED, &target_temperature_bed, 0, BED_MAXTEMP - 15);
#endif
        MENU_ITEM_EDIT(int3, MSG_FAN_SPEED, &fanSpeed, 0, 255);
        MENU_ITEM_EDIT(int3, MSG_FLOW, &extrudemultiply, 10, 999);
        MENU_ITEM_EDIT(int3, MSG_FLOW0, &extruder_multiply[0], 10, 999);
#if TEMP_SENSOR_1 != 0
        MENU_ITEM_EDIT(int3, MSG_FLOW1, &extruder_multiply[1], 10, 999);
#endif
#if TEMP_SENSOR_2 != 0
        MENU_ITEM_EDIT(int3, MSG_FLOW2, &extruder_multiply[2], 10, 999);
#endif
#ifdef BABYSTEPPING
#ifdef BABYSTEP_XY
        MENU_ITEM(submenu, MSG_BABYSTEP_X, lcd_babystep_x);
        MENU_ITEM(submenu, MSG_BABYSTEP_Y, lcd_babystep_y);
#endif //BABYSTEP_XY
        MENU_ITEM(submenu, MSG_BABYSTEP_Z, lcd_babystep_z);
#endif
#ifdef FILAMENTCHANGEENABLE
        MENU_ITEM(gcode, MSG_FILAMENTCHANGE, PSTR("M600"));
#endif
        END_MENU();
    }
    void lcd_preheat_pla0() {
        setTargetHotend0(plaPreheatHotendTemp);
        setTargetBed(plaPreheatHPBTemp);
        fanSpeed = plaPreheatFanSpeed;
        lcd_return_to_status();
        setWatch(); // heater sanity check timer
    }
    void lcd_preheat_abs0() {
        setTargetHotend0(absPreheatHotendTemp);
        setTargetBed(absPreheatHPBTemp);
        fanSpeed = absPreheatFanSpeed;
        lcd_return_to_status();
        setWatch(); // heater sanity check timer
    }
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && TEMP_SENSOR_1 != 0 && defined (ULTIPANEL) )
//2nd extruder preheat
    void lcd_preheat_pla1() {
        setTargetHotend1(plaPreheatHotendTemp);
        setTargetBed(plaPreheatHPBTemp);
        fanSpeed = plaPreheatFanSpeed;
        lcd_return_to_status();
        setWatch(); // heater sanity check timer
    }
    void lcd_preheat_abs1() {
        setTargetHotend1(absPreheatHotendTemp);
        setTargetBed(absPreheatHPBTemp);
        fanSpeed = absPreheatFanSpeed;
        lcd_return_to_status();
        setWatch(); // heater sanity check timer
    }
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
//2nd extruder preheat
#endif
#if defined (upstream) && (TEMP_SENSOR_2 != 0 && defined (ULTRA_LCD) && defined (ULTIPANEL) )
//3 extruder preheat
    void lcd_preheat_pla2() {
        setTargetHotend2(plaPreheatHotendTemp);
        setTargetBed(plaPreheatHPBTemp);
        fanSpeed = plaPreheatFanSpeed;
        lcd_return_to_status();
        setWatch(); // heater sanity check timer
    }
    void lcd_preheat_abs2() {
        setTargetHotend2(absPreheatHotendTemp);
        setTargetBed(absPreheatHPBTemp);
        fanSpeed = absPreheatFanSpeed;
        lcd_return_to_status();
        setWatch(); // heater sanity check timer
    }
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
//3 extruder preheat
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && (TEMP_SENSOR_1 != 0 || TEMP_SENSOR_2 != 0 && )defined (ULTIPANEL) )
//more than one extruder present
    void lcd_preheat_pla012() {
        setTargetHotend0(plaPreheatHotendTemp);
        setTargetHotend1(plaPreheatHotendTemp);
        setTargetHotend2(plaPreheatHotendTemp);
        setTargetBed(plaPreheatHPBTemp);
        fanSpeed = plaPreheatFanSpeed;
        lcd_return_to_status();
        setWatch(); // heater sanity check timer
    }
    void lcd_preheat_abs012() {
        setTargetHotend0(absPreheatHotendTemp);
        setTargetHotend1(absPreheatHotendTemp);
        setTargetHotend2(absPreheatHotendTemp);
        setTargetBed(absPreheatHPBTemp);
        fanSpeed = absPreheatFanSpeed;
        lcd_return_to_status();
        setWatch(); // heater sanity check timer
    }
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
//more than one extruder present
    void lcd_preheat_pla_bedonly() {
        setTargetBed(plaPreheatHPBTemp);
        fanSpeed = plaPreheatFanSpeed;
        lcd_return_to_status();
        setWatch(); // heater sanity check timer
    }
    void lcd_preheat_abs_bedonly() {
        setTargetBed(absPreheatHPBTemp);
        fanSpeed = absPreheatFanSpeed;
        lcd_return_to_status();
        setWatch(); // heater sanity check timer
    }
    static void lcd_preheat_pla_menu() {
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
    static void lcd_preheat_abs_menu() {
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
    void lcd_cooldown() {
        setTargetHotend0(0);
        setTargetHotend1(0);
        setTargetHotend2(0);
        setTargetBed(0);
        fanSpeed = 0;
        lcd_return_to_status();
    }
    static void lcd_prepare_menu() {
        START_MENU();
        MENU_ITEM(back, MSG_MAIN, lcd_main_menu);
#ifdef SDSUPPORT
#ifdef MENU_ADDAUTOSTART
        MENU_ITEM(function, MSG_AUTOSTART, lcd_autostart_sd);
#endif
#endif
        MENU_ITEM(gcode, MSG_DISABLE_STEPPERS, PSTR("M84"));
        MENU_ITEM(gcode, MSG_AUTO_HOME, PSTR("G28"));
        MENU_ITEM(function, MSG_SET_HOME_OFFSETS, lcd_set_home_offsets);
        //MENU_ITEM(gcode, MSG_SET_ORIGIN, PSTR("G92 X0 Y0 Z0"));
#if TEMP_SENSOR_0 != 0
#if TEMP_SENSOR_1 != 0 || TEMP_SENSOR_2 != 0 || TEMP_SENSOR_BED != 0
        MENU_ITEM(submenu, MSG_PREHEAT_PLA, lcd_preheat_pla_menu);
        MENU_ITEM(submenu, MSG_PREHEAT_ABS, lcd_preheat_abs_menu);
#else
        MENU_ITEM(function, MSG_PREHEAT_PLA, lcd_preheat_pla0);
        MENU_ITEM(function, MSG_PREHEAT_ABS, lcd_preheat_abs0);
#endif
#endif
        MENU_ITEM(function, MSG_COOLDOWN, lcd_cooldown);
#if PS_ON_PIN > -1
        if (powersupply) {
            MENU_ITEM(gcode, MSG_SWITCH_PS_OFF, PSTR("M81"));
        } else {
            MENU_ITEM(gcode, MSG_SWITCH_PS_ON, PSTR("M80"));
        }
#endif
        MENU_ITEM(submenu, MSG_MOVE_AXIS, lcd_move_menu);
        END_MENU();
    }
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (DELTA_CALIBRATION_MENU) && defined (ULTIPANEL) )
    static void lcd_delta_calibrate_menu() {
        START_MENU();
        MENU_ITEM(back, MSG_MAIN, lcd_main_menu);
        MENU_ITEM(gcode, MSG_AUTO_HOME, PSTR("G28"));
        MENU_ITEM(gcode, MSG_DELTA_CALIBRATE_X, PSTR("G0 F8000 X-77.94 Y-45 Z0"));
        MENU_ITEM(gcode, MSG_DELTA_CALIBRATE_Y, PSTR("G0 F8000 X77.94 Y-45 Z0"));
        MENU_ITEM(gcode, MSG_DELTA_CALIBRATE_Z, PSTR("G0 F8000 X0 Y90 Z0"));
        MENU_ITEM(gcode, MSG_DELTA_CALIBRATE_CENTER, PSTR("G0 F8000 X0 Y0 Z0"));
        END_MENU();
    }
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
// DELTA_CALIBRATION_MENU
    float move_menu_scale;
    static void lcd_move_menu_axis();
    static void _lcd_move(const char *name, int axis, int min, int max) {
        if (encoderPosition != 0) {
            refresh_cmd_timeout();
            current_position[axis] += float((int)encoderPosition) * move_menu_scale;
            if (min_software_endstops && current_position[axis] < min) current_position[axis] = min;
            if (max_software_endstops && current_position[axis] > max) current_position[axis] = max;
            encoderPosition = 0;
#ifdef DELTA
            calculate_delta(current_position);
            plan_buffer_line(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], current_position[E_AXIS], manual_feedrate[axis]/60, active_extruder);
#else
            plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS], manual_feedrate[axis]/60, active_extruder);
#endif
            lcdDrawUpdate = 1;
        }
        if (lcdDrawUpdate) lcd_implementation_drawedit(name, ftostr31(current_position[axis]));
        if (LCD_CLICKED) lcd_goto_menu(lcd_move_menu_axis);
    }
    static void lcd_move_x() {
        _lcd_move(PSTR("X"), X_AXIS, X_MIN_POS, X_MAX_POS);
    }
    static void lcd_move_y() {
        _lcd_move(PSTR("Y"), Y_AXIS, Y_MIN_POS, Y_MAX_POS);
    }
    static void lcd_move_z() {
        _lcd_move(PSTR("Z"), Z_AXIS, Z_MIN_POS, Z_MAX_POS);
    }
    static void lcd_move_e() {
        if (encoderPosition != 0) {
            current_position[E_AXIS] += float((int)encoderPosition) * move_menu_scale;
            encoderPosition = 0;
#ifdef DELTA
            calculate_delta(current_position);
            plan_buffer_line(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], current_position[E_AXIS], manual_feedrate[E_AXIS]/60, active_extruder);
#else
            plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS], manual_feedrate[E_AXIS]/60, active_extruder);
#endif
            lcdDrawUpdate = 1;
        }
        if (lcdDrawUpdate) {
            lcd_implementation_drawedit(PSTR("Extruder"), ftostr31(current_position[E_AXIS]));
        }
        if (LCD_CLICKED) lcd_goto_menu(lcd_move_menu_axis);
    }
    static void lcd_move_menu_axis() {
        START_MENU();
        MENU_ITEM(back, MSG_MOVE_AXIS, lcd_move_menu);
        MENU_ITEM(submenu, MSG_MOVE_X, lcd_move_x);
        MENU_ITEM(submenu, MSG_MOVE_Y, lcd_move_y);
        if (move_menu_scale < 10.0) {
            MENU_ITEM(submenu, MSG_MOVE_Z, lcd_move_z);
            MENU_ITEM(submenu, MSG_MOVE_E, lcd_move_e);
        }
        END_MENU();
    }
    static void lcd_move_menu_10mm() {
        move_menu_scale = 10.0;
        lcd_move_menu_axis();
    }
    static void lcd_move_menu_1mm() {
        move_menu_scale = 1.0;
        lcd_move_menu_axis();
    }
    static void lcd_move_menu_01mm() {
        move_menu_scale = 0.1;
        lcd_move_menu_axis();
    }
    static void lcd_move_menu() {
        START_MENU();
        MENU_ITEM(back, MSG_PREPARE, lcd_prepare_menu);
        MENU_ITEM(submenu, MSG_MOVE_10MM, lcd_move_menu_10mm);
        MENU_ITEM(submenu, MSG_MOVE_1MM, lcd_move_menu_1mm);
        MENU_ITEM(submenu, MSG_MOVE_01MM, lcd_move_menu_01mm);
        //TODO:X,Y,Z,E
        END_MENU();
    }
    static void lcd_control_menu() {
        START_MENU();
        MENU_ITEM(back, MSG_MAIN, lcd_main_menu);
        MENU_ITEM(submenu, MSG_TEMPERATURE, lcd_control_temperature_menu);
        MENU_ITEM(submenu, MSG_MOTION, lcd_control_motion_menu);
        MENU_ITEM(submenu, MSG_VOLUMETRIC, lcd_control_volumetric_menu);
#ifdef DOGLCD
//    MENU_ITEM_EDIT(int3, MSG_CONTRAST, &lcd_contrast, 0, 63);
        MENU_ITEM(submenu, MSG_CONTRAST, lcd_set_contrast);
#endif
#ifdef FWRETRACT
        MENU_ITEM(submenu, MSG_RETRACT, lcd_control_retract_menu);
#endif
#ifdef EEPROM_SETTINGS
        MENU_ITEM(function, MSG_STORE_EPROM, Config_StoreSettings);
        MENU_ITEM(function, MSG_LOAD_EPROM, Config_RetrieveSettings);
#endif
        MENU_ITEM(function, MSG_RESTORE_FAILSAFE, Config_ResetDefault);
        END_MENU();
    }
    static void lcd_control_temperature_menu() {
#ifdef PIDTEMP
        // set up temp variables - undo the default scaling
        raw_Ki = unscalePID_i(Ki);
        raw_Kd = unscalePID_d(Kd);
#endif
        START_MENU();
        MENU_ITEM(back, MSG_CONTROL, lcd_control_menu);
#if TEMP_SENSOR_0 != 0
        MENU_ITEM_EDIT(int3, MSG_NOZZLE, &target_temperature[0], 0, HEATER_0_MAXTEMP - 15);
#endif
#if TEMP_SENSOR_1 != 0
        MENU_ITEM_EDIT(int3, MSG_NOZZLE1, &target_temperature[1], 0, HEATER_1_MAXTEMP - 15);
#endif
#if TEMP_SENSOR_2 != 0
        MENU_ITEM_EDIT(int3, MSG_NOZZLE2, &target_temperature[2], 0, HEATER_2_MAXTEMP - 15);
#endif
#if TEMP_SENSOR_BED != 0
        MENU_ITEM_EDIT(int3, MSG_BED, &target_temperature_bed, 0, BED_MAXTEMP - 15);
#endif
        MENU_ITEM_EDIT(int3, MSG_FAN_SPEED, &fanSpeed, 0, 255);
#if defined AUTOTEMP && (TEMP_SENSOR_0 != 0)
        MENU_ITEM_EDIT(bool, MSG_AUTOTEMP, &autotemp_enabled);
        MENU_ITEM_EDIT(float3, MSG_MIN, &autotemp_min, 0, HEATER_0_MAXTEMP - 15);
        MENU_ITEM_EDIT(float3, MSG_MAX, &autotemp_max, 0, HEATER_0_MAXTEMP - 15);
        MENU_ITEM_EDIT(float32, MSG_FACTOR, &autotemp_factor, 0.0, 1.0);
#endif
#ifdef PIDTEMP
        MENU_ITEM_EDIT(float52, MSG_PID_P, &Kp, 1, 9990);
        // i is typically a small value so allows values below 1
        MENU_ITEM_EDIT_CALLBACK(float52, MSG_PID_I, &raw_Ki, 0.01, 9990, copy_and_scalePID_i);
        MENU_ITEM_EDIT_CALLBACK(float52, MSG_PID_D, &raw_Kd, 1, 9990, copy_and_scalePID_d);
# ifdef PID_ADD_EXTRUSION_RATE
        MENU_ITEM_EDIT(float3, MSG_PID_C, &Kc, 1, 9990);
# endif//PID_ADD_EXTRUSION_RATE
#endif//PIDTEMP
        MENU_ITEM(submenu, MSG_PREHEAT_PLA_SETTINGS, lcd_control_temperature_preheat_pla_settings_menu);
        MENU_ITEM(submenu, MSG_PREHEAT_ABS_SETTINGS, lcd_control_temperature_preheat_abs_settings_menu);
        END_MENU();
    }
    static void lcd_control_temperature_preheat_pla_settings_menu() {
        START_MENU();
        MENU_ITEM(back, MSG_TEMPERATURE, lcd_control_temperature_menu);
        MENU_ITEM_EDIT(int3, MSG_FAN_SPEED, &plaPreheatFanSpeed, 0, 255);
#if TEMP_SENSOR_0 != 0
        MENU_ITEM_EDIT(int3, MSG_NOZZLE, &plaPreheatHotendTemp, 0, HEATER_0_MAXTEMP - 15);
#endif
#if TEMP_SENSOR_BED != 0
        MENU_ITEM_EDIT(int3, MSG_BED, &plaPreheatHPBTemp, 0, BED_MAXTEMP - 15);
#endif
#ifdef EEPROM_SETTINGS
        MENU_ITEM(function, MSG_STORE_EPROM, Config_StoreSettings);
#endif
        END_MENU();
    }
    static void lcd_control_temperature_preheat_abs_settings_menu() {
        START_MENU();
        MENU_ITEM(back, MSG_TEMPERATURE, lcd_control_temperature_menu);
        MENU_ITEM_EDIT(int3, MSG_FAN_SPEED, &absPreheatFanSpeed, 0, 255);
#if TEMP_SENSOR_0 != 0
        MENU_ITEM_EDIT(int3, MSG_NOZZLE, &absPreheatHotendTemp, 0, HEATER_0_MAXTEMP - 15);
#endif
#if TEMP_SENSOR_BED != 0
        MENU_ITEM_EDIT(int3, MSG_BED, &absPreheatHPBTemp, 0, BED_MAXTEMP - 15);
#endif
#ifdef EEPROM_SETTINGS
        MENU_ITEM(function, MSG_STORE_EPROM, Config_StoreSettings);
#endif
        END_MENU();
    }
    static void lcd_control_motion_menu() {
        START_MENU();
        MENU_ITEM(back, MSG_CONTROL, lcd_control_menu);
#ifdef ENABLE_AUTO_BED_LEVELING
        MENU_ITEM_EDIT(float32, MSG_ZPROBE_ZOFFSET, &zprobe_zoffset, 0.5, 50);
#endif
        MENU_ITEM_EDIT(float5, MSG_ACC, &acceleration, 500, 99000);
        MENU_ITEM_EDIT(float3, MSG_VXY_JERK, &max_xy_jerk, 1, 990);
        MENU_ITEM_EDIT(float52, MSG_VZ_JERK, &max_z_jerk, 0.1, 990);
        MENU_ITEM_EDIT(float3, MSG_VE_JERK, &max_e_jerk, 1, 990);
        MENU_ITEM_EDIT(float3, MSG_VMAX MSG_X, &max_feedrate[X_AXIS], 1, 999);
        MENU_ITEM_EDIT(float3, MSG_VMAX MSG_Y, &max_feedrate[Y_AXIS], 1, 999);
        MENU_ITEM_EDIT(float3, MSG_VMAX MSG_Z, &max_feedrate[Z_AXIS], 1, 999);
        MENU_ITEM_EDIT(float3, MSG_VMAX MSG_E, &max_feedrate[E_AXIS], 1, 999);
        MENU_ITEM_EDIT(float3, MSG_VMIN, &minimumfeedrate, 0, 999);
        MENU_ITEM_EDIT(float3, MSG_VTRAV_MIN, &mintravelfeedrate, 0, 999);
        MENU_ITEM_EDIT_CALLBACK(long5, MSG_AMAX MSG_X, &max_acceleration_units_per_sq_second[X_AXIS], 100, 99000, reset_acceleration_rates);
        MENU_ITEM_EDIT_CALLBACK(long5, MSG_AMAX MSG_Y, &max_acceleration_units_per_sq_second[Y_AXIS], 100, 99000, reset_acceleration_rates);
        MENU_ITEM_EDIT_CALLBACK(long5, MSG_AMAX MSG_Z, &max_acceleration_units_per_sq_second[Z_AXIS], 100, 99000, reset_acceleration_rates);
        MENU_ITEM_EDIT_CALLBACK(long5, MSG_AMAX MSG_E, &max_acceleration_units_per_sq_second[E_AXIS], 100, 99000, reset_acceleration_rates);
        MENU_ITEM_EDIT(float5, MSG_A_RETRACT, &retract_acceleration, 100, 99000);
        MENU_ITEM_EDIT(float52, MSG_XSTEPS, &axis_steps_per_unit[X_AXIS], 5, 9999);
        MENU_ITEM_EDIT(float52, MSG_YSTEPS, &axis_steps_per_unit[Y_AXIS], 5, 9999);
        MENU_ITEM_EDIT(float51, MSG_ZSTEPS, &axis_steps_per_unit[Z_AXIS], 5, 9999);
        MENU_ITEM_EDIT(float51, MSG_ESTEPS, &axis_steps_per_unit[E_AXIS], 5, 9999);
#ifdef ABORT_ON_ENDSTOP_HIT_FEATURE_ENABLED
        MENU_ITEM_EDIT(bool, MSG_ENDSTOP_ABORT, &abort_on_endstop_hit);
#endif
#ifdef SCARA
        MENU_ITEM_EDIT(float74, MSG_XSCALE, &axis_scaling[X_AXIS],0.5,2);
        MENU_ITEM_EDIT(float74, MSG_YSCALE, &axis_scaling[Y_AXIS],0.5,2);
#endif
        END_MENU();
    }
    static void lcd_control_volumetric_menu() {
        START_MENU();
        MENU_ITEM(back, MSG_CONTROL, lcd_control_menu);
        MENU_ITEM_EDIT_CALLBACK(bool, MSG_VOLUMETRIC_ENABLED, &volumetric_enabled, calculate_volumetric_multipliers);
        if (volumetric_enabled) {
            MENU_ITEM_EDIT_CALLBACK(float43, MSG_FILAMENT_SIZE_EXTRUDER_0, &filament_size[0], DEFAULT_NOMINAL_FILAMENT_DIA - .5, DEFAULT_NOMINAL_FILAMENT_DIA + .5, calculate_volumetric_multipliers);
#if EXTRUDERS > 1
            MENU_ITEM_EDIT_CALLBACK(float43, MSG_FILAMENT_SIZE_EXTRUDER_1, &filament_size[1], DEFAULT_NOMINAL_FILAMENT_DIA - .5, DEFAULT_NOMINAL_FILAMENT_DIA + .5, calculate_volumetric_multipliers);
#if EXTRUDERS > 2
            MENU_ITEM_EDIT_CALLBACK(float43, MSG_FILAMENT_SIZE_EXTRUDER_2, &filament_size[2], DEFAULT_NOMINAL_FILAMENT_DIA - .5, DEFAULT_NOMINAL_FILAMENT_DIA + .5, calculate_volumetric_multipliers);
#endif
#endif
        }
        END_MENU();
    }
#endif
#if defined (upstream) && (defined (DOGLCD) && defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static void lcd_set_contrast() {
        if (encoderPosition != 0) {
            lcd_contrast -= encoderPosition;
            if (lcd_contrast < 0) lcd_contrast = 0;
            else if (lcd_contrast > 63) lcd_contrast = 63;
            encoderPosition = 0;
            lcdDrawUpdate = 1;
            u8g.setContrast(lcd_contrast);
        }
        if (lcdDrawUpdate) {
            lcd_implementation_drawedit(PSTR(MSG_CONTRAST), itostr2(lcd_contrast));
        }
        if (LCD_CLICKED) lcd_goto_menu(lcd_control_menu);
    }
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) && defined (FWRETRACT) )
    static void lcd_control_retract_menu() {
        START_MENU();
        MENU_ITEM(back, MSG_CONTROL, lcd_control_menu);
        MENU_ITEM_EDIT(bool, MSG_AUTORETRACT, &autoretract_enabled);
        MENU_ITEM_EDIT(float52, MSG_CONTROL_RETRACT, &retract_length, 0, 100);
#if EXTRUDERS > 1
        MENU_ITEM_EDIT(float52, MSG_CONTROL_RETRACT_SWAP, &retract_length_swap, 0, 100);
#endif
        MENU_ITEM_EDIT(float3, MSG_CONTROL_RETRACTF, &retract_feedrate, 1, 999);
        MENU_ITEM_EDIT(float52, MSG_CONTROL_RETRACT_ZLIFT, &retract_zlift, 0, 999);
        MENU_ITEM_EDIT(float52, MSG_CONTROL_RETRACT_RECOVER, &retract_recover_length, 0, 100);
#if EXTRUDERS > 1
        MENU_ITEM_EDIT(float52, MSG_CONTROL_RETRACT_RECOVER_SWAP, &retract_recover_length_swap, 0, 100);
#endif
        MENU_ITEM_EDIT(float3, MSG_CONTROL_RETRACT_RECOVERF, &retract_recover_feedrate, 1, 999);
        END_MENU();
    }
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
//FWRETRACT
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && SDCARDDETECT == -1 && defined (ULTIPANEL) )
    static void lcd_sd_refresh() {
        card.initsd();
        currentMenuViewOffset = 0;
    }
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static void lcd_sd_updir() {
        card.updir();
        currentMenuViewOffset = 0;
    }
    void lcd_sdcard_menu() {
        if (lcdDrawUpdate == 0 && LCD_CLICKED == 0)
            return;	// nothing to do (so don't thrash the SD card)
        uint16_t fileCnt = card.getnrfilenames();
        START_MENU();
        MENU_ITEM(back, MSG_MAIN, lcd_main_menu);
        card.getWorkDirName();
        if(card.filename[0]=='/') {
#if SDCARDDETECT == -1
            MENU_ITEM(function, LCD_STR_REFRESH MSG_REFRESH, lcd_sd_refresh);
#endif
        } else {
            MENU_ITEM(function, LCD_STR_FOLDER "..", lcd_sd_updir);
        }
        for(uint16_t i=0; i<fileCnt; i++) {
            if (_menuItemNr == _lineNr) {
#ifndef SDCARD_RATHERRECENTFIRST
                card.getfilename(i);
#else
                card.getfilename(fileCnt-1-i);
#endif
                if (card.filenameIsDir) {
                    MENU_ITEM(sddirectory, MSG_CARD_MENU, card.filename, card.longFilename);
                } else {
                    MENU_ITEM(sdfile, MSG_CARD_MENU, card.filename, card.longFilename);
                }
            } else {
                MENU_ITEM_DUMMY();
            }
        }
        END_MENU();
    }
#define menu_edit_type(_type, _name, _strFunc, scale) \
    void menu_edit_ ## _name () \
    { \
        if ((int32_t)encoderPosition < 0) encoderPosition = 0; \
        if ((int32_t)encoderPosition > maxEditValue) encoderPosition = maxEditValue; \
        if (lcdDrawUpdate) \
            lcd_implementation_drawedit(editLabel, _strFunc(((_type)((int32_t)encoderPosition + minEditValue)) / scale)); \
        if (LCD_CLICKED) \
        { \
            *((_type*)editValue) = ((_type)((int32_t)encoderPosition + minEditValue)) / scale; \
            lcd_goto_menu(prevMenu, prevEncoderPosition); \
        } \
    } \
    void menu_edit_callback_ ## _name () { \
        menu_edit_ ## _name (); \
        if (LCD_CLICKED) (*callbackFunc)(); \
    } \
    static void menu_action_setting_edit_ ## _name (const char* pstr, _type* ptr, _type minValue, _type maxValue) \
    { \
        prevMenu = currentMenu; \
        prevEncoderPosition = encoderPosition; \
         \
        lcdDrawUpdate = 2; \
        currentMenu = menu_edit_ ## _name; \
         \
        editLabel = pstr; \
        editValue = ptr; \
        minEditValue = minValue * scale; \
        maxEditValue = maxValue * scale - minEditValue; \
        encoderPosition = (*ptr) * scale - minEditValue; \
    }\
    static void menu_action_setting_edit_callback_ ## _name (const char* pstr, _type* ptr, _type minValue, _type maxValue, menuFunc_t callback) \
    { \
        prevMenu = currentMenu; \
        prevEncoderPosition = encoderPosition; \
         \
        lcdDrawUpdate = 2; \
        currentMenu = menu_edit_callback_ ## _name; \
         \
        editLabel = pstr; \
        editValue = ptr; \
        minEditValue = minValue * scale; \
        maxEditValue = maxValue * scale - minEditValue; \
        encoderPosition = (*ptr) * scale - minEditValue; \
        callbackFunc = callback;\
    }
    menu_edit_type(int, int3, itostr3, 1)
    menu_edit_type(float, float3, ftostr3, 1)
    menu_edit_type(float, float32, ftostr32, 100)
    menu_edit_type(float, float43, ftostr43, 1000)
    menu_edit_type(float, float5, ftostr5, 0.01)
    menu_edit_type(float, float51, ftostr51, 10)
    menu_edit_type(float, float52, ftostr52, 100)
    menu_edit_type(unsigned long, long5, ftostr5, 0.01)
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (REPRAPWORLD_KEYPAD) && defined (ULTIPANEL) )
    static void reprapworld_keypad_move_z_up() {
        encoderPosition = 1;
        move_menu_scale = REPRAPWORLD_KEYPAD_MOVE_STEP;
        lcd_move_z();
    }
    static void reprapworld_keypad_move_z_down() {
        encoderPosition = -1;
        move_menu_scale = REPRAPWORLD_KEYPAD_MOVE_STEP;
        lcd_move_z();
    }
    static void reprapworld_keypad_move_x_left() {
        encoderPosition = -1;
        move_menu_scale = REPRAPWORLD_KEYPAD_MOVE_STEP;
        lcd_move_x();
    }
    static void reprapworld_keypad_move_x_right() {
        encoderPosition = 1;
        move_menu_scale = REPRAPWORLD_KEYPAD_MOVE_STEP;
        lcd_move_x();
    }
    static void reprapworld_keypad_move_y_down() {
        encoderPosition = 1;
        move_menu_scale = REPRAPWORLD_KEYPAD_MOVE_STEP;
        lcd_move_y();
    }
    static void reprapworld_keypad_move_y_up() {
        encoderPosition = -1;
        move_menu_scale = REPRAPWORLD_KEYPAD_MOVE_STEP;
        lcd_move_y();
    }
    static void reprapworld_keypad_move_home() {
        enquecommand_P((PSTR("G28"))); // move all axis home
    }
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    /** End of menus **/
    static void lcd_quick_feedback() {
        lcdDrawUpdate = 2;
        blocking_enc = millis() + 500;
        lcd_implementation_quick_feedback();
    }
    /** Menu action functions **/
    static void menu_action_back(menuFunc_t data) {
        lcd_goto_menu(data);
    }
    static void menu_action_submenu(menuFunc_t data) {
        lcd_goto_menu(data);
    }
    static void menu_action_gcode(const char* pgcode) {
        enquecommand_P(pgcode);
    }
    static void menu_action_function(menuFunc_t data) {
        (*data)();
    }
    static void menu_action_sdfile(const char* filename, char* longFilename) {
        char cmd[30];
        char* c;
        sprintf_P(cmd, PSTR("M23 %s"), filename);
        for(c = &cmd[4]; *c; c++)
            *c = tolower(*c);
        enquecommand(cmd);
        enquecommand_P(PSTR("M24"));
        lcd_return_to_status();
    }
    static void menu_action_sddirectory(const char* filename, char* longFilename) {
        card.chdir(filename);
        encoderPosition = 0;
    }
    static void menu_action_setting_edit_bool(const char* pstr, bool* ptr) {
        *ptr = !(*ptr);
    }
    static void menu_action_setting_edit_callback_bool(const char* pstr, bool* ptr, menuFunc_t callback) {
        menu_action_setting_edit_bool(pstr, ptr);
        (*callback)();
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
//ULTIPANEL
    /** LCD API **/
#endif
#if defined (upstream) && defined (ULTRA_LCD) || defined (akadamson) && defined (ULTRA_LCD)
    void lcd_init
    () {
#if defined (upstream) && defined (ULTRA_LCD)
        lcd_implementation_init();
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
//beep();
#endif
#if defined (upstream) && (defined (NEWPANEL) && defined (ULTRA_LCD) )
        SET_INPUT(BTN_EN1);
#endif
#if defined (akadamson) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
        buttons_init();
#endif
#if defined (upstream) && (defined (NEWPANEL) && defined (ULTRA_LCD) )
        SET_INPUT(BTN_EN2);
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        byte Degree[8] = {
            B01100,
            B10010,
            B10010,
            B01100,
            B00000,
            B00000,
            B00000,
            B00000
        };
#endif
#if defined (upstream) && (defined (NEWPANEL) && defined (ULTRA_LCD) )
        WRITE(BTN_EN1,HIGH);
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        byte Thermometer[8] = {
            B00100,
            B01010,
            B01010,
            B01010,
            B01010,
            B10001,
            B10001,
            B01110
        };
#endif
#if defined (upstream) && (defined (NEWPANEL) && defined (ULTRA_LCD) )
        WRITE(BTN_EN2,HIGH);
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        byte uplevel[8]= {
            B00100,
            B01110,
            B11111,
            B00100,
            B11100,
            B00000,
            B00000,
            B00000
        };
#endif
#if defined (upstream) && (defined (NEWPANEL) && defined (ULTRA_LCD) && BTN_ENC > 0 )
        SET_INPUT(BTN_ENC);
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
//thanks joris
#endif
#if defined (upstream) && (defined (NEWPANEL) && defined (ULTRA_LCD) && BTN_ENC > 0 )
        WRITE(BTN_ENC,HIGH);
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        byte refresh[8]= {
            B00000,
            B00110,
            B11001,
            B11000,
            B00011,
            B10011,
            B01100,
            B00000,
        };
#endif
#if defined (upstream) && (defined (NEWPANEL) && defined (ULTRA_LCD) && defined (REPRAPWORLD_KEYPAD) )
        pinMode(SHIFT_CLK,OUTPUT);
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
//thanks joris
#endif
#if defined (upstream) && (defined (NEWPANEL) && defined (ULTRA_LCD) && defined (REPRAPWORLD_KEYPAD) )
        pinMode(SHIFT_LD,OUTPUT);
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        byte folder [8]= {
            B00000,
            B11100,
            B11111,
            B10001,
            B10001,
            B11111,
            B00000,
            B00000
        };
#endif
#if defined (upstream) && (defined (NEWPANEL) && defined (ULTRA_LCD) && defined (REPRAPWORLD_KEYPAD) )
        pinMode(SHIFT_OUT,INPUT);
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
//thanks joris
#endif
#if defined (upstream) && (defined (NEWPANEL) && defined (ULTRA_LCD) && defined (REPRAPWORLD_KEYPAD) )
        WRITE(SHIFT_OUT,HIGH);
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        lcd.begin(LCD_WIDTH, LCD_HEIGHT);
#endif
#if defined (upstream) && (defined (NEWPANEL) && defined (ULTRA_LCD) && defined (REPRAPWORLD_KEYPAD) )
        WRITE(SHIFT_LD,HIGH);
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        lcd.createChar(1,Degree);
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && !defined (NEWPANEL) )
// Not NEWPANEL
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        lcd.createChar(2,Thermometer);
#endif
#if defined (upstream) && (defined (SR_LCD_2W_NL) && defined (ULTRA_LCD) && !defined (NEWPANEL) )
// Non latching 2 wire shift register
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        lcd.createChar(3,uplevel);
#endif
#if defined (upstream) && (defined (SR_LCD_2W_NL) && defined (ULTRA_LCD) && !defined (NEWPANEL) )
        pinMode (SR_DATA_PIN, OUTPUT);
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        lcd.createChar(4,refresh);
#endif
#if defined (upstream) && (defined (SR_LCD_2W_NL) && defined (ULTRA_LCD) && !defined (NEWPANEL) )
        pinMode (SR_CLK_PIN, OUTPUT);
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        lcd.createChar(5,folder);
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined(SHIFT_CLK) && !defined (NEWPANEL) )
        pinMode(SHIFT_CLK,OUTPUT);
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        LCD_MESSAGEPGM(WELCOME_MSG);
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined(SHIFT_CLK) && !defined (NEWPANEL) )
        pinMode(SHIFT_LD,OUTPUT);
        pinMode(SHIFT_EN,OUTPUT);
        pinMode(SHIFT_OUT,INPUT);
        WRITE(SHIFT_OUT,HIGH);
        WRITE(SHIFT_LD,HIGH);
        WRITE(SHIFT_EN,LOW);
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && !defined (NEWPANEL) && !defined(SHIFT_CLK) && defined (ULTIPANEL) )
#error ULTIPANEL requires an encoder
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && !defined (NEWPANEL) )
// SR_LCD_2W_NL
#endif
#if defined (upstream) && defined (ULTRA_LCD)
//!NEWPANEL
#endif
#if defined (upstream) && ((defined (SDSUPPORT) && defined(SDCARDDETECT) && (SDCARDDETECT > 0) && )defined (ULTRA_LCD) )
        pinMode(SDCARDDETECT,INPUT);
        WRITE(SDCARDDETECT, HIGH);
        lcd_oldcardstatus = IS_SD_INSERTED;
#endif
#if defined (upstream) && defined (ULTRA_LCD)
//(SDCARDDETECT > 0)
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (LCD_HAS_SLOW_BUTTONS) )
        slow_buttons = 0;
#endif
#if defined (upstream) && defined (ULTRA_LCD)
        lcd_buttons_update();
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
        encoderDiff = 0;
#endif
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    void lcd_update() {
        static unsigned long timeoutToStatus = 0;
#ifdef LCD_HAS_SLOW_BUTTONS
        slow_buttons = lcd_implementation_read_slow_buttons(); // buttons which take too long to read in interrupt context
#endif
        lcd_buttons_update();
#if (SDCARDDETECT > 0)
        if((IS_SD_INSERTED != lcd_oldcardstatus && lcd_detected())) {
            lcdDrawUpdate = 2;
            lcd_oldcardstatus = IS_SD_INSERTED;
            lcd_implementation_init( // to maybe revive the LCD if static electricity killed it.
#if defined(LCD_PROGRESS_BAR) && defined(SDSUPPORT)
                currentMenu == lcd_status_screen
#endif
            );
            if(lcd_oldcardstatus) {
                card.initsd();
                LCD_MESSAGEPGM(MSG_SD_INSERTED);
            } else {
                card.release();
                LCD_MESSAGEPGM(MSG_SD_REMOVED);
            }
        }
#endif//CARDINSERTED
        if (lcd_next_update_millis < millis()) {
#ifdef ULTIPANEL
#ifdef REPRAPWORLD_KEYPAD
            if (REPRAPWORLD_KEYPAD_MOVE_Z_UP) {
                reprapworld_keypad_move_z_up();
            }
            if (REPRAPWORLD_KEYPAD_MOVE_Z_DOWN) {
                reprapworld_keypad_move_z_down();
            }
            if (REPRAPWORLD_KEYPAD_MOVE_X_LEFT) {
                reprapworld_keypad_move_x_left();
            }
            if (REPRAPWORLD_KEYPAD_MOVE_X_RIGHT) {
                reprapworld_keypad_move_x_right();
            }
            if (REPRAPWORLD_KEYPAD_MOVE_Y_DOWN) {
                reprapworld_keypad_move_y_down();
            }
            if (REPRAPWORLD_KEYPAD_MOVE_Y_UP) {
                reprapworld_keypad_move_y_up();
            }
            if (REPRAPWORLD_KEYPAD_MOVE_HOME) {
                reprapworld_keypad_move_home();
            }
#endif
            if (abs(encoderDiff) >= ENCODER_PULSES_PER_STEP) {
                lcdDrawUpdate = 1;
                encoderPosition += encoderDiff / ENCODER_PULSES_PER_STEP;
                encoderDiff = 0;
                timeoutToStatus = millis() + LCD_TIMEOUT_TO_STATUS;
            }
            if (LCD_CLICKED)
                timeoutToStatus = millis() + LCD_TIMEOUT_TO_STATUS;
#endif//ULTIPANEL
#ifdef DOGLCD        // Changes due to different driver architecture of the DOGM display
            blink++;     // Variable for fan animation and alive dot
            u8g.firstPage();
            do {
                u8g.setFont(u8g_font_6x10_marlin);
                u8g.setPrintPos(125,0);
                if (blink % 2) u8g.setColorIndex(1);
                else u8g.setColorIndex(0); // Set color for the alive dot
                u8g.drawPixel(127,63); // draw alive dot
                u8g.setColorIndex(1); // black on white
                (*currentMenu)();
                if (!lcdDrawUpdate)  break; // Terminate display update, when nothing new to draw. This must be done before the last dogm.next()
            } while( u8g.nextPage() );
#else
            (*currentMenu)();
#endif
#ifdef LCD_HAS_STATUS_INDICATORS
            lcd_implementation_update_indicators();
#endif
#ifdef ULTIPANEL
            if(timeoutToStatus < millis() && currentMenu != lcd_status_screen) {
                lcd_return_to_status();
                lcdDrawUpdate = 2;
            }
#endif//ULTIPANEL
            if (lcdDrawUpdate == 2) lcd_implementation_clear();
            if (lcdDrawUpdate) lcdDrawUpdate--;
            lcd_next_update_millis = millis() + LCD_UPDATE_INTERVAL;
        }
    }
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    void beep() {
        //return;
#ifdef ULTIPANEL
#if (BEEPER > -1)
        {
            pinMode(BEEPER,OUTPUT);
            for(int8_t i=0; i<20; i++) {
                WRITE(BEEPER,HIGH);
                delay(5);
                WRITE(BEEPER,LOW);
                delay(5);
            }
        }
#endif
#endif
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    void lcd_ignore_click(bool b) {
        ignore_click = b;
        wait_for_unclick = false;
    }
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    void beepshort() {
        //return;
#ifdef ULTIPANEL
#if (BEEPER > -1)
        {
            pinMode(BEEPER,OUTPUT);
            for(int8_t i=0; i<10; i++) {
                WRITE(BEEPER,HIGH);
                delay(3);
                WRITE(BEEPER,LOW);
                delay(3);
            }
        }
#endif
#endif
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    void lcd_finishstatus() {
        int len = strlen(lcd_status_message);
        if (len > 0) {
            while (len < LCD_WIDTH) {
                lcd_status_message[len++] = ' ';
            }
        }
        lcd_status_message[LCD_WIDTH] = '\0';
#if defined(LCD_PROGRESS_BAR) && defined(SDSUPPORT)
#if PROGRESS_MSG_EXPIRE > 0
        messageTick =
#endif
            progressBarTick = millis();
#endif
        lcdDrawUpdate = 2;
#ifdef FILAMENT_LCD_DISPLAY
        message_millis = millis();  //get status message to show up for a while
#endif
    }
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    void lcd_status() {
#ifdef ULTIPANEL
        static uint8_t oldbuttons=0;
        //static long previous_millis_buttons=0;
        //static long previous_lcdinit=0;
        //  buttons_check(); // Done in temperature interrupt
        //previous_millis_buttons=millis();
        unsigned long ms=millis();
        for(int8_t i=0; i<8; i++) {
#ifndef NEWPANEL
            if((blocking[i]>ms))
                buttons &= ~(1<<i);
#else
            if((blocking>ms))
                buttons &= ~(1<<i);
#endif
        }
        if((buttons==oldbuttons) &&  ((millis() - previous_millis_lcd) < LCD_UPDATE_INTERVAL)   )
            return;
        oldbuttons=buttons;
#else
        if(((millis() - previous_millis_lcd) < LCD_UPDATE_INTERVAL)   )
            return;
#endif
        previous_millis_lcd=millis();
        menu.update();
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    void lcd_setstatus(const char* message) {
        if (lcd_status_message_level > 0)
            return;
        strncpy(lcd_status_message, message, LCD_WIDTH);
        lcd_finishstatus();
    }
#endif
#if defined (akadamson) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    void buttons_init() {
#ifdef NEWPANEL
        pinMode(BTN_EN1,INPUT);
        pinMode(BTN_EN2,INPUT);
        pinMode(BTN_ENC,INPUT);
        pinMode(SDCARDDETECT,INPUT);
        WRITE(BTN_EN1,HIGH);
        WRITE(BTN_EN2,HIGH);
        WRITE(BTN_ENC,HIGH);
#if (SDCARDDETECT > -1)
        {
            WRITE(SDCARDDETECT,HIGH);
        }
#endif
#else
        pinMode(SHIFT_CLK,OUTPUT);
        pinMode(SHIFT_LD,OUTPUT);
        pinMode(SHIFT_EN,OUTPUT);
        pinMode(SHIFT_OUT,INPUT);
        WRITE(SHIFT_OUT,HIGH);
        WRITE(SHIFT_LD,HIGH);
        WRITE(SHIFT_EN,LOW);
#endif
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    void lcd_setstatuspgm(const char* message) {
        if (lcd_status_message_level > 0)
            return;
        strncpy_P(lcd_status_message, message, LCD_WIDTH);
        lcd_finishstatus();
    }
#endif
#if defined (akadamson) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    void buttons_check() {
#ifdef NEWPANEL
        uint8_t newbutton=0;
        if(READ(BTN_EN1)==0)  newbutton|=EN_A;
        if(READ(BTN_EN2)==0)  newbutton|=EN_B;
        if((blocking<millis()) &&(READ(BTN_ENC)==0))
            newbutton|=EN_C;
        buttons=newbutton;
#else   //read it from the shift register
        uint8_t newbutton=0;
        WRITE(SHIFT_LD,LOW);
        WRITE(SHIFT_LD,HIGH);
        unsigned char tmp_buttons=0;
        for(int8_t i=0; i<8; i++) {
            newbutton = newbutton>>1;
            if(READ(SHIFT_OUT))
                newbutton|=(1<<7);
            WRITE(SHIFT_CLK,HIGH);
            WRITE(SHIFT_CLK,LOW);
        }
        buttons=~newbutton; //invert it, because a pressed switch produces a logical 0
#endif
        //manage encoder rotation
        char enc=0;
        if(buttons&EN_A)
            enc|=(1<<0);
        if(buttons&EN_B)
            enc|=(1<<1);
        if(enc!=lastenc) {
            switch(enc) {
            case encrot0:
                if(lastenc==encrot3)
                    encoderpos++;
                else if(lastenc==encrot1)
                    encoderpos--;
                break;
            case encrot1:
                if(lastenc==encrot0)
                    encoderpos++;
                else if(lastenc==encrot2)
                    encoderpos--;
                break;
            case encrot2:
                if(lastenc==encrot1)
                    encoderpos++;
                else if(lastenc==encrot3)
                    encoderpos--;
                break;
            case encrot3:
                if(lastenc==encrot2)
                    encoderpos++;
                else if(lastenc==encrot0)
                    encoderpos--;
                break;
            default:
                ;
            }
        }
        lastenc=enc;
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    void lcd_setalertstatuspgm(const char* message) {
        lcd_setstatuspgm(message);
        lcd_status_message_level = 1;
#ifdef ULTIPANEL
        lcd_return_to_status();
#endif//ULTIPANEL
    }
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    MainMenu::MainMenu() {
        status=Main_Status;
        displayStartingRow=0;
        activeline=0;
        force_lcd_update=true;
        linechanging=false;
        tune=false;
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    void lcd_reset_alert_level() {
        lcd_status_message_level = 0;
    }
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    void MainMenu::showStatus() {
#if LCD_HEIGHT==4
        static int olddegHotEnd0=-1;
        static int oldtargetHotEnd0=-1;
        //force_lcd_update=true;
        if(force_lcd_update) { //initial display of content
            encoderpos=feedmultiply;
            clear();
            lcd.setCursor(0,0);
            LCD_PRINT_PGM("\002000/000\001 ");
#if defined BED_USES_THERMISTOR || defined BED_USES_AD595
            lcd.setCursor(10,0);
            LCD_PRINT_PGM("B000/000\001 ");
#elif EXTRUDERS > 1
            lcd.setCursor(10,0);
            LCD_PRINT_PGM("\002000/000\001 ");
#endif
        }
        int tHotEnd0=intround(degHotend0());
        if((tHotEnd0!=olddegHotEnd0)||force_lcd_update) {
            lcd.setCursor(1,0);
            lcd.print(ftostr3(tHotEnd0));
            olddegHotEnd0=tHotEnd0;
        }
        int ttHotEnd0=intround(degTargetHotend0());
        if((ttHotEnd0!=oldtargetHotEnd0)||force_lcd_update) {
            lcd.setCursor(5,0);
            lcd.print(ftostr3(ttHotEnd0));
            oldtargetHotEnd0=ttHotEnd0;
        }
#if defined BED_USES_THERMISTOR || defined BED_USES_AD595
        static int oldtBed=-1;
        static int oldtargetBed=-1;
        int tBed=intround(degBed());
        if((tBed!=oldtBed)||force_lcd_update) {
            lcd.setCursor(11,0);
            lcd.print(ftostr3(tBed));
            oldtBed=tBed;
        }
        int targetBed=intround(degTargetBed());
        if((targetBed!=oldtargetBed)||force_lcd_update) {
            lcd.setCursor(15,0);
            lcd.print(ftostr3(targetBed));
            oldtargetBed=targetBed;
        }
#elif EXTRUDERS > 1
        static int olddegHotEnd1=-1;
        static int oldtargetHotEnd1=-1;
        int tHotEnd1=intround(degHotend1());
        if((tHotEnd1!=olddegHotEnd1)||force_lcd_update) {
            lcd.setCursor(11,0);
            lcd.print(ftostr3(tHotEnd1));
            olddegHotEnd1=tHotEnd1;
        }
        int ttHotEnd1=intround(degTargetHotend1());
        if((ttHotEnd1!=oldtargetHotEnd1)||force_lcd_update) {
            lcd.setCursor(15,0);
            lcd.print(ftostr3(ttHotEnd1));
            oldtargetHotEnd1=ttHotEnd1;
        }
#endif
        //starttime=2;
        static uint16_t oldtime=0;
        if(starttime!=0) {
            lcd.setCursor(0,1);
            uint16_t time=millis()/60000-starttime/60000;
            if(starttime!=oldtime) {
                lcd.print(itostr2(time/60));
                LCD_PRINT_PGM("h ");
                lcd.print(itostr2(time%60));
                LCD_PRINT_PGM("m");
                oldtime=time;
            }
        }
        static int oldzpos=0;
        int currentz=current_position[2]*100;
        if((currentz!=oldzpos)||force_lcd_update) {
            lcd.setCursor(10,1);
            LCD_PRINT_PGM("Z:");
            lcd.print(ftostr52(current_position[2]));
            oldzpos=currentz;
        }
        static int oldfeedmultiply=0;
        int curfeedmultiply=feedmultiply;
        if(feedmultiplychanged == true) {
            feedmultiplychanged = false;
            encoderpos = curfeedmultiply;
        }
        if(encoderpos!=curfeedmultiply||force_lcd_update) {
            curfeedmultiply=encoderpos;
            if(curfeedmultiply<10)
                curfeedmultiply=10;
            if(curfeedmultiply>999)
                curfeedmultiply=999;
            feedmultiply=curfeedmultiply;
            encoderpos=curfeedmultiply;
        }
        if((curfeedmultiply!=oldfeedmultiply)||force_lcd_update) {
            oldfeedmultiply=curfeedmultiply;
            lcd.setCursor(0,2);
            lcd.print(itostr3(curfeedmultiply));
            LCD_PRINT_PGM("% ");
        }
        if(messagetext[0]!='\0') {
            lcd.setCursor(0,LCD_HEIGHT-1);
            lcd.print(messagetext);
            uint8_t n=strlen(messagetext);
            for(int8_t i=0; i<LCD_WIDTH-n; i++)
                lcd.print(" ");
            messagetext[0]='\0';
        }
#ifdef SDSUPPORT
        static uint8_t oldpercent=101;
        uint8_t percent=card.percentDone();
        if(oldpercent!=percent ||force_lcd_update) {
            lcd.setCursor(10,2);
            lcd.print(itostr3((int)percent));
            LCD_PRINT_PGM("%SD");
        }
#endif
#else //smaller LCDS----------------------------------
        static int olddegHotEnd0=-1;
        static int oldtargetHotEnd0=-1;
        if(force_lcd_update) { //initial display of content
            encoderpos=feedmultiply;
            lcd.setCursor(0,0);
            LCD_PRINT_PGM("\002---/---\001 ");
        }
        int tHotEnd0=intround(degHotend0());
        int ttHotEnd0=intround(degTargetHotend0());
        if((abs(tHotEnd0-olddegHotEnd0)>1)||force_lcd_update) {
            lcd.setCursor(1,0);
            lcd.print(ftostr3(tHotEnd0));
            olddegHotEnd0=tHotEnd0;
        }
        if((ttHotEnd0!=oldtargetHotEnd0)||force_lcd_update) {
            lcd.setCursor(5,0);
            lcd.print(ftostr3(ttHotEnd0));
            oldtargetHotEnd0=ttHotEnd0;
        }
        if(messagetext[0]!='\0') {
            lcd.setCursor(0,LCD_HEIGHT-1);
            lcd.print(messagetext);
            uint8_t n=strlen(messagetext);
            for(int8_t i=0; i<LCD_WIDTH-n; i++)
                lcd.print(" ");
            messagetext[0]='\0';
        }
#endif
        force_lcd_update=false;
    }
#endif
#if defined (upstream) && (defined (DOGLCD) && defined (ULTRA_LCD) )
    void lcd_setcontrast(uint8_t value) {
        lcd_contrast = value & 63;
        u8g.setContrast(lcd_contrast);
    }
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    enum {ItemP_exit, ItemP_autostart,ItemP_disstep,ItemP_home, ItemP_origin, ItemP_preheat_pla, ItemP_preheat_abs, ItemP_cooldown,/*ItemP_extrude,*/ItemP_move};
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    /* Warning: This function is called from interrupt context */
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
//any action must not contain a ',' character anywhere, or this breaks:
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    void lcd_buttons_update() {
#ifdef NEWPANEL
        uint8_t newbutton=0;
        if(READ(BTN_EN1)==0)  newbutton|=EN_A;
        if(READ(BTN_EN2)==0)  newbutton|=EN_B;
#if BTN_ENC > 0
        if((blocking_enc<millis()) && (READ(BTN_ENC)==0))
            newbutton |= EN_C;
#endif
        buttons = newbutton;
#ifdef LCD_HAS_SLOW_BUTTONS
        buttons |= slow_buttons;
#endif
#ifdef REPRAPWORLD_KEYPAD
        // for the reprapworld_keypad
        uint8_t newbutton_reprapworld_keypad=0;
        WRITE(SHIFT_LD,LOW);
        WRITE(SHIFT_LD,HIGH);
        for(int8_t i=0; i<8; i++) {
            newbutton_reprapworld_keypad = newbutton_reprapworld_keypad>>1;
            if(READ(SHIFT_OUT))
                newbutton_reprapworld_keypad|=(1<<7);
            WRITE(SHIFT_CLK,HIGH);
            WRITE(SHIFT_CLK,LOW);
        }
        buttons_reprapworld_keypad=~newbutton_reprapworld_keypad; //invert it, because a pressed switch produces a logical 0
#endif
#else   //read it from the shift register
        uint8_t newbutton=0;
        WRITE(SHIFT_LD,LOW);
        WRITE(SHIFT_LD,HIGH);
        unsigned char tmp_buttons=0;
        for(int8_t i=0; i<8; i++) {
            newbutton = newbutton>>1;
            if(READ(SHIFT_OUT))
                newbutton|=(1<<7);
            WRITE(SHIFT_CLK,HIGH);
            WRITE(SHIFT_CLK,LOW);
        }
        buttons=~newbutton; //invert it, because a pressed switch produces a logical 0
#endif//!NEWPANEL
        //manage encoder rotation
        uint8_t enc=0;
        if (buttons & EN_A) enc |= B01;
        if (buttons & EN_B) enc |= B10;
        if(enc != lastEncoderBits) {
            switch(enc) {
            case encrot0:
                if(lastEncoderBits==encrot3)
                    encoderDiff++;
                else if(lastEncoderBits==encrot1)
                    encoderDiff--;
                break;
            case encrot1:
                if(lastEncoderBits==encrot0)
                    encoderDiff++;
                else if(lastEncoderBits==encrot2)
                    encoderDiff--;
                break;
            case encrot2:
                if(lastEncoderBits==encrot1)
                    encoderDiff++;
                else if(lastEncoderBits==encrot3)
                    encoderDiff--;
                break;
            case encrot3:
                if(lastEncoderBits==encrot2)
                    encoderDiff++;
                else if(lastEncoderBits==encrot0)
                    encoderDiff--;
                break;
            }
        }
        lastEncoderBits = enc;
    }
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
#define MENUITEM(repaint_action, click_action) \
  {\
    if(force_lcd_update)  { lcd.setCursor(0,line);  repaint_action; } \
    if((activeline==line) && CLICKED) {click_action} \
  }
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    bool lcd_detected(void) {
#if (defined(LCD_I2C_TYPE_MCP23017) || defined(LCD_I2C_TYPE_MCP23008)) && defined(DETECT_DEVICE)
        return lcd.LcdDetected() == 1;
#else
        return true;
#endif
    }
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    void MainMenu::showPrepare() {
#ifdef ULTIPANEL
        uint8_t line=0;
        clearIfNecessary();
        for(int8_t i=lineoffset; i<lineoffset+LCD_HEIGHT; i++) {
            //Serial.println((int)(line-lineoffset));
            switch(i) {
            case ItemP_exit:
                MENUITEM(  LCD_PRINT_PGM(MSG_MAIN)  ,  BLOCK; status=Main_Menu; beepshort(); ) ;
                break;
            case ItemP_autostart:
                MENUITEM(  LCD_PRINT_PGM(MSG_AUTOSTART)  ,  BLOCK;
#ifdef SDSUPPORT
                           card.lastnr=0; card.setroot(); card.checkautostart(true);
#endif
                           beepshort(); ) ;
                break;
            case ItemP_disstep:
                MENUITEM(  LCD_PRINT_PGM(MSG_DISABLE_STEPPERS)  ,  BLOCK; enquecommand("M84"); beepshort(); ) ;
                break;
            case ItemP_home:
                MENUITEM(  LCD_PRINT_PGM(MSG_AUTO_HOME)  ,  BLOCK; enquecommand("G28"); beepshort(); ) ;
                break;
            case ItemP_origin:
                MENUITEM(  LCD_PRINT_PGM(MSG_SET_ORIGIN)  ,  BLOCK; enquecommand("G92 X0 Y0 Z0"); beepshort(); ) ;
                break;
            case ItemP_preheat_pla:
                MENUITEM(  LCD_PRINT_PGM(MSG_PREHEAT_PLA)  ,  BLOCK; setTargetHotend0(plaPreheatHotendTemp); setTargetBed(plaPreheatHPBTemp);
#if FAN_PIN > -1
                           FanSpeed = plaPreheatFanSpeed;
                           analogWrite(FAN_PIN,  FanSpeed);
#endif
                           beepshort(); );
                break;
            case ItemP_preheat_abs:
                MENUITEM(  LCD_PRINT_PGM(MSG_PREHEAT_ABS)  ,  BLOCK; setTargetHotend0(absPreheatHotendTemp); setTargetBed(absPreheatHPBTemp);
#if FAN_PIN > -1
                           FanSpeed = absPreheatFanSpeed;
                           analogWrite(FAN_PIN,  FanSpeed);
#endif
                           beepshort(); );
                break;
            case ItemP_cooldown:
                MENUITEM(  LCD_PRINT_PGM(MSG_COOLDOWN)  ,  BLOCK; setTargetHotend0(0); setTargetHotend1(0); setTargetHotend2(0); setTargetBed(0); beepshort(); ) ;
                break;
//    case ItemP_extrude:
            //    MENUITEM(  LCD_PRINT_PGM(" Extrude")  ,  BLOCK;enquecommand("G92 E0");enquecommand("G1 F700 E50");beepshort(); ) ;
            //  break;
            case ItemP_move:
                MENUITEM(  LCD_PRINT_PGM(MSG_MOVE_AXIS) , BLOCK; status=Sub_PrepareMove; beepshort(); );
                break;
            default:
                break;
            }
            line++;
        }
        updateActiveLines(ItemP_move,encoderpos);
#endif
    }
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    void lcd_buzz(long duration, uint16_t freq) {
#ifdef LCD_USE_I2C_BUZZER
        lcd.buzz(duration,freq);
#endif
    }
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    enum {
        ItemAM_exit,
        ItemAM_X, ItemAM_Y, ItemAM_Z, ItemAM_E, ItemAM_ERetract
    };
#endif
#if defined (upstream) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    bool lcd_clicked() {
        return LCD_CLICKED;
    }
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    void MainMenu::showAxisMove() {
        uint8_t line=0;
        int oldencoderpos=0;
        clearIfNecessary();
        for(int8_t i=lineoffset; i<lineoffset+LCD_HEIGHT; i++) {
            switch(i) {
            case ItemAM_exit:
                MENUITEM(  LCD_PRINT_PGM(MSG_PREPARE_ALT)  ,  BLOCK; status=Main_Prepare; beepshort(); ) ;
                break;
            case ItemAM_X: {
                //oldencoderpos=0;
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(" X:");
                    lcd.setCursor(11,line);
                    lcd.print(ftostr52(current_position[X_AXIS]));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        enquecommand("G91");
                    } else {
                        enquecommand("G90");
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if (encoderpos >0) {
                        enquecommand("G1 F700 X0.1");
                        oldencoderpos=encoderpos;
                        encoderpos=0;
                    } else if (encoderpos < 0) {
                        enquecommand("G1 F700 X-0.1");
                        oldencoderpos=encoderpos;
                        encoderpos=0;
                    }
                    lcd.setCursor(11,line);
                    lcd.print(ftostr52(current_position[X_AXIS]));
                }
            }
            break;
            case ItemAM_Y: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(" Y:");
                    lcd.setCursor(11,line);
                    lcd.print(ftostr52(current_position[Y_AXIS]));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        enquecommand("G91");
                    } else {
                        enquecommand("G90");
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if (encoderpos >0) {
                        enquecommand("G1 F700 Y0.1");
                        oldencoderpos=encoderpos;
                        encoderpos=0;
                    } else if (encoderpos < 0) {
                        enquecommand("G1 F700 Y-0.1");
                        oldencoderpos=encoderpos;
                        encoderpos=0;
                    }
                    lcd.setCursor(11,line);
                    lcd.print(ftostr52(current_position[Y_AXIS]));
                }
            }
            break;
            case ItemAM_Z: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(" Z:");
                    lcd.setCursor(11,line);
                    lcd.print(ftostr52(current_position[Z_AXIS]));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        enquecommand("G91");
                    } else {
                        enquecommand("G90");
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if (encoderpos >0) {
                        enquecommand("G1 F70 Z0.1");
                        oldencoderpos=encoderpos;
                        encoderpos=0;
                    } else if (encoderpos < 0) {
                        enquecommand("G1 F70 Z-0.1");
                        oldencoderpos=encoderpos;
                        encoderpos=0;
                    }
                    lcd.setCursor(11,line);
                    lcd.print(ftostr52(current_position[Z_AXIS]));
                }
            }
            break;
            case ItemAM_E:
                // ErikDB: TODO: this length should be changed for volumetric.
                MENUITEM(  LCD_PRINT_PGM(MSG_EXTRUDE)  ,  BLOCK; enquecommand("G92 E0"); enquecommand("G1 F70 E1"); beepshort(); ) ;
                break;
            case ItemAM_ERetract:
                // ErikDB: TODO: this length should be changed for volumetric.
                MENUITEM(  LCD_PRINT_PGM(MSG_RETRACT)  ,  BLOCK; enquecommand("G92 E0"); enquecommand("G1 F700 E-1"); beepshort(); ) ;
                break;
            default:
                break;
            }
            line++;
        }
        updateActiveLines(ItemAM_ERetract,encoderpos);
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
//ULTIPANEL
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    enum {ItemT_exit,ItemT_speed,ItemT_flow,ItemT_nozzle,
#if (HEATER_BED_PIN > -1)
          ItemT_bed,
#endif
          ItemT_fan
         };
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    /********************************/
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    void MainMenu::showTune() {
        uint8_t line=0;
        clearIfNecessary();
        for(int8_t i=lineoffset; i<lineoffset+LCD_HEIGHT; i++) {
            //Serial.println((int)(line-lineoffset));
            switch(i) {
            case ItemT_exit:
                MENUITEM(  LCD_PRINT_PGM(MSG_MAIN)  ,  BLOCK; status=Main_Menu; beepshort(); ) ;
                break;
            case ItemT_speed: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_SPEED);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(feedmultiply));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) { //AnalogWrite(FAN_PIN,  fanpwm);
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=feedmultiply;
                    } else {
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<1) encoderpos=1;
                    if(encoderpos>400) encoderpos=400;
                    feedmultiply = encoderpos;
                    feedmultiplychanged=true;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
            case ItemT_nozzle: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_NOZZLE);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(intround(degTargetHotend0())));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=intround(degTargetHotend0());
                    } else {
                        setTargetHotend0(encoderpos);
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>260) encoderpos=260;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
#if (HEATER_BED_PIN > -1)
            case ItemT_bed: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_BED);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(intround(degTargetBed())));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=intround(degTargetBed());
                    } else {
                        setTargetBed(encoderpos);
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>260) encoderpos=260;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
#endif
            case ItemT_fan: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_FAN_SPEED);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(FanSpeed));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) { //nalogWrite(FAN_PIN,  fanpwm);
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=FanSpeed;
                    } else {
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>255) encoderpos=255;
                    FanSpeed=encoderpos;
                    analogWrite(FAN_PIN,  FanSpeed);
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
            case ItemT_flow: { //axis_steps_per_unit[i] = code_value();
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_FLOW);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr52(axis_steps_per_unit[E_AXIS]));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)(axis_steps_per_unit[E_AXIS]*100.0);
                    } else {
                        float factor=float(encoderpos)/100.0/float(axis_steps_per_unit[E_AXIS]);
                        position[E_AXIS]=lround(position[E_AXIS]*factor);
                        //current_position[E_AXIS]*=factor;
                        axis_steps_per_unit[E_AXIS]= encoderpos/100.0;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<5) encoderpos=5;
                    if(encoderpos>999999) encoderpos=999999;
                    lcd.setCursor(13,line);
                    lcd.print(ftostr52(encoderpos/100.0));
                }
            }
            break;
            default:
                break;
            }
            line++;
        }
        updateActiveLines(ItemT_fan,encoderpos);
    }
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    void MainMenu::showTune() {
        uint8_t line=0;
        clearIfNecessary();
        for(int8_t i=lineoffset; i<lineoffset+LCD_HEIGHT; i++) {
            //Serial.println((int)(line-lineoffset));
            switch(i) {
            case ItemT_exit:
                MENUITEM(  LCD_PRINT_PGM(MSG_MAIN)  ,  BLOCK; status=Main_Menu; beepshort(); ) ;
                break;
            case ItemT_speed: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_SPEED);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(feedmultiply));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) { //AnalogWrite(FAN_PIN,  fanpwm);
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=feedmultiply;
                    } else {
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<1) encoderpos=1;
                    if(encoderpos>400) encoderpos=400;
                    feedmultiply = encoderpos;
                    feedmultiplychanged=true;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
            case ItemT_nozzle: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_NOZZLE);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(intround(degTargetHotend0())));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=intround(degTargetHotend0());
                    } else {
                        setTargetHotend0(encoderpos);
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>260) encoderpos=260;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
#if (HEATER_BED_PIN > -1)
            case ItemT_bed: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_BED);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(intround(degTargetBed())));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=intround(degTargetBed());
                    } else {
                        setTargetBed(encoderpos);
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>260) encoderpos=260;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
#endif
            case ItemT_fan: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_FAN_SPEED);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(FanSpeed));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) { //nalogWrite(FAN_PIN,  fanpwm);
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=FanSpeed;
                    } else {
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>255) encoderpos=255;
                    FanSpeed=encoderpos;
                    analogWrite(FAN_PIN,  FanSpeed);
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
            case ItemT_flow: { //axis_steps_per_unit[i] = code_value();
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_FLOW);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr52(axis_steps_per_unit[E_AXIS]));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)(axis_steps_per_unit[E_AXIS]*100.0);
                    } else {
                        float factor=float(encoderpos)/100.0/float(axis_steps_per_unit[E_AXIS]);
                        position[E_AXIS]=lround(position[E_AXIS]*factor);
                        //current_position[E_AXIS]*=factor;
                        axis_steps_per_unit[E_AXIS]= encoderpos/100.0;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<5) encoderpos=5;
                    if(encoderpos>999999) encoderpos=999999;
                    lcd.setCursor(13,line);
                    lcd.print(ftostr52(encoderpos/100.0));
                }
            }
            break;
            default:
                break;
            }
            line++;
        }
        updateActiveLines(ItemT_fan,encoderpos);
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    /** Float conversion utilities **/
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    /*does not work
    #define MENUCHANGEITEM(repaint_action,  enter_action, accept_action,  change_action) \
       {\
         if(force_lcd_update)  { lcd.setCursor(0,line);  repaint_action; } \
         if(activeline==line)  \
         { \
           if(CLICKED) \
           { \
             linechanging=!linechanging; \
             if(linechanging)  {enter_action;} \
             else {accept_action;} \
           }  \
           else \
           if(linechanging) {change_action};}\
       }
    */
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    /********************************/
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
    enum {
        ItemCT_exit,ItemCT_nozzle0,
#ifdef AUTOTEMP
        ItemCT_autotempactive,
        ItemCT_autotempmin,ItemCT_autotempmax,ItemCT_autotempfact,
#endif
#if EXTRUDERS > 1
        ItemCT_nozzle1,
#endif
#if EXTRUDERS > 2
        ItemCT_nozzle2,
#endif
#if defined BED_USES_THERMISTOR || defined BED_USES_AD595
        ItemCT_bed,
#endif
        ItemCT_fan,
        ItemCT_PID_P,ItemCT_PID_I,ItemCT_PID_D,ItemCT_PID_C,
        ItemCT_PLA_PreHeat_Setting,
        ItemCT_ABS_PreHeat_Setting,
    };
    void MainMenu::showControlTemp() {
        uint8_t line=0;
        clearIfNecessary();
        for(int8_t i=lineoffset; i<lineoffset+LCD_HEIGHT; i++) {
            switch(i) {
            case ItemCT_exit:
                MENUITEM(  LCD_PRINT_PGM(MSG_CONTROL)  ,  BLOCK; status=Main_Control; beepshort(); ) ;
                break;
            case ItemCT_nozzle0: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_NOZZLE);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(intround(degTargetHotend0())));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=intround(degTargetHotend0());
                    } else {
                        setTargetHotend0(encoderpos);
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>260) encoderpos=260;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
#if EXTRUDERS > 1
            case ItemCT_nozzle1: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_NOZZLE1);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(intround(degTargetHotend1())));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=intround(degTargetHotend1());
                    } else {
                        setTargetHotend1(encoderpos);
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>260) encoderpos=260;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
#endif
#if EXTRUDERS > 2
            case ItemCT_nozzle2: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_NOZZLE2);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(intround(degTargetHotend2())));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=intround(degTargetHotend2());
                    } else {
                        setTargetHotend2(encoderpos);
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>260) encoderpos=260;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
#endif
#ifdef AUTOTEMP
            case ItemCT_autotempmin: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_MIN);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(autotemp_min));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=intround(autotemp_min);
                    } else {
                        autotemp_min=encoderpos;
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>260) encoderpos=260;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
            case ItemCT_autotempmax: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_MAX);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(autotemp_max));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=intround(autotemp_max);
                    } else {
                        autotemp_max=encoderpos;
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>260) encoderpos=260;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
            case ItemCT_autotempfact: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_FACTOR);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr32(autotemp_factor));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=intround(autotemp_factor*100);
                    } else {
                        autotemp_max=encoderpos;
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>99) encoderpos=99;
                    lcd.setCursor(13,line);
                    lcd.print(ftostr32(encoderpos/100.));
                }
            }
            break;
            case ItemCT_autotempactive: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_AUTOTEMP);
                    lcd.setCursor(13,line);
                    if(autotemp_enabled)
                        LCD_PRINT_PGM(MSG_ON);
                    else
                        LCD_PRINT_PGM(MSG_OFF);
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    autotemp_enabled=!autotemp_enabled;
                    lcd.setCursor(13,line);
                    if(autotemp_enabled)
                        LCD_PRINT_PGM(MSG_ON);
                    else
                        LCD_PRINT_PGM(MSG_OFF);
                    BLOCK;
                }
            }
            break;
#endif //autotemp
#if defined BED_USES_THERMISTOR || defined BED_USES_AD595
            case ItemCT_bed: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_BED);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(intround(degTargetBed())));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=intround(degTargetBed());
                    } else {
                        setTargetBed(encoderpos);
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>260) encoderpos=260;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
#endif
            case ItemCT_fan: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_FAN_SPEED);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(FanSpeed));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) { //nalogWrite(FAN_PIN,  fanpwm);
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=FanSpeed;
                    } else {
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>255) encoderpos=255;
                    FanSpeed=encoderpos;
                    analogWrite(FAN_PIN,  FanSpeed);
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
#ifdef PIDTEMP
            case ItemCT_PID_P: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(" PID-P: ");
                    lcd.setCursor(13,line);
                    lcd.print(itostr4(Kp));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)Kp;
                    } else {
                        Kp= encoderpos;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<1) encoderpos=1;
                    if(encoderpos>9990) encoderpos=9990;
                    lcd.setCursor(13,line);
                    lcd.print(itostr4(encoderpos));
                }
            }
            break;
            case ItemCT_PID_I: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_PID_I);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr51(Ki/PID_dT));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)(Ki*10/PID_dT);
                    } else {
                        Ki= encoderpos/10.*PID_dT;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>9990) encoderpos=9990;
                    lcd.setCursor(13,line);
                    lcd.print(ftostr51(encoderpos/10.));
                }
            }
            break;
            case ItemCT_PID_D: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_PID_D);
                    lcd.setCursor(13,line);
                    lcd.print(itostr4(Kd*PID_dT));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)(Kd/5./PID_dT);
                    } else {
                        Kd= encoderpos;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>9990) encoderpos=9990;
                    lcd.setCursor(13,line);
                    lcd.print(itostr4(encoderpos));
                }
            }
            break;
            case ItemCT_PID_C:
#ifdef PID_ADD_EXTRUSION_RATE
            {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_PID_C);
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(Kc));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)Kc;
                    } else {
                        Kc= encoderpos;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>990) encoderpos=990;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
#endif
#endif
            break;
            case ItemCT_PLA_PreHeat_Setting:
                MENUITEM(  LCD_PRINT_PGM(MSG_PREHEAT_PLA_SETTINGS)  ,  BLOCK; status=Sub_PreheatPLASettings; beepshort(); ) ;
                break;
            case ItemCT_ABS_PreHeat_Setting:
                MENUITEM(  LCD_PRINT_PGM(MSG_PREHEAT_ABS_SETTINGS)  ,  BLOCK; status=Sub_PreheatABSSettings; beepshort(); ) ;
                break;
            default:
                break;
            }
            line++;
        }
        updateActiveLines(ItemCT_ABS_PreHeat_Setting,encoderpos);
    }
    enum {
        ItemCM_exit,
        ItemCM_acc, ItemCM_xyjerk,
        ItemCM_vmaxx, ItemCM_vmaxy, ItemCM_vmaxz, ItemCM_vmaxe,
        ItemCM_vtravmin,ItemCM_vmin,
        ItemCM_amaxx, ItemCM_amaxy, ItemCM_amaxz, ItemCM_amaxe,
        ItemCM_aret, ItemCM_xsteps,ItemCM_ysteps, ItemCM_zsteps, ItemCM_esteps
    };
    void MainMenu::showControlMotion() {
        uint8_t line=0;
        clearIfNecessary();
        for(int8_t i=lineoffset; i<lineoffset+LCD_HEIGHT; i++) {
            switch(i) {
            case ItemCM_exit:
                MENUITEM(  LCD_PRINT_PGM(MSG_CONTROL)  ,  BLOCK; status=Main_Control; beepshort(); ) ;
                break;
            case ItemCM_acc: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_ACC);
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(acceleration/100));
                    LCD_PRINT_PGM("00");
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)acceleration/100;
                    } else {
                        acceleration= encoderpos*100;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<5) encoderpos=5;
                    if(encoderpos>990) encoderpos=990;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                    LCD_PRINT_PGM("00");
                }
            }
            break;
            case ItemCM_xyjerk: { //max_xy_jerk
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_VXY_JERK);
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(max_xy_jerk));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)max_xy_jerk;
                    } else {
                        max_xy_jerk= encoderpos;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<1) encoderpos=1;
                    if(encoderpos>990) encoderpos=990;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
            case ItemCM_vmaxx:
            case ItemCM_vmaxy:
            case ItemCM_vmaxz:
            case ItemCM_vmaxe: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_VMAX);
                    if(i==ItemCM_vmaxx)LCD_PRINT_PGM(MSG_X);
                    if(i==ItemCM_vmaxy)LCD_PRINT_PGM(MSG_Y);
                    if(i==ItemCM_vmaxz)LCD_PRINT_PGM(MSG_Z);
                    if(i==ItemCM_vmaxe)LCD_PRINT_PGM(MSG_E);
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(max_feedrate[i-ItemCM_vmaxx]));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)max_feedrate[i-ItemCM_vmaxx];
                    } else {
                        max_feedrate[i-ItemCM_vmaxx]= encoderpos;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<1) encoderpos=1;
                    if(encoderpos>990) encoderpos=990;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
            case ItemCM_vmin: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_VMIN);
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(minimumfeedrate));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)(minimumfeedrate);
                    } else {
                        minimumfeedrate= encoderpos;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>990) encoderpos=990;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
            case ItemCM_vtravmin: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_VTRAV_MIN);
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(mintravelfeedrate));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)mintravelfeedrate;
                    } else {
                        mintravelfeedrate= encoderpos;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>990) encoderpos=990;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
            case ItemCM_amaxx:
            case ItemCM_amaxy:
            case ItemCM_amaxz:
            case ItemCM_amaxe: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(" Amax ");
                    if(i==ItemCM_amaxx)LCD_PRINT_PGM(MSG_X);
                    if(i==ItemCM_amaxy)LCD_PRINT_PGM(MSG_Y);
                    if(i==ItemCM_amaxz)LCD_PRINT_PGM(MSG_Z);
                    if(i==ItemCM_amaxe)LCD_PRINT_PGM(MSG_E);
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(max_acceleration_units_per_sq_second[i-ItemCM_amaxx]/100));
                    LCD_PRINT_PGM("00");
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)max_acceleration_units_per_sq_second[i-ItemCM_amaxx]/100;
                    } else {
                        max_acceleration_units_per_sq_second[i-ItemCM_amaxx]= encoderpos*100;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<1) encoderpos=1;
                    if(encoderpos>990) encoderpos=990;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                    LCD_PRINT_PGM("00");
                }
            }
            break;
            case ItemCM_aret: { //float retract_acceleration = 7000;
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_A_RETRACT);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(retract_acceleration/100));
                    LCD_PRINT_PGM("00");
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)retract_acceleration/100;
                    } else {
                        retract_acceleration= encoderpos*100;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<10) encoderpos=10;
                    if(encoderpos>990) encoderpos=990;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                    LCD_PRINT_PGM("00");
                }
            }
            break;
            case ItemCM_xsteps: { //axis_steps_per_unit[i] = code_value();
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_XSTEPS);
                    lcd.setCursor(11,line);
                    lcd.print(ftostr52(axis_steps_per_unit[X_AXIS]));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)(axis_steps_per_unit[X_AXIS]*100.0);
                    } else {
                        float factor=float(encoderpos)/100.0/float(axis_steps_per_unit[X_AXIS]);
                        position[X_AXIS]=lround(position[X_AXIS]*factor);
                        //current_position[X_AXIS]*=factor;
                        axis_steps_per_unit[X_AXIS]= encoderpos/100.0;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<5) encoderpos=5;
                    if(encoderpos>999999) encoderpos=999999;
                    lcd.setCursor(11,line);
                    lcd.print(ftostr52(encoderpos/100.0));
                }
            }
            break;
            case ItemCM_ysteps: { //axis_steps_per_unit[i] = code_value();
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_YSTEPS);
                    lcd.setCursor(11,line);
                    lcd.print(ftostr52(axis_steps_per_unit[Y_AXIS]));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)(axis_steps_per_unit[Y_AXIS]*100.0);
                    } else {
                        float factor=float(encoderpos)/100.0/float(axis_steps_per_unit[Y_AXIS]);
                        position[Y_AXIS]=lround(position[Y_AXIS]*factor);
                        //current_position[Y_AXIS]*=factor;
                        axis_steps_per_unit[Y_AXIS]= encoderpos/100.0;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<5) encoderpos=5;
                    if(encoderpos>999999) encoderpos=999999;
                    lcd.setCursor(11,line);
                    lcd.print(ftostr52(encoderpos/100.0));
                }
            }
            break;
            case ItemCM_zsteps: { //axis_steps_per_unit[i] = code_value();
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_ZSTEPS);
                    lcd.setCursor(11,line);
                    lcd.print(ftostr51(axis_steps_per_unit[Z_AXIS]));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)(axis_steps_per_unit[Z_AXIS]*100.0);
                    } else {
                        float factor=float(encoderpos)/100.0/float(axis_steps_per_unit[Z_AXIS]);
                        position[Z_AXIS]=lround(position[Z_AXIS]*factor);
                        //current_position[Z_AXIS]*=factor;
                        axis_steps_per_unit[Z_AXIS]= encoderpos/100.0;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<5) encoderpos=5;
                    if(encoderpos>999999) encoderpos=999999;
                    lcd.setCursor(11,line);
                    lcd.print(ftostr52(encoderpos/100.0));
                }
            }
            break;
            case ItemCM_esteps: { //axis_steps_per_unit[i] = code_value();
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_ESTEPS);
                    lcd.setCursor(11,line);
                    lcd.print(ftostr51(axis_steps_per_unit[E_AXIS]));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)(axis_steps_per_unit[E_AXIS]*100.0);
                    } else {
                        float factor=float(encoderpos)/100.0/float(axis_steps_per_unit[E_AXIS]);
                        position[E_AXIS]=lround(position[E_AXIS]*factor);
                        //current_position[E_AXIS]*=factor;
                        axis_steps_per_unit[E_AXIS]= encoderpos/100.0;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<5) encoderpos=5;
                    if(encoderpos>999999) encoderpos=999999;
                    lcd.setCursor(11,line);
                    lcd.print(ftostr52(encoderpos/100.0));
                }
            }
            break;
            default:
                break;
            }
            line++;
        }
        updateActiveLines(ItemCM_esteps,encoderpos);
    }
    enum {
        ItemR_exit,
        ItemR_autoretract,
        ItemR_retract_length,ItemR_retract_feedrate,ItemR_retract_zlift,
        ItemR_unretract_length,ItemR_unretract_feedrate,

    };
    void MainMenu::showControlRetract() {
#ifdef FWRETRACT
        uint8_t line=0;
        clearIfNecessary();
        for(int8_t i=lineoffset; i<lineoffset+LCD_HEIGHT; i++) {
            switch(i) {
            case ItemR_exit:
                MENUITEM(  LCD_PRINT_PGM(MSG_CONTROL)  ,  BLOCK; status=Main_Control; beepshort(); ) ;
                break;
            //float retract_length=2, retract_feedrate=1200, retract_zlift=0.4;
            //float retract_recover_length=0, retract_recover_feedrate=500;
            case ItemR_autoretract: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_AUTORETRACT);
                    lcd.setCursor(13,line);
                    if(autoretract_enabled)
                        LCD_PRINT_PGM(MSG_ON);
                    else
                        LCD_PRINT_PGM(MSG_OFF);
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    autoretract_enabled=!autoretract_enabled;
                    lcd.setCursor(13,line);
                    if(autoretract_enabled)
                        LCD_PRINT_PGM(MSG_ON);
                    else
                        LCD_PRINT_PGM(MSG_OFF);
                    BLOCK;
                }
            }
            break;
            case ItemR_retract_length: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_CONTROL_RETRACT);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr52(retract_length));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)(retract_length*100);
                    } else {
                        retract_length= encoderpos/100.;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<1) encoderpos=1;
                    if(encoderpos>990) encoderpos=990;
                    lcd.setCursor(13,line);
                    lcd.print(ftostr52(encoderpos/100.));
                }
            }
            break;
            case ItemR_retract_feedrate: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_CONTROL_RETRACTF);
                    lcd.setCursor(13,line);
                    lcd.print(itostr4(retract_feedrate));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)(retract_feedrate/5);
                    } else {
                        retract_feedrate= encoderpos*5.;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<1) encoderpos=1;
                    if(encoderpos>990) encoderpos=990;
                    lcd.setCursor(13,line);
                    lcd.print(itostr4(encoderpos*5));
                }
            }
            break;
            case ItemR_retract_zlift: { //float retract_acceleration = 7000;
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_CONTROL_RETRACT_ZLIFT);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr52(retract_zlift));;
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)(retract_zlift*10);
                    } else {
                        retract_zlift= encoderpos/10.;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>990) encoderpos=990;
                    lcd.setCursor(13,line);
                    lcd.print(ftostr52(encoderpos/10.));
                }
            }
            break;
            case ItemR_unretract_length: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_CONTROL_RETRACT_RECOVER);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr52(retract_recover_length));;
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)(retract_recover_length*100);
                    } else {
                        retract_recover_length= encoderpos/100.;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>990) encoderpos=990;
                    lcd.setCursor(13,line);
                    lcd.print(ftostr52(encoderpos/100.));
                }
            }
            break;
            case ItemR_unretract_feedrate: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_CONTROL_RETRACT_RECOVERF);
                    lcd.setCursor(13,line);
                    lcd.print(itostr4(retract_recover_feedrate));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=(long)retract_recover_feedrate/5;
                    } else {
                        retract_recover_feedrate= encoderpos*5.;
                        encoderpos=activeline*lcdslow;
                    }
                    BLOCK;
                    beepshort();
                }
                if(linechanging) {
                    if(encoderpos<1) encoderpos=1;
                    if(encoderpos>990) encoderpos=990;
                    lcd.setCursor(13,line);
                    lcd.print(itostr4(encoderpos*5));
                }
            }
            break;
            default:
                break;
            }
            line++;
        }
        updateActiveLines(ItemR_unretract_feedrate,encoderpos);
#endif
    }
    enum {
        ItemC_exit,ItemC_temp,ItemC_move,
#ifdef FWRETRACT
        ItemC_rectract,
#endif
        ItemC_store, ItemC_load,ItemC_failsafe
    };
    void MainMenu::showControl() {
        uint8_t line=0;
        clearIfNecessary();
        for(int8_t i=lineoffset; i<lineoffset+LCD_HEIGHT; i++) {
            switch(i) {
            case ItemC_exit:
                MENUITEM(  LCD_PRINT_PGM(MSG_MAIN_WIDE)  ,  BLOCK; status=Main_Menu; beepshort(); ) ;
                break;
            case ItemC_temp:
                MENUITEM(  LCD_PRINT_PGM(MSG_TEMPERATURE_WIDE)  ,  BLOCK; status=Sub_TempControl; beepshort(); ) ;
                break;
            case ItemC_move:
                MENUITEM(  LCD_PRINT_PGM(MSG_MOTION_WIDE)  ,  BLOCK; status=Sub_MotionControl; beepshort(); ) ;
                break;
#ifdef FWRETRACT
            case ItemC_rectract:
                MENUITEM(  LCD_PRINT_PGM(MSG_RECTRACT_WIDE)  ,  BLOCK; status=Sub_RetractControl; beepshort(); ) ;
                break;
#endif
            case ItemC_store: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_STORE_EPROM);
                }
                if((activeline==line) && CLICKED) {
                    //enquecommand("M84");
                    beepshort();
                    BLOCK;
                    Config_StoreSettings();
                }
            }
            break;
            case ItemC_load: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_LOAD_EPROM);
                }
                if((activeline==line) && CLICKED) {
                    //enquecommand("M84");
                    beepshort();
                    BLOCK;
                    Config_RetrieveSettings();
                }
            }
            break;
            case ItemC_failsafe: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_RESTORE_FAILSAFE);
                }
                if((activeline==line) && CLICKED) {
                    //enquecommand("M84");
                    beepshort();
                    BLOCK;
                    Config_ResetDefault();
                }
            }
            break;
            default:
                break;
            }
            line++;
        }
        updateActiveLines(ItemC_failsafe,encoderpos);
    }
    void MainMenu::showSD() {
#ifdef SDSUPPORT
        uint8_t line=0;
        clearIfNecessary();
        static uint8_t nrfiles=0;
        if(force_lcd_update) {
            if(card.cardOK) {
                nrfiles=card.getnrfilenames();
            } else {
                nrfiles=0;
                lineoffset=0;
            }
        }
        bool enforceupdate=false;
        for(int8_t i=lineoffset; i<lineoffset+LCD_HEIGHT; i++) {
            switch(i) {
            case 0:
                MENUITEM(  LCD_PRINT_PGM(MSG_MAIN)  ,  BLOCK; status=Main_Menu; beepshort(); ) ;
                break;
//     case 1:
//       {
//         if(force_lcd_update)
//         {
//           lcd.setCursor(0,line);
//           if(CARDINSERTED)
//           {
//             LCD_PRINT_PGM(" \004Refresh");
//           }
//           else
//           {
//             LCD_PRINT_PGM(" \004Insert Card");
//           }
//
//         }
//         if((activeline==line) && CLICKED)
//         {
//           BLOCK;
//           beepshort();
//           card.initsd();
//           force_lcd_update=true;
//            nrfiles=card.getnrfilenames();
//         }
//       }break;
            case 1:
                MENUITEM(  lcd.print(" "); card.getWorkDirName();
                           if(card.filename[0]=='/') LCD_PRINT_PGM(MSG_REFRESH);
                else {
                    lcd.print("\005");
                        lcd.print(card.filename);
                        lcd.print("/..");
                    }  ,
                BLOCK;
                if(SDCARDDETECT == -1) card.initsd();
                card.updir();
                enforceupdate=true;
                              lineoffset=0;
                              beepshort(); ) ;
                break;
            default: {
#define FIRSTITEM 2
                if(i-FIRSTITEM<nrfiles) {
                    if(force_lcd_update) {
                        card.getfilename(i-FIRSTITEM);
                        //Serial.print("Filenr:");Serial.println(i-2);
                        lcd.setCursor(0,line);
                        LCD_PRINT_PGM(" ");
                        if(card.filenameIsDir) {
                            lcd.print("\005");
                            card.longFilename[LCD_WIDTH-2] = '\0';
                        }
                        if (card.longFilename[0]) {
                            card.longFilename[LCD_WIDTH-1] = '\0';
                            lcd.print(card.longFilename);
                        } else {
                            lcd.print(card.filename);
                        }
                    }
                    if((activeline==line) && CLICKED) {
                        BLOCK
                        card.getfilename(i-FIRSTITEM);
                        if(card.filenameIsDir) {
                            for(uint8_t i=0; i<strlen(card.filename); i++)
                                card.filename[i]=tolower(card.filename[i]);
                            card.chdir(card.filename);
                            lineoffset=0;
                            enforceupdate=true;
                        } else {
                            char cmd[30];
                            for(uint8_t i=0; i<strlen(card.filename); i++)
                                card.filename[i]=tolower(card.filename[i]);
                            sprintf(cmd,"M23 %s",card.filename);
                            //sprintf(cmd,"M115");
                            enquecommand(cmd);
                            enquecommand("M24");
                            beep();
                            status=Main_Status;
                            if (card.longFilename[0]) {
                                card.longFilename[LCD_WIDTH-1] = '\0';
                                lcd_status(card.longFilename);
                            } else {
                                lcd_status(card.filename);
                            }
                        }
                    }
                }
            }
            break;
            }
            line++;
        }
        updateActiveLines(FIRSTITEM+nrfiles-1,encoderpos);
        if(enforceupdate) {
            force_lcd_update=true;
            enforceupdate=false;
        }
#endif
    }
    enum {ItemM_watch, ItemM_prepare, ItemM_control, ItemM_file, ItemM_pause};
    void MainMenu::showMainMenu() {
#ifndef ULTIPANEL
        force_lcd_update=false;
#endif
        if(tune) {
            if(!(movesplanned() || IS_SD_PRINTING)) {
                force_lcd_update=true;
                tune=false;
            }
        } else {
            if(movesplanned() || IS_SD_PRINTING) {
                force_lcd_update=true;
                tune=true;
            }
        }
        clearIfNecessary();
        uint8_t line=0;
        for(int8_t i=lineoffset; i<lineoffset+LCD_HEIGHT; i++) {
            switch(i) {
            case ItemM_watch:
                MENUITEM(  LCD_PRINT_PGM(MSG_WATCH)  ,  BLOCK; status=Main_Status; beepshort(); ) ;
                break;
            case ItemM_prepare:
                MENUITEM(  if(!tune) LCD_PRINT_PGM(MSG_PREPARE); else  LCD_PRINT_PGM(MSG_TUNE); ,  BLOCK; status=Main_Prepare; beepshort(); ) ;
                break;
            case ItemM_control:
                MENUITEM(  LCD_PRINT_PGM(MSG_CONTROL_ARROW)  ,  BLOCK; status=Main_Control; beepshort(); ) ;
                break;
#ifdef SDSUPPORT
            case ItemM_file: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    if(CARDINSERTED) {
                        if(card.sdprinting)
                            LCD_PRINT_PGM(MSG_STOP_PRINT);
                        else
                            LCD_PRINT_PGM(MSG_CARD_MENU);
                    } else {
                        LCD_PRINT_PGM(MSG_NO_CARD);
                    }
                }
                if(CARDINSERTED&&(activeline==line)&&CLICKED) {
                    card.printingHasFinished();
                    BLOCK;
                    status=Main_SD;
                    beepshort();
                }
            }
            break;
            case ItemM_pause: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    if(CARDINSERTED) {
                        if(card.sdprinting)
                            LCD_PRINT_PGM(MSG_PAUSE_PRINT);
                        else
                            LCD_PRINT_PGM(MSG_RESUME_PRINT);
                    } else {
                        //LCD_PRINT_PGM(MSG_NO_CARD);
                    }
                }
                if(CARDINSERTED && (activeline==line) && CLICKED) {
                    if(card.sdprinting) {
                        card.pauseSDPrint();
                        beepshort();
                        status = Main_Status;
                    } else {
                        card.startFileprint();
                        starttime=millis();
                        beepshort();
                        status = Main_Status;
                    }
                }
            }
            break;
#else
            case ItemM_file:
                break;
            case ItemM_pause:
                break;
#endif
            default:
                SERIAL_ERROR_START;
                SERIAL_ERRORLNPGM(MSG_SERIAL_ERROR_MENU_STRUCTURE);
                break;
            }
            line++;
        }
        uint8_t numberOfLines = 4;
#ifdef SDSUPPORT
        numberOfLines = 4;
#else
        numberOfLines = 3;
#endif
        updateActiveLines(numberOfLines,encoderpos);
    }
    void MainMenu::update() {
        static MainStatus oldstatus=Main_Menu;  //init automatically causes foce_lcd_update=true
        static unsigned long timeoutToStatus=0;
#if (SDCARDDETECT > -1)
        //This code is only relivant if you have an SDcard detect pin.
        static bool oldcardstatus=false;
        if((CARDINSERTED != oldcardstatus)) {
            force_lcd_update=true;
            oldcardstatus=CARDINSERTED;
            lcd_init(); // to maybe revive the lcd if static electricty killed it.
            //Serial.println("echo: SD CHANGE");
            if(CARDINSERTED) {
                card.initsd();
                LCD_MESSAGEPGM(MSG_SD_INSERTED);
            } else {
                card.release();
                LCD_MESSAGEPGM(MSG_SD_REMOVED);
            }
        }
#endif
        if(status!=oldstatus) {
            force_lcd_update=true;
            encoderpos=0;
            lineoffset=0;
            oldstatus=status;
        }
        if( (encoderpos!=lastencoderpos) || CLICKED)
            timeoutToStatus=millis()+STATUSTIMEOUT;
        switch(status) {
        case Main_Status: {
            showStatus();
            if(CLICKED) {
                linechanging=false;
                BLOCK
                status=Main_Menu;
                timeoutToStatus=millis()+STATUSTIMEOUT;
            }
        }
        break;
        case Main_Menu: {
            showMainMenu();
            linechanging=false;
        }
        break;
        case Main_Prepare: {
            if(tune) {
                showTune();
            } else {
                showPrepare();
            }
        }
        break;
        case Sub_PrepareMove: {
            showAxisMove();
        }
        break;
        case Main_Control: {
            showControl();
        }
        break;
        case Sub_MotionControl: {
            showControlMotion();
        }
        break;
        case Sub_RetractControl: {
            showControlRetract();
        }
        break;
        case Sub_TempControl: {
            showControlTemp();
        }
        break;
        case Main_SD: {
            showSD();
        }
        break;
        case Sub_PreheatPLASettings: {
            showPLAsettings();
        }
        break;
        case Sub_PreheatABSSettings: {
            showABSsettings();
        }
        break;
        }
        if(timeoutToStatus<millis())
            status=Main_Status;
        //force_lcd_update=false;
        lastencoderpos=encoderpos;
    }
    enum {
        ItemPLAPreHeat_Exit,
        ItemPLAPreHeat_set_PLA_FanSpeed,
        ItemPLAPreHeat_set_nozzle,
        ItemPLAPreHeat_set_HPB,
        ItemPLAPreHeat_Store_Eprom
    };
    void MainMenu::showPLAsettings() {
#ifdef ULTIPANEL
        uint8_t line=0;
        clearIfNecessary();
        for(int8_t i=lineoffset; i<lineoffset+LCD_HEIGHT; i++) {
            switch(i) {
            case ItemPLAPreHeat_Exit:
                MENUITEM(  LCD_PRINT_PGM(MSG_TEMPERATURE_RTN)  ,  BLOCK; status=Sub_TempControl; beepshort(); ) ;
                break;
            case ItemPLAPreHeat_set_PLA_FanSpeed: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_FAN_SPEED);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(plaPreheatFanSpeed));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=plaPreheatFanSpeed;
                    } else {
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>255) encoderpos=255;
                    plaPreheatFanSpeed=encoderpos;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
            case ItemPLAPreHeat_set_nozzle: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_NOZZLE);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(plaPreheatHotendTemp));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=plaPreheatHotendTemp;
                    } else {
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>260) encoderpos=260;
                    plaPreheatHotendTemp = encoderpos;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
            case ItemPLAPreHeat_set_HPB: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_BED);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(plaPreheatHPBTemp));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=plaPreheatHPBTemp;
                    } else {
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>250) encoderpos=150;
                    plaPreheatHPBTemp = encoderpos;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
            case ItemPLAPreHeat_Store_Eprom: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_STORE_EPROM);
                }
                if((activeline==line) && CLICKED) {
                    //enquecommand("M84");
                    beepshort();
                    BLOCK;
                    Config_StoreSettings();
                }
            }
            break;
            default:
                break;
            }
            line++;
        }
        updateActiveLines(ItemPLAPreHeat_Store_Eprom,encoderpos);
#endif
    }
    enum {
        ItemABSPreHeat_Exit,
        ItemABSPreHeat_set_FanSpeed,
        ItemABSPreHeat_set_nozzle,
        ItemABSPreHeat_set_HPB,
        ItemABSPreHeat_Store_Eprom
    };
    void MainMenu::showABSsettings() {
#ifdef ULTIPANEL
        uint8_t line=0;
        clearIfNecessary();
        for(int8_t i=lineoffset; i<lineoffset+LCD_HEIGHT; i++) {
            switch(i) {
            case ItemABSPreHeat_Exit:
                MENUITEM(  LCD_PRINT_PGM(MSG_TEMPERATURE_RTN)  ,  BLOCK; status=Sub_TempControl; beepshort(); ) ;
                break;
            case ItemABSPreHeat_set_FanSpeed: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_FAN_SPEED);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(absPreheatFanSpeed));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=absPreheatFanSpeed;
                    } else {
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>255) encoderpos=255;
                    absPreheatFanSpeed=encoderpos;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
            case ItemABSPreHeat_set_nozzle: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_NOZZLE);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(absPreheatHotendTemp));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=absPreheatHotendTemp;
                    } else {
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>260) encoderpos=260;
                    absPreheatHotendTemp = encoderpos;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
            case ItemABSPreHeat_set_HPB: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_BED);
                    lcd.setCursor(13,line);
                    lcd.print(ftostr3(absPreheatHPBTemp));
                }
                if((activeline!=line) )
                    break;
                if(CLICKED) {
                    linechanging=!linechanging;
                    if(linechanging) {
                        encoderpos=absPreheatHPBTemp;
                    } else {
                        encoderpos=activeline*lcdslow;
                        beepshort();
                    }
                    BLOCK;
                }
                if(linechanging) {
                    if(encoderpos<0) encoderpos=0;
                    if(encoderpos>250) encoderpos=150;
                    absPreheatHPBTemp = encoderpos;
                    lcd.setCursor(13,line);
                    lcd.print(itostr3(encoderpos));
                }
            }
            break;
            case ItemABSPreHeat_Store_Eprom: {
                if(force_lcd_update) {
                    lcd.setCursor(0,line);
                    LCD_PRINT_PGM(MSG_STORE_EPROM);
                }
                if((activeline==line) && CLICKED) {
                    //enquecommand("M84");
                    beepshort();
                    BLOCK;
                    Config_StoreSettings();
                }
            }
            break;
            default:
                break;
            }
            line++;
        }
        updateActiveLines(ItemABSPreHeat_Store_Eprom,encoderpos);
#endif
    }
//**********************************************************************************************************
#endif
#if defined (upstream) && defined (ULTRA_LCD) || defined (akadamson) && defined (ULTRA_LCD)
//  convert float to string with +123.4 format
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    char conv[8];
#endif
#if defined (upstream) && defined (ULTRA_LCD) || defined (akadamson) && defined (ULTRA_LCD)
    char * ftostr3
    (const float &x) {
#if defined (upstream) && defined (ULTRA_LCD)
        return itostr3((int)x);
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
//sprintf(conv,"%5.1f",x);
        int xx=x;
        conv[0]=(xx/100)%10+'0';
        conv[1]=(xx/10)%10+'0';
        conv[2]=(xx)%10+'0';
        conv[3]=0;
        return conv;
#endif
    }
    char * itostr2
    (const uint8_t &x) {
//sprintf(conv,"%5.1f",x);
        int xx=x;
        conv[0]=(xx/10)%10+'0';
        conv[1]=(xx)%10+'0';
        conv[2]=0;
        return conv;
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
// Convert float to string with 123.4 format, dropping sign
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
//  convert float to string with +123.4 format
#endif
#if defined (upstream) && defined (ULTRA_LCD) || defined (akadamson) && defined (ULTRA_LCD)
    char * ftostr31
    (const float &x) {
        int xx=x*10;
        conv[0]=(xx>=0)?'+':'-';
        xx=abs(xx);
        conv[1]=(xx/1000)%10+'0';
        conv[2]=(xx/100)%10+'0';
        conv[3]=(xx/10)%10+'0';
        conv[4]='.';
        conv[5]=(xx)%10+'0';
        conv[6]=0;
        return conv;
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
// Convert float to string with 123.4 format
    char *ftostr31ns(const float &x) {
        int xx=x*10;
        //conv[0]=(xx>=0)?'+':'-';
        xx=abs(xx);
        conv[0]=(xx/1000)%10+'0';
        conv[1]=(xx/100)%10+'0';
        conv[2]=(xx/10)%10+'0';
        conv[3]='.';
        conv[4]=(xx)%10+'0';
        conv[5]=0;
        return conv;
    }
    char *ftostr32(const float &x) {
        long xx=x*100;
        if (xx >= 0)
            conv[0]=(xx/10000)%10+'0';
        else
            conv[0]='-';
        xx=abs(xx);
        conv[1]=(xx/1000)%10+'0';
        conv[2]=(xx/100)%10+'0';
        conv[3]='.';
        conv[4]=(xx/10)%10+'0';
        conv[5]=(xx)%10+'0';
        conv[6]=0;
        return conv;
    }
// Convert float to string with 1.234 format
#endif
#if defined (upstream) && defined (ULTRA_LCD) || defined (akadamson) && defined (ULTRA_LCD)
    char * ftostr43
    (const float &x) {
#if defined (upstream) && defined (ULTRA_LCD)
        long xx = x * 1000;
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        long xx=x*100;
#endif
#if defined (upstream) && defined (ULTRA_LCD)
        if (xx >= 0)
            conv[0] = (xx / 1000) % 10 + '0';
        else
            conv[0] = '-';
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        conv[0]=(xx>=0)?'+':'-';
#endif
        xx = abs(xx);
#if defined (upstream) && defined (ULTRA_LCD)
        conv[1] = '.';
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        conv[1]=(xx/100)%10+'0';
#endif
#if defined (upstream) && defined (ULTRA_LCD)
        conv[2] = (xx / 100) % 10 + '0';
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        conv[2]='.';
#endif
        conv[3] = (xx / 10) % 10 + '0';
        conv[4] = (xx) % 10 + '0';
#if defined (upstream) && defined (ULTRA_LCD)
        conv[5] = 0;
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        conv[6]=0;
#endif
        return conv;
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
//Float to string with 1.23 format
    char *ftostr12ns(const float &x) {
        long xx=x*100;
        xx=abs(xx);
        conv[0]=(xx/100)%10+'0';
        conv[1]='.';
        conv[2]=(xx/10)%10+'0';
        conv[3]=(xx)%10+'0';
        conv[4]=0;
        return conv;
    }
//  convert float to space-padded string with -_23.4_ format
    char *ftostr32sp(const float &x) {
        long xx = abs(x * 100);
        uint8_t dig;
        if (x < 0) { // negative val = -_0
            conv[0] = '-';
            dig = (xx / 1000) % 10;
            conv[1] = dig ? '0' + dig : ' ';
        } else { // positive val = __0
            dig = (xx / 10000) % 10;
            if (dig) {
                conv[0] = '0' + dig;
                conv[1] = '0' + (xx / 1000) % 10;
            } else {
                conv[0] = ' ';
                dig = (xx / 1000) % 10;
                conv[1] = dig ? '0' + dig : ' ';
            }
        }
        conv[2] = '0' + (xx / 100) % 10; // lsd always
        dig = xx % 10;
        if (dig) { // 2 decimal places
            conv[5] = '0' + dig;
            conv[4] = '0' + (xx / 10) % 10;
            conv[3] = '.';
        } else { // 1 or 0 decimal place
            dig = (xx / 10) % 10;
            if (dig) {
                conv[4] = '0' + dig;
                conv[3] = '.';
            } else {
                conv[3] = conv[4] = ' ';
            }
            conv[5] = ' ';
        }
        conv[6] = '\0';
        return conv;
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD) || defined (akadamson) && defined (ULTRA_LCD)
    char * itostr31
    (const int &xx) {
        conv[0]=(xx>=0)?'+':'-';
        conv[1]=(xx/1000)%10+'0';
        conv[2]=(xx/100)%10+'0';
        conv[3]=(xx/10)%10+'0';
        conv[4]='.';
        conv[5]=(xx)%10+'0';
        conv[6]=0;
        return conv;
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
// Convert int to rj string with 123 or -12 format
    char *itostr3(const int &x) {
        int xx = x;
        if (xx < 0) {
            conv[0]='-';
            xx = -xx;
        } else if (xx >= 100)
            conv[0]=(xx/100)%10+'0';
        else
            conv[0]=' ';
        if (xx >= 10)
            conv[1]=(xx/10)%10+'0';
        else
            conv[1]=' ';
        conv[2]=(xx)%10+'0';
        conv[3]=0;
        return conv;
    }
// Convert int to lj string with 123 format
#endif
#if defined (upstream) && defined (ULTRA_LCD) || defined (akadamson) && defined (ULTRA_LCD)
    char * itostr3left
    (const int &xx) {
#if defined (upstream) && defined (ULTRA_LCD)
        if (xx >= 100) {
            conv[0]=(xx/100)%10+'0';
            conv[1]=(xx/10)%10+'0';
            conv[2]=(xx)%10+'0';
            conv[3]=0;
        } else if (xx >= 10) {
            conv[0]=(xx/10)%10+'0';
            conv[1]=(xx)%10+'0';
            conv[2]=0;
        } else {
            conv[0]=(xx)%10+'0';
            conv[1]=0;
        }
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        conv[0]=(xx/100)%10+'0';
        conv[1]=(xx/10)%10+'0';
        conv[2]=(xx)%10+'0';
        conv[3]=0;
#endif
        return conv;
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
// Convert int to rj string with 1234 format
#endif
#if defined (upstream) && defined (ULTRA_LCD) || defined (akadamson) && defined (ULTRA_LCD)
    char * itostr4
    (const int &xx) {
#if defined (upstream) && defined (ULTRA_LCD)
        conv[0] = xx >= 1000 ? (xx / 1000) % 10 + '0' : ' ';
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        conv[0]=(xx/1000)%10+'0';
#endif
#if defined (upstream) && defined (ULTRA_LCD)
        conv[1] = xx >= 100 ? (xx / 100) % 10 + '0' : ' ';
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        conv[1]=(xx/100)%10+'0';
#endif
#if defined (upstream) && defined (ULTRA_LCD)
        conv[2] = xx >= 10 ? (xx / 10) % 10 + '0' : ' ';
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        conv[2]=(xx/10)%10+'0';
#endif
#if defined (upstream) && defined (ULTRA_LCD)
        conv[3] = xx % 10 + '0';
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
        conv[3]=(xx)%10+'0';
#endif
        conv[4] = 0;
        return conv;
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
// Convert float to rj string with 12345 format
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
//  convert float to string with +1234.5 format
#endif
#if defined (upstream) && defined (ULTRA_LCD)
    char *ftostr5(const float &x) {
        long xx = abs(x);
        conv[0] = xx >= 10000 ? (xx / 10000) % 10 + '0' : ' ';
        conv[1] = xx >= 1000 ? (xx / 1000) % 10 + '0' : ' ';
        conv[2] = xx >= 100 ? (xx / 100) % 10 + '0' : ' ';
        conv[3] = xx >= 10 ? (xx / 10) % 10 + '0' : ' ';
        conv[4] = xx % 10 + '0';
        conv[5] = 0;
        return conv;
    }
// Convert float to string with +1234.5 format
#endif
#if defined (upstream) && defined (ULTRA_LCD) || defined (akadamson) && defined (ULTRA_LCD)
    char * ftostr51
    (const float &x) {
        long xx=x*10;
        conv[0]=(xx>=0)?'+':'-';
        xx=abs(xx);
        conv[1]=(xx/10000)%10+'0';
        conv[2]=(xx/1000)%10+'0';
        conv[3]=(xx/100)%10+'0';
        conv[4]=(xx/10)%10+'0';
        conv[5]='.';
        conv[6]=(xx)%10+'0';
        conv[7]=0;
        return conv;
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
// Convert float to string with +123.45 format
#endif
#if defined (akadamson) && defined (ULTRA_LCD)
//  convert float to string with +123.45 format
#endif
#if defined (upstream) && defined (ULTRA_LCD) || defined (akadamson) && defined (ULTRA_LCD)
    char * ftostr52
    (const float &x) {
        long xx=x*100;
        conv[0]=(xx>=0)?'+':'-';
        xx=abs(xx);
        conv[1]=(xx/10000)%10+'0';
        conv[2]=(xx/1000)%10+'0';
        conv[3]=(xx/100)%10+'0';
        conv[4]='.';
        conv[5]=(xx/10)%10+'0';
        conv[6]=(xx)%10+'0';
        conv[7]=0;
        return conv;
    }
#endif
#if defined (upstream) && defined (ULTRA_LCD)
// Callback for after editing PID i value
// grab the PID i value out of the temp variable; scale it; then update the PID driver
    void copy_and_scalePID_i() {
#ifdef PIDTEMP
        Ki = scalePID_i(raw_Ki);
        updatePID();
#endif
    }
// Callback for after editing PID d value
// grab the PID d value out of the temp variable; scale it; then update the PID driver
    void copy_and_scalePID_d() {
#ifdef PIDTEMP
        Kd = scalePID_d(raw_Kd);
        updatePID();
#endif
    }
#endif
#if defined (upstream) || defined (akadamson)
//ULTRA_LCD
#endif
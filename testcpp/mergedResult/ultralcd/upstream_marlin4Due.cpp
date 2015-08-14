#if defined (A)
    #include "temperature.h"
#endif
#if defined (A) || defined (B)
    #include "ultralcd.h"
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
    #include "Marlin.h"
    #include "language.h"
    #include "cardreader.h"
    #include "temperature.h"
    #include "stepper.h"
#endif
#if defined (A) && defined (ULTRA_LCD)
    #include "ConfigurationStore.h"
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
    #include "configuration_store.h"
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
    int8_t encoderDiff;
#endif
#if defined (A) && defined (ULTRA_LCD)
    /* encoderDiff is updated from interrupt context and added to encoderPosition every LCD update */
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
    // updated from interrupt context and added to encoderPosition every LCD update
#endif
#if defined (A) && defined (ULTRA_LCD)
    /* Configuration settings */
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
    bool encoderRateMultiplierEnabled;
    int32_t lastEncoderMovementMillis;
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
    int plaPreheatHotendTemp;
    int plaPreheatHPBTemp;
    int plaPreheatFanSpeed;
    int absPreheatHotendTemp;
    int absPreheatHPBTemp;
    int absPreheatFanSpeed;
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (FILAMENT_LCD_DISPLAY) )
    unsigned long message_millis = 0;
#endif
#if defined (B) && (ENABLED(FILAMENT_LCD_DISPLAY) && ENABLED(ULTRA_LCD) )
    millis_t previous_lcd_status_ms = 0;
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static float manual_feedrate[] = MANUAL_FEEDRATE;
#endif
#if defined (A) && defined (ULTRA_LCD)
    // ULTIPANEL
    /* !Configuration settings */
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
    //Function pointer to menu functions.
    typedef void (*menuFunc_t)();
    uint8_t lcd_status_message_level;
#endif
#if defined (A) && defined (ULTRA_LCD)
    char lcd_status_message[LCD_WIDTH+1] = WELCOME_MSG;
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
    char lcd_status_message[3*LCD_WIDTH+1] = WELCOME_MSG;
    // worst case is kana with up to 3*LCD_WIDTH+1
#endif
#if defined (A) && (defined (DOGLCD) && defined (ULTRA_LCD) ) || defined (B) && (ENABLED(ULTRA_LCD) && ENABLED(DOGLCD) )
    #include "dogm_lcd_implementation.h"
#endif
#if defined (A) && (defined (ULTRA_LCD) && !defined (DOGLCD) ) || defined (B) && (!ENABLED(DOGLCD) && ENABLED(ULTRA_LCD) )
    #include "ultralcd_implementation_hitachi_HD44780.h"
#endif
#if defined (A) && defined (ULTRA_LCD)
    /** forward declarations **/
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
    // The main status screen
#endif
#if defined (A) && defined (ULTRA_LCD)
    void copy_and_scalePID_i();
    void copy_and_scalePID_d();
    /* Different menus */
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
    static void lcd_status_screen();
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (HAS_POWER_SWITCH && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
    extern bool powersupply;
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
    const float manual_feedrate[] = MANUAL_FEEDRATE;
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
    static void lcd_main_menu();
    static void lcd_tune_menu();
    static void lcd_prepare_menu();
    static void lcd_move_menu();
    static void lcd_control_menu();
    static void lcd_control_temperature_menu();
    static void lcd_control_temperature_preheat_pla_settings_menu();
    static void lcd_control_temperature_preheat_abs_settings_menu();
    static void lcd_control_motion_menu();
    static void lcd_control_volumetric_menu();
#endif
#if defined (A) && (defined (DOGLCD) && defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(HAS_LCD_CONTRAST) )
    static void lcd_set_contrast();
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(FWRETRACT) && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
    static void lcd_control_retract_menu();
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
    static void lcd_sdcard_menu();
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (DELTA_CALIBRATION_MENU) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(DELTA_CALIBRATION_MENU) )
    static void lcd_delta_calibrate_menu();
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    // DELTA_CALIBRATION_MENU
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(MANUAL_BED_LEVELING) )
    #include "mesh_bed_leveling.h"
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    static void lcd_quick_feedback();
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(MANUAL_BED_LEVELING) )
    static void _lcd_level_bed();
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    //Cause an LCD refresh, and give the user visual or audible feedback that something has happened
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(MANUAL_BED_LEVELING) )
    static void _lcd_level_bed_homing();
    static void lcd_level_bed();
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
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
#if defined (A) && (defined (ULTRA_LCD) && !defined(LCD_I2C_VIKI) && !defined (ENCODER_STEPS_PER_MENU_ITEM) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && !defined (ENCODER_STEPS_PER_MENU_ITEM) && DISABLED(LCD_I2C_VIKI) )
    #define ENCODER_STEPS_PER_MENU_ITEM 5
#endif
#if defined (A) && (defined (ULTRA_LCD) && !defined(LCD_I2C_VIKI) && !defined (ENCODER_PULSES_PER_STEP) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && !defined (ENCODER_PULSES_PER_STEP) && DISABLED(LCD_I2C_VIKI) )
    #define ENCODER_PULSES_PER_STEP 1
#endif
#if defined (A) && (defined (ULTRA_LCD) && !defined (ENCODER_STEPS_PER_MENU_ITEM) && defined(LCD_I2C_VIKI) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && !defined (ENCODER_STEPS_PER_MENU_ITEM) && !DISABLED(LCD_I2C_VIKI) )
    #define ENCODER_STEPS_PER_MENU_ITEM 2
    // VIKI LCD rotary encoder uses a different number of steps per rotation
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined(LCD_I2C_VIKI) && !defined (ENCODER_PULSES_PER_STEP) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && !DISABLED(LCD_I2C_VIKI) && !defined (ENCODER_PULSES_PER_STEP) )
    #define ENCODER_PULSES_PER_STEP 1
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
    /* Helper macros for menus */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
#define START_MENU() do { \
    if (encoderPosition > 0x8000) encoderPosition = 0; \
    if (encoderPosition / ENCODER_STEPS_PER_MENU_ITEM < currentMenuViewOffset) currentMenuViewOffset = encoderPosition / ENCODER_STEPS_PER_MENU_ITEM;\
    uint8_t _lineNr = currentMenuViewOffset, _menuItemNr; \
    bool wasClicked = LCD_CLICKED;\
    for(uint8_t _drawLineNr = 0; _drawLineNr < LCD_HEIGHT; _drawLineNr++, _lineNr++) { \
        _menuItemNr = 0;
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
    /**
    * START_MENU generates the init code for a menu function
    */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
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
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && (defined(BTN_BACK) && BTN_BACK > 0 &)
#define START_MENU(last_menu) do { \
    encoderRateMultiplierEnabled = false; \
    if (encoderPosition > 0x8000) encoderPosition = 0; \
    uint8_t encoderLine = encoderPosition / ENCODER_STEPS_PER_MENU_ITEM; \
    if (encoderLine < currentMenuViewOffset) currentMenuViewOffset = encoderLine; \
    uint8_t _lineNr = currentMenuViewOffset, _menuItemNr; \
    bool wasClicked = LCD_CLICKED, itemSelected; \
    bool wasBackClicked = LCD_BACK_CLICKED; \
    if (wasBackClicked) { \
      lcd_quick_feedback(); \
      menu_action_back( last_menu ); \
      return; } \
    for (uint8_t _drawLineNr = 0; _drawLineNr < LCD_HEIGHT; _drawLineNr++, _lineNr++) { \
      _menuItemNr = 0;
#endif
#if defined (B) && ((!defined(BTN_BACK) && BTN_BACK > 0 && )ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
#define START_MENU(last_menu) do { \
    encoderRateMultiplierEnabled = false; \
    if (encoderPosition > 0x8000) encoderPosition = 0; \
    uint8_t encoderLine = encoderPosition / ENCODER_STEPS_PER_MENU_ITEM; \
    if (encoderLine < currentMenuViewOffset) currentMenuViewOffset = encoderLine; \
    uint8_t _lineNr = currentMenuViewOffset, _menuItemNr; \
    bool wasClicked = LCD_CLICKED, itemSelected; \
    for (uint8_t _drawLineNr = 0; _drawLineNr < LCD_HEIGHT; _drawLineNr++, _lineNr++) { \
      _menuItemNr = 0;
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
/**
   * MENU_ITEM generates draw & handler code for a menu item, potentially calling:
   *
   *   lcd_implementation_drawmenu_[type](sel, row, label, arg3...)
   *   menu_action_[type](arg3...)
   *
   * Examples:
   *   MENU_ITEM(back, MSG_WATCH, lcd_status_screen)
   *     lcd_implementation_drawmenu_back(sel, row, PSTR(MSG_WATCH), lcd_status_screen)
   *     menu_action_back(lcd_status_screen)
   *
   *   MENU_ITEM(function, MSG_PAUSE_PRINT, lcd_sdcard_pause)
   *     lcd_implementation_drawmenu_function(sel, row, PSTR(MSG_PAUSE_PRINT), lcd_sdcard_pause)
   *     menu_action_function(lcd_sdcard_pause)
   *
   *   MENU_ITEM_EDIT(int3, MSG_SPEED, &feedrate_multiplier, 10, 999)
   *   MENU_ITEM(setting_edit_int3, MSG_SPEED, PSTR(MSG_SPEED), &feedrate_multiplier, 10, 999)
   *     lcd_implementation_drawmenu_setting_edit_int3(sel, row, PSTR(MSG_SPEED), PSTR(MSG_SPEED), &feedrate_multiplier, 10, 999)
   *     menu_action_setting_edit_int3(PSTR(MSG_SPEED), &feedrate_multiplier, 10, 999)
   *
   */
#define MENU_ITEM(type, label, args...) do { \
    if (_menuItemNr == _lineNr) { \
      itemSelected = encoderLine == _menuItemNr; \
      if (lcdDrawUpdate) \
        lcd_implementation_drawmenu_ ## type(itemSelected, _drawLineNr, PSTR(label), ## args); \
      if (wasClicked && itemSelected) { \
        lcd_quick_feedback(); \
        menu_action_ ## type(args); \
        return; \
      } \
    } \
    _menuItemNr++; \
  } while(0)
#endif
#if defined (B) && (ENABLED(ENCODER_RATE_MULTIPLIER) && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//#define ENCODER_RATE_MULTIPLIER_DEBUG  // If defined, output the encoder steps per second value
/**
     * MENU_MULTIPLIER_ITEM generates drawing and handling code for a multiplier menu item
     */
#define MENU_MULTIPLIER_ITEM(type, label, args...) do { \
      if (_menuItemNr == _lineNr) { \
        itemSelected = encoderLine == _menuItemNr; \
        if (lcdDrawUpdate) \
          lcd_implementation_drawmenu_ ## type(itemSelected, _drawLineNr, PSTR(label), ## args); \
        if (wasClicked && itemSelected) { \
          lcd_quick_feedback(); \
          encoderRateMultiplierEnabled = true; \
          lastEncoderMovementMillis = 0; \
          menu_action_ ## type(args); \
          return; \
        } \
      } \
      _menuItemNr++; \
    } while(0)
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
    //ENCODER_RATE_MULTIPLIER
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
    #define MENU_ITEM_DUMMY() do { _menuItemNr++; } while(0)
    #define MENU_ITEM_EDIT(type, label, args...) MENU_ITEM(setting_edit_ ## type, label, PSTR(label) , ## args )
    #define MENU_ITEM_EDIT_CALLBACK(type, label, args...) MENU_ITEM(setting_edit_callback_ ## type, label, PSTR(label) , ## args )
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
#define END_MENU() \
    if (encoderPosition / ENCODER_STEPS_PER_MENU_ITEM >= _menuItemNr) encoderPosition = _menuItemNr * ENCODER_STEPS_PER_MENU_ITEM - 1; \
    if ((uint8_t)(encoderPosition / ENCODER_STEPS_PER_MENU_ITEM) >= currentMenuViewOffset + LCD_HEIGHT) { currentMenuViewOffset = (encoderPosition / ENCODER_STEPS_PER_MENU_ITEM) - LCD_HEIGHT + 1; lcdDrawUpdate = 1; _lineNr = currentMenuViewOffset - 1; _drawLineNr = -1; } \
    } } while(0)
#endif
#if defined (B) && (ENABLED(ENCODER_RATE_MULTIPLIER) && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
    #define MENU_MULTIPLIER_ITEM_EDIT(type, label, args...) MENU_MULTIPLIER_ITEM(setting_edit_ ## type, label, PSTR(label), ## args)
    #define MENU_MULTIPLIER_ITEM_EDIT_CALLBACK(type, label, args...) MENU_MULTIPLIER_ITEM(setting_edit_callback_ ## type, label, PSTR(label), ## args)
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && !ENABLED(ENCODER_RATE_MULTIPLIER) && ENABLED(ULTRA_LCD) )
    //!ENCODER_RATE_MULTIPLIER
    #define MENU_MULTIPLIER_ITEM_EDIT(type, label, args...) MENU_ITEM(setting_edit_ ## type, label, PSTR(label), ## args)
    #define MENU_MULTIPLIER_ITEM_EDIT_CALLBACK(type, label, args...) MENU_ITEM(setting_edit_callback_ ## type, label, PSTR(label), ## args)
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//!ENCODER_RATE_MULTIPLIER
#define END_MENU() \
      if (encoderLine >= _menuItemNr) { encoderPosition = _menuItemNr * ENCODER_STEPS_PER_MENU_ITEM - 1; encoderLine = encoderPosition / ENCODER_STEPS_PER_MENU_ITEM; }\
      if (encoderLine >= currentMenuViewOffset + LCD_HEIGHT) { currentMenuViewOffset = encoderLine - LCD_HEIGHT + 1; lcdDrawUpdate = 1; _lineNr = currentMenuViewOffset - 1; _drawLineNr = -1; } \
      } } while(0)
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
    /** Used variables to keep track of the menu */
#endif
#if defined (A) && (defined (ULTRA_LCD) && !defined (REPRAPWORLD_KEYPAD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
    volatile uint8_t buttons;
#endif
#if defined (A) && (defined (ULTRA_LCD) && !defined (REPRAPWORLD_KEYPAD) && defined (ULTIPANEL) )
    //Contains the bits of the currently pressed buttons.
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
    //the last checked buttons in a bit array.
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (REPRAPWORLD_KEYPAD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(REPRAPWORLD_KEYPAD) )
    volatile uint8_t buttons_reprapworld_keypad;
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (REPRAPWORLD_KEYPAD) && defined (ULTIPANEL) )
    // to store the reprapworld_keypad shift register values
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(REPRAPWORLD_KEYPAD) )
    // to store the keypad shift register values
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) && defined (LCD_HAS_SLOW_BUTTONS) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(LCD_HAS_SLOW_BUTTONS) )
    volatile uint8_t slow_buttons;
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) && defined (LCD_HAS_SLOW_BUTTONS) )
    //Contains the bits of the currently pressed buttons.
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(LCD_HAS_SLOW_BUTTONS) )
    // Bits of the pressed buttons.
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
    uint8_t currentMenuViewOffset;
    /* scroll offset in the current menu */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
    uint32_t blocking_enc;
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
    millis_t next_button_update_ms;
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
    uint8_t lastEncoderBits;
    uint32_t encoderPosition;
#endif
#if defined (A) && (defined (ULTRA_LCD) && (SDCARDDETECT > 0) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && (SDCARDDETECT > 0) && ENABLED(ULTRA_LCD) )
    bool lcd_oldcardstatus;
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
    //ULTIPANEL
    menuFunc_t currentMenu = lcd_status_screen;
    /* function pointer to the currently active menu */
#endif
#if defined (A) && defined (ULTRA_LCD)
    uint32_t lcd_next_update_millis;
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
    millis_t next_lcd_update_ms;
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
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
#endif
#if defined (A) && defined (ULTRA_LCD)
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
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
    /**
     * General function to go directly to a menu
     */
#endif
#if defined (A) && defined (ULTRA_LCD)
    /* Main status screen. It's up to the implementation specific part to show what is needed. As this is very display dependent */
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
    static void lcd_goto_menu(menuFunc_t menu, const bool feedback=false, const uint32_t encoder=0) {
        if (currentMenu != menu) {
            currentMenu = menu;
#if ENABLED(NEWPANEL)
            encoderPosition = encoder;
            if (feedback) lcd_quick_feedback();
#endif
            // For LCD_PROGRESS_BAR re-initialize the custom characters
#if ENABLED(LCD_PROGRESS_BAR)
            lcd_set_custom_characters(menu == lcd_status_screen);
#endif
        }
        /**
         *
         * "Info Screen"
         *
         * This is very display-dependent, so the lcd implementation draws this.
         */
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
        void lcd_status_screen
        () {
#if defined (A)
            uint16_t mil = millis();
#endif
#if defined (B)
            encoderRateMultiplierEnabled = false;
#endif
#if defined (A)
            if (mil > progressBarTick + PROGRESS_BAR_MSG_TIME + PROGRESS_BAR_BAR_TIME) {
                progressBarTick = mil;
            }
#endif
#if defined (B)
            millis_t ms = millis();
#endif
#if defined (A)
// keep the message alive if paused, count down otherwise
#endif
#if defined (B)
            if (ms > progress_bar_ms + PROGRESS_BAR_MSG_TIME + PROGRESS_BAR_BAR_TIME) {
                progress_bar_ms = ms;
            }
#endif
#if defined (A)
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
#if defined (B)
// Handle message expire
#endif
#if defined (B) && (ENABLED(LCD_PROGRESS_BAR) && PROGRESS_MSG_EXPIRE > 0 && ENABLED(ULTRA_LCD) )
            if (expire_status_ms > 0) {
                if (card.isFileOpen()) {
                    // Expire the message when printing is active
                    if (IS_SD_PRINTING) {
                        // Expire the message when printing is active
                        if (ms >= expire_status_ms) {
                            lcd_status_message[0] = '\0';
                            expire_status_ms = 0;
                        }
                    } else {
                        expire_status_ms += LCD_UPDATE_INTERVAL;
                    }
                } else {
                    expire_status_ms = 0;
                }
            }
#endif
//LCD_PROGRESS_BAR
#if defined (A)
            if (lcd_status_update_delay)
                lcd_status_update_delay--;
            else
                lcdDrawUpdate = 1;
#endif
#if defined (B)
            lcd_implementation_status_screen();
#endif
#if defined (A) && defined (ULTRA_LCD)
            if (lcdDrawUpdate) {
                lcd_implementation_status_screen();
                lcd_status_update_delay = 10;   /* redraw the main screen every second. This is easier then trying keep track of all things that change on the screen */
            }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            bool current_click = LCD_CLICKED;
            if
            (ignore_click) {
                if
                (wait_for_unclick) {
                    if
                    (!current_click) {
#if defined (A)
                        {
                            ignore_click = wait_for_unclick = false;
                        }
#endif
#if defined (B)
                        ignore_click = wait_for_unclick = false;
#endif
                    }
#if defined (A)
                    else {
                        current_click = false;
                    }
#endif
#if defined (B)
                    else
                        current_click = false;
#endif
                } else if
                (current_click) {
                    lcd_quick_feedback();
                    wait_for_unclick = true;
                    current_click = false;
                }
            }
            if
            (current_click) {
#if defined (A)
                lcd_goto_menu(lcd_main_menu);
#endif
#if defined (B)
                lcd_goto_menu(lcd_main_menu, true);
#endif
#if defined (A)
                lcd_implementation_init( // to maybe revive the LCD if static electricity killed it.
#if defined(LCD_PROGRESS_BAR) && defined(SDSUPPORT)
                    currentMenu == lcd_status_screen
#endif
                );
#endif
#if defined (B)
                lcd_implementation_init( // to maybe revive the LCD if static electricity killed it.
#if ENABLED(LCD_PROGRESS_BAR)
                    currentMenu == lcd_status_screen
#endif
                );
#endif
#if defined (A)
                message_millis = millis();
#endif
#if defined (B)
                previous_lcd_status_ms = millis();
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (FILAMENT_LCD_DISPLAY) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(FILAMENT_LCD_DISPLAY) && ENABLED(ULTRA_LCD) )
// get status message to show up for a while
#endif
            }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL_FEEDMULTIPLY) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTIPANEL_FEEDMULTIPLY) && ENABLED(ULTRA_LCD) )
// Dead zone at 100% feedrate
#endif
#if defined (A)
            if ((feedmultiply < 100 && (feedmultiply + int(encoderPosition)) > 100) ||
                    (feedmultiply > 100 && (feedmultiply + int(encoderPosition)) < 100)) {
                encoderPosition = 0;
                feedmultiply = 100;
            }
#endif
#if defined (B)
            if ((feedrate_multiplier < 100 && (feedrate_multiplier + int(encoderPosition)) > 100) ||
                    (feedrate_multiplier > 100 && (feedrate_multiplier + int(encoderPosition)) < 100)) {
                encoderPosition = 0;
                feedrate_multiplier = 100;
            }
#endif
#if defined (A)
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
#endif
#if defined (B)
            if (feedrate_multiplier == 100) {
                if (int(encoderPosition) > ENCODER_FEEDRATE_DEADZONE) {
                    feedrate_multiplier += int(encoderPosition) - ENCODER_FEEDRATE_DEADZONE;
                    encoderPosition = 0;
                } else if (int(encoderPosition) < -ENCODER_FEEDRATE_DEADZONE) {
                    feedrate_multiplier += int(encoderPosition) + ENCODER_FEEDRATE_DEADZONE;
                    encoderPosition = 0;
                }
            } else {
                feedrate_multiplier += int(encoderPosition);
                encoderPosition = 0;
            }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//ULTIPANEL_FEEDMULTIPLY
#endif
#if defined (A)
            if (feedmultiply < 10)
                feedmultiply = 10;
            else if (feedmultiply > 999)
                feedmultiply = 999;
#endif
#if defined (B)
            feedrate_multiplier = constrain(feedrate_multiplier, 10, 999);
#endif
//ULTIPANEL
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        static void lcd_return_to_status
        () {
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
            lcd_goto_menu(lcd_status_screen, 0, false);
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            lcd_goto_menu(lcd_status_screen);
#endif
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && defined (SDSUPPORT) )
        static void lcd_sdcard_pause
        () {
            card.pauseSDPrint();
        }
        static void lcd_sdcard_resume
        () {
            card.startFileprint();
        }
        static void lcd_sdcard_stop
        () {
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && defined (SDSUPPORT) )
            quickStop();
#endif
            card.sdprinting = false;
            card.closefile();
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
            quickStop();
            if(SD_FINISHED_STEPPERRELEASE) {
                enquecommand_P(PSTR(SD_FINISHED_RELEASECOMMAND));
            }
#endif
            autotempShutdown();
            cancel_heatup = true;
#if defined (A)
            lcd_setstatus(MSG_PRINT_ABORTED);
#endif
#if defined (B)
            lcd_setstatus(MSG_PRINT_ABORTED, true);
#endif
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
        /* Menu implementation */
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
         *
         * "Main" menu
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        static void lcd_main_menu
        () {
#if defined (A)
            START_MENU();
#endif
#if defined (B)
            START_MENU(lcd_status_screen);
#endif
            MENU_ITEM(back, MSG_WATCH, lcd_status_screen);
            if
            (movesplanned() || IS_SD_PRINTING) {
                MENU_ITEM(submenu, MSG_TUNE, lcd_tune_menu);
            } else {
                MENU_ITEM(submenu, MSG_PREPARE, lcd_prepare_menu);
#if defined (A) && (defined (ULTRA_LCD) && defined (DELTA_CALIBRATION_MENU) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(DELTA_CALIBRATION_MENU) )
                MENU_ITEM(submenu, MSG_DELTA_CALIBRATE, lcd_delta_calibrate_menu);
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
// DELTA_CALIBRATION_MENU
#endif
            }
            MENU_ITEM(submenu, MSG_CONTROL, lcd_control_menu);
#if defined (A) && (defined (ULTRA_LCD) && defined (SDSUPPORT) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(SDSUPPORT) && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            if
            (card.cardOK) {
                if
                (card.isFileOpen()) {
                    if
                    (card.sdprinting)
                        MENU_ITEM(function, MSG_PAUSE_PRINT, lcd_sdcard_pause);
                    else
                        MENU_ITEM(function, MSG_RESUME_PRINT, lcd_sdcard_resume);
                    MENU_ITEM(function, MSG_STOP_PRINT, lcd_sdcard_stop);
                } else {
                    MENU_ITEM(submenu, MSG_CARD_MENU, lcd_sdcard_menu);
#if defined (A) && (SDCARDDETECT < 1 && defined (ULTRA_LCD) && defined (SDSUPPORT) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(SDSUPPORT) && SDCARDDETECT < 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
                    MENU_ITEM(gcode, MSG_CNG_SDCARD, PSTR("M21"));
// SD-card changed by user
#endif
                }
            } else {
                MENU_ITEM(submenu, MSG_NO_CARD, lcd_sdcard_menu);
#if defined (A) && (SDCARDDETECT < 1 && defined (ULTRA_LCD) && defined (SDSUPPORT) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(SDSUPPORT) && SDCARDDETECT < 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
                MENU_ITEM(gcode, MSG_INIT_SDCARD, PSTR("M21"));
// Manually initialize the SD-card via user interface
#endif
            }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//SDSUPPORT
#endif
            END_MENU();
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (SDSUPPORT) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && (ENABLED(SDSUPPORT) && ENABLED(MENU_ADDAUTOSTART) &)
        static void lcd_autostart_sd
        () {
#if defined (A)
            card.lastnr=0;
#endif
#if defined (B)
            card.autostart_index = 0;
#endif
            card.setroot();
            card.checkautostart(true);
        }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
         * Set the home offset based on the current_position
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        void lcd_set_home_offsets
        () {
#if defined (A)
            for(int8_t i=0; i < NUM_AXIS; i++) {
                if (i != E_AXIS) {
                    add_homing[i] -= current_position[i];
                    current_position[i] = 0.0;
                }
            }
#endif
#if defined (B)
// M428 Command
#endif
#if defined (A)
            plan_set_position(0.0, 0.0, 0.0, current_position[E_AXIS]);
#endif
#if defined (B)
            enqueuecommands_P(PSTR("M428"));
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
// Audio feedback
            enquecommand_P(PSTR("M300 S659 P200"));
            enquecommand_P(PSTR("M300 S698 P200"));
#endif
            lcd_return_to_status();
        }
#endif
#if defined (A) && (defined (BABYSTEPPING) && defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(BABYSTEPPING) )
        static void _lcd_babystep
        (int axis, const char *msg) {
            if
            (encoderPosition != 0) {
                babystepsTodo[axis] += (int)encoderPosition;
                encoderPosition = 0;
                lcdDrawUpdate = 1;
            }
            if
            (lcdDrawUpdate)
                lcd_implementation_drawedit(msg, "");
            if
            (LCD_CLICKED)
                lcd_goto_menu(lcd_tune_menu);
        }
        static void lcd_babystep_x
        () {
            _lcd_babystep(X_AXIS, PSTR(MSG_BABYSTEPPING_X));
        }
        static void lcd_babystep_y
        () {
            _lcd_babystep(Y_AXIS, PSTR(MSG_BABYSTEPPING_Y));
        }
        static void lcd_babystep_z
        () {
            _lcd_babystep(Z_AXIS, PSTR(MSG_BABYSTEPPING_Z));
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//BABYSTEPPING
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
         *
         * "Tune" submenu
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        static void lcd_tune_menu
        () {
#if defined (A)
            START_MENU();
#endif
#if defined (B)
            START_MENU(lcd_main_menu);
#endif
            MENU_ITEM(back, MSG_MAIN, lcd_main_menu);
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_SPEED, &feedmultiply, 10, 999);
#endif
#if defined (B)
            MENU_ITEM_EDIT(int3, MSG_SPEED, &feedrate_multiplier, 10, 999);
#endif
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_NOZZLE, &target_temperature[0], 0, HEATER_0_MAXTEMP - 15);
#endif
#if defined (B)
            MENU_MULTIPLIER_ITEM_EDIT(int3, MSG_NOZZLE, &target_temperature[0], 0, HEATER_0_MAXTEMP - 15);
#endif
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_NOZZLE1, &target_temperature[1], 0, HEATER_1_MAXTEMP - 15);
#endif
#if defined (B)
            MENU_MULTIPLIER_ITEM_EDIT(int3, MSG_NOZZLE MSG_N2, &target_temperature[1], 0, HEATER_1_MAXTEMP - 15)
#endif
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_NOZZLE2, &target_temperature[2], 0, HEATER_2_MAXTEMP - 15);
#endif
#if defined (B)
            ;
#endif
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_BED, &target_temperature_bed, 0, BED_MAXTEMP - 15);
#endif
#if defined (B)
            MENU_MULTIPLIER_ITEM_EDIT(int3, MSG_NOZZLE MSG_N3, &target_temperature[2], 0, HEATER_2_MAXTEMP - 15)
#endif
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_FAN_SPEED, &fanSpeed, 0, 255);
#endif
#if defined (B)
            ;
#endif
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_FLOW, &extrudemultiply, 10, 999);
#endif
#if defined (B)
            MENU_MULTIPLIER_ITEM_EDIT(int3, MSG_NOZZLE MSG_N4, &target_temperature[3], 0, HEATER_3_MAXTEMP - 15)
#endif
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_FLOW0, &extruder_multiply[0], 10, 999);
#endif
#if defined (B)
            ;
#endif
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_FLOW1, &extruder_multiply[1], 10, 999);
#endif
#if defined (B)
            MENU_MULTIPLIER_ITEM_EDIT(int3, MSG_BED, &target_temperature_bed, 0, BED_MAXTEMP - 15);
#endif
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_FLOW2, &extruder_multiply[2], 10, 999);
#endif
#if defined (B)
            MENU_MULTIPLIER_ITEM_EDIT(int3, MSG_FAN_SPEED, &fanSpeed, 0, 255);
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            MENU_ITEM_EDIT(int3, MSG_FLOW, &extruder_multiplier[active_extruder], 10, 999);
            MENU_ITEM_EDIT(int3, MSG_FLOW MSG_N0, &extruder_multiplier[0], 10, 999)
            ;
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && TEMP_SENSOR_1 != 0 )
            MENU_ITEM_EDIT(int3, MSG_FLOW MSG_N1, &extruder_multiplier[1], 10, 999)
            ;
#endif
#if defined (B) && (TEMP_SENSOR_2 != 0 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            MENU_ITEM_EDIT(int3, MSG_FLOW MSG_N2, &extruder_multiplier[2], 10, 999)
            ;
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && TEMP_SENSOR_3 != 0 )
            MENU_ITEM_EDIT(int3, MSG_FLOW MSG_N3, &extruder_multiplier[3], 10, 999)
            ;
#endif
#if defined (A) && (defined (BABYSTEPPING) && defined (ULTRA_LCD) && defined (BABYSTEP_XY) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(BABYSTEPPING) && ENABLED(BABYSTEP_XY) )
            MENU_ITEM(submenu, MSG_BABYSTEP_X, lcd_babystep_x);
            MENU_ITEM(submenu, MSG_BABYSTEP_Y, lcd_babystep_y);
#endif
#if defined (A) && (defined (BABYSTEPPING) && defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(BABYSTEPPING) )
//BABYSTEP_XY
            MENU_ITEM(submenu, MSG_BABYSTEP_Z, lcd_babystep_z);
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) && defined (FILAMENTCHANGEENABLE) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(FILAMENTCHANGEENABLE) )
            MENU_ITEM(gcode, MSG_FILAMENTCHANGE, PSTR("M600"));
#endif
            END_MENU();
        }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        void _lcd_preheat(int endnum, const float temph, const float tempb, const int fan) {
            if (temph > 0) setTargetHotend(temph, endnum);
#if TEMP_SENSOR_BED != 0
            setTargetBed(tempb);
#endif
            fanSpeed = fan;
            lcd_return_to_status();
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        void lcd_preheat_pla0
        () {
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
            setTargetHotend0(plaPreheatHotendTemp);
            setTargetBed(plaPreheatHPBTemp);
            fanSpeed = plaPreheatFanSpeed;
            lcd_return_to_status();
            setWatch(); // heater sanity check timer
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            _lcd_preheat(0, plaPreheatHotendTemp, plaPreheatHPBTemp, plaPreheatFanSpeed);
#endif
        }
        void lcd_preheat_abs0
        () {
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
            setTargetHotend0(absPreheatHotendTemp);
            setTargetBed(absPreheatHPBTemp);
            fanSpeed = absPreheatFanSpeed;
            lcd_return_to_status();
            setWatch(); // heater sanity check timer
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            _lcd_preheat(0, absPreheatHotendTemp, absPreheatHPBTemp, absPreheatFanSpeed);
#endif
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && TEMP_SENSOR_1 != 0 && defined (ULTIPANEL) )
//2nd extruder preheat
#endif
#if defined (A) && (defined (ULTRA_LCD) && TEMP_SENSOR_1 != 0 && defined (ULTIPANEL) ) || defined (B) && (EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        void lcd_preheat_pla1
        () {
#if defined (A) && (defined (ULTRA_LCD) && TEMP_SENSOR_1 != 0 && defined (ULTIPANEL) )
            setTargetHotend1(plaPreheatHotendTemp);
            setTargetBed(plaPreheatHPBTemp);
            fanSpeed = plaPreheatFanSpeed;
            lcd_return_to_status();
            setWatch(); // heater sanity check timer
#endif
#if defined (B) && (EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            _lcd_preheat(1, plaPreheatHotendTemp, plaPreheatHPBTemp, plaPreheatFanSpeed);
#endif
        }
        void lcd_preheat_abs1
        () {
#if defined (A) && (defined (ULTRA_LCD) && TEMP_SENSOR_1 != 0 && defined (ULTIPANEL) )
            setTargetHotend1(absPreheatHotendTemp);
            setTargetBed(absPreheatHPBTemp);
            fanSpeed = absPreheatFanSpeed;
            lcd_return_to_status();
            setWatch(); // heater sanity check timer
#endif
#if defined (B) && (EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            _lcd_preheat(1, absPreheatHotendTemp, absPreheatHPBTemp, absPreheatFanSpeed);
#endif
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
//2nd extruder preheat
#endif
#if defined (A) && (TEMP_SENSOR_2 != 0 && defined (ULTRA_LCD) && defined (ULTIPANEL) )
//3 extruder preheat
#endif
#if defined (A) && (TEMP_SENSOR_2 != 0 && defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (EXTRUDERS > 2 && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        void lcd_preheat_pla2
        () {
#if defined (A) && (TEMP_SENSOR_2 != 0 && defined (ULTRA_LCD) && defined (ULTIPANEL) )
            setTargetHotend2(plaPreheatHotendTemp);
            setTargetBed(plaPreheatHPBTemp);
            fanSpeed = plaPreheatFanSpeed;
            lcd_return_to_status();
            setWatch(); // heater sanity check timer
#endif
#if defined (B) && (EXTRUDERS > 2 && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            _lcd_preheat(2, plaPreheatHotendTemp, plaPreheatHPBTemp, plaPreheatFanSpeed);
#endif
        }
        void lcd_preheat_abs2
        () {
#if defined (A) && (TEMP_SENSOR_2 != 0 && defined (ULTRA_LCD) && defined (ULTIPANEL) )
            setTargetHotend2(absPreheatHotendTemp);
            setTargetBed(absPreheatHPBTemp);
            fanSpeed = absPreheatFanSpeed;
            lcd_return_to_status();
            setWatch(); // heater sanity check timer
#endif
#if defined (B) && (EXTRUDERS > 2 && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            _lcd_preheat(2, absPreheatHotendTemp, absPreheatHPBTemp, absPreheatFanSpeed);
#endif
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
//3 extruder preheat
#endif
#if defined (B) && (EXTRUDERS > 3 && EXTRUDERS > 2 && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        void lcd_preheat_pla3() {
            _lcd_preheat(3, plaPreheatHotendTemp, plaPreheatHPBTemp, plaPreheatFanSpeed);
        }
#endif
#if defined (B) && (EXTRUDERS > 3 && EXTRUDERS > 2 && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        void lcd_preheat_pla3() {
            _lcd_preheat(3, plaPreheatHotendTemp, plaPreheatHPBTemp, plaPreheatFanSpeed);
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && (TEMP_SENSOR_1 != 0 || TEMP_SENSOR_2 != 0 && )defined (ULTIPANEL) )
//more than one extruder present
#endif
#if defined (B) && (EXTRUDERS > 3 && EXTRUDERS > 2 && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        void lcd_preheat_abs3() {
            _lcd_preheat(3, absPreheatHotendTemp, absPreheatHPBTemp, absPreheatFanSpeed);
        }
#endif
#if defined (B) && (EXTRUDERS > 3 && EXTRUDERS > 2 && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        void lcd_preheat_abs3() {
            _lcd_preheat(3, absPreheatHotendTemp, absPreheatHPBTemp, absPreheatFanSpeed);
        }
#endif
#if defined (A)
        void lcd_preheat_pla012() {
            setTargetHotend0(plaPreheatHotendTemp);
            setTargetHotend1(plaPreheatHotendTemp);
            setTargetHotend2(plaPreheatHotendTemp);
            setTargetBed(plaPreheatHPBTemp);
            fanSpeed = plaPreheatFanSpeed;
            lcd_return_to_status();
            setWatch(); // heater sanity check timer
        }
#endif
#if defined (B)
        void lcd_preheat_pla0123() {
            setTargetHotend0(plaPreheatHotendTemp);
            setTargetHotend1(plaPreheatHotendTemp);
            setTargetHotend2(plaPreheatHotendTemp);
            _lcd_preheat(3, plaPreheatHotendTemp, plaPreheatHPBTemp, plaPreheatFanSpeed);
        }
#endif
#if defined (A)
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
#if defined (B)
        void lcd_preheat_abs0123() {
            setTargetHotend0(absPreheatHotendTemp);
            setTargetHotend1(absPreheatHotendTemp);
            setTargetHotend2(absPreheatHotendTemp);
            _lcd_preheat(3, absPreheatHotendTemp, absPreheatHPBTemp, absPreheatFanSpeed);
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
//more than one extruder present
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
// EXTRUDERS > 1
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (TEMP_SENSOR_BED != 0 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        void lcd_preheat_pla_bedonly
        () {
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
            setTargetBed(plaPreheatHPBTemp);
            fanSpeed = plaPreheatFanSpeed;
            lcd_return_to_status();
            setWatch(); // heater sanity check timer
#endif
#if defined (B) && (TEMP_SENSOR_BED != 0 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            _lcd_preheat(0, 0, plaPreheatHPBTemp, plaPreheatFanSpeed);
#endif
        }
        void lcd_preheat_abs_bedonly
        () {
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
            setTargetBed(absPreheatHPBTemp);
            fanSpeed = absPreheatFanSpeed;
            lcd_return_to_status();
            setWatch(); // heater sanity check timer
#endif
#if defined (B) && (TEMP_SENSOR_BED != 0 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            _lcd_preheat(0, 0, absPreheatHPBTemp, absPreheatFanSpeed);
#endif
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        static void lcd_preheat_pla_menu
        () {
#if defined (A)
            START_MENU();
#endif
#if defined (B)
            START_MENU(lcd_prepare_menu);
#endif
            MENU_ITEM(back, MSG_PREPARE, lcd_prepare_menu);
#if defined (A)
            MENU_ITEM(function, MSG_PREHEAT_PLA0, lcd_preheat_pla0);
#endif
#if defined (B)
            MENU_ITEM(function, MSG_PREHEAT_PLA, lcd_preheat_pla0);
#endif
#if defined (A)
//2 extruder preheat
#endif
#if defined (B)
            MENU_ITEM(function, MSG_PREHEAT_PLA_N MSG_H1, lcd_preheat_pla0)
#endif
#if defined (A)
            MENU_ITEM(function, MSG_PREHEAT_PLA1, lcd_preheat_pla1);
#endif
#if defined (B)
            ;
#endif
#if defined (A)
//2 extruder preheat
#endif
#if defined (B)
            MENU_ITEM(function, MSG_PREHEAT_PLA_N MSG_H2, lcd_preheat_pla1)
#endif
#if defined (A)
//3 extruder preheat
#endif
#if defined (B)
            ;
#endif
#if defined (A)
            MENU_ITEM(function, MSG_PREHEAT_PLA2, lcd_preheat_pla2);
#endif
#if defined (B)
            MENU_ITEM(function, MSG_PREHEAT_PLA_N MSG_H3, lcd_preheat_pla2)
#endif
#if defined (A)
//3 extruder preheat
#endif
#if defined (B)
            ;
#endif
#if defined (A)
//all extruder preheat
#endif
#if defined (B)
            MENU_ITEM(function, MSG_PREHEAT_PLA_N MSG_H4, lcd_preheat_pla3)
#endif
#if defined (A)
            MENU_ITEM(function, MSG_PREHEAT_PLA012, lcd_preheat_pla012);
#endif
#if defined (B)
            ;
#endif
#if defined (A)
//2 extruder preheat
#endif
#if defined (B)
            MENU_ITEM(function, MSG_PREHEAT_PLA_ALL, lcd_preheat_pla0123);
#endif
#if defined (A) && (TEMP_SENSOR_BED != 0 && defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (TEMP_SENSOR_BED != 0 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            MENU_ITEM(function, MSG_PREHEAT_PLA_BEDONLY, lcd_preheat_pla_bedonly);
#endif
            END_MENU();
        }
        static void lcd_preheat_abs_menu
        () {
#if defined (A)
            START_MENU();
#endif
#if defined (B)
            START_MENU(lcd_prepare_menu);
#endif
            MENU_ITEM(back, MSG_PREPARE, lcd_prepare_menu);
#if defined (A)
            MENU_ITEM(function, MSG_PREHEAT_ABS0, lcd_preheat_abs0);
#endif
#if defined (B)
            MENU_ITEM(function, MSG_PREHEAT_ABS, lcd_preheat_abs0);
#endif
#if defined (A)
//2 extruder preheat
#endif
#if defined (B)
            MENU_ITEM(function, MSG_PREHEAT_ABS_N MSG_H1, lcd_preheat_abs0)
#endif
#if defined (A)
            MENU_ITEM(function, MSG_PREHEAT_ABS1, lcd_preheat_abs1);
#endif
#if defined (B)
            ;
#endif
#if defined (A)
//2 extruder preheat
#endif
#if defined (B)
            MENU_ITEM(function, MSG_PREHEAT_ABS_N MSG_H2, lcd_preheat_abs1)
#endif
#if defined (A)
//3 extruder preheat
#endif
#if defined (B)
            ;
#endif
#if defined (A)
            MENU_ITEM(function, MSG_PREHEAT_ABS2, lcd_preheat_abs2);
#endif
#if defined (B)
            MENU_ITEM(function, MSG_PREHEAT_ABS_N MSG_H3, lcd_preheat_abs2)
#endif
#if defined (A)
//3 extruder preheat
#endif
#if defined (B)
            ;
#endif
#if defined (A)
//all extruder preheat
#endif
#if defined (B)
            MENU_ITEM(function, MSG_PREHEAT_ABS_N MSG_H4, lcd_preheat_abs3)
#endif
#if defined (A)
            MENU_ITEM(function, MSG_PREHEAT_ABS012, lcd_preheat_abs012);
#endif
#if defined (B)
            ;
#endif
#if defined (A)
//2 extruder preheat
#endif
#if defined (B)
            MENU_ITEM(function, MSG_PREHEAT_ABS_ALL, lcd_preheat_abs0123);
#endif
#if defined (A) && (TEMP_SENSOR_BED != 0 && defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (TEMP_SENSOR_BED != 0 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            MENU_ITEM(function, MSG_PREHEAT_ABS_BEDONLY, lcd_preheat_abs_bedonly);
#endif
            END_MENU();
        }
        void lcd_cooldown
        () {
#if defined (A)
            setTargetHotend0(0);
#endif
#if defined (B)
            disable_all_heaters();
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
            setTargetHotend1(0);
            setTargetHotend2(0);
            setTargetBed(0);
#endif
            fanSpeed = 0;
            lcd_return_to_status();
        }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
         *
         * "Prepare" submenu
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        static void lcd_prepare_menu
        () {
#if defined (A)
            START_MENU();
#endif
#if defined (B)
            START_MENU(lcd_main_menu);
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//
// ^ Main
//
#endif
            MENU_ITEM(back, MSG_MAIN, lcd_main_menu);
#if defined (A)
            MENU_ITEM(function, MSG_AUTOSTART, lcd_autostart_sd);
#endif
#if defined (B)
//
#endif
#if defined (A)
            MENU_ITEM(gcode, MSG_DISABLE_STEPPERS, PSTR("M84"));
#endif
#if defined (B)
// Auto Home
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//
#endif
            MENU_ITEM(gcode, MSG_AUTO_HOME, PSTR("G28"));
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//
// Set Home Offsets
//
#endif
            MENU_ITEM(function, MSG_SET_HOME_OFFSETS, lcd_set_home_offsets);
//MENU_ITEM(gcode, MSG_SET_ORIGIN, PSTR("G92 X0 Y0 Z0"));
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//
// Level Bed
//
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(ENABLE_AUTO_BED_LEVELING) )
            if (axis_known_position[X_AXIS] && axis_known_position[Y_AXIS])
                MENU_ITEM(gcode, MSG_LEVEL_BED, PSTR("G29"));
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(MANUAL_BED_LEVELING) )
            MENU_ITEM(submenu, MSG_LEVEL_BED, lcd_level_bed);
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//
// Move Axis
//
            MENU_ITEM(submenu, MSG_MOVE_AXIS, lcd_move_menu);
//
// Disable Steppers
//
            MENU_ITEM(gcode, MSG_DISABLE_STEPPERS, PSTR("M84"));
//
// Preheat PLA
// Preheat ABS
//
#endif
#if defined (A) && (defined (ULTRA_LCD) && TEMP_SENSOR_0 != 0 && defined (ULTIPANEL) && (TEMP_SENSOR_1 != 0 || TEMP_SENSOR_2 != 0 || TEMP_SENSOR_BED != 0 &) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && (TEMP_SENSOR_1 != 0 || TEMP_SENSOR_2 != 0 || TEMP_SENSOR_3 != 0 || TEMP_SENSOR_BED != 0 && )TEMP_SENSOR_0 != 0 )
            MENU_ITEM(submenu, MSG_PREHEAT_PLA, lcd_preheat_pla_menu);
            MENU_ITEM(submenu, MSG_PREHEAT_ABS, lcd_preheat_abs_menu);
#endif
#if defined (A) && (defined (ULTRA_LCD) && (EMP_SENSOR_1 != 0 || TEMP_SENSOR_2 != 0 || TEMP_SENSOR_BED != 0 && )TEMP_SENSOR_0 != 0 && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && (EMP_SENSOR_1 != 0 || TEMP_SENSOR_2 != 0 || TEMP_SENSOR_3 != 0 || TEMP_SENSOR_BED != 0 && )TEMP_SENSOR_0 != 0 )
            MENU_ITEM(function, MSG_PREHEAT_PLA, lcd_preheat_pla0);
            MENU_ITEM(function, MSG_PREHEAT_ABS, lcd_preheat_abs0);
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//
// Cooldown
//
#endif
            MENU_ITEM(function, MSG_COOLDOWN, lcd_cooldown);
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//
// Switch power on/off
//
#endif
#if defined (A) && (defined (ULTRA_LCD) && PS_ON_PIN > -1 && defined (ULTIPANEL) ) || defined (B) && (HAS_POWER_SWITCH && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            if
            (powersupply) {
#if defined (A)
                {
                    MENU_ITEM(gcode, MSG_SWITCH_PS_OFF, PSTR("M81"));
                }
#endif
#if defined (B)
                MENU_ITEM(gcode, MSG_SWITCH_PS_OFF, PSTR("M81"));
#endif
            }
#if defined (A)
            else {
                MENU_ITEM(gcode, MSG_SWITCH_PS_ON, PSTR("M80"));
            }
#endif
#if defined (B)
            else
                MENU_ITEM(gcode, MSG_SWITCH_PS_ON, PSTR("M80"));
#endif
#endif
#if defined (A)
            MENU_ITEM(submenu, MSG_MOVE_AXIS, lcd_move_menu);
#endif
#if defined (B)
//
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
// Autostart
//
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && (ENABLED(SDSUPPORT) && ENABLED(MENU_ADDAUTOSTART) &)
            MENU_ITEM(function, MSG_AUTOSTART, lcd_autostart_sd);
#endif
            END_MENU();
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (DELTA_CALIBRATION_MENU) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(DELTA_CALIBRATION_MENU) )
        static void lcd_delta_calibrate_menu
        () {
#if defined (A)
            START_MENU();
#endif
#if defined (B)
            START_MENU(lcd_main_menu);
#endif
            MENU_ITEM(back, MSG_MAIN, lcd_main_menu);
            MENU_ITEM(gcode, MSG_AUTO_HOME, PSTR("G28"));
            MENU_ITEM(gcode, MSG_DELTA_CALIBRATE_X, PSTR("G0 F8000 X-77.94 Y-45 Z0"));
            MENU_ITEM(gcode, MSG_DELTA_CALIBRATE_Y, PSTR("G0 F8000 X77.94 Y-45 Z0"));
            MENU_ITEM(gcode, MSG_DELTA_CALIBRATE_Z, PSTR("G0 F8000 X0 Y90 Z0"));
            MENU_ITEM(gcode, MSG_DELTA_CALIBRATE_CENTER, PSTR("G0 F8000 X0 Y0 Z0"));
            END_MENU();
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
// DELTA_CALIBRATION_MENU
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        inline void line_to_current(AxisEnum axis) {
#if ENABLED(DELTA)
            calculate_delta(current_position);
            plan_buffer_line(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], current_position[E_AXIS], manual_feedrate[axis]/60, active_extruder);
#else
            plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS], manual_feedrate[axis]/60, active_extruder);
#endif
        }
        /**
         *
         * "Prepare" > "Move Axis" submenu
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        float move_menu_scale;
        static void lcd_move_menu_axis();
        static void _lcd_move
#if defined (A)
        (const char *name, int axis, int min, int max)
#endif
#if defined (B)
        (const char *name, AxisEnum axis, int min, int max)
#endif
        {
            if
            (encoderPosition != 0) {
                refresh_cmd_timeout();
                current_position[axis] += float((int)encoderPosition) * move_menu_scale;
                if
                (min_software_endstops && current_position[axis] < min)
                    current_position[axis] = min;
                if
                (max_software_endstops && current_position[axis] > max)
                    current_position[axis] = max;
                encoderPosition = 0;
#if defined (A)
                calculate_delta(current_position);
#endif
#if defined (B)
                line_to_current(axis);
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (DELTA) && defined (ULTIPANEL) )
                plan_buffer_line(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], current_position[E_AXIS], manual_feedrate[axis]/60, active_extruder);
#endif
#if defined (A) && (defined (ULTRA_LCD) && !defined (DELTA) && defined (ULTIPANEL) )
                plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS], manual_feedrate[axis]/60, active_extruder);
#endif
                lcdDrawUpdate = 1;
            }
            if
            (lcdDrawUpdate)
                lcd_implementation_drawedit(name, ftostr31(current_position[axis]));
            if
            (LCD_CLICKED)
                lcd_goto_menu(lcd_move_menu_axis);
        }
        static void lcd_move_x
        () {
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
            _lcd_move(PSTR("X"), X_AXIS, X_MIN_POS, X_MAX_POS);
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            _lcd_move(PSTR(MSG_MOVE_X), X_AXIS, X_MIN_POS, X_MAX_POS);
#endif
        }
        static void lcd_move_y
        () {
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
            _lcd_move(PSTR("Y"), Y_AXIS, Y_MIN_POS, Y_MAX_POS);
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            _lcd_move(PSTR(MSG_MOVE_Y), Y_AXIS, Y_MIN_POS, Y_MAX_POS);
#endif
        }
        static void lcd_move_z
        () {
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
            _lcd_move(PSTR("Z"), Z_AXIS, Z_MIN_POS, Z_MAX_POS);
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            _lcd_move(PSTR(MSG_MOVE_Z), Z_AXIS, Z_MIN_POS, Z_MAX_POS);
#endif
        }
        static void lcd_move_e
        () {
            if
            (encoderPosition != 0) {
                current_position[E_AXIS] += float((int)encoderPosition) * move_menu_scale;
                encoderPosition = 0;
#if defined (A)
                calculate_delta(current_position);
#endif
#if defined (B)
                line_to_current(E_AXIS);
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (DELTA) && defined (ULTIPANEL) )
                plan_buffer_line(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], current_position[E_AXIS], manual_feedrate[E_AXIS]/60, active_extruder);
#endif
#if defined (A) && (defined (ULTRA_LCD) && !defined (DELTA) && defined (ULTIPANEL) )
                plan_buffer_line(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS], manual_feedrate[E_AXIS]/60, active_extruder);
#endif
                lcdDrawUpdate = 1;
            }
            if
            (lcdDrawUpdate) {
#if defined (A)
                {
                    lcd_implementation_drawedit(PSTR("Extruder"), ftostr31(current_position[E_AXIS]));
                }
#endif
#if defined (B)
                lcd_implementation_drawedit(PSTR(MSG_MOVE_E), ftostr31(current_position[E_AXIS]));
#endif
            }
            if
            (LCD_CLICKED)
                lcd_goto_menu(lcd_move_menu_axis);
        }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
         *
         * "Prepare" > "Move Xmm" > "Move XYZ" submenu
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        static void lcd_move_menu_axis
        () {
#if defined (A)
            START_MENU();
#endif
#if defined (B)
            START_MENU(lcd_move_menu);
#endif
            MENU_ITEM(back, MSG_MOVE_AXIS, lcd_move_menu);
            MENU_ITEM(submenu, MSG_MOVE_X, lcd_move_x);
            MENU_ITEM(submenu, MSG_MOVE_Y, lcd_move_y);
            if
            (move_menu_scale < 10.0) {
                MENU_ITEM(submenu, MSG_MOVE_Z, lcd_move_z);
                MENU_ITEM(submenu, MSG_MOVE_E, lcd_move_e);
            }
            END_MENU();
        }
        static void lcd_move_menu_10mm
        () {
            move_menu_scale = 10.0;
            lcd_move_menu_axis();
        }
        static void lcd_move_menu_1mm
        () {
            move_menu_scale = 1.0;
            lcd_move_menu_axis();
        }
        static void lcd_move_menu_01mm
        () {
            move_menu_scale = 0.1;
            lcd_move_menu_axis();
        }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
         *
         * "Prepare" > "Move Axis" submenu
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        static void lcd_move_menu
        () {
#if defined (A)
            START_MENU();
#endif
#if defined (B)
            START_MENU(lcd_prepare_menu);
#endif
            MENU_ITEM(back, MSG_PREPARE, lcd_prepare_menu);
            MENU_ITEM(submenu, MSG_MOVE_10MM, lcd_move_menu_10mm);
            MENU_ITEM(submenu, MSG_MOVE_1MM, lcd_move_menu_1mm);
            MENU_ITEM(submenu, MSG_MOVE_01MM, lcd_move_menu_01mm);
//TODO:X,Y,Z,E
            END_MENU();
        }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
         *
         * "Control" submenu
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        static void lcd_control_menu
        () {
#if defined (A)
            START_MENU();
#endif
#if defined (B)
            START_MENU(lcd_main_menu);
#endif
            MENU_ITEM(back, MSG_MAIN, lcd_main_menu);
            MENU_ITEM(submenu, MSG_TEMPERATURE, lcd_control_temperature_menu);
            MENU_ITEM(submenu, MSG_MOTION, lcd_control_motion_menu);
            MENU_ITEM(submenu, MSG_VOLUMETRIC, lcd_control_volumetric_menu);
#if defined (A) && (defined (DOGLCD) && defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(HAS_LCD_CONTRAST) )
//    MENU_ITEM_EDIT(int3, MSG_CONTRAST, &lcd_contrast, 0, 63);
            MENU_ITEM(submenu, MSG_CONTRAST, lcd_set_contrast);
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) && defined (FWRETRACT) ) || defined (B) && (ENABLED(FWRETRACT) && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            MENU_ITEM(submenu, MSG_RETRACT, lcd_control_retract_menu);
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (EEPROM_SETTINGS) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(EEPROM_SETTINGS) )
            MENU_ITEM(function, MSG_STORE_EPROM, Config_StoreSettings);
            MENU_ITEM(function, MSG_LOAD_EPROM, Config_RetrieveSettings);
#endif
            MENU_ITEM(function, MSG_RESTORE_FAILSAFE, Config_ResetDefault);
            END_MENU();
        }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
         *
         * "Temperature" submenu
         *
         */
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(PIDTEMP) )
// Helpers for editing PID Ki & Kd values
// grab the PID value out of the temp variable; scale it; then update the PID driver
        void copy_and_scalePID_i(int e) {
            PID_PARAM(Ki, e) = scalePID_i(raw_Ki);
            updatePID();
        }
        void copy_and_scalePID_d(int e) {
            PID_PARAM(Kd, e) = scalePID_d(raw_Kd);
            updatePID();
        }
        void copy_and_scalePID_i_E1() {
            copy_and_scalePID_i(0);
        }
        void copy_and_scalePID_d_E1() {
            copy_and_scalePID_d(0);
        }
#endif
#if defined (B) && (ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(PIDTEMP) )
        void copy_and_scalePID_i_E2() {
            copy_and_scalePID_i(1);
        }
        void copy_and_scalePID_d_E2() {
            copy_and_scalePID_d(1);
        }
#endif
#if defined (B) && (EXTRUDERS > 2 && ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(PIDTEMP) )
        void copy_and_scalePID_i_E3() {
            copy_and_scalePID_i(2);
        }
        void copy_and_scalePID_d_E3() {
            copy_and_scalePID_d(2);
        }
#endif
#if defined (B) && (EXTRUDERS > 3 && EXTRUDERS > 2 && ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(PIDTEMP) )
        void copy_and_scalePID_i_E4() {
            copy_and_scalePID_i(3);
        }
        void copy_and_scalePID_d_E4() {
            copy_and_scalePID_d(3);
        }
#endif
#if defined (B) && (EXTRUDERS > 2 && ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(PIDTEMP) )
//EXTRUDERS > 3
#endif
#if defined (B) && (ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(PIDTEMP) )
//EXTRUDERS > 2
#endif
#if defined (B) && (ENABLED(PID_PARAMS_PER_EXTRUDER) && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(PIDTEMP) )
//EXTRUDERS > 1
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(PIDTEMP) )
//PID_PARAMS_PER_EXTRUDER
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//PIDTEMP
        /**
         *
         * "Control" > "Temperature" submenu
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        static void lcd_control_temperature_menu
        () {
#if defined (A)
// set up temp variables - undo the default scaling
#endif
#if defined (B)
            START_MENU(lcd_control_menu);
#endif
#if defined (A)
            raw_Ki = unscalePID_i(Ki);
#endif
#if defined (B)
//
#endif
#if defined (A)
            raw_Kd = unscalePID_d(Kd);
#endif
#if defined (B)
// ^ Control
#endif
#if defined (A)
            START_MENU();
#endif
#if defined (B)
//
#endif
            MENU_ITEM(back, MSG_CONTROL, lcd_control_menu);
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_NOZZLE, &target_temperature[0], 0, HEATER_0_MAXTEMP - 15);
#endif
#if defined (B)
//
#endif
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_NOZZLE1, &target_temperature[1], 0, HEATER_1_MAXTEMP - 15);
#endif
#if defined (B)
// Nozzle, Nozzle 2, Nozzle 3, Nozzle 4
#endif
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_NOZZLE2, &target_temperature[2], 0, HEATER_2_MAXTEMP - 15);
#endif
#if defined (B)
//
#endif
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_BED, &target_temperature_bed, 0, BED_MAXTEMP - 15);
#endif
#if defined (B)
            MENU_MULTIPLIER_ITEM_EDIT(int3, MSG_NOZZLE, &target_temperature[0], 0, HEATER_0_MAXTEMP - 15);
#endif
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_FAN_SPEED, &fanSpeed, 0, 255);
#endif
#if defined (B)
            MENU_MULTIPLIER_ITEM_EDIT(int3, MSG_NOZZLE MSG_N2, &target_temperature[1], 0, HEATER_1_MAXTEMP - 15)
#endif
#if defined (B) && (EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && TEMP_SENSOR_1 != 0 )
            ;
#endif
#if defined (B) && (TEMP_SENSOR_2 != 0 && EXTRUDERS > 2 && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            MENU_MULTIPLIER_ITEM_EDIT(int3, MSG_NOZZLE MSG_N3, &target_temperature[2], 0, HEATER_2_MAXTEMP - 15)
            ;
#endif
#if defined (B) && (EXTRUDERS > 3 && EXTRUDERS > 2 && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && TEMP_SENSOR_3 != 0 )
            MENU_MULTIPLIER_ITEM_EDIT(int3, MSG_NOZZLE MSG_N4, &target_temperature[3], 0, HEATER_3_MAXTEMP - 15)
            ;
#endif
#if defined (B) && (EXTRUDERS > 2 && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
// EXTRUDERS > 3
#endif
#if defined (B) && (EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
// EXTRUDERS > 2
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
// EXTRUDERS > 1
//
// Bed
//
#endif
#if defined (B) && (TEMP_SENSOR_BED != 0 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            MENU_MULTIPLIER_ITEM_EDIT(int3, MSG_BED, &target_temperature_bed, 0, BED_MAXTEMP - 15);
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//
// Fan Speed
//
            MENU_MULTIPLIER_ITEM_EDIT(int3, MSG_FAN_SPEED, &fanSpeed, 0, 255);
//
// Autotemp, Min, Max, Fact
//
#endif
#if defined (A) && (defined (ULTRA_LCD) && (defined AUTOTEMP && (TEMP_SENSOR_0 != 0) && )defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && (ENABLED(AUTOTEMP) && (TEMP_SENSOR_0 != 0) &)
            MENU_ITEM_EDIT(bool, MSG_AUTOTEMP, &autotemp_enabled);
            MENU_ITEM_EDIT(float3, MSG_MIN, &autotemp_min, 0, HEATER_0_MAXTEMP - 15);
            MENU_ITEM_EDIT(float3, MSG_MAX, &autotemp_max, 0, HEATER_0_MAXTEMP - 15);
            MENU_ITEM_EDIT(float32, MSG_FACTOR, &autotemp_factor, 0.0, 1.0);
#endif
#if defined (A)
            MENU_ITEM_EDIT(float52, MSG_PID_P, &Kp, 1, 9990);
#endif
#if defined (B)
//
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
// PID-P, PID-I, PID-D, PID-C
//
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(ULTRA_LCD) )
// set up temp variables - undo the default scaling
            raw_Ki = unscalePID_i(PID_PARAM(Ki,0));
            raw_Kd = unscalePID_d(PID_PARAM(Kd,0));
            MENU_ITEM_EDIT(float52, MSG_PID_P, &PID_PARAM(Kp,0), 1, 9990);
// i is typically a small value so allows values below 1
            MENU_ITEM_EDIT_CALLBACK(float52, MSG_PID_I, &raw_Ki, 0.01, 9990, copy_and_scalePID_i_E1);
            MENU_ITEM_EDIT_CALLBACK(float52, MSG_PID_D, &raw_Kd, 1, 9990, copy_and_scalePID_d_E1);
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(PID_ADD_EXTRUSION_RATE) && ENABLED(ULTRA_LCD) )
            MENU_ITEM_EDIT(float3, MSG_PID_C, &PID_PARAM(Kc,0), 1, 9990);
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(ULTRA_LCD) )
//PID_ADD_EXTRUSION_RATE
#endif
#if defined (B) && (ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(ULTRA_LCD) )
// set up temp variables - undo the default scaling
            raw_Ki = unscalePID_i(PID_PARAM(Ki,1));
            raw_Kd = unscalePID_d(PID_PARAM(Kd,1));
            MENU_ITEM_EDIT(float52, MSG_PID_P MSG_E2, &PID_PARAM(Kp,1), 1, 9990)
            ;
// i is typically a small value so allows values below 1
            MENU_ITEM_EDIT_CALLBACK(float52, MSG_PID_I MSG_E2, &raw_Ki, 0.01, 9990, copy_and_scalePID_i_E2)
            ;
            MENU_ITEM_EDIT_CALLBACK(float52, MSG_PID_D MSG_E2, &raw_Kd, 1, 9990, copy_and_scalePID_d_E2)
            ;
#endif
#if defined (B) && (ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(PID_ADD_EXTRUSION_RATE) && ENABLED(ULTRA_LCD) )
            MENU_ITEM_EDIT(float3, MSG_PID_C MSG_E2, &PID_PARAM(Kc,1), 1, 9990)
            ;
#endif
#if defined (B) && (ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(ULTRA_LCD) )
//PID_ADD_EXTRUSION_RATE
#endif
#if defined (B) && (EXTRUDERS > 2 && ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(ULTRA_LCD) )
// set up temp variables - undo the default scaling
            raw_Ki = unscalePID_i(PID_PARAM(Ki,2));
            raw_Kd = unscalePID_d(PID_PARAM(Kd,2));
            MENU_ITEM_EDIT(float52, MSG_PID_P MSG_E3, &PID_PARAM(Kp,2), 1, 9990)
            ;
// i is typically a small value so allows values below 1
            MENU_ITEM_EDIT_CALLBACK(float52, MSG_PID_I MSG_E3, &raw_Ki, 0.01, 9990, copy_and_scalePID_i_E3)
            ;
            MENU_ITEM_EDIT_CALLBACK(float52, MSG_PID_D MSG_E3, &raw_Kd, 1, 9990, copy_and_scalePID_d_E3)
            ;
#endif
#if defined (B) && (EXTRUDERS > 2 && ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(PID_ADD_EXTRUSION_RATE) && ENABLED(ULTRA_LCD) )
            MENU_ITEM_EDIT(float3, MSG_PID_C MSG_E3, &PID_PARAM(Kc,2), 1, 9990)
            ;
#endif
#if defined (B) && (EXTRUDERS > 2 && ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(ULTRA_LCD) )
//PID_ADD_EXTRUSION_RATE
#endif
#if defined (B) && (EXTRUDERS > 3 && EXTRUDERS > 2 && ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(ULTRA_LCD) )
// set up temp variables - undo the default scaling
            raw_Ki = unscalePID_i(PID_PARAM(Ki,3));
            raw_Kd = unscalePID_d(PID_PARAM(Kd,3));
            MENU_ITEM_EDIT(float52, MSG_PID_P MSG_E4, &PID_PARAM(Kp,3), 1, 9990)
            ;
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (PIDTEMP) && defined (ULTIPANEL) ) || defined (B) && (EXTRUDERS > 3 && EXTRUDERS > 2 && ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(ULTRA_LCD) )
// i is typically a small value so allows values below 1
#endif
#if defined (A)
            MENU_ITEM_EDIT_CALLBACK(float52, MSG_PID_I, &raw_Ki, 0.01, 9990, copy_and_scalePID_i);
#endif
#if defined (B)
            MENU_ITEM_EDIT_CALLBACK(float52, MSG_PID_I MSG_E4, &raw_Ki, 0.01, 9990, copy_and_scalePID_i_E4)
#endif
#if defined (A)
            MENU_ITEM_EDIT_CALLBACK(float52, MSG_PID_D, &raw_Kd, 1, 9990, copy_and_scalePID_d);
#endif
#if defined (B)
            ;
#endif
#if defined (A)
            MENU_ITEM_EDIT(float3, MSG_PID_C, &Kc, 1, 9990);
#endif
#if defined (B)
            MENU_ITEM_EDIT_CALLBACK(float52, MSG_PID_D MSG_E4, &raw_Kd, 1, 9990, copy_and_scalePID_d_E4)
#endif
#if defined (B) && (EXTRUDERS > 3 && EXTRUDERS > 2 && ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(ULTRA_LCD) )
            ;
#endif
#if defined (B) && (EXTRUDERS > 3 && EXTRUDERS > 2 && ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(PID_ADD_EXTRUSION_RATE) && ENABLED(ULTRA_LCD) )
            MENU_ITEM_EDIT(float3, MSG_PID_C MSG_E4, &PID_PARAM(Kc,3), 1, 9990)
            ;
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (PIDTEMP) && defined (ULTIPANEL) ) || defined (B) && (EXTRUDERS > 3 && EXTRUDERS > 2 && ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(ULTRA_LCD) )
//PID_ADD_EXTRUSION_RATE
#endif
#if defined (B) && (EXTRUDERS > 2 && ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(ULTRA_LCD) )
//EXTRUDERS > 3
#endif
#if defined (B) && (ENABLED(PID_PARAMS_PER_EXTRUDER) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(ULTRA_LCD) )
//EXTRUDERS > 2
#endif
#if defined (B) && (ENABLED(PID_PARAMS_PER_EXTRUDER) && ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(ULTRA_LCD) )
//EXTRUDERS > 1
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(PIDTEMP) && ENABLED(ULTRA_LCD) )
//PID_PARAMS_PER_EXTRUDER
#endif
//PIDTEMP
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//
// Preheat PLA conf
//
#endif
            MENU_ITEM(submenu, MSG_PREHEAT_PLA_SETTINGS, lcd_control_temperature_preheat_pla_settings_menu);
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//
// Preheat ABS conf
//
#endif
            MENU_ITEM(submenu, MSG_PREHEAT_ABS_SETTINGS, lcd_control_temperature_preheat_abs_settings_menu);
            END_MENU();
        }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
         *
         * "Temperature" > "Preheat PLA conf" submenu
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        static void lcd_control_temperature_preheat_pla_settings_menu
        () {
#if defined (A)
            START_MENU();
#endif
#if defined (B)
            START_MENU(lcd_control_temperature_menu);
#endif
            MENU_ITEM(back, MSG_TEMPERATURE, lcd_control_temperature_menu);
            MENU_ITEM_EDIT(int3, MSG_FAN_SPEED, &plaPreheatFanSpeed, 0, 255);
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_NOZZLE, &plaPreheatHotendTemp, 0, HEATER_0_MAXTEMP - 15);
#endif
#if defined (B)
            MENU_ITEM_EDIT(int3, MSG_NOZZLE, &plaPreheatHotendTemp, HEATER_0_MINTEMP, HEATER_0_MAXTEMP - 15);
#endif
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_BED, &plaPreheatHPBTemp, 0, BED_MAXTEMP - 15);
#endif
#if defined (B)
            MENU_ITEM_EDIT(int3, MSG_BED, &plaPreheatHPBTemp, BED_MINTEMP, BED_MAXTEMP - 15);
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (EEPROM_SETTINGS) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(EEPROM_SETTINGS) )
            MENU_ITEM(function, MSG_STORE_EPROM, Config_StoreSettings);
#endif
            END_MENU();
        }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
         *
         * "Temperature" > "Preheat ABS conf" submenu
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        static void lcd_control_temperature_preheat_abs_settings_menu
        () {
#if defined (A)
            START_MENU();
#endif
#if defined (B)
            START_MENU(lcd_control_temperature_menu);
#endif
            MENU_ITEM(back, MSG_TEMPERATURE, lcd_control_temperature_menu);
            MENU_ITEM_EDIT(int3, MSG_FAN_SPEED, &absPreheatFanSpeed, 0, 255);
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_NOZZLE, &absPreheatHotendTemp, 0, HEATER_0_MAXTEMP - 15);
#endif
#if defined (B)
            MENU_ITEM_EDIT(int3, MSG_NOZZLE, &absPreheatHotendTemp, HEATER_0_MINTEMP, HEATER_0_MAXTEMP - 15);
#endif
#if defined (A)
            MENU_ITEM_EDIT(int3, MSG_BED, &absPreheatHPBTemp, 0, BED_MAXTEMP - 15);
#endif
#if defined (B)
            MENU_ITEM_EDIT(int3, MSG_BED, &absPreheatHPBTemp, BED_MINTEMP, BED_MAXTEMP - 15);
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (EEPROM_SETTINGS) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(EEPROM_SETTINGS) )
            MENU_ITEM(function, MSG_STORE_EPROM, Config_StoreSettings);
#endif
            END_MENU();
        }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
         *
         * "Control" > "Motion" submenu
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        static void lcd_control_motion_menu
        () {
#if defined (A)
            START_MENU();
#endif
#if defined (B)
            START_MENU(lcd_control_menu);
#endif
            MENU_ITEM(back, MSG_CONTROL, lcd_control_menu);
#if defined (A)
            MENU_ITEM_EDIT(float32, MSG_ZPROBE_ZOFFSET, &zprobe_zoffset, 0.5, 50);
#endif
#if defined (B)
            MENU_ITEM_EDIT(float32, MSG_ZPROBE_ZOFFSET, &zprobe_zoffset, Z_PROBE_OFFSET_RANGE_MIN, Z_PROBE_OFFSET_RANGE_MAX);
#endif
#if defined (A)
            MENU_ITEM_EDIT(float5, MSG_ACC, &acceleration, 500, 99000);
#endif
#if defined (B)
            MENU_ITEM_EDIT(float5, MSG_ACC, &acceleration, 10, 99000);
#endif
            MENU_ITEM_EDIT(float3, MSG_VXY_JERK, &max_xy_jerk, 1, 990);
            MENU_ITEM_EDIT(float52, MSG_VZ_JERK, &max_z_jerk, 0.1, 990);
            MENU_ITEM_EDIT(float3, MSG_VE_JERK, &max_e_jerk, 1, 990);
            ;
            ;
            ;
            ;
            MENU_ITEM_EDIT(float3, MSG_VMIN, &minimumfeedrate, 0, 999);
            MENU_ITEM_EDIT(float3, MSG_VTRAV_MIN, &mintravelfeedrate, 0, 999);
            ;
            ;
#if defined (A)
            MENU_ITEM_EDIT_CALLBACK(long5, MSG_AMAX MSG_Z, &max_acceleration_units_per_sq_second[Z_AXIS], 100, 99000, reset_acceleration_rates)
#endif
#if defined (B)
            MENU_ITEM_EDIT_CALLBACK(long5, MSG_AMAX MSG_Z, &max_acceleration_units_per_sq_second[Z_AXIS], 10, 99000, reset_acceleration_rates)
#endif
            ;
            ;
            MENU_ITEM_EDIT(float5, MSG_A_RETRACT, &retract_acceleration, 100, 99000);
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            MENU_ITEM_EDIT(float5, MSG_A_TRAVEL, &travel_acceleration, 100, 99000);
#endif
            MENU_ITEM_EDIT(float52, MSG_XSTEPS, &axis_steps_per_unit[X_AXIS], 5, 9999);
            MENU_ITEM_EDIT(float52, MSG_YSTEPS, &axis_steps_per_unit[Y_AXIS], 5, 9999);
            MENU_ITEM_EDIT(float51, MSG_ZSTEPS, &axis_steps_per_unit[Z_AXIS], 5, 9999);
            MENU_ITEM_EDIT(float51, MSG_ESTEPS, &axis_steps_per_unit[E_AXIS], 5, 9999);
#if defined (A) && (defined (ULTRA_LCD) && defined (ABORT_ON_ENDSTOP_HIT_FEATURE_ENABLED) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(ABORT_ON_ENDSTOP_HIT_FEATURE_ENABLED) )
            MENU_ITEM_EDIT(bool, MSG_ENDSTOP_ABORT, &abort_on_endstop_hit);
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (SCARA) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(SCARA) )
            MENU_ITEM_EDIT(float74, MSG_XSCALE, &axis_scaling[X_AXIS],0.5,2);
            MENU_ITEM_EDIT(float74, MSG_YSCALE, &axis_scaling[Y_AXIS],0.5,2);
#endif
            END_MENU();
        }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
         *
         * "Control" > "Filament" submenu
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        static void lcd_control_volumetric_menu
        () {
#if defined (A)
            START_MENU();
#endif
#if defined (B)
            START_MENU(lcd_control_menu);
#endif
            MENU_ITEM(back, MSG_CONTROL, lcd_control_menu);
            MENU_ITEM_EDIT_CALLBACK(bool, MSG_VOLUMETRIC_ENABLED, &volumetric_enabled, calculate_volumetric_multipliers);
            if
            (volumetric_enabled) {
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
                MENU_ITEM_EDIT_CALLBACK(float43, MSG_FILAMENT_SIZE_EXTRUDER_0, &filament_size[0], DEFAULT_NOMINAL_FILAMENT_DIA - .5, DEFAULT_NOMINAL_FILAMENT_DIA + .5, calculate_volumetric_multipliers);
#if EXTRUDERS > 1
                MENU_ITEM_EDIT_CALLBACK(float43, MSG_FILAMENT_SIZE_EXTRUDER_1, &filament_size[1], DEFAULT_NOMINAL_FILAMENT_DIA - .5, DEFAULT_NOMINAL_FILAMENT_DIA + .5, calculate_volumetric_multipliers);
#if EXTRUDERS > 2
                MENU_ITEM_EDIT_CALLBACK(float43, MSG_FILAMENT_SIZE_EXTRUDER_2, &filament_size[2], DEFAULT_NOMINAL_FILAMENT_DIA - .5, DEFAULT_NOMINAL_FILAMENT_DIA + .5, calculate_volumetric_multipliers);
#endif
#endif
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
                MENU_MULTIPLIER_ITEM_EDIT_CALLBACK(float43, MSG_FILAMENT_SIZE_EXTRUDER_0, &filament_size[0], 1.5, 3.25, calculate_volumetric_multipliers);
#if EXTRUDERS > 1
                MENU_MULTIPLIER_ITEM_EDIT_CALLBACK(float43, MSG_FILAMENT_SIZE_EXTRUDER_1, &filament_size[1], 1.5, 3.25, calculate_volumetric_multipliers);
#if EXTRUDERS > 2
                MENU_MULTIPLIER_ITEM_EDIT_CALLBACK(float43, MSG_FILAMENT_SIZE_EXTRUDER_2, &filament_size[2], 1.5, 3.25, calculate_volumetric_multipliers);
#if EXTRUDERS > 3
                MENU_MULTIPLIER_ITEM_EDIT_CALLBACK(float43, MSG_FILAMENT_SIZE_EXTRUDER_3, &filament_size[3], 1.5, 3.25, calculate_volumetric_multipliers);
#endif //EXTRUDERS > 3
#endif //EXTRUDERS > 2
#endif //EXTRUDERS > 1
#endif
            }
            END_MENU();
        }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
         *
         * "Control" > "Contrast" submenu
         *
         */
#endif
#if defined (A) && (defined (DOGLCD) && defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(HAS_LCD_CONTRAST) )
        static void lcd_set_contrast
        () {
            if
            (encoderPosition != 0) {
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(U8GLIB_LM6059_AF) && ENABLED(ULTRA_LCD) && ENABLED(HAS_LCD_CONTRAST) )
                lcd_contrast += encoderPosition;
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(U8GLIB_LM6059_AF) && ENABLED(ULTRA_LCD) && ENABLED(HAS_LCD_CONTRAST) )
                lcd_contrast &= 0xFF;
#endif
#if defined (A) && (defined (DOGLCD) && defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(HAS_LCD_CONTRAST) && !ENABLED(U8GLIB_LM6059_AF) )
                lcd_contrast -= encoderPosition;
#endif
#if defined (A)
                if (lcd_contrast < 0) lcd_contrast = 0;
                else if (lcd_contrast > 63) lcd_contrast = 63;
#endif
#if defined (B)
                lcd_contrast &= 0x3F;
#endif
                encoderPosition = 0;
                lcdDrawUpdate = 1;
                u8g.setContrast(lcd_contrast);
            }
            if
            (lcdDrawUpdate) {
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(U8GLIB_LM6059_AF) && ENABLED(ULTRA_LCD) && ENABLED(HAS_LCD_CONTRAST) )
                lcd_implementation_drawedit(PSTR(MSG_CONTRAST), itostr3(lcd_contrast));
#endif
#if defined (A) && (defined (DOGLCD) && defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(HAS_LCD_CONTRAST) && !ENABLED(U8GLIB_LM6059_AF) )
                lcd_implementation_drawedit(PSTR(MSG_CONTRAST), itostr2(lcd_contrast));
#endif
            }
            if
            (LCD_CLICKED)
                lcd_goto_menu(lcd_control_menu);
        }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
// HAS_LCD_CONTRAST
        /**
         *
         * "Control" > "Retract" submenu
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) && defined (FWRETRACT) ) || defined (B) && (ENABLED(FWRETRACT) && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        static void lcd_control_retract_menu
        () {
#if defined (A)
            START_MENU();
#endif
#if defined (B)
            START_MENU(lcd_control_menu);
#endif
            MENU_ITEM(back, MSG_CONTROL, lcd_control_menu);
            MENU_ITEM_EDIT(bool, MSG_AUTORETRACT, &autoretract_enabled);
            MENU_ITEM_EDIT(float52, MSG_CONTROL_RETRACT, &retract_length, 0, 100);
#if defined (A) && (EXTRUDERS > 1 && defined (ULTRA_LCD) && defined (ULTIPANEL) && defined (FWRETRACT) ) || defined (B) && (ENABLED(FWRETRACT) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            MENU_ITEM_EDIT(float52, MSG_CONTROL_RETRACT_SWAP, &retract_length_swap, 0, 100);
#endif
            MENU_ITEM_EDIT(float3, MSG_CONTROL_RETRACTF, &retract_feedrate, 1, 999);
            MENU_ITEM_EDIT(float52, MSG_CONTROL_RETRACT_ZLIFT, &retract_zlift, 0, 999);
            MENU_ITEM_EDIT(float52, MSG_CONTROL_RETRACT_RECOVER, &retract_recover_length, 0, 100);
#if defined (A) && (EXTRUDERS > 1 && defined (ULTRA_LCD) && defined (ULTIPANEL) && defined (FWRETRACT) ) || defined (B) && (ENABLED(FWRETRACT) && EXTRUDERS > 1 && ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            MENU_ITEM_EDIT(float52, MSG_CONTROL_RETRACT_RECOVER_SWAP, &retract_recover_length_swap, 0, 100);
#endif
            MENU_ITEM_EDIT(float3, MSG_CONTROL_RETRACT_RECOVERF, &retract_recover_feedrate, 1, 999);
            END_MENU();
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
//FWRETRACT
#endif
#if defined (A) && (defined (ULTRA_LCD) && SDCARDDETECT == -1 && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && defined (SDSUPPORT) && SDCARDDETECT == -1 )
        static void lcd_sd_refresh
        () {
            card.initsd();
            currentMenuViewOffset = 0;
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && defined (SDSUPPORT) )
        static void lcd_sd_updir
        () {
            card.updir();
            currentMenuViewOffset = 0;
        }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && defined (SDSUPPORT) )
        /**
         *
         * "Print from SD" submenu
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && defined (SDSUPPORT) )
        void lcd_sdcard_menu
        () {
            if
            (lcdDrawUpdate == 0 && LCD_CLICKED == 0)
                return;
// nothing to do (so don't thrash the SD card)
            uint16_t fileCnt = card.getnrfilenames();
#if defined (A)
            START_MENU();
#endif
#if defined (B)
            START_MENU(lcd_main_menu);
#endif
            MENU_ITEM(back, MSG_MAIN, lcd_main_menu);
            card.getWorkDirName();
            if
            (card.filename[0]=='/') {
#if defined (A) && (defined (ULTRA_LCD) && SDCARDDETECT == -1 && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && SDCARDDETECT == -1 && defined (SDSUPPORT) )
#endif
            } else {
                MENU_ITEM(function, LCD_STR_FOLDER "..", lcd_sd_updir);
            }
#if defined (A)
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
#endif
#if defined (B)
            for (uint16_t i = 0; i < fileCnt; i++) {
                if (_menuItemNr == _lineNr) {
                    card.getfilename(
#if ENABLED(SDCARD_RATHERRECENTFIRST)
                        fileCnt-1 -
#endif
                        i
                    );
                    if (card.filenameIsDir)
                        MENU_ITEM(sddirectory, MSG_CARD_MENU, card.filename, card.longFilename);
                    else
                        MENU_ITEM(sdfile, MSG_CARD_MENU, card.filename, card.longFilename);
                } else {
                    MENU_ITEM_DUMMY();
                }
            }
#endif
            END_MENU();
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
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
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
         *
         * Functions for editing single values
         *
         */
#define menu_edit_type(_type, _name, _strFunc, scale) \
  bool _menu_edit_ ## _name () { \
    bool isClicked = LCD_CLICKED; \
    if ((int32_t)encoderPosition < 0) encoderPosition = 0; \
    if ((int32_t)encoderPosition > maxEditValue) encoderPosition = maxEditValue; \
    if (lcdDrawUpdate) \
        lcd_implementation_drawedit(editLabel, _strFunc(((_type)((int32_t)encoderPosition + minEditValue)) / scale)); \
    if (isClicked) { \
      *((_type*)editValue) = ((_type)((int32_t)encoderPosition + minEditValue)) / scale; \
      lcd_goto_menu(prevMenu, prevEncoderPosition); \
    } \
    return isClicked; \
  } \
  void menu_edit_ ## _name () { _menu_edit_ ## _name(); } \
  void menu_edit_callback_ ## _name () { if (_menu_edit_ ## _name ()) (*callbackFunc)(); } \
  static void _menu_action_setting_edit_ ## _name (const char* pstr, _type* ptr, _type minValue, _type maxValue) { \
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
  } \
  static void menu_action_setting_edit_ ## _name (const char* pstr, _type* ptr, _type minValue, _type maxValue) { \
    _menu_action_setting_edit_ ## _name(pstr, ptr, minValue, maxValue); \
    currentMenu = menu_edit_ ## _name; \
  }\
  static void menu_action_setting_edit_callback_ ## _name (const char* pstr, _type* ptr, _type minValue, _type maxValue, menuFunc_t callback) { \
    _menu_action_setting_edit_ ## _name(pstr, ptr, minValue, maxValue); \
    currentMenu = menu_edit_callback_ ## _name; \
    callbackFunc = callback; \
  }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
         *
         * Handlers for RepRap World Keypad input
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (REPRAPWORLD_KEYPAD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(REPRAPWORLD_KEYPAD) )
        static void reprapworld_keypad_move_z_up
        () {
            encoderPosition = 1;
            move_menu_scale = REPRAPWORLD_KEYPAD_MOVE_STEP;
            lcd_move_z();
        }
        static void reprapworld_keypad_move_z_down
        () {
            encoderPosition = -1;
            move_menu_scale = REPRAPWORLD_KEYPAD_MOVE_STEP;
            lcd_move_z();
        }
        static void reprapworld_keypad_move_x_left
        () {
            encoderPosition = -1;
            move_menu_scale = REPRAPWORLD_KEYPAD_MOVE_STEP;
            lcd_move_x();
        }
        static void reprapworld_keypad_move_x_right
        () {
            encoderPosition = 1;
            move_menu_scale = REPRAPWORLD_KEYPAD_MOVE_STEP;
            lcd_move_x();
        }
        static void reprapworld_keypad_move_y_down
        () {
            encoderPosition = 1;
            move_menu_scale = REPRAPWORLD_KEYPAD_MOVE_STEP;
            lcd_move_y();
        }
        static void reprapworld_keypad_move_y_up
        () {
            encoderPosition = -1;
            move_menu_scale = REPRAPWORLD_KEYPAD_MOVE_STEP;
            lcd_move_y();
        }
        static void reprapworld_keypad_move_home
        () {
#if defined (A)
            enquecommand_P((PSTR("G28")));
#endif
#if defined (B)
            enqueuecommands_P((PSTR("G28")));
#endif
// move all axis home
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
        /** End of menus **/
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
// REPRAPWORLD_KEYPAD
#endif
#if defined (A)
        static void lcd_quick_feedback() {
            lcdDrawUpdate = 2;
            blocking_enc = millis() + 500;
            lcd_implementation_quick_feedback();
        }
#endif
#if defined (B)
        /**
         *
         * Audio feedback for controller clicks
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
        /** Menu action functions **/
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(LCD_USE_I2C_BUZZER) )
        void lcd_buzz(long duration, uint16_t freq) { // called from buzz() in Marlin_main.cpp where lcd is unknown
            lcd.buzz(duration, freq);
        }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(LCD_USE_I2C_BUZZER) )
        void lcd_buzz(long duration, uint16_t freq) { // called from buzz() in Marlin_main.cpp where lcd is unknown
            lcd.buzz(duration, freq);
        }
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        void lcd_quick_feedback() {
            lcdDrawUpdate = 2;
            next_button_update_ms = millis() + 500;
#if ENABLED(LCD_USE_I2C_BUZZER)
#ifndef LCD_FEEDBACK_FREQUENCY_HZ
#define LCD_FEEDBACK_FREQUENCY_HZ 100
#endif
#ifndef LCD_FEEDBACK_FREQUENCY_DURATION_MS
#define LCD_FEEDBACK_FREQUENCY_DURATION_MS (1000/6)
#endif
            lcd.buzz(LCD_FEEDBACK_FREQUENCY_DURATION_MS, LCD_FEEDBACK_FREQUENCY_HZ);
#elif defined(BEEPER) && BEEPER >= 0
#ifndef LCD_FEEDBACK_FREQUENCY_HZ
#define LCD_FEEDBACK_FREQUENCY_HZ 5000
#endif
#ifndef LCD_FEEDBACK_FREQUENCY_DURATION_MS
#define LCD_FEEDBACK_FREQUENCY_DURATION_MS 2
#endif
            buzz(LCD_FEEDBACK_FREQUENCY_DURATION_MS, LCD_FEEDBACK_FREQUENCY_HZ);
#else
#ifndef LCD_FEEDBACK_FREQUENCY_DURATION_MS
#define LCD_FEEDBACK_FREQUENCY_DURATION_MS 2
#endif
            delay(LCD_FEEDBACK_FREQUENCY_DURATION_MS);
#endif
        }
        /**
         *
         * Menu actions
         *
         */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        static void menu_action_back
#if defined (A)
        (menuFunc_t data)
#endif
#if defined (B)
        (menuFunc_t func)
#endif
        {
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
            lcd_goto_menu(data);
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            lcd_goto_menu(func);
#endif
        }
        static void menu_action_submenu
#if defined (A)
        (menuFunc_t data)
#endif
#if defined (B)
        (menuFunc_t func)
#endif
        {
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
            lcd_goto_menu(data);
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            lcd_goto_menu(func);
#endif
        }
        static void menu_action_gcode
        (const char* pgcode) {
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
            enquecommand_P(pgcode);
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            enqueuecommands_P(pgcode);
#endif
        }
        static void menu_action_function
#if defined (A)
        (menuFunc_t data)
#endif
#if defined (B)
        (menuFunc_t func)
#endif
        {
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
            (*data)();
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            (*func)();
#endif
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && defined (SDSUPPORT) )
        static void menu_action_sdfile
        (const char* filename, char* longFilename) {
            char cmd[30];
            char* c;
            sprintf_P(cmd, PSTR("M23 %s"), filename);
            for(c = &cmd[4]; *c; c++)
#if defined (A)
                enquecommand(cmd);
#endif
#if defined (B)
            enqueuecommand(cmd);
#endif
#if defined (A)
            enquecommand_P(PSTR("M24"));
#endif
#if defined (B)
            enqueuecommands_P(PSTR("M24"));
#endif
            lcd_return_to_status();
        }
        static void menu_action_sddirectory
        (const char* filename, char* longFilename) {
            card.chdir(filename);
            encoderPosition = 0;
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        static void menu_action_setting_edit_bool
        (const char* pstr, bool* ptr) {
            *ptr = !(*ptr);
        }
        static void menu_action_setting_edit_callback_bool
        (const char* pstr, bool* ptr, menuFunc_t callback) {
            menu_action_setting_edit_bool(pstr, ptr);
            (*callback)();
        }
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
//ULTIPANEL
        /** LCD API **/
        void lcd_init
        () {
            lcd_implementation_init();
#if defined (A) && (defined (NEWPANEL) && defined (ULTRA_LCD) ) || defined (B) && (ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL) )
            SET_INPUT(BTN_EN1);
            SET_INPUT(BTN_EN2);
#endif
#if defined (A)
            WRITE(BTN_EN1,HIGH);
#endif
#if defined (B)
            PULLUP(BTN_EN1,HIGH);
#endif
#if defined (A)
            WRITE(BTN_EN2,HIGH);
#endif
#if defined (B)
            PULLUP(BTN_EN2,HIGH);
#endif
#if defined (A) && (defined (NEWPANEL) && defined (ULTRA_LCD) && BTN_ENC > 0 ) || defined (B) && (BTN_ENC > 0 && ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL) )
            SET_INPUT(BTN_ENC);
#endif
#if defined (A)
            WRITE(BTN_ENC,HIGH);
#endif
#if defined (B)
            PULLUP(BTN_ENC,HIGH);
#endif
#if defined (A) && (defined (NEWPANEL) && defined (ULTRA_LCD) && defined (REPRAPWORLD_KEYPAD) ) || defined (B) && (ENABLED(ULTRA_LCD) && ENABLED(REPRAPWORLD_KEYPAD) && ENABLED(NEWPANEL) )
            pinMode(SHIFT_CLK,OUTPUT);
            pinMode(SHIFT_LD,OUTPUT);
            pinMode(SHIFT_OUT,INPUT);
#endif
#if defined (A)
            WRITE(SHIFT_OUT,HIGH);
#endif
#if defined (B)
            PULLUP(SHIFT_OUT,HIGH);
#endif
#if defined (A)
            WRITE(SHIFT_LD,HIGH);
#endif
#if defined (B)
            PULLUP(SHIFT_LD,HIGH);
#endif
#if defined (A) && (defined (ULTRA_LCD) && !defined (NEWPANEL) ) || defined (B) && (ENABLED(ULTRA_LCD) && !ENABLED(NEWPANEL) )
// Not NEWPANEL
#endif
#if defined (A) && (defined (SR_LCD_2W_NL) && defined (ULTRA_LCD) && !defined (NEWPANEL) ) || defined (B) && (ENABLED(ULTRA_LCD) && ENABLED(SR_LCD_2W_NL) && !ENABLED(NEWPANEL) )
// Non latching 2 wire shift register
            pinMode (SR_DATA_PIN, OUTPUT);
            pinMode (SR_CLK_PIN, OUTPUT);
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined(SHIFT_CLK) && !defined (NEWPANEL) ) || defined (B) && (defined(SHIFT_CLK) && ENABLED(ULTRA_LCD) && !ENABLED(NEWPANEL) )
            pinMode(SHIFT_CLK,OUTPUT);
            pinMode(SHIFT_LD,OUTPUT);
            pinMode(SHIFT_EN,OUTPUT);
            pinMode(SHIFT_OUT,INPUT);
#endif
#if defined (A)
            WRITE(SHIFT_OUT,HIGH);
#endif
#if defined (B)
            PULLUP(SHIFT_OUT,HIGH);
#endif
#if defined (A)
            WRITE(SHIFT_LD,HIGH);
#endif
#if defined (B)
            PULLUP(SHIFT_LD,HIGH);
#endif
#if defined (A)
            WRITE(SHIFT_EN,LOW);
#endif
#if defined (B)
            PULLUP(SHIFT_EN,LOW);
#endif
#if defined (A) && (defined (ULTRA_LCD) && !defined (NEWPANEL) && !defined(SHIFT_CLK) && defined (ULTIPANEL) )
#error ULTIPANEL requires an encoder
#endif
#if defined (A) && (defined (ULTRA_LCD) && !defined (NEWPANEL) ) || defined (B) && (ENABLED(ULTRA_LCD) && !ENABLED(NEWPANEL) )
// SR_LCD_2W_NL
#endif
//!NEWPANEL
#if defined (A) && ((defined (SDSUPPORT) && defined(SDCARDDETECT) && (SDCARDDETECT > 0) && )defined (ULTRA_LCD) ) || defined (B) && ((ENABLED(SDSUPPORT) && defined(SDCARDDETECT) && (SDCARDDETECT > 0) && )ENABLED(ULTRA_LCD) )
            pinMode(SDCARDDETECT,INPUT);
#endif
#if defined (A)
            WRITE(SDCARDDETECT, HIGH);
#endif
#if defined (B)
            PULLUP(SDCARDDETECT, HIGH);
#endif
#if defined (A) && ((defined (SDSUPPORT) && defined(SDCARDDETECT) && (SDCARDDETECT > 0) && )defined (ULTRA_LCD) ) || defined (B) && ((ENABLED(SDSUPPORT) && defined(SDCARDDETECT) && (SDCARDDETECT > 0) && )ENABLED(ULTRA_LCD) )
            lcd_oldcardstatus = IS_SD_INSERTED;
#endif
//(SDCARDDETECT > 0)
#if defined (A) && (defined (ULTRA_LCD) && defined (LCD_HAS_SLOW_BUTTONS) ) || defined (B) && (ENABLED(ULTRA_LCD) && ENABLED(LCD_HAS_SLOW_BUTTONS) )
            slow_buttons = 0;
#endif
            lcd_buttons_update();
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            encoderDiff = 0;
#endif
        }
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
        int lcd_strlen(char *s) {
            int i = 0, j = 0;
            while (s[i]) {
                if ((s[i] & 0xc0) != 0x80) j++;
                i++;
            }
            return j;
        }
        int lcd_strlen_P(const char *s) {
            int j = 0;
            while (pgm_read_byte(s)) {
                if ((pgm_read_byte(s) & 0xc0) != 0x80) j++;
                s++;
            }
            return j;
        }
        /**
         * Update the LCD, read encoder buttons, etc.
         *   - Read button states
         *   - Check the SD Card slot state
         *   - Act on RepRap World keypad input
         *   - Update the encoder position
         *   - Apply acceleration to the encoder position
         *   - Reset the Info Screen timeout if there's any input
         *   - Update status indicators, if any
         *   - Clear the LCD if lcdDrawUpdate == 2
         *
         * Warning: This function is called from interrupt context!
         */
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
        void lcd_update
        () {
#if defined (A)
            static unsigned long timeoutToStatus = 0;
#endif
#if defined (B)
            static millis_t return_to_status_ms = 0;
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (LCD_HAS_SLOW_BUTTONS) ) || defined (B) && (ENABLED(ULTRA_LCD) && ENABLED(LCD_HAS_SLOW_BUTTONS) )
            slow_buttons = lcd_implementation_read_slow_buttons();
// buttons which take too long to read in interrupt context
#endif
            lcd_buttons_update();
#if defined (A)
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
#endif
#if defined (B)
            if (IS_SD_INSERTED != lcd_oldcardstatus && lcd_detected()) {
                lcdDrawUpdate = 2;
                lcd_oldcardstatus = IS_SD_INSERTED;
                lcd_implementation_init( // to maybe revive the LCD if static electricity killed it.
#if ENABLED(LCD_PROGRESS_BAR)
                    currentMenu == lcd_status_screen
#endif
                );
                if (lcd_oldcardstatus) {
                    card.initsd();
                    LCD_MESSAGEPGM(MSG_SD_INSERTED);
                } else {
                    card.release();
                    LCD_MESSAGEPGM(MSG_SD_REMOVED);
                }
            }
#endif
//CARDINSERTED
#if defined (A)
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
#endif
#if defined (B)
            millis_t ms = millis();
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
            if (ms > next_lcd_update_ms) {
#if ENABLED(ULTIPANEL)
#if ENABLED(REPRAPWORLD_KEYPAD)
                if (REPRAPWORLD_KEYPAD_MOVE_Z_UP)     reprapworld_keypad_move_z_up();
                if (REPRAPWORLD_KEYPAD_MOVE_Z_DOWN)   reprapworld_keypad_move_z_down();
                if (REPRAPWORLD_KEYPAD_MOVE_X_LEFT)   reprapworld_keypad_move_x_left();
                if (REPRAPWORLD_KEYPAD_MOVE_X_RIGHT)  reprapworld_keypad_move_x_right();
                if (REPRAPWORLD_KEYPAD_MOVE_Y_DOWN)   reprapworld_keypad_move_y_down();
                if (REPRAPWORLD_KEYPAD_MOVE_Y_UP)     reprapworld_keypad_move_y_up();
                if (REPRAPWORLD_KEYPAD_MOVE_HOME)     reprapworld_keypad_move_home();
#endif
                bool encoderPastThreshold = (abs(encoderDiff) >= ENCODER_PULSES_PER_STEP);
                if (encoderPastThreshold || LCD_CLICKED) {
                    if (encoderPastThreshold) {
                        int32_t encoderMultiplier = 1;
#if ENABLED(ENCODER_RATE_MULTIPLIER)
                        if (encoderRateMultiplierEnabled) {
                            int32_t encoderMovementSteps = abs(encoderDiff) / ENCODER_PULSES_PER_STEP;
                            if (lastEncoderMovementMillis != 0) {
                                // Note that the rate is always calculated between to passes through the
                                // loop and that the abs of the encoderDiff value is tracked.
                                float encoderStepRate = (float)(encoderMovementSteps) / ((float)(ms - lastEncoderMovementMillis)) * 1000.0;
                                if (encoderStepRate >= ENCODER_100X_STEPS_PER_SEC)     encoderMultiplier = 100;
                                else if (encoderStepRate >= ENCODER_10X_STEPS_PER_SEC) encoderMultiplier = 10;
#if ENABLED(ENCODER_RATE_MULTIPLIER_DEBUG)
                                SERIAL_ECHO_START;
                                SERIAL_ECHO("Enc Step Rate: ");
                                SERIAL_ECHO(encoderStepRate);
                                SERIAL_ECHO("  Multiplier: ");
                                SERIAL_ECHO(encoderMultiplier);
                                SERIAL_ECHO("  ENCODER_10X_STEPS_PER_SEC: ");
                                SERIAL_ECHO(ENCODER_10X_STEPS_PER_SEC);
                                SERIAL_ECHO("  ENCODER_100X_STEPS_PER_SEC: ");
                                SERIAL_ECHOLN(ENCODER_100X_STEPS_PER_SEC);
#endif //ENCODER_RATE_MULTIPLIER_DEBUG
                            }
                            lastEncoderMovementMillis = ms;
                        } // encoderRateMultiplierEnabled
#endif //ENCODER_RATE_MULTIPLIER
                        encoderPosition += (encoderDiff * encoderMultiplier) / ENCODER_PULSES_PER_STEP;
                        encoderDiff = 0;
                    }
                    return_to_status_ms = ms + LCD_TIMEOUT_TO_STATUS;
                    lcdDrawUpdate = 1;
                }
#endif //ULTIPANEL
                if (currentMenu == lcd_status_screen) {
                    if (!lcd_status_update_delay) {
                        lcdDrawUpdate = 1;
                        lcd_status_update_delay = 10;   /* redraw the main screen every second. This is easier then trying keep track of all things that change on the screen */
                    } else {
                        lcd_status_update_delay--;
                    }
                }
#if ENABLED(DOGLCD)  // Changes due to different driver architecture of the DOGM display
                if (lcdDrawUpdate) {
                    blink++;     // Variable for fan animation and alive dot
                    u8g.firstPage();
                    do {
                        lcd_setFont(FONT_MENU);
                        u8g.setPrintPos(125, 0);
                        if (blink % 2) u8g.setColorIndex(1);
                        else u8g.setColorIndex(0); // Set color for the alive dot
                        u8g.drawPixel(127, 63); // draw alive dot
                        u8g.setColorIndex(1); // black on white
                        (*currentMenu)();
                    } while( u8g.nextPage() );
                }
#else
                (*currentMenu)();
#endif
#if ENABLED(LCD_HAS_STATUS_INDICATORS)
                lcd_implementation_update_indicators();
#endif
#if ENABLED(ULTIPANEL)
                // Return to Status Screen after a timeout
                if (currentMenu != lcd_status_screen &&
#if ENABLED(MANUAL_BED_LEVELING)
                        currentMenu != _lcd_level_bed &&
                        currentMenu != _lcd_level_bed_homing &&
#endif
                        millis() > return_to_status_ms
                   ) {
                    lcd_return_to_status();
                    lcdDrawUpdate = 2;
                }
#endif // ULTIPANEL
                if (lcdDrawUpdate == 2) lcd_implementation_clear();
                if (lcdDrawUpdate) lcdDrawUpdate--;
                next_lcd_update_ms = ms + LCD_UPDATE_INTERVAL;
            }
#endif
        }
        void lcd_ignore_click
        (bool b) {
            ignore_click = b;
            wait_for_unclick = false;
        }
        void lcd_finishstatus
#if defined (A)
        ()
#endif
#if defined (B)
        (bool persist=false)
#endif
        {
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
#if defined (B) && ((ENABLED(LCD_PROGRESS_BAR) && PROGRESS_MSG_EXPIRE > 0 && )ENABLED(ULTRA_LCD) )
        void dontExpireStatus() {
            expire_status_ms = 0;
        }
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
        void set_utf_strlen(char *s, uint8_t n) {
            uint8_t i = 0, j = 0;
            while (s[i] && (j < n)) {
                if ((s[i] & 0xc0u) != 0x80u) j++;
                i++;
            }
            while (j++ < n) s[i++] = ' ';
            s[i] = 0;
        }
        bool lcd_hasstatus() {
            return (lcd_status_message[0] != '\0');
        }
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
        void lcd_setstatus
#if defined (A)
        (const char* message)
#endif
#if defined (B)
        (const char* message, bool persist)
#endif
        {
            if
            (lcd_status_message_level > 0)
                return;
#if defined (A)
            strncpy(lcd_status_message, message, LCD_WIDTH);
#endif
#if defined (B)
            strncpy(lcd_status_message, message, 3*LCD_WIDTH);
#endif
#if defined (A)
            lcd_finishstatus();
#endif
#if defined (B)
            set_utf_strlen(lcd_status_message, LCD_WIDTH);
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
            lcd_finishstatus(persist);
#endif
        }
        void lcd_setstatuspgm
#if defined (A)
        (const char* message)
#endif
#if defined (B)
        (const char* message, uint8_t level)
#endif
        {
#if defined (A) && defined (ULTRA_LCD)
            if (lcd_status_message_level > 0)
                return;
            strncpy_P(lcd_status_message, message, LCD_WIDTH);
            lcd_finishstatus();
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
            if (level >= lcd_status_message_level) {
                strncpy_P(lcd_status_message, message, 3*LCD_WIDTH);
                set_utf_strlen(lcd_status_message, LCD_WIDTH);
                lcd_status_message_level = level;
                lcd_finishstatus(level > 0);
            }
#endif
        }
        void lcd_setalertstatuspgm
        (const char* message) {
#if defined (A)
            lcd_setstatuspgm(message);
#endif
#if defined (B)
            lcd_setstatuspgm(message, 1);
#endif
#if defined (A) && defined (ULTRA_LCD)
            lcd_status_message_level = 1;
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            lcd_return_to_status();
#endif
#if defined (A) && defined (ULTRA_LCD)
//ULTIPANEL
#endif
        }
        void lcd_reset_alert_level
        () {
            lcd_status_message_level = 0;
        }
#endif
#if defined (A) && (defined (DOGLCD) && defined (ULTRA_LCD) ) || defined (B) && (ENABLED(ULTRA_LCD) && ENABLED(HAS_LCD_CONTRAST) )
        void lcd_setcontrast
        (uint8_t value) {
#if defined (A)
            lcd_contrast = value & 63;
#endif
#if defined (B)
            lcd_contrast = value & 0x3F;
#endif
            u8g.setContrast(lcd_contrast);
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
        /* Warning: This function is called from interrupt context */
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
           * Setup Rotary Encoder Bit Values (for two pin encoders to indicate movement)
           * These values are independent of which pins are used for EN_A and EN_B indications
           * The rotary encoder part is also independent to the chipset used for the LCD
           */
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && (defined(EN_A) && defined(EN_B) &)
#define encrot0 0
#define encrot1 2
#define encrot2 3
#define encrot3 1
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        /**
           * Read encoder buttons from the hardware registers
           * Warning: This function is called from interrupt context!
           */
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        void lcd_buttons_update
        () {
#if defined (A) && (defined (NEWPANEL) && defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL) )
            uint8_t newbutton=0;
            if
            (READ(BTN_EN1)==0)
                newbutton|=EN_A;
            if
            (READ(BTN_EN2)==0)
                newbutton|=EN_B;
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && BTN_ENC > 0 && ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL) )
            millis_t ms = millis();
#endif
#if defined (A) && (defined (NEWPANEL) && defined (ULTRA_LCD) && BTN_ENC > 0 && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && BTN_ENC > 0 && ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL) )
            if
#if defined (A)
            ((blocking_enc<millis()) && (READ(BTN_ENC)==0))
#endif
#if defined (B)
                (ms > next_button_update_ms && READ(BTN_ENC) == 0)
#endif
                newbutton |= EN_C;
#endif
#if defined (B) && (ENABLED(ULTIPANEL) && BTN_ENC > 0 && (defined(BTN_BACK) && BTN_BACK > 0 && )ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL) )
            if (ms > next_button_update_ms && READ(BTN_BACK) == 0) newbutton |= EN_D;
#endif
#if defined (A) && (defined (NEWPANEL) && defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL) )
            buttons = newbutton;
#endif
#if defined (A) && (defined (NEWPANEL) && defined (ULTRA_LCD) && defined (ULTIPANEL) && defined (LCD_HAS_SLOW_BUTTONS) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL) && ENABLED(LCD_HAS_SLOW_BUTTONS) )
            buttons |= slow_buttons;
#endif
#if defined (A) && (defined (NEWPANEL) && defined (ULTRA_LCD) && defined (REPRAPWORLD_KEYPAD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(REPRAPWORLD_KEYPAD) && ENABLED(NEWPANEL) )
// for the reprapworld_keypad
            uint8_t newbutton_reprapworld_keypad=0;
            WRITE(SHIFT_LD,LOW);
            WRITE(SHIFT_LD,HIGH);
#endif
#if defined (A)
            for(int8_t i=0; i<8; i++) {
                newbutton_reprapworld_keypad = newbutton_reprapworld_keypad>>1;
                if(READ(SHIFT_OUT))
                    newbutton_reprapworld_keypad|=(1<<7);
                WRITE(SHIFT_CLK,HIGH);
                WRITE(SHIFT_CLK,LOW);
            }
#endif
#if defined (B)
            for(int8_t i = 0; i < 8; i++) {
                newbutton_reprapworld_keypad >>= 1;
                if (READ(SHIFT_OUT)) newbutton_reprapworld_keypad |= BIT(7);
                WRITE(SHIFT_CLK, HIGH);
                WRITE(SHIFT_CLK, LOW);
            }
#endif
#if defined (A) && (defined (NEWPANEL) && defined (ULTRA_LCD) && defined (REPRAPWORLD_KEYPAD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ENABLED(REPRAPWORLD_KEYPAD) && ENABLED(NEWPANEL) )
            buttons_reprapworld_keypad=~newbutton_reprapworld_keypad;
//invert it, because a pressed switch produces a logical 0
#endif
#if defined (A) && (defined (ULTRA_LCD) && !defined (NEWPANEL) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && !ENABLED(NEWPANEL) )
//read it from the shift register
            uint8_t newbutton=0;
            WRITE(SHIFT_LD,LOW);
            WRITE(SHIFT_LD,HIGH);
            unsigned char tmp_buttons=0;
#endif
#if defined (A)
            for(int8_t i=0; i<8; i++) {
                newbutton = newbutton>>1;
                if(READ(SHIFT_OUT))
                    newbutton|=(1<<7);
                WRITE(SHIFT_CLK,HIGH);
                WRITE(SHIFT_CLK,LOW);
            }
#endif
#if defined (B)
            for(int8_t i=0; i<8; i++) {
                newbutton >>= 1;
                if (READ(SHIFT_OUT)) newbutton |= BIT(7);
                WRITE(SHIFT_CLK, HIGH);
                WRITE(SHIFT_CLK, LOW);
            }
#endif
#if defined (A) && (defined (ULTRA_LCD) && !defined (NEWPANEL) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && !ENABLED(NEWPANEL) )
            buttons=~newbutton;
//invert it, because a pressed switch produces a logical 0
#endif
//!NEWPANEL
//manage encoder rotation
            uint8_t enc=0;
            if
            (buttons & EN_A)
                enc |= B01;
            if
            (buttons & EN_B)
                enc |= B10;
            if
            (enc != lastEncoderBits) {
                switch
                (enc) {
                case
                        encrot0
                        :
                    if
                    (lastEncoderBits==encrot3)
                        encoderDiff++;
                    else if
                    (lastEncoderBits==encrot1)
                        encoderDiff--;
                    break;
                case
                        encrot1
                        :
                    if
                    (lastEncoderBits==encrot0)
                        encoderDiff++;
                    else if
                    (lastEncoderBits==encrot2)
                        encoderDiff--;
                    break;
                case
                        encrot2
                        :
                    if
                    (lastEncoderBits==encrot1)
                        encoderDiff++;
                    else if
                    (lastEncoderBits==encrot3)
                        encoderDiff--;
                    break;
                case
                        encrot3
                        :
                    if
                    (lastEncoderBits==encrot2)
                        encoderDiff++;
                    else if
                    (lastEncoderBits==encrot0)
                        encoderDiff--;
                    break;
                }
            }
            lastEncoderBits = enc;
        }
        bool lcd_detected
        (void) {
#if defined (A) && (defined (ULTRA_LCD) && ((defined(LCD_I2C_TYPE_MCP23017) || defined(LCD_I2C_TYPE_MCP23008)) && defined(DETECT_DEVICE) && )defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) && ((ENABLED(LCD_I2C_TYPE_MCP23017) || ENABLED(LCD_I2C_TYPE_MCP23008)) && ENABLED(DETECT_DEVICE) &)
            return lcd.LcdDetected() == 1;
#endif
#if defined (A) && (defined (ULTRA_LCD) && (!(defined(LCD_I2C_TYPE_MCP23017) || defined(LCD_I2C_TYPE_MCP23008)) && defined(DETECT_DEVICE) && )defined (ULTIPANEL) ) || defined (B) && ((!(ENABLED(LCD_I2C_TYPE_MCP23017) || ENABLED(LCD_I2C_TYPE_MCP23008)) && ENABLED(DETECT_DEVICE) && )ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
            return true;
#endif
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) )
        void lcd_buzz(long duration, uint16_t freq) {
#ifdef LCD_USE_I2C_BUZZER
            lcd.buzz(duration,freq);
#endif
        }
#endif
#if defined (A) && (defined (ULTRA_LCD) && defined (ULTIPANEL) ) || defined (B) && (ENABLED(ULTIPANEL) && ENABLED(ULTRA_LCD) )
        bool lcd_clicked
        () {
            return LCD_CLICKED;
        }
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
//ULTIPANEL
#endif
#if defined (A) && defined (ULTRA_LCD)
        /********************************/
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
        /*********************************/
#endif
#if defined (A) && defined (ULTRA_LCD)
        /** Float conversion utilities **/
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
        /** Number to string conversion **/
#endif
#if defined (A) && defined (ULTRA_LCD)
        /********************************/
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
        /*********************************/
#endif
#if defined (A) && defined (ULTRA_LCD)
//  convert float to string with +123.4 format
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
        char conv[8];
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
// Convert float to string with +123.4 format
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
        char * ftostr3
        (const float &x) {
            return itostr3((int)x);
        }
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
// Convert int to string with 12 format
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
        char * itostr2
        (const uint8_t &x) {
//sprintf(conv,"%5.1f",x);
            int xx=x;
            conv[0]=(xx/10)%10+'0';
#if defined (A)
            conv[1]=(xx)%10+'0';
#endif
#if defined (B)
            conv[1] = xx % 10 + '0';
#endif
            conv[2]=0;
            return conv;
        }
#endif
#if defined (A) && defined (ULTRA_LCD)
// Convert float to string with 123.4 format, dropping sign
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
// Convert float to string with +123.4 format
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
        char * ftostr31
        (const float &x) {
#if defined (A)
            int xx=x*10;
#endif
#if defined (B)
            int xx = abs(x * 10);
#endif
#if defined (A)
            conv[0]=(xx>=0)?'+':'-';
#endif
#if defined (B)
            conv[0] = (x >= 0) ? '+' : '-';
#endif
#if defined (A) && defined (ULTRA_LCD)
            xx=abs(xx);
#endif
            conv[1]=(xx/1000)%10+'0';
            conv[2]=(xx/100)%10+'0';
            conv[3]=(xx/10)%10+'0';
            conv[4]='.';
#if defined (A)
            conv[5]=(xx)%10+'0';
#endif
#if defined (B)
            conv[5] = xx % 10 + '0';
#endif
            conv[6]=0;
            return conv;
        }
#endif
#if defined (A) && defined (ULTRA_LCD)
// Convert float to string with 123.4 format
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
// Convert float to string with 123.4 format, dropping sign
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
        char * ftostr31ns
        (const float &x) {
#if defined (A)
            int xx=x*10;
#endif
#if defined (B)
            int xx = abs(x * 10);
#endif
#if defined (A) && defined (ULTRA_LCD)
//conv[0]=(xx>=0)?'+':'-';
            xx=abs(xx);
#endif
            conv[0]=(xx/1000)%10+'0';
            conv[1]=(xx/100)%10+'0';
            conv[2]=(xx/10)%10+'0';
            conv[3]='.';
#if defined (A)
            conv[4]=(xx)%10+'0';
#endif
#if defined (B)
            conv[4] = xx % 10 + '0';
#endif
            conv[5]=0;
            return conv;
        }
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
// Convert float to string with 123.4 format
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
        char * ftostr32
        (const float &x) {
#if defined (A)
            long xx=x*100;
#endif
#if defined (B)
            long xx = abs(x * 100);
#endif
#if defined (A)
            if (xx >= 0)
                conv[0]=(xx/10000)%10+'0';
            else
                conv[0]='-';
#endif
#if defined (B)
            conv[0] = x >= 0 ? (xx / 10000) % 10 + '0' : '-';
#endif
#if defined (A) && defined (ULTRA_LCD)
            xx=abs(xx);
#endif
            conv[1]=(xx/1000)%10+'0';
            conv[2]=(xx/100)%10+'0';
            conv[3]='.';
            conv[4]=(xx/10)%10+'0';
#if defined (A)
            conv[5]=(xx)%10+'0';
#endif
#if defined (B)
            conv[5] = xx % 10 + '0';
#endif
            conv[6]=0;
            return conv;
        }
// Convert float to string with 1.234 format
        char * ftostr43
        (const float &x) {
            long xx = x * 1000;
            if
            (xx >= 0)
                conv[0] = (xx / 1000) % 10 + '0';
            else
                conv[0] = '-';
            xx = abs(xx);
            conv[1] = '.';
            conv[2] = (xx / 100) % 10 + '0';
            conv[3] = (xx / 10) % 10 + '0';
            conv[4] = (xx) % 10 + '0';
            conv[5] = 0;
            return conv;
        }
#endif
#if defined (A) && defined (ULTRA_LCD)
//Float to string with 1.23 format
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
// Convert float to string with 1.23 format
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
        char * ftostr12ns
        (const float &x) {
            long xx=x*100;
            xx=abs(xx);
            conv[0]=(xx/100)%10+'0';
            conv[1]='.';
            conv[2]=(xx/10)%10+'0';
            conv[3]=(xx)%10+'0';
            conv[4]=0;
            return conv;
        }
#endif
#if defined (A) && defined (ULTRA_LCD)
//  convert float to space-padded string with -_23.4_ format
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
// Convert float to space-padded string with -_23.4_ format
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
        char * ftostr32sp
        (const float &x) {
            long xx = abs(x * 100);
            uint8_t dig;
            if
            (x < 0) {
// negative val = -_0
                conv[0] = '-';
                dig = (xx / 1000) % 10;
                conv[1] = dig ? '0' + dig : ' ';
            } else {
// positive val = __0
                dig = (xx / 10000) % 10;
                if
                (dig) {
                    conv[0] = '0' + dig;
                    conv[1] = '0' + (xx / 1000) % 10;
                } else {
                    conv[0] = ' ';
                    dig = (xx / 1000) % 10;
                    conv[1] = dig ? '0' + dig : ' ';
                }
            }
            conv[2] = '0' + (xx / 100) % 10;
// lsd always
            dig = xx % 10;
            if
            (dig) {
// 2 decimal places
                conv[5] = '0' + dig;
                conv[4] = '0' + (xx / 10) % 10;
                conv[3] = '.';
            } else {
// 1 or 0 decimal place
                dig = (xx / 10) % 10;
                if
                (dig) {
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
#if defined (A)
        char *itostr31(const int &xx) {
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
#if defined (B)
// Convert int to lj string with +123.0 format
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
        char *itostr31(const int &x) {
            conv[0] = x >= 0 ? '+' : '-';
            int xx = abs(x);
            conv[1] = (xx / 100) % 10 + '0';
            conv[2] = (xx / 10) % 10 + '0';
            conv[3] = xx % 10 + '0';
            conv[4] = '.';
            conv[5] = '0';
            conv[6] = 0;
            return conv;
        }
#endif
#if defined (A) && defined (ULTRA_LCD) || defined (B) && ENABLED(ULTRA_LCD)
// Convert int to rj string with 123 or -12 format
        char * itostr3
        (const int &x) {
            int xx = x;
            if
            (xx < 0) {
                conv[0]='-';
                xx = -xx;
            }
#if defined (A)
            else if (xx >= 100)
                conv[0]=(xx/100)%10+'0';
            else
                conv[0]=' ';
#endif
#if defined (B)
            else
                conv[0] = xx >= 100 ? (xx / 100) % 10 + '0' : ' ';
#endif
#if defined (A)
            if (xx >= 10)
                conv[1]=(xx/10)%10+'0';
            else
                conv[1]=' ';
#endif
#if defined (B)
            conv[1] = xx >= 10 ? (xx / 10) % 10 + '0' : ' ';
#endif
#if defined (A)
            conv[2]=(xx)%10+'0';
#endif
#if defined (B)
            conv[2] = xx % 10 + '0';
#endif
            conv[3]=0;
            return conv;
        }
// Convert int to lj string with 123 format
        char * itostr3left
        (const int &xx) {
            if
            (xx >= 100) {
                conv[0]=(xx/100)%10+'0';
                conv[1]=(xx/10)%10+'0';
#if defined (A)
                conv[2]=(xx)%10+'0';
#endif
#if defined (B)
                conv[2] = xx % 10 + '0';
#endif
                conv[3]=0;
            } else if
            (xx >= 10) {
                conv[0]=(xx/10)%10+'0';
#if defined (A)
                conv[1]=(xx)%10+'0';
#endif
#if defined (B)
                conv[1] = xx % 10 + '0';
#endif
                conv[2]=0;
            } else {
#if defined (A)
                conv[0]=(xx)%10+'0';
#endif
#if defined (B)
                conv[0] = xx % 10 + '0';
#endif
                conv[1]=0;
            }
            return conv;
        }
// Convert int to rj string with 1234 format
        char * itostr4
        (const int &xx) {
            conv[0] = xx >= 1000 ? (xx / 1000) % 10 + '0' : ' ';
            conv[1] = xx >= 100 ? (xx / 100) % 10 + '0' : ' ';
            conv[2] = xx >= 10 ? (xx / 10) % 10 + '0' : ' ';
            conv[3] = xx % 10 + '0';
            conv[4] = 0;
            return conv;
        }
// Convert float to rj string with 12345 format
        char * ftostr5
        (const float &x) {
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
        char * ftostr51
        (const float &x) {
#if defined (A)
            long xx=x*10;
#endif
#if defined (B)
            long xx = abs(x * 10);
#endif
#if defined (A)
            conv[0]=(xx>=0)?'+':'-';
#endif
#if defined (B)
            conv[0] = (x >= 0) ? '+' : '-';
#endif
#if defined (A) && defined (ULTRA_LCD)
            xx=abs(xx);
#endif
            conv[1]=(xx/10000)%10+'0';
            conv[2]=(xx/1000)%10+'0';
            conv[3]=(xx/100)%10+'0';
            conv[4]=(xx/10)%10+'0';
            conv[5]='.';
#if defined (A)
            conv[6]=(xx)%10+'0';
#endif
#if defined (B)
            conv[6] = xx % 10 + '0';
#endif
            conv[7]=0;
            return conv;
        }
// Convert float to string with +123.45 format
        char * ftostr52
        (const float &x) {
#if defined (A)
            long xx=x*100;
#endif
#if defined (B)
            conv[0] = (x >= 0) ? '+' : '-';
#endif
#if defined (A)
            conv[0]=(xx>=0)?'+':'-';
#endif
#if defined (B)
            long xx = abs(x * 100);
#endif
#if defined (A) && defined (ULTRA_LCD)
            xx=abs(xx);
#endif
            conv[1]=(xx/10000)%10+'0';
            conv[2]=(xx/1000)%10+'0';
            conv[3]=(xx/100)%10+'0';
            conv[4]='.';
            conv[5]=(xx/10)%10+'0';
#if defined (A)
            conv[6]=(xx)%10+'0';
#endif
#if defined (B)
            conv[6] = xx % 10 + '0';
#endif
            conv[7]=0;
            return conv;
        }
#endif
#if defined (A) && defined (ULTRA_LCD)
// Callback for after editing PID i value
#endif
#if defined (B) && (ENABLED(ULTRA_LCD) && ENABLED(MANUAL_BED_LEVELING) )
        static int _lcd_level_bed_position;
#endif
#if defined (A) && defined (ULTRA_LCD)
// grab the PID i value out of the temp variable; scale it; then update the PID driver
#endif
#if defined (B) && (ENABLED(ULTRA_LCD) && ENABLED(MANUAL_BED_LEVELING) )
        /**
           * MBL Wait for controller movement and clicks:
           *   - Movement adjusts the Z axis
           *   - Click saves the Z and goes to the next mesh point
           */
#endif
#if defined (A)
        void copy_and_scalePID_i() {
#ifdef PIDTEMP
            Ki = scalePID_i(raw_Ki);
            updatePID();
#endif
        }
#endif
#if defined (B)
        static void _lcd_level_bed() {
            if (encoderPosition != 0) {
                refresh_cmd_timeout();
                current_position[Z_AXIS] += float((int)encoderPosition) * MBL_Z_STEP;
                if (min_software_endstops && current_position[Z_AXIS] < Z_MIN_POS) current_position[Z_AXIS] = Z_MIN_POS;
                if (max_software_endstops && current_position[Z_AXIS] > Z_MAX_POS) current_position[Z_AXIS] = Z_MAX_POS;
                encoderPosition = 0;
                line_to_current(Z_AXIS);
                lcdDrawUpdate = 2;
            }
            if (lcdDrawUpdate) lcd_implementation_drawedit(PSTR("Z"), ftostr43(current_position[Z_AXIS]));
            static bool debounce_click = false;
            if (LCD_CLICKED) {
                if (!debounce_click) {
                    debounce_click = true;
                    int ix = _lcd_level_bed_position % MESH_NUM_X_POINTS,
                        iy = _lcd_level_bed_position / MESH_NUM_X_POINTS;
                    if (iy & 1) ix = (MESH_NUM_X_POINTS - 1) - ix; // Zig zag
                    mbl.set_z(ix, iy, current_position[Z_AXIS]);
                    _lcd_level_bed_position++;
                    if (_lcd_level_bed_position == MESH_NUM_X_POINTS*MESH_NUM_Y_POINTS) {
                        current_position[Z_AXIS] = MESH_HOME_SEARCH_Z;
                        line_to_current(Z_AXIS);
                        mbl.active = 1;
                        enqueuecommands_P(PSTR("G28"));
                        lcd_return_to_status();
                    } else {
                        current_position[Z_AXIS] = MESH_HOME_SEARCH_Z;
                        line_to_current(Z_AXIS);
                        ix = _lcd_level_bed_position % MESH_NUM_X_POINTS;
                        iy = _lcd_level_bed_position / MESH_NUM_X_POINTS;
                        if (iy & 1) ix = (MESH_NUM_X_POINTS - 1) - ix; // Zig zag
                        current_position[X_AXIS] = mbl.get_x(ix);
                        current_position[Y_AXIS] = mbl.get_y(iy);
                        line_to_current(manual_feedrate[X_AXIS] <= manual_feedrate[Y_AXIS] ? X_AXIS : Y_AXIS);
                        lcdDrawUpdate = 2;
                    }
                }
            } else {
                debounce_click = false;
            }
        }
#endif
#if defined (A) && defined (ULTRA_LCD)
// Callback for after editing PID d value
#endif
#if defined (B) && (ENABLED(ULTRA_LCD) && ENABLED(MANUAL_BED_LEVELING) )
        /**
           * MBL Move to mesh starting point
           */
#endif
#if defined (A) && defined (ULTRA_LCD)
// grab the PID d value out of the temp variable; scale it; then update the PID driver
#endif
#if defined (B) && (ENABLED(ULTRA_LCD) && ENABLED(MANUAL_BED_LEVELING) )
        static void _lcd_level_bed_homing() {
            if (lcdDrawUpdate) lcd_implementation_drawedit(PSTR("XYZ"), "Homing");
            if (axis_known_position[X_AXIS] && axis_known_position[Y_AXIS] && axis_known_position[Z_AXIS]) {
                current_position[Z_AXIS] = MESH_HOME_SEARCH_Z;
                plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
                current_position[X_AXIS] = MESH_MIN_X;
                current_position[Y_AXIS] = MESH_MIN_Y;
                line_to_current(manual_feedrate[X_AXIS] <= manual_feedrate[Y_AXIS] ? X_AXIS : Y_AXIS);
                _lcd_level_bed_position = 0;
                lcd_goto_menu(_lcd_level_bed);
            }
            lcdDrawUpdate = 2;
        }
#endif
#if defined (B) && (ENABLED(ULTRA_LCD) && ENABLED(MANUAL_BED_LEVELING) )
        static void _lcd_level_bed_homing() {
            if (lcdDrawUpdate) lcd_implementation_drawedit(PSTR("XYZ"), "Homing");
            if (axis_known_position[X_AXIS] && axis_known_position[Y_AXIS] && axis_known_position[Z_AXIS]) {
                current_position[Z_AXIS] = MESH_HOME_SEARCH_Z;
                plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
                current_position[X_AXIS] = MESH_MIN_X;
                current_position[Y_AXIS] = MESH_MIN_Y;
                line_to_current(manual_feedrate[X_AXIS] <= manual_feedrate[Y_AXIS] ? X_AXIS : Y_AXIS);
                _lcd_level_bed_position = 0;
                lcd_goto_menu(_lcd_level_bed);
            }
            lcdDrawUpdate = 2;
        }
#endif
#if defined (A)
        void copy_and_scalePID_d() {
#ifdef PIDTEMP
            Kd = scalePID_d(raw_Kd);
            updatePID();
#endif
        }
#endif
#if defined (B)
        /**
           * MBL entry-point
           */
#endif
#if defined (B) && (ENABLED(ULTRA_LCD) && ENABLED(MANUAL_BED_LEVELING) )
        static void lcd_level_bed() {
            axis_known_position[X_AXIS] = axis_known_position[Y_AXIS] = axis_known_position[Z_AXIS] = false;
            mbl.reset();
            enqueuecommands_P(PSTR("G28"));
            lcdDrawUpdate = 2;
            lcd_goto_menu(_lcd_level_bed_homing);
        }
#endif
#if defined (B) && ENABLED(ULTRA_LCD)
// MANUAL_BED_LEVELING
#endif
#if defined (A) || defined (B)
//ULTRA_LCD
#endif
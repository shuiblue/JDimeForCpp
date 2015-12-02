#if defined (upstream) && !defined (CONFIGURATION_H) || defined (jcrocholl) && !defined (CONFIGURATION_H) || defined (jcrochollUpstream) && !defined (CONFIGURATION_H)
    #define CONFIGURATION_H
#endif
#if defined (upstream) && !defined (CONFIGURATION_H) || defined (jcrocholl) && !defined (CONFIGURATION_H)

    #define STRING_CONFIG_H_AUTHOR "(jcrocholl, deltabot)"
#endif
#if defined (jcrochollUpstream) && !defined (CONFIGURATION_H)
    #define STRING_CONFIG_H_AUTHOR "(none, default config)"
#endif
#if defined (upstream) && !defined (CONFIGURATION_H) || defined (jcrocholl) && !defined (CONFIGURATION_H) || defined (jcrochollUpstream) && !defined (CONFIGURATION_H)
    //Who made the changes.
#endif
#if defined (upstream) && (!defined (CONFIGURATION_H) && !defined (MOTHERBOARD) ) || defined (jcrocholl) && (!defined (CONFIGURATION_H) && !defined (MOTHERBOARD) )

    #define MOTHERBOARD 33
#endif
#if defined (jcrochollUpstream) && (!defined (CONFIGURATION_H) && !defined (MOTHERBOARD) )
    #define MOTHERBOARD 7
#endif
#if defined (upstream) && !defined (CONFIGURATION_H) || defined (jcrocholl) && !defined (CONFIGURATION_H)

    //===========================================================================

    //============================== Delta Settings =============================

    //===========================================================================

    #define DELTA_SEGMENTS_PER_SECOND 200

    #define COS_60 0.5

    #define DELTA_TOWER1_X -SIN_60*DELTA_RADIUS
#endif
#if defined (upstream) && !defined (CONFIGURATION_H) || defined (jcrocholl) && !defined (CONFIGURATION_H) || defined (jcrochollUpstream) && !defined (CONFIGURATION_H)
    //===========================================================================
    //=============================Thermal Settings  ============================
    //===========================================================================
#endif
#if defined (upstream) && !defined (CONFIGURATION_H) || defined (jcrocholl) && !defined (CONFIGURATION_H)

    #define TEMP_SENSOR_0 1
#endif
#if defined (jcrochollUpstream) && !defined (CONFIGURATION_H)
    #define TEMP_SENSOR_0 -1
#endif
#if defined (upstream) && !defined (CONFIGURATION_H) || defined (jcrocholl) && !defined (CONFIGURATION_H) || defined (jcrochollUpstream) && !defined (CONFIGURATION_H)
    // PID settings:
    // Comment the following line to disable PID and enable bang-bang.
    #define PIDTEMP
    #define PID_MAX 255
    // limits current to nozzle; 255=full current
    //===========================================================================
    //=============================Mechanical Settings===========================
    //===========================================================================
    // The pullups are needed if you directly connect a mechanical endswitch between the signal and ground pins.
#endif
#if defined (upstream) && !defined (CONFIGURATION_H) || defined (jcrocholl) && !defined (CONFIGURATION_H)

    const bool X_ENDSTOPS_INVERTING = false;
#endif
#if defined (jcrochollUpstream) && !defined (CONFIGURATION_H)
    const bool X_ENDSTOPS_INVERTING = true;
#endif
#if defined (upstream) && !defined (CONFIGURATION_H) || defined (jcrocholl) && !defined (CONFIGURATION_H) || defined (jcrochollUpstream) && !defined (CONFIGURATION_H)
    // set to true to invert the logic of the endstops.
    //#define DISABLE_MAX_ENDS
    //automatic expansion
#endif
#if defined (upstream) && (!defined (CONFIGURATION_H) && (defined(ULTIMAKERCONTROLLER) || defined(REPRAP_DISCOUNT_SMART_CONTROLLER) &) || defined (jcrocholl) && (!defined (CONFIGURATION_H) && (defined(ULTIMAKERCONTROLLER) || defined(REPRAP_DISCOUNT_SMART_CONTROLLER) &) || defined (jcrochollUpstream) && (!defined (CONFIGURATION_H) && (defined(ULTIMAKERCONTROLLER) || defined(REPRAP_DISCOUNT_SMART_CONTROLLER) &)
    #define ULTIPANEL
    #define NEWPANEL
#endif
#if defined (upstream) && !defined (CONFIGURATION_H) || defined (jcrocholl) && !defined (CONFIGURATION_H) || defined (jcrochollUpstream) && !defined (CONFIGURATION_H)
    // Preheat Constants
    #define PLA_PREHEAT_HOTEND_TEMP 180
    #define PLA_PREHEAT_HPB_TEMP 70
    #define PLA_PREHEAT_FAN_SPEED 255
    // Insert Value between 0 and 255
    #define ABS_PREHEAT_HOTEND_TEMP 240
    #define ABS_PREHEAT_HPB_TEMP 100
    #define ABS_PREHEAT_FAN_SPEED 255
    // Insert Value between 0 and 255
#endif
#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)
    //__CONFIGURATION_H
#endif

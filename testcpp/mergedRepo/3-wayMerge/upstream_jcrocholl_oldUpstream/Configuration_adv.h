#if defined (upstream) && !defined (CONFIGURATION_ADV_H) || defined (jcrocholl) && !defined (CONFIGURATION_ADV_H) || defined (jcrochollUpstream) && !defined (CONFIGURATION_ADV_H)
    #define CONFIGURATION_ADV_H
#endif
#if defined (upstream) && (defined (MANUAL_HOME_POSITIONS) && !defined (CONFIGURATION_ADV_H) ) || defined (jcrocholl) && (defined (MANUAL_HOME_POSITIONS) && !defined (CONFIGURATION_ADV_H) ) || defined (jcrochollUpstream) && (!defined (CONFIGURATION_ADV_H) && defined (MANUAL_HOME_POSITION) )
    //Use manual limit switch locations
    #define X_HOME_POS MANUAL_X_HOME_POS
#endif
#if defined (upstream) && !defined (CONFIGURATION_ADV_H) || defined (jcrocholl) && !defined (CONFIGURATION_ADV_H)

    #define Z_HOME_RETRACT_MM 5
#endif
#if defined (jcrochollUpstream) && !defined (CONFIGURATION_ADV_H)
    #define Z_HOME_RETRACT_MM 1
#endif
#if defined (upstream) && !defined (CONFIGURATION_ADV_H) || defined (jcrocholl) && !defined (CONFIGURATION_ADV_H)

    //#define SLOWDOWN
#endif
#if defined (jcrochollUpstream) && !defined (CONFIGURATION_ADV_H)
    #define SLOWDOWN
#endif
#if defined (upstream) && !defined (CONFIGURATION_ADV_H) || defined (jcrocholl) && !defined (CONFIGURATION_ADV_H) || defined (jcrochollUpstream) && !defined (CONFIGURATION_ADV_H)
    //===========================================================================
    //=============================  Define Defines  ============================
    //===========================================================================
#endif
#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)
    //__CONFIGURATION_ADV_H
#endif
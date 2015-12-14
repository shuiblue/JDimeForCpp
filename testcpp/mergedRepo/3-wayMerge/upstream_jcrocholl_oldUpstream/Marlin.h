#if defined (upstream) && !defined (MARLIN_H) || defined (jcrocholl) && !defined (MARLIN_H) || defined (jcrochollUpstream) && !defined (MARLIN_H)
    #define MARLIN_H
#endif
#if defined (upstream) && (defined(__AVR_ATmega644P__) && ARDUINO >= 100 && !defined (MARLIN_H) ) || defined (jcrocholl) && (defined(__AVR_ATmega644P__) && ARDUINO >= 100 && !defined (MARLIN_H) ) || defined (jcrochollUpstream) && (defined(__AVR_ATmega644P__) && ARDUINO >= 100 && !defined (MARLIN_H) )
    #include "WProgram.h"
#endif
#if defined (upstream) && (ARDUINO >= 100 && !defined(__AVR_ATmega644P__) && !defined (MARLIN_H) ) || defined (jcrocholl) && (ARDUINO >= 100 && !defined(__AVR_ATmega644P__) && !defined (MARLIN_H) ) || defined (jcrochollUpstream) && (ARDUINO >= 100 && !defined(__AVR_ATmega644P__) && !defined (MARLIN_H) )
    #include "Arduino.h"
#endif
#if defined (upstream) && (!defined (MARLIN_H) && !ARDUINO >= 100 ) || defined (jcrocholl) && (!defined (MARLIN_H) && !ARDUINO >= 100 ) || defined (jcrochollUpstream) && (!defined (MARLIN_H) && !ARDUINO >= 100 )
    #include "WProgram.h"
#endif
#if defined (upstream) && !defined (MARLIN_H) || defined (jcrocholl) && !defined (MARLIN_H) || defined (jcrochollUpstream) && !defined (MARLIN_H)
    void manage_inactivity();
#endif
#if defined (upstream) && !defined (MARLIN_H) || defined (jcrocholl) && !defined (MARLIN_H)

    void calculate_delta(float cartesian[3]);
#endif
#if defined (upstream) && !defined (MARLIN_H) || defined (jcrocholl) && !defined (MARLIN_H) || defined (jcrochollUpstream) && !defined (MARLIN_H)
    extern bool feedmultiplychanged;
#endif
#if defined (upstream) && (!defined (MARLIN_H) && defined (FWRETRACT) ) || defined (jcrocholl) && (!defined (MARLIN_H) && defined (FWRETRACT) ) || defined (jcrochollUpstream) && (!defined (MARLIN_H) && defined (FWRETRACT) )
    extern bool retracted;
#endif
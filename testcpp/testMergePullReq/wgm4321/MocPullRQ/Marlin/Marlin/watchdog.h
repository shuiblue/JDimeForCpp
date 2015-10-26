#if defined (upstreamBeforeMerge) && !defined (WATCHDOG_H) || defined (forkBeforeMerge) && !defined (WATCHDOG_H)
    #define WATCHDOG_H
    #include "Marlin.h"
#endif
#if defined (upstreamBeforeMerge) && (defined (USE_WATCHDOG) && !defined (WATCHDOG_H) ) || defined (forkBeforeMerge) && (defined (USE_WATCHDOG) && !defined (WATCHDOG_H) )
    // initialize watch dog with a 1 sec interrupt time
    void watchdog_init();
    // pad the dog/reset watchdog. MUST be called at least every second after the first watchdog_init or AVR will go into emergency procedures..
    void watchdog_reset();
#endif
#if defined (upstreamBeforeMerge) && (!defined (USE_WATCHDOG) && !defined (WATCHDOG_H) ) || defined (forkBeforeMerge) && (!defined (USE_WATCHDOG) && !defined (WATCHDOG_H) )
//If we do not have a watchdog, then we can have empty functions which are optimized away.
FORCE_INLINE void watchdog_init
() {
}
;
FORCE_INLINE void watchdog_reset
() {
}
;
#endif

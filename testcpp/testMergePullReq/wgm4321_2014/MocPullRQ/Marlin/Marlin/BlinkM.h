#if defined (upstreamBeforeMerge) || defined (forkBeforeMerge)
/*
  BlinkM.h
  Library header file for BlinkM library
 */
#endif
#if defined (upstreamBeforeMerge) && (ARDUINO >= 100) || defined (forkBeforeMerge) && (ARDUINO >= 100)
    #include "Arduino.h"
#endif
#if defined (upstreamBeforeMerge) && !(ARDUINO >= 100) || defined (forkBeforeMerge) && !(ARDUINO >= 100)
    #include "WProgram.h"
#endif
#if defined (upstreamBeforeMerge) || defined (forkBeforeMerge)
    #include "Wire.h"
    void SendColors(byte red, byte grn, byte blu);
#endif

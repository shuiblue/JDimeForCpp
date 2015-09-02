#if defined (B)
/*
  blinkm.cpp - Library for controlling a BlinkM over i2c
  Created by Tim Koster, August 21 2013.
*/
#endif
#if defined (A) || defined (C)
    /*
    BlinkM.cpp - Library for controlling a BlinkM over i2c
    Created by Tim Koster, August 21 2013.
    */
#endif
#if defined (A) || defined (B) || defined (C)
    #include "Marlin.h"
#endif
#if defined (C) && ((ARDUINO >= 100) && defined (BLINKM) )
    #include "Arduino.h"
#endif
#if defined (B) && defined (BLINKM)
    #include "blinkm.h"
#endif
#if defined (A) && defined (BLINKM) || defined (C) && defined (BLINKM)
    #include "BlinkM.h"
#endif
#if defined (A) && defined (BLINKM) || defined (B) && defined (BLINKM) || defined (C) && defined (BLINKM)
void SendColors
(byte red, byte grn, byte blu) {
#if defined (B) && defined (BLINKM) || defined (C) && defined (BLINKM)
    Wire.begin();
#endif
#if defined (A) && defined (BLINKM) || defined (B) && defined (BLINKM)
    Wire.beginTransmission(0x09);
#endif
}
#endif
#if defined (A) || defined (B) || defined (C)
    //BLINKM
#endif

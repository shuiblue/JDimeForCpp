#if defined (A) || defined (B)
/*
  BlinkM.cpp - Library for controlling a BlinkM over i2c
  Created by Tim Koster, August 21 2013.
*/
#endif
#if defined (C)
    /*
    blinkm.cpp - Library for controlling a BlinkM over i2c
    Created by Tim Koster, August 21 2013.
    */
#endif
#if defined (A) || defined (B) || defined (C)
    #include "Marlin.h"
#endif
#if defined (A) && ((ARDUINO >= 100) && defined (BLINKM) ) || defined (B) && ((ARDUINO >= 100) && defined (BLINKM) )
    #include "Arduino.h"
#endif
#if defined (C) && defined (BLINKM)
    #include "blinkm.h"
#endif
#if defined (A) && (!(ARDUINO >= 100) && defined (BLINKM) ) || defined (B) && (!(ARDUINO >= 100) && defined (BLINKM) )
    #include "WProgram.h"
#endif
#if defined (A) && defined (BLINKM) || defined (B) && defined (BLINKM)
    #include "BlinkM.h"
#endif
#if defined (A) && defined (BLINKM) || defined (B) && defined (BLINKM) || defined (C) && defined (BLINKM)
void SendColors
(byte red, byte grn, byte blu) {
    Wire.begin();
    Wire.beginTransmission(0x09);
    Wire.write('o');
//to disable ongoing script, only needs to be used once
    Wire.write('n');
    Wire.write(red);
    Wire.write(grn);
    Wire.write(blu);
    Wire.endTransmission();
}
#endif
#if defined (A) || defined (B) || defined (C)
    //BLINKM
#endif

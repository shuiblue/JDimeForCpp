#if defined (upstream)
/*
  BlinkM.cpp - Library for controlling a BlinkM over i2c
  Created by Tim Koster, August 21 2013.
*/
#endif
#if defined (marlin4Due)
    /*
    blinkm.cpp - Library for controlling a BlinkM over i2c
    Created by Tim Koster, August 21 2013.
    */
#endif
#if defined (upstream) || defined (marlin4Due)
    #include "Marlin.h"
#endif
#if defined (upstream) && ((ARDUINO >= 100) && defined (BLINKM) )
    #include "Arduino.h"
#endif
#if defined (marlin4Due) && defined (BLINKM)
    #include "blinkm.h"
#endif
#if defined (upstream) && (!(ARDUINO >= 100) && defined (BLINKM) )
    #include "WProgram.h"
#endif
#if defined (upstream) && defined (BLINKM)
    #include "BlinkM.h"
#endif
#if defined (upstream) && defined (BLINKM) || defined (marlin4Due) && defined (BLINKM)
void SendColors
(byte red, byte grn, byte blu) {
    Wire.begin();
    Wire.beginTransmission(0x09);
    Wire.write('o');
//to disable ongoing script, only needs to be used once
    Wire.write('n');
    Wire.write(red);
#if defined (upstream) && defined (BLINKM)
    Wire.write(grn);
#endif
#if defined (marlin4Due) && defined (BLINKM)
// Wire.write(grn);
#endif
    Wire.write(blu);
    Wire.endTransmission();
}
#endif
#if defined (upstream) || defined (marlin4Due)
    //BLINKM
#endif
#if defined (upstream) || defined (ut7)
/*
  BlinkM.cpp - Library for controlling a BlinkM over i2c
  Created by Tim Koster, August 21 2013.
*/
#include "Marlin.h"
#endif
#if defined (upstream) && ((ARDUINO >= 100) && defined (BLINKM) ) || defined (ut7) && ((ARDUINO >= 100) && defined (BLINKM) )
    #include "Arduino.h"
#endif
#if defined (upstream) && (!(ARDUINO >= 100) && defined (BLINKM) ) || defined (ut7) && (!(ARDUINO >= 100) && defined (BLINKM) )
    #include "WProgram.h"
#endif
#if defined (upstream) && defined (BLINKM) || defined (ut7) && defined (BLINKM)
#include "BlinkM.h"
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
#if defined (upstream) || defined (ut7)
    //BLINKM
#endif
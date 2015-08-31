#if defined (upstream) || defined (bobc) || defined (mattsch) || defined (quikshot) || defined (ErikZalm) || defined (Ognog) || defined (alromh87) || defined (hampussandberg) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
/*
  BlinkM.cpp - Library for controlling a BlinkM over i2c
  Created by Tim Koster, August 21 2013.
*/
#include "Marlin.h"
#endif
#if defined (upstream) && ((ARDUINO >= 100) && defined (BLINKM) ) || defined (bobc) && ((ARDUINO >= 100) && defined (BLINKM) ) || defined (mattsch) && ((ARDUINO >= 100) && defined (BLINKM) ) || defined (quikshot) && ((ARDUINO >= 100) && defined (BLINKM) ) || defined (ErikZalm) && ((ARDUINO >= 100) && defined (BLINKM) ) || defined (Ognog) && ((ARDUINO >= 100) && defined (BLINKM) ) || defined (alromh87) && ((ARDUINO >= 100) && defined (BLINKM) ) || defined (hampussandberg) && ((ARDUINO >= 100) && defined (BLINKM) ) || defined (oysteinkrog) && ((ARDUINO >= 100) && defined (BLINKM) ) || defined (johnnyr) && ((ARDUINO >= 100) && defined (BLINKM) ) || defined (yuroller) && ((ARDUINO >= 100) && defined (BLINKM) ) || defined (ut7) && ((ARDUINO >= 100) && defined (BLINKM) )
    #include "Arduino.h"
#endif
#if defined (upstream) && (!(ARDUINO >= 100) && defined (BLINKM) ) || defined (bobc) && (!(ARDUINO >= 100) && defined (BLINKM) ) || defined (mattsch) && (!(ARDUINO >= 100) && defined (BLINKM) ) || defined (quikshot) && (!(ARDUINO >= 100) && defined (BLINKM) ) || defined (ErikZalm) && (!(ARDUINO >= 100) && defined (BLINKM) ) || defined (Ognog) && (!(ARDUINO >= 100) && defined (BLINKM) ) || defined (alromh87) && (!(ARDUINO >= 100) && defined (BLINKM) ) || defined (hampussandberg) && (!(ARDUINO >= 100) && defined (BLINKM) ) || defined (oysteinkrog) && (!(ARDUINO >= 100) && defined (BLINKM) ) || defined (johnnyr) && (!(ARDUINO >= 100) && defined (BLINKM) ) || defined (yuroller) && (!(ARDUINO >= 100) && defined (BLINKM) ) || defined (ut7) && (!(ARDUINO >= 100) && defined (BLINKM) )
    #include "WProgram.h"
#endif
#if defined (upstream) && defined (BLINKM) || defined (bobc) && defined (BLINKM) || defined (mattsch) && defined (BLINKM) || defined (quikshot) && defined (BLINKM) || defined (ErikZalm) && defined (BLINKM) || defined (Ognog) && defined (BLINKM) || defined (alromh87) && defined (BLINKM) || defined (hampussandberg) && defined (BLINKM) || defined (oysteinkrog) && defined (BLINKM) || defined (johnnyr) && defined (BLINKM) || defined (yuroller) && defined (BLINKM) || defined (ut7) && defined (BLINKM)
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
#if defined (upstream) || defined (bobc) || defined (mattsch) || defined (quikshot) || defined (ErikZalm) || defined (Ognog) || defined (alromh87) || defined (hampussandberg) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
    //BLINKM
#endif

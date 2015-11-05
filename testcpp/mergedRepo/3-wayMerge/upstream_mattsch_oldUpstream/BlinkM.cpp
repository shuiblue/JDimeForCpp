#if defined (upstream)
/*
  blinkm.cpp - Library for controlling a BlinkM over i2c
  Created by Tim Koster, August 21 2013.
*/
#endif
#if defined (mattsch) || defined (mattschUpstream)

    /*
    BlinkM.cpp - Library for controlling a BlinkM over i2c
    Created by Tim Koster, August 21 2013.
    */
#endif
#if defined (upstream) || defined (mattsch) || defined (mattschUpstream)
    #include "Marlin.h"
#endif
#if defined (upstream) && ENABLED(BLINKM)
    #include "blinkm.h"
#endif
#if defined (mattsch) && ((ARDUINO >= 100) && defined (BLINKM) ) || defined (mattschUpstream) && ((ARDUINO >= 100) && defined (BLINKM) )

    #include "Arduino.h"
#endif
#if defined (mattsch) && (!(ARDUINO >= 100) && defined (BLINKM) ) || defined (mattschUpstream) && (!(ARDUINO >= 100) && defined (BLINKM) )

    #include "WProgram.h"
#endif
#if defined (mattsch) && defined (BLINKM) || defined (mattschUpstream) && defined (BLINKM)

    #include "BlinkM.h"
#endif
#if defined (upstream) && ENABLED(BLINKM) || defined (mattsch) && defined (BLINKM) || defined (mattschUpstream) && defined (BLINKM)
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
#if defined (upstream) || defined (mattsch) || defined (mattschUpstream)
    //BLINKM
#endif

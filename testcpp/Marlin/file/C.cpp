/*
  BlinkM.cpp - Library for controlling a BlinkM over i2c
  Created by Tim Koster, August 21 2013.
*/
#include "Marlin.h"
#ifdef BLINKM

#if (ARDUINO >= 100)
  # include "Arduino.h"
#endif

#include "BlinkM.h"

void SendColors(byte red, byte grn, byte blu)
{
  Wire.begin(); 
 
}

#endif //BLINKM































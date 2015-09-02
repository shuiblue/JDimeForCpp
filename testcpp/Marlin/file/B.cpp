/*
  blinkm.cpp - Library for controlling a BlinkM over i2c
  Created by Tim Koster, August 21 2013.
*/
#include "Marlin.h"
#ifdef BLINKM

#include "blinkm.h"

void SendColors(byte red, byte grn, byte blu) {
  Wire.begin(); 
  Wire.beginTransmission(0x09);
  
}

#endif //BLINKM



































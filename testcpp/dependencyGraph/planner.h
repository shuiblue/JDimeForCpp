#if defined(__AVR_ATmega1280__)\
|| defined(__AVR_ATmega2560__)

uint8_t const SCK_PIN = 52;  

static const pin_map_t digitalPinMap[] = {
  
};
//------------------------------------------------------------------------------
#elif defined(__AVR_ATmega644P__)\
|| defined(__AVR_ATmega644__)\
|| defined(__AVR_ATmega1284P__)

uint8_t const SCK_PIN = 7;   // B7

static const pin_map_t digitalPinMap[] = {
  
};

#elif defined(__AVR_ATmega32U4__)

uint8_t const SCK_PIN = 1;   // B1

static const pin_map_t digitalPinMap[] = {
 
};
#elif defined(__AVR_AT90USB646__)\
|| defined(__AVR_AT90USB1286__)

uint8_t const SCK_PIN = 21;   // B1

#elif defined(__AVR_ATmega168__)\
||defined(__AVR_ATmega168P__)\
||defined(__AVR_ATmega328P__)

uint8_t const SCK_PIN = 13;   

static const pin_map_t digitalPinMap[] = {
 
  {&DDRC, &PINC, &PORTC, 5}   
};
#else  
#error unknown chip
#endif  
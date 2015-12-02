#ifndef MARLINFIRMWARE_H
#define MARLINFIRMWARE_H

#define AS_QUOTED_STRING(S)           #S
#define INCLUDE_BY_CLASS_AND_ID(C,I)  AS_QUOTED_STRING(configurations/C/I/Customization.h)
#define INCLUDE_BY_PATH(P)            AS_QUOTED_STRING(P)

#include "FirmwareCustomization.h"

#ifndef CONFIGURATION_H
  #ifdef CONFIGURATION_FILE
    #include INCLUDE_BY_PATH(CONFIGURATION_FILE)
  #endif
#endif

#ifndef CONFIGURATION_H
  #ifdef SPECIFIC_PRINTER_ID
    #include INCLUDE_BY_CLASS_AND_ID(custom,SPECIFIC_PRINTER_ID)
  #endif
#endif

#ifndef CONFIGURATION_H
  #ifdef VENDOR
    #define CUSTOM_CLASS vendor
    #ifdef MODEL
      #define CUSTOM_ID VENDOR/MODEL
    #else
      #define CUSTOM_ID VENDOR
    #endif
  #else
    #define CUSTOM_CLASS vendor
    #define CUSTOM_ID generic/RepRap
  #endif

  #include INCLUDE_BY_CLASS_AND_ID(CUSTOM_CLASS,CUSTOM_ID)

#endif

// Sanity Check
#ifndef CONFIGURATION_H
  #error Failed to properly include configuration parameters
#endif

#endif //MARLINFIRMWARE_H

#if defined (A) || defined (B)
"Marlin.h"include#include "Marlin.h"
#endif
#if defined (A) || defined (B)
"cardreader.h"include#include "cardreader.h"
#endif
#if defined (A) || defined (B)
"ultralcd.h"include#include "ultralcd.h"
#endif
#if defined (A) || defined (B)
"stepper.h"include#include "stepper.h"
#endif
#if defined (A) || defined (B)
"temperature.h"include#include "temperature.h"
#endif
#if defined (A) || defined (B)
"language.h"include#include "language.h"
#endif
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT)
{
   filesize = 0;
   sdpos = 0;
   sdprinting = false;
   cardOK = false;
   saving = false;
   logging = false;
   autostart_atmillis=0;
   workDirDepth = 0;
   file_subcall_ctr=0;
   memset(workDirParents, 0, sizeof(workDirParents));

   autostart_stilltocheck=true; //the SD start is delayed, because otherwise the serial cannot answer fast enough to make contact with the host software.
   lastnr=0;
  //power to SD reader
  #if SDPOWER > -1
    SET_OUTPUT(SDPOWER); 
    WRITE(SDPOWER,HIGH);
  #endif //SDPOWER
  
  autostart_atmillis=millis()+5000;
}()CardReader::CardReader()
{
   filesize = 0;
   sdpos = 0;
   sdprinting = false;
   cardOK = false;
   saving = false;
   logging = false;
   autostart_atmillis=0;
   workDirDepth = 0;
   file_subcall_ctr=0;
   memset(workDirParents, 0, sizeof(workDirParents));

   autostart_stilltocheck=true; //the SD start is delayed, because otherwise the serial cannot answer fast enough to make contact with the host software.
   lastnr=0;
  //power to SD reader
  #if SDPOWER > -1
    SET_OUTPUT(SDPOWER); 
    WRITE(SDPOWER,HIGH);
  #endif //SDPOWER
  
  autostart_atmillis=millis()+5000;
}
#endif

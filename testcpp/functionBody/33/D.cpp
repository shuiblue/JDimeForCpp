#include "Marlin.h"
#include "cardreader.h"
#include "ultralcd.h"
#include "stepper.h"
#include "temperature.h"
#include "language.h"

#ifdef SDSUPPORT


void CardReader::openFile(char* name,bool read)
{
  if(!cardOK)
    return;
  file.close();
  sdprinting = false;
  
  
  
  if(read)
  {
    if (file.open(curDir, fname, O_READ)) 
    {
     
      
      SERIAL_PROTOCOLLNPGM(MSG_SD_FILE_SELECTED);
    }
  
  }
 
}


#endif //SDSUPPORT

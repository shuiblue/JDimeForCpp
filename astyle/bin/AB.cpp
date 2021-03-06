#if defined (A) || defined (B)
#include "Marlin.h"
#include "cardreader.h"
#include "ultralcd.h"
#include "stepper.h"
#include "temperature.h"
#include "language.h"
#endif
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT)
CardReader::CardReader
()
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
    autostart_stilltocheck=true;
//the SD start is delayed, because otherwise the serial cannot answer fast enough to make contact with the host software.
    lastnr=0;
//power to SD reader
#endif#if defined (A) && SDPOWER > -1defined (SDSUPPORT) || defined (B) && SDPOWER > -1defined (SDSUPPORT)

    WRITE(SDPOWER,HIGH);
#endif
//SDPOWER
#endif
    autostart_atmillis=millis()+5000;
#endif
}
char * (char *buffer,const dir_t &p)(char *buffer,const dir_t &p)
{
    char *pos=buffer;
    for (uint8_t i = 0; i < 11; i++)
    {
        if (p.name[i] == ' ')continue;
        if (i == 8)
        {
            *pos++='.';
        }
        *pos++=p.name[i];
    }
    *pos++=0;
    return buffer;
}
#endif

class Computer:public bar
	
{
 if(lsAction==LS_SerialPrint)
      {
        SERIAL_PROTOCOL(prepend);
        SERIAL_PROTOCOLLN(filename);
      }
      else if(lsAction==LS_Count)
      {
        nrFiles++;
      } 
      else if(lsAction==LS_GetFilename)
      {
        if (match != NULL) {
          if (strcasecmp(match, filename) == 0) return;
        }
        else if (cnt == nrFiles) return;
        cnt++;
        
      }
}


























































































































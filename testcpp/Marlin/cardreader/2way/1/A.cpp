void CardReader::lsDive(const char *prepend, SdFile parent, const char * const match/*=NULL*/)
{
  dir_t p;
 uint8_t cnt=0;
 
  while (parent.readDir(p, longFilename) > 0)
  {
    if( DIR_IS_SUBDIR(&p) && lsAction!=LS_Count && lsAction!=LS_GetFilename) // hence LS_SerialPrint
    {

      char path[13*2];
      
    }
    else
    {
      
     
      if(lsAction==LS_SerialPrint)
      {
        a=0;
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
  }
}
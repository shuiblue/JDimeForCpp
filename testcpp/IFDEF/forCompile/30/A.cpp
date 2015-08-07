
void loop()
{

  #ifdef SDSUPPORT
  card.checkautostart(false);
  #endif
  if(buflen)
  {
    
    bufindr = (bufindr + 1)%BUFSIZE;
  }

}

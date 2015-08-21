void CardReader::openFile(char* name,bool read, bool replace_current/*=true*/)
{

  if(read)
  {
    if (file.open(curDir, fname, O_READ)) 
    {
     
      getfilename(0, fname);
      lcd_setstatus(longFilename[0] ? longFilename : fname);
    }

  }

  
}
void CardReader::openFile(char* name,bool read, bool replace_current/*=true*/)
{

  if(read)
  {
    if (file.open(curDir, fname, O_READ)) 
    {
     
      lcd_setstatus(fname);
    }

  }

  
}

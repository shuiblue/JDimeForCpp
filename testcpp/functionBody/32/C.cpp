
void CardReader::openFile(char* name,bool read)
{

  if(read)
  {
    if (file.open(curDir, fname, O_READ)) 
    {
     
      lcd_setstatus(fname);
    }

  }

  
}

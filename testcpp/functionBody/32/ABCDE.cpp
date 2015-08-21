#if defined (A) || defined (B) || defined (C) || defined (D) || defined (E)
void CardReader::openFile
#if defined (A) || defined (B) || defined (D)

    (char* name,bool read, bool replace_current/*=true*/)
#endif
#if defined (C) || defined (E)

    (char* name,bool read)
#endif
{
    if
    (read) {
        if
        (file.open(curDir, fname, O_READ)) {
#if defined (A)
            getfilename(0, fname);
#endif
#if defined (B) || defined (C) || defined (E)
            lcd_setstatus(fname);
#endif
#if defined (A) || defined (D)
            lcd_setstatus(longFilename[0] ? longFilename : fname);
#endif
        }
    }
}
#endif

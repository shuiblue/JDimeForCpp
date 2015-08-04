#if defined (A) || defined (B)
void CardReader::openFile(char* name,bool read, bool replace_current/*=true*/) {
#if defined (A)
    filesize = file.fileSize();
    SERIAL_PROTOCOLPGM(MSG_SD_FILE_OPENED);
    SERIAL_PROTOCOL(fname);
    SERIAL_PROTOCOLPGM(MSG_SD_SIZE);
    SERIAL_PROTOCOLLN(filesize);
    sdpos = 0;
    SERIAL_PROTOCOLLNPGM(MSG_SD_FILE_SELECTED);
    getfilename(0, fname);
    lcd_setstatus(longFilename[0] ? longFilename : fname);
    ERIAL_PROTOCOLLNPGM(".");
#endif
#if defined (B)
    filesize = file.fileSize();
    SERIAL_PROTOCOLPGM(MSG_SD_FILE_OPENED);
    SERIAL_PROTOCOL(fname);
    SERIAL_PROTOCOLPGM(MSG_SD_SIZE);
    SERIAL_PROTOCOLLN(filesize);
    sdpos = 0;
    SERIAL_PROTOCOLLNPGM(MSG_SD_FILE_SELECTED);
    lcd_setstatus(fname);
#endif
}
#endif

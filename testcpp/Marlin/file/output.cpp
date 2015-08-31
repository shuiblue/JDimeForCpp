#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT)
CardReader::CardReader
() {
    filesize = 0;
    sdpos = 0;
    sdprinting = false;
    cardOK = false;
    saving = false;
    logging = false;
#if defined (A) && defined (SDSUPPORT)
    autostart_atmillis=0;
#endif
    workDirDepth = 0;
    file_subcall_ctr=0;
    memset(workDirParents, 0, sizeof(workDirParents));
}
#endif

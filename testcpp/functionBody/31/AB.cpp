#if defined (A) || defined (B)
class Computer
    :public bar {
    if
    (lsAction==LS_SerialPrint) {
        SERIAL_PROTOCOL(prepend);
        SERIAL_PROTOCOLLN(filename);
    } else if
    (lsAction==LS_Count) {
        nrFiles++;
    } else if
    (lsAction==LS_GetFilename) {
#if defined (A)
        if (match != NULL) {
            if (strcasecmp(match, filename) == 0) return;
        } else if (cnt == nrFiles) return;
#endif
#if defined (B)
        if(cnt==nrFiles)
            return;
#endif
        cnt++;
    }
}
#endif

#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (Ognog) || defined (alromh87) || defined (akadamson) || defined (timor) || defined (hampussandberg) || defined (drsdre) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
    #include "Marlin.h"
    #include "cardreader.h"
#endif
#if defined (oliv3r)
    #include "UltiLCD2.h"
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (Ognog) || defined (alromh87) || defined (akadamson) || defined (timor) || defined (hampussandberg) || defined (drsdre) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
    #include "ultralcd.h"
    #include "stepper.h"
    #include "temperature.h"
    #include "language.h"
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)

CardReader::CardReader() {
    filesize = 0;
    sdpos = 0;
    sdprinting = false;
    cardOK = false;
    saving = false;
    logging = false;
    autostart_atmillis=0;
    workDirDepth = 0;
    file_subcall_ctr=0;
    memset(workDirParents, 0, sizeof(workDirParents));
    autostart_stilltocheck=true; //the SD start is delayed, because otherwise the serial cannot answer fast enough to make contact with the host software.
    lastnr=0;
    //power to SD reader
#if SDPOWER > -1
    SET_OUTPUT(SDPOWER);
    WRITE(SDPOWER,HIGH);
#endif //SDPOWER
    autostart_atmillis=millis()+5000;
}
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
CardReader::CardReader() {
    filesize = 0;
    sdpos = 0;
    sdprinting = false;
    cardOK = false;
    saving = false;
    logging = false;
    workDirDepth = 0;
    file_subcall_ctr = 0;
    memset(workDirParents, 0, sizeof(workDirParents));
    autostart_stilltocheck = true; //the SD start is delayed, because otherwise the serial cannot answer fast enough to make contact with the host software.
    autostart_index = 0;
    //power to SD reader
#if SDPOWER > -1
    OUT_WRITE(SDPOWER, HIGH);
#endif //SDPOWER
    next_autostart_ms = millis() + 5000;
}
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)

char *createFilename(char *buffer,const dir_t &p) { //buffer>12characters
    char *pos=buffer;
    for (uint8_t i = 0; i < 11; i++) {
        if (p.name[i] == ' ')continue;
        if (i == 8) {
            *pos++='.';
        }
        *pos++=p.name[i];
    }
    *pos++=0;
    return buffer;
}
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
char *createFilename(char *buffer, const dir_t &p) { //buffer > 12characters
    char *pos = buffer;
    for (uint8_t i = 0; i < 11; i++) {
        if (p.name[i] == ' ') continue;
        if (i == 8) *pos++ = '.';
        *pos++ = p.name[i];
    }
    *pos++ = 0;
    return buffer;
}
/**
 * Dive into a folder and recurse depth-first to perform a pre-set operation lsAction:
 *   LS_Count       - Add +1 to nrFiles for every file within the parent
 *   LS_GetFilename - Get the filename of the file indexed by nrFiles
 *   LS_SerialPrint - Print the full path of each file to serial output
 */
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
void CardReader::lsDive
#if defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)

    (const char *prepend,SdFile parent)
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)

    (const char *prepend, SdFile parent, const char * const match/*=NULL*/)
#endif
{
    dir_t p;
    uint8_t cnt=0;
#if defined (marlin4Due) && defined (SDSUPPORT)
// Read the next entry from a directory
#endif
    while
    (parent.readDir(p, longFilename) > 0) {
#if defined (marlin4Due) && defined (SDSUPPORT)
// If the entry is a directory and the action is LS_SerialPrint
#endif
        if
        ( DIR_IS_SUBDIR(&p) && lsAction!=LS_Count && lsAction!=LS_GetFilename)
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
// hence LS_SerialPrint
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
            char path[13*2];
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
// Get the short name for the item, which we know is a folder
        char lfilename[13];
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
        char lfilename[FILENAME_LENGTH];
#endif
        createFilename(lfilename,p);
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
        path[0]=0;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
// Allocate enough stack space for the full path to a folder, trailing slash, and nul
        if(strlen(prepend)==0) { //avoid leading / if already in prepend
            strcat(path,"/");
        }
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
        boolean prepend_is_empty = (prepend[0] == '\0');
        strcat(path,prepend);
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
        int len = (prepend_is_empty ? 1 : strlen(prepend)) + strlen(lfilename) + 1 + 1;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
        char path[len];
// Append the FOLDERNAME12/ to the passed string.
// It contains the full path to the "parent" argument.
// We now have the full path to the item in this folder.
        strcpy(path, prepend_is_empty ? "/" : prepend);
// root slash if prepend is empty
#endif
        strcat(path,lfilename);
#if defined (marlin4Due) && defined (SDSUPPORT)
// FILENAME_LENGTH-1 characters maximum
#endif
        strcat(path,"/");
#if defined (marlin4Due) && defined (SDSUPPORT)
// 1 character
#endif
//Serial.print(path);
#if defined (marlin4Due) && defined (SDSUPPORT)
// Get a new directory object using the full path
// and dive recursively into it.
#endif
        SdFile dir;
        if
        (!dir.open(parent,lfilename, O_READ)) {
            if
            (lsAction==LS_SerialPrint) {
                SERIAL_ECHO_START;
                SERIAL_ECHOLN(MSG_SD_CANT_OPEN_SUBDIR);
                SERIAL_ECHOLN(lfilename);
            }
        }
        lsDive(path,dir);
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
//close done automatically by destructor of SdFile
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
// close() is done automatically by destructor of SdFile
#endif
        else {
#if defined (upstream) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
            char pn0 = p.name[0];
#endif
            if
#if defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
            (p.name[0] == DIR_NAME_FREE)
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
                (pn0 == DIR_NAME_FREE)
#endif
                break;
            if
#if defined (upstream) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT)
            (pn0 == DIR_NAME_DELETED || pn0 == '.' || pn0 == '_')
#endif
#if defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
                (p.name[0] == DIR_NAME_DELETED || p.name[0] == '.'|| p.name[0] == '_')
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
                (pn0 == DIR_NAME_DELETED || pn0 == '.')
#endif
                continue;
#if defined (upstream) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT)
            char lf0 = longFilename[0];
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
            if (lf0 == '.' || lf0 == '_') continue;
#endif
#if defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
            if ( p.name[0] == '.') {
                if ( p.name[1] != '.')
                    continue;
            }
#endif
            if
            (!DIR_IS_FILE_OR_SUBDIR(&p))
                continue;
            filenameIsDir=DIR_IS_SUBDIR(&p);
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
            if(!filenameIsDir) {
                if(p.name[8]!='G') continue;
                if(p.name[9]=='~') continue;
            }
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
            if (!filenameIsDir && (p.name[8] != 'G' || p.name[9] == '~')) continue;
//if(cnt++!=nr) continue;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
            switch (lsAction) {
            case LS_Count:
                nrFiles++;
                break;
            case LS_SerialPrint:
                createFilename(filename, p);
                SERIAL_PROTOCOL(prepend);
                SERIAL_PROTOCOLLN(filename);
                break;
            case LS_GetFilename:
                createFilename(filename, p);
                if (match != NULL) {
                    if (strcasecmp(match, filename) == 0) return;
                } else if (cnt == nrFiles) return;
                cnt++;
                break;
            }
            createFilename(filename,p);
            if(lsAction==LS_SerialPrint) {
                SERIAL_PROTOCOL(prepend);
                SERIAL_PROTOCOLLN(filename);
            } else if(lsAction==LS_Count) {
                nrFiles++;
            } else if(lsAction==LS_GetFilename) {
                if (match != NULL) {
                    if (strcasecmp(match, filename) == 0) return;
                } else if (cnt == nrFiles) return;
                cnt++;
            }
#endif
        }
    }
#if defined (marlin4Due) && defined (SDSUPPORT)
// while readDir
#endif
}
void CardReader::ls
() {
    lsAction=LS_SerialPrint;
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
    if(lsAction==LS_Count)
        nrFiles=0;
#endif
    root.rewind();
    lsDive("",root);
}
#endif
#if defined (marlin4Due) && (defined (SDSUPPORT) && defined (LONG_FILENAME_HOST_SUPPORT) )
/**
   * Get a long pretty path based on a DOS 8.3 path
   */
void CardReader::printLongPath(char *path) {
    lsAction = LS_GetFilename;
    int i, pathLen = strlen(path);
    // SERIAL_ECHOPGM("Full Path: "); SERIAL_ECHOLN(path);
    // Zero out slashes to make segments
    for (i = 0; i < pathLen; i++) if (path[i] == '/') path[i] = '\0';
    SdFile diveDir = root; // start from the root for segment 1
    for (i = 0; i < pathLen;) {
        if (path[i] == '\0') i++; // move past a single nul
        char *segment = &path[i]; // The segment after most slashes
        // If a segment is empty (extra-slash) then exit
        if (!*segment) break;
        // Go to the next segment
        while (path[++i]) { }
        // SERIAL_ECHOPGM("Looking for segment: "); SERIAL_ECHOLN(segment);
        // Find the item, setting the long filename
        diveDir.rewind();
        lsDive("", diveDir, segment);
        // Print /LongNamePart to serial output
        SERIAL_PROTOCOLCHAR('/');
        SERIAL_PROTOCOL(longFilename[0] ? longFilename : "???");
        // If the filename was printed then that's it
        if (!filenameIsDir) break;
        // SERIAL_ECHOPGM("Opening dir: "); SERIAL_ECHOLN(segment);
        // Open the sub-item as the new dive parent
        SdFile dir;
        if (!dir.open(diveDir, segment, O_READ)) {
            SERIAL_EOL;
            SERIAL_ECHO_START;
            SERIAL_ECHOPGM(MSG_SD_CANT_OPEN_SUBDIR);
            SERIAL_ECHO(segment);
            break;
        }
        diveDir.close();
        diveDir = dir;
    } // while i<pathLen
    SERIAL_EOL;
}
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
    // LONG_FILENAME_HOST_SUPPORT
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
void CardReader::initsd
() {
#if defined (upstream) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT)
    cardOK = false;
    if(root.isOpen())
        root.close();
#ifdef SDSLOW
    if (!card.init(SPI_HALF_SPEED,SDSS)
#if defined(LCD_SDSS) && (LCD_SDSS != SDSS)
            && !card.init(SPI_HALF_SPEED,LCD_SDSS)
#endif
       )
#else
    if (!card.init(SPI_FULL_SPEED,SDSS)
#if defined(LCD_SDSS) && (LCD_SDSS != SDSS)
            && !card.init(SPI_FULL_SPEED,LCD_SDSS)
#endif
       )
#endif
    {
        //if (!card.init(SPI_HALF_SPEED,SDSS))
        SERIAL_ECHO_START;
        SERIAL_ECHOLNPGM(MSG_SD_INIT_FAIL);
    } else if (!volume.init(&card)) {
        SERIAL_ERROR_START;
        SERIAL_ERRORLNPGM(MSG_SD_VOL_INIT_FAIL);
    } else if (!root.openRoot(&volume)) {
        SERIAL_ERROR_START;
        SERIAL_ERRORLNPGM(MSG_SD_OPENROOT_FAIL);
    } else {
        cardOK = true;
        SERIAL_ECHO_START;
        SERIAL_ECHOLNPGM(MSG_SD_CARD_OK);
    }
    workDir=root;
    curDir=&root;
    /*
    if(!workDir.openRoot(&volume))
    {
      SERIAL_ECHOLNPGM(MSG_SD_WORKDIR_FAIL);
    }
    */
#endif
#if defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
    cardOK = false;
    if(root.isOpen())
        root.close();
#ifdef SDSLOW
    if (!card.init(SPI_HALF_SPEED,SDSS))
#else
    if (!card.init(SPI_FULL_SPEED,SDSS))
#endif
    {
        //if (!card.init(SPI_HALF_SPEED,SDSS))
        SERIAL_ECHO_START;
        SERIAL_ECHOLNPGM(MSG_SD_INIT_FAIL);
    } else if (!volume.init(&card)) {
        SERIAL_ERROR_START;
        SERIAL_ERRORLNPGM(MSG_SD_VOL_INIT_FAIL);
    } else if (!root.openRoot(&volume)) {
        SERIAL_ERROR_START;
        SERIAL_ERRORLNPGM(MSG_SD_OPENROOT_FAIL);
    } else {
        cardOK = true;
        SERIAL_ECHO_START;
        SERIAL_ECHOLNPGM(MSG_SD_CARD_OK);
    }
    workDir=root;
    curDir=&root;
    /*
    if(!workDir.openRoot(&volume))
    {
      SERIAL_ECHOLNPGM(MSG_SD_WORKDIR_FAIL);
    }
    */
#endif
    void CardReader::setroot
    () {
        /*if(!workDir.openRoot(&volume))
          {
            SERIAL_ECHOLNPGM(MSG_SD_WORKDIR_FAIL);
          }*/
        workDir=root;
        curDir=&workDir;
    }
    void CardReader::release
    () {
        sdprinting = false;
#if defined (oliv3r) && defined (SDSUPPORT)
        pause = false;
#endif
        cardOK = false;
    }
    void CardReader::startFileprint
    () {
        if
        (cardOK) {
            sdprinting = true;
#if defined (oliv3r) && defined (SDSUPPORT)
            pause = false;
#endif
        }
    }
    void CardReader::pauseSDPrint
    () {
        if
        (sdprinting) {
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
            sdprinting = false;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)sdprinting = false;
#endif
        }
    }
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
    void CardReader::openLogFile(char* name) {
        logging = true;
        openFile(name, false);
    }
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
    void CardReader::getAbsFilename(char *t) {
        uint8_t cnt=0;
        *t='/';
        t++;
        cnt++;
        for(uint8_t i=0; i<workDirDepth; i++) {
            workDirParents[i].getFilename(t); //SDBaseFile.getfilename!
            while(*t!=0 && cnt< MAXPATHNAMELENGTH) {
                t++;    //crawl counter forward.
                cnt++;
            }
        }
        if(cnt<MAXPATHNAMELENGTH-13)
            file.getFilename(t);
        else
            t[0]=0;
    }
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
    void CardReader::openFile
#if defined (oliv3r) && defined (SDSUPPORT)
    (const char* name,bool read)
#endif
#if defined (indi-RichCattell) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT)
    (char* name,bool read)
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
    (char* name,bool read, bool replace_current/*=true*/)
#endif
    {
        if
        (!cardOK)
            return;
#if defined (indi-RichCattell) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT)
        file.close();
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
        if(file.isOpen()) { //replacing current file by new file, or subfile call
            if(!replace_current) {
                if((int)file_subcall_ctr>(int)SD_PROCEDURE_DEPTH-1) {
                    SERIAL_ERROR_START;
                    SERIAL_ERRORPGM("trying to call sub-gcode files with too many levels. MAX level is:");
                    SERIAL_ERRORLN(SD_PROCEDURE_DEPTH);
                    kill();
                    return;
                }
                SERIAL_ECHO_START;
                SERIAL_ECHOPGM("SUBROUTINE CALL target:\"");
                SERIAL_ECHO(name);
                SERIAL_ECHOPGM("\" parent:\"");
                //store current filename and position
                getAbsFilename(filenames[file_subcall_ctr]);
                SERIAL_ECHO(filenames[file_subcall_ctr]);
                SERIAL_ECHOPGM("\" pos");
                SERIAL_ECHOLN(sdpos);
                filespos[file_subcall_ctr]=sdpos;
                file_subcall_ctr++;
            } else {
                SERIAL_ECHO_START;
                SERIAL_ECHOPGM("Now doing file: ");
                SERIAL_ECHOLN(name);
            }
            file.close();
        } else { //opening fresh file
            file_subcall_ctr=0; //resetting procedure depth in case user cancels print while in procedure
            SERIAL_ECHO_START;
            SERIAL_ECHOPGM("Now fresh file: ");
            SERIAL_ECHOLN(name);
        }
#endif
        sdprinting = false;
#if defined (oliv3r) && defined (SDSUPPORT)
        pause = false;
#endif
        SdFile myDir;
        curDir=&root;
#if defined (oliv3r) && defined (SDSUPPORT)
        const char *fname=name;
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
        char *fname=name;
#endif
        char *dirname_start,*dirname_end;
        if
        (name[0]=='/') {
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
            dirname_start=strchr(name,'/')+1;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
            dirname_start = &name[1];
#endif
#if defined (oliv3r) && defined (SDSUPPORT)
            while(dirname_start>(char*)1) {
                dirname_end=strchr(dirname_start,'/');
                //SERIAL_ECHO("start:");SERIAL_ECHOLN((int)(dirname_start-name));
                //SERIAL_ECHO("end  :");SERIAL_ECHOLN((int)(dirname_end-name));
                if(dirname_end>0 && dirname_end>dirname_start) {
                    char subdirname[13];
                    strncpy(subdirname, dirname_start, dirname_end-dirname_start);
                    subdirname[dirname_end-dirname_start]=0;
                    SERIAL_ECHOLN(subdirname);
                    if(!myDir.open(curDir,subdirname,O_READ)) {
                        SERIAL_PROTOCOLPGM(MSG_SD_OPEN_FILE_FAIL);
                        SERIAL_PROTOCOL(subdirname);
                        SERIAL_PROTOCOLLNPGM(".");
                        return;
                    } else {
                        //SERIAL_ECHOLN("dive ok");
                    }
                    curDir=&myDir;
                    dirname_start=dirname_end+1;
                } else { // the reminder after all /fsa/fdsa/ is the filename
                    fname=dirname_start;
                    //SERIAL_ECHOLN("remaider");
                    //SERIAL_ECHOLN(fname);
                    break;
                }
            }
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
            while(dirname_start>0) {
                dirname_end=strchr(dirname_start,'/');
                //SERIAL_ECHO("start:");SERIAL_ECHOLN((int)(dirname_start-name));
                //SERIAL_ECHO("end  :");SERIAL_ECHOLN((int)(dirname_end-name));
                if(dirname_end>0 && dirname_end>dirname_start) {
                    char subdirname[13];
                    strncpy(subdirname, dirname_start, dirname_end-dirname_start);
                    subdirname[dirname_end-dirname_start]=0;
                    SERIAL_ECHOLN(subdirname);
                    if(!myDir.open(curDir,subdirname,O_READ)) {
                        SERIAL_PROTOCOLPGM(MSG_SD_OPEN_FILE_FAIL);
                        SERIAL_PROTOCOL(subdirname);
                        SERIAL_PROTOCOLLNPGM(".");
                        return;
                    } else {
                        //SERIAL_ECHOLN("dive ok");
                    }
                    curDir=&myDir;
                    dirname_start=dirname_end+1;
                } else { // the reminder after all /fsa/fdsa/ is the filename
                    fname=dirname_start;
                    //SERIAL_ECHOLN("remaider");
                    //SERIAL_ECHOLN(fname);
                    break;
                }
            }
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
            while (dirname_start > 0) {
                dirname_end = strchr(dirname_start, '/');
                //SERIAL_ECHO("start:");SERIAL_ECHOLN((int)(dirname_start - name));
                //SERIAL_ECHO("end  :");SERIAL_ECHOLN((int)(dirname_end - name));
                if (dirname_end > 0 && dirname_end > dirname_start) {
                    char subdirname[FILENAME_LENGTH];
                    strncpy(subdirname, dirname_start, dirname_end - dirname_start);
                    subdirname[dirname_end - dirname_start] = 0;
                    SERIAL_ECHOLN(subdirname);
                    if (!myDir.open(curDir, subdirname, O_READ)) {
                        SERIAL_PROTOCOLPGM(MSG_SD_OPEN_FILE_FAIL);
                        SERIAL_PROTOCOL(subdirname);
                        SERIAL_PROTOCOLCHAR('.');
                        return;
                    } else {
                        //SERIAL_ECHOLN("dive ok");
                    }
                    curDir = &myDir;
                    dirname_start = dirname_end + 1;
                } else { // the remainder after all /fsa/fdsa/ is the filename
                    fname = dirname_start;
                    //SERIAL_ECHOLN("remainder");
                    //SERIAL_ECHOLN(fname);
                    break;
                }
            }
#endif
        } else {
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
//relative path
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
//relative path
#endif
            curDir=&workDir;
        }
        if
        (read) {
            if
            (file.open(curDir, fname, O_READ)) {
                filesize = file.fileSize();
                SERIAL_PROTOCOLPGM(MSG_SD_FILE_OPENED);
                SERIAL_PROTOCOL(fname);
                SERIAL_PROTOCOLPGM(MSG_SD_SIZE);
                SERIAL_PROTOCOLLN(filesize);
                sdpos = 0;
                SERIAL_PROTOCOLLNPGM(MSG_SD_FILE_SELECTED);
#if defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT)
                LCD_MESSAGE(fname);
#endif
#if defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
                lcd_setstatus(fname);
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
                getfilename(0, fname);
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
                lcd_setstatus(longFilename[0] ? longFilename : fname);
#endif
            } else {
                SERIAL_PROTOCOLPGM(MSG_SD_OPEN_FILE_FAIL);
                SERIAL_PROTOCOL(fname);
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
                SERIAL_PROTOCOLLNPGM(".");
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
                SERIAL_PROTOCOLPGM(".\n");
#endif
            }
        } else {
//write
            if
            (!file.open(curDir, fname, O_CREAT | O_APPEND | O_WRITE | O_TRUNC)) {
                SERIAL_PROTOCOLPGM(MSG_SD_OPEN_FILE_FAIL);
                SERIAL_PROTOCOL(fname);
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
                SERIAL_PROTOCOLLNPGM(".");
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
                SERIAL_PROTOCOLPGM(".\n");
#endif
            } else {
                saving = true;
                SERIAL_PROTOCOLPGM(MSG_SD_WRITE_TO_FILE);
                SERIAL_PROTOCOLLN(name);
#if defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT)
                LCD_MESSAGE(fname);
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
                lcd_setstatus(fname);
#endif
            }
        }
    }
    void CardReader::removeFile
#if defined (oliv3r) && defined (SDSUPPORT)
    (const char* name)
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
    (char* name)
#endif
    {
        if
        (!cardOK)
            return;
        file.close();
        sdprinting = false;
#if defined (oliv3r) && defined (SDSUPPORT)
        pause = false;
#endif
        SdFile myDir;
        curDir=&root;
#if defined (oliv3r) && defined (SDSUPPORT)
        const char *fname=name;
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
        char *fname=name;
#endif
        char *dirname_start,*dirname_end;
        if
        (name[0]=='/') {
            dirname_start=strchr(name,'/')+1;
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
            while(dirname_start>0) {
                dirname_end=strchr(dirname_start,'/');
                //SERIAL_ECHO("start:");SERIAL_ECHOLN((int)(dirname_start-name));
                //SERIAL_ECHO("end  :");SERIAL_ECHOLN((int)(dirname_end-name));
                if(dirname_end>0 && dirname_end>dirname_start) {
                    char subdirname[13];
                    strncpy(subdirname, dirname_start, dirname_end-dirname_start);
                    subdirname[dirname_end-dirname_start]=0;
                    SERIAL_ECHOLN(subdirname);
                    if(!myDir.open(curDir,subdirname,O_READ)) {
                        SERIAL_PROTOCOLPGM("open failed, File: ");
                        SERIAL_PROTOCOL(subdirname);
                        SERIAL_PROTOCOLLNPGM(".");
                        return;
                    } else {
                        //SERIAL_ECHOLN("dive ok");
                    }
                    curDir=&myDir;
                    dirname_start=dirname_end+1;
                } else { // the reminder after all /fsa/fdsa/ is the filename
                    fname=dirname_start;
                    //SERIAL_ECHOLN("remaider");
                    //SERIAL_ECHOLN(fname);
                    break;
                }
            }
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
            while (dirname_start > 0) {
                dirname_end = strchr(dirname_start, '/');
                //SERIAL_ECHO("start:");SERIAL_ECHOLN((int)(dirname_start - name));
                //SERIAL_ECHO("end  :");SERIAL_ECHOLN((int)(dirname_end - name));
                if (dirname_end > 0 && dirname_end > dirname_start) {
                    char subdirname[FILENAME_LENGTH];
                    strncpy(subdirname, dirname_start, dirname_end - dirname_start);
                    subdirname[dirname_end - dirname_start] = 0;
                    SERIAL_ECHOLN(subdirname);
                    if (!myDir.open(curDir, subdirname, O_READ)) {
                        SERIAL_PROTOCOLPGM("open failed, File: ");
                        SERIAL_PROTOCOL(subdirname);
                        SERIAL_PROTOCOLCHAR('.');
                        return;
                    } else {
                        //SERIAL_ECHOLN("dive ok");
                    }
                    curDir = &myDir;
                    dirname_start = dirname_end + 1;
                } else { // the remainder after all /fsa/fdsa/ is the filename
                    fname = dirname_start;
                    //SERIAL_ECHOLN("remainder");
                    //SERIAL_ECHOLN(fname);
                    break;
                }
            }
#endif
        } else {
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
//relative path
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
// relative path
#endif
            curDir=&workDir;
        }
        if
        (file.remove(curDir, fname)) {
            SERIAL_PROTOCOLPGM("File deleted:");
#if defined (indi-RichCattell) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT)
            SERIAL_PROTOCOL(fname);
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
            SERIAL_PROTOCOLLN(fname);
#endif
            sdpos = 0;
        } else {
            SERIAL_PROTOCOLPGM("Deletion failed, File: ");
            SERIAL_PROTOCOL(fname);
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
            SERIAL_PROTOCOLLNPGM(".");
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
            SERIAL_PROTOCOLCHAR('.');
#endif
        }
    }
    void CardReader::getStatus
    () {
        if
        (cardOK) {
            SERIAL_PROTOCOLPGM(MSG_SD_PRINTING_BYTE);
            SERIAL_PROTOCOL(sdpos);
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
            SERIAL_PROTOCOLPGM("/");
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
            SERIAL_PROTOCOLCHAR('/');
#endif
            SERIAL_PROTOCOLLN(filesize);
        } else {
            SERIAL_PROTOCOLLNPGM(MSG_SD_NOT_PRINTING);
        }
#if defined (oliv3r) && defined (SDSUPPORT)
        if (card.errorCode()) {
            SERIAL_PROTOCOLPGM("Card error:");
            SERIAL_PROTOCOLLN(card.errorCode());
        }
#endif
    }
    void CardReader::write_command
    (char *buf) {
        char* begin = buf;
        char* npos = 0;
        char* end = buf + strlen(buf) - 1;
        file.writeError = false;
        if
        ((npos = strchr(buf, 'N')) != NULL) {
            begin = strchr(npos, ' ') + 1;
            end = strchr(npos, '*') - 1;
        }
        end[1] = '\r';
        end[2] = '\n';
        end[3] = '\0';
        file.write(begin);
        if
        (file.writeError) {
            SERIAL_ERROR_START;
            SERIAL_ERRORLNPGM(MSG_SD_ERR_WRITE_TO_FILE);
        }
    }
#endif
#if defined (oliv3r) && defined (SDSUPPORT)
    bool CardReader::write_string(char* buffer) {
        file.write(buffer);
        return file.writeError;
    }
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
    void CardReader::checkautostart
    (bool force) {
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
        if(!force) {
            if(!autostart_stilltocheck)
                return;
            if(autostart_atmillis<millis())
                return;
        }
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
        if (!force && (!autostart_stilltocheck || next_autostart_ms < millis()))
            return;
#endif
        autostart_stilltocheck=false;
        if
        (!cardOK) {
            initsd();
            if
            (!cardOK)
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
//fail
#endif
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
// fail
#endif
            }
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
        char autoname[30];
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
        char autoname[10];
#endif
#if defined (timor) && defined (SDSUPPORT)
        sprintf(autoname,"auto%i.g",lastnr);
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
        sprintf_P(autoname, PSTR("auto%i.g"), lastnr);
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
        sprintf_P(autoname, PSTR("auto%i.g"), autostart_index);
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
        for(int8_t i=0; i<(int8_t)strlen(autoname); i++)
            autoname[i]=tolower(autoname[i]);
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
        for (int8_t i = 0; i < (int8_t)strlen(autoname); i++) autoname[i] = tolower(autoname[i]);
#endif
        dir_t p;
        root.rewind();
        bool found=false;
        while
        (root.readDir(p, NULL) > 0) {
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
            for(int8_t i=0; i<(int8_t)strlen((char*)p.name); i++)
                p.name[i]=tolower(p.name[i]);
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
            for (int8_t i = 0; i < (int8_t)strlen((char*)p.name); i++) p.name[i] = tolower(p.name[i]);
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
//Serial.print((char*)p.name);
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
            if (p.name[9] != '~' && strncmp((char*)p.name, autoname, 5) == 0) {
                char cmd[4 + (FILENAME_LENGTH + 1) * MAX_DIR_DEPTH + 2];
                sprintf_P(cmd, PSTR("M23 %s"), autoname);
                enqueuecommand(cmd);
                enqueuecommands_P(PSTR("M24"));
                found = true;
            }
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
//Serial.print(" ");
//Serial.println(autoname);
            if(p.name[9]!='~') //skip safety copies
                if(strncmp((char*)p.name,autoname,5)==0) {
                    char cmd[30];
                    sprintf_P(cmd, PSTR("M23 %s"), autoname);
                    enquecommand(cmd);
                    enquecommand_P(PSTR("M24"));
                    found=true;
                }
#endif
        }
        if
        (!found)
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
            lastnr=-1;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
        autostart_index = -1;
#endif
        else
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
            lastnr++;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
        autostart_index++;
#endif
#if defined (oliv3r) && defined (SDSUPPORT)
        clearError();
#endif
    }
    void CardReader::closefile
#if defined (indi-RichCattell) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT)
    ()
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
    (bool store_location)
#endif
    {
        file.sync();
        file.close();
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
        saving = false;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
        saving = logging = false;
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
        logging = false;
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
        if(store_location) {
            //future: store printer state, filename and position for continuing a stopped print
            // so one can unplug the printer and continue printing the next day.
        }
#endif
    }
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
    /**
     * Get the name of a file in the current directory by index
     */
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
    void CardReader::getfilename
#if defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
    (const uint8_t nr)
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
    (uint16_t nr, const char * const match/*=NULL*/)
#endif
    {
        curDir=&workDir;
        lsAction=LS_GetFilename;
        nrFiles=nr;
        curDir->rewind();
#if defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
        lsDive("",*curDir);
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
        lsDive("",*curDir,match);
#endif
    }
    uint16_t CardReader::getnrfilenames
    () {
        curDir=&workDir;
        lsAction=LS_Count;
        nrFiles=0;
        curDir->rewind();
        lsDive("",*curDir);
//SERIAL_ECHOLN(nrFiles);
        return nrFiles;
    }
    void CardReader::chdir
    (const char * relpath) {
        SdFile newfile;
        SdFile *parent=&root;
        if
        (workDir.isOpen())
            parent=&workDir;
        if
        (!newfile.open(*parent,relpath, O_READ)) {
            SERIAL_ECHO_START;
            SERIAL_ECHOPGM(MSG_SD_CANT_ENTER_SUBDIR);
            SERIAL_ECHOLN(relpath);
        } else {
#if defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT)
            workDirParentParent=workDirParent;
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
            if (workDirDepth < MAX_DIR_DEPTH) {
                for (int d = ++workDirDepth; d--;)
                    workDirParents[d+1] = workDirParents[d];
                workDirParents[0]=*parent;
            }
            workDirParent=*parent;
#endif
            workDir=newfile;
        }
    }
    void CardReader::updir
    () {
#if defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT)
        if(!workDir.isRoot()) {
            workDir=workDirParent;
            workDirParent=workDirParentParent;
        }
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
        if(workDirDepth > 0) {
            --workDirDepth;
            workDir = workDirParents[0];
            int d;
            for (int d = 0; d < workDirDepth; d++)
                workDirParents[d] = workDirParents[d+1];
        }
#endif
    }
    void CardReader::printingHasFinished
    () {
        st_synchronize();
#if defined (indi-RichCattell) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT)
        quickStop();
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
        if(file_subcall_ctr>0) { //heading up to a parent file that called current as a procedure.
            file.close();
            file_subcall_ctr--;
            openFile(filenames[file_subcall_ctr],true,true);
            setIndex(filespos[file_subcall_ctr]);
            startFileprint();
        } else {
            quickStop();
            file.close();
            sdprinting = false;
            if(SD_FINISHED_STEPPERRELEASE) {
                //finishAndDisableSteppers();
                enquecommand_P(PSTR(SD_FINISHED_RELEASECOMMAND));
            }
            autotempShutdown();
        }
#endif
#if defined (indi-RichCattell) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT)
        file.close();
#endif
#if defined (indi-RichCattell) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT)
        sdprinting = false;
#endif
#if defined (oliv3r) && defined (SDSUPPORT)
        pause = false;
#endif
#if defined (indi-RichCattell) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT)
        if(SD_FINISHED_STEPPERRELEASE) {
            //finishAndDisableSteppers();
            enquecommand_P(PSTR(SD_FINISHED_RELEASECOMMAND));
        }
        autotempShutdown();
#endif
    }
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (Ognog) || defined (alromh87) || defined (akadamson) || defined (timor) || defined (hampussandberg) || defined (drsdre) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7) || defined (marlin4Due)
//SDSUPPORT
#endif
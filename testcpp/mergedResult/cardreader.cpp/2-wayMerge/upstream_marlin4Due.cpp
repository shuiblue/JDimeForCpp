#if defined (upstream) || defined (marlin4Due)
    #include "Marlin.h"
    #include "cardreader.h"
    #include "ultralcd.h"
    #include "stepper.h"
    #include "temperature.h"
    #include "language.h"
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
CardReader::CardReader
() {
    filesize = 0;
    sdpos = 0;
    sdprinting = false;
    cardOK = false;
    saving = false;
    logging = false;
#if defined (upstream) && defined (SDSUPPORT)
    autostart_atmillis=0;
#endif
    workDirDepth = 0;
    file_subcall_ctr=0;
    memset(workDirParents, 0, sizeof(workDirParents));
    autostart_stilltocheck=true;
//the SD start is delayed, because otherwise the serial cannot answer fast enough to make contact with the host software.
#if defined (upstream) && defined (SDSUPPORT)
    lastnr=0;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
    autostart_index = 0;
#endif
//power to SD reader
#if defined (upstream) && (SDPOWER > -1 && defined (SDSUPPORT) )
    SET_OUTPUT(SDPOWER);
#endif
#if defined (marlin4Due) && (SDPOWER > -1 && defined (SDSUPPORT) )
    OUT_WRITE(SDPOWER, HIGH);
#endif
#if defined (upstream) && (SDPOWER > -1 && defined (SDSUPPORT) )
    WRITE(SDPOWER,HIGH);
#endif
//SDPOWER
#if defined (upstream) && defined (SDSUPPORT)
    autostart_atmillis=millis()+5000;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
    next_autostart_ms = millis() + 5000;
#endif
}
char * createFilename
(char *buffer,const dir_t &p)
#if defined (upstream) && defined (SDSUPPORT)
    //buffer>12characters
#endif
{
#if defined (marlin4Due) && defined (SDSUPPORT)
//buffer > 12characters
#endif
    char *pos=buffer;
    for(uint8_t i = 0; i < 11; i++) {
        if
        (p.name[i] == ' ')
            continue;
        if
        (i == 8) {
#if defined (upstream) && defined (SDSUPPORT)
            *pos++='.';
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)*pos++ = '.';
#endif
        }
        *pos++=p.name[i];
    }
    *pos++=0;
    return buffer;
}
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
    /**
    * Dive into a folder and recurse depth-first to perform a pre-set operation lsAction:
    *   LS_Count       - Add +1 to nrFiles for every file within the parent
    *   LS_GetFilename - Get the filename of the file indexed by nrFiles
    *   LS_SerialPrint - Print the full path of each file to serial output
    */
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
void CardReader::lsDive
(const char *prepend, SdFile parent, const char * const match/*=NULL*/) {
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
#if defined (upstream) && defined (SDSUPPORT)
// hence LS_SerialPrint
#endif
#if defined (upstream) && defined (SDSUPPORT)
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
#if defined (upstream) && defined (SDSUPPORT)
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
#if defined (upstream) && defined (SDSUPPORT)
//close done automatically by destructor of SdFile
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
// close() is done automatically by destructor of SdFile
#endif
        else {
            char pn0 = p.name[0];
            if
            (pn0 == DIR_NAME_FREE)
                break;
            if
#if defined (upstream) && defined (SDSUPPORT)
            (pn0 == DIR_NAME_DELETED || pn0 == '.' || pn0 == '_')
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
                (pn0 == DIR_NAME_DELETED || pn0 == '.')
#endif
                continue;
#if defined (upstream) && defined (SDSUPPORT)
            char lf0 = longFilename[0];
#endif
            if
#if defined (upstream) && defined (SDSUPPORT)
            (lf0 == '.' || lf0 == '_')
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
                (longFilename[0] == '.')
#endif
                continue;
            if
            (!DIR_IS_FILE_OR_SUBDIR(&p))
                continue;
            filenameIsDir=DIR_IS_SUBDIR(&p);
#if defined (upstream) && defined (SDSUPPORT)
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
#if defined (upstream) && defined (SDSUPPORT)
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
#if defined (upstream) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
void CardReader::initsd
() {
    {
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
    }
}
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
    cardOK = false;
}
void CardReader::startFileprint
() {
    if
    (cardOK) {
        sdprinting = true;
    }
}
void CardReader::pauseSDPrint
() {
    if
    (sdprinting) {
#if defined (upstream) && defined (SDSUPPORT)
        sdprinting = false;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)sdprinting = false;
#endif
    }
}
void CardReader::openLogFile
(char* name) {
    logging = true;
    openFile(name, false);
}
void CardReader::getAbsFilename
(char *t) {
    uint8_t cnt=0;
    *t='/';
    t++;
    cnt++;
#if defined (upstream) && defined (SDSUPPORT)
    for(uint8_t i=0; i<workDirDepth; i++) {
        workDirParents[i].getFilename(t); //SDBaseFile.getfilename!
        while(*t!=0 && cnt< MAXPATHNAMELENGTH) {
            t++;    //crawl counter forward.
            cnt++;
        }
    }
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
    for (uint8_t i = 0; i < workDirDepth; i++) {
        workDirParents[i].getFilename(t); //SDBaseFile.getfilename!
        while(*t && cnt < MAXPATHNAMELENGTH) {
            t++;    //crawl counter forward.
            cnt++;
        }
    }
#endif
    if
#if defined (upstream) && defined (SDSUPPORT)
    (cnt<MAXPATHNAMELENGTH-13)
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
        (cnt < MAXPATHNAMELENGTH - FILENAME_LENGTH)
#endif
        file.getFilename(t);
    else
        t[0]=0;
}
void CardReader::openFile
(char* name,bool read, bool replace_current/*=true*/) {
    if
    (!cardOK)
        return;
    if
    (file.isOpen())
#if defined (upstream) && defined (SDSUPPORT)
//replacing current file by new file, or subfile call
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
//replacing current file by new file, or subfile call
#endif
        if
        (!replace_current) {
#if defined (upstream) && defined (SDSUPPORT)
            if((int)file_subcall_ctr>(int)SD_PROCEDURE_DEPTH-1) {
                SERIAL_ERROR_START;
                SERIAL_ERRORPGM("trying to call sub-gcode files with too many levels. MAX level is:");
                SERIAL_ERRORLN(SD_PROCEDURE_DEPTH);
                kill();
                return;
            }
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
            if (file_subcall_ctr > SD_PROCEDURE_DEPTH - 1) {
                SERIAL_ERROR_START;
                SERIAL_ERRORPGM("trying to call sub-gcode files with too many levels. MAX level is:");
                SERIAL_ERRORLN(SD_PROCEDURE_DEPTH);
                kill(PSTR(MSG_KILLED));
                return;
            }
#endif
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
#endif
    else {
#if defined (upstream) && defined (SDSUPPORT)
//opening fresh file
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
//opening fresh file
#endif
        file_subcall_ctr=0;
//resetting procedure depth in case user cancels print while in procedure
        SERIAL_ECHO_START;
        SERIAL_ECHOPGM("Now fresh file: ");
        SERIAL_ECHOLN(name);
    }
    sdprinting = false;
    SdFile myDir;
    curDir=&root;
    char *fname=name;
    char *dirname_start,*dirname_end;
    if
    (name[0]=='/') {
#if defined (upstream) && defined (SDSUPPORT)
        dirname_start=strchr(name,'/')+1;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
        dirname_start = &name[1];
#endif
        while
        (dirname_start>0) {
            dirname_end=strchr(dirname_start,'/');
//SERIAL_ECHO("start:");SERIAL_ECHOLN((int)(dirname_start-name));
//SERIAL_ECHO("end  :");SERIAL_ECHOLN((int)(dirname_end-name));
            if
            (dirname_end>0 && dirname_end>dirname_start) {
#if defined (upstream) && defined (SDSUPPORT)
                char subdirname[13];
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
                char subdirname[FILENAME_LENGTH];
#endif
                strncpy(subdirname, dirname_start, dirname_end-dirname_start);
                subdirname[dirname_end-dirname_start]=0;
                SERIAL_ECHOLN(subdirname);
                if
                (!myDir.open(curDir,subdirname,O_READ)) {
                    SERIAL_PROTOCOLPGM(MSG_SD_OPEN_FILE_FAIL);
                    SERIAL_PROTOCOL(subdirname);
#if defined (upstream) && defined (SDSUPPORT)
                    SERIAL_PROTOCOLLNPGM(".");
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
                    SERIAL_PROTOCOLCHAR('.');
#endif
                    return;
                } else {
//SERIAL_ECHOLN("dive ok");
                }
                curDir=&myDir;
                dirname_start=dirname_end+1;
            } else {
#if defined (upstream) && defined (SDSUPPORT)
// the reminder after all /fsa/fdsa/ is the filename
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
// the remainder after all /fsa/fdsa/ is the filename
#endif
                fname=dirname_start;
#if defined (upstream) && defined (SDSUPPORT)
//SERIAL_ECHOLN("remaider");
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
//SERIAL_ECHOLN("remainder");
#endif
//SERIAL_ECHOLN(fname);
                break;
            }
        }
    } else {
#if defined (upstream) && defined (SDSUPPORT)
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
            getfilename(0, fname);
            lcd_setstatus(longFilename[0] ? longFilename : fname);
        } else {
            SERIAL_PROTOCOLPGM(MSG_SD_OPEN_FILE_FAIL);
            SERIAL_PROTOCOL(fname);
#if defined (upstream) && defined (SDSUPPORT)
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
#if defined (upstream) && defined (SDSUPPORT)
            SERIAL_PROTOCOLLNPGM(".");
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
            SERIAL_PROTOCOLPGM(".\n");
#endif
        } else {
            saving = true;
            SERIAL_PROTOCOLPGM(MSG_SD_WRITE_TO_FILE);
            SERIAL_PROTOCOLLN(name);
            lcd_setstatus(fname);
        }
    }
}
void CardReader::removeFile
(char* name) {
    if
    (!cardOK)
        return;
    file.close();
    sdprinting = false;
    SdFile myDir;
    curDir=&root;
    char *fname=name;
    char *dirname_start,*dirname_end;
    if
    (name[0]=='/') {
        dirname_start=strchr(name,'/')+1;
        while
        (dirname_start>0) {
            dirname_end=strchr(dirname_start,'/');
//SERIAL_ECHO("start:");SERIAL_ECHOLN((int)(dirname_start-name));
//SERIAL_ECHO("end  :");SERIAL_ECHOLN((int)(dirname_end-name));
            if
            (dirname_end>0 && dirname_end>dirname_start) {
#if defined (upstream) && defined (SDSUPPORT)
                char subdirname[13];
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
                char subdirname[FILENAME_LENGTH];
#endif
                strncpy(subdirname, dirname_start, dirname_end-dirname_start);
                subdirname[dirname_end-dirname_start]=0;
                SERIAL_ECHOLN(subdirname);
                if
                (!myDir.open(curDir,subdirname,O_READ)) {
                    SERIAL_PROTOCOLPGM("open failed, File: ");
                    SERIAL_PROTOCOL(subdirname);
#if defined (upstream) && defined (SDSUPPORT)
                    SERIAL_PROTOCOLLNPGM(".");
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
                    SERIAL_PROTOCOLCHAR('.');
#endif
                    return;
                } else {
//SERIAL_ECHOLN("dive ok");
                }
                curDir=&myDir;
                dirname_start=dirname_end+1;
            } else {
#if defined (upstream) && defined (SDSUPPORT)
// the reminder after all /fsa/fdsa/ is the filename
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
// the remainder after all /fsa/fdsa/ is the filename
#endif
                fname=dirname_start;
#if defined (upstream) && defined (SDSUPPORT)
//SERIAL_ECHOLN("remaider");
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
//SERIAL_ECHOLN("remainder");
#endif
//SERIAL_ECHOLN(fname);
                break;
            }
        }
    } else {
#if defined (upstream) && defined (SDSUPPORT)
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
        SERIAL_PROTOCOLLN(fname);
        sdpos = 0;
    } else {
        SERIAL_PROTOCOLPGM("Deletion failed, File: ");
        SERIAL_PROTOCOL(fname);
#if defined (upstream) && defined (SDSUPPORT)
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
#if defined (upstream) && defined (SDSUPPORT)
        SERIAL_PROTOCOLPGM("/");
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
        SERIAL_PROTOCOLCHAR('/');
#endif
        SERIAL_PROTOCOLLN(filesize);
    } else {
        SERIAL_PROTOCOLLNPGM(MSG_SD_NOT_PRINTING);
    }
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
void CardReader::checkautostart
(bool force) {
#if defined (upstream) && defined (SDSUPPORT)
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
#if defined (upstream) && defined (SDSUPPORT)
//fail
#endif
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
// fail
#endif
        }
#if defined (upstream) && defined (SDSUPPORT)
    char autoname[30];
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
    char autoname[10];
#endif
#if defined (upstream) && defined (SDSUPPORT)
    sprintf_P(autoname, PSTR("auto%i.g"), lastnr);
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
    sprintf_P(autoname, PSTR("auto%i.g"), autostart_index);
#endif
#if defined (upstream) && defined (SDSUPPORT)
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
#if defined (upstream) && defined (SDSUPPORT)
        for(int8_t i=0; i<(int8_t)strlen((char*)p.name); i++)
            p.name[i]=tolower(p.name[i]);
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
        for (int8_t i = 0; i < (int8_t)strlen((char*)p.name); i++) p.name[i] = tolower(p.name[i]);
#endif
#if defined (upstream) && defined (SDSUPPORT)
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
#if defined (upstream) && defined (SDSUPPORT)
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
#if defined (upstream) && defined (SDSUPPORT)
        lastnr=-1;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
    autostart_index = -1;
#endif
    else
#if defined (upstream) && defined (SDSUPPORT)
        lastnr++;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
    autostart_index++;
#endif
}
void CardReader::closefile
(bool store_location) {
    file.sync();
    file.close();
#if defined (upstream) && defined (SDSUPPORT)
    saving = false;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
    saving = logging = false;
#endif
#if defined (upstream) && defined (SDSUPPORT)
    logging = false;
#endif
    if
    (store_location) {
//future: store printer state, filename and position for continuing a stopped print
// so one can unplug the printer and continue printing the next day.
    }
}
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
    /**
    * Get the name of a file in the current directory by index
    */
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (marlin4Due) && defined (SDSUPPORT)
void CardReader::getfilename
(uint16_t nr, const char * const match/*=NULL*/) {
    curDir=&workDir;
    lsAction=LS_GetFilename;
    nrFiles=nr;
    curDir->rewind();
    lsDive("",*curDir,match);
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
        if
        (workDirDepth < MAX_DIR_DEPTH) {
#if defined (upstream) && defined (SDSUPPORT)
            for (int d = ++workDirDepth; d--;)
                workDirParents[d+1] = workDirParents[d];
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
            ++workDirDepth;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
            for (int d = workDirDepth; d--;) workDirParents[d + 1] = workDirParents[d];
#endif
            workDirParents[0]=*parent;
        }
        workDir=newfile;
    }
}
void CardReader::updir
() {
    if
    (workDirDepth > 0) {
        --workDirDepth;
        workDir = workDirParents[0];
#if defined (upstream) && defined (SDSUPPORT)
        int d;
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
        for (uint16_t d = 0; d < workDirDepth; d++)
            workDirParents[d] = workDirParents[d+1];
        for (int d = 0; d < workDirDepth; d++)
            workDirParents[d] = workDirParents[d+1];
#endif
    }
}
void CardReader::printingHasFinished
() {
    st_synchronize();
    if
    (file_subcall_ctr>0)
#if defined (upstream) && defined (SDSUPPORT)
//heading up to a parent file that called current as a procedure.
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
// Heading up to a parent file that called current as a procedure.
#endif
        file.close();
    file_subcall_ctr--;
    openFile(filenames[file_subcall_ctr],true,true);
    setIndex(filespos[file_subcall_ctr]);
#endif
    else {
#if defined (upstream) && defined (SDSUPPORT)
        quickStop();
#endif
        file.close();
        sdprinting = false;
        if
        (SD_FINISHED_STEPPERRELEASE) {
//finishAndDisableSteppers();
#if defined (upstream) && defined (SDSUPPORT)
            enquecommand_P(PSTR(SD_FINISHED_RELEASECOMMAND));
#endif
#if defined (marlin4Due) && defined (SDSUPPORT)
            enqueuecommands_P(PSTR(SD_FINISHED_RELEASECOMMAND));
#endif
        }
        autotempShutdown();
    }
}
#endif
#if defined (upstream) || defined (marlin4Due)
    //SDSUPPORT
#endif
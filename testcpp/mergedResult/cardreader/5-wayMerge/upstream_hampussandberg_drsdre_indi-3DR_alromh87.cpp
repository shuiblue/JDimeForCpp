#if defined (A) || defined (B) || defined (C) || defined (D) || defined (E)
    #include "Marlin.h"
    #include "cardreader.h"
    #include "ultralcd.h"
    #include "stepper.h"
    #include "temperature.h"
    #include "language.h"
#endif
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT) || defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
CardReader::CardReader
() {
    filesize = 0;
    sdpos = 0;
    sdprinting = false;
    cardOK = false;
    saving = false;
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
    logging = false;
#endif
    autostart_atmillis=0;
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
    workDirDepth = 0;
    file_subcall_ctr=0;
    memset(workDirParents, 0, sizeof(workDirParents));
#endif
    autostart_stilltocheck=true;
#if defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT)
//the sd start is delayed, because otherwise the serial cannot answer fast enought to make contact with the hostsoftware.
#endif
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
//the SD start is delayed, because otherwise the serial cannot answer fast enough to make contact with the host software.
#endif
    lastnr=0;
//power to SD reader
#if defined (A) && (SDPOWER > -1 && defined (SDSUPPORT) ) || defined (B) && (SDPOWER > -1 && defined (SDSUPPORT) ) || defined (C) && (SDPOWER > -1 && defined (SDSUPPORT) ) || defined (D) && (SDPOWER > -1 && defined (SDSUPPORT) ) || defined (E) && (SDPOWER > -1 && defined (SDSUPPORT) )
    SET_OUTPUT(SDPOWER);
    WRITE(SDPOWER,HIGH);
#endif
//SDPOWER
    autostart_atmillis=millis()+5000;
}
char * createFilename
(char *buffer,const dir_t &p)
//buffer>12characters
{
    char *pos=buffer;
    for(uint8_t i = 0; i < 11; i++) {
        if
        (p.name[i] == ' ')
            continue;
        if
        (i == 8) {
            *pos++='.';
        }
        *pos++=p.name[i];
    }
    *pos++=0;
    return buffer;
}
void CardReader::lsDive
#if defined (A) && defined (SDSUPPORT)
    (const char *prepend, SdFile parent, const char * const match/*=NULL*/)
#endif
#if defined (B) && defined (SDSUPPORT) || defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)

    (const char *prepend,SdFile parent)
#endif
{
    dir_t p;
    uint8_t cnt=0;
    while
    (parent.readDir(p, longFilename) > 0) {
        if
        ( DIR_IS_SUBDIR(&p) && lsAction!=LS_Count && lsAction!=LS_GetFilename)
// hence LS_SerialPrint
            char path[13*2];
        char lfilename[13];
        createFilename(lfilename,p);
        path[0]=0;
        if
        (strlen(prepend)==0)
//avoid leading / if already in prepend
            strcat(path,"/");
        strcat(path,prepend);
        strcat(path,lfilename);
        strcat(path,"/");
//Serial.print(path);
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
//close done automatically by destructor of SdFile
        else {
#if defined (A) && defined (SDSUPPORT)
            char pn0 = p.name[0];
#endif
            if
#if defined (A) && defined (SDSUPPORT)
            (pn0 == DIR_NAME_FREE)
#endif
#if defined (B) && defined (SDSUPPORT) || defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
                (p.name[0] == DIR_NAME_FREE)
#endif
                break;
            if
#if defined (A) && defined (SDSUPPORT)
            (pn0 == DIR_NAME_DELETED || pn0 == '.' || pn0 == '_')
#endif
#if defined (B) && defined (SDSUPPORT) || defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
                (p.name[0] == DIR_NAME_DELETED || p.name[0] == '.'|| p.name[0] == '_')
#endif
                continue;
#if defined (A) && defined (SDSUPPORT)
            char lf0 = longFilename[0];
#endif
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT) || defined (C) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
            if (lf0 == '.' || lf0 == '_') continue;
#endif
#if defined (B) && defined (SDSUPPORT) || defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
            if ( p.name[0] == '.') {
                if ( p.name[1] != '.')
                    continue;
            }
#endif
            if
            (!DIR_IS_FILE_OR_SUBDIR(&p))
                continue;
            filenameIsDir=DIR_IS_SUBDIR(&p);
            if
            (!filenameIsDir) {
                if
                (p.name[8]!='G')
                    continue;
                if
                (p.name[9]=='~')
                    continue;
            }
//if(cnt++!=nr) continue;
            createFilename(filename,p);
            if
            (lsAction==LS_SerialPrint) {
                SERIAL_PROTOCOL(prepend);
                SERIAL_PROTOCOLLN(filename);
            } else if
            (lsAction==LS_Count) {
                nrFiles++;
            } else if
            (lsAction==LS_GetFilename) {
#if defined (A) && defined (SDSUPPORT)
                if (match != NULL) {
                    if (strcasecmp(match, filename) == 0) return;
                } else if (cnt == nrFiles) return;
#endif
#if defined (B) && defined (SDSUPPORT) || defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
                if(cnt==nrFiles)
                    return;
#endif
                cnt++;
            }
        }
    }
}
void CardReader::ls
() {
    lsAction=LS_SerialPrint;
    if
    (lsAction==LS_Count)
        nrFiles=0;
    root.rewind();
    lsDive("",root);
}
void CardReader::initsd
() {
#if defined (A) && defined (SDSUPPORT)
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
#if defined (B) && defined (SDSUPPORT) || defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT)
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
#if defined (E) && defined (SDSUPPORT)
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
            sdprinting = false;
        }
    }
#endif
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
    void CardReader::openLogFile(char* name) {
        logging = true;
        openFile(name, false);
    }
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
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT) || defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
    void CardReader::openFile
#if defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT)
    (char* name,bool read)
#endif
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
    (char* name,bool read, bool replace_current/*=true*/)
#endif
    {
        if
        (!cardOK)
            return;
#if defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT)
        file.close();
#endif
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
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
                    char subdirname[13];
                    strncpy(subdirname, dirname_start, dirname_end-dirname_start);
                    subdirname[dirname_end-dirname_start]=0;
                    SERIAL_ECHOLN(subdirname);
                    if
                    (!myDir.open(curDir,subdirname,O_READ)) {
                        SERIAL_PROTOCOLPGM(MSG_SD_OPEN_FILE_FAIL);
                        SERIAL_PROTOCOL(subdirname);
                        SERIAL_PROTOCOLLNPGM(".");
                        return;
                    } else {
//SERIAL_ECHOLN("dive ok");
                    }
                    curDir=&myDir;
                    dirname_start=dirname_end+1;
                } else {
// the reminder after all /fsa/fdsa/ is the filename
                    fname=dirname_start;
//SERIAL_ECHOLN("remaider");
//SERIAL_ECHOLN(fname);
                    break;
                }
            }
        } else {
//relative path
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
#if defined (A) && defined (SDSUPPORT)
                getfilename(0, fname);
#endif
#if defined (B) && defined (SDSUPPORT) || defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
                lcd_setstatus(fname);
                lcd_setstatus(longFilename[0] ? longFilename : fname);
#endif
            } else {
                SERIAL_PROTOCOLPGM(MSG_SD_OPEN_FILE_FAIL);
                SERIAL_PROTOCOL(fname);
                SERIAL_PROTOCOLLNPGM(".");
            }
        } else {
//write
            if
            (!file.open(curDir, fname, O_CREAT | O_APPEND | O_WRITE | O_TRUNC)) {
                SERIAL_PROTOCOLPGM(MSG_SD_OPEN_FILE_FAIL);
                SERIAL_PROTOCOL(fname);
                SERIAL_PROTOCOLLNPGM(".");
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
                    char subdirname[13];
                    strncpy(subdirname, dirname_start, dirname_end-dirname_start);
                    subdirname[dirname_end-dirname_start]=0;
                    SERIAL_ECHOLN(subdirname);
                    if
                    (!myDir.open(curDir,subdirname,O_READ)) {
                        SERIAL_PROTOCOLPGM("open failed, File: ");
                        SERIAL_PROTOCOL(subdirname);
                        SERIAL_PROTOCOLLNPGM(".");
                        return;
                    } else {
//SERIAL_ECHOLN("dive ok");
                    }
                    curDir=&myDir;
                    dirname_start=dirname_end+1;
                } else {
// the reminder after all /fsa/fdsa/ is the filename
                    fname=dirname_start;
//SERIAL_ECHOLN("remaider");
//SERIAL_ECHOLN(fname);
                    break;
                }
            }
        } else {
//relative path
            curDir=&workDir;
        }
        if
        (file.remove(curDir, fname)) {
            SERIAL_PROTOCOLPGM("File deleted:");
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT)
            SERIAL_PROTOCOLLN(fname);
#endif
#if defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
            SERIAL_PROTOCOL(fname);
#endif
            sdpos = 0;
        } else {
            SERIAL_PROTOCOLPGM("Deletion failed, File: ");
            SERIAL_PROTOCOL(fname);
            SERIAL_PROTOCOLLNPGM(".");
        }
    }
    void CardReader::getStatus
    () {
        if
        (cardOK) {
            SERIAL_PROTOCOLPGM(MSG_SD_PRINTING_BYTE);
            SERIAL_PROTOCOL(sdpos);
            SERIAL_PROTOCOLPGM("/");
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
        if
        (!force) {
            if
            (!autostart_stilltocheck)
                return;
            if
            (autostart_atmillis<millis())
                return;
        }
        autostart_stilltocheck=false;
        if
        (!cardOK) {
            initsd();
            if
            (!cardOK)
//fail
                return;
        }
        char autoname[30];
        sprintf_P(autoname, PSTR("auto%i.g"), lastnr);
        for(int8_t i=0; i<(int8_t)strlen(autoname); i++)
            dir_t p;
        root.rewind();
        bool found=false;
        while
        (root.readDir(p, NULL) > 0) {
            for(int8_t i=0; i<(int8_t)strlen((char*)p.name); i++)
//Serial.print((char*)p.name);
//Serial.print(" ");
//Serial.println(autoname);
                if
                (p.name[9]!='~')
//skip safety copies
                    if
                    (strncmp((char*)p.name,autoname,5)==0) {
                        char cmd[30];
                        sprintf_P(cmd, PSTR("M23 %s"), autoname);
                        enquecommand(cmd);
                        enquecommand_P(PSTR("M24"));
                        found=true;
                    }
        }
        if
        (!found)
            lastnr=-1;
        else
            lastnr++;
    }
    void CardReader::closefile
#if defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT)
    ()
#endif
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
    (bool store_location)
#endif
    {
        file.sync();
        file.close();
        saving = false;
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
        logging = false;
        if(store_location) {
            //future: store printer state, filename and position for continuing a stopped print
            // so one can unplug the printer and continue printing the next day.
        }
#endif
    }
    void CardReader::getfilename
#if defined (A) && defined (SDSUPPORT)
    (uint16_t nr, const char * const match/*=NULL*/)
#endif
#if defined (B) && defined (SDSUPPORT) || defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
    (const uint8_t nr)
#endif
    {
        curDir=&workDir;
        lsAction=LS_GetFilename;
        nrFiles=nr;
        curDir->rewind();
#if defined (A) && defined (SDSUPPORT)
        lsDive("",*curDir,match);
#endif
#if defined (B) && defined (SDSUPPORT) || defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
        lsDive("",*curDir);
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
#if defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT)
            workDirParentParent=workDirParent;
#endif
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
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
#if defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT)
        if(!workDir.isRoot()) {
            workDir=workDirParent;
            workDirParent=workDirParentParent;
        }
#endif
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
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
#if defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT)
        quickStop();
#endif
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT) || defined (E) && defined (SDSUPPORT)
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
#if defined (C) && defined (SDSUPPORT) || defined (D) && defined (SDSUPPORT)
        file.close();
        sdprinting = false;
        if(SD_FINISHED_STEPPERRELEASE) {
            //finishAndDisableSteppers();
            enquecommand_P(PSTR(SD_FINISHED_RELEASECOMMAND));
        }
        autotempShutdown();
#endif
    }
#endif
#if defined (A) || defined (B) || defined (C) || defined (D) || defined (E)
//SDSUPPORT
#endif
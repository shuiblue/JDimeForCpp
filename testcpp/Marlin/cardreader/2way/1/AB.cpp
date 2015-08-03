#if defined (A) || defined (B)
void CardReader::lsDive
#if defined (A)
(const char *prepend, SdFile parent, const char * const match/*=NULL*/)
#endif
#if defined (B)
(const char *prepend,SdFile parent)
#endif
{
    dir_t p;
    uint8_t cnt=0;
    while
    (parent.readDir(p, longFilename) > 0) {
        if ( DIR_IS_SUBDIR(&p) && lsAction!=LS_Count && lsAction!=LS_GetFilename) {
// hence LS_SerialPrint
            char path[13*2];
            char lfilename[13];
            createFilename(lfilename,p);
            path[0]=0;
            if (strlen(prepend)==0) {
//avoid leading / if already in prepend
                strcat(path,"/");
            }
            strcat(path,prepend);
            strcat(path,lfilename);
            strcat(path,"/");
//Serial.print(path);
            SdFile dir;
            if (!dir.open(parent,lfilename, O_READ)) {
                if (lsAction==LS_SerialPrint) {
                    SERIAL_ECHO_START;
                    SERIAL_ECHOLN(MSG_SD_CANT_OPEN_SUBDIR);
                    SERIAL_ECHOLN(lfilename);
                }
            }
            lsDive(path,dir);
//close done automatically by destructor of SdFile
        }
#if defined (A)
        char pn0 = p.name[0];
#endif
#if defined (B)
        if (p.name[0] == DIR_NAME_FREE) break;
#endif
#if defined (A)
        if (pn0 == DIR_NAME_FREE) break;
#endif
#if defined (B)
        if (p.name[0] == DIR_NAME_DELETED || p.name[0] == '.'|| p.name[0] == '_') continue;
#endif
#if defined (A)
        if (pn0 == DIR_NAME_DELETED || pn0 == '.' || pn0 == '_') continue;
#endif
#if defined (B)
        if (longFilename[0] != '\0' &&
                (longFilename[0] == '.' || longFilename[0] == '_')) continue;
#endif
#if defined (A)
        char lf0 = longFilename[0];
#endif
#if defined (B)
        if ( p.name[0] == '.') {
            if ( p.name[1] != '.')
                continue;
        }
#endif
#if defined (A)
        if (lf0 == '.' || lf0 == '_') continue;
#endif
        if (!DIR_IS_FILE_OR_SUBDIR(&p)) {
            continue;
        }
        filenameIsDir=DIR_IS_SUBDIR(&p);
        if (!filenameIsDir) {
            if (p.name[8]!='G') {
                continue;
            }
            if (p.name[9]=='~') {
                continue;
            }
        }
//if(cnt++!=nr) continue;
        createFilename(filename,p);
        if (lsAction==LS_SerialPrint) {
            SERIAL_PROTOCOL(prepend);
            SERIAL_PROTOCOLLN(filename);
        } else if (lsAction==LS_Count) {
            nrFiles++;
        } else if (lsAction==LS_GetFilename) {
#if defined (A)
            if (match != NULL) {
                if (strcasecmp(match, filename) == 0) return;
            } else if (cnt == nrFiles) return;
#endif
#if defined (B)
            if(cnt==nrFiles)
                return;
#endif
#endif
#endif
        }
    }
#endif
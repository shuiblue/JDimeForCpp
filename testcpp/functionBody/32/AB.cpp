#if defined (A) || defined (B)
char * createFilename
(char *buffer,const dir_t &p)
//buffer>12characters
{
    char *pos=buffer;
    for(uint8_ti=0; i<11; i++) {
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


#endif

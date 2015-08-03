#if defined (A) || defined (B)
void a() {
    for(i=0; i<max; i++) {
        if ( line[i] == ' ' ) {
#if defined (A)
            aaa++;
#endif
#if defined (B)
            space++;
#endif
        }
        if ( line[i] == '\t' ) {
            tab++;
        }
    }
}
#endif

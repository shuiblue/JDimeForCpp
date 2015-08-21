#if defined (A) || defined (B)
void a
() {
    a=0;
#if defined (A) && defined (X) || defined (B)
    while
    ( i >= 0 ) {
#if defined (A) && defined (X)
        string1[i] = string2[i];
#endif
#if defined (B)
        string1[x] = string2[x];
#endif
    }
#endif
}
#endif

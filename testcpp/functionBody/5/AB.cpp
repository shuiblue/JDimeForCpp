#if defined (A)
    int x=0;
#endif
#if defined (A) || defined (B)
void a
() {
#if defined (A) && defined (X)
    i=0;
#endif
#if defined (B)
    i=1;
#endif
#if defined (A)
    j=2;
#endif
}
#endif

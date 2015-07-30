#if defined (A) || defined (B)
void a() {
#if defined (A)
    i=0;
#endif
#if defined (B)
    i=2;
    j=0;
#endif
}
#endif

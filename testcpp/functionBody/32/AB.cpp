#if defined (A) || defined (B) || defined (C) || defined (D)
void a
() {
#if defined (A)
    a=0;
#endif
#if defined (B)
    b=0;
#endif
#if defined (C)
    c=0;
#endif
#if defined (D)
    int d=0;
#endif
}
#endif

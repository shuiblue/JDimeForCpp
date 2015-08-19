#if defined (A) || defined (B) || defined (C)
void a
() {
#if defined (A)
    a=0;
#endif
#if defined (B || C)
    b=0;
#endif
}
#endif

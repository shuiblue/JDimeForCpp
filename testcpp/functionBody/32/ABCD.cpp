#if defined (A) || defined (B) || defined (C)
void a
() {
#if defined (A)
    int a =0;
#endif
#if defined (B || C)
    int b=0;
#endif
}
#endif

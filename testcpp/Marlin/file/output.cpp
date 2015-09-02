#if defined (A) || defined (B)
void a
() {
    a++;
#if defined (A)
    b++;
#endif
}
#endif

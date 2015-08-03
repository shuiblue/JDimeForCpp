#if defined (A) || defined (B)
void a() {
    if
#if defined (A)
    (x > 5)
#endif
#if defined (B)
        (x > 4)
#endif
    {
        y+=4
    }
}
#endif

#if defined (A)
void a() {
#ifdef SDSLOW
    if (X)
#else
    if (Y)
#endif
    {
        cardOK = true;
    }
}
#endif
#if defined (B)
void b() {
#ifdef SDSLOW
    if (z)
#else
    if (b)
#endif
    {
        cardOK = true;
    }
}
#endif

#if defined (A) || defined (B)
void a() {
#if defined (A)
#ifdef SDSLOW
    if (X)
#else
    if (Y)
#endif
    {
        cardOK = true;
    }
#endif
#if defined (B)
#ifdef SDSLOW
    if (z)
#else
    if (Y)
#endif
    {
        cardOK = true;
    }
#endif
}
#endif

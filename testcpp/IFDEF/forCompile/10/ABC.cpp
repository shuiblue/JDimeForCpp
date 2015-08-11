#if defined (A) && defined (X) || defined (B) && defined (X)
    void a();
#endif
#if defined (C)
    void c();
#endif
#if defined (A) || defined (B) && defined (Y)
    void b();
#endif

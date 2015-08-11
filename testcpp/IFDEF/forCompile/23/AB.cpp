#if defined (A) && defined (X)
    void a();
#endif
#if defined (B)
    void b();
#endif
#if defined (A) && !defined (X)
    void t();
#endif

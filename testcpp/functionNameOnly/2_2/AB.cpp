#if defined (A)
    void a();
#endif
#if defined (A) || defined (B)
    void x();
#endif
#if defined (B)
    void b();
#endif

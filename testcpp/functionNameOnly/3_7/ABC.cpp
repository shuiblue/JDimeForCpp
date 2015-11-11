#if defined (A)
    void a();
#endif
#if defined (C)
    void c();
#endif
#if defined (A) || defined (B) || defined (C)
    void x();
#endif
#if defined (B)
    void b();
#endif
#if defined (A) || defined (B)

    void y();
#endif

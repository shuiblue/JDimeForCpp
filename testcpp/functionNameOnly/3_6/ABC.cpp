#if defined (A)
    void a();
#endif
#if defined (C)
    void bc();
#endif
#if defined (A) || defined (B) || defined (C)
    void x();
#endif
#if defined (B)
    void bc();
#endif

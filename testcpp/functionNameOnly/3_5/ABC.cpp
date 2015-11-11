#if defined (A)
    void a();
#endif
#if defined (A) || defined (B) || defined (C)
    void x();
#endif
#if defined (B) || defined (C)

    void bc();
#endif

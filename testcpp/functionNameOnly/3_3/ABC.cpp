#if defined (A) || defined (B) || defined (C)
    void x();
#endif
#if defined (A) || defined (B)

    void ab();
#endif
#if defined (C)
    void c();
#endif

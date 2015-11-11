#if defined (A) || defined (B) || defined (C) || defined (D)
    void x();
#endif
#if defined (A) || defined (B)

    void ab();
#endif
#if defined (C)
    void c();
#endif
#if defined (D)
    void d();
#endif

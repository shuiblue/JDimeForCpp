#if defined (A) || defined (B) || defined (C) || defined (D)
    void x();
#endif
#if defined (A) || defined (B) || defined (C)

    void abc();
#endif
#if defined (D)
    void d();
#endif

#if defined (A) || defined (B) || defined (C) || defined (D)
    void x();
#endif
#if defined (B)
    void b();
#endif
#if defined (A) || defined (C)

    void ac();
#endif
#if defined (D)
    void d();
#endif

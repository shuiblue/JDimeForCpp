#if defined (A) || defined (B) || defined (C)
    void x();
#endif
#if defined (B)
    void b();
#endif
#if defined (A) || defined (C)

    void ac();
#endif

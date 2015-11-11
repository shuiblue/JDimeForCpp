#if defined (A) || defined (B) || defined (C) || defined (D)
    void x();
#endif
#if defined (A) || defined (C)

    void ac();
#endif
#if defined (B) || defined (D)

    void bd();
#endif

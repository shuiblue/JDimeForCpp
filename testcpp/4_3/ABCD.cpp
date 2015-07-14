#ifdef A || B || C
void x();
#endif
#ifdef B
void bd();
#endif
#ifdef A || C
void ac();
#endif

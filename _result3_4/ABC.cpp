#ifdef A || B || C
void x();
#endif
#ifdef B
void b();
#endif
#ifdef A || C
void ac();
#endif

#ifdef A
void a();
#endif
#ifdef A || B || C
void x();
#endif
#ifdef B || C
void bc();
#endif

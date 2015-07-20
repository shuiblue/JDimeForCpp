#ifdef A
void a();
#endif
#ifdef C
void bc();
#endif
#ifdef A || B || C
void x();
#endif
#ifdef B
void bc();
#endif

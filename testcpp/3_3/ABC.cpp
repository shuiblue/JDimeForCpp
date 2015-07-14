#ifdef A || B || C
void x();
#endif
#ifdef A
void ab();
#endif
#ifdef C
void c();
#endif

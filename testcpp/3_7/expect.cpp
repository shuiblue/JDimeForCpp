#ifdef A
void a();
#endif
#ifdef C
void c();
#endif
#ifdef A || B || C
void x();
#endif
#ifdef A || B
void y();
#endif

#ifdef A
void a();
#endif
#ifdef A || B
void x();
#endif
#ifdef B
void b();
#endif

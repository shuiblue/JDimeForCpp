#ifdef A || B || C || D
void x();
#endif
#ifdef B
void b();
#endif
#ifdef A || C
#ifdef D
void d();
#endif

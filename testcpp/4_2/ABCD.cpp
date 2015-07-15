#ifdef A || B || C || D
void x();
#endif
#ifdef B
void b();
#endif
#ifdef A || C
void ac();
#endif
#ifdef D
void d();
#endif

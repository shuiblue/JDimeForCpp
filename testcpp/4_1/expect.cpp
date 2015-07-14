#ifdef A || B || C || D
void x();
#endif
#ifdef A
void ab();
#endif
#ifdef C
void c();
#endif
#ifdef D
void d();
#endif

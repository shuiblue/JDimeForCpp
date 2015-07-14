#ifdef A || B || C || D
void x();
#endif
#ifdef A || B
void ab();
#endif
#ifdef C
void c();
#endif
#ifdef D
void d();
#endif

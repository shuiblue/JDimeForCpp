#ifdef A || B || C || D
void x();
#endif
#ifdef A
void abc();
#endif
#ifdef D
void d();
#endif

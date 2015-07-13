#ifdef (A||B||C)
void x();
#endif
#ifdef A||B
void ab();
#endif
#ifdef C
void c();
#endif
#ifdef (A||B||C||D)
void x();
#endif
#ifdef A||B||C
void abc();
#endif
#ifdef D
void d();
#endif

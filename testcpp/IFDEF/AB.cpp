#ifdef A
#ifdef X
#endif
#ifdef A && X || B
void a();
#endif
#ifdef A
#endif
#endif
#ifdef B
void b();
#endif

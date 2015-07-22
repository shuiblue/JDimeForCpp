#if defined (A) && defined (X) || defined (B) && defined (X)
void a();
#endif
#if defined (A)
void b();
#endif
#if defined (B)
void c();
#endif

#if defined (A) && defined (X)
void a();
#endif
#if defined (B) && defined (Y)
void b();
#endif
#if defined (A) && !defined (X)
void t();
#endif
#if defined (B) && !defined (Y)
void s();
#endif

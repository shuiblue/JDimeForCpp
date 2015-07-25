#if defined (A) && defined (X)
void a();
#if defined (B)
void b();
#if defined (A) && !defined (X)
void t();
#endif

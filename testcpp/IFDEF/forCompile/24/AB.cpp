#if defined (A) && defined (X)
void a();
#if defined (B) && defined (Y)
void b();
#if defined (A) && !defined (X)
void t();
#if defined (B) && !defined (Y)
void s();
#endif

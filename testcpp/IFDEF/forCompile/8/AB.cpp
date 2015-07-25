#if defined (A) && defined (X) || defined (B) && defined (X)
void a();
#if defined (A)
void b();
#if defined (B)
void c();
#endif

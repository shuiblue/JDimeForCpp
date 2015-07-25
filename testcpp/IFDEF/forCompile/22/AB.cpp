#if defined (A)
#define P 0
#endif
#if defined (B)
void b();
#endif
#if defined (A) && defined(X)
void a();
#endif

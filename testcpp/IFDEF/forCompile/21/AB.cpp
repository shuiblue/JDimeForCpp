#if defined (A) && (defined(X) || !defined(Y))
void a();
#if defined (B) && (defined(Z) && defined(Y))
void b();
#endif

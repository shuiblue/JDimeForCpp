#if defined (A) && defined (X) || defined (B) && defined (X)
void a();
#if defined (A) || defined (B) && defined (X)
void b();
#endif

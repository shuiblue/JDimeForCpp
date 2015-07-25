#if defined (B)
void b();
#if defined (A) && defined (X) || defined (B)
void a();
#endif

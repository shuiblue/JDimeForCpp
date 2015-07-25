#if defined (A) && defined (X) || defined (B) && defined (X)
void a();
#if defined (C) && defined (Y)
void c();
#if defined (A) || defined (B) && defined (Y)
void b();
#endif

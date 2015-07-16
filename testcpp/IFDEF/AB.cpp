#ifdef A || B
#include "x.h";
#endif

#ifdef A
#ifdef X
#endif

#ifdef B
void b();
#endif

#ifdef A
void a();
#endif
#endif

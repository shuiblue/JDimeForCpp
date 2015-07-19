#ifdef A || B || C || D
void x();
#endif
#ifdef A || C
void ac();
#endif
#ifdef B || D
void bd();
#endif

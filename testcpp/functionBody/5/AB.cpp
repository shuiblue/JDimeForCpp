#if defined (A)
int x=0;
#endif
#if defined (A) || defined (B)
void a(){
#if defined (A)
#ifdef X
i=0;
#endif
j=2;
#endif
#if defined (B)
i=1;
#endif
}
#endif
#if defined (A)
int x=0;
int y=0;
#endif
#if defined (A) || defined (B)
void a(){
#if defined (A)
i=0;
#endif
#if defined (B)
i=1;
#endif
}
#endif
#if defined (A)
void aa(){
j=0;
}

#endif

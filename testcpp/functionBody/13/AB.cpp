#if defined (A) || defined (B)
void a() {
#if defined (A)
    if(x > 5)
        y+=4
#endif
#if defined (B)
           if(x > 4)
               y+=4
#endif
        }
#endif
#if defined (A) || defined (B)
class Computer
#if defined (A)
    :public bar
#endif
{
    if ( i > 0 ) {
        x = i;
    }else
#if defined (A)
     if(i<0) {
        s=2;
    } else {
        t=0;
    }
#endif
#if defined (B)
     {
        t=0;
    }
#endif
}
#endif

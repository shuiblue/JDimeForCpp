#if defined (A) || defined (B)
class Computer
#if defined (A)
    :public bar
#endif

{
    if ( i > 0 ) {
        x = i;
    }
#if defined (A)
    else if(i<0) {
        s=2;
    } else {
        t=0;
    }
#endif
#if defined (B)
    else {
        t=0;
    }


#endif
}
#endif
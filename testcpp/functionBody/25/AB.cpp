#if defined (A) || defined (B)
class Computer
#if defined (A)
    :public bar
#endif

{
    while
    ( i-- > 0 ) {
        if ( x == 1 ) {
            a++;
            if (x>0) {
                b++;
#if defined (A)
                if(x<0) {
                    c++;
                }
#endif
            }
        }
    }
}
#endif

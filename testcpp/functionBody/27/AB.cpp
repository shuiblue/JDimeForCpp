#if defined (A) || defined (B)
class Computer:public bar {
    while
    ( i-- > 0 ) {
        if ( x == 1 ) {
            a++;
            if (x>0) {
                b++;
#if defined (A)
                if(x==0) {
                    c++;
                }
#endif
            }
#if defined (B)
            else {
                c++;
            }
#endif
        }
    }
}
#endif

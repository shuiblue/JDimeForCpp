#if defined (A) || defined (B)
class Computer
#if defined (A)
    :public bar
#endif
{
    while
    ( i-- > 0 ) {
        x = f( i );
        if ( x == 1 ) {
#if defined (A)
            continue;
#endif
#if defined (B)
            t++;
#endif
        }
        y += x * x;
    }
}
#endif

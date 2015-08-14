#if defined (A) || defined (B)
class Computer

#if defined (A)
    :public bar
#endif

{
    switch
    ( i ) {
    case
            -1
            :
#if defined (A)
        n++;
#endif
#if defined (B)
        p++;
#endif
        break;
    case
            0
            :
        z++;
        break;
    case
            1
            :
        p++;
        break;
    }
}
#endif

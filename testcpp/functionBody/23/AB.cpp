#if defined (A) || defined (B)
class Computer
#if defined (A)
    :public bar
#endif
{
    switch
    ( i ) {
    case
            :
#if defined (A)
        n++;
#endif
#if defined (B)
        p++;
#endif
        break;
    case
            :
        z++;
        break;
    case
            :
        p++;
        break;
    }
}
#endif

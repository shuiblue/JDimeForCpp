#if defined (A) || defined (B)
void a()
{
    for(i=0; i<max;)
    {
#if defined (A)
        if ( line[i] == ' ' )
        {
            aaa++;
        }
#endif
#if defined (B)
        if ( line[i] == ' ' )
        {
            space++;
        }
#endif
        if ( line[i] == '\t' )
        {
            tab++;
        }
    }
}
#endif

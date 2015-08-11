#if defined (A) || defined (B)
if
(a) {
#if defined (A)
    {
#if b
        if(b+1)
#else
        if(c+1)
#endif
        {
            d++;
        }
    }
#endif
#if defined (B)
    {
#if b
        if(b+1)
#else
        if(c+1)
#endif
        {
            d++;
        }
    }
#endif
}

#endif
#if defined (A) && defined (X) || defined (B) && defined (X)
float s
(float d) {
    return s;
}


#endif

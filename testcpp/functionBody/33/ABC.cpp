#if defined (A) && defined (x) || defined (B) && defined (x) || defined (C) && defined (x)
void a
#if defined (B) && defined (x)
    (xx)
#endif
#if defined (A) && defined (x) || defined (C) && defined (x)

    ()
#endif
{
#if defined (A) && defined (x)
    a++;
#endif
#if defined (B) && defined (x)
    b++;
#endif
#if defined (C) && defined (x)
    c++;
#endif
}
#endif

void a#if defined (A) || defined (B)
()
#endif
{
#if defined (A) || defined (B)
i=0;
#endif
#if defined (B)
j=0;
#endif
}
#endif

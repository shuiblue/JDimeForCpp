#if defined (A) || defined (B)
class Foo
#if defined (A)
    :public bar
#endif
{
    int i=0;
    long a=0;
    int y=0;
#if defined (B) && defined (X)
    int t=0;
#endif
      protected:
#if defined (A)

    int s = 1;
#endif
#if defined (B)

    int s = 0;

#endif
}
#endif

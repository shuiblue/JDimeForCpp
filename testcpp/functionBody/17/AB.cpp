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
#if defined (A)
  protected:
    int s = 1;


#endif
#if defined (B)
  protected:
    int s = 0;


#endif
}
#endif

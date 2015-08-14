#if defined (A) || defined (B)
class Foo

#if defined (A)
    :public bar
#endif

{
    int i=0;
#if defined (A)
    long a=0;
    int y=0;
  protected:
    int s = 0;


#endif
}
#endif

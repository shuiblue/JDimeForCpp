int foo;
void test1 ()
{
 int foo;
 foo=1;
}
void test2 ()
{
 foo=2;
 test1();
 test3();
}

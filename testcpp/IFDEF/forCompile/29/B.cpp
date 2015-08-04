void a()
{
#ifdef SDSLOW
  if (z)
#else
  if (Y)
#endif
  {
    cardOK = true;
  }

}
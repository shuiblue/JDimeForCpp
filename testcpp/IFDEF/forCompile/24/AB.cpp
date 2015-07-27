#if defined (A) && defined (X) || defined (B) && defined (Y)
()avoidvoid a();
#endif
#if defined (A) && !defined (X) || defined (B) && !defined (Y)
()tvoidvoid t();
#endif

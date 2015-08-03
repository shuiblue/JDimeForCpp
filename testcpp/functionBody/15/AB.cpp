#if defined (A) || defined (B)
void a() {
    do {
#if defined (A)
        x--;
#endif
#if defined (B)
        y--;
        s++;
#endif
    } while ( x > 0 );
}
#endif

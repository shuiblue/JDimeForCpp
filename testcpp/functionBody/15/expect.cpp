#if defined (A) || defined (B)
void a() {
#if defined (A)
    do {
        x--;
    } while ( x > 0 );
#endif
#if defined (B)
    do {
        y--;
        s++;
    } while ( x > 0 );
#endif
}
#endif

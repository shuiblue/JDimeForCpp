#if defined (A) || defined (B)
void loop() {
#if defined (A) && defined (SDSUPPORT) || defined (B) && defined (SDSUPPORT)
    card.checkautostart(false);
    if (buflen)
#endif
    {
        bufindr = (bufindr + 1)%BUFSIZE;
    }
}
}
#endif

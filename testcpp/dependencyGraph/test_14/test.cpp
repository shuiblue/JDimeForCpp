static inline __attribute__((always_inline))
  void spiSendBlock(uint8_t token, const uint8_t* buf) {
  SPDR = token;
  for (uint16_t i = 0; i < 512; i += 2) {
    while (!(SPSR & (1 << SPIF))) { /* Intentionally left empty */ }
    SPDR = buf[i];
    while (!(SPSR & (1 << SPIF))) { /* Intentionally left empty */ }
    SPDR = buf[i + 1];
  }
  while (!(SPSR & (1 << SPIF))) { /* Intentionally left empty */ }
}

// These commands scroll the display without changing the RAM
void LiquidCrystalRus::scrollDisplayLeft(void) {
  command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}
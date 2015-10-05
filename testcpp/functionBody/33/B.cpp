
void setup()
{
  setup_killpin();
  
  // STRING_VERSION_CONFIG_H
  
  
#ifdef STAT_LED_RED
  pinMode(STAT_LED_RED, OUTPUT);
  digitalWrite(STAT_LED_RED, LOW); // turn it off
#endif
#ifdef STAT_LED_BLUE
  pinMode(STAT_LED_BLUE, OUTPUT);
  digitalWrite(STAT_LED_BLUE, LOW); // turn it off
#endif  
}












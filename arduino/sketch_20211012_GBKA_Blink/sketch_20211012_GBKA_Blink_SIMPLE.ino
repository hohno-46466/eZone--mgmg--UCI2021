#ifdef __SIMPLE_CODE__

#ifdef LED_BUILTIN
#undef LED_BUILTIN
#define LED_BUILTIN (4)
#endif

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}

#endif // __SIMPLE_CODE__

const int PROBE_PIN = 2;
const int LED_PIN   = 13;

void setup() {
  pinMode(PROBE_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  bool continuity = (digitalRead(PROBE_PIN) == LOW);

  digitalWrite(LED_PIN, continuity ? HIGH : LOW);
  delay(10);
}

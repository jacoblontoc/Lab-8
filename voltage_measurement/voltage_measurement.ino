#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int   PROBE_POS = A0;
const int   PROBE_NEG = A1;
const float VREF      = 5.00;
const int   SAMPLES   = 20;

float readVolts(int pin) {
  analogRead(pin);
  delay(2);
  long total = 0;
  for (int i = 0; i < SAMPLES; i++) {
    total += analogRead(pin);
    delay(1);
  }
  return (total / (float)SAMPLES) * VREF / 1023.0;
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("DC Voltmeter");
  delay(1500);
  lcd.clear();
}

void loop() {
  float vPos = readVolts(PROBE_POS);
  float vNeg = readVolts(PROBE_NEG);
  float vDiff = vPos - vNeg;

  if (abs(vDiff) < 0.02) vDiff = 0.0;

  lcd.setCursor(0, 0);
  lcd.print("V = ");
  lcd.print(vDiff, 2);
  lcd.print(" V      ");

  lcd.setCursor(0, 1);
  lcd.print("+");
  lcd.print(vPos, 2);
  lcd.print("  -");
  lcd.print(vNeg, 2);
  lcd.print("    ");

  delay(300);
}

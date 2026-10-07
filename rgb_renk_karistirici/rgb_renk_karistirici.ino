// RGB LED Renk Karıştırıcı
// Joystick X  -> Kırmızı
// Joystick Y  -> Yeşil
// Potansiyometre -> Mavi
//
// Test edilen kart: Arduino Mega 2560 (Uno'da da aynı pinlerle çalışır)

const int pinR = 9;   // PWM
const int pinG = 10;  // PWM
const int pinB = 11;  // PWM

void setup() {
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void loop() {
  int r = map(analogRead(A0), 0, 1023, 0, 255);  // joystick X
  int g = map(analogRead(A1), 0, 1023, 0, 255);  // joystick Y
  int b = map(analogRead(A2), 0, 1023, 0, 255);  // potansiyometre

  analogWrite(pinR, r);
  analogWrite(pinG, g);
  analogWrite(pinB, b);
  delay(20);
}

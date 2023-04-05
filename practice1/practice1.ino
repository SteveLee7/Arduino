const int whiteLED = 9;

void blink1()
{
  digitalWrite(whiteLED, HIGH);
  delay(500);
  digitalWrite(whiteLED, LOW);
  delay(500);
}

void setup() {
  pinMode(whiteLED, OUTPUT);
}

void loop() {
  blink1();
}
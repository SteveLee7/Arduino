const int whiteLED = 9;
unsigned int count = 10;

void blink1()
{
  digitalWrite(whiteLED, HIGH);
  delay(500);
  digitalWrite(whiteLED, LOW);
  delay(500);
};
void blink2(int count){
while( count > 0 ){

  digitalWrite(whiteLED, HIGH);
  delay(500);
  digitalWrite(whiteLED, LOW);
  delay(500);
  count = count-1;
   Serial.println(count);
  }
};  
void setup() {
  pinMode(whiteLED, OUTPUT);
  Serial.begin(115200);
 
}

void loop() {
  blink2(count);
}
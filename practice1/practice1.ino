const int whiteLED = 9;
const int LEDWhite = 9;
  const int LEDRed = 6;
  const int LEDGreen = 5;
const int count = 10;
  const int SWWhite = 7;
  const int SWGreen = 8;
   const int sensor_pin = A0;
void blink1()
{
  if(analogRead(sensor_pin) > 100){
  digitalWrite(whiteLED, HIGH);
  delay(500);
  digitalWrite(whiteLED, LOW);
  delay(500);
   Serial.println(analogRead(sensor_pin));
  }
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
int blink3(int period)
{
   int result;
  for(int switchVal=0; switchVal < 3 ;switchVal++)
  {
    digitalWrite(LEDRed,HIGH);
    delay(period);
    digitalWrite(LEDRed,LOW);
    delay(period);
    result= result +1;
    switchVal - digitalRead(SWWhite);
   Serial.println(result);
  }
  return result;
};
void setup() {
  pinMode(LEDWhite,OUTPUT);
  pinMode(LEDRed,OUTPUT);
  pinMode(LEDGreen,OUTPUT);
  pinMode(SWWhite,INPUT);
  pinMode(SWGreen,INPUT);
//  pinMode(tone_pin,OUTPUT);
  Serial.begin(115200);
 
}

void loop() {
  blink1();
   Serial.println(analogRead(sensor_pin));
 //int count= blink3(1000);

   delay(500);
}
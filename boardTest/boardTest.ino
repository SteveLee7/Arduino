// 20230404 Board Hardware's Function Test
  const int LEDWhite = 9;
  const int LEDRed = 6;
  const int LEDGreen = 5;
  const int SWWhite = 7;
  const int SWGreen = 8;
  const int tone_pin = 11;
  const int sensor_pin = A0;
  char sw_read_white =0;
  char sw_read_green =0;
  
void setup() {
  // initialize digital pin LED_BUILTIN as an output.

  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEDWhite,OUTPUT);
  pinMode(LEDRed,OUTPUT);
  pinMode(LEDGreen,OUTPUT);
  pinMode(SWWhite,INPUT);
  pinMode(SWGreen,INPUT);
  pinMode(tone_pin,OUTPUT);
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  sw_read_white=digitalRead(SWWhite);
  sw_read_green=digitalRead(SWGreen);
  if (sw_read_white == HIGH){
    digitalWrite(LEDWhite, HIGH);  
    tone(tone_pin,1000,500);
  }
  if (sw_read_green == HIGH)
    digitalWrite(LEDRed, HIGH);  
  digitalWrite(LEDGreen, HIGH); 
  delay(1000);                    
  digitalWrite(LEDWhite, LOW);   
  digitalWrite(LEDRed, LOW);  
  digitalWrite(LEDGreen, LOW); 
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1000);                   
}

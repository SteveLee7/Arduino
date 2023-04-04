// 20230404 Board Hardware's Function Test
  const int LEDWhite = 9;
  const int LEDRed = 6;
  const int LEDGreen = 5;
  const int SWWhite = 7;
  const int SWGreen = 8;
  const int tone_pin = 11;
  const int sensor_pin = A0;
  int a[]={5,6,9};
  
;void setup() {
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
 
  for(int i =0; i <3 ;i++){
  digitalWrite(a[i], HIGH); 
  delay(1000);                   
  digitalWrite(a[i], LOW);
  delay(1000);
  }
}  
  /*if (digitalRead(SWWhite) == HIGH){
    digitalWrite(LEDWhite, HIGH);  
   
  }
  if (digitalRead(SWGreen) == HIGH)
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
*/
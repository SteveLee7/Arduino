
int sensorPin = A0;   // select the input pin for the potentiometer
int ledPin = 10;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
const int ACTIVE_BUZZER = 13;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
   Serial.begin(115200);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  digitalWrite(ledPin, LOW);
  sensorValue = map(sensorValue, 0,1023, 0,255);
 // analogWrite(ledPin,sensorValue);
  if(sensorValue >= 150 )  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
//  delay(1000);
  tone(ACTIVE_BUZZER,sensorValue);
  Serial.println("AD:");  
  Serial.println(sensorValue);
        
}

#include <Servo.h>



 #define A_tone 440
 #define B_tone 493
 #define C_tone 523
 #define D_tone 587
 #define E_tone 659
 #define F_tone 698
 #define G_tone 783

Servo myservo;

const int LEDRed = 6;
const int trigPin = 9;
const int echoPin = 10;
const int tone_pin = 4;
float duration, distance;
 const int SWWhite = 7;
int pos = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDRed,OUTPUT);
  pinMode(tone_pin,OUTPUT);
  pinMode(SWWhite,INPUT);
  Serial.begin(9600);
  myservo.attach(11);
}
void ultrasonicMesur(){  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  return 0;
};
void  UltrasonicProc(){
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
  if (distance < 30){
  switch ((int)distance) {
      case 0 ... 5:
        digitalWrite(LEDRed,HIGH);
        tone(tone_pin,C_tone,100);
      break;
      case 6 ... 10:  
        digitalWrite(LEDRed,HIGH);
        tone(tone_pin,D_tone,200);
      break;
      case 11 ... 15:  
        digitalWrite(LEDRed,HIGH);
        tone(tone_pin,E_tone,300);
      break;
      case 16 ... 20:  
        digitalWrite(LEDRed,HIGH);
        tone(tone_pin,F_tone,400);
      case 21 ... 30:  
        digitalWrite(LEDRed,HIGH);
        tone(tone_pin,G_tone,500);  
        break;  
      default:
      digitalWrite(LEDRed,LOW);
      break;
      }
  }
  return  0 ;  
}  

void loop() {
  
  if (digitalRead(SWWhite)== HIGH) {
    ultrasonicMesur();
    UltrasonicProc();
    int angle = map((int)distance,0,30,0,180);
    myservo.write(angle);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(100);
}
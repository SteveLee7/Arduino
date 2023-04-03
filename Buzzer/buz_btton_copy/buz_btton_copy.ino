
// #include <Servo.h>
const int ledPin = 10;
// Servo servo;
const int buttonPin = 2;
const int ACTIVE_BUZZER = 13;

//int servo_state =30;
int led_state = LOW;
int buzzer_state = LOW;
int buzzer_state_low = LOW;

//bool servo_state_changed = false;
bool  led_state_changed = false;
bool buzzer_state_changed = false;

void buttonPressed(){
//  servo_state = (servo_state ==30)?150:30;
//  servo_state_changed = true;
led_state = (led_state ==LOW)?HIGH:LOW;
led_state_changed = true;
buzzer_state =(buzzer_state ==LOW)?HIGH:LOW;
buzzer_state_changed = true;
}
void setup() {
  Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
  pinMode(ACTIVE_BUZZER, OUTPUT);
  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin),buttonPressed, RISING);
//  servo.attach(SERVO);
//  servo.write(0);
//  delay(1000);
}
void loop(){
//  if(servo_state_changed){
//    servo_state_changed = false;
//    servo.write(servo_state);
//    digitalWrite(ACTIVE_BUZZER, buzzer_state);

    if(led_state_changed){
       led_state_changed = false;
       digitalWrite(ledPin, led_state);
       Serial.println("led_state:");  
      Serial.println(led_state);
    }
    if(buzzer_state_changed){ 
        buzzer_state_changed = false;
      if(buzzer_state_low == true){
          buzzer_state_low = false;
        if(buzzer_state== true){
          buzzer_state_low = true;
          tone(ACTIVE_BUZZER,262);
          delay(3000);
          noTone(ACTIVE_BUZZER);
          delay(1000);
          Serial.println("buzzer_state:");  
          Serial.println(buzzer_state);
        }
      }  
    }  
  
}

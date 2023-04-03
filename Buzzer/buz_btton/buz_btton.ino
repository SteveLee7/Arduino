
// #include <Servo.h>
const int ledPin = 13;
// Servo servo;
const int buttonPin = 2;
const int ACTIVE_BUZZER = 10;

//int servo_state =30;
//int led_state = LOW;
int buzzer_state = LOW;
//bool servo_state_changed = false;
//bool  led_state_changed = false;
bool buzzer_state_changed = false;

void buttonPressed(){
//  servo_state = (servo_state ==30)?150:30;
//led_state = (led_state ==LOW)?HIGH:LOW;
buzzer_state =(buzzer_state ==LOW)?HIGH:LOW;
//  servo_state_changed = true;
//    led_state_changed = true;
    buzzer_state_changed = true;
}
void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin),buttonPressed, RISING);
//  servo.attach(SERVO);
//  servo.write(0);
//  delay(1000);
}
void loop(){
//  if(servo_state_changed){
//    if(led_state_changed){
      if(buzzer_state_changed){
//      servo_state_changed = false;
//      led_state_changed = false;
      buzzer_state_changed = false;
//    servo.write(servo_state);
//      digitalWrite(ledPin, led_state);
        digitalWrite(ACTIVE_BUZZER, buzzer_state);
  }
}

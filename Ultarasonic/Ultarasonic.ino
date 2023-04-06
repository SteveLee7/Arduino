
// 20230404 Board Hardware's Function Test
  const int LEDWhite = 9;
  const int LEDRed = 6;
  const int LEDGreen = 5;
  const int SWWhite = 7;
  const int SWGreen = 8;
  const int tone_pin = 11;
  const int sensor_pin = A0;
  int a[]={5,6,9};
  int led_buzzer_sel;
  int time_how_long;
  
  unsigned long prevMillis=0;


  void LedOnOff(int interval){
    for (;millis() - prevMillis >= interval;) {
        digitalWrite(LEDWhite, HIGH);
        delay(interval);
        digitalWrite(LEDWhite, LOW);
        delay(500);
        prevMillis=millis();
    }   
        return 0;
  };
  
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
void loop() {

if (Serial.available() > 0) {
    Serial.print("White LED:1, Buzzer:2 ? ");
    led_buzzer_sel=Serial.read();
    Serial.println(led_buzzer_sel, HEX);
    }
    if (Serial.available() > 0) {
    Serial.print("How Long Time:3 ? ");
    time_how_long=Serial.read();
    Serial.println(time_how_long, HEX);
    }
      switch (led_buzzer_sel & 0x0f){
        case 1:
          LedOnOff(time_how_long);
          break;
        case 2:
          tone(tone_pin,1000,time_how_long);
          break;
       }  
     
  } 

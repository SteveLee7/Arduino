const int LED=13;

void setup() {
  // put your setup code here, to run once:
pinMode(LED, OUTPUT);
digitalWrite(LED,LOW);
Serial.begin(115200);
}
int cnt = 0;
void loop() {

 digitalWrite(LED,HIGH);
 delay(8);
 digitalWrite(LED,LOW);
 delay(2);
 while(true){
   for(int t_high=0; t_high <=10; t_high++){
      digitalWrite(LED,HIGH);
      delay(t_high);
      digitalWrite(LED,LOW);
      delay(10-t_high);      
      cnt++;
      if (cnt ==10) break;
      }
      
  }
}

const int Wbutton = 7;
const int Gbutton = 8;
const int CDS = A0;

char logging = 0;
void setup() {
  pinMode(Wbutton,INPUT);
  pinMode(Gbutton,INPUT);
  Serial.begin(9600);// put your setup code here, to run once:

}
void loop() {
  if (digitalRead(Wbutton)) {
        Serial.println("테스트 시작");
       logging = 1;
   }
  else if (digitalRead(Gbutton)){
     Serial.println("테스트 끝");
         logging = 0;
  }    
   delay(1000);
  if (logging) Serial.println(analogRead(CDS));   
  
 }

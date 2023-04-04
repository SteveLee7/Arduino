const int LED = 10;
int t_high=0;
unsigned long t_prev = 0;
unsigned long t_button_prev;
const unsigned long t_delay =4;
 const unsigned long t_button_delay =  1000 ;
const int buttonPin = 13;
int t_button_high = 0;
char button_high_flag =0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}
void loop() {
unsigned long t_now = millis();
    
int buttonInput=digitalRead(buttonPin);
if(button_high_flag = 0) {
  if(buttonInput==HIGH){
      if(button_high_flag == 1)
        if(t_now- t_prev >= t_delay){
        t_prev = t_now;
         t_high++;
        if(t_high>255)  t_high = 0;
        t_button_high ++;   
      if (t_button_high>255) {
        t_button_high = 0; 
        button_high_flag = 1;
        } 
       analogWrite(LED, t_high); 
       Serial.println(t_high) ;
      }
  else {
    analogWrite(LED, 0);
    button_high_flag = 0;
      }   
    }
  }  
}
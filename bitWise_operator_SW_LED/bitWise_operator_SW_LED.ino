#define SETd2       PORTD |= B00000100  // D2 HIGH       ~187.5ns to go HIGH
#define RESETd2     PORTD &= B11111011  // D2 LOW        ~187.5ns to go LOW
#define TOGGLEd2     PIND  = B00000100  // D2 Toggle     ~62.5ns to toggle a pin
#define TESTd2      (PIND  & B00000100) // D2 is tested  ~125ns to read a pin

#define SETd3       PORTD |= B00001000  // D3 HIGH
#define RESETd3     PORTD &= B11110111  // D3 LOW
#define TOGGLEd3     PIND  = B00001000  // D3 Toggle
#define TESTd3      (PIND  & B00001000) // D3 is testedbitSet(PORTB,4); // turn ON pullup
setup(){
  DDRD = TESTd2 | TOGGLEd3 ;
}

void loop() {
    if(!bitRead(TOGGLd3)) { // if pin 12 low
//...do some stuff here that I want done when pin 12 is low ...
      bitSet(SETd2);
      }
      bitClear(SETd2); // set pin 12 direction as input
      delay(100);
}
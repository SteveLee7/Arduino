/*
  

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce
*/

#define NOT_PRESSED 0
#define PRESSED 1

const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin

// Variables will change:
int ledState = HIGH;        // the current state of the output pin
int btnState = NOT_PRESSED;            // the current reading from the input pin
int reading ;
char btnTmp;    

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {

    if (btnState == NOT_PRESSED)
    {
      reading = digitalRead(buttonPin);
      if (reading = 1)
      btnState = PRESSED; 
    }  
   else
   {
      reading = digitalRead(buttonPin);
      if (reading == 0)
         btnState = NOT_PRESSED;
   }
   delay(1);
}
/*
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/StateChangeDetection
*/

// this constant won't change:
const int buttonPin = 7;  // the pin that the pushbutton is attached to
const int ledPin =12;    // the pin that the LED is attached to
const int sensor_pin = A0;

// Variables will change:
int buttonPushCounter = 0;  // counter for the number of button presses
int buttonState = 0;        // current state of the button
int lastButtonState = 0;    // previous state of the button
int button_pressed = 0;
int button_depressed = 0;
int buttonHigh =0;
void setup() 
{
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop()
 {
 buttonState = digitalRead(buttonPin);     
int button_state;
if (buttonState != lastButtonState)  buttonHigh=buttonCheck(button_state);  

  if (buttonPushCounter % 100 == 0)
  {
    int val = analogRead(sensor_pin);
  /*  
    if (_value)
    digitalWrite(ledPin, HIGH);
  
  {
    digitalWrite(ledPin, LOW);
  }
  */
  } 
}
int buttonCheck(int button_vlaue) {
    
 if (buttonState)
  {
     button_pressed ++;
     if(button_pressed == 16)
     {
     button_pressed = 0;
     buttonPushCounter++;
     Serial.println("on");
     lastButtonState = buttonState; 

     }
     delay(1);
     return 1;
   } 
   else
   { 
      button_depressed ++;
     if (button_depressed == 16)
     { 
     button_depressed=0;
     Serial.println("off");
     lastButtonState = buttonState; 
     }
     delay(1);
     return 0;
   }
}  

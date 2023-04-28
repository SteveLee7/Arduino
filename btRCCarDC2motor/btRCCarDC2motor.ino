/*
 * Created by Vasilakis Michalis // 12-12-2014 ver.2
 * Project: Control RC Car via Bluetooth with Android Smartphone
 * More information at www.ardumotive.com
 * Modify to use L9110 and two motor RC car, by zeta
 */

#define __MEGA2560__ 0	
#define BAUDRATE 9600

#if __MEGA2560__
	#define blueToothSerial Serial3		//the software serial port
#else
	#include <SoftwareSerial.h>   		//Software Serial Port
	#define RxD 2
	#define TxD 3
	SoftwareSerial blueToothSerial(RxD,TxD);	//the software serial port 
#endif  

//L9110 Connection   
  const int motorA1  = 6;  // A-1B of L9110, right motor
  const int motorA2  = 5;  // A-1A of L9110, right motor
  const int motorB1  = 10; // B-1B of L9110, left motor
  const int motorB2  = 9; // B-1A of L9110, left motor
//Bluetooth (HC-06 JY-MCU) State pin on pin 2 of Arduino
  const int BTState = 7; 
//Calculate Battery Level
  const float maxBattery =7.2;// Change value to your max battery voltage level, 2x3.6V
  int perVolt;                 // Percentage variable 
  float voltage = 0.0;         // Read battery voltage
  int level;
// Use it to make a delay... without delay() function!
  long previousMillis = -1000*10;// -1000*10=-10sec. to read the first value. If you use 0 then you will take the first value after 10sec.  
  long interval = 1000*10;       // interval at which to read battery voltage, change it if you want! (10*1000=10sec)
  unsigned long currentMillis;   //unsigned long currentMillis;
//Useful Variables
  int i=0;
  int j=0;
  int state;
  int vSpeed=200;     // Default speed, from 0 to 255

void setup() {
    Serial.begin(9600);   				    //Serial port for debugging
    blueToothSerial.begin(BAUDRATE);            //BT module baud rate
    // Set pins as outputs:
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
    pinMode(BTState, INPUT);    
    // Initialize serial communication at 9600 bits per second:
}
 
void loop() {
  //Stop car when connection lost or bluetooth disconnected
     if(digitalRead(BTState)==LOW) { state='S'; }

  //Save income data to variable 'state'
    if(blueToothSerial.available() > 0){     
      state = blueToothSerial.read();   
      Serial.println(char(state));
    }
 	  
  /***********************Forward****************************/
  //If state is equal with letter 'F', car will go forward!
    if (state == 'F') {
    	analogWrite(motorA1, 0); analogWrite(motorA2, 255);
        analogWrite(motorB1, 0); analogWrite(motorB2, 255); 
    }
  /**********************Forward Left************************/
  //If state is equal with letter 'G', car will go forward left
    else if (state == 'G') {
    	analogWrite(motorA1, 0); analogWrite(motorA2,255);  
        analogWrite(motorB1, 0);    analogWrite(motorB2, 0); 
    }
  /**********************Forward Right************************/
  //If state is equal with letter 'I', car will go forward right
    else if (state == 'I') {
      	analogWrite(motorA1, 0); analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);      analogWrite(motorB2, 255); 
    }
  /***********************Backward****************************/
  //If state is equal with letter 'B', car will go backward
    else if (state == 'B') {
    	analogWrite(motorA1, 255);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, 255);   analogWrite(motorB2, 0); 
    }
  /**********************Backward Left************************/
  //If state is equal with letter 'H', car will go backward left
    else if (state == 'R') {
    	analogWrite(motorA1, 255);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0); analogWrite(motorB2, 0); 
    }
  /**********************Backward Right************************/
  //If state is equal with letter 'J', car will go backward right
    else if (state == 'L') {
    	analogWrite(motorA1, 0);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, 255);   analogWrite(motorB2, 0); 
    }
	
  /************************Stop*****************************/
  //If state is equal with letter 'S', stop the car
    else if (state == 'S'){
        analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
    }
  /***********************Battery*****************************/
  //Read battery voltage every 10sec.
    currentMillis = millis();
    if(currentMillis - (previousMillis) > (interval)) {
       previousMillis = currentMillis; 
       //Read voltage from analog pin A0 and make calibration:
       voltage = (analogRead(A0)*5.015 / 1024.0)*11.132;
       //Calculate percentage...
       perVolt = (voltage*100)/ maxBattery;
       if      (perVolt<=75)               { level=0; }
       else if (perVolt>75 && perVolt<=80) { level=1; }    //        Battery level
       else if (perVolt>80 && perVolt<=85) { level=2; }    //Min ------------------------   Max
       else if (perVolt>85 && perVolt<=90) { level=3; }    //    | 0 | 1 | 2 | 3 | 4 | 5 | >
       else if (perVolt>90 && perVolt<=95) { level=4; }    //    ------------------------
       else if (perVolt>95)                { level=5; }   
       blueToothSerial.println(level);    
    }
    
}
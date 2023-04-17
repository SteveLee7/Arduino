
  char cmd =0,a=0, b=0, enter, oneByte, incomingBytes=0;
  char bitWisecmd[4] = {cmd,a,b,enter};

void setup() {
  Serial.begin(9600);

}

void loop() {
    
    switch (oneByte != Serial.read()){
    case 0:
    bitWisecmd[cmd] = Serial.available();
    Serial.println(bitWisecmd[cmd]);
    case 1:
    bitWisecmd[a] = Serial.available();
     Serial.println(bitWisecmd[a]);
    case 2:
    bitWisecmd[b] = Serial.available();
    Serial.println(bitWisecmd[b]);
    case 3:
    bitWisecmd[enter] = Serial.available(); 
    Serial.println(bitWisecmd[enter]);  
    default:
    oneByte = Serial.read()     
    ;
    }
  delay(100);      
   /*    
  

    for(int i=0;Serial.available ()>=2 ;i++) bitWisecmd[i]=Serial.read();
    // read the most recent byte (which will be from 0 to 255):

      Serial.println(bitWisecmd[cmd]);
      Serial.println(bitWisecmd[a]);
      Serial.println(bitWisecmd[b]);
      Serial.println(0x(bitWisecmd[enter])
      
    
  /*
   if (bitWisecmd[cmd] ==  'A') { 
     Serial.println(bitWisecmd[cmd]);
     Serial.print("AND= ");
     Serial.println(bitWisecmd[a]&bitWisecmd[b]);
   }
   else if (bitWisecmd[cmd] =='O') {
     Serial.println(bitWisecmd[cmd]);
     Serial.print("OR= ");
     Serial.println(bitWisecmd[a]|bitWisecmd[b]);
   }
   else if(bitWisecmd[cmd] =='X') {
     Serial.println(bitWisecmd[cmd]);
     Serial.print("XOR= ");
     Serial.println(bitWisecmd[a]^bitWisecmd[b]);
   }
   else if(bitWisecmd[cmd] =='S') {
     Serial.println(bitWisecmd[cmd]);
     Serial.print("Right Shift= ");
     Serial.println(bitWisecmd[a] >> bitWisecmd[b]);
   }
   //else   Serial.println("???");
   */
}

// C++ code
//
void setup()
{
  char pinIO;
  for(pinIO=0;pinIO<8;pinIO++)
  pinMode(pinIO,OUTPUT);
}

void loop()
{
  char pinNo;
  for(pinNo=0;pinNo<8;pinNo++)
  digitalWrite(pinNo,HIGH);
  delay(1000); // Wait for 1000 millisecond(s)

  for(pinNo=0;pinNo<8;pinNo++)
  digitalWrite(pinNo,LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
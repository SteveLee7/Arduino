// C++ code
//
void setup()
{
DDRD = 0xff;
}
int main(void) {
  
  while(1){
   PORTD |= 0x90;
   _delay_ms(1000);
   PORTD &= 0x70;
   _delay_ms(1000);
  }
}


#define Trigg 0x04  
#define Echo 0x02

long T_duration;
int Distance;


void setup() 
{
  // setting DDRB as output
  DDRB|= 0x04;   //Trigg output and echo input
  DDRB &= (0x1D); // Echo 
  DDRB|= 0x10;   //o/p Pin
  
}
 
void loop()
{
  unsigned long pulse_width = 0;
  Trigger();
  
  while ((PORTB & 0x02) == 1)
  {
    pulse_width++;
  }
  
}

void Trigger()
{  
  PORTB &= ~(0x04);// trigering turned off at the loop starting
  delay(2);
  PORTB |= 0x04; // Trigger pin turned of for 
  delay(10);
  PORTB &= ~(0x04);
}

  

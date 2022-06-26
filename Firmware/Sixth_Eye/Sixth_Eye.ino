/*
* Implimenting US sensor distance measurement.
* Accelerometer interrupt awakens mC from sleep mode at of 275 - pending
*
* Author:
* Muhammed Shibili k
* mshibili01@gmail.com
*/
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
  
  while((PINB & Echo) == 1)
  {
    pulse_width++;
   
   } 

 T_duration = clockCyclesToMicroseconds(pulse_width * 8 + 8);
   
   
}
void Trigger()
{  
  PORTB &= ~(Trigg);// trigering turned off at the loop starting
  delay(2);
  PORTB |= Trigg; // Trigger pin turned of foxr 
  delay(10);
  PORTB &= ~(Trigg);
}

  

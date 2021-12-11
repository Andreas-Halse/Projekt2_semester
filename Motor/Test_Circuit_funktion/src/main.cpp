#include <Arduino.h>
#include <avr/io.h>

int main() 
{

bool on = false;
bool retning = false;

pinMode(53, OUTPUT); // sætter pin 53 til output
pinMode(51, OUTPUT); // sætter pin 51 til output
pinMode(27, INPUT); // sætter knap 5 til input
pinMode(28, INPUT); // sætter knap 6 til input


for (;;)
{

do
{

if(digitalRead(27) == 0) // skifter on hvis knap 5 trykkes
{
  on = !on; // inverter bool on
}

if(digitalRead(28) == 0) // skifter retning hvis knap 6 trykkes
{
  retning = !retning; //inverter bool retning
}

if(on == true) //
{
  digitalWrite(53, HIGH); // motor køre så længe on = true

}
else
{
  digitalWrite(53, LOW); // motor køre ikke

}
  

  if (retning == true)
  { 
    digitalWrite(51, HIGH); // retning
  }
  else
  {
    digitalWrite(51, LOW); // retning
  }
} 
while (on == true);

}

}
















// if (on == true && retning == true) // sætter både retning og on
// {
//   digitalWrite(53, HIGH);
//   digitalWrite(51, HIGH);
// }
// else if (on == true && retning == false) // sætter kun on
// {
//   digitalWrite(53, HIGH);
// }
// else // slukker
// {
//   digitalWrite(53, LOW);
//   digitalWrite(51, LOW);
// }

// END loop

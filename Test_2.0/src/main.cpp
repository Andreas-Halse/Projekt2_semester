#include <Arduino.h>
#include <avr/io.h>

bool on = false;
bool retning = false;

int main() 
{

pinMode(53, OUTPUT); // sætter pin 53 til output til on
pinMode(51, OUTPUT); // sætter pin 51 til output til retning
pinMode(22, INPUT); // sætter knap 0 til input
pinMode(23, INPUT); // sætter knap 1 til input
pinMode(24, INPUT); // sætter knap 2 til input
pinMode(25, INPUT); // sætter knap 3 til input

// knap 0 slukker motor
// knap 1 tænder motor
// knap 2 sætter retning
// knap 3 sætter retnings


for (;;)
{
if(digitalRead(22) == 0) // slukker motor knap 0
{
  on = false;
}
if(digitalRead(23) == 0) // tænder motor knap 1
{
  on = true;
}

if(digitalRead(24) == 0) // ændre retning knap 2
{
  retning = false;
}
if(digitalRead(25) == 0) // ændre retning knap 3
{
  retning = true;
}

if(on == true) // tænder motor hvis on = true
{
  digitalWrite(53, HIGH);
}
else // slukker motor hvis on = false
{
  digitalWrite(53, LOW);
}


if(retning == true) // retning 1
{
  digitalWrite(51, HIGH);
}
else // retning 2
{
  digitalWrite(51, LOW);
}

}

}
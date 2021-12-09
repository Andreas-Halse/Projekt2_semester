#include <Arduino.h>
#include <avr/io.h>

int main()
{

bool on = false;
bool retning =  false;

pinMode(53, OUTPUT);
pinMode(51, OUTPUT);
pinMode(27, INPUT);
pinMode(28, INPUT);

for (;;)
{

if (digitalRead(27) == 0)
{
if (on)
{
  on = false;
  /* code */
}
else
{
  on = true;
}
}
if
 (digitalRead(28) == 0)
 {
   if (retning)
{
  retning = false;
  /* code */
}
else
{
  retning = true;
}
 }


if (on == true)
{
  digitalWrite(53, HIGH);
}
else
{
  digitalWrite(53, LOW);
}


if (retning == true)
{
  digitalWrite(51, HIGH);
}
else
  digitalWrite(51, LOW);


  /* code */
}


}
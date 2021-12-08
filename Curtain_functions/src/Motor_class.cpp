#include "Motor.hpp"
#include <Arduino.h>
#include <avr/io.h>
#include "Motor.hpp"

Motor::Motor()
{

}

void Motor::checkOnOff()
{
    if(digitalRead(22) == 0) // Knap 0 ændre "on" state til false
    {
      on = false;
    }
    if(digitalRead(23) == 0) // Knap 1 ændre "on" state til true
    {
      on = true;
    }

    if(on == true) // tænder motor hvis on = true
    {
      digitalWrite(53, HIGH);
    }
    else // slukker motor hvis on = false
    {
      digitalWrite(53, LOW);
    }
}

void Motor::checkDirecton()
{
    if(digitalRead(24) == 0) // knap 2 ændre "retning" state til false
    {
      direction = false;
    }
    if(digitalRead(25) == 0) // knap 3 ændre "retning" state til true
    {
      direction = true;
    }

    if(direction == true) // retning 1
    {
        digitalWrite(51, HIGH);
    }
    else // retning 2
    {
        digitalWrite(51, LOW); 
    }
}
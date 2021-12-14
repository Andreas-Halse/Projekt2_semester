#include "Motor_module.hpp"
#include <Arduino.h>
#include <avr/io.h>


 Motor_module::Motor_module()
 {

 }
    
void Motor_module::rollDown()
    {
        digitalWrite(33, HIGH); // tænder motor
        digitalWrite(31, HIGH); // gardin 1. retning
    }

void Motor_module::rollUp()
    {
        digitalWrite(33, LOW); // slukker motor
        digitalWrite(31, LOW); // gardin 2. retning
    }

void Motor_module::stop()
{
  digitalWrite(33, LOW); // slukker motor  
}
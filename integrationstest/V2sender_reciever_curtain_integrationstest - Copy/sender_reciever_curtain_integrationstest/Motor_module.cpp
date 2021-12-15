#include "Motor_module.h"
#include <Arduino.h>
#include <avr/io.h>


Motor_module::Motor_module()
{

}

void Motor_module::rollDown()
{
    digitalWrite(33, HIGH); // t?nder motor
    digitalWrite(31, HIGH); // gardin 1. retning
}

void Motor_module::rollUp()
{
    digitalWrite(33, HIGH); // T?nder
    digitalWrite(31, LOW); // gardin 2. retning
}

void Motor_module::stop()
{
    Serial.print("Stop kaldet");
    digitalWrite(33, LOW); // slukker motor  
}
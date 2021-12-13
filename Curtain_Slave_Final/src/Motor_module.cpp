#include "Motor_module.hpp"
#include <Arduino.h>
#include <avr/io.h>


 Motor_module::Motor_module()
 {

 }
    
void Motor_module::MotorOn()
    {
        digitalWrite(53, HIGH); // tænder motor
    }

void Motor_module::MotorOff()
    {
        digitalWrite(53, LOW); // slukker motor
    }

void Motor_module::CurtainUp()
    {
        digitalWrite(51, HIGH); // gardin 1. retning
    }

void Motor_module::CurtainDown()
    {
        digitalWrite(51, LOW); // gardin 2. retning
    }

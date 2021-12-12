#include <Arduino.h>
#include <avr/io.h>
#include <Stream.h>
#include "Motor_module.hpp"




int main()
{

Serial.begin(9600);
pinMode(53, OUTPUT); // sætter pin 53 til output til on
pinMode(51, OUTPUT); // sætter pin 51 til output til retning
Motor_module M;

for(;;)
{



M.MotorOn();
M.CurtainUp();

_delay_ms(4000);

M.MotorOff();

_delay_ms(5000);


M.MotorOn();
M.CurtainDown();

_delay_ms(10000);
}

}
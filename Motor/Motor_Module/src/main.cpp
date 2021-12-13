#include <Arduino.h>
#include <avr/io.h>
#include <Stream.h>
#include "Motor_module.hpp"




int main()
{

Serial.begin(9600); // sætter Baudrate
pinMode(53, OUTPUT); // sætter pin 53 til output til on
pinMode(51, OUTPUT); // sætter pin 51 til output til retning

Motor_module M; // opretter object

for(;;)
{
// Dette er en test main.

M.MotorOn(); // vi tænder motor
M.CurtainUp(); // sætter retning

_delay_ms(4000); // laver delay (4 sekunder) mens motor køre

M.MotorOff(); // slukker motor

_delay_ms(5000); // venter 5 sekunder

M.MotorOn(); // tænder motor
M.CurtainDown(); // retning ændret

_delay_ms(10000); // venter 10 sekunder
}
}
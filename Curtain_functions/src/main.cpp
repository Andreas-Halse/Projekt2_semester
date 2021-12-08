#include "Motor.hpp"
#include <Arduino.h>
#include <avr/io.h>



int main()
{
pinMode(53, OUTPUT); // sætter pin 53 til output til on
pinMode(51, OUTPUT); // sætter pin 51 til output til retning
pinMode(22, INPUT); // sætter knap 0 til input
pinMode(23, INPUT); // sætter knap 1 til input
pinMode(24, INPUT); // sætter knap 2 til input
pinMode(25, INPUT); // sætter knap 3 til input
Motor M;
  for(;;)
  {
    M.checkOnOff();
    M.checkDirecton();
  }
}
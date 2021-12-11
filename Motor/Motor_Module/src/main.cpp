#include <Arduino.h>
#include <avr/io.h>
#include <Arduino.h>
#include <Stream.h>
#include "Motor_module.hpp"



int main()
{

Serial.begin(9600);
pinMode(53, OUTPUT); // sætter pin 53 til output til on
pinMode(51, OUTPUT); // sætter pin 51 til output til retning
Motor_module M;

Serial.print("TEST1");
cout << "Test1"
for(;;)
{
M.CurtainUp();
Serial.print("TEST2");
M.MotorOn();

Serial.print("TEST");
delay(2000);

// M.CurtainDown();
M.MotorOff();

// delay(10000);

// M.CurtainUp();

// delay(5000);

}

}
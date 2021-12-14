#include "Motor_module.hpp"
#include "Slave_Array_Read.hpp"
#include <Arduino.h>
#include <avr/io.h>

int main()
{


// up 1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1
// Before 1,1,1,0,1,0,0,1,0,1,1,0,0,1
    int inArrayUp[35] = { 1,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,1,0,0,0,0 };
   int inArrayDown[35] = { 1,1,1,0,1,0,0,1,0,1,1,0,0,1,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0};

    Serial.begin(9600); // sætter Baudrate
    pinMode(33, OUTPUT); // sætter pin 33 til output til on
    pinMode(31, OUTPUT); // sætter pin 31 til output til retning
    Slave_Array_Read test;



    for(;;)
    {
        
        test.FunctionsValidateCall(inArrayUp);
    
    }

}
#include "Slave_Array_Read.h"
#include "Light_Class.h"
#include <Arduino.h>
#include <avr/io.h>
Slave_Array_Read test;

 int llightOn[35] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,1,1,0,0,0,0 };

 int llightOff[35] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0,1,0,0,0,0 };

 int lincreaseBrightness[35] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,1,0,0,0,0 };

 int ldecreaseBrightness[35] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,0,0 };

 int lstop[35] = { 1,1,1,0,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,0,0,0 };

void setup()
{
    Serial.begin(115200);
    pinMode(2, OUTPUT);
    test.FunctionsValidateCall(llightOn);
    _delay_ms(2500);
    test.FunctionsValidateCall(ldecreaseBrightness);
    _delay_ms(2500);
    test.FunctionsValidateCall(ldecreaseBrightness);
    _delay_ms(2500);
    test.FunctionsValidateCall(ldecreaseBrightness);
}

void loop()
{
    


}

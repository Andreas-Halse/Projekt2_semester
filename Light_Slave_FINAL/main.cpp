#include "Slave_Array_Read.h"
#include "Light_Class.h"
#include <Arduino.h>
#include <avr/io.h>
Slave_Array_Read test;

int testOn[35] =        { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,1,1,0,0,0,0 };

int  testOff[35] =      { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0,1,0,0,0,0 };

int testIncrease[35] =  { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,1,0,0,0,0 };

int testDecrease[35] =  { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,0,0 };

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    test.FunctionsValidateCall(testOn);
    _delay_ms(2000);
    test.FunctionsValidateCall(testDecrease);
    _delay_ms(2000);
    test.FunctionsValidateCall(testDecrease);
}

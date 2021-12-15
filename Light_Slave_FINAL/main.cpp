#include "Slave_Array_Read.h"
#include "Light_Class.h"
#include <Arduino.h>
#include <avr/io.h>
Slave_Array_Read test;
int testOn[35] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0,1,0,0,0,0 };

int  testOff[35] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,1,0,0,0,0 };

int testIncrease[35] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,1,0,0,0,0 };

int testDecrease[35] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,0,0 };
void setup()
{
  


    Serial.begin(9600); // ster Baudrate
    //pinMode(35, OUTPUT);
    Serial.print("tis");
    

}

void loop()
{
    Serial.print("tis");
    test.FunctionsValidateCall(testOn);

    test.FunctionsValidateCall(testDecrease);
    //test.FunctionsValidateCall(testDecrease);
    _delay_ms(10000);

}
/*int main()
{
    int testOn[35] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0,1,0,0,0,0 };

    int  testOff[35] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,1,0,0,0,0 };

    int testIncrease[35] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,1,0,0,0,0 };

    int testDecrease[35] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,0,0 };


    Serial.begin(9600); // sætter Baudrate
    //pinMode(35, OUTPUT);
    Slave_Array_Read test;


    for (;;)
    {
        Serial.print("tis")
        test.FunctionsValidateCall(testOn);

        test.FunctionsValidateCall(testDecrease); 
        //test.FunctionsValidateCall(testDecrease);
        _delay_ms(10000);


    }
}*/
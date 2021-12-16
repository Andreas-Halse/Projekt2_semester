#include "Slave_Array_read.h"
#include "Light_Class.h"
#include <avr/io.h>
#include <Arduino.h>

/*
d. 13-12-2021
author: 1. version Julie
author: 2. version Elisabeth, Andreas
*/

Lys_Class A;

Slave_Array_Read::Slave_Array_Read()
{
}

bool Slave_Array_Read::StartSekvensValidate(int arrayIn[])
{
    int match = 0;

    for (int i = 0; i <= 3; i++)    // tjekker startbit sekvens er ens
    {
        if (arrayIn[i] == light[i])
        {
            match++;
        }
    }
    if (match == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Slave_Array_Read::AdresseSekvensValidate(int arrayIn[])
{
    int match = 0;
    int match_stop = 0;
    
        for (int j = 4; j <= 11; j++)
        {
            if (arrayIn[j] == light[j])
            {
                match++;
            }

        }
        for (int k = 4; k <= 11; k++)
        {
            if (arrayIn[k] == stop[k])
            {
                match_stop++;
            }

        }
        if (match == 8)
        {
            return true;
        }
        if (match_stop == 8)
        {
            return true;
        }
        else
        {
            return false;
        }
}

void Slave_Array_Read::FunctionsValidateCall(int arrayIn[])
{

    if (StartSekvensValidate(arrayIn) == true)
    {
        if (AdresseSekvensValidate(arrayIn) == true)
        {
            
            int counter_lightOn = 0;
            int counter_lightOff = 0;
            int counter_increaseBrightness = 0;
            int counter_decreaseBrightness = 0;
            int counter_stop = 0;
            for (int x = 15; x <= 30; x++)
            {
                if (lightOn[x] == arrayIn[x])
                {
                    counter_lightOn++;
                }
                if (lightOff[x] == arrayIn[x])
                {
                    counter_lightOff++;
                }
                if (increaseBrightness[x] == arrayIn[x])
                {
                    counter_increaseBrightness++;
                }
                if (decreaseBrightness[x] == arrayIn[x])
                {
                    counter_decreaseBrightness++;
                }
                if (stop[x] == arrayIn[x])
                {
                    counter_stop++;
                }
            }
            if (counter_lightOn == 16)
            {
                Serial.print("Turned on ");
                A.turnOn();
            }
            if (counter_lightOff == 16)
            {
                Serial.print("Turned off ");
                A.turnOff();
            }
            if (counter_increaseBrightness == 16)
            {
                Serial.print("increased ");
                A.increaseBrightness();
            }
            if (counter_decreaseBrightness == 16)
            {
                Serial.print("Decreased ");
                A.decreaseBrightness();
            }
            if (counter_stop == 16)
            {
                  A.turnOff();
            }
        }
    }
}

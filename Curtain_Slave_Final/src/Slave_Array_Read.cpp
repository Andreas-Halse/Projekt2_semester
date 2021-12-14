#include "Slave_Array_Read.hpp"
#include "Motor_module.hpp"
#include <avr/io.h>
#include <Arduino.h>


/*
d. 13-12-2021
author: 1. version Julie
author: 2. version Elisabeth, sekundÊr: Andreas.
*/

Slave_Array_Read::Slave_Array_Read()
{
}

bool Slave_Array_Read::StartSekvensValidate(int arrayIn[])
{
	int match = 0;

	for (int i = 0; i <= 3; i++)	// tjekker startbit sekvens er ens
	{
		if (arrayIn[i] == curtain[i])
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
	if (StartSekvensValidate(arrayIn) == true)	//hvis start sekvens er ens, gÂr den ned i det her loop og tjekker 
	{
		for (int j = 4; j <= 11; j++)
		{
			if (arrayIn[j] == curtain[j])
			{
				match++;
			}
			else
			{
				return false;
			}
		}
		if (match == 8)
		{
			Serial.print("adresse sekvens virker");
			return true;
		}
	}
	return false;
}

void Slave_Array_Read::FunctionsValidateCall(int arrayIn[])
{
	Motor_module A;
	int counter_rollUp = 0;
	int counter_rollDown = 0;
	int counter_stop = 0;
	if (StartSekvensValidate(arrayIn) == true)
	{
		if (AdresseSekvensValidate(arrayIn) == true)
		{
			for (int x = 10; x <= 17; x++)
			{
				if (curtain[x] == arrayIn[x])
				{
					counter_rollUp = counter_rollUp + 1;
				}
				else if (curtain[x] == arrayIn[x])
				{
					counter_rollDown = counter_rollDown + 1;
				}

				else if (stop[x] == arrayIn[x])
				{
					counter_stop = counter_stop +1;
				}
			}
		if (counter_rollUp == 8)
		{
			A.rollUp();
		}
		if (counter_rollDown == 8)
		{
			A.rollUp();
		}
		if (counter_stop == 8)
		{
			A.stop();
		}
		}
	}
}

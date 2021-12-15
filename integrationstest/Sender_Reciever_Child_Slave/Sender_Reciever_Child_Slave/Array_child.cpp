
#include "Slave_Array_Read_cpp.h"
#include "Slave_Child.h"
#include <avr/io.h>
#include <Arduino.h>

/*
d. 13-12-2021
author: 1. version:  Elisabeth, sekundær: Andreas.
author: 2. version: Elisabeth.
*/


Slave_Array_Read_cpp::Slave_Array_Read_cpp()
{
}

bool Slave_Array_Read_cpp::StartSekvensValidate(int arrayIn[])
{
	int Match = 0;

	for (int i = 0; i <= 3; i++)	// tjekker startbit sekvens er ens
	{

		if (arrayIn[i] == child_array[i])
		{
			Match++;
		}
		
	}
	if (Match == 4)
	{
		return true;
	}
	else

	{
		return false;
	}
}

bool Slave_Array_Read_cpp::AdresseSekvensValidate(int arrayIn[])
{		
	int Match = 0;
	int Match_Stop = 0;

	if (StartSekvensValidate(arrayIn) == true)	//hvis start sekvens er ens, går den ned i det her loop og tjekker 
	{
		for (int j = 4; j <= 11; j++)
		{
			if (arrayIn[j] == child_array[j])
			{
				Match++;
			}
			for (int j = 4; j <= 11; j++)
			{
				if (arrayIn[j] == stop_array[j])
				{
					Match_Stop++;
				}
			}

		}
		if (Match == 8)
		{
			return true;

		}
		if (Match_Stop == 8)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
}

void Slave_Array_Read_cpp::FunctionsValidateCall(int arrayIn[])
{
	Slave_Child A;
	if (StartSekvensValidate(arrayIn) == true)
	{
		if (AdresseSekvensValidate(arrayIn) == true)
		{
			int CounterOn = 0;
			int CounterOff = 0;
			int CounterStop = 0;

			for (int x = 15; x <= 30; x++)
			{
				if (activate_array[x] == arrayIn[x])
				{
					CounterOn++;
				}
				if (deactivate_array[x] == arrayIn[x])
				{
					CounterOff++;
				}

				if (arrayIn[x] == stop_array[x])
				{
					CounterStop++;
				}

				if (CounterOn == 16)
				{
					Serial.print("aktiveret");
					A.activate();
				}
				if (CounterOff == 16)
				{
					Serial.print("deaktiveret");
					A.deactivate();
				}
				if (CounterStop == 16)
				{
					A.stop();
				}
			}
		}
	}

}

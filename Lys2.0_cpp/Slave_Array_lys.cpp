#include "Lys_Class.h"
#include "Slave_Array_read.h"

#include "Slave_Array_Read.h"
#include "Lys_Class.h"

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
	bool startSekvens = false;

	for (int i = 0; i <= 3; i++)	// tjekker startbit sekvens er ens
	{

		if (arrayIn[i] == light_array[i])
		{
			startSekvens = true;
		}
		else
		{
			startSekvens = false;
			break;
		}
	}
	if (startSekvens)
	{
		return true;
	}
}

bool Slave_Array_Read_cpp::AdresseSekvensValidate(int arrayIn[])
{
	bool adresseSekvens = false;
	if (StartSekvensValidate(arrayIn) == true)	//hvis start sekvens er ens, går den ned i det her loop og tjekker 
	{
		for (int j = 4; j <= 11; j++)
		{
			if (arrayIn[j] == light_array[j])
			{
				adresseSekvens = true;
			}
			else
			{
				adresseSekvens = false;
				break;
			}
		}
		if (adresseSekvens == true)
		{
			return true;
		}

	}
}

void Slave_Array_Read_cpp::FunctionsValidateCall(int arrayIn[])
{
	Lys_Class A;
	if (StartSekvensValidate(arrayIn) == true)
	{
		if (AdresseSekvensValidate(arrayIn) == true)
		{
			for (int x = 10; x <= 17; x++)
			{
				if (lightsOn_array[x] == arrayIn[x])
				{
					A.turnOn();
				}
				else if (lightsOff_array[x] == arrayIn[x])
				{
					A.turnOff();
				}

				else if (increaseBrightness_array[x] == arrayIn[x])
				{
					A.increaseBrightness();
				}
			}

		}
		else
		{
			//udskriv fejlmeddelse1 ( adr sekvens er ikke ens)

		}
	}
	else
	{
		// udskriv fejlmeddelse2 ( start sek.er ikke ens)
	}









}

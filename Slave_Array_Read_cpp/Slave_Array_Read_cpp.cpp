
include "Slave_Array_Read_cpp.h"
#include "Slave_Child_Class.h"

/*
d. 13-12-2021
author: 1. version:  Elisabeth, sekund�r: Andreas.
author: 2. version:
*/


Slave_Array_Read_cpp::Slave_Array_Read_cpp()
{
}

bool Slave_Array_Read_cpp::StartSekvensValidate(int arrayIn[])
{
	bool startSekvens = false;

	for (int i = 0; i <= 3; i++)	// tjekker startbit sekvens er ens
	{

		if (arrayIn[i] == child[i])
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
	if (StartSekvensValidate(arrayIn) == true)	//hvis start sekvens er ens, g�r den ned i det her loop og tjekker 
	{
		for (int j = 4; j <= 11; j++)
		{
			if (arrayIn[j] == child[j])
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
	Slave_Child A;
	if (StartSekvensValidate(arrayIn) == true)
	{
		if (AdresseSekvensValidate(arrayIn) == true)
		{
			for (int x = 10; x <= 17; x++)
			{
				if (activate[x] == arrayIn[x])
				{
					A.activate();
				}
				else if (deactivate[x] == arrayIn[x])
				{
					A.deactivate();
				}

				else if (stop[x] == arrayIn[x])
				{
					A.stop();
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

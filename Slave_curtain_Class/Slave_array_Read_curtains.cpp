#include "Slave_array_Read_curtains.h"
#include "Slave_curtains.h"


/*****
d. 13-12-2021
author: 1. version:  Elisabeth
author: 2. version:
*/


Slave_Array_Read::Slave_Array_Read()
{
}

bool Slave_Array_Read::StartSekvensValidate(int arrayIn[])
{
	bool startSekvens = false;

	for (int i = 0; i <= 3; i++)	// tjekker startbit sekvens er ens
	{

		if (arrayIn[i] == Slave_curtains[i])
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

bool Slave_Array_Read::AdresseSekvensValidate(int arrayIn[])
{
	bool adresseSekvens = false;
	if (StartSekvensValidate(arrayIn) == true)	//hvis start sekvens er ens, går den ned i det her loop og tjekker 
	{
		for (int j = 4; j <= 11; j++)
		{
			if (arrayIn[j] == Slave_curtains[j])
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

void Slave_Array_Read::FunctionsValidateCall(int arrayIn[])
{
	Slave_curtains A;
	if (StartSekvensValidate(arrayIn) == true)
	{
		if (AdresseSekvensValidate(arrayIn) == true)
		{
			for (int x = 10; x <= 17; x++)
			{
				if (rollDown[x] == arrayIn[x])
				{
					A.rollDown();
				}
				else if (rollUp[x] == arrayIn[x])
				{
					A.rollUp();
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

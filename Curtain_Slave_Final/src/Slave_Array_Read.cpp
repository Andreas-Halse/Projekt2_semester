#include "Slave_Array_Read.hpp"
#include "Motor_module.hpp"


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

bool Slave_Array_Read::AdresseSekvensValidate(int arrayIn[])
{
	bool adresseSekvens = false;
	if (StartSekvensValidate(arrayIn) == true)	//hvis start sekvens er ens, gÂr den ned i det her loop og tjekker 
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

void Slave_Array_Read::FunctionsValidateCall(int arrayIn[])
{
	Motor_module A;
	if (StartSekvensValidate(arrayIn) == true)
	{
		if (AdresseSekvensValidate(arrayIn) == true)
		{
			for (int x = 10; x <= 17; x++)
			{
				if (activateChild[x] == arrayIn[x])
				{
					A.activate();
				}
				else if (deactivateChild[x] == arrayIn[x])
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

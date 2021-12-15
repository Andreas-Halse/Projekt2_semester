#include "Slave_Array_Read.h"
#include "Motor_module.h"
#include <avr/io.h>
#include <Arduino.h>


/*
d. 13-12-2021
author: 1. version Julie
author: 2. version Elisabeth, Andreas
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
	int match_stop = 0;
	if (StartSekvensValidate(arrayIn) == true)	//hvis start sekvens er ens, g?r den ned i det her loop og tjekker 
	{
		for (int j = 4; j <= 11; j++)
		{
			if (arrayIn[j] == curtain[j])
			{
				match++;
			}

		}
		for (int j = 4; j <= 11; j++)
		{
			if (arrayIn[j] == stop[j])
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
}

void Slave_Array_Read::FunctionsValidateCall(int arrayIn[])
{
	Motor_module A;
	if (StartSekvensValidate(arrayIn) == true)
	{
		if (AdresseSekvensValidate(arrayIn) == true)
		{
			//digitalWrite(33, HIGH); // t?nder motor
			int counter_rollUp = 0;
			int counter_rollDown = 0;
			int counter_stop = 0;
			for (int x = 15; x <= 30; x++)
			{
				if (rollUp[x] == arrayIn[x])
				{
					counter_rollUp++;
				}
				if (rollDown[x] == arrayIn[x])
				{
					counter_rollDown++;
				}

				if (stop[x] == arrayIn[x])
				{
					counter_stop++;
				}
			}
			if (counter_rollUp == 16)
			{
				A.rollUp();
			}
			if (counter_rollDown == 16)
			{
				A.rollDown();
			}
			if (counter_stop == 16)
			{
				A.stop();
			}
		}
	}
}

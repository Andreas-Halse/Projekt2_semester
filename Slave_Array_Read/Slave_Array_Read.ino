/*
 Name:		Slave_Array_Read.ino
 Created:	12/13/2021 10:05:21 AM
 Author:	Elisabeth Lennert
*/

using namespace std;
#include "Slave_Array_Read.h"

/*
00..3 plads = startsekvens
4..7. plads= adresse til subsystemer
8-9. plads = suffix
10.-17. = funktionskald
18.-20.suffix
21.-23 = stopsekvens
*/
const int activateChild[34] = { 1,1,1,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0 };
const int deactivateChild[34] = { 1,1,1,0,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,0,0,0 };
const int stop[34] = { 1,1,1,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,0,0,0 };

int main()
{
		int const dummy[34] = { 1,1,1,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0 }; // første 4 = start, næste 8 er child adr i manchester
		int const child [12] = {1,1,1,0,1,0,0,1,1,0,0,1};
		bool startSekvens = false;
		bool adrSekvens = false;
	
		for (int i = 0; i <=3;i++)	// tjekker startbit sekvens er ens
		{

			if (dummy[i] == child[i])
			{
				startSekvens = true;
			}
			else
			{
				startSekvens = false;
			}
		}
		if (startSekvens == true)	//hvis start sekvens er ens, går den ned i det her loop og tjekker 
		{
			for (int j = 4; j <= 11; j++)
			{
				if (dummy[j] == child[j])
				{
					adrSekvens = true;
				}
				else
				{
					adrSekvens = false;
				}
			}
		}
		

		if (adrSekvens = true)	// nu tjekkes adressesekvens er true
		{
			for (int x = 10; x <=17 ; x++)
			{	
				if (activateChild[x] == dummy[x])
				{
					// kald funktion
				}
				else if (deactivateChild[x] == dummy[x])
				{
					//kald funktion
				}

				else if (stop[x] == dummy[x])
				{
					//kald funktion
				}
			}
		}


}





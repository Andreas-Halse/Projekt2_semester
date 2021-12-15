#include "Slave_Child.h"
#include "Arduino.h"

/*
* @brief constructor til klassen 
* 
*/

Slave_Child::Slave_Child()
{	
}

/*
* @brief metoden sl�r EM til
* @returns bool status v�rdi for at kunne sende status til master
*
*/
void Slave_Child::activate()
{
	digitalWrite(30, HIGH);							//s�tter alle ben til port C til 0
}

/*
* @brief metoden sl�r EM fra
* @returns bool status v�rdi for at kunne sende status til master
*
*/
void Slave_Child::deactivate()
{
	digitalWrite(30, LOW);					//s�tter alle ben til port C til 0
}


/*
* @brief metoden kalder deactivate() metoden
* @returns void
*
*/
void Slave_Child::stop()
{
		deactivate();
}

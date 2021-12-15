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
* @brief metoden slår EM til
* @returns bool status værdi for at kunne sende status til master
*
*/
void Slave_Child::activate()
{
	digitalWrite(30, HIGH);							//sætter alle ben til port C til 0
}

/*
* @brief metoden slår EM fra
* @returns bool status værdi for at kunne sende status til master
*
*/
void Slave_Child::deactivate()
{
	digitalWrite(30, LOW);					//sætter alle ben til port C til 0
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

#include "Slave_Child.h"

/*
* @brief constructor til klassen 
* 
*/

Slave_Child::Slave_Child()
{	
	//opsætning af association
}


/*
* @brief metoden slår EM til
* @returns bool status værdi for at kunne sende status til master
*
*/
bool Slave_Child::activate()
{
	if ((PINA & 0b00001000) == 0)			//ikke korrekt betingelse, dette skal være funktionskaldet fra masteren
	PORTC = 0x00;							//sætter alle ben til port C til 0
	state_ = 1;								//opdater status
}

/*
* @brief metoden slår EM fra
* @returns bool status værdi for at kunne sende status til master
*
*/
bool Slave_Child::deactivate()
{
	if ((PINA & 0b00001000) == 1)			//ikke korrekt betingelse, skal være funktionskaldet fra masteren
	PORTC = 0xFF;							//sætter alle ben til port C til 0
	state_ = 0;								//opdater status
}


/*
* @brief metoden kalder deactivate() metoden
* @returns void
*
*/
void Slave_Child::stop()
{
	if (true)								//ikke korrekt betingelse, skal være funktionskaldet fra masteren
		deactivate();
}

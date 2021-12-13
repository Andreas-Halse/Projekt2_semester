#include "Slave_Child_Class.h"

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
bool Slave_Child::activate()
{
	PORTC = 0x00;							//s�tter alle ben til port C til 0
	state_ = 1;								//opdater status
}

/*
* @brief metoden sl�r EM fra
* @returns bool status v�rdi for at kunne sende status til master
*
*/
bool Slave_Child::deactivate()
{
	PORTC = 0xFF;							//s�tter alle ben til port C til 0
	state_ = 0;								//opdater status
}


/*
* @brief metoden kalder deactivate() metoden
* @returns void
*
*/
void Slave_Child::stop()
{
	if (true)								//ikke korrekt betingelse, skal v�re funktionskaldet fra masteren
		deactivate();
}

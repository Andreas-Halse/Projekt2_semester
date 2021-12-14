#include "Slave_child.h"
#include "Slave_child_array.h"


/*
* @brief constructor til klassen
*
*/

Slave_Child::Slave_Child(Slave_Array_Read_cpp *ArrayPtr)
{
	ArrayPtr_ = ArrayPtr;
}


/*
* @brief metoden slår EM til
* @returns bool status værdi for at kunne sende status til master
*
*/
bool Slave_Child::activate()
{
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

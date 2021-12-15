#include "DE2_IF.h"
#include <avr/io.h>
#include <Arduino.h>

/*
*@Author Julie Zepernick Jepsen
*@brief default constructor
*@params bool to set signalUnlock, bool to set signalPermanentLock
*/
DE2_IF::DE2_IF(bool sigUnlock, bool sigPermLock)
{
	signalUnlock_ = sigUnlock;
}

/*
* @brief $name to recieve high signal from arduino pin 56.
* Set attribute to true if pin is high, and false if not.
*/
bool DE2_IF::signalUnlock()
{
	if (PINC & 0b00001000)
	{
		signalUnlock_ = true;
	}
	else
	{
		signalUnlock_ = false;
	}
	return signalUnlock_;
}


/*
* @brief $name to print out messages via UART COM port
*/
void DE2_IF::checkPassword()
{
	//if statement to print pass / fail of password entry
	if (signalUnlock_ == true)
	{
			Serial.print("Password Correct \n");

	}
	
}




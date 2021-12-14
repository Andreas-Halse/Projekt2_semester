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
	signalPermLock_ = sigPermLock;
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
* @brief $name to receive high signal from arduino pin 58
* set attribute signalPernLock_ to true if three password attempts was incorrect.
*/

void DE2_IF::signalPermLock()
{
	if (PINC & 0b00100000)
	{
		signalPermLock_ = true;
	}
	else
	{
		signalPermLock_ = false;
	}
}

/*
* @brief $name to print out messages via UART COM port
*/
void DE2_IF::print() const
{
	//if statement to print pass / fail of password entry
	if (signalUnlock_ == true)
	{
		Serial.print("Password Correct \n");
	}
	else if (signalUnlock_ == false)
	{
		Serial.print("Password Incorrect \n");
	}

	//if statement to print permLock mode
	if (signalPermLock_ == true)
	{
		Serial.print("System is in permanent lock. \n Please go to user manual for reset. ");
	}
}




#include "DE2_IF.h"
#include <avr/io.h>

/*@brief default constructor
* @params bool to set signalUnlock, bool to set signalPermanentLock
*/
DE2_IF::DE2_IF(bool sigUnlock, bool sigPermLock)
{
	signalUnlock_ = sigUnlock;
	signalPermLock_ = sigPermLock;
}

/*
* @brief method to recieve high signal from arduino pin 56.
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
#include "DE2_IF.h"

DE2_IF::DE2_IF()
{
}

//sets attributes for login
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


//sets attribute for permanent lock mode
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

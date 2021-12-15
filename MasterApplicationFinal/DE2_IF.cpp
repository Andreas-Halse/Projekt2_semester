#include "DE2_IF.h"
#include "Arduino.h"

DE2_IF::DE2_IF()
{
	i_ = 0;
	Allowprint_ = false;
	DDRC = 0x00;
}

void DE2_IF::resetI()
{
	i_ = 0;
}

bool DE2_IF::signalUnlocked() const
{
	if (PINC & 0b00001000)
	{
		return true;
	}
	else
		return false;
}

bool DE2_IF::getAllowPrint() const
{
	return Allowprint_;
}

void DE2_IF::setAllowPrint(bool x)
{
	Allowprint_ = x;
}

int DE2_IF::getI() const
{
	return i_;
}

void DE2_IF::setI()
{
	i_ = 1;
}

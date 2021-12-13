/*
*@ Author Oliver V. Schousboe - Date 12.12.2021
*@ Brief File that contains implementation for all method calls in class related
*/

#include "x10_Sender.h"
#include <avr/delay.h>
#include <avr/io.h>

/*
*@ brief constructor for class x10_Sender that initializes private attributes to appropriate values.
*/

x10_Sender::x10_Sender()
{
	bitcounter_ = 0;
	twoMessagesSent_ = 0;
	countCrosses_ = 0;
	bitPointer_ = nullptr;
	DDRL = 0xFF;
}

/*
*@ brief method which sets private attribute 'twoMessagesSent' to zero
*@ return nothing
*/

void x10_Sender::setTwoMessagesSentToZero()
{
	twoMessagesSent_ = 0;
}

/*
*@ brief method that takes paramter and sets it to the private attribute bitPointer_
*@ parametres takes one constant char pointer
*@ return nothing
*/

void x10_Sender::setBitPointer(const char* ptr)  // read only pointer
{
	bitPointer_ = ptr;
}

/*
*@ brief method which sets external pin PL0 on ATmega2560 to zero or 1 in a switch statement based on private attributes. It also counts zero crossings to make sure there are 3 zerocrossing before sending another message
*@ return
*/

void x10_Sender::sendx10Message()
{
	if (twoMessagesSent_ == 2)
	{
		return;
	}
	else
	{
		switch (bitPointer_[bitcounter_])
		{
		case '1':
			PORTL |= 0b00000001;
			bitcounter_++;
			_delay_ms(1);
			PORTL &= 0b11111110;
			break;
		case '0':
			bitcounter_++;
			break;
		case '\0':
			++countCrosses_;
			if (countCrosses_ == 3)
			{
				bitcounter_ -= bitcounter_;
				countCrosses_ = 0;
				twoMessagesSent_++;
			}
			break;
		default:
			break;
		}
	}
}
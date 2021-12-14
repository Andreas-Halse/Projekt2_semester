#include "x10_reciever.h"


x10_reciever reciever;

ISR(INT3_vect)
{
	if (startBitCheck())
	{
		reciever.readData();
	}

}

void setup()
{

}

void loop()
{

}

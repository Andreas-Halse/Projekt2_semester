#include "Lys_Class.h"
#include <avr/io.h>

using namespace std;

int main()
{
	pinMode(13, OUTPUT); //Sætter pin 13 til output
	Lys_Class Lys;

	for (;;)
	{
		Lys.turnOn();
		_delay_ms(1234);
		Lys.decreaseBrightness();
		_delay_ms(1234);
		Lys.decreaseBrightness();
		_delay_ms(1234);
		Lys.decreaseBrightness();
		_delay_ms(1234);
		Lys.decreaseBrightness();


	}
}


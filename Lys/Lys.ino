/*
 Name:		Lys.ino
 Created:	12/12/2021 3:57:29 PM
 Author:	
*/

#include <avr/io.h>

using namespace std;

int volatile intensitet = 220;


void setup() {
	pinMode(13, OUTPUT); //sætter 13 til output
}


void loop() {

		turnOn();
		_delay_ms(1000);
		decreaseBrightness();
		_delay_ms(1000);
		decreaseBrightness();
		_delay_ms(1000);
		decreaseBrightness();
		_delay_ms(1000);
		decreaseBrightness();
		_delay_ms(1000);
		decreaseBrightness();
		_delay_ms(1000);
}

void turnOn() {
	if (intensitet <= 0)
	{
		intensitet = 220;
		analogWrite(13, intensitet);
	}
	else
	{
		analogWrite(13, intensitet);
	}
}

void turnOff() 
{
	analogWrite(13, LOW);
}

void increaseBrightness() {

	if (intensitet <= 220)
	{
		intensitet = intensitet + 55;
	}
	else
	{
		intensitet = 220;
	}
	
	analogWrite(13, intensitet);
}

void decreaseBrightness() {

	if (intensitet >= 55) 
	{
		intensitet = intensitet - 55;
		analogWrite(13, intensitet);
	} 
	else 
	{
		intensitet = 0;
	}
}



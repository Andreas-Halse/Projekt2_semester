/*
 Name:		Lys.ino
 Created:	12/12/2021 3:57:29 PM
 Author:	
*/

#include <avr/io.h>

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
		decreaseBrightness(); // =0
		_delay_ms(1000);
		decreaseBrightness(); // test af validering
		_delay_ms(1000);
		increaseBrightness(); 
		_delay_ms(1000);
		increaseBrightness();
		_delay_ms(1000);
		increaseBrightness();
		_delay_ms(1000);
		increaseBrightness(); // = 100
		_delay_ms(1000);
		increaseBrightness(); // test af validering
		turnOff();
		_delay_ms(5000);
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

	if (intensitet <= 165)
	{
		intensitet = intensitet + 55;
		analogWrite(13, intensitet);
	}
	else
	{
		intensitet = 220;
		analogWrite(13, intensitet);
	}
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
		analogWrite(13, intensitet);
	}
}



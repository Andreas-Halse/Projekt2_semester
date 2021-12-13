/*
 Name:		Lys.ino
 Created:	12/12/2021 3:57:29 PM
 Author:
*/

#include <avr/io.h>


using namespace std;

int volatile intensitet = 220;			//Variabel til at gemme lys intensitet


void setup() {
	pinMode(13, OUTPUT);				//Sætter pin 13 til output
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

void turnOn() {							//Tænder lyset
	if (intensitet <= 0)
	{
		intensitet = 220;				//Hvis intensitet er 0 - så tænd 100%
		analogWrite(13, intensitet);
	}
	else
	{
		analogWrite(13, intensitet);	//Ellers tænd ved sidste intensitet
	}
}

void turnOff()							//Slukker lyset
{
	analogWrite(13, LOW);
}

void increaseBrightness() {				//Øger intensitet med 25%

	if (intensitet <= 165)				//Validering
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

void decreaseBrightness() {				//Sænker intensitet med 25%

	if (intensitet >= 55)				//Validering
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



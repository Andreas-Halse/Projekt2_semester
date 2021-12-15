#include "Light_Class.h"
#include <avr/io.h>
#include <Arduino.h>


Lys_Class::Lys_Class()
{
}

void Lys_Class::turnOn()				//T�nder lys
{
	if (intensitet <= 0)				//Hvis intensitet er 0 - s� t�nd 100%
	{
		Serial.print("if Turn on/");
		intensitet = 220;
		analogWrite(2, intensitet);
	}
	else								//Ellers t�nd ved sidste intensitet
	{
		Serial.print("Else Turn on/");
		analogWrite(2, intensitet);
	}
}

void Lys_Class::turnOff()
{
	Serial.print("Turn off/");
	analogWrite(2, LOW);
}

void Lys_Class::increaseBrightness()	//�ger lys intensitet
{
	if (intensitet <= 165)				//Validering
	{
		Serial.print("if incB/");
		intensitet = intensitet + 55;
		analogWrite(2, intensitet);
	}
	else
	{
		Serial.print("Else incB/");
		intensitet = 220;
		analogWrite(2, intensitet);
	}
}

void Lys_Class::decreaseBrightness()	//S�nker lys intensitet
{
	if (intensitet >= 110)				//Validering
	{
		Serial.print("If decB/");
		intensitet -= 55;
		analogWrite(2, intensitet);
	}
	else
	{
		Serial.print("Else decB/");
		intensitet = 55;
		analogWrite(2, intensitet);
	}



	/*do
	{
		intensitet = intensitet - 55;
		analogWrite(, intensitet);
	} while (intensitet >= 110);
	*/
}

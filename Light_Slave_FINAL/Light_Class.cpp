#include "Light_Class.h"
#include <avr/io.h>
#include <Arduino.h>
#include "Slave_Array_read.h"


Lys_Class::Lys_Class()
{
}

void Lys_Class::turnOn()				//Tænder lys
{
	if (intensitet <= 0)				//Hvis intensitet er 0 - så tænd 100%
	{
		intensitet = 220;
		analogWrite(35, intensitet);
	}
	else								//Ellers tænd ved sidste intensitet
	{
		analogWrite(35, intensitet);
	}
}

void Lys_Class::turnOff()
{
	analogWrite(35, LOW);
}

void Lys_Class::increaseBrightness()	//Øger lys intensitet
{
	if (intensitet <= 165)				//Validering
	{
		intensitet = intensitet + 55;
		analogWrite(35, intensitet);
	}
	else
	{
		intensitet = 220;
		analogWrite(35, intensitet);
	}
}

void Lys_Class::decreaseBrightness()	//Sænker lys intensitet
{
	if (intensitet > 54)				//Validering
	{
		intensitet = intensitet - 55;
		analogWrite(35, intensitet);
	}
	else
	{
		intensitet = 55;
		analogWrite(35, intensitet);
	}
}

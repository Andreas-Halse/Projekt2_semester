#include "Lys_Class.h"
#include <avr/io.h>
#include <Slave_Array_Read.h>


Lys_Class::Lys_Class() 
{
}

void Lys_Class::turnOn()				//Tænder lys
{
	if (intensitet <= 0)				//Hvis intensitet er 0 - så tænd 100%
	{
		intensitet = 220;				
		analogWrite(13, intensitet);
	}
	else								//Ellers tænd ved sidste intensitet
	{
		analogWrite(13, intensitet);	
	}
}

void Lys_Class::turnOff()
{
	analogWrite(13, LOW);
}

void Lys_Class::increaseBrightness()	//Øger lys intensitet
{
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

void Lys_Class::decreaseBrightness()	//Sænker lys intensitet
{
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

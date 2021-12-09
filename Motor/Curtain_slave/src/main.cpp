/*
 Name:		Slave_Curtain.ino
 Created:	12/7/2021 4:43:53 PM
 Author:	andreashalse
*/
#define F_CPU 16000000
#include <avr/io.h>
#include <Arduino.h>

int main()
{
	pinMode(PH3, OUTPUT); // Sætter Hastigheds pin (PWM)
	pinMode(PE3, OUTPUT); // Sætter retnings pin
	Serial.begin(9600);
	pinMode(PA6, INPUT); // knap til retning
	pinMode(PA5, INPUT); // tændsluk knap  (PWM)



for (;;)
{
	bool retning = false;
	bool on = false;

	if (digitalRead(PA5) == 0)
	on = true;

	if (digitalRead(PA6) == 0)
		retning = true;

	if (on == true && retning == false)
	{
		digitalWrite(PH3, HIGH);
	}
	else
	{
		digitalWrite(PH3, LOW);
	}
	if (on == true && retning == true)
	{
		digitalWrite(PH3, HIGH);
		digitalWrite(PE3, HIGH);
	}




  /* code */
}





}
/*
 Name:		Slave_Curtain.ino
 Created:	12/7/2021 4:43:53 PM
 Author:	andreashalse
*/
#define F_CPU 16000000
#include "avr/io.h"



// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(9, OUTPUT); // Sætter Hastigheds pin (PWM)
	pinMode(8, OUTPUT); // Sætter retnings pin
	Serial.begin(9600);
	pinMode(PORTA6, INPUT); // knap til retning
	pinMode(PORTA5, INPUT); // tændsluk knap

}

// the loop function runs over and over again until power down or reset
void loop() {
	bool retning =false;
	bool on = false;

	if (digitalRead(PORT5) == 1)
		~on;

	if (digitalRead(PORT6) == 1)
		~retning;

	if (on == true && retning == false)
	{
		digitalWrite(9, HIGH);
	}
	else
	{
		digitalWrite(9, LOW);
	}
	if (on == true && retning == on)
	{
		digitalWrite(9, HIGH);
		digitalWrite(8, HIGH);
	}

}

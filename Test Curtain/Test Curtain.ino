/*
 Name:		Slave_Curtain.ino
 Created:	12/7/2021 4:43:53 PM
 Author:	andreashalse
*/
#define F_CPU 16000000
#include "avr/io.h"

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(9, OUTPUT); // S�tter Hastigheds pin (PWM)
	pinMode(8, OUTPUT); // S�tter retnings pin
	//Serial.begin(9600);
	pinMode(1, INPUT_PULLUP); // knap til retning - set switch_pin as Input //Pullup means default state = HIGH
	pinMode(2, INPUT_PULLUP); // t�ndsluk knap - set switch_pin as Input //Pullup means default state = HIGH

}

// the loop function runs over and over again until power down or reset
void loop() {
	bool retning = false;
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



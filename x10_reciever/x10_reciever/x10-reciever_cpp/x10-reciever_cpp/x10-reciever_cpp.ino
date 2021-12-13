/*
 Name:		x10_reciever_cpp.ino
 Created:	12/13/2021 1:01:51 PM
 Author:	oscar
*/

#include <avr/io.h>
int volatile x = 0;
// the setup function runs once when you press reset or power the board

void setup() {
	pinMode(13, OUTPUT);
	x = 70;
}

// the loop function runs over and over again until power down or reset
void loop() {
	digitalWrite(13, HIGH);
	_delay_us(100);
	digitalWrite(13, LOW);
	_delay_us(100 - x);
}

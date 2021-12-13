/*
 Name:		DE2_IF.ino
 Created:	12/13/2021 11:53:32 AM
 Author:	juliezepernickjepsen
*/
#include <Arduino.h>
#include "DE2_IF.h"

DE2_IF test;		//globalt objekt til test

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	DDRC = 0x00;
}

// the loop function runs over and over again until power down or reset
void loop() {
	test.signalUnlock();
	test.print();

}





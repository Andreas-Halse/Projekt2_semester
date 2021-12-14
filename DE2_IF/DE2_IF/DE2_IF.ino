
/*
 Name:		DE2_IF.ino
 Created:	12/13/2021 12:59:09 PM
 Author:	juliezepernickjepsen
*/
#define F_CPU 16000000

#include "DE2_IF.h"
#include <avr/io.h>
#include <Arduino.h>
DE2_IF test;		//globalt objekt til test


void setup() {
	Serial.begin(9600);
	DDRC = 0x00;
}


void loop() {
	test.signalUnlock();
	test.print();
	test.signalPermLock();
	test.print();
}



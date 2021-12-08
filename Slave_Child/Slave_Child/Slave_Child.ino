/*
 Name:		Slave_Child.ino
 Created:	12/7/2021 11:58:48 AM
 Author:	juliezepernickjepsen
 Iteration: Test code for EM
*/

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

/*
* @brief Setup of pins and UART to baud rate 9600
* @returns void
* @Pin36 as output to MOSFET in HW.
*/
void setup() {
	DDRA = 0x00;			//SW ouput
	DDRC = 0xFF;			// input
}

void loop() {
	if ((PINA & 0b00001000) == 0) // hvis SW3 er trykket
	{
		PORTC = 0x00;		//sæt alle ben på port C til 0

	}
	else
	{
		PORTC = 0xFF;		//ellers sæt alle ben på port C til 1. 
	}
}

//void setup() {
//	pinMode(36, OUTPUT);
//	Serial.begin(9600);
//	pinMode(PORTA7, INPUT);
//}
//
//void loop() {
//	if (digitalRead(PORTA7) == 1)
//	{
//		digitalWrite(PIN_A9, LOW);
//	}
//	else
//		digitalWrite(PIN_A9, HIGH);
//}
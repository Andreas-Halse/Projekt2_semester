/*
	Name:       Class_Sender.ino   -- Also known as MASTER MAIN CODE
	Created:	12-12-2021 11:17:23
	Author:     Oliver V. Schousboe
*/
#include "PC_IF.h"
#include "x10_Sender.h"
#include "Control.h"


//Global objects with appropriate initializations
PC_IF pc;
x10_Sender x10;
Control control(&pc, &x10);

//Interrupt service routine for clock overflow -- attempts to send bit when clock 1 overflows
ISR(TIMER1_COMPA_vect)
{
	if (PORTL | 0b00000000)				// If ON
	{
		PORTL &= 0b11111011;			// Turn off
	}
	else if (PORTL | 0b00000100)		// Else If off
	{
		PORTL |= 0b00000100;			// Turn on
	}
	control.sendMessage();
}

//Global character arrays that contain start sequence, address, and function (arrays below are just an example)
const char array1[11] = "1110101011";
const char array2[11] = "1111010111";

// The setup() function runs once each time the micro-controller starts
void setup()
{
	Serial.begin(9600);
	//starts timer 1 with a frequency of 50hz
	TCCR1B = 0b00001100;
	TCCR1A = 0x00;
	OCR1A = 624;
	//Enables interrupt for timer 1 (clock)
	TIMSK1 = 0x02;

	//Test for clock signal on PORTB 
	PORTL |= 0b00000100;
	sei();
}

// Infinite loop() function
void loop()
{
	if (Serial.available() > 0) {
		// read the incoming byte:
		pc.setMessageFromPC(Serial.read());
		if (control.getNumberFromPC() == 111)			// If serial information read is an 'O'
		{
			control.prepareNewMessageFromPc();
			control.prepareMessageTox10(array1);
		}
		if (control.getNumberFromPC() == 112)			// If serial information read is a 'P'
		{
			control.prepareNewMessageFromPc();
			control.prepareMessageTox10(array2);
		}
	}
}

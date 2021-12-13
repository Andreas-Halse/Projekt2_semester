/*
	Name:       Class_Sender.ino   -- Also known as MASTER MAIN CODE
	Created:	12-12-2021 11:17:23
	Author:     Oliver V. Schousboe
*/
#include "PC_IF.h"
#include "x10_Sender.h"
#include "Control.h"
#include "DE2_IF.h"



//Global objects with appropriate initializations
PC_IF pc;
x10_Sender x10;
DE2_IF password(false,false);
Control control(&pc, &x10, &password);


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
	control.printStartMenu();
}

// Infinite loop() function
void loop()
{
	if (Serial.available() > 0)
	{
		pc.setMessageFromPC(Serial.read());
		if (control.getNumberFromPC() == 76)	//76 = L. Activate EM lock. 
		{
			control.prepareNewMessageFromPc();
			control.prepareMessageTox10(control.setArray('AL'));
		}
		if (control.getNumberFromPC() == 68)	//69 = D. Deactivate EM lock
		{
			control.prepareNewMessageFromPc();
			control.prepareMessageTox10(control.setArray('DL'));
		}
		if (control.getNumberFromPC() == 85)	//85 = U. Roll up curtain
		{
			control.prepareNewMessageFromPc();
			control.prepareMessageTox10(control.setArray('RU'));
		}
		if (control.getNumberFromPC() == 67)	//67 = C. Roll down curtain
		{
			control.prepareNewMessageFromPc();
			control.prepareMessageTox10(control.setArray('RD'));
		}
		if (control.getNumberFromPC() == 79)	// 79 = O. Lights ON
		{
			control.prepareNewMessageFromPc();
			control.prepareMessageTox10(control.setArray('ON'));
		}
		if (control.getNumberFromPC() == 70)	// 70 = F. Lights OFF
		{
			control.prepareNewMessageFromPc();
			control.prepareMessageTox10(control.setArray('OF'));
		}
		if (control.getNumberFromPC() == 73)	// 73 = I.Increase brightness
		{
			control.prepareNewMessageFromPc();
			control.prepareMessageTox10(control.setArray('I'));
		}
		if (control.getNumberFromPC() == 68)	// 68 = F.Increase brightness
		{
			control.prepareNewMessageFromPc();
			control.prepareMessageTox10(control.setArray('D'));
		}
	}
}


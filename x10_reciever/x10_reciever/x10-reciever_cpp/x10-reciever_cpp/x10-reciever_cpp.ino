#include "x10_reciever.h"


void x10_reciever::initReciever()
{
	DDRA = 0x00;			// set to input to enable interrupt by pressing SW3
	pinMode(53, INPUT);		// the data read pin
	EICRA |= 0b01000000;		// any edge
	EIMSK |= 0b00001000;	//  activate INT3
	sei();					// enable interrupts
	Serial.begin(9600);		//not used in final build
}

void x10_reciever::loadIntoArray(int arr[SIZE])
{
	if (digitalRead(53) == HIGH)//if datapin high
	{
		//Serial.print("Test1\n");

		arr[i] = 1;		//load in i
		_i++;			//count up databit counter
		_zeroCounter = 0;//reset zerocounter
	}
	else if (digitalRead(53) == LOW)
	{
		//Serial.print("Test2\n");
		arr[i] = 0;
		_i++;
		_zeroCounter++;	// count up zerocounter
	}
}

bool x10_reciever::startBitCheck()
{
	if (_oneCounter >= 3)
	{
		return (true);
	}
	else if (digitalRead(53) == HIGH)
	{
		_oneCounter++;
		if (_arrayBool)
		{
			loadIntoArray(messageArray);
		}
		else
		{
			loadIntoArray(compareArray);
		}

	}
	else
	{
		_oneCounter = 0;//Makes sure random faulty ones are sorted out by setting one counter to zero if 3 ones arent sent in a row
	}
}

void x10_reciever::checkForStopBits()
{
	if (_zeroCounter >= 3)		//counts number of zeroes to check for stopbits
	{
		//Serial.print("zeroCounter overflow\n  ");
		_arrayBool = !_arrayBool;		//switch input array
		_zeroCounter = 0;		//reset zerocounter
		_i = 0;					// reset databit recieved counter to ensure
		_oneCounter = 0;
	}
	if (_arrayBool)
	{
		messageDone = true;
	}
}

void x10_reciever::readData()
{
	if (_i <= (SIZE + 1))
	{
		Serial.println(digitalRead(53));
		if (_arrayBool)		// if true load into messageArray if false compareArray
		{
			loadIntoArray(messageArray);
			checkForStopBits();
		}
		else								//Same thing
		{
			loadIntoArray(compareArray);
			checkForStopBits();
		}	
	}
	else
	{
		Serial.print("array too small");
	}
}

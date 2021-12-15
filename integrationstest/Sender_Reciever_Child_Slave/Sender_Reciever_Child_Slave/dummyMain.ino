#include "Slave_Child.h"
#include "ArrayCompareFinal.h"
#include "x10_reciever.h"
#include <avr/io.h>
#include <Arduino.h>
#include "Slave_Array_Read_cpp.h"
/*
 Name:		Slave_Array_Read.ino
 Created:	12/13/2021 10:05:21 AM
 Author:	Elisabeth Lennert
*/

using namespace std;


ArrayCompareFinal B;
Slave_Array_Read_cpp C;
x10_reciever reciever;

ISR(INT3_vect)
{
	if (reciever.startBitCheck())
	{
		reciever.readData();
	}

}

void setup()
{
	pinMode(30, OUTPUT);
	reciever.initReciever();
}

void loop()
{
	if (reciever._messageDone) //
	{
		cli();

		Serial.print("Both messages recieved comparing messages\n");

		Serial.print("the first array\n");
		for (int element : reciever._messageArray)//prints the array
		{
			Serial.println(element);
		}
		Serial.print("the second array\n");
		for (int element : reciever._compareArray)
		{
			Serial.println(element);
		}

		reciever.setMessageDone(false);
		
		if (B.ArrayDataCompare(reciever._compareArray, reciever._messageArray) == true)
		{
			Serial.print("egaul");
			C.FunctionsValidateCall(reciever._messageArray);
		}

		sei();
	}
}


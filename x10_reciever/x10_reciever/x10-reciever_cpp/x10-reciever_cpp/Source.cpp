#include "x10_reciever.h"
#include <avr/io.h>
#include <Arduino.h>
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
	reciever.initReciever();
}

void loop()
{
	if (messageDone) //
	{
		cli();
		//kald Andreas compare shit
		//Kald elisabeths funktions-v?lger shit
		// from here to the end of the second for loop is used for testing
		Serial.print("Both messages recieved comparing messages\n");

		Serial.print("the first array\n");
		for (int element : messageArray)//prints the array
		{
			Serial.println(element);
		}
		Serial.print("the second array\n");
		for (int element : compareArray)
		{
			Serial.println(element);
		}

		messageDone = false;



		sei();
	}
}

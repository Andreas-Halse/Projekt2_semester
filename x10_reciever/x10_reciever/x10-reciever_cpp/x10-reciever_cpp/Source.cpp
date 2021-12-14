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
	if (reciever._messageDone) //
	{
		cli();
		//kald Andreas compare shit
		//Kald elisabeths funktions-v?lger shit
		// from here to the end of the second for loop is used for testing
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



		sei();
	}
}

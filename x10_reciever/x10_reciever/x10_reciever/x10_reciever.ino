/*
 Name:		x_10_reciever.ino
 Created:	12/1/2021 10:55:26 AM
 Author:	oscar
*/
#include <avr/io.h>
#define SIZE 20
// the setup function runs once when you press reset or power the board
ISR(INT3_vect); // prototype
int messageArray[50];
int compareArray[50];
int volatile i = 0;
int volatile zeroCounter;
bool volatile messageDone = false;
bool volatile arrayBool = true;

void setup()
{
	pinMode(53, INPUT);
	DDRA = 0x00;
	pinMode(53, INPUT);
	EICRA = 0b11000000; // trigger rising edge
	EIMSK |= 0b00001000; //  activate INT3
	sei(); // enable interrupts
	Serial.begin(9600);
}

void loop()
{
	if (messageDone)
	{
		
		Serial.print("Both messages recieved comparing messages\n");
		//kald Andreas compare shit
		Serial.print("the first array\n");
		for (int element : messageArray)
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
ISR(INT3_vect)
{
	Serial.print("interrupt triggered  \n ");
	if (i < (SIZE+1))
	{
		Serial.println(digitalRead(53));
		if (arrayBool)
		{
			loadIntoArray(messageArray);
				if (zeroCounter >= 3)
				{
					Serial.print("zeroCounter overflow\n  ");
					arrayBool=false;
					zeroCounter = 0;
					i = 0;
				}
		}
		else
		{
			loadIntoArray(compareArray);
				if (zeroCounter >= 3)
				{
					Serial.print("zeroCounter overflow  AGAIN \n");
					zeroCounter = 0;
					arrayBool=true;
					messageDone = true;
					cli();
					i = 0;
				}
		}
	}
	else
	{
		if (!arrayBool&&!(messageArray==compareArray))
		{
			Serial.print("beskederne er ikke ens. Fejl.\n");
			messageDone = true;
			zeroCounter = 0;
			arrayBool = true;
		}
		arrayBool = !arrayBool;
	}


}





void loadIntoArray(int arr[20])
{
	if (digitalRead(53) == HIGH)
	{
		Serial.print("Test1\n");

		arr[i] = 1;
		i++;
		zeroCounter = 0;
	}
	else if(digitalRead(53)==LOW)
	{
		Serial.print("Test2\n");
		arr[i] = 0;
		i++;
		zeroCounter++;
	}
}
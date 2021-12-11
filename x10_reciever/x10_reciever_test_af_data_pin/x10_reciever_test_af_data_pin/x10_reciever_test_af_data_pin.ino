/*
 Name:		x_10_reciever.ino
 Created:	12/1/2021 10:55:26 AM
 Author:	oscar
*/
#include <avr/io.h>
#define SIZE 20
// the setup function runs once when you press reset or power the board
ISR(INT3_vect); // prototype
int messageArray[20];
int compareArray[20];
int volatile i = 0;
int volatile zeroCounter;
bool volatile messageDone = false;
bool volatile arrayBool = true;

void setup()
{
	DDRA = 0x00;
	pinMode(51, INPUT);
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
	if (digitalRead(51) == HIGH)
	{
		Serial.print("Test1\n");

		
		i++;
		zeroCounter = 0;
	}
	else if (digitalRead(51)==LOW)
	{
		Serial.print("Test2\n");
		
		i++;
		zeroCounter++;
	}

}





void loadIntoArray(int arr[20])
{

}
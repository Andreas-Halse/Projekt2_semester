/*
 Name:		x_10_reciever.ino
 Created:	12/1/2021 10:55:26 AM
 Author:	oscar
*/
#include <avr/io.h>
#define SIZE 20// the array size we work with
// the setup function runs once when you press reset or power the board
ISR(INT3_vect); // prototype
int messageArray[SIZE];				// the array in which the command is stored
int compareArray[SIZE];				// the compare array that verifies the data  
int volatile i = 0;					// counts number of databits recieved per array
int volatile zeroCounter;			// counts zeroes
bool volatile messageDone = false;	// prints the message
bool volatile arrayBool = true;		// Is used to switch which array the data is loaded into

void setup()
{
	
	DDRA = 0x00;			// set to input to enable interrupt by pressing SW3
	pinMode(53, INPUT);		// the data read pin
	EICRA = 0b01000000;		// any rising edge
	EIMSK |= 0b00001000;	//  activate INT3
	sei();					// enable interrupts
	Serial.begin(9600);		//not used in final build
}

void loop() 
{
	if (messageDone) //
	{
		cli();
		//kald Andreas compare shit
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
ISR(INT3_vect)
{
	
	if (i < (SIZE+1))
	{
		Serial.println(digitalRead(53));
		if (arrayBool)		// if true load into messageArray if false compareArray
		{
			loadIntoArray(messageArray);
				if (zeroCounter >= 3)		//counts number of zeroes to check for stopbits
				{
					//Serial.print("zeroCounter overflow\n  ");
					arrayBool=false;		//switch input array
					zeroCounter = 0;		//reset zerocounter
					i = 0;					// reset databit recieved counter to ensure
				}
		}
		else								//Same thing
		{
			loadIntoArray(compareArray);
				if (zeroCounter >= 3)
				{
					//Serial.print("zeroCounter overflow  AGAIN \n");
					zeroCounter = 0;
					arrayBool=true;
					messageDone = true;
					i = 0;
				}
		}
	}
	else
	{
		Serial.print("array too small");
	}

}





void loadIntoArray(int arr[20])
{
	if (digitalRead(53) == HIGH)//if datapin high
	{
		//Serial.print("Test1\n");

		arr[i] = 1;		//load in i
		i++;			//count up databit counter
		zeroCounter = 0;//reset zerocounter
	}
	else if(digitalRead(53)==LOW)
	{
		//Serial.print("Test2\n");
		arr[i] = 0;
		i++;
		zeroCounter++;	// count up zerocounter
	}
}
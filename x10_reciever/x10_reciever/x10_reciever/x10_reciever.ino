/*
 Name:		x_10_reciever.ino
 Created:	12/1/2021 10:55:26 AM
 Author:	oscar
*/
#include <avr/io.h>
#define SIZE 35
// the setup function runs once when you press reset or power the board
ISR(INT3_vect); // prototype
int messageArray[SIZE];				// the array in which the command is stored
int compareArray[SIZE];				// the compare array that verifies the data  
int volatile i = 0;					// counts number of databits recieved per array
bool volatile arrayBool = true;		// Is used to switch which array the data is loaded into
int volatile zeroCounter;			// counts zeroes
int volatile oneCounter;			// counts ones

bool volatile messageDone = false;	// pr	ints the message

void setup()
{
	

}

void loop() 
{
	if (messageDone) //
	{
		cli();
		//kald Andreas compare shit
		//Kald elisabeths funktions-vælger shit
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
	
	if (oneCounter >= 3)
	{
		if (i <= (SIZE + 1))
		{
			Serial.println(digitalRead(53));
			if (arrayBool)		// if true load into messageArray if false compareArray
			{
				loadIntoArray(messageArray);
				if (zeroCounter >= 3)		//counts number of zeroes to check for stopbits
				{
					//Serial.print("zeroCounter overflow\n  ");
					arrayBool = false;		//switch input array
					zeroCounter = 0;		//reset zerocounter
					i = 0;					// reset databit recieved counter to ensure
					oneCounter = 0;
				}
			}
			else								//Same thing
			{
				loadIntoArray(compareArray);
				if (zeroCounter >= 3)
				{
					//Serial.print("zeroCounter overflow  AGAIN \n");
					zeroCounter = 0;
					arrayBool = true;
					messageDone = true;
					i = 0;
					oneCounter = 0;
				}
			}
		}
		else
		{
			Serial.print("array too small");
		}
	}
	else if (digitalRead(53) == HIGH)
	{
		oneCounter++;
		if(arrayBool)
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
		oneCounter = 0;//Makes sure random faulty ones are sorted out
	}
}





void loadIntoArray(int arr[SIZE])
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
#include "x10_reciever.h"



void x10_reciever::loadIntoArray(int arr)
{
	if (digitalRead(53) == HIGH)//if datapin high
	{
		//Serial.print("Test1\n");

		arr[i] = 1;		//load in i
		i++;			//count up databit counter
		zeroCounter = 0;//reset zerocounter
	}
	else if (digitalRead(53) == LOW)
	{
		//Serial.print("Test2\n");
		arr[i] = 0;
		i++;
		zeroCounter++;	// count up zerocounter
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
		if (arrayBool)
		{
			loadIntoArray(messageArray);
		}
		else
		{
			loadIntoArray(compareArray);
		}

	}
}

void x10_reciever::readData()
{
	if (i <= (SIZE + 1))
	{
		Serial.println(digitalRead(53));
		if (arrayBool)		// if true load into messageArray if false compareArray
		{
			loadIntoArray(_messageArray);
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
			loadIntoArray(_compareArray);
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

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
int i = 0;
bool arrayBool = true;

int main(void)
{
	DDRA = 0x00;
	pinMode(53, INPUT);
	EICRA = 0b11000000; // trigger rising edge
	EIMSK |= 0b00001000; //  activate INT3
	sei(); // enable interrupts
	for (;;)
	{

	}
}
ISR(INT3_vect)
{
	if (i < (SIZE+1)
	{
		if (arrayBool)
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
		if (!arrayBool&&!(messageArray==compareArray))
		{
			Serial.print("beskederne er ikke ens. Fejl.");
		}
		arrayBool = !arrayBool;
	}


}





void loadIntoArray(int arr[20])
{
	if (digitalRead(53) == HIGH)
	{
		arr[i] = 1;
		i++;
	}
	else
	{
		arr[i] = 0;
		i++;
	}
}
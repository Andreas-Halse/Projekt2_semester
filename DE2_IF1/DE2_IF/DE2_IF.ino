/*
 Name:		DE2_IF.ino
 Created:	12/13/2021 11:53:32 AM
 Author:	juliezepernickjepsen
*/
#include <Arduino.h>
#include "DE2_IF.h"



// the setup function runs once when you press reset or power the board

	

// the loop function runs over and over again until power down or reset
int main() {
	DE2_IF test;		//globalt objekt til test
	Serial.begin(9600);
	DDRC = 0x00;
	for (;;)
	{
		test.signalUnlock();
		test.print();
	}

}





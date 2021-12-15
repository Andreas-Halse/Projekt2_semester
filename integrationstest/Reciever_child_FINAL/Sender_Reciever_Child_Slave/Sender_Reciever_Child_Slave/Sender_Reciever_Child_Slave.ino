/*
 Name:		sender_reciever_curtain_integrationstest.ino
 Created:	12/14/2021 5:10:26 PM
 Author:	oscar
*/
#include "Slave_Array_Read.h"
#include "x10_reciever.h"
#include "ArrayCompareFinal.h"
#include <Arduino.h>
#include <avr/io.h>

<<<<<<< HEAD
=======

x10_reciever reciever;
ArrayCompareFinal compareModule;
ISR(INT3_vect)
{

	if (reciever.startBitCheck())
	{
		reciever.readData();
	}

}
void setup() {
	Serial.begin(9600); // sætter Baudrate
	reciever.initReciever();


}

// the loop function runs over and over again until power down or reset
void loop() {


	if (reciever._messageDone) //
	{
		cli();
		//kald Andreas compare shit
		compareModule.ArrayDataCompare(reciever._messageArray, reciever._compareArray);

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
		//Kald elisabeths funktions-v?lger shit
		// SE MIG SE MIG SE MIG
		// SE MIG SE MIG SE MIG
		// SE MIG SE MIG SE MIG
		// SE MIG SE MIG SE MIG
		// SE MIG SE MIG SE MIG
		// HER SKAL INDSAETTES DIT OBJEKT.denOnskedeFunktion(reciever._messageArray);
		// fx
		//arrayReader.FunctionsValidateCall(reciever._messageArray);
		reciever.setMessageDone(false);
		sei();
	}
}
>>>>>>> 66aee5fb3c2daa6746f816ad3b25fd872c067580

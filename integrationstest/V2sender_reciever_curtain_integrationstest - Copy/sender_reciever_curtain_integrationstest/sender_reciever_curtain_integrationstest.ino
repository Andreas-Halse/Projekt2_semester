/*
 Name:		sender_reciever_curtain_integrationstest.ino
 Created:	12/14/2021 5:10:26 PM
 Author:	oscar
*/
#include "Motor_module.h"
#include "Slave_Array_Read.h"
#include "x10_reciever.h"
#include "ArrayCompareFinal.h"
#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>


x10_reciever reciever;
Slave_Array_Read arrayReader;
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
    pinMode(33, OUTPUT); // sætter pin 33 til output til on
    pinMode(31, OUTPUT); // sætter pin 31 til output til retning
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
		arrayReader.FunctionsValidateCall(reciever._messageArray);
		reciever.setMessageDone(false);
		sei();
	}
}

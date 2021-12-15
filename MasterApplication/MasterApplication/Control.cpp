/*
* @ Author Oliver V. Schousboe - Date 12.12.2021
* @ Brief File that contains implementation for all method calls in class related
*/

#include "Control.h"
#include <Arduino.h>
#include <avr/io.h>

/*
*@ brief Constructor for class Control - sets up association and initializes private attributes
*/
Control::Control(PC_IF* PointerToPC, x10_Sender* PointerToSender, DE2_IF* DE2Ptr)
{
	pcPtr = PointerToPC;
	senderPtr = PointerToSender;
	DE2Ptr_ = DE2Ptr;
	byteReceived = 0;
}

/*
*@ brief Uses association to retrieve number from class PC_IF
*@ return Integer from private attribute in class PC_IF
*/
int Control::getNumberFromPC() const
{
	return (pcPtr->getIncomingByte());
}

/*
*@ brief Uses association to prepare a new message by resetting variables needed to perform communication
*@ return Nothing
*/
void Control::prepareNewMessageFromPc()
{
	pcPtr->setIncomingByteToZero(true);
	senderPtr->setTwoMessagesSentToZero();
}

/*
*@ brief Uses association to send a message in x10 protocol
*/
void Control::sendMessage()
{
	senderPtr->sendx10Message();
}

/*
*@ brief Uses association to prepare a new message by resetting variables needed to perform communication
*/
void Control::prepareMessageTox10(const char* a)
{
	senderPtr->setBitPointer(a);
}

/*@Autor: Julie Zepernick Jepsen
* @brief conditional if statement with pointer to DE2 class, checking for valid password
* Printing options to user interface
*/

void Control::printStartMenu() const
{
	do
	{
		if (DE2Ptr_->signalUnlock())
		{
			Serial.print("\n-------------------------- \n Welcome to your Smart Home! \n-------------------------- \n\n");
			Serial.print("-------LIGHTS-------\n");
			Serial.print("To turn ON your lights:        press O\n");
			Serial.print("To turn OFF your lights:       press F\n");
			Serial.print("To turn UP your lights:        press I\n");
			Serial.print("To turn DOWN your lights:      press B\n");
			Serial.print("\n---------LOCK---------\n");
			Serial.print("To activate lock on cabinet:   press L\n");
			Serial.print("To deactivate lock on cabinet: press D\n");
			Serial.print("\n-------CURTAINS-------\n");
			Serial.print("To roll UP curtains:			press U\n");
			Serial.print("To roll DOWN curtains:		 press C\n");
			Serial.print("\n---- Stop system:------ \n");
			Serial.print("To stop all systems:           press Q\n");
		}
	} while (!(DE2Ptr_->signalUnlock()));
}






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

void Control::printStartMenu()
{
	if (DE2Ptr_->signalUnlock())
	{
		Serial.print("-------------------------- \n Welcome to your Smart Home! \n -------------------------- ");
		Serial.print("For at tænde lys, indtast O\n");
		Serial.print("For at slukke lys, indtast F\n");
		Serial.print("For at skrue op for lysstyrken, indtast på I\n");
		Serial.print("For at skrue ned for lysstyrken, indtast på B\n");
		Serial.print("For at slå låsen på kemikalieskabet til, indtast L\n");
		Serial.print("For at slå låsen på kemikalieskabet fra, indtast D\n");
		Serial.print("For at rulle gardinet op, indtast U\n");
		Serial.print("For at rulle gardinet ned, indtast C\n");
		Serial.print("For at stoppe alle systemer, indtast Q\n");
	}
}

void Control::stop()
{
	control.prepareMessageTox10(LightsOff);
	control.prepareMessageTox10(DeactivateLock);
	control.prepareMessageTox10(RollUpCurtain);
}





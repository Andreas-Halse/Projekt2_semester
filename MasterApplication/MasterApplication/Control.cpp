/*
* @ Author Oliver V. Schousboe - Date 12.12.2021
* @ Brief File that contains implementation for all method calls in class related
*/

#include "Control.h"
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

void Control::printStartMenu()
{
	if (DE2Ptr_->signalUnlock())
	{
		Serial.print("-------------------------- \n Welcome to your Smart Home! \n -------------------------- ");
		Serial.print("To adjust your light, type 'LIGHT'\n");
		Serial.print("To adjust your curtains, type 'CURTAIN'\n");
		Serial.print("To control your child safety, type 'CHILD'\n");
	}

}


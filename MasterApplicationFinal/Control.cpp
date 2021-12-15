/*
* @ Author Oliver V. Schousboe - Date 12.12.2021
* @ Brief File that contains implementation for all method calls in class related
*/

#include "Control.h"
/*
*@ brief Constructor for class Control - sets up association and initializes private attributes
*/
Control::Control(PC_IF* PointerToPC, x10_Sender* PointerToSender, DE2_IF* PointerToDE2)
{
	pcPtr = PointerToPC;
	senderPtr = PointerToSender;
	de2Ptr = PointerToDE2;
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

bool Control::UARTReady()
{
	if (pcPtr->allowedToSendToTerminal())
	{
		return true;
	}
	else
		return false;
}

void Control::checkPin()
{
	if ((de2Ptr->signalUnlocked())&&(de2Ptr->getAllowPrint()))
	{
		return;
	}
	if ((de2Ptr->signalUnlocked()) && !(de2Ptr->getAllowPrint()))
	{
		de2Ptr->setAllowPrint(true);
	}
	if (!(de2Ptr->signalUnlocked()))
	{
		de2Ptr->resetI();
		de2Ptr->setAllowPrint(false);
	}
}

void Control::showMenu()
{
	if ((de2Ptr->getAllowPrint()) && (de2Ptr->getI() == 0))
	{
		pcPtr->printToTerminal();
		de2Ptr->setI();
	}
}

bool Control::systemOpen()
{
	return (de2Ptr->signalUnlocked());
}


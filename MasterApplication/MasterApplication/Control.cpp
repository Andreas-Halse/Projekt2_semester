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
	AdrFctPtr = nullptr;
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
	}
}

/*
* @Author Julie Zepernick Jepsen
* @brief switch case to set const char arrays from domain class AdresseOgFunktion
* @returns const char array pointer 
*/
const char* Control::setArray(char AdrFct) 
{
	switch (AdrFct) {
	case 'AL':
		AdrFctPtr = (AdrFct_.ActivateLock);
		break;
	case 'DL':
		AdrFctPtr = (AdrFct_.DeactivateLock);
		break;
	case 'RU':
		AdrFctPtr = (AdrFct_.RollUpCurtain);
		break;
	case 'RD':
		AdrFctPtr = (AdrFct_.RollDownCurtain);
		break;
	case 'ON':
		AdrFctPtr = (AdrFct_.LightsOn);
		break;
	case 'OFF':
		AdrFctPtr = (AdrFct_.LightsOff);
		break;
	case 'I':
		AdrFctPtr = (AdrFct_.IncreaseBrightness);
		break;
	case 'D':
		AdrFctPtr = (AdrFct_.DecreaseBrightness);
		break;
	}
	return AdrFctPtr;
}



void Control::stopAll()
{
	AdrFct_.LightsOff;
	AdrFct_.DeactivateLock;
	AdrFct_.RollDownCurtain;

}


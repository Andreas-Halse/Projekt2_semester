#pragma once
/*
* @Author Oliver V. Schousboe - Date 12.12.2021
* @Brief class header for PC_IF. Defines all function prototypes
*/

#include "PC_IF.h"
#include "x10_Sender.h"


class Control
{
public:
	Control(PC_IF*, x10_Sender*);
	int getNumberFromPC() const;
	void prepareNewMessageFromPc();
	void sendMessage();
	void prepareMessageTox10(const char* a);
private:
	int byteReceived;
	PC_IF* pcPtr;
	x10_Sender* senderPtr;

};

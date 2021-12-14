#pragma once
/*
* @Author Oliver V. Schousboe - Date 12.12.2021
* @Brief class header for PC_IF. Defines all function prototypes
*/

#include "PC_IF.h"
#include "x10_Sender.h"
#include "DE2_IF.h"



class Control
{
public:
	Control(PC_IF*, x10_Sender*, DE2_IF*);
	int getNumberFromPC() const;
	void prepareNewMessageFromPc();
	void sendMessage();
	void prepareMessageTox10(const char* a);
	void printStartMenu(); 

private:
	int byteReceived;
	PC_IF* pcPtr;
	x10_Sender* senderPtr;
	DE2_IF* DE2Ptr_;

};

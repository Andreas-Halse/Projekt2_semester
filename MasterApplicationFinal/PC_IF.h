#pragma once
/*
*@ Author Oliver V. Schousboe - Date 12.12.2021
*@ Brief class header for PC_IF. Defines all function prototypes
*/

class PC_IF
{
public:
	PC_IF();
	void setMessageFromPC(int);
	bool allowedToSendToTerminal();
	int getIncomingByte();
	void setIncomingByteToZero(bool);
	void printToTerminal();
private:
	int incomingByte_;
};


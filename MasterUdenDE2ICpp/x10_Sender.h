#pragma once
/*
*@ Author Oliver V. Schousboe -  Date 12.12.2021
*@ Brief class header for PC_IF. Defines all function prototypes
*/

class x10_Sender
{
public:
	x10_Sender();
	void setTwoMessagesSentToZero();
	void setBitPointer(const char*);
	void sendx10Message();
private:
	const char* bitPointer_;
	int bitcounter_;
	int twoMessagesSent_;
	int countCrosses_;
};


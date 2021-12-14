#pragma once
#define SIZE 35

int messageArray[SIZE];				// the array in which the command is stored
int compareArray[SIZE];				// the compare array that verifies the data  
bool volatile messageDone;



bool volatile messageDone = false;	// pr	ints the message
class x10_reciever
{
public:
	x10_reciever();
	~x10_reciever();
	void initReciever();
	void checkForStopBits();
	bool startBitCheck();
	void loadIntoArray(int[]);
	void readData();
	
private:
	int _i = 0;					// counts number of databits recieved per array
	bool _arrayBool = true;		// Is used to switch which array the data is loaded into
	int _zeroCounter=0;			// counts zeroes
	int  _oneCounter=0;			// counts ones
};

x10_reciever::x10_reciever()
{
}

x10_reciever::~x10_reciever()
{
}
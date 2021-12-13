#pragma once
#define SIZE 35

int messageArray[SIZE];				// the array in which the command is stored
int compareArray[SIZE];				// the compare array that verifies the data  
int volatile i = 0;					// counts number of databits recieved per array
bool volatile arrayBool = true;		// Is used to switch which array the data is loaded into
int volatile zeroCounter;			// counts zeroes
int volatile oneCounter;			// counts ones
ISR(INT3_vect);

bool volatile messageDone = false;	// pr	ints the message
class x10_reciever
{
public:
	x10_reciever();
	~x10_reciever();
	void loadIntoArray(int arr);
	void readData();
	
private:
	int _messageArray[SIZE];
	int _compareArray[SIZE];
};

x10_reciever::x10_reciever()
{
}

x10_reciever::~x10_reciever()
{
}
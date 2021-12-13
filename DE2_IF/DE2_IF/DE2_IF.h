/*
* @Author Julie Zepernick Jepsen
* @Date 13-12-2021
* @brief class for checking password pass / fail from  DE2
* @attribute inclass initilization of bools
*/
#pragma once

using namespace std;

class DE2_IF
{
public:
	DE2_IF();
	bool signalUnlock();
	void signalPermLock();
	void print() const;

private:
	bool signalUnlock_ = false;			//char 'P' - signal to unlock from DE2 board
	bool signalPermLock_ = false;		//char 'F' - signal to permanent lock from DE2 board (three times)
};


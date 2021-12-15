#pragma once
/*
* @Author Julie Zepernick Jepsen
* @Date 13-12-2021
* @brief class $name for checking password pass / fail from  DE2
* @attribute inclass initilization of bools
*/

using namespace std;

class DE2_IF
{
public:
	DE2_IF(bool, bool);
	bool signalUnlock();
	void checkPassword();

private:
	bool signalUnlock_;			// signal to unlock from DE2 board
	//int printCounter_;

};
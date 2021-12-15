#pragma once
class Slave_Array_Read
{

public:

	Slave_Array_Read();
	bool StartSekvensValidate(int arrayIn[]);
	bool AdresseSekvensValidate(int arrayIn[]);
	void FunctionsValidateCall(int arrayIn[]);


private:
	int const curtain[35] = { 1,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,1,0,0,0,0 };
	int const rollDown[35] = { 1,1,1,0,1,0,0,1,0,1,1,0,0,1,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0 };
	int const rollUp[35] = { 1,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,1,0,0,0,0 };


	int const stop[35] = { 1,1,1,0,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,0,0,0 };

};

//UP //1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1

// DOWN 0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0

// Stop 1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1
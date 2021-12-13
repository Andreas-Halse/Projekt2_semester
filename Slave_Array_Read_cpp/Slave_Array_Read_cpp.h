#pragma once
class Slave_Array_Read_cpp
{

public:
	
	Slave_Array_Read_cpp();
	bool StartSekvensValidate(int arrayIn[]);
	bool AdresseSekvensValidate(int arrayIn[]);
	void FunctionsValidateCall(int arrayIn[]);


};

int const child[12] = { 1,1,1,0,1,0,0,1,1,0,0,1 };
const int activateChild[34] = { 1,1,1,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0 };
const int deactivateChild[34] = { 1,1,1,0,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,0,0,0 };
const int stop[34] = { 1,1,1,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,0,0,0 };


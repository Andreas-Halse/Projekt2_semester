#pragma once
class Slave_Array_Read
{

public:
	
	Slave_Array_Read();
	bool StartSekvensValidate(int arrayIn[]);
	bool AdresseSekvensValidate(int arrayIn[]);
	void FunctionsValidateCall(int arrayIn[]);


};

int const Motor[12] = { 1,1,1,0,1,0,0,1,0,1,1,0};
const int rollUp[34] = { 1,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,1,0,0,0,0 };
const int Rolldown[34] = { 1,1,1,0,1,0,0,1,0,1,1,0,0,1 XXX 1,0,0,0,0 };
const int stop[34] = { ,0,0,0,0 };

//{ 1,1,1,0,1,0,0,1,0,1,1,0,0,1 XXX 1,0,0,0,0};
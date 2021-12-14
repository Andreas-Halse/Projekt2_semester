#pragma once
//1. versions Author: Andreas
// 2. version author: Elisabeth
//

class Slave_Array_Read
{
public:
	Slave_Array_Read();
	bool StartSekvensValidate(int arrayIn[]);
	bool AdresseSekvensValidate(int arrayIn[]);
	void FunctionsValidateCall(int arrayIn[]);
};
int const curtain[12] = { 1,1,1,0,1,0,0,1,0,1,1,0 };
int const rollDown[34] = { 1,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,1,0};
int const rollUp[34] = { 1,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,1,0 };
int const stop[34] = { 1,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0 };

//
//const int rollDown[34] = { 1,1,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0 };
//
//int const stop[34] = { 1,1,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1 }
//
//int const rollDown={
//	{ 1,1,1,0,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,0,0,0 };
//const int stop[34] = { 1,1,1,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,0,0,0 };


/*Read array curtains

start sekvens : 1110

adresse : 8 bit

suffix : 01

funktionskald : 8 bit

suffix 10
*/



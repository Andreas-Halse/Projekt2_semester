/*
* Versionshistorik og author:
1. version: Andreas Halse Gravesen, d. 13/12-2021
2. version: Elisabeth Lennert, d. 13/12-2021


*/
#pragma once

/*@brief
Denne klasse validere startbit sekvens, adressebitsekvens samt 
laver funktionskald
*/

class Slave_Array_Read_cpp
{

public:
	
	Slave_Array_Read_cpp();
	bool StartSekvensValidate(int arrayIn[]);
	bool AdresseSekvensValidate(int arrayIn[]);
	void FunctionsValidateCall(int arrayIn[]);


};
/*@brief
0..3=startsekvens
4-7. = adresse
8.-9. = sufffix
10.-18.=funktionskald

*/
int const child[12] = {1,1,1,0,1,0,0,1,1,0,0,1 }; //startsekvens 1110, manchester adresse
const int activateChild[34] =   { 1,1,1,0//,1,0,0,1,1,0,0,1,//0,1,//1,0,1,0,1,0,1,0,1,0,1,0,1,0,//1,0};//startsekvens 1110, manchester adresse,suffix, funktionskald, suffix.
const int deactivateChild[34] = { 1,1,1,0//,1,0,0,1,1,0,0,1,//0,1,//0,1,0,1,0,1,0,1,0,1,0,1,0,1,//1,0 };
const int stop[34] =            { 1,1,1,0//,1,0,0,1,1,0,0,1,//0,1//1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1//1,0};  


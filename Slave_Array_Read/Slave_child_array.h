/*
* Versionshistorik og author:
1. version: Elisabeth Lennert, d. 13/12-2021
2. version: , d.


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
Slave_light funktioner global initialisering :*/

/*
* @brief
*
00-03= startbit
4-11. = adr
12.-13=suffix 01
14-29.= funktion ( 16 pladser)
30.-31=suffix = 10
32.-35= stop bit 000
*/
const int activateChild[35] = { 1,1,1,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0 };
const int deactivateChild[35] = { 1,1,1,0,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,0,0,0 };
const int stop[34] = { 1,1,1,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,0,0,0 };

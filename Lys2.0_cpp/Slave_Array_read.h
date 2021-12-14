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
00..3 plads = startsekvens
4..7. plads= adresse til subsystemer
8-9. plads = suffix
10.-17. = funktionskald
18.-20.suffix
21.-23 = stopsekvens
*/
int const light_array[12] = { 1,1,1,0,0,1,1,0,0,1,1,0 };
int const lightsOn_array[34] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,1,10 };
int const lightsOff_array[34] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0,1,0 };
int const increaseBrightness_array[34] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,1,0 };
int const decreaseBrightness_array[34] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0 };
int const stop[34] = { 1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0 };

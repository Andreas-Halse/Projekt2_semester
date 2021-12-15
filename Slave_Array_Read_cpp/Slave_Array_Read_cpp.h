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
0..3=startsekvens 1110
4-11. = adresse
12.-13. = sufffix 01
10.-18.=funktionskald
19-20 = suffix 10
stoo sekvens 000

*/

const int child_array[34] = { 1,1,1,0,1,0,0,1,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0 };
const int activate_array[34] = { 1,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0 };
const int deactivate_array[34] = { 1,1,1,0,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,0,0,0 };
const int stop[34] = { 1,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,0,0,0 };


#pragma once
/*
* @brief domain class for data on addresses and funktion on x.10
* @author: Julie Zepernick Jepsen
* @
*/

class AdresseOgFunktion
{
private:
	//Slaves adresse databits
	const char SlaveChildAdr_[8] = { 1,0,0,1,1,0,0,1 };
	const char SlaveCurtainAdr_[8] = { 1,0,0,1,0,1,1,0 };
	const char SlaveLightAdr_[8] = { 0,1,1,0,0,1,1,0 };

	//Funktionskald databits
	const char ActivateFct_[16] = { 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0 };
	const char DectivateFct_[16] = { 0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 };
	const char RollUpFct_[16] = { 1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1 };
	const char RollDownFct_[16] = { 0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0 };
	const char LightsOnFct[16] = { 1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,1 };
	const char LightsOffFct[16] = { 0,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0 };
	const char IncreaseBrightness_[16] = { 1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1 };
	const char DecreaseBrightness_[16] = { 0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0 };
	const char Stop[16] = { 1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1 };
};






#pragma once
/*
* @brief domain class for data on addresses and funktion on x.10
* @author: Julie Zepernick Jepsen
*/

class AdresseOgFunktion
{
public:
	//child:
	const char ActivateLock[27]			= { "100110011010101010101010" };
	const char DeactivateLock[27]		= { "100110010101010101010101" };
	//curtain
	const char RollUpCurtain[27]		= { "100101101001100101010101" };
	const char RollDownCurtain[27]		= { "100101100110011010101010" };
	//lights
	const char LightsOn[27]				= { "011001101010010110100101" };
	const char LightsOff[27]			= { "011001100101101001011010" };
	const char IncreaseBrightness[27]	= { "011001101010101010100101" };
	const char DecreaseBrightness[27]	= { "011001100101010101011010" };
};






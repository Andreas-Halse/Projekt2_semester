#pragma once
/// @brief domain class for data on addresses and funktion on x.10
/// author: Julie Zepernick Jepsen
/// Dato: 11.12.2021
/// 
class AdresseOgFunktion
{
private:
	//Slaves adresse databits
	const int SlaveChildAdr_[8]			= {1,0,0,1,1,0,0,1};
	const int SlaveCurtainAdr_[8]		= {1,0,0,1,0,1,1,0};
	const int SlaveLightAdr_[8]			= {0,1,1,0,0,1,1,0};

	//Funktionskald databits
	const int ActivateFct_[16]			= {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
	const int DectivateFct_[16]			= {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
	const int RollUpFct_[16]			= {1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1};
	const int RollDownFct_[16]			= {0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0};
	const int LightsOnFct[16]			= {1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,1};
	const int LightsOffFct[16]			= {0,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0};
	const int IncreaseBrightness_[16]	= {1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1};
	const int DecreaseBrightness_[16]	= {0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0};
	const int Stop[16]					= {1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1};
};


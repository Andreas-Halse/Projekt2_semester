#pragma once
/*
* Versionshistorik og author:
1. version: Julie Zepernick Jepsen, d. 08/12-2021
2. version: Andreas Halse Gravesen, d. 13/12-2021
3. version: 

*/


/*
* @brief Klassen $name til styring af elektromagnetisk lås
* @relates
*/


class Slave_Child
{
public:
	Slave_Child();
	bool activate();
	bool deactivate();
	void stop();

private:
	bool state_;

};

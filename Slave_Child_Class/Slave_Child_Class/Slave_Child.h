#pragma once

/*
* @brief Klassen $name til styring af elektromagnetisk l�s
* @relates 
*/


class Slave_Child
{
public: 
	Slave_Child();			//parametre: ptr til boundary
	bool activate();
	bool deactivate();
	void stop();

private:
	bool state_;
	//ptr til L�s IF
	//ptr til X10 IF
};


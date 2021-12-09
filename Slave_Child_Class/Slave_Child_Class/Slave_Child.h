#pragma once

/*
* @brief Klassen $name til styring af elektromagnetisk lås
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
	//ptr til Lås IF
	//ptr til X10 IF
};


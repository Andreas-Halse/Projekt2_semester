#pragma once

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

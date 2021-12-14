#pragma once

class Lys_Class
{
public:
	Lys_Class();

	void turnOn();
	void turnOff();
	void increaseBrightness();
	void decreaseBrightness();

private:
	int volatile intensitet = 220;
};





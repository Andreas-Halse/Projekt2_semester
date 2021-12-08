// 
// 
// 

#include "SlaveLight_IF.h"
#include <avr/io.h>

void SlaveLight_IF::initTimer()
{
	DDRB = 0xFF;

	//TCCR4A = 0b00000011;
	//TCCR4B = 0bxxxxxxxx
}
void SlaveLight_IF::turnON()
{
	PORTB = 0xFF;
}
void SlaveLight_IF::increaseBrightness()
{

}
void SlaveLight_IF::decreaseBrightness()
{

}
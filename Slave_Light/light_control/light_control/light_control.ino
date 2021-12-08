/*
 Name:		light_control.ino
 Created:	12/8/2021 2:06:56 PM
 Author:	oscar
*/

#include <avr/io.h>
#include "SlaveLight_IF.h"

void setup() {
	SlaveLight_IF c;
	c.initTimer();
	c.turnON();

}

// the loop function runs over and over again until power down or reset
void loop() {
  
}

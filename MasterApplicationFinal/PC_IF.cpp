
/*
* @ Author Oliver V. Schousboe - Date 12.12.2021
* @ Brief File that contains implementation for all method calls in class related
*/

#include "PC_IF.h"
#include "Arduino.h"

/*
*@ brief Constructor for PC_IF class. Initializes all attributes to appropriate values
*/
PC_IF::PC_IF()
{
    incomingByte_ = 0;
}

/*
*@ brief Method that sets the recieved character's ascii value received from PC to incominbByte_
*@ parametres takes an integer parameter which is used to set private attribute incomingByte_
*@ return nothing
*/
void PC_IF::setMessageFromPC(int message)
{
    incomingByte_ = message;
}

bool PC_IF::allowedToSendToTerminal()
{
    return (Serial.available() > 0);
}

/*
*@ brief Method that retrieves attribute incomingByte_
*@ parametres nothing
*@ return private attribute incomingByte_
*/
int PC_IF::getIncomingByte()
{
    return incomingByte_;
}

/*
*@ brief Method call for resetting received information from PC
*@ parametres takes a boolean - if true: resets incomingByte_  // if false: incomingByte_ remains the same
*@ return nothing
*/
void PC_IF::setIncomingByteToZero(bool byte)
{
    incomingByte_ = (byte) ? 0 : incomingByte_;
}

void PC_IF::printToTerminal()
{
        Serial.print("-------------------------- \n Welcome to your Smart Home! \n-------------------------- \n\n");
        Serial.print("-------LIGHTS-------\n");
        Serial.print("To turn ON your lights:        press O\n");
        Serial.print("To turn OFF your lights:       press F\n");
        Serial.print("To turn UP your lights:        press I\n");
        Serial.print("To turn DOWN your lights:      press B\n");
        Serial.print("\n---------LOCK---------\n");
        Serial.print("To activate lock on cabinet:   press L\n");
        Serial.print("To deactivate lock on cabinet: press D\n");
        Serial.print("\n-------CURTAINS-------\n");
        Serial.print("To roll UP curtains:			 press U\n");
        Serial.print("To roll DOWN curtains:		 press C\n");
        Serial.print("\n Stop system: \n");
        Serial.print("To stop all systems:           press Q\n");
}

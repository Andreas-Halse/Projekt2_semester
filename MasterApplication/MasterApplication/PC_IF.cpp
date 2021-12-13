
/*
* @ Author Oliver V. Schousboe - Date 12.12.2021
* @ Brief File that contains implementation for all method calls in class related
*/

#include "PC_IF.h"

/*
*@ brief Constructor for PC_IF class. Initializes all attributes to appropriate values
*/
PC_IF::PC_IF()
{
    incomingByte_ = 0;
}

/*
*@ brief Method that sets the recieved character's ascii value received from PC to incomingByte_
*@ parametres takes an integer parameter which is used to set private attribute incomingByte_
*@ return nothing
*/
void PC_IF::setMessageFromPC(int message)
{
    incomingByte_ = message;
}

/*
*@ brief Method that retrieves attribute incomingByte_
*@ parametres nothing
*@ return private attribute incomingByte_
*/
int PC_IF::getIncomingByte() const
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
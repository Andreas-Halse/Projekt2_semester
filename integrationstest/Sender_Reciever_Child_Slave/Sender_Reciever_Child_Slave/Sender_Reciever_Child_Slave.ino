/*
 Name:		sender_reciever_curtain_integrationstest.ino
 Created:	12/14/2021 5:10:26 PM
 Author:	oscar
*/
#include "Slave_Array_Read.h"
#include "x10_reciever.h"
#include "ArrayCompareFinal.h"
#include <Arduino.h>
#include <avr/io.h>


x10_reciever reciever;
ArrayCompareFinal compareModule;
ISR(INT3_vect)
{


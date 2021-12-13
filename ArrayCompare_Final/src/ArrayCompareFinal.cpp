#include <string.h>
#include <avr/io.h>
#include <Arduino.h>
#include "ArrayCompareFinal.hpp"

using namespace std;

ArrayCompareFinal::ArrayCompareFinal(int A1[], int A2[])
{
}

bool ArrayCompareFinal::ArrayLengthCompare(int A1[], int A2[])
{
	int LA1 = sizeof A1 / sizeof A1[0];
	int LA2 = sizeof A2  / sizeof A2[0];
	bool dataLoss = false;

	try
	{
		if (LA1 != LA2)
		{
			dataLoss = true;
			throw (dataLoss);
		}
		else
		{
		
			return true;
			
		}
	}
	catch (bool dataLoss)
	{
    digitalWrite(13, HIGH);	
    }
}

bool ArrayCompareFinal::ArrayDataCompare(int A1[], int A2[])
{
	int length = sizeof A1 / sizeof A1[0];

	for (int index = 0; index <= length; index++)
	{
		if (A1[index] != A2[index])
		{
			digitalWrite(13, HIGH);
			return false; 
		}
	}
	return true;
}

#include <string.h>
#include <avr/io.h>
#include <Arduino.h>
#include "ArrayCompareFinal.hpp"

using namespace std;

ArrayCompareFinal::ArrayCompareFinal(int A1[], int A2[])
{

}


bool ArrayCompareFinal::ArrayDataCompare(int A1[], int A2[])
{
	int length = 35;

	for (int index = 0; index <= length; index++)
	{
		if (A1[index] != A2[index])
		{
			digitalWrite(13, HIGH);
			return false; 
		}
		else
		{
			digitalWrite(13, LOW);
			return true;
		}
	}
}

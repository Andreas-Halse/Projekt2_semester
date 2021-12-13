#include <string.h>
#include <avr/io.h>
#include <Arduino.h>
#include "ArrayCompareFinal.hpp"



int main()
{
	int Array1[5] = { 2,1,1,1,1 };
	int Array2[5] = { 1,1,1,1,1 };

	ArrayCompareFinal test(Array1, Array2);

	
}
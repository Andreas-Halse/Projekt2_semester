#include <string.h>
#include <avr/io.h>
#include <Arduino.h>
#include "ArrayCompareFinal.hpp"

int main()
{
  	pinMode(13, OUTPUT);

	int Array1[35] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int Array2[35] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };

	ArrayCompareFinal test(Array1, Array2);

	test.ArrayDataCompare(Array1, Array2);

}
#include "ArrayCompare.h"
#include <iostream>
using namespace std;

int main()
{
	int Array1[5] = { 2,1,1,1,1 };
	int Array2[5] = { 1,1,1,1,1 };

	ArrayCompare test(Array1, Array2);

	
	cout << test.ArrayLengthCompare(Array1, Array2);
	cout << test.ArrayDataCompare(Array1, Array2);

}
#include "ArrayCompare.h"
#include <string>
#include <iostream>

using namespace std;

ArrayCompare::ArrayCompare(int A1[], int A2[])
{
}

bool ArrayCompare::ArrayLengthCompare(int A1[], int A2[])
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
			cout << "Vi har IKKE dataLoss - Array lengde passer." << endl;
			return true;
			
		}
	}
	catch (bool dataLoss)
	{
		cout << "Vi har dataLoss - Array længde passer ikke.";
	}
}

bool ArrayCompare::ArrayDataCompare(int A1[], int A2[])
{

	cout << endl;
	int length = sizeof A1 / sizeof A1[0];

	for (int index = 0; index <= length; index++)
	{
		if (A1[index] != A2[index])
		{
			cout << "Data matcher IKKE " << endl;
			return false; 
		}
	}
	cout << "Data matcher" << endl;
	return true;
}

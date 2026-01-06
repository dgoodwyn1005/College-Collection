// Classwork 10-08-2024 pt.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void lowPassFiler(double valueList[], int size, double cutValue);

int main()
{
	double numList[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	int size = 5;
	double maxValue = 3.0;
	//print array before
	for (int i = 0; i < size; i++)
	{
		cout << numList[i] << " ";
	}
	cout << endl;

	lowPassFiler(numList, size, maxValue);

	//print array after
	for (int i = 0; i < size; i++)
	{
		cout << numList[i] << " ";
	}
	return 0;
}

void lowPassFiler(double valueList[], int size, double cutValue)
{
	for (int n = 0; n < size; n++)
	{
		if (valueList[n] > cutValue)
		{
			valueList[n] = cutValue;
		}
	}
}
// Classwork 09-24-2024 pt.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    double array1[5] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
    double array2[5] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
    int size = 5;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter a number for array1: ";
        cin >> array1[i];    
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Enter a number for array2: ";
        cin >> array2[i];
    }

    //Display arrays
    for (int i = 0; i < size; i++)
    {
        cout << "array1[" << i << "] = " << array1[i] << "   array2[" << i << "] = " << array2[i] << endl;
    }
    
    //Compare the arrays
    bool isEqual = true;
    int n = 0;
    while (isEqual && n < size)
    {
        if (array1[n] != array2[n])
        {
            isEqual = false;
        }
        n++;
    }
    
    if (isEqual)
    {
        cout << "The arrays are equal." << endl;
    }
    else
    {
        cout << "The arrays are not equal." << endl;
    }

    return 0;
}


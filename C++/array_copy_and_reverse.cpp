// Assignment 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    //ASSIGNMENT PART 1
    cout << "PART 1" << endl;

    int array1[5] = { 0, 0, 0, 0, 0 };
    int array2[5] = { 0, 0, 0, 0, 0 };
    int size = 5;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter a number for the array: ";
        cin >> array1[i];
    }
    cout << "Duplicating array... " << endl;
    for (int i = 0; i < size; i++)
    {
        array2[i] = array1[i];
    }

    //Display arrays
    for (int i = 0; i < size; i++)
    {
        cout << "array1[" << i << "] = " << array1[i] << "   array2[" << i << "] = " << array2[i] << endl;
    }

    cout << endl << "PART 2" << endl;

    //ASSIGNMENT PART 2
    int rand_array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int reversed_array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    size = 10;

    srand((int)time(0));
    for (int i = 0; i < size; i++)
    {
        rand_array[i] = (rand() % 20) - 10;
    }
    cout << "Creating random array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i << "] = " << rand_array[i] << ", ";
    }
    cout << endl << "Reversing array..." << endl;
    int count = 0;
    for (int i = size; i > 0; i--)
    {
        reversed_array[count] = rand_array[i-1];
        count++;
    }
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i << "] = " << reversed_array[i] << ", ";
    }

    return 0;
}
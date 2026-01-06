// Classwork 09-24-2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int int_array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int size = 10;

    srand(time(0));
    for (int n = 0; n < size; n++)
    {
        int_array[n] = rand() % 100 + 1;
    }

    for (int n = 0; n < size; n++)
    {
        cout << int_array[n] << " ";
    }

    int sum = 0;
    for (int n = 0; n < size; n++)
    {
        sum += int_array[n];
    }

    cout << "\nThe average of the array elements is " << (double)sum / size << endl;

    return 0;
}

// Classwork 10-3-2024 pt.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int alternateSum(int arr[], int size);

int main()
{
    int arr[] = { 1, 2 };
    const int size = 2;
    cout << "The alternate sum of the array is: " << alternateSum(arr, size) << endl;
    return 0;
}

int alternateSum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            sum += arr[i];
        }
        else
        {
            sum -= arr[i];
        }
    }
    return sum;
}
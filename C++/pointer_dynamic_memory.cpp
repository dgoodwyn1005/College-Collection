// Classwork 12-03-2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;

void updateValues(int* a, int* b, int* c);
int sumArray(int* array, int size);

int main()
{
    int a = 0, b = 0, c = 0;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    updateValues(&a, &b, &c);
    cout << "The updated values are: " << a << " " << b << " " << c << endl;

    cout << endl;

    int intArray[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = 10;

    cout << "The sum of the elements of the array is: " << sumArray(intArray, size) << endl;

    cout << endl;

    int s = 0;
    int* iArray = nullptr;
    cout << "Enter the size of the array: ";
    cin >> s;
    iArray = new int[s];
    for (int i = 0; i < s; i++)
    {
        cout << "Enter the value for element " << i << ": ";
        cin >> *(iArray + i);
    }
    cout << "The values in the array in reverse are: ";
    for (int i = s - 1; i >= 0; i--)
    {
        cout << *(iArray + i) << " ";
    }

    return 0;
}

void updateValues(int* a, int* b, int* c)
{
    *a = *a * *a;
    *b = *b * *b;
    *c = *c * *c;
}

int sumArray(int* array, int size)
{
    int sum = 0;
    for (int n = 0; n < size; n++)
    {
        sum += *(array + n);
    }
    return sum;
}
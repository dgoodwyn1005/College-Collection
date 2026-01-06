// Classword 11-18-2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void swap(int& a, int& b);

int main()
{
    int x = 5, y = 7;
    cout << "Before swapping : x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "After swapping : x = " << x << ", y = " << y << endl;

    return 0;
}

//function definition
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
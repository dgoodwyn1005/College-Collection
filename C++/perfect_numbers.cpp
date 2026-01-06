// Classwork 10-3-2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
bool isPerfect(int n);

int main()
{
    int n = 2;
    int count = 0;
    while (count < 5)
    {
        if (isPerfect(n))
        {
            cout << n << " is a perfect number." << endl;
            count++;
        }
        n++;
    }
    return 0;
}

bool isPerfect(int n)
{
    int sum = 0;
    for (int i = 1; i <= n/2; i++)
    {
        if (n % i == 0)
        {
            sum += 1;
        }
    }
    return sum == n;
}


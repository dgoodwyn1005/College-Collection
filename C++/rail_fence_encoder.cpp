// Classwork 10-08-2024 pt.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void railFenceCypherEncoder(char plainText[], char cypherText[], int size);

int main()
{
    const int SIZE = 26;
    char plainText[] = { 'w','e','w','i','l','l','a','t','t','a','c','k','a','t','n','o','o','n',
        't','o','m','o','r','r','o','w' };
    char cypherText[SIZE] = { '\0' };
    railFenceCypherEncoder(plainText, cypherText, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        cout << cypherText[i];
    }
    return 0;
}

void railFenceCypherEncoder(char plainText[], char cypherText[], int size)
{
    int k = 0;
    for (int n = 0; n < size; n += 4, k++)
    {
        cypherText[k] = plainText[n];
    }
    for (int n = 1; n < size; n += 2, k++)
    {
        cypherText[k] = plainText[n];
    }
    for (int n = 2; n < size; n += 4, k++)
    {
        cypherText[k] = plainText[n];
    }
    
    for (int i = 0; i < size; i++)
    {
        cout << cypherText[i];
    }
    cout << endl;
}
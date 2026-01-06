// Assignment12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void decrypt_rail_cypher(char cypherText[], char plainText[], int size);
void xor_array(int arr1[], int arr2[], int size, int result[]);

int main()
{
    //Part 1s
    const int SIZE = 14;
    char cypherText[] = { 'i','e','s','k','h','p','t','i','w','r','s','o','h','o'};
    char plainText[SIZE] = { '\0' };

    decrypt_rail_cypher(cypherText, plainText, SIZE);

    //Part 2
    cout << endl;
    int arr1[] = { 1, 0, 0, 1, 1 };
    int arr2[] = { 1, 1, 0, 1, 0 };
    const int size = sizeof(arr1) / sizeof(arr1[0]);
    int result[size];
    xor_array(arr1, arr2, size, result);

    for (int i = 0; i < size; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

void decrypt_rail_cypher(char cypherText[], char plainText[], int size)
{
    int k = 0;

    for (int n = 0; n < size; n += 4)

    {

        plainText[n] = cypherText[k++];

    }

    for (int n = 1; n < size; n += 2)

    {

        plainText[n] = cypherText[k++];

    }

    for (int n = 2; n < size; n += 4)

    {

        plainText[n] = cypherText[k++];

    }


    for (int i = 0; i < size; i++)

    {

        cout << plainText[i];

    }

    cout << endl;
}

void xor_array(int arr1[], int arr2[], int size, int result[]) {
    for (int i = 0; i < size; ++i)
    {
        if (arr1[i] == arr2[i])
        {
            result[i] = 0;
        }
        else
        {
            result[i] = 1;
        }
    }
}
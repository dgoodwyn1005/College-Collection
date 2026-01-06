// Assignment11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

double dodec_volume(int length)
{
    return (((15 + (7 * (sqrt(5)))) / 4) * (pow(length, 3)));
}

int num_array_values(int arr1[3], int arr2[3])
{
    bool included = false;
    int count = 0;

    int arr1_len = 3;
    int arr2_len = 3;

    for (int i = 0; i < arr1_len; ++i)
    {
        bool included = false;

        // Check if arr1[i] has already been counted
        for (int j = 0; j < i; ++j)
        {
            if (arr1[i] == arr1[j])
            {
                included = true;
                break;
            }
        }

        if (!included)
        {
            // Check if arr1[i] is in arr2
            for (int j = 0; j < arr2_len; ++j)
            {
                if (arr1[i] == arr2[j])
                {
                    count++;
                    break;
                }
            }
        }
    }

    return count;
}

int main()
{
    cout << "Part 1\n";
    int side_length = 5;

    cout << "Volume of dodecahedron of size " << side_length << " is equal to " << dodec_volume(side_length) << endl;
    cout << endl;

    cout << "Part 2\n";

    int array1[] = { 1, 2, 3 };
    int array2[] = { 2, 3, 4 };

    cout << num_array_values(array1, array2);
    cout << endl;

    int array3[] = { 9, 12, 35 };
    int array4[] = { 35, 11, 2 };

    cout << num_array_values(array3, array4);
    cout << endl;

    return 0;
}
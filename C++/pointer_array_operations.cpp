#include <iostream>
using namespace std;

void findMinMax(int* arr, int size, int* min, int* max);
void reverseArray(int* arr, int size);
int compareValues(double* a, double* b);

int main()
{
	int arr1[] = {1, 3, 5};
	int size1 = 3;
	int min;
	int max;

	cout << "Array: ";
	for (int i = 0; i < size1; ++i) {
		cout << arr1[i] << " ";
	}
	cout << endl;

	findMinMax(arr1, size1, &min, &max);

	int arr2[] = {2, 4, 6, 8, 10};
	int size2 = 5;

	cout << "Array: ";
	for (int i = 0; i < size2; ++i) {
		cout << arr2[i] << " ";
	}
	cout << endl;

	reverseArray(arr2, size2);

	cout << "Reverse Array: ";
	for (int i = 0; i < size2; ++i) {
		cout << arr2[i] << " ";
	}
	cout << endl;

	double value1 = 10;
	double value2 = 8;

	cout << "Compare Values: " << value1 << ", " << value2 << ". " << " Return Value: " << compareValues(&value1, &value2);
}

void findMinMax(int* arr, int size, int* min, int* max)
{
	if (size < 1)
	{
		cout << "Array too small";
		return;
	}

	*min = arr[0] - 1;
	*max = arr[0];

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < *min)
		{
			*min = arr[i];
		}
		if (arr[i] > *max)
		{
			*max = arr[i];
		}
	}
}

void reverseArray(int* arr, int size)
{
	int* start = arr;
	int* end = arr + size - 1;

	while (start < end) {
		int temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}

int compareValues(double* a, double* b)
{
	if (*a > *b)
	{
		return 1;
	}
	else if (*a < *b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
#include <iostream>
using namespace std;

int main()
{
	int num = 0;
	int sum = 0;
	int count = 0;

	while (num != -1)
	{
		cout << "Enter a test score (0-100) or -1 to terminate input: ";
		cin >> num;

		if (num >= 0)
		{
			sum += num;
			count++;
		}
	}

	if (count > 0)
	{
		cout << "The average of the numbers entered is: " << double(sum) / count;
	}
	else
	{
		cout << "No numbers were entered.";
	}
	return 0;
}
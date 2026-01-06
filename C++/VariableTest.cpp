// VariableTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	double weight = 0, height = 0, bmi = 0;
	// ask user for height and weight
	cout << "Enter your weight in pounds: ";
	cin >> weight;
	cout << "Enter your height in inches: ";
	cin >> height;
	// calculate BMI
	bmi = (weight * 703) / (height * height);
	// check if BMI is underweight, normal, overweight, or obese
	if (bmi < 18.5)
	{
		cout << "Your BMI is " << bmi << " and you are underweight." << endl;
	}
	else if (bmi >= 18.5 && bmi <= 24.9)
	{
		cout << "Your BMI is " << bmi << " and you are normal." << endl;
	}
	else if (bmi >= 25 && bmi <= 29.9)
	{
		cout << "Your BMI is " << bmi << " and you are overweight." << endl;
	}
	else
	{
		cout << "Your BMI is " << bmi << " and you are obese." << endl;
	}
}
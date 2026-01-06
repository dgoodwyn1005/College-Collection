// Classwork 10-01-2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	enum class dayOfWeek {SUNDAY = 1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
	dayOfWeek choice = dayOfWeek::SUNDAY;
	int userChoice = 0;
	cout << "Enter a number between 1 and 7 indicating the day of the week: ";
	cin >> userChoice;
	switch (userChoice)
	{
	case 1:
		choice = dayOfWeek::SUNDAY;
		break;
	case 2:
		choice = dayOfWeek::MONDAY;
		break;
	case 3:
		choice = dayOfWeek::TUESDAY;
		break;
	case 4:
		choice = dayOfWeek::WEDNESDAY;
		break;
	case 5:
		choice = dayOfWeek::THURSDAY;
		break;
	case 6:
		choice = dayOfWeek::FRIDAY;
		break;
	case 7:
		choice = dayOfWeek::SATURDAY;
		break;
	default:
		cout << "Invalid Choice" << endl;
	}

	cout << "The day of the week is ";
	switch (choice)
	{
	case dayOfWeek::SUNDAY:
		cout << "Sunday";
		break;
	case dayOfWeek::MONDAY:
		cout << "Monday";
		break;
	case dayOfWeek::TUESDAY:
		cout << "Tuesday";
		break;
	case dayOfWeek::WEDNESDAY:
		cout << "Wednesday";
		break;
	case dayOfWeek::THURSDAY:
		cout << "Thursday";
		break;
	case dayOfWeek::FRIDAY:
		cout << "Friday";
		break;
	case dayOfWeek::SATURDAY:
		cout << "Saturday";
		break;
	}
	cout << endl;

	return 0;
}


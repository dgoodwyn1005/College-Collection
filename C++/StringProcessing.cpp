// String Processing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    //declare a string variable
    string score = "Score = 0";
    string message = "GAME OVER!!";
    int scoreValue = 100;
    //concatenate two strings
    stringstream ss("");
    ss << score << message << scoreValue;

    //cout << score << " " << message << endl;
}

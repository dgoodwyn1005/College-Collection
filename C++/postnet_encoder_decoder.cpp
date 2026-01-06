//*******************************************************************
// Course: CSCI 286
// Assignment 19
// Programmer: Deshawn Goodwyn
// Instructor: Dr. Mirek Mystkowski
// Date: November 7, 2024
// Synopsis: POSTNET class creation
//*******************************************************************

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Postnet
{
private:
    string zip_code;
    string encoded_barcode;
public:
    void setZipCode(string zip);
    string getZipCode();
    int calculateCheckDigit();
    void encode();
    void decode();
    void printBarcode();

    Postnet()
    {
        zip_code = "00000";
    }

    Postnet(string zip)
    {
        zip_code = zip;
    }
};

int main()
{
    Postnet p("23552");
    p.encode();
    p.printBarcode();
    p.decode();
    cout << endl << p.getZipCode();
}

string convert_to_string(int value)
{
    switch (value)
    {
    case 1:
        return ":::||";
        break;
    case 2:
        return "::|:|";
        break;
    case 3:
        return "::||:";
        break;
    case 4:
        return ":|::|";
        break;
    case 5:
        return ":|:|:";
        break;
    case 6:
        return ":||::";
        break;
    case 7:
        return "|:::|";
        break;
    case 8:
        return "|::|:";
        break;
    case 9:
        return "|:|::";
        break;
    case 0:
        return "||:::";
        break;
    }
}

int convert_to_num(string value)
{
    if (value == ":::||")
    {
        return 1;
    }
    else if (value == "::|:|")
    {
        return 2;
    }
    else if (value == "::||:")
    {
        return 3;
    }
    else if (value == ":|::|")
    {
        return 4;
    }
    else if (value == ":|:|:")
    {
        return 5;
    }
    else if (value == ":||::")
    {
        return 6;
    }
    else if (value == "|:::|")
    {
        return 7;
    }
    else if (value == "|::|:")
    {
        return 8;
    }
    else if (value == "|:|::")
    {
        return 9;
    }
    else if (value == "||:::")
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void Postnet::setZipCode(string zip)
{
    zip_code = zip;
}

string Postnet::getZipCode()
{
    return zip_code;
}

int Postnet::calculateCheckDigit()
{
    int total = 0;
    int check_digit = 0;

    for (int i = 0; i < zip_code.length(); i++)
    {
        total += zip_code[i] - '0';
    }

    check_digit = (10 - (total % 10)) % 10; // Extra modulus 10 so it can't be 10
    return check_digit;
}

void Postnet::encode()
{
    std::stringstream ss;

    ss << "|";

    for (int i = 0; i < zip_code.length(); i++)
    {
        int current_num = zip_code[i] - '0';
        ss << convert_to_string(current_num);
    }

    int check_digit = calculateCheckDigit();
    ss << convert_to_string(check_digit);
    ss << "|";

    encoded_barcode = ss.str();
    ss.clear();
}

void Postnet::decode()
{
    std::stringstream ss;
    int len = encoded_barcode.length();

    int index = 1; //Skips guard rail
    while (index < len - 6) // Index is less than the length of the barcode, excluding the guard rails & check number
    {
        string current_string = "";
        for (int i = 0; i < 5; i++)
        {
            current_string = current_string + encoded_barcode[index + i];
        }
        ss << convert_to_num(current_string);

        index += 5;
    }

    zip_code = ss.str();
    ss.clear();
}


void Postnet::printBarcode()
{
    cout << encoded_barcode;
}


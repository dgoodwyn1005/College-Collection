// Assignment20.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void pig_latin(string sentence);
string palindromic_substring(string s);
char non_repeating(const string s);

void pig_latin(string sentence)
{
    stringstream ss;
    ss << sentence;
    string word, result;

    while (ss >> word) {
        string new_word;
        if (word.length() <= 1)
        {
            new_word = word + "ay";
        }
        else
        {
            new_word = word.substr(1) + word[0] + "ay";
        }

        result += new_word + " ";
    }

    cout << result << endl;
}

string palindromic_substring(string s)
{
    int n = s.size();
    if (n == 0)
    {
        return "";
    }

    // dp[i] will be true if str[i..i+len-1] is a palindrome
    vector<bool> dp(n, false);
    int start = 0;  // Starting index of the longest palindrome
    int maxLength = 1;  // Length of the longest palindrome

    // Every single character is a palindrome
    for (int i = 0; i < n; i++) {
        dp[i] = true;
    }

    // Check for palindromes of length 2 and more
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;  // j is the end index of the substring
            if (s[i] == s[j])
            {
                if (len == 2 || dp[i + 1])
                {
                    dp[i] = true;
                    if (len > maxLength)
                    {
                        start = i;
                        maxLength = len;
                    }
                }
            }
            else
            {
                dp[i] = false;
            }
        }
    }

    return s.substr(start, maxLength);
}

char non_repeating(string s) {
    for (int i = 0; i < s.length(); i++)
    {
        char current = s[i];
        bool not_used = true;

        // Check if the character repeats in the string
        for (int j = 0; j < s.length(); j++)
        {
            if (i != j && s[j] == current)
            {
                not_used = false;
                break;
            }
        }

        if (not_used)
        {
            return current; // Return the first non-repeating character
        }
    }

    return '\0'; // Return null
}

int main()
{
    pig_latin("hello kind world");
    cout << endl;
    cout << palindromic_substring("look at this racecar") << endl;
    cout << non_repeating("hello") << endl;
}

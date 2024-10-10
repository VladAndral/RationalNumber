#include <iostream>
#include "Rational.h"

using namespace std;

string convertToLowercase(const string& str);

int main() {

    Rational rat1;
    Rational rat2;

    cout << "Enter your first fraction [##/##]" << endl;
    cin >> rat1;
    cout << "Enter your second fraction [##/##]" << endl;
    cin >> rat2;

    cout << "What operation would you like to perform?" << endl;
    cout << "[Add, Subtract, Multiply, Divide]" << endl;
    string choice;
    cin >> choice;
    convertToLowercase(choice);

    // /*
    // Debugging
    // */
    // Rational rat1 = Rational(5, 6);
    // Rational rat2 = Rational(6, 7);
    // string choice = "add";

    Rational result;
    if (choice == "add") { // No error handling yet
        result = rat1+rat2;
    } else if (choice == "subtract") {
        result = rat1-rat2;
    } else if (choice == "multiply") {
        result = rat1*rat2;
    } else if (choice == "divide") {
        result = rat1/rat2;
    }
    result.reduceFraction();
    cout << "Here is the result: " <<result << endl;
}

string convertToLowercase(const string& str) // Borrowed Code
{
    string result = "";
    for (int i = 0; i < result.length(); i++) {
        // Convert each character to lowercase using tolower
        char ch = result[i];
        result += tolower(ch);
    }
    return result;
}
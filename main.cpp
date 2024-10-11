#include <iostream>
#include "Rational.h"

using namespace std;

string convertToLowercase(string str);

int main() {

    Rational rat1;
    Rational rat2;

    cout << "What operation would you like to perform?" << endl;
    cout << "[Add, Subtract, Multiply, Divide, Equal, Reduce]" << endl;
    string choice;
    cin >> choice;

    if (choice != "reduce") {
        cout << "Enter your first fraction [##/##]" << endl;
        cin >> rat1;
        cout << "Enter your second fraction [##/##]" << endl;
        cin >> rat2;
    } else {
        cout << "Enter your fraction [##/##]" << endl;
        cin >> rat1;        
    }

    convertToLowercase(choice);

    // /*
    // Debugging
    // */
    // Rational rat1 = Rational(9221, 12345);
    // // Rational rat2 = Rational(6, 7);
    // Rational rat2 = Rational(10, 12);
    // string choice = "reduce";

    Rational result;
    bool equal;
    if (choice == "add") { // No error handling yet
        result = rat1+rat2;
    } else if (choice == "subtract") {
        result = rat1-rat2;
    } else if (choice == "multiply") {
        result = rat1*rat2;
    } else if (choice == "divide") {
        result = rat1/rat2;
    } else if (choice == "equal") {
        equal = rat1==rat2;
    } else if (choice == "reduce") {
        rat1.reduceFraction();
        result = rat1;
    }

    cout << "Here is the result: " << endl;
    if (choice == "equal") {
        if (equal) {
            cout << "Fractions are equal" << endl;
        } else {
            cout << "Fractions are not equal" << endl;
        }
    } else {
        result.reduceFraction();
        cout << result << endl;

    }
}

string convertToLowercase(string str) // Borrowed Code
{
    string result = "";
    for (int i = 0; i < result.length(); i++) {
        // Convert each character to lowercase using tolower
        char ch = result[i];
        result += tolower(ch);
    }
    return result;
}
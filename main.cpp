#include <iostream>
#include "Rational.h"

using namespace std;

string toLowercase(string str);
bool isStringInt(string input);
bool isInputValid(string input, vector<string> choices);
bool isFractionValid(string input);

int main() {

    Rational rat1;
    Rational rat2;
    vector<string> choices = {"add", "subtract", "multiply", "divide", "equal", "reduce"};

    bool correctInput = false;
    cout << "What operation would you like to perform?" << endl;
    cout << "[Add, Subtract, Multiply, Divide, Equal, Reduce]" << endl;
    string choice;
    cin >> choice;
    toLowercase(choice);
    correctInput = isInputValid(choice, choices);
    while (!correctInput) {
        cout << "Enter a valid input" << endl;
        cin >> choice;
        toLowercase(choice);
        correctInput = isInputValid(choice, choices);
    }
    
    correctInput = false;
    string input1;
    string input2;
    if (choice != "reduce") {
        cout << "Enter your first fraction [##/##]" << endl;
        cin >> input1;
        cout << "Enter your second fraction [##/##]" << endl;
        cin >> input2;
    } else {
        cout << "Enter your fraction [##/##]" << endl;
        cin >> input1;        
    }
    correctInput = isFractionValid(input1) && isFractionValid(input2);

    while (!correctInput) {
        cout << "Input should be number / number" << endl;
        cout << "E.g. '25/56'" << endl;
        if (choice != "reduce") {
            cout << "Enter your first fraction [##/##]" << endl;
            cin >> input1;
            cout << "Enter your second fraction [##/##]" << endl;
            cin >> input2;
        } else {
            cout << "Enter your fraction [##/##]" << endl;
            cin >> input1;        
        }
        correctInput = isFractionValid(input1) && isFractionValid(input2);
    }
    rat1.set_value(input1);
    rat2.set_value(input2);

    // /*
    // Debugging
    // */
    // Rational rat1 = Rational(9221, 12345);
    // // Rational rat2 = Rational(6, 7);
    // Rational rat2 = Rational(10, 12);
    // string choices[6] = {"add", "subtract", "multiply", "divide", "equal", "reduce"};
    // string choice = "reduce";
    // isInputValid(choice, choices);

    Rational result;
    bool equal;
    if (choice == "add") {
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

string toLowercase(string str) // Borrowed Code
{
    string result = "";
    for (int i = 0; i < str.length(); i++) {
        // Convert each character to lowercase using tolower
        char ch = str[i];
        result += tolower(ch);
    }
    return result;
}

bool isFractionValid(string input) {
    string numerator;
    string denominator;
    bool reachedSlash = false;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '/') {
			reachedSlash = true;
			continue;
		}
		if (reachedSlash) {
			denominator += input[i];
		} else {
			numerator += input[i];
		}
    }
    return (isStringInt(numerator) && isStringInt(denominator));
}

bool isStringInt(string input) {
    try
    {
        stoi(input);
    }
    catch(const std::exception& e)
    {
        return false;
    }
    return true;
    
}

bool isInputValid(string input, vector<string> choices) {
    input = toLowercase(input);
    for (int i = 0; i < choices.size(); i++) {
        if (input == choices[i]) {
            return true;
        }
    }
    return false;    
}
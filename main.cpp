#include <iostream>
#include "Rational.h"

using namespace std;

int main() {

    Rational rat1 = Rational(4, 6);
    Rational rat2 = Rational(12, 15);

    Rational multiplied = rat1*rat2;
    multiplied.reduceFraction();

    cout << multiplied << endl;

}